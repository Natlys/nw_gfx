#ifndef NWG_OGL_ARB_H
#define NWG_OGL_ARB_H
#include "nwg_ogl_native.h"
namespace NWG
{
	extern void OglLoadArb();
}
#ifndef NWG_OGL_ARB_FUNC
#define NWG_OGL_ARB_FUNC 1

#ifndef GL_ARB_vertex_buffer_object
// GL types for handling large vertex buffer objects
typedef ptrdiff_t GLintptrARB;
typedef ptrdiff_t GLsizeiptrARB;
#endif

#ifndef GL_ARB_shader_objects
// GL types for program/shader text and shader object handles
typedef char GLcharARB;
typedef unsigned int GLhandleARB;
#endif

// GL type for "half" precision (s10e5) float data in host memory
#ifndef GL_ARB_half_float_pixel
typedef unsigned short GLhalfARB;
#endif

#ifndef GL_NV_half_float
typedef unsigned short GLhalfNV;
#endif

#ifndef GLEXT_64_TYPES_DEFINED
// This code block is duplicated in glxext.h, so must be protected
#define GLEXT_64_TYPES_DEFINED
// define int32_t, int64_t, and uint64_t types for ust/msc
// (as used in the GL_EXT_timer_query extension).
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#elif defined(__sun__) || defined(__digital__)
#include <inttypes.h>
#if defined(__STDC__)
#if defined(__arch64__) || defined(_LP64)
typedef long int int64_t;
typedef unsigned long int uint64_t;
#else
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#endif // __arch64__
#endif // __STDC__
#elif defined( __VMS ) || defined(__sgi)
#include <inttypes.h>
#elif defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
#elif defined(__UNIXOS2__) || defined(__SOL64__)
typedef long int int32_t;
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#elif defined(_WIN32) && defined(__GNUC__)
#include <stdint.h>
#elif defined(_WIN32)
typedef __int32 int32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
// fallback if nothing above works
#include <inttypes.h>
#endif
#endif

#ifndef GL_EXT_timer_query
typedef int64_t GLint64EXT;
typedef uint64_t GLuint64EXT;
#endif


#ifndef GL_ARB_cl_event
// These incomplete types let us declare types compatible with OpenCL's cl_context and cl_event
struct _cl_context;
struct _cl_event;
#endif

#ifndef GL_ARB_debug_output
typedef void (APIENTRY* GLDEBUGPROCARB)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, GLvoid* userParam);
#endif

#ifndef GL_AMD_debug_output
typedef void (APIENTRY* GLDEBUGPROCAMD)(GLuint id, GLenum category, GLenum severity, GLsizei length, const GLchar* message, GLvoid* userParam);
#endif

#ifndef GL_KHR_debug
typedef void (APIENTRY* GLDEBUGPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, GLvoid* userParam);
#endif

#ifndef GL_ARB_depth_buffer_float
#define GL_ARB_depth_buffer_float 1
#endif

#ifndef GL_ARB_framebuffer_object
#define GL_ARB_framebuffer_object 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI GLboolean APIENTRY glIsRenderbuffer(GLuint renderbuffer);
GLAPI void APIENTRY glBindRenderbuffer(GLenum target, GLuint renderbuffer);
GLAPI void APIENTRY glDeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers);
GLAPI void APIENTRY glGenRenderbuffers(GLsizei n, GLuint* renderbuffers);
GLAPI void APIENTRY glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params);
GLAPI GLboolean APIENTRY glIsFramebuffer(GLuint framebuffer);
GLAPI void APIENTRY glBindFramebuffer(GLenum target, GLuint framebuffer);
GLAPI void APIENTRY glDeleteFramebuffers(GLsizei n, const GLuint* framebuffers);
GLAPI void APIENTRY glGenFramebuffers(GLsizei n, GLuint* framebuffers);
GLAPI GLenum APIENTRY glCheckFramebufferStatus(GLenum target);
GLAPI void APIENTRY glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void APIENTRY glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void APIENTRY glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
GLAPI void APIENTRY glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI void APIENTRY glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params);
GLAPI void APIENTRY glGenerateMipmap(GLenum target);
GLAPI void APIENTRY glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLAPI void APIENTRY glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
#endif // GLCOREARB_PROTOTYPES
typedef GLboolean(APIENTRYP PFNGLISRENDERBUFFERPROC) (GLuint renderbuffer);
typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC) (GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC) (GLsizei n, const GLuint* renderbuffers);
typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC) (GLsizei n, GLuint* renderbuffers);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint* params);
typedef GLboolean(APIENTRYP PFNGLISFRAMEBUFFERPROC) (GLuint framebuffer);
typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC) (GLenum target, GLuint framebuffer);
typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC) (GLsizei n, const GLuint* framebuffers);
typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC) (GLsizei n, GLuint* framebuffers);
typedef GLenum(APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC) (GLenum target);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC) (GLenum target, GLenum attachment, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC) (GLenum target);
typedef void (APIENTRYP PFNGLBLITFRAMEBUFFERPROC) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
extern PFNGLISRENDERBUFFERPROC OglIsRenderbuffer;
extern PFNGLBINDRENDERBUFFERPROC OglBindRenderbuffer;
extern PFNGLDELETERENDERBUFFERSPROC OglDeleteRenderbuffers;
extern PFNGLGENRENDERBUFFERSPROC OglGenRenderbuffers;
extern PFNGLRENDERBUFFERSTORAGEPROC OglRenderbufferStorage;
extern PFNGLGETRENDERBUFFERPARAMETERIVPROC OglGetRenderbufferParameteriv;
extern PFNGLISFRAMEBUFFERPROC OglIsFramebuffer;
extern PFNGLBINDFRAMEBUFFERPROC OglBindFramebuffer;
extern PFNGLDELETEFRAMEBUFFERSPROC OglDeleteFramebuffers;
extern PFNGLGENFRAMEBUFFERSPROC OglGenFramebuffers;
extern PFNGLCHECKFRAMEBUFFERSTATUSPROC OglCheckFramebufferStatus;
extern PFNGLFRAMEBUFFERTEXTURE1DPROC OglFramebufferTexture1D;
extern PFNGLFRAMEBUFFERTEXTURE2DPROC OglFramebufferTexture2D;
extern PFNGLFRAMEBUFFERTEXTURE3DPROC OglFramebufferTexture3D;
extern PFNGLFRAMEBUFFERRENDERBUFFERPROC OglFramebufferRenderbuffer;
extern PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC OglGetFramebufferAttachmentParameteriv;
extern PFNGLGENERATEMIPMAPPROC OglGenerateMipmap;
extern PFNGLBLITFRAMEBUFFERPROC OglBlitFramebuffer;
extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC OglRenderbufferStorageMultisample;
extern PFNGLFRAMEBUFFERTEXTURELAYERPROC OglFramebufferTextureLayer;
#endif

#ifndef GL_ARB_framebuffer_sRGB
#define GL_ARB_framebuffer_sRGB 1
#endif

#ifndef GL_ARB_half_float_vertex
#define GL_ARB_half_float_vertex 1
#endif

#ifndef GL_ARB_map_buffer_range
#define GL_ARB_map_buffer_range 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI GLvoid* APIENTRY glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI void APIENTRY glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length);
#endif // GLCOREARB_PROTOTYPES
typedef GLvoid* (APIENTRYP PFNGLMAPBUFFERRANGEPROC) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC) (GLenum target, GLintptr offset, GLsizeiptr length);
extern PFNGLMAPBUFFERRANGEPROC OglMapBufferRange;
extern PFNGLFLUSHMAPPEDBUFFERRANGEPROC OglFlushMappedBufferRange;
#endif

#ifndef GL_ARB_texture_compression_rgtc
#define GL_ARB_texture_compression_rgtc 1
#endif

#ifndef GL_ARB_texture_rg
#define GL_ARB_texture_rg 1
#endif

#ifndef GL_ARB_vertex_array_object
#define GL_ARB_vertex_array_object 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glBindVertexArray(GLuint array);
GLAPI void APIENTRY glDeleteVertexArrays(GLsizei n, const GLuint* arrays);
GLAPI void APIENTRY glGenVertexArrays(GLsizei n, GLuint* arrays);
GLAPI GLboolean APIENTRY glIsVertexArray(GLuint array);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLBINDVERTEXARRAYPROC) (GLuint array);
typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC) (GLsizei n, const GLuint* arrays);
typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC) (GLsizei n, GLuint* arrays);
typedef GLboolean(APIENTRYP PFNGLISVERTEXARRAYPROC) (GLuint array);
extern PFNGLBINDVERTEXARRAYPROC OglBindVertexArray;
extern PFNGLDELETEVERTEXARRAYSPROC OglDeleteVertexArrays;
extern PFNGLGENVERTEXARRAYSPROC OglGenVertexArrays;
extern PFNGLISVERTEXARRAYPROC OglIsVertexArray;
#endif

#ifndef GL_ARB_uniform_buffer_object
#define GL_ARB_uniform_buffer_object 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices);
GLAPI void APIENTRY glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
GLAPI void APIENTRY glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
GLAPI GLuint APIENTRY glGetUniformBlockIndex(GLuint program, const GLchar* uniformBlockName);
GLAPI void APIENTRY glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
GLAPI void APIENTRY glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
GLAPI void APIENTRY glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLGETUNIFORMINDICESPROC) (GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC) (GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC) (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
typedef GLuint(APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC) (GLuint program, const GLchar* uniformBlockName);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
typedef void (APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
extern PFNGLGETUNIFORMINDICESPROC OglGetUniformIndices;
extern PFNGLGETACTIVEUNIFORMSIVPROC OglGetActiveUniformsiv;
extern PFNGLGETACTIVEUNIFORMNAMEPROC OglGetActiveUniformName;
extern PFNGLGETUNIFORMBLOCKINDEXPROC OglGetUniformBlockIndex;
extern PFNGLGETACTIVEUNIFORMBLOCKIVPROC OglGetActiveUniformBlockiv;
extern PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC OglGetActiveUniformBlockName;
extern PFNGLUNIFORMBLOCKBINDINGPROC OglUniformBlockBinding;
#endif

#ifndef GL_ARB_copy_buffer
#define GL_ARB_copy_buffer 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC) (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
extern PFNGLCOPYBUFFERSUBDATAPROC OglCopyBufferSubData;
#endif

#ifndef GL_ARB_depth_clamp
#define GL_ARB_depth_clamp 1
#endif

#ifndef GL_ARB_draw_elements_base_vertex
#define GL_ARB_draw_elements_base_vertex 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
GLAPI void APIENTRY glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
GLAPI void APIENTRY glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount, GLint basevertex);
GLAPI void APIENTRY glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei* count, GLenum type, const GLvoid* const* indices, GLsizei drawcount, const GLint* basevertex);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC) (GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC) (GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount, GLint basevertex);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC) (GLenum mode, const GLsizei* count, GLenum type, const GLvoid* const* indices, GLsizei drawcount, const GLint* basevertex);
extern PFNGLDRAWELEMENTSBASEVERTEXPROC OglDrawElementsBaseVertex;
extern PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC OglDrawRangeElementsBaseVertex;
extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC OglDrawElementsInstancedBaseVertex;
extern PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC OglMultiDrawElementsBaseVertex;
#endif

#ifndef GL_ARB_fragment_coord_conventions
#define GL_ARB_fragment_coord_conventions 1
#endif

#ifndef GL_ARB_provoking_vertex
#define GL_ARB_provoking_vertex 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glProvokingVertex(GLenum mode);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLPROVOKINGVERTEXPROC) (GLenum mode);
extern PFNGLPROVOKINGVERTEXPROC OglProvokingVertex;
#endif

#ifndef GL_ARB_seamless_cube_map
#define GL_ARB_seamless_cube_map 1
#endif

