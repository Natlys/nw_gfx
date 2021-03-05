#include <nwg_pch.hpp>
#include "imgui_ogl.h"
#if (NWG_GAPI & NWG_GAPI_OGL)
#include "../imgui_core.hpp"
#include <lib/nwg_ogl_v1.h>
#include <lib/nwg_ogl_v2.h>
#include <lib/nwg_ogl_v3.h>
#include <lib/nwg_ogl_arb.h>

//----------------------------------------
// OpenGL    GLSL      GLSL
// version   version   string
//----------------------------------------
//  2.0       110       "#version 110"
//  2.1       120       "#version 120"
//  3.0       130       "#version 130"
//  3.1       140       "#version 140"
//  3.2       150       "#version 150"
//  3.3       330       "#version 330 core"
//  4.0       400       "#version 400 core"
//  4.1       410       "#version 410 core"
//  4.2       420       "#version 410 core"
//  4.3       430       "#version 430 core"
//  ES 2.0    100       "#version 100"      = WebGL 1.0
//  ES 3.0    300       "#version 300 es"   = WebGL 2.0
//----------------------------------------

// desktop opengl 3.2+ has glDrawElementsBaseVertex() which gl embedded systems and webgl don't have.
#if defined(IMGUI_IMPL_OPENGL_ES2) || defined(IMGUI_IMPL_OPENGL_ES3) || !defined(GL_VERSION_3_2)
#define IMGUI_IMPL_OPENGL_MAY_HAVE_VTX_OFFSET   0
#else
#define IMGUI_IMPL_OPENGL_MAY_HAVE_VTX_OFFSET   1
#endif
namespace GUI
{
    static GLuint s_nGlVer = 0;
    static GLchar s_strGlslVer[32] = "";
    static GLuint s_nFontMap = 0;
    static GLuint s_nShaderProg = 0, s_nShaderVtx = 0, s_nShaderPxl = 0;
    static GLint s_nTexLoc = 0, s_ProjMatLoc = 0;
    static GLuint s_nVtxCrdLoc = 0, s_nTexCrdLoc = 0, s_nVtxClrLoc = 0;
    static GLuint s_nVtxBuf = 0, s_nIdxBuf = 0;

    // Forward Declarations
    static void OglInitPlatformInterface();
    static void OglShutdownPlatformInterface();
    
    NWG_API bool OglCreateFontsTexture();
    NWG_API void OglDestroyFontsTexture();
    NWG_API bool OglCreateDeviceObjects();
    NWG_API void OglDestroyDeviceObjects();

    void OglRenderDrawData(ImDrawData* dData);