#ifndef GL_ARB_sync
#define GL_ARB_sync 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI GLsync APIENTRY glFenceSync(GLenum condition, GLbitfield flags);
GLAPI GLboolean APIENTRY glIsSync(GLsync sync);
GLAPI void APIENTRY glDeleteSync(GLsync sync);
GLAPI GLenum APIENTRY glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
GLAPI void APIENTRY glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
GLAPI void APIENTRY glGetInteger64v(GLenum pname, GLint64* params);
GLAPI void APIENTRY glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei* length, GLint* values);
#endif // GLCOREARB_PROTOTYPES
typedef GLsync(APIENTRYP PFNGLFENCESYNCPROC) (GLenum condition, GLbitfield flags);
typedef GLboolean(APIENTRYP PFNGLISSYNCPROC) (GLsync sync);
typedef void (APIENTRYP PFNGLDELETESYNCPROC) (GLsync sync);
typedef GLenum(APIENTRYP PFNGLCLIENTWAITSYNCPROC) (GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (APIENTRYP PFNGLWAITSYNCPROC) (GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (APIENTRYP PFNGLGETINTEGER64VPROC) (GLenum pname, GLint64* params);
typedef void (APIENTRYP PFNGLGETSYNCIVPROC) (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei* length, GLint* values);
extern PFNGLFENCESYNCPROC OglFenceSync;
extern PFNGLISSYNCPROC OglIsSync;
extern PFNGLDELETESYNCPROC OglDeleteSync;
extern PFNGLCLIENTWAITSYNCPROC OglClientWaitSync;
extern PFNGLWAITSYNCPROC OglWaitSync;
extern PFNGLGETINTEGER64VPROC OglGetInteger64v;
extern PFNGLGETSYNCIVPROC OglGetSynciv;
#endif

#ifndef GL_ARB_texture_multisample
#define GL_ARB_texture_multisample 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glTexImage2DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTexImage3DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glGetMultisamplefv(GLenum pname, GLuint index, GLfloat* val);
GLAPI void APIENTRY glSampleMaski(GLuint index, GLbitfield mask);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVPROC) (GLenum pname, GLuint index, GLfloat* val);
typedef void (APIENTRYP PFNGLSAMPLEMASKIPROC) (GLuint index, GLbitfield mask);
extern PFNGLTEXIMAGE2DMULTISAMPLEPROC OglTexImage2DMultisample;
extern PFNGLTEXIMAGE3DMULTISAMPLEPROC OglTexImage3DMultisample;
extern PFNGLGETMULTISAMPLEFVPROC OglGetMultisamplefv;
extern PFNGLSAMPLEMASKIPROC OglSampleMaski;
#endif	// GL_ARB_texture_multisample

#ifndef GL_ARB_vertex_array_bgra
#define GL_ARB_vertex_array_bgra 1
#endif

#ifndef GL_ARB_draw_buffers_blend
#define GL_ARB_draw_buffers_blend 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glBlendEquationiARB(GLuint buf, GLenum mode);
GLAPI void APIENTRY glBlendEquationSeparateiARB(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLAPI void APIENTRY glBlendFunciARB(GLuint buf, GLenum src, GLenum dst);
GLAPI void APIENTRY glBlendFuncSeparateiARB(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLBLENDEQUATIONIARBPROC) (GLuint buf, GLenum mode);
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIARBPROC) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLBLENDFUNCIARBPROC) (GLuint buf, GLenum src, GLenum dst);
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIARBPROC) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
extern PFNGLBLENDEQUATIONIARBPROC OglBlendEquationiARB;
extern PFNGLBLENDEQUATIONSEPARATEIARBPROC OglBlendEquationSeparateiARB;
extern PFNGLBLENDFUNCIARBPROC OglBlendFunciARB;
extern PFNGLBLENDFUNCSEPARATEIARBPROC OglBlendFuncSeparateiARB;
#endif

#ifndef GL_ARB_sample_shading
#define GL_ARB_sample_shading 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glMinSampleShadingARB(GLfloat value);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLMINSAMPLESHADINGARBPROC) (GLfloat value);
extern PFNGLMINSAMPLESHADINGARBPROC OglMinSampleShadingARB;
#endif

#ifndef GL_ARB_texture_cube_map_array
#define GL_ARB_texture_cube_map_array 1
#endif

#ifndef GL_ARB_texture_gather
#define GL_ARB_texture_gather 1
#endif

#ifndef GL_ARB_texture_query_lod
#define GL_ARB_texture_query_lod 1
#endif

#ifndef GL_ARB_shading_language_include
#define GL_ARB_shading_language_include 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glNamedStringARB(GLenum type, GLint namelen, const GLchar* name, GLint stringlen, const GLchar* string);
GLAPI void APIENTRY glDeleteNamedStringARB(GLint namelen, const GLchar* name);
GLAPI void APIENTRY glCompileShaderIncludeARB(GLuint shader, GLsizei count, const GLchar** path, const GLint* length);
GLAPI GLboolean APIENTRY glIsNamedStringARB(GLint namelen, const GLchar* name);
GLAPI void APIENTRY glGetNamedStringARB(GLint namelen, const GLchar* name, GLsizei bufSize, GLint* stringlen, GLchar* string);
GLAPI void APIENTRY glGetNamedStringivARB(GLint namelen, const GLchar* name, GLenum pname, GLint* params);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLNAMEDSTRINGARBPROC) (GLenum type, GLint namelen, const GLchar* name, GLint stringlen, const GLchar* string);
typedef void (APIENTRYP PFNGLDELETENAMEDSTRINGARBPROC) (GLint namelen, const GLchar* name);
typedef void (APIENTRYP PFNGLCOMPILESHADERINCLUDEARBPROC) (GLuint shader, GLsizei count, const GLchar** path, const GLint* length);
typedef GLboolean(APIENTRYP PFNGLISNAMEDSTRINGARBPROC) (GLint namelen, const GLchar* name);
typedef void (APIENTRYP PFNGLGETNAMEDSTRINGARBPROC) (GLint namelen, const GLchar* name, GLsizei bufSize, GLint* stringlen, GLchar* string);
typedef void (APIENTRYP PFNGLGETNAMEDSTRINGIVARBPROC) (GLint namelen, const GLchar* name, GLenum pname, GLint* params);
extern PFNGLNAMEDSTRINGARBPROC OglNamedStringARB;
extern PFNGLDELETENAMEDSTRINGARBPROC OglDeleteNamedStringARB;
extern PFNGLCOMPILESHADERINCLUDEARBPROC OglCompileShaderIncludeARB;
extern PFNGLISNAMEDSTRINGARBPROC OglIsNamedStringARB;
extern PFNGLGETNAMEDSTRINGARBPROC OglGetNamedStringARB;
extern PFNGLGETNAMEDSTRINGIVARBPROC OglGetNamedStringivARB;
#endif

#ifndef GL_ARB_texture_compression_bptc
#define GL_ARB_texture_compression_bptc 1
#endif

#ifndef GL_ARB_blend_func_extended
#define GL_ARB_blend_func_extended 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name);
GLAPI GLint APIENTRY glGetFragDataIndex(GLuint program, const GLchar* name);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC) (GLuint program, GLuint colorNumber, GLuint index, const GLchar* name);
typedef GLint(APIENTRYP PFNGLGETFRAGDATAINDEXPROC) (GLuint program, const GLchar* name);
extern PFNGLBINDFRAGDATALOCATIONINDEXEDPROC OglBindFragDataLocationIndexed;
extern PFNGLGETFRAGDATAINDEXPROC OglGetFragDataIndex;
#endif

#ifndef GL_ARB_explicit_attrib_location
#define GL_ARB_explicit_attrib_location 1
#endif

#ifndef GL_ARB_occlusion_query2
#define GL_ARB_occlusion_query2 1
#endif

#ifndef GL_ARB_sampler_objects
#define GL_ARB_sampler_objects 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glGenSamplers(GLsizei count, GLuint* samplers);
GLAPI void APIENTRY glDeleteSamplers(GLsizei count, const GLuint* samplers);
GLAPI GLboolean APIENTRY glIsSampler(GLuint sampler);
GLAPI void APIENTRY glBindSampler(GLuint unit, GLuint sampler);
GLAPI void APIENTRY glSamplerParameteri(GLuint sampler, GLenum pname, GLint param);
GLAPI void APIENTRY glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint* param);
GLAPI void APIENTRY glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param);
GLAPI void APIENTRY glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat* param);
GLAPI void APIENTRY glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint* param);
GLAPI void APIENTRY glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint* param);
GLAPI void APIENTRY glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint* params);
GLAPI void APIENTRY glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint* params);
GLAPI void APIENTRY glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* params);
GLAPI void APIENTRY glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint* params);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLGENSAMPLERSPROC) (GLsizei count, GLuint* samplers);
typedef void (APIENTRYP PFNGLDELETESAMPLERSPROC) (GLsizei count, const GLuint* samplers);
typedef GLboolean(APIENTRYP PFNGLISSAMPLERPROC) (GLuint sampler);
typedef void (APIENTRYP PFNGLBINDSAMPLERPROC) (GLuint unit, GLuint sampler);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIPROC) (GLuint sampler, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, const GLint* param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFPROC) (GLuint sampler, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, const GLfloat* param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, const GLint* param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC) (GLuint sampler, GLenum pname, const GLuint* param);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, GLfloat* params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC) (GLuint sampler, GLenum pname, GLuint* params);
extern PFNGLGENSAMPLERSPROC OglGenSamplers;
extern PFNGLDELETESAMPLERSPROC OglDeleteSamplers;
extern PFNGLISSAMPLERPROC OglIsSampler;
extern PFNGLBINDSAMPLERPROC OglBindSampler;
extern PFNGLSAMPLERPARAMETERIPROC OglSamplerParameteri;
extern PFNGLSAMPLERPARAMETERIVPROC OglSamplerParameteriv;
extern PFNGLSAMPLERPARAMETERFPROC OglSamplerParameterf;
extern PFNGLSAMPLERPARAMETERFVPROC OglSamplerParameterfv;
extern PFNGLSAMPLERPARAMETERIIVPROC OglSamplerParameterIiv;
extern PFNGLSAMPLERPARAMETERIUIVPROC OglSamplerParameterIuiv;
extern PFNGLGETSAMPLERPARAMETERIVPROC OglGetSamplerParameteriv;
extern PFNGLGETSAMPLERPARAMETERIIVPROC OglGetSamplerParameterIiv;
extern PFNGLGETSAMPLERPARAMETERFVPROC OglGetSamplerParameterfv;
extern PFNGLGETSAMPLERPARAMETERIUIVPROC OglGetSamplerParameterIuiv;
#endif

#ifndef GL_ARB_shader_bit_encoding
#define GL_ARB_shader_bit_encoding 1
#endif

#ifndef GL_ARB_texture_rgb10_a2ui
#define GL_ARB_texture_rgb10_a2ui 1
#endif

#ifndef GL_ARB_texture_swizzle
#define GL_ARB_texture_swizzle 1
#endif

#ifndef GL_ARB_timer_query
#define GL_ARB_timer_query 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glQueryCounter(GLuint id, GLenum target);
GLAPI void APIENTRY glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64* params);
GLAPI void APIENTRY glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64* params);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLQUERYCOUNTERPROC) (GLuint id, GLenum target);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VPROC) (GLuint id, GLenum pname, GLint64* params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC) (GLuint id, GLenum pname, GLuint64* params);
#endif

#ifndef GL_ARB_vertex_type_2_10_10_10_rev
#define GL_ARB_vertex_type_2_10_10_10_rev 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glVertexP2ui(GLenum type, GLuint value);
GLAPI void APIENTRY glVertexP2uiv(GLenum type, const GLuint* value);
GLAPI void APIENTRY glVertexP3ui(GLenum type, GLuint value);
GLAPI void APIENTRY glVertexP3uiv(GLenum type, const GLuint* value);
GLAPI void APIENTRY glVertexP4ui(GLenum type, GLuint value);
GLAPI void APIENTRY glVertexP4uiv(GLenum type, const GLuint* value);
GLAPI void APIENTRY glTexCoordP1ui(GLenum type, GLuint coords);
GLAPI void APIENTRY glTexCoordP1uiv(GLenum type, const GLuint* coords);
GLAPI void APIENTRY glTexCoordP2ui(GLenum type, GLuint coords);
GLAPI void APIENTRY glTexCoordP2uiv(GLenum type, const GLuint* coords);
GLAPI void APIENTRY glTexCoordP3ui(GLenum type, GLuint coords);
GLAPI void APIENTRY glTexCoordP3uiv(GLenum type, const GLuint* coords);
GLAPI void APIENTRY glTexCoordP4ui(GLenum type, GLuint coords);
GLAPI void APIENTRY glTexCoordP4uiv(GLenum type, const GLuint* coords);
GLAPI void APIENTRY glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords);
GLAPI void APIENTRY glMultiTexCoordP1uiv(GLenum texture, GLenum type, const GLuint* coords);
GLAPI void APIENTRY glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords);
GLAPI void APIENTRY glMultiTexCoordP2uiv(GLenum texture, GLenum type, const GLuint* coords);
GLAPI void APIENTRY glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords);
GLAPI void APIENTRY glMultiTexCoordP3uiv(GLenum texture, GLenum type, const GLuint* coords);
GLAPI void APIENTRY glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords);
GLAPI void APIENTRY glMultiTexCoordP4uiv(GLenum texture, GLenum type, const GLuint* coords);
GLAPI void APIENTRY glNormalP3ui(GLenum type, GLuint coords);
GLAPI void APIENTRY glNormalP3uiv(GLenum type, const GLuint* coords);
GLAPI void APIENTRY glColorP3ui(GLenum type, GLuint color);
GLAPI void APIENTRY glColorP3uiv(GLenum type, const GLuint* color);
GLAPI void APIENTRY glColorP4ui(GLenum type, GLuint color);
GLAPI void APIENTRY glColorP4uiv(GLenum type, const GLuint* color);
GLAPI void APIENTRY glSecondaryColorP3ui(GLenum type, GLuint color);
GLAPI void APIENTRY glSecondaryColorP3uiv(GLenum type, const GLuint* color);
GLAPI void APIENTRY glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
GLAPI void APIENTRY glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
GLAPI void APIENTRY glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
GLAPI void APIENTRY glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLVERTEXP2UIPROC) (GLenum type, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXP2UIVPROC) (GLenum type, const GLuint* value);
typedef void (APIENTRYP PFNGLVERTEXP3UIPROC) (GLenum type, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXP3UIVPROC) (GLenum type, const GLuint* value);
typedef void (APIENTRYP PFNGLVERTEXP4UIPROC) (GLenum type, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXP4UIVPROC) (GLenum type, const GLuint* value);
typedef void (APIENTRYP PFNGLTEXCOORDP1UIPROC) (GLenum type, GLuint coords);
typedef void (APIENTRYP PFNGLTEXCOORDP1UIVPROC) (GLenum type, const GLuint* coords);
typedef void (APIENTRYP PFNGLTEXCOORDP2UIPROC) (GLenum type, GLuint coords);
typedef void (APIENTRYP PFNGLTEXCOORDP2UIVPROC) (GLenum type, const GLuint* coords);
typedef void (APIENTRYP PFNGLTEXCOORDP3UIPROC) (GLenum type, GLuint coords);
typedef void (APIENTRYP PFNGLTEXCOORDP3UIVPROC) (GLenum type, const GLuint* coords);
typedef void (APIENTRYP PFNGLTEXCOORDP4UIPROC) (GLenum type, GLuint coords);
typedef void (APIENTRYP PFNGLTEXCOORDP4UIVPROC) (GLenum type, const GLuint* coords);
typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIPROC) (GLenum texture, GLenum type, GLuint coords);
typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIVPROC) (GLenum texture, GLenum type, const GLuint* coords);
typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIPROC) (GLenum texture, GLenum type, GLuint coords);
typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIVPROC) (GLenum texture, GLenum type, const GLuint* coords);
typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIPROC) (GLenum texture, GLenum type, GLuint coords);
typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIVPROC) (GLenum texture, GLenum type, const GLuint* coords);
typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIPROC) (GLenum texture, GLenum type, GLuint coords);
typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIVPROC) (GLenum texture, GLenum type, const GLuint* coords);
typedef void (APIENTRYP PFNGLNORMALP3UIPROC) (GLenum type, GLuint coords);
typedef void (APIENTRYP PFNGLNORMALP3UIVPROC) (GLenum type, const GLuint* coords);
typedef void (APIENTRYP PFNGLCOLORP3UIPROC) (GLenum type, GLuint color);
typedef void (APIENTRYP PFNGLCOLORP3UIVPROC) (GLenum type, const GLuint* color);
typedef void (APIENTRYP PFNGLCOLORP4UIPROC) (GLenum type, GLuint color);
typedef void (APIENTRYP PFNGLCOLORP4UIVPROC) (GLenum type, const GLuint* color);
typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIPROC) (GLenum type, GLuint color);
typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIVPROC) (GLenum type, const GLuint* color);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
#endif

#ifndef GL_ARB_draw_indirect
#define GL_ARB_draw_indirect 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glDrawArraysIndirect(GLenum mode, const GLvoid* indirect);
GLAPI void APIENTRY glDrawElementsIndirect(GLenum mode, GLenum type, const GLvoid* indirect);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC) (GLenum mode, const GLvoid* indirect);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC) (GLenum mode, GLenum type, const GLvoid* indirect);
#endif

#ifndef GL_ARB_gpu_shader5
#define GL_ARB_gpu_shader5 1
#endif

#ifndef GL_ARB_gpu_shader_fp64
#define GL_ARB_gpu_shader_fp64 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glUniform1d(GLint location, GLdouble x);
GLAPI void APIENTRY glUniform2d(GLint location, GLdouble x, GLdouble y);
GLAPI void APIENTRY glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void APIENTRY glUniform1dv(GLint location, GLsizei count, const GLdouble* value);
GLAPI void APIENTRY glUniform2dv(GLint location, GLsizei count, const GLdouble* value);
GLAPI void APIENTRY glUniform3dv(GLint location, GLsizei count, const GLdouble* value);
GLAPI void APIENTRY glUniform4dv(GLint location, GLsizei count, const GLdouble* value);
GLAPI void APIENTRY glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY glGetUniformdv(GLuint program, GLint location, GLdouble* params);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLUNIFORM1DPROC) (GLint location, GLdouble x);
typedef void (APIENTRYP PFNGLUNIFORM2DPROC) (GLint location, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLUNIFORM3DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLUNIFORM4DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLUNIFORM1DVPROC) (GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORM2DVPROC) (GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORM3DVPROC) (GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORM4DVPROC) (GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLGETUNIFORMDVPROC) (GLuint program, GLint location, GLdouble* params);
#endif

#ifndef GL_ARB_shader_subroutine
#define GL_ARB_shader_subroutine 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI GLint APIENTRY glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar* name);
GLAPI GLuint APIENTRY glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar* name);
GLAPI void APIENTRY glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values);
GLAPI void APIENTRY glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name);
GLAPI void APIENTRY glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name);
GLAPI void APIENTRY glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint* indices);
GLAPI void APIENTRY glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint* params);
GLAPI void APIENTRY glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint* values);
#endif // GLCOREARB_PROTOTYPES
typedef GLint(APIENTRYP PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC) (GLuint program, GLenum shadertype, const GLchar* name);
typedef GLuint(APIENTRYP PFNGLGETSUBROUTINEINDEXPROC) (GLuint program, GLenum shadertype, const GLchar* name);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC) (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name);
typedef void (APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC) (GLenum shadertype, GLsizei count, const GLuint* indices);
typedef void (APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC) (GLenum shadertype, GLint location, GLuint* params);
typedef void (APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC) (GLuint program, GLenum shadertype, GLenum pname, GLint* values);
#endif

#ifndef GL_ARB_tessellation_shader
#define GL_ARB_tessellation_shader 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glPatchParameteri(GLenum pname, GLint value);
GLAPI void APIENTRY glPatchParameterfv(GLenum pname, const GLfloat* values);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLPATCHPARAMETERIPROC) (GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLPATCHPARAMETERFVPROC) (GLenum pname, const GLfloat* values);
#endif

#ifndef GL_ARB_texture_buffer_object_rgb32
#define GL_ARB_texture_buffer_object_rgb32 1
#endif

#ifndef GL_ARB_transform_feedback2
#define GL_ARB_transform_feedback2 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glBindTransformFeedback(GLenum target, GLuint id);
GLAPI void APIENTRY glDeleteTransformFeedbacks(GLsizei n, const GLuint* ids);
GLAPI void APIENTRY glGenTransformFeedbacks(GLsizei n, GLuint* ids);
GLAPI GLboolean APIENTRY glIsTransformFeedback(GLuint id);
GLAPI void APIENTRY glPauseTransformFeedback(void);
GLAPI void APIENTRY glResumeTransformFeedback(void);
GLAPI void APIENTRY glDrawTransformFeedback(GLenum mode, GLuint id);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC) (GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC) (GLsizei n, const GLuint* ids);
typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC) (GLsizei n, GLuint* ids);
typedef GLboolean(APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC) (GLuint id);
typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC) (void);
typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC) (void);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC) (GLenum mode, GLuint id);
#endif

#ifndef GL_ARB_transform_feedback3
#define GL_ARB_transform_feedback3 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream);
GLAPI void APIENTRY glBeginQueryIndexed(GLenum target, GLuint index, GLuint id);
GLAPI void APIENTRY glEndQueryIndexed(GLenum target, GLuint index);
GLAPI void APIENTRY glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint* params);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC) (GLenum mode, GLuint id, GLuint stream);
typedef void (APIENTRYP PFNGLBEGINQUERYINDEXEDPROC) (GLenum target, GLuint index, GLuint id);
typedef void (APIENTRYP PFNGLENDQUERYINDEXEDPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLGETQUERYINDEXEDIVPROC) (GLenum target, GLuint index, GLenum pname, GLint* params);
#endif

#ifndef GL_ARB_ES2_compatibility
#define GL_ARB_ES2_compatibility 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glReleaseShaderCompiler(void);
GLAPI void APIENTRY glShaderBinary(GLsizei count, const GLuint* shaders, GLenum binaryformat, const GLvoid* binary, GLsizei length);
GLAPI void APIENTRY glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
GLAPI void APIENTRY glDepthRangef(GLfloat n, GLfloat f);
GLAPI void APIENTRY glClearDepthf(GLfloat d);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLRELEASESHADERCOMPILERPROC) (void);
typedef void (APIENTRYP PFNGLSHADERBINARYPROC) (GLsizei count, const GLuint* shaders, GLenum binaryformat, const GLvoid* binary, GLsizei length);
typedef void (APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC) (GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
typedef void (APIENTRYP PFNGLDEPTHRANGEFPROC) (GLfloat n, GLfloat f);
typedef void (APIENTRYP PFNGLCLEARDEPTHFPROC) (GLfloat d);
#endif

#ifndef GL_ARB_get_program_binary
#define GL_ARB_get_program_binary 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, GLvoid* binary);
GLAPI void APIENTRY glProgramBinary(GLuint program, GLenum binaryFormat, const GLvoid* binary, GLsizei length);
GLAPI void APIENTRY glProgramParameteri(GLuint program, GLenum pname, GLint value);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLGETPROGRAMBINARYPROC) (GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, GLvoid* binary);
typedef void (APIENTRYP PFNGLPROGRAMBINARYPROC) (GLuint program, GLenum binaryFormat, const GLvoid* binary, GLsizei length);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIPROC) (GLuint program, GLenum pname, GLint value);
#endif