    bool CheckShader(GLuint idx, const char* strDesc);
    bool CheckProgram(GLuint idx, const char* strDesc);
}
namespace GUI
{
    bool OglInit(const char* strGlslVer)
    {
        GLint nMajorVer = 0, nMinorVer = 0;
        glGetIntegerv(GL_MAJOR_VERSION, &nMajorVer);
        glGetIntegerv(GL_MINOR_VERSION, &nMinorVer);
        s_nGlVer = (GLuint)(nMajorVer * 100 + nMinorVer * 10);

        // setup back-end capabilities flags
        ImGuiIO& io = GUI::GetIO();
        io.BackendRendererName = "nwg_ogl";
#if IMGUI_IMPL_OPENGL_MAY_HAVE_VTX_OFFSET
        if (s_nGlVer >= 320) { io.BackendFlags |= ImGuiBackendFlags_RendererHasVtxOffset; }
        // we can honor the ImDrawCmd::VtxOffset field, allowing for large meshes.
#endif
        // we can create multi-viewports on the renderer side (optional)
        io.BackendFlags |= ImGuiBackendFlags_RendererHasViewports;

        // store glsl version string so we can refer to it later in case we recreate shaders;
        // note: glsl version is not the same as gl version. Leave this to NULL if unsure;
        if (strGlslVer == NULL) { strGlslVer = "#version 130"; }
        IM_ASSERT((int)strlen(strGlslVer) + 2 < IM_ARRAYSIZE(s_strGlslVer));
        strcpy(s_strGlslVer, strGlslVer);
        strcat(s_strGlslVer, "\n");
        // debugging construct to make it easily visible in the ide and debugger which gl loader has been selected.
        // the code actually never uses the 'gl_loader' variable! It is only here so you can read it!
        // if auto-detection fails or doesn't select the same gl loader file as used by your application,
        // you are likely to get a crash below.
        // you can explicitly select a loader by using '#define IMGUI_IMPL_OPENGL_LOADER_XXX' in imconfig.h or compiler command-line.
        const char* strGlLoader = "nwg_ogl_loader";
        IM_UNUSED(strGlLoader);
        // make an arbitrary gl call (we don't actually need the result)
        // if you get a crash here: it probably means that you haven't initialized the OpenGL function loader used by this code.
        // desktop opengl 3/4 need a function loader. See the IMGUI_IMPL_OPENGL_LOADER_xxx explanation above.
        GLint nTexCurr = 0;
        glGetIntegerv(GL_TEXTURE_BINDING_2D, &nTexCurr);

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) { OglInitPlatformInterface(); }
        return true;
    }
    void OglShutdown()
    {
        OglShutdownPlatformInterface();
        OglDestroyDeviceObjects();
    }
}
namespace GUI
{
    void OglNewFrame() { if (!s_nShaderProg) { OglCreateDeviceObjects(); } }
    static void OglSetupRenderState(ImDrawData* dData, int nFbWidth, int nFbHeight, GLuint nVtxArr)
    {
        // setup render state: alpha-blending enabled, no face culling, no depth testing, scissor enabled, polygon fill
        glEnable(GL_BLEND);
        glBlendEquation(GL_FUNC_ADD);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDisable(GL_CULL_FACE);
        glDisable(GL_DEPTH_TEST);
        glEnable(GL_SCISSOR_TEST);
#ifdef GL_POLYGON_MODE
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
#endif

        // support for gl 4.5 rarely used glClipControl(GL_UPPER_LEFT)
        bool bClipLowerLeft = true;
#if defined(GL_CLIP_ORIGIN) && !defined(__APPLE__)
        GLenum enCurrClipOrig = 0;
        glGetIntegerv(GL_CLIP_ORIGIN, (GLint*)&current_clip_origin);
        if (current_clip_origin == GL_UPPER_LEFT)
            clip_origin_lower_left = false;
#endif
        // setup viewport, orthographic projection matrix
        // our visible imgui space lies from draw_data->DisplayPos (top left)
        // to draw_data->DisplayPos+data_data->DisplaySize (bottom right).
        // DisplayPos is (0,0) for single viewport apps.
        glViewport(0, 0, (GLsizei)nFbWidth, (GLsizei)nFbHeight);
        float L = dData->DisplayPos.x;
        float R = dData->DisplayPos.x + dData->DisplaySize.x;
        float T = dData->DisplayPos.y;
        float B = dData->DisplayPos.y + dData->DisplaySize.y;
        if (!bClipLowerLeft) { float tmp = T; T = B; B = tmp; } // swap top and bottom if origin is upper left
        const float matProj[4][4] = {
            { 2.0f / (R - L),   0.0f,         0.0f,   0.0f },
            { 0.0f,         2.0f / (T - B),   0.0f,   0.0f },
            { 0.0f,         0.0f,        -1.0f,   0.0f },
            { (R + L) / (L - R),  (T + B) / (B - T),  0.0f,   1.0f },
        };
        glUseProgram(s_nShaderProg);
        glUniform1i(s_nTexLoc, 0);
        glUniformMatrix4fv(s_ProjMatLoc, 1, GL_FALSE, &matProj[0][0]);
#ifdef GL_SAMPLER_BINDING
        glBindSampler(0, 0); // we use combined texture/sampler state. Applications using gl 3.3 may set that otherwise.
#endif
        (void)nVtxArr;
#ifndef IMGUI_IMPL_OPENGL_ES2
        glBindVertexArray(nVtxArr);
#endif
        // bind vertex/index buffers and setup attributes for ImDrawVert
        glBindBuffer(GL_ARRAY_BUFFER, s_nVtxBuf);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s_nIdxBuf);
        glEnableVertexAttribArray(s_nVtxCrdLoc);
        glEnableVertexAttribArray(s_nTexCrdLoc);
        glEnableVertexAttribArray(s_nVtxClrLoc);
        glVertexAttribPointer(s_nVtxCrdLoc, 2, GL_FLOAT, GL_FALSE, sizeof(ImDrawVert), (GLvoid*)IM_OFFSETOF(ImDrawVert, pos));
        glVertexAttribPointer(s_nTexCrdLoc, 2, GL_FLOAT, GL_FALSE, sizeof(ImDrawVert), (GLvoid*)IM_OFFSETOF(ImDrawVert, uv));
        glVertexAttribPointer(s_nVtxClrLoc, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(ImDrawVert), (GLvoid*)IM_OFFSETOF(ImDrawVert, col));
    }
    // opengl3 render function.
    // (this used to be set in io.RenderDrawListsFn and called by GUI::Render(),
    // but you can now call this directly from your main loop)
    // note that this implementation is little overcomplicated because
    // we are saving/setting up/restoring every opengl state explicitly, in order
    // to be able to run within any opengl engine that doesn't do so.
    void OglRenderDrawData(ImDrawData* dData)
    {
        // Avoid rendering when minimized, scale coordinates for retina displays (screen coordinates != framebuffer coordinates)
        int nFbWidth = (int)(dData->DisplaySize.x * dData->FramebufferScale.x);
        int nFbHeight = (int)(dData->DisplaySize.y * dData->FramebufferScale.y);
        if (nFbWidth <= 0 || nFbHeight <= 0) { return; }

        // backup gl state
        GLenum nLastActiveTex; glGetIntegerv(GL_ACTIVE_TEXTURE, (GLint*)&nLastActiveTex);
        GLuint nLastProg; glGetIntegerv(GL_CURRENT_PROGRAM, (GLint*)&nLastProg);
        GLuint nLastTex; glGetIntegerv(GL_TEXTURE_BINDING_2D, (GLint*)&nLastTex);
#ifdef GL_SAMPLER_BINDING
        GLuint nLastSampler; glGetIntegerv(GL_SAMPLER_BINDING, (GLint*)&nLastSampler);
#endif
        GLuint nLastArr; glGetIntegerv(GL_ARRAY_BUFFER_BINDING, (GLint*)&nLastArr);
#ifndef IMGUI_IMPL_OPENGL_ES2
        GLuint nLastVtxArr; glGetIntegerv(GL_VERTEX_ARRAY_BINDING, (GLint*)&nLastVtxArr);
#endif
#ifdef GL_POLYGON_MODE
        GLint nLastPolyMode[2]; glGetIntegerv(GL_POLYGON_MODE, nLastPolyMode);
#endif
        GLint nLastViewport[4]; glGetIntegerv(GL_VIEWPORT, nLastViewport);
        GLint nLastScisBox[4]; glGetIntegerv(GL_SCISSOR_BOX, nLastScisBox);
        GLenum nLastBlendSrcRgb; glGetIntegerv(GL_BLEND_SRC_RGB, (GLint*)&nLastBlendSrcRgb);
        GLenum nLastBlendDstRgb; glGetIntegerv(GL_BLEND_DST_RGB, (GLint*)&nLastBlendDstRgb);
        GLenum nLastBlendSrcAlpha; glGetIntegerv(GL_BLEND_SRC_ALPHA, (GLint*)&nLastBlendSrcAlpha);
        GLenum nLastBlendDstAlpha; glGetIntegerv(GL_BLEND_DST_ALPHA, (GLint*)&nLastBlendDstAlpha);
        GLenum nLastBlendEquationRgb; glGetIntegerv(GL_BLEND_EQUATION_RGB, (GLint*)&nLastBlendEquationRgb);
        GLenum nLastBlendEquationAlpha; glGetIntegerv(GL_BLEND_EQUATION_ALPHA, (GLint*)&nLastBlendEquationAlpha);
        GLboolean nLastEnableBlend = glIsEnabled(GL_BLEND);
        GLboolean nLastEnableCullFace = glIsEnabled(GL_CULL_FACE);
        GLboolean nLastEnableDepthTest = glIsEnabled(GL_DEPTH_TEST);
        GLboolean nLastEnableScissorTest = glIsEnabled(GL_SCISSOR_TEST);

        // setup desired gl state
        // recreate the vao every time (this is to easily allow multiple gl contexts to be rendered to;
        // vao are not shared among gl contexts
        // the renderer would actually work without any vao bound,
        // but then our VertexAttrib calls would overwrite the default one currently bound
        GLuint nVtxArr = 0;
#ifndef IMGUI_IMPL_OPENGL_ES2
        glGenVertexArrays(1, &nVtxArr);
#endif
        OglSetupRenderState(dData, nFbWidth, nFbHeight, nVtxArr);
        // will project scissor/clipping rectangles into framebuffer space
        // (0,0) unless using multi-viewports
        ImVec2 xyClipOff = dData->DisplayPos;
        // (1,1) unless using retina display which are often (2,2)
        ImVec2 xyClipScale = dData->FramebufferScale;
        // render command lists
        glActiveTexture(GL_TEXTURE0);
        for (int n = 0; n < dData->CmdListsCount; n++) {
            const ImDrawList* cmd_list = dData->CmdLists[n];

            // upload vertex/index buffers
            glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)cmd_list->VtxBuffer.Size * (int)sizeof(ImDrawVert),
                (const GLvoid*)cmd_list->VtxBuffer.Data, GL_STREAM_DRAW);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)cmd_list->IdxBuffer.Size * (int)sizeof(ImDrawIdx),
                (const GLvoid*)cmd_list->IdxBuffer.Data, GL_STREAM_DRAW);

            for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++) {
                const ImDrawCmd* pcmd = &cmd_list->CmdBuffer[cmd_i];
                if (pcmd->UserCallback != NULL) {
                    // user callback, registered via ImDrawList::AddCallback()
                    // (ImDrawCallback_ResetRenderState is a special callback value
                    // used by the user to request the renderer to reset render state.)
                    if (pcmd->UserCallback == ImDrawCallback_ResetRenderState) {
                        OglSetupRenderState(dData, nFbWidth, nFbHeight, nVtxArr);
                    }
                    else { pcmd->UserCallback(cmd_list, pcmd); }
                }
                else {
                    // project scissor/clipping rectangles into framebuffer space
                    ImVec4 rectClip;
                    rectClip.x = (pcmd->ClipRect.x - xyClipOff.x) * xyClipScale.x;
                    rectClip.y = (pcmd->ClipRect.y - xyClipOff.y) * xyClipScale.y;
                    rectClip.z = (pcmd->ClipRect.z - xyClipOff.x) * xyClipScale.x;
                    rectClip.w = (pcmd->ClipRect.w - xyClipOff.y) * xyClipScale.y;
                    if (rectClip.x < nFbWidth && rectClip.y < nFbHeight
                        && rectClip.z >= 0.0f && rectClip.w >= 0.0f) {
                        // apply scissor/clipping rectangle
                        glScissor((int)rectClip.x, (int)(nFbHeight - rectClip.w), (int)(rectClip.z - rectClip.x), (int)(rectClip.w - rectClip.y));
                        // bind texture, draw
                        glBindTexture(GL_TEXTURE_2D, (GLuint)(intptr_t)pcmd->TextureId);
#                   if IMGUI_IMPL_OPENGL_MAY_HAVE_VTX_OFFSET
                        if (s_nGlVer >= 320) {
                            glDrawElementsBaseVertex(GL_TRIANGLES, (GLsizei)pcmd->ElemCount,
                                sizeof(ImDrawIdx) == 2 ? GL_UNSIGNED_SHORT : GL_UNSIGNED_INT,
                                (void*)(intptr_t)(pcmd->IdxOffset * sizeof(ImDrawIdx)), (GLint)pcmd->VtxOffset);
                        }
                        else {
                            glDrawElements(GL_TRIANGLES, (GLsizei)pcmd->ElemCount,
                                sizeof(ImDrawIdx) == 2 ? GL_UNSIGNED_SHORT : GL_UNSIGNED_INT,
                                (void*)(intptr_t)(pcmd->IdxOffset * sizeof(ImDrawIdx)));
                        }
#                   else
                        glDrawElements(GL_TRIANGLES, (GLsizei)pcmd->ElemCount,
                            sizeof(ImDrawIdx) == 2 ? GL_UNSIGNED_SHORT : GL_UNSIGNED_INT,
                            (void*)(intptr_t)(pcmd->IdxOffset * sizeof(ImDrawIdx)));
#                   endif
                    }
                }
            }
        }
        // destroy the temporary vao
#ifndef IMGUI_IMPL_OPENGL_ES2
        glDeleteVertexArrays(1, &nVtxArr);
#endif
        // restore modified gl state
        glUseProgram(nLastProg);
        glBindTexture(GL_TEXTURE_2D, nLastTex);
#ifdef GL_SAMPLER_BINDING
        glBindSampler(0, nLastSampler);
#endif
        glActiveTexture(nLastTex);
#ifndef IMGUI_IMPL_OPENGL_ES2
        glBindVertexArray(nLastVtxArr);
#endif
        glBindBuffer(GL_ARRAY_BUFFER, nLastArr);
        glBlendEquationSeparate(nLastBlendEquationRgb, nLastBlendEquationAlpha);
        glBlendFuncSeparate(nLastBlendSrcRgb, nLastBlendDstRgb, nLastBlendSrcAlpha, nLastBlendDstAlpha);
        if (nLastEnableBlend) glEnable(GL_BLEND); else glDisable(GL_BLEND);
        if (nLastEnableCullFace) glEnable(GL_CULL_FACE); else glDisable(GL_CULL_FACE);
        if (nLastEnableDepthTest) glEnable(GL_DEPTH_TEST); else glDisable(GL_DEPTH_TEST);
        if (nLastEnableScissorTest) glEnable(GL_SCISSOR_TEST); else glDisable(GL_SCISSOR_TEST);