#ifndef GL_ARB_separate_shader_objects
#define GL_ARB_separate_shader_objects 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program);
GLAPI void APIENTRY glActiveShaderProgram(GLuint pipeline, GLuint program);
GLAPI GLuint APIENTRY glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar* const* strings);
GLAPI void APIENTRY glBindProgramPipeline(GLuint pipeline);
GLAPI void APIENTRY glDeleteProgramPipelines(GLsizei n, const GLuint* pipelines);
GLAPI void APIENTRY glGenProgramPipelines(GLsizei n, GLuint* pipelines);
GLAPI GLboolean APIENTRY glIsProgramPipeline(GLuint pipeline);
GLAPI void APIENTRY glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint* params);
GLAPI void APIENTRY glProgramUniform1i(GLuint program, GLint location, GLint v0);
GLAPI void APIENTRY glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint* value);
GLAPI void APIENTRY glProgramUniform1f(GLuint program, GLint location, GLfloat v0);
GLAPI void APIENTRY glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat* value);
GLAPI void APIENTRY glProgramUniform1d(GLuint program, GLint location, GLdouble v0);
GLAPI void APIENTRY glProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble* value);
GLAPI void APIENTRY glProgramUniform1ui(GLuint program, GLint location, GLuint v0);
GLAPI void APIENTRY glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint* value);
GLAPI void APIENTRY glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1);
GLAPI void APIENTRY glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint* value);
GLAPI void APIENTRY glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1);
GLAPI void APIENTRY glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat* value);
GLAPI void APIENTRY glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1);
GLAPI void APIENTRY glProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble* value);
GLAPI void APIENTRY glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1);
GLAPI void APIENTRY glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint* value);
GLAPI void APIENTRY glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void APIENTRY glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint* value);
GLAPI void APIENTRY glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void APIENTRY glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat* value);
GLAPI void APIENTRY glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
GLAPI void APIENTRY glProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble* value);
GLAPI void APIENTRY glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void APIENTRY glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint* value);
GLAPI void APIENTRY glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void APIENTRY glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint* value);
GLAPI void APIENTRY glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void APIENTRY glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat* value);
GLAPI void APIENTRY glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
GLAPI void APIENTRY glProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble* value);
GLAPI void APIENTRY glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void APIENTRY glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint* value);
GLAPI void APIENTRY glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void APIENTRY glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void APIENTRY glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void APIENTRY glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void APIENTRY glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void APIENTRY glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void APIENTRY glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void APIENTRY glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void APIENTRY glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void APIENTRY glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void APIENTRY glValidateProgramPipeline(GLuint pipeline);
GLAPI void APIENTRY glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLUSEPROGRAMSTAGESPROC) (GLuint pipeline, GLbitfield stages, GLuint program);
typedef void (APIENTRYP PFNGLACTIVESHADERPROGRAMPROC) (GLuint pipeline, GLuint program);
typedef GLuint(APIENTRYP PFNGLCREATESHADERPROGRAMVPROC) (GLenum type, GLsizei count, const GLchar* const* strings);
typedef void (APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC) (GLsizei n, const GLuint* pipelines);
typedef void (APIENTRYP PFNGLGENPROGRAMPIPELINESPROC) (GLsizei n, GLuint* pipelines);
typedef GLboolean(APIENTRYP PFNGLISPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC) (GLuint pipeline, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IPROC) (GLuint program, GLint location, GLint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC) (GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FPROC) (GLuint program, GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DPROC) (GLuint program, GLint location, GLdouble v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC) (GLuint program, GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IPROC) (GLuint program, GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC) (GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC) (GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC) (GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC) (GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
extern PFNGLUSEPROGRAMSTAGESPROC OglUseProgramStages;
extern PFNGLACTIVESHADERPROGRAMPROC OglActiveShaderProgram;
extern PFNGLCREATESHADERPROGRAMVPROC OglCreateShaderProgramv;
extern PFNGLBINDPROGRAMPIPELINEPROC OglBindProgramPipeline;
extern PFNGLDELETEPROGRAMPIPELINESPROC OglDeleteProgramPipelines;
extern PFNGLGENPROGRAMPIPELINESPROC OglGenProgramPipelines;
extern PFNGLISPROGRAMPIPELINEPROC OglIsProgramPipeline;
extern PFNGLGETPROGRAMPIPELINEIVPROC OglGetProgramPipelineiv;
extern PFNGLPROGRAMUNIFORM1IPROC OglProgramUniform1i;
extern PFNGLPROGRAMUNIFORM1IVPROC OglProgramUniform1iv;
extern PFNGLPROGRAMUNIFORM1FPROC OglProgramUniform1f;
extern PFNGLPROGRAMUNIFORM1FVPROC OglProgramUniform1fv;
extern PFNGLPROGRAMUNIFORM1DPROC OglProgramUniform1d;
extern PFNGLPROGRAMUNIFORM1DVPROC OglProgramUniform1dv;
extern PFNGLPROGRAMUNIFORM1UIPROC OglProgramUniform1ui;
extern PFNGLPROGRAMUNIFORM1UIVPROC OglProgramUniform1uiv;
extern PFNGLPROGRAMUNIFORM2IPROC OglProgramUniform2i;
extern PFNGLPROGRAMUNIFORM2IVPROC OglProgramUniform2iv;
extern PFNGLPROGRAMUNIFORM2FPROC OglProgramUniform2f;
extern PFNGLPROGRAMUNIFORM2FVPROC OglProgramUniform2fv;
extern PFNGLPROGRAMUNIFORM2DPROC OglProgramUniform2d;
extern PFNGLPROGRAMUNIFORM2DVPROC OglProgramUniform2dv;
extern PFNGLPROGRAMUNIFORM2UIPROC OglProgramUniform2ui;
extern PFNGLPROGRAMUNIFORM2UIVPROC OglProgramUniform2uiv;
extern PFNGLPROGRAMUNIFORM3IPROC OglProgramUniform3i;
extern PFNGLPROGRAMUNIFORM3IVPROC OglProgramUniform3iv;
extern PFNGLPROGRAMUNIFORM3FPROC OglProgramUniform3f;
extern PFNGLPROGRAMUNIFORM3FVPROC OglProgramUniform3fv;
extern PFNGLPROGRAMUNIFORM3DPROC OglProgramUniform3d;
extern PFNGLPROGRAMUNIFORM3DVPROC OglProgramUniform3dv;
extern PFNGLPROGRAMUNIFORM3UIPROC OglProgramUniform3ui;
extern PFNGLPROGRAMUNIFORM3UIVPROC OglProgramUniform3uiv;
extern PFNGLPROGRAMUNIFORM4IPROC OglProgramUniform4i;
extern PFNGLPROGRAMUNIFORM4IVPROC OglProgramUniform4iv;
extern PFNGLPROGRAMUNIFORM4FPROC OglProgramUniform4f;
extern PFNGLPROGRAMUNIFORM4FVPROC OglProgramUniform4fv;
extern PFNGLPROGRAMUNIFORM4DPROC OglProgramUniform4d;
extern PFNGLPROGRAMUNIFORM4DVPROC OglProgramUniform4dv;
extern PFNGLPROGRAMUNIFORM4UIPROC OglProgramUniform4ui;
extern PFNGLPROGRAMUNIFORM4UIVPROC OglProgramUniform4uiv;
extern PFNGLPROGRAMUNIFORMMATRIX2FVPROC OglProgramUniformMatrix2fv;
extern PFNGLPROGRAMUNIFORMMATRIX3FVPROC OglProgramUniformMatrix3fv;
extern PFNGLPROGRAMUNIFORMMATRIX4FVPROC OglProgramUniformMatrix4fv;
extern PFNGLPROGRAMUNIFORMMATRIX2DVPROC OglProgramUniformMatrix2dv;
extern PFNGLPROGRAMUNIFORMMATRIX3DVPROC OglProgramUniformMatrix3dv;
extern PFNGLPROGRAMUNIFORMMATRIX4DVPROC OglProgramUniformMatrix4dv;
extern PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC OglProgramUniformMatrix2x3fv;
extern PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC OglProgramUniformMatrix3x2fv;
extern PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC OglProgramUniformMatrix2x4fv;
extern PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC OglProgramUniformMatrix4x2fv;
extern PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC OglProgramUniformMatrix3x4fv;
extern PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC OglProgramUniformMatrix4x3fv;
extern PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC OglProgramUniformMatrix2x3dv;
extern PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC OglProgramUniformMatrix3x2dv;
extern PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC OglProgramUniformMatrix2x4dv;
extern PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC OglProgramUniformMatrix4x2dv;
extern PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC OglProgramUniformMatrix3x4dv;
extern PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC OglProgramUniformMatrix4x3dv;
extern PFNGLVALIDATEPROGRAMPIPELINEPROC OglValidateProgramPipeline;
extern PFNGLGETPROGRAMPIPELINEINFOLOGPROC OglGetProgramPipelineInfoLog;
#endif

#ifndef GL_ARB_vertex_attrib_64bit
#define GL_ARB_vertex_attrib_64bit 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glVertexAttribL1d(GLuint index, GLdouble x);
GLAPI void APIENTRY glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y);
GLAPI void APIENTRY glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void APIENTRY glVertexAttribL1dv(GLuint index, const GLdouble* v);
GLAPI void APIENTRY glVertexAttribL2dv(GLuint index, const GLdouble* v);
GLAPI void APIENTRY glVertexAttribL3dv(GLuint index, const GLdouble* v);
GLAPI void APIENTRY glVertexAttribL4dv(GLuint index, const GLdouble* v);
GLAPI void APIENTRY glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
GLAPI void APIENTRY glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble* params);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DPROC) (GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DVPROC) (GLuint index, const GLdouble* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DVPROC) (GLuint index, const GLdouble* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DVPROC) (GLuint index, const GLdouble* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DVPROC) (GLuint index, const GLdouble* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLDVPROC) (GLuint index, GLenum pname, GLdouble* params);
#endif

#ifndef GL_ARB_viewport_array
#define GL_ARB_viewport_array 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glViewportArrayv(GLuint first, GLsizei count, const GLfloat* v);
GLAPI void APIENTRY glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
GLAPI void APIENTRY glViewportIndexedfv(GLuint index, const GLfloat* v);
GLAPI void APIENTRY glScissorArrayv(GLuint first, GLsizei count, const GLint* v);
GLAPI void APIENTRY glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
GLAPI void APIENTRY glScissorIndexedv(GLuint index, const GLint* v);
GLAPI void APIENTRY glDepthRangeArrayv(GLuint first, GLsizei count, const GLdouble* v);
GLAPI void APIENTRY glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f);
GLAPI void APIENTRY glGetFloati_v(GLenum target, GLuint index, GLfloat* data);
GLAPI void APIENTRY glGetDoublei_v(GLenum target, GLuint index, GLdouble* data);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLVIEWPORTARRAYVPROC) (GLuint first, GLsizei count, const GLfloat* v);
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFVPROC) (GLuint index, const GLfloat* v);
typedef void (APIENTRYP PFNGLSCISSORARRAYVPROC) (GLuint first, GLsizei count, const GLint* v);
typedef void (APIENTRYP PFNGLSCISSORINDEXEDPROC) (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLSCISSORINDEXEDVPROC) (GLuint index, const GLint* v);
typedef void (APIENTRYP PFNGLDEPTHRANGEARRAYVPROC) (GLuint first, GLsizei count, const GLdouble* v);
typedef void (APIENTRYP PFNGLDEPTHRANGEINDEXEDPROC) (GLuint index, GLdouble n, GLdouble f);
typedef void (APIENTRYP PFNGLGETFLOATI_VPROC) (GLenum target, GLuint index, GLfloat* data);
typedef void (APIENTRYP PFNGLGETDOUBLEI_VPROC) (GLenum target, GLuint index, GLdouble* data);
#endif

#ifndef GL_ARB_cl_event
#define GL_ARB_cl_event 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI GLsync APIENTRY glCreateSyncFromCLeventARB(struct _cl_context* context, struct _cl_event* event, GLbitfield flags);
#endif // GLCOREARB_PROTOTYPES
typedef GLsync(APIENTRYP PFNGLCREATESYNCFROMCLEVENTARBPROC) (struct _cl_context* context, struct _cl_event* event, GLbitfield flags);
#endif

#ifndef GL_ARB_debug_output
#define GL_ARB_debug_output 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glDebugMessageControlARB(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
GLAPI void APIENTRY glDebugMessageInsertARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
GLAPI void APIENTRY glDebugMessageCallbackARB(GLDEBUGPROCARB callback, const GLvoid* userParam);
GLAPI GLuint APIENTRY glGetDebugMessageLogARB(GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLARBPROC) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTARBPROC) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKARBPROC) (GLDEBUGPROCARB callback, const GLvoid* userParam);
typedef GLuint(APIENTRYP PFNGLGETDEBUGMESSAGELOGARBPROC) (GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
#endif

#ifndef GL_ARB_robustness
#define GL_ARB_robustness 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI GLenum APIENTRY glGetGraphicsResetStatusARB(void);
GLAPI void APIENTRY glGetnTexImageARB(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* img);
GLAPI void APIENTRY glReadnPixelsARB(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid* data);
GLAPI void APIENTRY glGetnCompressedTexImageARB(GLenum target, GLint lod, GLsizei bufSize, GLvoid* img);
GLAPI void APIENTRY glGetnUniformfvARB(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
GLAPI void APIENTRY glGetnUniformivARB(GLuint program, GLint location, GLsizei bufSize, GLint* params);
GLAPI void APIENTRY glGetnUniformuivARB(GLuint program, GLint location, GLsizei bufSize, GLuint* params);
GLAPI void APIENTRY glGetnUniformdvARB(GLuint program, GLint location, GLsizei bufSize, GLdouble* params);
#endif // GLCOREARB_PROTOTYPES
typedef GLenum(APIENTRYP PFNGLGETGRAPHICSRESETSTATUSARBPROC) (void);
typedef void (APIENTRYP PFNGLGETNTEXIMAGEARBPROC) (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* img);
typedef void (APIENTRYP PFNGLREADNPIXELSARBPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid* data);
typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC) (GLenum target, GLint lod, GLsizei bufSize, GLvoid* img);
typedef void (APIENTRYP PFNGLGETNUNIFORMFVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
typedef void (APIENTRYP PFNGLGETNUNIFORMIVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLint* params);
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLuint* params);
typedef void (APIENTRYP PFNGLGETNUNIFORMDVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLdouble* params);
#endif

#ifndef GL_ARB_shader_stencil_export
#define GL_ARB_shader_stencil_export 1
#endif

#ifndef GL_ARB_base_instance
#define GL_ARB_base_instance 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
GLAPI void APIENTRY glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLuint baseinstance);
GLAPI void APIENTRY glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLuint baseinstance);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
#endif

#ifndef GL_ARB_shading_language_420pack
#define GL_ARB_shading_language_420pack 1
#endif

#ifndef GL_ARB_transform_feedback_instanced
#define GL_ARB_transform_feedback_instanced 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount);
GLAPI void APIENTRY glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC) (GLenum mode, GLuint id, GLsizei instancecount);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC) (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#endif

#ifndef GL_ARB_compressed_texture_pixel_storage
#define GL_ARB_compressed_texture_pixel_storage 1
#endif

#ifndef GL_ARB_conservative_depth
#define GL_ARB_conservative_depth 1
#endif

#ifndef GL_ARB_internalformat_query
#define GL_ARB_internalformat_query 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint* params);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLGETINTERNALFORMATIVPROC) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint* params);
#endif

#ifndef GL_ARB_map_buffer_alignment
#define GL_ARB_map_buffer_alignment 1
#endif

#ifndef GL_ARB_shader_atomic_counters
#define GL_ARB_shader_atomic_counters 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glGetActiveAtomicCounterefferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint* params);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC) (GLuint program, GLuint bufferIndex, GLenum pname, GLint* params);
#endif

#ifndef GL_ARB_shader_image_load_store
#define GL_ARB_shader_image_load_store 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
GLAPI void APIENTRY glMemoryBarrier(GLbitfield barriers);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLBINDIMAGETEXTUREPROC) (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
typedef void (APIENTRYP PFNGLMEMORYBARRIERPROC) (GLbitfield barriers);
#endif

#ifndef GL_ARB_shading_language_packing
#define GL_ARB_shading_language_packing 1
#endif

#ifndef GL_ARB_texture_storage
#define GL_ARB_texture_storage 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI void APIENTRY glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void APIENTRY glTextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI void APIENTRY glTextureStorage2DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTextureStorage3DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLTEXSTORAGE1DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLTEXSTORAGE2DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXSTORAGE3DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DEXTPROC) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DEXTPROC) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DEXTPROC) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#endif

#ifndef GL_KHR_texture_compression_astc_ldr
#define GL_KHR_texture_compression_astc_ldr 1
#endif

#ifndef GL_KHR_debug
#define GL_KHR_debug 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
GLAPI void APIENTRY glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
GLAPI void APIENTRY glDebugMessageCallback(GLDEBUGPROC callback, const void* userParam);
GLAPI GLuint APIENTRY glGetDebugMessageLog(GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
GLAPI void APIENTRY glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar* message);
GLAPI void APIENTRY glPopDebugGroup(void);
GLAPI void APIENTRY glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar* label);
GLAPI void APIENTRY glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label);
GLAPI void APIENTRY glObjectPtrLabel(const void* ptr, GLsizei length, const GLchar* label);
GLAPI void APIENTRY glGetObjectPtrLabel(const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLPROC) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTPROC) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC) (GLDEBUGPROC callback, const void* userParam);
typedef GLuint(APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC) (GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
typedef void (APIENTRYP PFNGLPUSHDEBUGGROUPPROC) (GLenum source, GLuint id, GLsizei length, const GLchar* message);
typedef void (APIENTRYP PFNGLPOPDEBUGGROUPPROC) (void);
typedef void (APIENTRYP PFNGLOBJECTLABELPROC) (GLenum identifier, GLuint name, GLsizei length, const GLchar* label);
typedef void (APIENTRYP PFNGLGETOBJECTLABELPROC) (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label);
typedef void (APIENTRYP PFNGLOBJECTPTRLABELPROC) (const void* ptr, GLsizei length, const GLchar* label);
typedef void (APIENTRYP PFNGLGETOBJECTPTRLABELPROC) (const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label);
#endif

#ifndef GL_ARB_arrays_of_arrays
#define GL_ARB_arrays_of_arrays 1
#endif

#ifndef GL_ARB_clear_buffer_object
#define GL_ARB_clear_buffer_object 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glClearefferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data);
GLAPI void APIENTRY glClearefferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data);
GLAPI void APIENTRY glClearNamedBufferDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data);
GLAPI void APIENTRY glClearNamedBufferSubDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, GLsizeiptr offset, GLsizeiptr size, const void* data);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLCLEARBUFFERDATAPROC) (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data);
typedef void (APIENTRYP PFNGLCLEARBUFFERSUBDATAPROC) (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAEXTPROC) (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC) (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, GLsizeiptr offset, GLsizeiptr size, const void* data);
#endif

#ifndef GL_ARB_compute_shader
#define GL_ARB_compute_shader 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
GLAPI void APIENTRY glDispatchComputeIndirect(GLintptr indirect);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEPROC) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC) (GLintptr indirect);
extern PFNGLDISPATCHCOMPUTEPROC OglDispatchCompute;
extern PFNGLDISPATCHCOMPUTEINDIRECTPROC OglDispatchComputeIndirect;
#endif

#ifndef GL_ARB_copy_image
#define GL_ARB_copy_image 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLCOPYIMAGESUBDATAPROC) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
extern PFNGLCOPYIMAGESUBDATAPROC OglCopyImageSubData;
#endif

#ifndef GL_ARB_texture_view
#define GL_ARB_texture_view 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLTEXTUREVIEWPROC) (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
extern PFNGLTEXTUREVIEWPROC OglTextureView;
#endif

#ifndef GL_ARB_vertex_attrib_binding
#define GL_ARB_vertex_attrib_binding 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI void APIENTRY glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI void APIENTRY glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexAttribBinding(GLuint attribindex, GLuint bindingindex);
GLAPI void APIENTRY glVertexBindingDivisor(GLuint bindingindex, GLuint divisor);
GLAPI void APIENTRY glVertexArrayBindVertexBufferEXT(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI void APIENTRY glVertexArrayVertexAttribFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI void APIENTRY glVertexArrayVertexAttribIFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexArrayVertexAttribLFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexArrayVertexAttribBindingEXT(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
GLAPI void APIENTRY glVertexArrayVertexBindingDivisorEXT(GLuint vaobj, GLuint bindingindex, GLuint divisor);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERPROC) (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBBINDINGPROC) (GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLVERTEXBINDINGDIVISORPROC) (GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC) (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC) (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC) (GLuint vaobj, GLuint bindingindex, GLuint divisor);
extern PFNGLBINDVERTEXBUFFERPROC OglBindVertexBuffer;
extern PFNGLVERTEXATTRIBFORMATPROC OglVertexAttribFormat;
extern PFNGLVERTEXATTRIBIFORMATPROC OglVertexAttribIFormat;
extern PFNGLVERTEXATTRIBLFORMATPROC OglVertexAttribLFormat;
extern PFNGLVERTEXATTRIBBINDINGPROC OglVertexAttribBinding;
extern PFNGLVERTEXBINDINGDIVISORPROC OglVertexBindingDivisor;
extern PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC OglVertexArrayBindVertexBufferEXT;
extern PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC OglVertexArrayVertexAttribFormatEXT;
extern PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC OglVertexArrayVertexAttribIFormatEXT;
extern PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC OglVertexArrayVertexAttribLFormatEXT;
extern PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC OglVertexArrayVertexAttribBindingEXT;
extern PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC OglVertexArrayVertexBindingDivisorEXT;
#endif

#ifndef GL_ARB_robustness_isolation
#define GL_ARB_robustness_isolation 1
#endif

#ifndef GL_ARB_ES3_compatibility
#define GL_ARB_ES3_compatibility 1
#endif

#ifndef GL_ARB_explicit_uniform_location
#define GL_ARB_explicit_uniform_location 1
#endif

#ifndef GL_ARB_fragment_layer_viewport
#define GL_ARB_fragment_layer_viewport 1
#endif

#ifndef GL_ARB_framebuffer_no_attachments
#define GL_ARB_framebuffer_no_attachments 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glFramebufferParameteri(GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint* params);
GLAPI void APIENTRY glNamedFramebufferParameteriEXT(GLuint framebuffer, GLenum pname, GLint param);
GLAPI void APIENTRY glGetNamedFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint* params);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC) (GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC) (GLuint framebuffer, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC) (GLuint framebuffer, GLenum pname, GLint* params);
extern PFNGLFRAMEBUFFERPARAMETERIPROC OglFramebufferParameteri;
extern PFNGLGETFRAMEBUFFERPARAMETERIVPROC OglGetFramebufferParameteriv;
extern PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC OglNamedFramebufferParameteriEXT;
extern PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC OglGetNamedFramebufferParameterivEXT;
#endif

#ifndef GL_ARB_internalformat_query2
#define GL_ARB_internalformat_query2 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64* params);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLGETINTERNALFORMATI64VPROC) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64* params);
extern PFNGLGETINTERNALFORMATI64VPROC OglGetInternalformati64v;
#endif	// GL_ARB_internalformat_query2

#ifndef GL_ARB_invalidate_subdata
#define GL_ARB_invalidate_subdata 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void APIENTRY glInvalidateTexImage(GLuint texture, GLint level);
GLAPI void APIENTRY glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length);
GLAPI void APIENTRY glInvalidateBufferData(GLuint buffer);
GLAPI void APIENTRY glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments);
GLAPI void APIENTRY glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLINVALIDATETEXSUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLINVALIDATETEXIMAGEPROC) (GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERDATAPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC) (GLenum target, GLsizei numAttachments, const GLenum* attachments);
typedef void (APIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC) (GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height);
extern PFNGLINVALIDATETEXSUBIMAGEPROC OglInvalidateTexSubImage;
extern PFNGLINVALIDATETEXIMAGEPROC OglInvalidateTexImage;
extern PFNGLINVALIDATEBUFFERSUBDATAPROC OglInvalidateBufferSubData;
extern PFNGLINVALIDATEBUFFERDATAPROC OglInvalidateBufferData;
extern PFNGLINVALIDATEFRAMEBUFFERPROC OglInvalidateFramebuffer;
extern PFNGLINVALIDATESUBFRAMEBUFFERPROC OglInvalidateSubFramebuffer;
#endif	// GL_ARB_invalidate_subdata

#ifndef GL_ARB_multi_draw_indirect
#define GL_ARB_multi_draw_indirect 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glMultiDrawArraysIndirect(GLenum mode, const void* indirect, GLsizei drawcount, GLsizei stride);
GLAPI void APIENTRY glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect, GLsizei drawcount, GLsizei stride);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTPROC) (GLenum mode, const void* indirect, GLsizei drawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTPROC) (GLenum mode, GLenum type, const void* indirect, GLsizei drawcount, GLsizei stride);
extern PFNGLMULTIDRAWARRAYSINDIRECTPROC OglMultiDrawArraysIndirect;
extern PFNGLMULTIDRAWELEMENTSINDIRECTPROC OglMultiDrawElementsIndirect;
#endif	// GL_ARB_multi_draw_indirect

#ifndef GL_ARB_program_interface_query
#define GL_ARB_program_interface_query 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint* params);
GLAPI GLuint APIENTRY glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar* name);
GLAPI void APIENTRY glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
GLAPI void APIENTRY glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei bufSize, GLsizei* length, GLint* params);
GLAPI GLint APIENTRY glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar* name);
GLAPI GLint APIENTRY glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar* name);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC) (GLuint program, GLenum programInterface, GLenum pname, GLint* params);
typedef GLuint(APIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC) (GLuint program, GLenum programInterface, const GLchar* name);
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei bufSize, GLsizei* length, GLint* params);
typedef GLint(APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC) (GLuint program, GLenum programInterface, const GLchar* name);
typedef GLint(APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC) (GLuint program, GLenum programInterface, const GLchar* name);
extern PFNGLGETPROGRAMINTERFACEIVPROC OglGetProgramInterfaceiv;
extern PFNGLGETPROGRAMRESOURCEINDEXPROC OglGetProgramResourceIndex;
extern PFNGLGETPROGRAMRESOURCENAMEPROC OglGetProgramResourceName;
extern PFNGLGETPROGRAMRESOURCEIVPROC OglGetProgramResourceiv;
extern PFNGLGETPROGRAMRESOURCELOCATIONPROC OglGetProgramResourceLocation;
extern PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC OglGetProgramResourceLocationIndex;
#endif	// GL_ARB_program_interface_query