#ifdef GL_POLYGON_MODE
        glPolygonMode(GL_FRONT_AND_BACK, (GLenum)nLastPolyMode[0]);
#endif
        glViewport(nLastViewport[0], nLastViewport[1], (GLsizei)nLastViewport[2], (GLsizei)nLastViewport[3]);
        glScissor(nLastScisBox[0], nLastScisBox[1], (GLsizei)nLastScisBox[2], (GLsizei)nLastScisBox[3]);
    }
}
namespace GUI
{
    bool OglCreateDeviceObjects()
    {
        // backup gl state
        GLint nLastTex; glGetIntegerv(GL_TEXTURE_BINDING_2D, &nLastTex);
        GLint nLastArr; glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &nLastArr);
#ifndef IMGUI_IMPL_OPENGL_ES2
        GLint nLastVtxArr; glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &nLastVtxArr);
#endif
        // parse glsl version string
        int glsl_version = 130;
        sscanf(s_strGlslVer, "#version %d", &glsl_version);
        {

            const GLchar* vertex_shader_glsl_120 =
                "uniform mat4 ProjMtx;\n"
                "attribute vec2 Position;\n"
                "attribute vec2 UV;\n"
                "attribute vec4 Color;\n"
                "varying vec2 Frag_UV;\n"
                "varying vec4 Frag_Color;\n"
                "void main()\n"
                "{\n"
                "    Frag_UV = UV;\n"
                "    Frag_Color = Color;\n"
                "    gl_Position = ProjMtx * vec4(Position.xy,0,1);\n"
                "}\n";

            const GLchar* vertex_shader_glsl_130 =
                "uniform mat4 ProjMtx;\n"
                "in vec2 Position;\n"
                "in vec2 UV;\n"
                "in vec4 Color;\n"
                "out vec2 Frag_UV;\n"
                "out vec4 Frag_Color;\n"
                "void main()\n"
                "{\n"
                "    Frag_UV = UV;\n"
                "    Frag_Color = Color;\n"
                "    gl_Position = ProjMtx * vec4(Position.xy,0,1);\n"
                "}\n";

            const GLchar* vertex_shader_glsl_300_es =
                "precision mediump float;\n"
                "layout (location = 0) in vec2 Position;\n"
                "layout (location = 1) in vec2 UV;\n"
                "layout (location = 2) in vec4 Color;\n"
                "uniform mat4 ProjMtx;\n"
                "out vec2 Frag_UV;\n"
                "out vec4 Frag_Color;\n"
                "void main()\n"
                "{\n"
                "    Frag_UV = UV;\n"
                "    Frag_Color = Color;\n"
                "    gl_Position = ProjMtx * vec4(Position.xy,0,1);\n"
                "}\n";

            const GLchar* vertex_shader_glsl_410_core =
                "layout (location = 0) in vec2 Position;\n"
                "layout (location = 1) in vec2 UV;\n"
                "layout (location = 2) in vec4 Color;\n"
                "uniform mat4 ProjMtx;\n"
                "out vec2 Frag_UV;\n"
                "out vec4 Frag_Color;\n"
                "void main()\n"
                "{\n"
                "    Frag_UV = UV;\n"
                "    Frag_Color = Color;\n"
                "    gl_Position = ProjMtx * vec4(Position.xy,0,1);\n"
                "}\n";

            const GLchar* fragment_shader_glsl_120 =
                "#ifdef GL_ES\n"
                "    precision mediump float;\n"
                "#endif\n"
                "uniform sampler2D Texture;\n"
                "varying vec2 Frag_UV;\n"
                "varying vec4 Frag_Color;\n"
                "void main()\n"
                "{\n"
                "    gl_FragColor = Frag_Color * texture2D(Texture, Frag_UV.st);\n"
                "}\n";

            const GLchar* fragment_shader_glsl_130 =
                "uniform sampler2D Texture;\n"
                "in vec2 Frag_UV;\n"
                "in vec4 Frag_Color;\n"
                "out vec4 Out_Color;\n"
                "void main()\n"
                "{\n"
                "    Out_Color = Frag_Color * texture(Texture, Frag_UV.st);\n"
                "}\n";

            const GLchar* fragment_shader_glsl_300_es =
                "precision mediump float;\n"
                "uniform sampler2D Texture;\n"
                "in vec2 Frag_UV;\n"
                "in vec4 Frag_Color;\n"
                "layout (location = 0) out vec4 Out_Color;\n"
                "void main()\n"
                "{\n"
                "    Out_Color = Frag_Color * texture(Texture, Frag_UV.st);\n"
                "}\n";

            const GLchar* fragment_shader_glsl_410_core =
                "in vec2 Frag_UV;\n"
                "in vec4 Frag_Color;\n"
                "uniform sampler2D Texture;\n"
                "layout (location = 0) out vec4 Out_Color;\n"
                "void main()\n"
                "{\n"
                "    Out_Color = Frag_Color * texture(Texture, Frag_UV.st);\n"
                "}\n";
            // select shaders matching our GLSL versions
            const GLchar* vertex_shader = NULL;
            const GLchar* fragment_shader = NULL;
            if (glsl_version < 130) {
                vertex_shader = vertex_shader_glsl_120;
                fragment_shader = fragment_shader_glsl_120;
            }
            else if (glsl_version >= 410) {
                vertex_shader = vertex_shader_glsl_410_core;
                fragment_shader = fragment_shader_glsl_410_core;
            }
            else if (glsl_version == 300) {
                vertex_shader = vertex_shader_glsl_300_es;
                fragment_shader = fragment_shader_glsl_300_es;
            }
            else {
                vertex_shader = vertex_shader_glsl_130;
                fragment_shader = fragment_shader_glsl_130;
            }

            // Create shaders
            const GLchar* vtxShaderWithVer[2] = { s_strGlslVer, vertex_shader };
            s_nShaderVtx = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(s_nShaderVtx, 2, vtxShaderWithVer, NULL);
            glCompileShader(s_nShaderVtx);
            CheckShader(s_nShaderVtx, "vertex shader");

            const GLchar* fragment_shader_with_version[2] = { s_strGlslVer, fragment_shader };
            s_nShaderPxl = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(s_nVtxClrLoc, 2, fragment_shader_with_version, NULL);
            glCompileShader(s_nVtxClrLoc);
            CheckShader(s_nVtxClrLoc, "pixel shader");
        }

        s_nShaderProg = glCreateProgram();
        glAttachShader(s_nShaderProg, s_nShaderVtx);
        glAttachShader(s_nShaderProg, s_nShaderPxl);
        glLinkProgram(s_nShaderProg);
        CheckProgram(s_nShaderProg, "shader program");

        s_nTexLoc = glGetUniformLocation(s_nShaderProg, "Texture");
        s_ProjMatLoc = glGetUniformLocation(s_nShaderProg, "ProjMtx");
        s_nVtxCrdLoc = (GLuint)glGetAttribLocation(s_nShaderProg, "Position");
        s_nTexCrdLoc = (GLuint)glGetAttribLocation(s_nShaderProg, "UV");
        s_nVtxClrLoc = (GLuint)glGetAttribLocation(s_nShaderProg, "Color");
        // create buffers
        glGenBuffers(1, &s_nVtxBuf);
        glGenBuffers(1, &s_nIdxBuf);
        OglCreateFontsTexture();
        // restore modified gl state
        glBindTexture(GL_TEXTURE_2D, nLastTex);
        glBindBuffer(GL_ARRAY_BUFFER, nLastArr);