#ifndef GL_ARB_robust_buffer_access_behavior
#define GL_ARB_robust_buffer_access_behavior 1
#endif

#ifndef GL_ARB_shader_image_size
#define GL_ARB_shader_image_size 1
#endif

#ifndef GL_ARB_shader_storage_buffer_object
#define GL_ARB_shader_storage_buffer_object 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLSHADERSTORAGEBLOCKBINDINGPROC) (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
extern PFNGLSHADERSTORAGEBLOCKBINDINGPROC OglShaderStorageBlockBinding;
#endif

#ifndef GL_ARB_stencil_texturing
#define GL_ARB_stencil_texturing 1
#endif

#ifndef GL_ARB_texture_buffer_range
#define GL_ARB_texture_buffer_range 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void APIENTRY glTextureBufferRangeEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLTEXBUFFERRANGEPROC) (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEEXTPROC) (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
extern PFNGLTEXBUFFERRANGEPROC OglTexBufferRange;
extern PFNGLTEXTUREBUFFERRANGEEXTPROC OglTextureBufferRangeEXT;
#endif

#ifndef GL_ARB_texture_query_levels
#define GL_ARB_texture_query_levels 1
#endif

#ifndef GL_ARB_texture_storage_multisample
#define GL_ARB_texture_storage_multisample 1
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTextureStorage2DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTextureStorage3DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC) (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC) (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
extern PFNGLTEXSTORAGE2DMULTISAMPLEPROC OglTexStorage2DMultisample;
extern PFNGLTEXSTORAGE3DMULTISAMPLEPROC OglTexStorage3DMultisample;
extern PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC OglTextureStorage2DMultisampleEXT;
extern PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC OglTextureStorage3DMultisampleEXT;
#endif



extern PFNGLQUERYCOUNTERPROC OglQueryCounter;
extern PFNGLGETQUERYOBJECTI64VPROC OglGetQueryObjecti64v;
extern PFNGLGETQUERYOBJECTUI64VPROC OglGetQueryObjectui64v;
extern PFNGLVERTEXP2UIPROC OglVertexP2ui;
extern PFNGLVERTEXP2UIVPROC OglVertexP2uiv;
extern PFNGLVERTEXP3UIPROC OglVertexP3ui;
extern PFNGLVERTEXP3UIVPROC OglVertexP3uiv;
extern PFNGLVERTEXP4UIPROC OglVertexP4ui;
extern PFNGLVERTEXP4UIVPROC OglVertexP4uiv;
extern PFNGLTEXCOORDP1UIPROC OglTexCoordP1ui;
extern PFNGLTEXCOORDP1UIVPROC OglTexCoordP1uiv;
extern PFNGLTEXCOORDP2UIPROC OglTexCoordP2ui;
extern PFNGLTEXCOORDP2UIVPROC OglTexCoordP2uiv;
extern PFNGLTEXCOORDP3UIPROC OglTexCoordP3ui;
extern PFNGLTEXCOORDP3UIVPROC OglTexCoordP3uiv;
extern PFNGLTEXCOORDP4UIPROC OglTexCoordP4ui;
extern PFNGLTEXCOORDP4UIVPROC OglTexCoordP4uiv;
extern PFNGLMULTITEXCOORDP1UIPROC OglMultiTexCoordP1ui;
extern PFNGLMULTITEXCOORDP1UIVPROC OglMultiTexCoordP1uiv;
extern PFNGLMULTITEXCOORDP2UIPROC OglMultiTexCoordP2ui;
extern PFNGLMULTITEXCOORDP2UIVPROC OglMultiTexCoordP2uiv;
extern PFNGLMULTITEXCOORDP3UIPROC OglMultiTexCoordP3ui;
extern PFNGLMULTITEXCOORDP3UIVPROC OglMultiTexCoordP3uiv;
extern PFNGLMULTITEXCOORDP4UIPROC OglMultiTexCoordP4ui;
extern PFNGLMULTITEXCOORDP4UIVPROC OglMultiTexCoordP4uiv;
extern PFNGLNORMALP3UIPROC OglNormalP3ui;
extern PFNGLNORMALP3UIVPROC OglNormalP3uiv;
extern PFNGLCOLORP3UIPROC OglColorP3ui;
extern PFNGLCOLORP3UIVPROC OglColorP3uiv;
extern PFNGLCOLORP4UIPROC OglColorP4ui;
extern PFNGLCOLORP4UIVPROC OglColorP4uiv;
extern PFNGLSECONDARYCOLORP3UIPROC OglSecondaryColorP3ui;
extern PFNGLSECONDARYCOLORP3UIVPROC OglSecondaryColorP3uiv;
extern PFNGLVERTEXATTRIBP1UIPROC OglVertexAttribP1ui;
extern PFNGLVERTEXATTRIBP1UIVPROC OglVertexAttribP1uiv;
extern PFNGLVERTEXATTRIBP2UIPROC OglVertexAttribP2ui;
extern PFNGLVERTEXATTRIBP2UIVPROC OglVertexAttribP2uiv;
extern PFNGLVERTEXATTRIBP3UIPROC OglVertexAttribP3ui;
extern PFNGLVERTEXATTRIBP3UIVPROC OglVertexAttribP3uiv;
extern PFNGLVERTEXATTRIBP4UIPROC OglVertexAttribP4ui;
extern PFNGLVERTEXATTRIBP4UIVPROC OglVertexAttribP4uiv;
extern PFNGLDRAWARRAYSINDIRECTPROC OglDrawArraysIndirect;
extern PFNGLDRAWELEMENTSINDIRECTPROC OglDrawElementsIndirect;
extern PFNGLUNIFORM1DPROC OglUniform1d;
extern PFNGLUNIFORM2DPROC OglUniform2d;
extern PFNGLUNIFORM3DPROC OglUniform3d;
extern PFNGLUNIFORM4DPROC OglUniform4d;
extern PFNGLUNIFORM1DVPROC OglUniform1dv;
extern PFNGLUNIFORM2DVPROC OglUniform2dv;
extern PFNGLUNIFORM3DVPROC OglUniform3dv;
extern PFNGLUNIFORM4DVPROC OglUniform4dv;
extern PFNGLUNIFORMMATRIX2DVPROC OglUniformMatrix2dv;
extern PFNGLUNIFORMMATRIX3DVPROC OglUniformMatrix3dv;
extern PFNGLUNIFORMMATRIX4DVPROC OglUniformMatrix4dv;
extern PFNGLUNIFORMMATRIX2X3DVPROC OglUniformMatrix2x3dv;
extern PFNGLUNIFORMMATRIX2X4DVPROC OglUniformMatrix2x4dv;
extern PFNGLUNIFORMMATRIX3X2DVPROC OglUniformMatrix3x2dv;
extern PFNGLUNIFORMMATRIX3X4DVPROC OglUniformMatrix3x4dv;
extern PFNGLUNIFORMMATRIX4X2DVPROC OglUniformMatrix4x2dv;
extern PFNGLUNIFORMMATRIX4X3DVPROC OglUniformMatrix4x3dv;
extern PFNGLGETUNIFORMDVPROC OglGetUniformdv;
extern PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC OglGetSubroutineUniformLocation;
extern PFNGLGETSUBROUTINEINDEXPROC OglGetSubroutineIndex;
extern PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC OglGetActiveSubroutineUniformiv;
extern PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC OglGetActiveSubroutineUniformName;
extern PFNGLGETACTIVESUBROUTINENAMEPROC OglGetActiveSubroutineName;
extern PFNGLUNIFORMSUBROUTINESUIVPROC OglUniformSubroutinesuiv;
extern PFNGLGETUNIFORMSUBROUTINEUIVPROC OglGetUniformSubroutineuiv;
extern PFNGLGETPROGRAMSTAGEIVPROC OglGetProgramStageiv;
extern PFNGLPATCHPARAMETERIPROC OglPatchParameteri;
extern PFNGLPATCHPARAMETERFVPROC OglPatchParameterfv;
extern PFNGLBINDTRANSFORMFEEDBACKPROC OglBindTransformFeedback;
extern PFNGLDELETETRANSFORMFEEDBACKSPROC OglDeleteTransformFeedbacks;
extern PFNGLGENTRANSFORMFEEDBACKSPROC OglGenTransformFeedbacks;
extern PFNGLISTRANSFORMFEEDBACKPROC OglIsTransformFeedback;
extern PFNGLPAUSETRANSFORMFEEDBACKPROC OglPauseTransformFeedback;
extern PFNGLRESUMETRANSFORMFEEDBACKPROC OglResumeTransformFeedback;
extern PFNGLDRAWTRANSFORMFEEDBACKPROC OglDrawTransformFeedback;
extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC OglDrawTransformFeedbackStream;
extern PFNGLBEGINQUERYINDEXEDPROC OglBeginQueryIndexed;
extern PFNGLENDQUERYINDEXEDPROC OglEndQueryIndexed;
extern PFNGLGETQUERYINDEXEDIVPROC OglGetQueryIndexediv;
extern PFNGLRELEASESHADERCOMPILERPROC OglReleaseShaderCompiler;
extern PFNGLSHADERBINARYPROC OglShaderBinary;
extern PFNGLGETSHADERPRECISIONFORMATPROC OglGetShaderPrecisionFormat;
extern PFNGLDEPTHRANGEFPROC OglDepthRangef;
extern PFNGLCLEARDEPTHFPROC OglClearDepthf;
extern PFNGLGETPROGRAMBINARYPROC OglGetProgramBinary;
extern PFNGLPROGRAMBINARYPROC OglProgramBinary;
extern PFNGLPROGRAMPARAMETERIPROC OglProgramParameteri;
extern PFNGLVERTEXATTRIBL1DPROC OglVertexAttribL1d;
extern PFNGLVERTEXATTRIBL2DPROC OglVertexAttribL2d;
extern PFNGLVERTEXATTRIBL3DPROC OglVertexAttribL3d;
extern PFNGLVERTEXATTRIBL4DPROC OglVertexAttribL4d;
extern PFNGLVERTEXATTRIBL1DVPROC OglVertexAttribL1dv;
extern PFNGLVERTEXATTRIBL2DVPROC OglVertexAttribL2dv;
extern PFNGLVERTEXATTRIBL3DVPROC OglVertexAttribL3dv;
extern PFNGLVERTEXATTRIBL4DVPROC OglVertexAttribL4dv;
extern PFNGLVERTEXATTRIBLPOINTERPROC OglVertexAttribLPointer;
extern PFNGLGETVERTEXATTRIBLDVPROC OglGetVertexAttribLdv;
extern PFNGLVIEWPORTARRAYVPROC OglViewportArrayv;
extern PFNGLVIEWPORTINDEXEDFPROC OglViewportIndexedf;
extern PFNGLVIEWPORTINDEXEDFVPROC OglViewportIndexedfv;
extern PFNGLSCISSORARRAYVPROC OglScissorArrayv;
extern PFNGLSCISSORINDEXEDPROC OglScissorIndexed;
extern PFNGLSCISSORINDEXEDVPROC OglScissorIndexedv;
extern PFNGLDEPTHRANGEARRAYVPROC OglDepthRangeArrayv;
extern PFNGLDEPTHRANGEINDEXEDPROC OglDepthRangeIndexed;
extern PFNGLGETFLOATI_VPROC OglGetFloati_v;
extern PFNGLGETDOUBLEI_VPROC OglGetDoublei_v;
extern PFNGLCREATESYNCFROMCLEVENTARBPROC OglCreateSyncFromCLeventARB;
extern PFNGLDEBUGMESSAGECONTROLARBPROC OglDebugMessageControlARB;
extern PFNGLDEBUGMESSAGEINSERTARBPROC OglDebugMessageInsertARB;
extern PFNGLDEBUGMESSAGECALLBACKARBPROC OglDebugMessageCallbackARB;
extern PFNGLGETDEBUGMESSAGELOGARBPROC OglGetDebugMessageLogARB;
extern PFNGLGETGRAPHICSRESETSTATUSARBPROC OglGetGraphicsResetStatusARB;
extern PFNGLGETNTEXIMAGEARBPROC OglGetnTexImageARB;
extern PFNGLREADNPIXELSARBPROC OglReadnPixelsARB;
extern PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC OglGetnCompressedTexImageARB;
extern PFNGLGETNUNIFORMFVARBPROC OglGetnUniformfvARB;
extern PFNGLGETNUNIFORMIVARBPROC OglGetnUniformivARB;
extern PFNGLGETNUNIFORMUIVARBPROC OglGetnUniformuivARB;
extern PFNGLGETNUNIFORMDVARBPROC OglGetnUniformdvARB;
extern PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC OglDrawArraysInstancedBaseInstance;
extern PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC OglDrawElementsInstancedBaseInstance;
extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC OglDrawElementsInstancedBaseVertexBaseInstance;
extern PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC OglDrawTransformFeedbackInstanced;
extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC OglDrawTransformFeedbackStreamInstanced;
extern PFNGLGETINTERNALFORMATIVPROC OglGetInternalformativ;
extern PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC OglGetActiveAtomicCounterefferiv;
extern PFNGLBINDIMAGETEXTUREPROC OglBindImageTexture;
extern PFNGLMEMORYBARRIERPROC OglMemoryBarrier;
extern PFNGLTEXSTORAGE1DPROC OglTexStorage1D;
extern PFNGLTEXSTORAGE2DPROC OglTexStorage2D;
extern PFNGLTEXSTORAGE3DPROC OglTexStorage3D;
extern PFNGLTEXTURESTORAGE1DEXTPROC OglTextureStorage1DEXT;
extern PFNGLTEXTURESTORAGE2DEXTPROC OglTextureStorage2DEXT;
extern PFNGLTEXTURESTORAGE3DEXTPROC OglTextureStorage3DEXT;
extern PFNGLDEBUGMESSAGECONTROLPROC OglDebugMessageControl;
extern PFNGLDEBUGMESSAGEINSERTPROC OglDebugMessageInsert;
extern PFNGLDEBUGMESSAGECALLBACKPROC OglDebugMessageCallback;
extern PFNGLGETDEBUGMESSAGELOGPROC OglGetDebugMessageLog;
extern PFNGLPUSHDEBUGGROUPPROC OglPushDebugGroup;
extern PFNGLPOPDEBUGGROUPPROC OglPopDebugGroup;
extern PFNGLOBJECTLABELPROC OglObjectLabel;
extern PFNGLGETOBJECTLABELPROC OglGetObjectLabel;
extern PFNGLOBJECTPTRLABELPROC OglObjectPtrLabel;
extern PFNGLGETOBJECTPTRLABELPROC OglGetObjectPtrLabel;
extern PFNGLCLEARBUFFERDATAPROC OglClearefferData;
extern PFNGLCLEARBUFFERSUBDATAPROC OglClearefferSubData;
extern PFNGLCLEARNAMEDBUFFERDATAEXTPROC OglClearNamedBufferDataEXT;
extern PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC OglClearNamedBufferSubDataEXT;

#define glIsRenderbuffer		OglIsRenderbuffer
#define glBindRenderbuffer		OglBindRenderbuffer
#define glDeleteRenderbuffers		OglDeleteRenderbuffers
#define glGenRenderbuffers		OglGenRenderbuffers
#define glRenderbufferStorage		OglRenderbufferStorage
#define glGetRenderbufferParameteriv		OglGetRenderbufferParameteriv
#define glIsFramebuffer		OglIsFramebuffer
#define glBindFramebuffer		OglBindFramebuffer
#define glDeleteFramebuffers		OglDeleteFramebuffers
#define glGenFramebuffers		OglGenFramebuffers
#define glCheckFramebufferStatus		OglCheckFramebufferStatus
#define glFramebufferTexture1D		OglFramebufferTexture1D
#define glFramebufferTexture2D		OglFramebufferTexture2D
#define glFramebufferTexture3D		OglFramebufferTexture3D
#define glFramebufferRenderbuffer		OglFramebufferRenderbuffer
#define glGetFramebufferAttachmentParameteriv		OglGetFramebufferAttachmentParameteriv
#define glGenerateMipmap		OglGenerateMipmap
#define glBlitFramebuffer		OglBlitFramebuffer
#define glRenderbufferStorageMultisample		OglRenderbufferStorageMultisample
#define glFramebufferTextureLayer		OglFramebufferTextureLayer
#define glMapBufferRange		OglMapBufferRange
#define glFlushMappedBufferRange		OglFlushMappedBufferRange
#define glBindVertexArray		OglBindVertexArray
#define glDeleteVertexArrays		OglDeleteVertexArrays
#define glGenVertexArrays		OglGenVertexArrays
#define glIsVertexArray		OglIsVertexArray
#define glGetUniformIndices		OglGetUniformIndices
#define glGetActiveUniformsiv		OglGetActiveUniformsiv
#define glGetActiveUniformName		OglGetActiveUniformName
#define glGetUniformBlockIndex		OglGetUniformBlockIndex
#define glGetActiveUniformBlockiv		OglGetActiveUniformBlockiv
#define glGetActiveUniformBlockName		OglGetActiveUniformBlockName
#define glUniformBlockBinding		OglUniformBlockBinding
#define glCopyBufferSubData		OglCopyBufferSubData
#define glDrawElementsBaseVertex		OglDrawElementsBaseVertex
#define glDrawRangeElementsBaseVertex		OglDrawRangeElementsBaseVertex
#define glDrawElementsInstancedBaseVertex		OglDrawElementsInstancedBaseVertex
#define glMultiDrawElementsBaseVertex		OglMultiDrawElementsBaseVertex
#define glProvokingVertex		OglProvokingVertex
#define glFenceSync		OglFenceSync
#define glIsSync		OglIsSync
#define glDeleteSync		OglDeleteSync
#define glClientWaitSync		OglClientWaitSync
#define glWaitSync		OglWaitSync
#define glGetInteger64v		OglGetInteger64v
#define glGetSynciv		OglGetSynciv
#define glTexImage2DMultisample		OglTexImage2DMultisample
#define glTexImage3DMultisample		OglTexImage3DMultisample
#define glGetMultisamplefv		OglGetMultisamplefv
#define glSampleMaski		OglSampleMaski
#define glBlendEquationiARB		OglBlendEquationiARB
#define glBlendEquationSeparateiARB		OglBlendEquationSeparateiARB
#define glBlendFunciARB		OglBlendFunciARB
#define glBlendFuncSeparateiARB		OglBlendFuncSeparateiARB
#define glMinSampleShadingARB		OglMinSampleShadingARB
#define glNamedStringARB		OglNamedStringARB
#define glDeleteNamedStringARB		OglDeleteNamedStringARB
#define glCompileShaderIncludeARB		OglCompileShaderIncludeARB
#define glIsNamedStringARB		OglIsNamedStringARB
#define glGetNamedStringARB		OglGetNamedStringARB
#define glGetNamedStringivARB		OglGetNamedStringivARB
#define glBindFragDataLocationIndexed		OglBindFragDataLocationIndexed
#define glGetFragDataIndex		OglGetFragDataIndex
#define glGenSamplers		OglGenSamplers
#define glDeleteSamplers		OglDeleteSamplers
#define glIsSampler		OglIsSampler
#define glBindSampler		OglBindSampler
#define glSamplerParameteri		OglSamplerParameteri
#define glSamplerParameteriv		OglSamplerParameteriv
#define glSamplerParameterf		OglSamplerParameterf
#define glSamplerParameterfv		OglSamplerParameterfv
#define glSamplerParameterIiv		OglSamplerParameterIiv
#define glSamplerParameterIuiv		OglSamplerParameterIuiv
#define glGetSamplerParameteriv		OglGetSamplerParameteriv
#define glGetSamplerParameterIiv		OglGetSamplerParameterIiv
#define glGetSamplerParameterfv		OglGetSamplerParameterfv
#define glGetSamplerParameterIuiv		OglGetSamplerParameterIuiv
#define glQueryCounter		OglQueryCounter
#define glGetQueryObjecti64v		OglGetQueryObjecti64v
#define glGetQueryObjectui64v		OglGetQueryObjectui64v
#define glVertexP2ui		OglVertexP2ui
#define glVertexP2uiv		OglVertexP2uiv
#define glVertexP3ui		OglVertexP3ui
#define glVertexP3uiv		OglVertexP3uiv
#define glVertexP4ui		OglVertexP4ui
#define glVertexP4uiv		OglVertexP4uiv
#define glTexCoordP1ui		OglTexCoordP1ui
#define glTexCoordP1uiv		OglTexCoordP1uiv
#define glTexCoordP2ui		OglTexCoordP2ui
#define glTexCoordP2uiv		OglTexCoordP2uiv
#define glTexCoordP3ui		OglTexCoordP3ui
#define glTexCoordP3uiv		OglTexCoordP3uiv
#define glTexCoordP4ui		OglTexCoordP4ui
#define glTexCoordP4uiv		OglTexCoordP4uiv
#define glMultiTexCoordP1ui		OglMultiTexCoordP1ui
#define glMultiTexCoordP1uiv		OglMultiTexCoordP1uiv
#define glMultiTexCoordP2ui		OglMultiTexCoordP2ui
#define glMultiTexCoordP2uiv		OglMultiTexCoordP2uiv
#define glMultiTexCoordP3ui		OglMultiTexCoordP3ui
#define glMultiTexCoordP3uiv		OglMultiTexCoordP3uiv
#define glMultiTexCoordP4ui		OglMultiTexCoordP4ui
#define glMultiTexCoordP4uiv		OglMultiTexCoordP4uiv
#define glNormalP3ui		OglNormalP3ui
#define glNormalP3uiv		OglNormalP3uiv
#define glColorP3ui		OglColorP3ui
#define glColorP3uiv		OglColorP3uiv
#define glColorP4ui		OglColorP4ui
#define glColorP4uiv		OglColorP4uiv
#define glSecondaryColorP3ui		OglSecondaryColorP3ui
#define glSecondaryColorP3uiv		OglSecondaryColorP3uiv
#define glVertexAttribP1ui		OglVertexAttribP1ui
#define glVertexAttribP1uiv		OglVertexAttribP1uiv
#define glVertexAttribP2ui		OglVertexAttribP2ui
#define glVertexAttribP2uiv		OglVertexAttribP2uiv
#define glVertexAttribP3ui		OglVertexAttribP3ui
#define glVertexAttribP3uiv		OglVertexAttribP3uiv
#define glVertexAttribP4ui		OglVertexAttribP4ui
#define glVertexAttribP4uiv		OglVertexAttribP4uiv
#define glDrawArraysIndirect		OglDrawArraysIndirect
#define glDrawElementsIndirect		OglDrawElementsIndirect
#define glUniform1d		OglUniform1d
#define glUniform2d		OglUniform2d
#define glUniform3d		OglUniform3d
#define glUniform4d		OglUniform4d
#define glUniform1dv		OglUniform1dv
#define glUniform2dv		OglUniform2dv
#define glUniform3dv		OglUniform3dv
#define glUniform4dv		OglUniform4dv
#define glUniformMatrix2dv		OglUniformMatrix2dv
#define glUniformMatrix3dv		OglUniformMatrix3dv
#define glUniformMatrix4dv		OglUniformMatrix4dv
#define glUniformMatrix2x3dv		OglUniformMatrix2x3dv
#define glUniformMatrix2x4dv		OglUniformMatrix2x4dv
#define glUniformMatrix3x2dv		OglUniformMatrix3x2dv
#define glUniformMatrix3x4dv		OglUniformMatrix3x4dv
#define glUniformMatrix4x2dv		OglUniformMatrix4x2dv
#define glUniformMatrix4x3dv		OglUniformMatrix4x3dv
#define glGetUniformdv		OglGetUniformdv
#define glGetSubroutineUniformLocation		OglGetSubroutineUniformLocation
#define glGetSubroutineIndex		OglGetSubroutineIndex
#define glGetActiveSubroutineUniformiv		OglGetActiveSubroutineUniformiv
#define glGetActiveSubroutineUniformName		OglGetActiveSubroutineUniformName
#define glGetActiveSubroutineName		OglGetActiveSubroutineName
#define glUniformSubroutinesuiv		OglUniformSubroutinesuiv
#define glGetUniformSubroutineuiv		OglGetUniformSubroutineuiv
#define glGetProgramStageiv		OglGetProgramStageiv
#define glPatchParameteri		OglPatchParameteri
#define glPatchParameterfv		OglPatchParameterfv
#define glBindTransformFeedback		OglBindTransformFeedback
#define glDeleteTransformFeedbacks		OglDeleteTransformFeedbacks
#define glGenTransformFeedbacks		OglGenTransformFeedbacks
#define glIsTransformFeedback		OglIsTransformFeedback
#define glPauseTransformFeedback		OglPauseTransformFeedback
#define glResumeTransformFeedback		OglResumeTransformFeedback
#define glDrawTransformFeedback		OglDrawTransformFeedback
#define glDrawTransformFeedbackStream		OglDrawTransformFeedbackStream
#define glBeginQueryIndexed		OglBeginQueryIndexed
#define glEndQueryIndexed		OglEndQueryIndexed
#define glGetQueryIndexediv		OglGetQueryIndexediv
#define glReleaseShaderCompiler		OglReleaseShaderCompiler
#define glShaderBinary		OglShaderBinary
#define glGetShaderPrecisionFormat		OglGetShaderPrecisionFormat
#define glDepthRangef		OglDepthRangef
#define glClearDepthf		OglClearDepthf
#define glGetProgramBinary		OglGetProgramBinary
#define glProgramBinary		OglProgramBinary
#define glProgramParameteri		OglProgramParameteri
#define glUseProgramStages		OglUseProgramStages
#define glActiveShaderProgram		OglActiveShaderProgram
#define glCreateShaderProgramv		OglCreateShaderProgramv
#define glBindProgramPipeline		OglBindProgramPipeline
#define glDeleteProgramPipelines		OglDeleteProgramPipelines
#define glGenProgramPipelines		OglGenProgramPipelines
#define glIsProgramPipeline		OglIsProgramPipeline
#define glGetProgramPipelineiv		OglGetProgramPipelineiv
#define glProgramUniform1i		OglProgramUniform1i
#define glProgramUniform1iv		OglProgramUniform1iv
#define glProgramUniform1f		OglProgramUniform1f
#define glProgramUniform1fv		OglProgramUniform1fv
#define glProgramUniform1d		OglProgramUniform1d
#define glProgramUniform1dv		OglProgramUniform1dv
#define glProgramUniform1ui		OglProgramUniform1ui
#define glProgramUniform1uiv		OglProgramUniform1uiv
#define glProgramUniform2i		OglProgramUniform2i
#define glProgramUniform2iv		OglProgramUniform2iv
#define glProgramUniform2f		OglProgramUniform2f
#define glProgramUniform2fv		OglProgramUniform2fv
#define glProgramUniform2d		OglProgramUniform2d
#define glProgramUniform2dv		OglProgramUniform2dv
#define glProgramUniform2ui		OglProgramUniform2ui
#define glProgramUniform2uiv		OglProgramUniform2uiv
#define glProgramUniform3i		OglProgramUniform3i
#define glProgramUniform3iv		OglProgramUniform3iv
#define glProgramUniform3f		OglProgramUniform3f
#define glProgramUniform3fv		OglProgramUniform3fv
#define glProgramUniform3d		OglProgramUniform3d
#define glProgramUniform3dv		OglProgramUniform3dv
#define glProgramUniform3ui		OglProgramUniform3ui
#define glProgramUniform3uiv		OglProgramUniform3uiv
#define glProgramUniform4i		OglProgramUniform4i
#define glProgramUniform4iv		OglProgramUniform4iv
#define glProgramUniform4f		OglProgramUniform4f
#define glProgramUniform4fv		OglProgramUniform4fv
#define glProgramUniform4d		OglProgramUniform4d
#define glProgramUniform4dv		OglProgramUniform4dv
#define glProgramUniform4ui		OglProgramUniform4ui
#define glProgramUniform4uiv		OglProgramUniform4uiv
#define glProgramUniformMatrix2fv		OglProgramUniformMatrix2fv
#define glProgramUniformMatrix3fv		OglProgramUniformMatrix3fv
#define glProgramUniformMatrix4fv		OglProgramUniformMatrix4fv
#define glProgramUniformMatrix2dv		OglProgramUniformMatrix2dv
#define glProgramUniformMatrix3dv		OglProgramUniformMatrix3dv
#define glProgramUniformMatrix4dv		OglProgramUniformMatrix4dv
#define glProgramUniformMatrix2x3fv		OglProgramUniformMatrix2x3fv
#define glProgramUniformMatrix3x2fv		OglProgramUniformMatrix3x2fv
#define glProgramUniformMatrix2x4fv		OglProgramUniformMatrix2x4fv
#define glProgramUniformMatrix4x2fv		OglProgramUniformMatrix4x2fv
#define glProgramUniformMatrix3x4fv		OglProgramUniformMatrix3x4fv
#define glProgramUniformMatrix4x3fv		OglProgramUniformMatrix4x3fv
#define glProgramUniformMatrix2x3dv		OglProgramUniformMatrix2x3dv
#define glProgramUniformMatrix3x2dv		OglProgramUniformMatrix3x2dv
#define glProgramUniformMatrix2x4dv		OglProgramUniformMatrix2x4dv
#define glProgramUniformMatrix4x2dv		OglProgramUniformMatrix4x2dv
#define glProgramUniformMatrix3x4dv		OglProgramUniformMatrix3x4dv
#define glProgramUniformMatrix4x3dv		OglProgramUniformMatrix4x3dv
#define glValidateProgramPipeline		OglValidateProgramPipeline
#define glGetProgramPipelineInfoLog		OglGetProgramPipelineInfoLog
#define glVertexAttribL1d		OglVertexAttribL1d
#define glVertexAttribL2d		OglVertexAttribL2d
#define glVertexAttribL3d		OglVertexAttribL3d
#define glVertexAttribL4d		OglVertexAttribL4d
#define glVertexAttribL1dv		OglVertexAttribL1dv
#define glVertexAttribL2dv		OglVertexAttribL2dv
#define glVertexAttribL3dv		OglVertexAttribL3dv
#define glVertexAttribL4dv		OglVertexAttribL4dv
#define glVertexAttribLPointer		OglVertexAttribLPointer
#define glGetVertexAttribLdv		OglGetVertexAttribLdv
#define glViewportArrayv		OglViewportArrayv
#define glViewportIndexedf		OglViewportIndexedf
#define glViewportIndexedfv		OglViewportIndexedfv
#define glScissorArrayv		OglScissorArrayv
#define glScissorIndexed		OglScissorIndexed
#define glScissorIndexedv		OglScissorIndexedv
#define glDepthRangeArrayv		OglDepthRangeArrayv
#define glDepthRangeIndexed		OglDepthRangeIndexed
#define glGetFloati_v		OglGetFloati_v
#define glGetDoublei_v		OglGetDoublei_v
#define glCreateSyncFromCLeventARB		OglCreateSyncFromCLeventARB
#define glDebugMessageControlARB		OglDebugMessageControlARB
#define glDebugMessageInsertARB		OglDebugMessageInsertARB
#define glDebugMessageCallbackARB		OglDebugMessageCallbackARB
#define glGetDebugMessageLogARB		OglGetDebugMessageLogARB
#define glGetGraphicsResetStatusARB		OglGetGraphicsResetStatusARB
#define glGetnTexImageARB		OglGetnTexImageARB
#define glReadnPixelsARB		OglReadnPixelsARB
#define glGetnCompressedTexImageARB		OglGetnCompressedTexImageARB
#define glGetnUniformfvARB		OglGetnUniformfvARB
#define glGetnUniformivARB		OglGetnUniformivARB
#define glGetnUniformuivARB		OglGetnUniformuivARB
#define glGetnUniformdvARB		OglGetnUniformdvARB
#define glDrawArraysInstancedBaseInstance		OglDrawArraysInstancedBaseInstance
#define glDrawElementsInstancedBaseInstance		OglDrawElementsInstancedBaseInstance
#define glDrawElementsInstancedBaseVertexBaseInstance		OglDrawElementsInstancedBaseVertexBaseInstance
#define glDrawTransformFeedbackInstanced		OglDrawTransformFeedbackInstanced
#define glDrawTransformFeedbackStreamInstanced		OglDrawTransformFeedbackStreamInstanced
#define glGetInternalformativ		OglGetInternalformativ
#define glGetActiveAtomicCounterefferiv		OglGetActiveAtomicCounterefferiv
#define glBindImageTexture		OglBindImageTexture
#define glMemoryBarrier		OglMemoryBarrier
#define glTexStorage1D		OglTexStorage1D
#define glTexStorage2D		OglTexStorage2D
#define glTexStorage3D		OglTexStorage3D
#define glTextureStorage1DEXT		OglTextureStorage1DEXT
#define glTextureStorage2DEXT		OglTextureStorage2DEXT
#define glTextureStorage3DEXT		OglTextureStorage3DEXT
#define glDebugMessageControl		OglDebugMessageControl
#define glDebugMessageInsert		OglDebugMessageInsert
#define glDebugMessageCallback		OglDebugMessageCallback
#define glGetDebugMessageLog		OglGetDebugMessageLog
#define glPushDebugGroup		OglPushDebugGroup
#define glPopDebugGroup		OglPopDebugGroup
#define glObjectLabel		OglObjectLabel
#define glGetObjectLabel		OglGetObjectLabel
#define glObjectPtrLabel		OglObjectPtrLabel
#define glGetObjectPtrLabel		OglGetObjectPtrLabel
#define glClearefferData		OglClearefferData
#define glClearefferSubData		OglClearefferSubData
#define glClearNamedBufferDataEXT		OglClearNamedBufferDataEXT
#define glClearNamedBufferSubDataEXT		OglClearNamedBufferSubDataEXT
#define glDispatchCompute		OglDispatchCompute
#define glDispatchComputeIndirect		OglDispatchComputeIndirect
#define glCopyImageSubData		OglCopyImageSubData
#define glTextureView		OglTextureView
#define glBindVertexBuffer		OglBindVertexBuffer
#define glVertexAttribFormat		OglVertexAttribFormat
#define glVertexAttribIFormat		OglVertexAttribIFormat
#define glVertexAttribLFormat		OglVertexAttribLFormat
#define glVertexAttribBinding		OglVertexAttribBinding
#define glVertexBindingDivisor		OglVertexBindingDivisor
#define glVertexArrayBindVertexBufferEXT		OglVertexArrayBindVertexBufferEXT
#define glVertexArrayVertexAttribFormatEXT		OglVertexArrayVertexAttribFormatEXT
#define glVertexArrayVertexAttribIFormatEXT		OglVertexArrayVertexAttribIFormatEXT
#define glVertexArrayVertexAttribLFormatEXT		OglVertexArrayVertexAttribLFormatEXT
#define glVertexArrayVertexAttribBindingEXT		OglVertexArrayVertexAttribBindingEXT
#define glVertexArrayVertexBindingDivisorEXT		OglVertexArrayVertexBindingDivisorEXT
#define glFramebufferParameteri		OglFramebufferParameteri
#define glGetFramebufferParameteriv		OglGetFramebufferParameteriv
#define glNamedFramebufferParameteriEXT		OglNamedFramebufferParameteriEXT
#define glGetNamedFramebufferParameterivEXT		OglGetNamedFramebufferParameterivEXT
#define glGetInternalformati64v		OglGetInternalformati64v
#define glInvalidateTexSubImage		OglInvalidateTexSubImage
#define glInvalidateTexImage		OglInvalidateTexImage
#define glInvalidateBufferSubData		OglInvalidateBufferSubData
#define glInvalidateBufferData		OglInvalidateBufferData
#define glInvalidateFramebuffer		OglInvalidateFramebuffer
#define glInvalidateSubFramebuffer		OglInvalidateSubFramebuffer
#define glMultiDrawArraysIndirect		OglMultiDrawArraysIndirect
#define glMultiDrawElementsIndirect		OglMultiDrawElementsIndirect
#define glGetProgramInterfaceiv		OglGetProgramInterfaceiv
#define glGetProgramResourceIndex		OglGetProgramResourceIndex
#define glGetProgramResourceName		OglGetProgramResourceName
#define glGetProgramResourceiv		OglGetProgramResourceiv
#define glGetProgramResourceLocation		OglGetProgramResourceLocation
#define glGetProgramResourceLocationIndex		OglGetProgramResourceLocationIndex
#define glShaderStorageBlockBinding		OglShaderStorageBlockBinding
#define glTexBufferRange		OglTexBufferRange
#define glTextureBufferRangeEXT		OglTextureBufferRangeEXT
#define glTexStorage2DMultisample		OglTexStorage2DMultisample
#define glTexStorage3DMultisample		OglTexStorage3DMultisample
#define glTextureStorage2DMultisampleEXT		OglTextureStorage2DMultisampleEXT
#define glTextureStorage3DMultisampleEXT		OglTextureStorage3DMultisampleEXT
#endif	// NWG_OGL_ARB_FUNC

#endif	// NWG_OGL_ARB_H