#ifndef IMGUI_IMPL_OPENGL_ES2
        glBindVertexArray(nLastVtxArr);
#endif
        return true;
    }
    void OglDestroyDeviceObjects()
    {
        if (s_nVtxBuf) { glDeleteBuffers(1, &s_nVtxBuf); s_nVtxBuf = 0; }
        if (s_nIdxBuf) { glDeleteBuffers(1, &s_nIdxBuf); s_nIdxBuf = 0; }
        if (s_nShaderProg && s_nShaderVtx) { glDetachShader(s_nShaderProg, s_nShaderVtx); }
        if (s_nShaderProg && s_nShaderPxl) { glDetachShader(s_nShaderProg, s_nShaderPxl); }
        if (s_nShaderVtx) { glDeleteShader(s_nShaderVtx); s_nShaderVtx = 0; }
        if (s_nShaderPxl) { glDeleteShader(s_nShaderPxl); s_nShaderPxl = 0; }
        if (s_nShaderProg) { glDeleteProgram(s_nShaderProg); s_nShaderProg = 0; }

        OglDestroyFontsTexture();
    }
    bool OglCreateFontsTexture()
    {
        // Build texture atlas
        ImGuiIO& io = GUI::GetIO();
        unsigned char* pPixels;
        int width, height;
        // load as rgba 32-bit (75% of the memory is wasted, but default font is so small)
        // because it is more likely to be compatible with user's existing shaders.
        // if your ImTextureId represent a higher-level concept than just a gl texture id,
        // consider calling GetTexDataAsAlpha8() instead to save on gpu memory.
        io.Fonts->GetTexDataAsRGBA32(&pPixels, &width, &height);
        // upload texture to graphics system
        GLint nLastTex;
        glGetIntegerv(GL_TEXTURE_BINDING_2D, &nLastTex);
        glGenTextures(1, &s_nFontMap);
        glBindTexture(GL_TEXTURE_2D, s_nFontMap);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
#ifdef GL_UNPACK_ROW_LENGTH
        glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
            width, height, 0,
            GL_RGBA, GL_UNSIGNED_BYTE, pPixels);
        // store our identifier
        io.Fonts->TexID = (ImTextureID)(intptr_t)s_nFontMap;
        // restore state
        glBindTexture(GL_TEXTURE_2D, nLastTex);
        return true;
    }
    void OglDestroyFontsTexture()
    {
        if (s_nFontMap != NULL) {
            ImGuiIO& io = GUI::GetIO();
            glDeleteTextures(1, &s_nFontMap);
            io.Fonts->TexID = 0;
            s_nFontMap = 0;
        }
    }
}
namespace GUI
{
    // if you get an error please report on github.
    // you may try different gl context version or glsl version.
    // see gl<>glsl version table at the top of this file.
    bool CheckShader(GLuint idx, const char* strDesc)
    {
        GLint nStatus = 0, nLogLen = 0;
        glGetShaderiv(idx, GL_COMPILE_STATUS, &nStatus);
        glGetShaderiv(idx, GL_INFO_LOG_LENGTH, &nLogLen);
        if ((GLboolean)nStatus == GL_FALSE) {
            fprintf(stderr, "ERROR: OglCreateDeviceObjects: failed to compile %s!\n", strDesc);
        }
        if (nLogLen > 1) {
            ImVector<char> buf;
            buf.resize((int)(nLogLen + 1));
            glGetshader_infoLog(idx, nLogLen, NULL, (GLchar*)buf.begin());
            fprintf(stderr, "%s\n", buf.begin());
        }
        return (GLboolean)nStatus == GL_TRUE;
    }
    bool CheckProgram(GLuint idx, const char* strDesc)
    {
        GLint nStatus = 0, nLogLen = 0;
        glGetProgramiv(idx, GL_LINK_STATUS, &nStatus);
        glGetProgramiv(idx, GL_INFO_LOG_LENGTH, &nLogLen);
        if ((GLboolean)nStatus == GL_FALSE) {
            fprintf(stderr, "ERROR: OglCreateDeviceObjects: failed to link %s! (with glsl '%s')\n", strDesc, s_strGlslVer);
        }
        if (nLogLen > 1) {
            ImVector<char> buf;
            buf.resize((int)(nLogLen + 1));
            glGetProgramInfoLog(idx, nLogLen, NULL, (GLchar*)buf.begin());
            fprintf(stderr, "%s\n", buf.begin());
        }
        return (GLboolean)nStatus == GL_TRUE;
    }
}
namespace GUI
{
    //--------------------------------------------------------------------------------------------------------
    // MULTI-VIEWPORT / PLATFORM INTERFACE SUPPORT
    // this is an _advanced_ and _optional_ feature,
    // allowing the back-end to create and handle multiple viewports simultaneously.
    //--------------------------------------------------------------------------------------------------------
    static void OglRenderWindow(ImGuiViewport* pViewport, void*)
    {
        if (!(pViewport->Flags & ImGuiViewportFlags_NoRendererClear)) {
            ImVec4 rgbaClear = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
            glClearColor(rgbaClear.x, rgbaClear.y, rgbaClear.z, rgbaClear.w);
            glClear(GL_COLOR_BUFFER_BIT);
        }
        OglRenderDrawData(pViewport->DrawData);
    }

    static void OglInitPlatformInterface()
    {
        ImGuiPlatformIO& platform_io = GUI::GetPlatformIO();
        platform_io.Renderer_RenderWindow = OglRenderWindow;
    }

    static void OglShutdownPlatformInterface() { GUI::DestroyPlatformWindows(); }
}
#endif  // NWG_GAPI