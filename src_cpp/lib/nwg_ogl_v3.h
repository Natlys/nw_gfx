#ifndef NWG_OGL_V3_H
#define NWG_OGL_V3_H
#include "nwg_ogl_native.h"
namespace NWG
{
	extern void OglLoadV3();
}
#ifndef GL_VERSION_3_0
#define GL_VERSION_3_0 1

#define GL_COMPARE_REF_TO_TEXTURE         0x884E
#define GL_CLIP_DISTANCE0                 0x3000
#define GL_CLIP_DISTANCE1                 0x3001
#define GL_CLIP_DISTANCE2                 0x3002
#define GL_CLIP_DISTANCE3                 0x3003
#define GL_CLIP_DISTANCE4                 0x3004
#define GL_CLIP_DISTANCE5                 0x3005
#define GL_CLIP_DISTANCE6                 0x3006
#define GL_CLIP_DISTANCE7                 0x3007
#define GL_MAX_CLIP_DISTANCES             0x0D32
#define GL_MAJOR_VERSION                  0x821B
#define GL_MINOR_VERSION                  0x821C
#define GL_NUM_EXTENSIONS                 0x821D
#define GL_CONTEXT_FLAGS                  0x821E
#define GL_COMPRESSED_RED                 0x8225
#define GL_COMPRESSED_RG                  0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x0001
#define GL_RGBA32F                        0x8814
#define GL_RGB32F                         0x8815
#define GL_RGBA16F                        0x881A
#define GL_RGB16F                         0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER    0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS       0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET       0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET       0x8905
#define GL_CLAMP_READ_COLOR               0x891C
#define GL_FIXED_ONLY                     0x891D
#define GL_MAX_VARYING_COMPONENTS         0x8B4B
#define GL_TEXTURE_1D_ARRAY               0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY         0x8C19
#define GL_TEXTURE_2D_ARRAY               0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY         0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY       0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY       0x8C1D
#define GL_R11F_G11F_B10F                 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV   0x8C3B
#define GL_RGB9_E5                        0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV       0x8C3E
#define GL_TEXTURE_SHARED_SIZE            0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS    0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED           0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD             0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS            0x8C8C
#define GL_SEPARATE_ATTRIBS               0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER      0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_RGBA32UI                       0x8D70
#define GL_RGB32UI                        0x8D71
#define GL_RGBA16UI                       0x8D76
#define GL_RGB16UI                        0x8D77
#define GL_RGBA8UI                        0x8D7C
#define GL_RGB8UI                         0x8D7D
#define GL_RGBA32I                        0x8D82
#define GL_RGB32I                         0x8D83
#define GL_RGBA16I                        0x8D88
#define GL_RGB16I                         0x8D89
#define GL_RGBA8I                         0x8D8E
#define GL_RGB8I                          0x8D8F
#define GL_RED_INTEGER                    0x8D94
#define GL_GREEN_INTEGER                  0x8D95
#define GL_BLUE_INTEGER                   0x8D96
#define GL_RGB_INTEGER                    0x8D98
#define GL_RGBA_INTEGER                   0x8D99
#define GL_BGR_INTEGER                    0x8D9A
#define GL_BGRA_INTEGER                   0x8D9B
#define GL_SAMPLER_1D_ARRAY               0x8DC0
#define GL_SAMPLER_2D_ARRAY               0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW        0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW        0x8DC4
#define GL_SAMPLER_CUBE_SHADOW            0x8DC5
#define GL_UNSIGNED_INT_VEC2              0x8DC6
#define GL_UNSIGNED_INT_VEC3              0x8DC7
#define GL_UNSIGNED_INT_VEC4              0x8DC8
#define GL_INT_SAMPLER_1D                 0x8DC9
#define GL_INT_SAMPLER_2D                 0x8DCA
#define GL_INT_SAMPLER_3D                 0x8DCB
#define GL_INT_SAMPLER_CUBE               0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY           0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY           0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D        0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D        0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D        0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE      0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY  0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY  0x8DD7
#define GL_QUERY_WAIT                     0x8E13
#define GL_QUERY_NO_WAIT                  0x8E14
#define GL_QUERY_BY_REGION_WAIT           0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT        0x8E16
#define GL_BUFFER_ACCESS_FLAGS            0x911F
#define GL_BUFFER_MAP_LENGTH              0x9120
#define GL_BUFFER_MAP_OFFSET              0x9121
// Reuse tokens from ARB_depth_buffer_float
// reuse GL_DEPTH_COMPONENT32F
// reuse GL_DEPTH32F_STENCIL8
// reuse GL_FLOAT_32_UNSIGNED_INT_24_8_REV
// Reuse tokens from ARB_framebuffer_object
// reuse GL_INVALID_FRAMEBUFFER_OPERATION
// reuse GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING
// reuse GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE
// reuse GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE
// reuse GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE
// reuse GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE
// reuse GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE
// reuse GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE
// reuse GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE
// reuse GL_FRAMEBUFFER_DEFAULT
// reuse GL_FRAMEBUFFER_UNDEFINED
// reuse GL_DEPTH_STENCIL_ATTACHMENT
// reuse GL_INDEX
// reuse GL_MAX_RENDERBUFFER_SIZE
// reuse GL_DEPTH_STENCIL
// reuse GL_UNSIGNED_INT_24_8
// reuse GL_DEPTH24_STENCIL8
// reuse GL_TEXTURE_STENCIL_SIZE
// reuse GL_TEXTURE_RED_TYPE
// reuse GL_TEXTURE_GREEN_TYPE
// reuse GL_TEXTURE_BLUE_TYPE
// reuse GL_TEXTURE_ALPHA_TYPE
// reuse GL_TEXTURE_DEPTH_TYPE
// reuse GL_UNSIGNED_NORMALIZED
// reuse GL_FRAMEBUFFER_BINDING
// reuse GL_DRAW_FRAMEBUFFER_BINDING
// reuse GL_RENDERBUFFER_BINDING
// reuse GL_READ_FRAMEBUFFER
// reuse GL_DRAW_FRAMEBUFFER
// reuse GL_READ_FRAMEBUFFER_BINDING
// reuse GL_RENDERBUFFER_SAMPLES
// reuse GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE
// reuse GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME
// reuse GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL
// reuse GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE
// reuse GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER
// reuse GL_FRAMEBUFFER_COMPLETE
// reuse GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
// reuse GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
// reuse GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER
// reuse GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER
// reuse GL_FRAMEBUFFER_UNSUPPORTED
// reuse GL_MAX_COLOR_ATTACHMENTS
// reuse GL_COLOR_ATTACHMENT0
// reuse GL_COLOR_ATTACHMENT1
// reuse GL_COLOR_ATTACHMENT2
// reuse GL_COLOR_ATTACHMENT3
// reuse GL_COLOR_ATTACHMENT4
// reuse GL_COLOR_ATTACHMENT5
// reuse GL_COLOR_ATTACHMENT6
// reuse GL_COLOR_ATTACHMENT7
// reuse GL_COLOR_ATTACHMENT8
// reuse GL_COLOR_ATTACHMENT9
// reuse GL_COLOR_ATTACHMENT10
// reuse GL_COLOR_ATTACHMENT11
// reuse GL_COLOR_ATTACHMENT12
// reuse GL_COLOR_ATTACHMENT13
// reuse GL_COLOR_ATTACHMENT14
// reuse GL_COLOR_ATTACHMENT15
// reuse GL_DEPTH_ATTACHMENT
// reuse GL_STENCIL_ATTACHMENT
// reuse GL_FRAMEBUFFER
// reuse GL_RENDERBUFFER
// reuse GL_RENDERBUFFER_WIDTH
// reuse GL_RENDERBUFFER_HEIGHT
// reuse GL_RENDERBUFFER_INTERNAL_FORMAT
// reuse GL_STENCIL_INDEX1
// reuse GL_STENCIL_INDEX4
// reuse GL_STENCIL_INDEX8
// reuse GL_STENCIL_INDEX16
// reuse GL_RENDERBUFFER_RED_SIZE
// reuse GL_RENDERBUFFER_GREEN_SIZE
// reuse GL_RENDERBUFFER_BLUE_SIZE
// reuse GL_RENDERBUFFER_ALPHA_SIZE
// reuse GL_RENDERBUFFER_DEPTH_SIZE
// reuse GL_RENDERBUFFER_STENCIL_SIZE
// reuse GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
// reuse GL_MAX_SAMPLES
// Reuse tokens from ARB_framebuffer_sRGB
// reuse GL_FRAMEBUFFER_SRGB
// Reuse tokens from ARB_half_float_vertex
// reuse GL_HALF_FLOAT
// Reuse tokens from ARB_map_buffer_range
// reuse GL_MAP_READ_BIT
// reuse GL_MAP_WRITE_BIT
// reuse GL_MAP_INVALIDATE_RANGE_BIT
// reuse GL_MAP_INVALIDATE_BUFFER_BIT
// reuse GL_MAP_FLUSH_EXPLICIT_BIT
// reuse GL_MAP_UNSYNCHRONIZED_BIT
// Reuse tokens from ARB_texture_compression_rgtc
// reuse GL_COMPRESSED_RED_RGTC1
// reuse GL_COMPRESSED_SIGNED_RED_RGTC1
// reuse GL_COMPRESSED_RG_RGTC2
// reuse GL_COMPRESSED_SIGNED_RG_RGTC2
// Reuse tokens from ARB_texture_rg
// reuse GL_RG
// reuse GL_RG_INTEGER
// reuse GL_R8
// reuse GL_R16
// reuse GL_RG8
// reuse GL_RG16
// reuse GL_R16F
// reuse GL_R32F
// reuse GL_RG16F
// reuse GL_RG32F
// reuse GL_R8I
// reuse GL_R8UI
// reuse GL_R16I
// reuse GL_R16UI
// reuse GL_R32I
// reuse GL_R32UI
// reuse GL_RG8I
// reuse GL_RG8UI
// reuse GL_RG16I
// reuse GL_RG16UI
// reuse GL_RG32I
// reuse GL_RG32UI
// Reuse tokens from ARB_vertex_array_object
// reuse GL_VERTEX_ARRAY_BINDING
// OpenGL 3.0 also reuses entry points from these extensions:
// ARB_framebuffer_object
// ARB_map_buffer_range
// ARB_vertex_array_object
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
GLAPI void APIENTRY glGetBooleani_v(GLenum target, GLuint index, GLboolean* data);
GLAPI void APIENTRY glGetIntegeri_v(GLenum target, GLuint index, GLint* data);
GLAPI void APIENTRY glEnablei(GLenum target, GLuint index);
GLAPI void APIENTRY glDisablei(GLenum target, GLuint index);
GLAPI GLboolean APIENTRY glIsEnabledi(GLenum target, GLuint index);
GLAPI void APIENTRY glBeginTransformFeedback(GLenum primitiveMode);
GLAPI void APIENTRY glEndTransformFeedback(void);
GLAPI void APIENTRY glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void APIENTRY glBindBufferBase(GLenum target, GLuint index, GLuint buffer);
GLAPI void APIENTRY glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode);
GLAPI void APIENTRY glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
GLAPI void APIENTRY glClampColor(GLenum target, GLenum clamp);
GLAPI void APIENTRY glBeginConditionalRender(GLuint id, GLenum mode);
GLAPI void APIENTRY glEndConditionalRender(void);
GLAPI void APIENTRY glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
GLAPI void APIENTRY glGetVertexAttribIiv(GLuint index, GLenum pname, GLint* params);
GLAPI void APIENTRY glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint* params);
GLAPI void APIENTRY glVertexAttribI1i(GLuint index, GLint x);
GLAPI void APIENTRY glVertexAttribI2i(GLuint index, GLint x, GLint y);
GLAPI void APIENTRY glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z);
GLAPI void APIENTRY glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI void APIENTRY glVertexAttribI1ui(GLuint index, GLuint x);
GLAPI void APIENTRY glVertexAttribI2ui(GLuint index, GLuint x, GLuint y);
GLAPI void APIENTRY glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z);
GLAPI void APIENTRY glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI void APIENTRY glVertexAttribI1iv(GLuint index, const GLint* v);
GLAPI void APIENTRY glVertexAttribI2iv(GLuint index, const GLint* v);
GLAPI void APIENTRY glVertexAttribI3iv(GLuint index, const GLint* v);
GLAPI void APIENTRY glVertexAttribI4iv(GLuint index, const GLint* v);
GLAPI void APIENTRY glVertexAttribI1uiv(GLuint index, const GLuint* v);
GLAPI void APIENTRY glVertexAttribI2uiv(GLuint index, const GLuint* v);
GLAPI void APIENTRY glVertexAttribI3uiv(GLuint index, const GLuint* v);
GLAPI void APIENTRY glVertexAttribI4uiv(GLuint index, const GLuint* v);
GLAPI void APIENTRY glVertexAttribI4bv(GLuint index, const GLbyte* v);
GLAPI void APIENTRY glVertexAttribI4sv(GLuint index, const GLshort* v);
GLAPI void APIENTRY glVertexAttribI4ubv(GLuint index, const GLubyte* v);
GLAPI void APIENTRY glVertexAttribI4usv(GLuint index, const GLushort* v);
GLAPI void APIENTRY glGetUniformuiv(GLuint program, GLint location, GLuint* params);
GLAPI void APIENTRY glBindFragDataLocation(GLuint program, GLuint color, const GLchar* name);
GLAPI GLint APIENTRY glGetFragDataLocation(GLuint program, const GLchar* name);
GLAPI void APIENTRY glUniform1ui(GLint location, GLuint v0);
GLAPI void APIENTRY glUniform2ui(GLint location, GLuint v0, GLuint v1);
GLAPI void APIENTRY glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void APIENTRY glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void APIENTRY glUniform1uiv(GLint location, GLsizei count, const GLuint* value);
GLAPI void APIENTRY glUniform2uiv(GLint location, GLsizei count, const GLuint* value);
GLAPI void APIENTRY glUniform3uiv(GLint location, GLsizei count, const GLuint* value);
GLAPI void APIENTRY glUniform4uiv(GLint location, GLsizei count, const GLuint* value);
GLAPI void APIENTRY glTexParameterIiv(GLenum target, GLenum pname, const GLint* params);
GLAPI void APIENTRY glTexParameterIuiv(GLenum target, GLenum pname, const GLuint* params);
GLAPI void APIENTRY glGetTexParameterIiv(GLenum target, GLenum pname, GLint* params);
GLAPI void APIENTRY glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint* params);
GLAPI void APIENTRY glClearefferiv(GLenum buffer, GLint drawbuffer, const GLint* value);
GLAPI void APIENTRY glClearefferuiv(GLenum buffer, GLint drawbuffer, const GLuint* value);
GLAPI void APIENTRY glClearefferfv(GLenum buffer, GLint drawbuffer, const GLfloat* value);
GLAPI void APIENTRY glClearefferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLAPI const GLubyte* APIENTRY glGetStringi(GLenum name, GLuint index);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLCOLORMASKIPROC) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef void (APIENTRYP PFNGLGETBOOLEANI_VPROC) (GLenum target, GLuint index, GLboolean* data);
typedef void (APIENTRYP PFNGLGETINTEGERI_VPROC) (GLenum target, GLuint index, GLint* data);
typedef void (APIENTRYP PFNGLENABLEIPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLDISABLEIPROC) (GLenum target, GLuint index);
typedef GLboolean(APIENTRYP PFNGLISENABLEDIPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC) (GLenum primitiveMode);
typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC) (void);
typedef void (APIENTRYP PFNGLBINDBUFFERRANGEPROC) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLBINDBUFFERBASEPROC) (GLenum target, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC) (GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
typedef void (APIENTRYP PFNGLCLAMPCOLORPROC) (GLenum target, GLenum clamp);
typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERPROC) (GLuint id, GLenum mode);
typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERPROC) (void);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVPROC) (GLuint index, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC) (GLuint index, GLenum pname, GLuint* params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IPROC) (GLuint index, GLint x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IPROC) (GLuint index, GLint x, GLint y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IPROC) (GLuint index, GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IPROC) (GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIPROC) (GLuint index, GLuint x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIPROC) (GLuint index, GLuint x, GLuint y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIPROC) (GLuint index, GLuint x, GLuint y, GLuint z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIPROC) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IVPROC) (GLuint index, const GLint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IVPROC) (GLuint index, const GLint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IVPROC) (GLuint index, const GLint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVPROC) (GLuint index, const GLint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIVPROC) (GLuint index, const GLuint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIVPROC) (GLuint index, const GLuint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIVPROC) (GLuint index, const GLuint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVPROC) (GLuint index, const GLuint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4BVPROC) (GLuint index, const GLbyte* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4SVPROC) (GLuint index, const GLshort* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UBVPROC) (GLuint index, const GLubyte* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4USVPROC) (GLuint index, const GLushort* v);
typedef void (APIENTRYP PFNGLGETUNIFORMUIVPROC) (GLuint program, GLint location, GLuint* params);
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONPROC) (GLuint program, GLuint color, const GLchar* name);
typedef GLint(APIENTRYP PFNGLGETFRAGDATALOCATIONPROC) (GLuint program, const GLchar* name);
typedef void (APIENTRYP PFNGLUNIFORM1UIPROC) (GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLUNIFORM2UIPROC) (GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLUNIFORM3UIPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLUNIFORM4UIPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLUNIFORM1UIVPROC) (GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLUNIFORM2UIVPROC) (GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLUNIFORM3UIVPROC) (GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLUNIFORM4UIVPROC) (GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLTEXPARAMETERIIVPROC) (GLenum target, GLenum pname, const GLint* params);
typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVPROC) (GLenum target, GLenum pname, const GLuint* params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVPROC) (GLenum target, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVPROC) (GLenum target, GLenum pname, GLuint* params);
typedef void (APIENTRYP PFNGLCLEARBUFFERIVPROC) (GLenum buffer, GLint drawbuffer, const GLint* value);
typedef void (APIENTRYP PFNGLCLEARBUFFERUIVPROC) (GLenum buffer, GLint drawbuffer, const GLuint* value);
typedef void (APIENTRYP PFNGLCLEARBUFFERFVPROC) (GLenum buffer, GLint drawbuffer, const GLfloat* value);
typedef void (APIENTRYP PFNGLCLEARBUFFERFIPROC) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef const GLubyte* (APIENTRYP PFNGLGETSTRINGIPROC) (GLenum name, GLuint index);
extern PFNGLCOLORMASKIPROC OglColorMaski;
extern PFNGLGETBOOLEANI_VPROC OglGetBooleani_v;
extern PFNGLGETINTEGERI_VPROC OglGetIntegeri_v;
extern PFNGLENABLEIPROC OglEnablei;
extern PFNGLDISABLEIPROC OglDisablei;
extern PFNGLISENABLEDIPROC OglIsEnabledi;
extern PFNGLBEGINTRANSFORMFEEDBACKPROC OglBeginTransformFeedback;
extern PFNGLENDTRANSFORMFEEDBACKPROC OglEndTransformFeedback;
extern PFNGLBINDBUFFERRANGEPROC OglBindBufferRange;
extern PFNGLBINDBUFFERBASEPROC OglBindBufferBase;
extern PFNGLTRANSFORMFEEDBACKVARYINGSPROC OglTransformFeedbackVaryings;
extern PFNGLGETTRANSFORMFEEDBACKVARYINGPROC OglGetTransformFeedbackVarying;
extern PFNGLCLAMPCOLORPROC OglClampColor;
extern PFNGLBEGINCONDITIONALRENDERPROC OglBeginConditionalRender;
extern PFNGLENDCONDITIONALRENDERPROC OglEndConditionalRender;
extern PFNGLVERTEXATTRIBIPOINTERPROC OglVertexAttribIPointer;
extern PFNGLGETVERTEXATTRIBIIVPROC OglGetVertexAttribIiv;
extern PFNGLGETVERTEXATTRIBIUIVPROC OglGetVertexAttribIuiv;
extern PFNGLVERTEXATTRIBI1IPROC OglVertexAttribI1i;
extern PFNGLVERTEXATTRIBI2IPROC OglVertexAttribI2i;
extern PFNGLVERTEXATTRIBI3IPROC OglVertexAttribI3i;
extern PFNGLVERTEXATTRIBI4IPROC OglVertexAttribI4i;
extern PFNGLVERTEXATTRIBI1UIPROC OglVertexAttribI1ui;
extern PFNGLVERTEXATTRIBI2UIPROC OglVertexAttribI2ui;
extern PFNGLVERTEXATTRIBI3UIPROC OglVertexAttribI3ui;
extern PFNGLVERTEXATTRIBI4UIPROC OglVertexAttribI4ui;
extern PFNGLVERTEXATTRIBI1IVPROC OglVertexAttribI1iv;
extern PFNGLVERTEXATTRIBI2IVPROC OglVertexAttribI2iv;
extern PFNGLVERTEXATTRIBI3IVPROC OglVertexAttribI3iv;
extern PFNGLVERTEXATTRIBI4IVPROC OglVertexAttribI4iv;
extern PFNGLVERTEXATTRIBI1UIVPROC OglVertexAttribI1uiv;
extern PFNGLVERTEXATTRIBI2UIVPROC OglVertexAttribI2uiv;
extern PFNGLVERTEXATTRIBI3UIVPROC OglVertexAttribI3uiv;
extern PFNGLVERTEXATTRIBI4UIVPROC OglVertexAttribI4uiv;
extern PFNGLVERTEXATTRIBI4BVPROC OglVertexAttribI4bv;
extern PFNGLVERTEXATTRIBI4SVPROC OglVertexAttribI4sv;
extern PFNGLVERTEXATTRIBI4UBVPROC OglVertexAttribI4ubv;
extern PFNGLVERTEXATTRIBI4USVPROC OglVertexAttribI4usv;
extern PFNGLGETUNIFORMUIVPROC OglGetUniformuiv;
extern PFNGLBINDFRAGDATALOCATIONPROC OglBindFragDataLocation;
extern PFNGLGETFRAGDATALOCATIONPROC OglGetFragDataLocation;
extern PFNGLUNIFORM1UIPROC OglUniform1ui;
extern PFNGLUNIFORM2UIPROC OglUniform2ui;
extern PFNGLUNIFORM3UIPROC OglUniform3ui;
extern PFNGLUNIFORM4UIPROC OglUniform4ui;
extern PFNGLUNIFORM1UIVPROC OglUniform1uiv;
extern PFNGLUNIFORM2UIVPROC OglUniform2uiv;
extern PFNGLUNIFORM3UIVPROC OglUniform3uiv;
extern PFNGLUNIFORM4UIVPROC OglUniform4uiv;
extern PFNGLTEXPARAMETERIIVPROC OglTexParameterIiv;
extern PFNGLTEXPARAMETERIUIVPROC OglTexParameterIuiv;
extern PFNGLGETTEXPARAMETERIIVPROC OglGetTexParameterIiv;
extern PFNGLGETTEXPARAMETERIUIVPROC OglGetTexParameterIuiv;
extern PFNGLCLEARBUFFERIVPROC OglClearefferiv;
extern PFNGLCLEARBUFFERUIVPROC OglClearefferuiv;
extern PFNGLCLEARBUFFERFVPROC OglClearefferfv;
extern PFNGLCLEARBUFFERFIPROC OglClearefferfi;
extern PFNGLGETSTRINGIPROC OglGetStringi;
#define glColorMaski		OglColorMaski
#define glGetBooleani_v		OglGetBooleani_v
#define glGetIntegeri_v		OglGetIntegeri_v
#define glEnablei		OglEnablei
#define glDisablei		OglDisablei
#define glIsEnabledi		OglIsEnabledi
#define glBeginTransformFeedback		OglBeginTransformFeedback
#define glEndTransformFeedback		OglEndTransformFeedback
#define glBindBufferRange		OglBindBufferRange
#define glBindBufferBase		OglBindBufferBase
#define glTransformFeedbackVaryings		OglTransformFeedbackVaryings
#define glGetTransformFeedbackVarying		OglGetTransformFeedbackVarying
#define glClampColor		OglClampColor
#define glBeginConditionalRender		OglBeginConditionalRender
#define glEndConditionalRender		OglEndConditionalRender
#define glVertexAttribIPointer		OglVertexAttribIPointer
#define glGetVertexAttribIiv		OglGetVertexAttribIiv
#define glGetVertexAttribIuiv		OglGetVertexAttribIuiv
#define glVertexAttribI1i		OglVertexAttribI1i
#define glVertexAttribI2i		OglVertexAttribI2i
#define glVertexAttribI3i		OglVertexAttribI3i
#define glVertexAttribI4i		OglVertexAttribI4i
#define glVertexAttribI1ui		OglVertexAttribI1ui
#define glVertexAttribI2ui		OglVertexAttribI2ui
#define glVertexAttribI3ui		OglVertexAttribI3ui
#define glVertexAttribI4ui		OglVertexAttribI4ui
#define glVertexAttribI1iv		OglVertexAttribI1iv
#define glVertexAttribI2iv		OglVertexAttribI2iv
#define glVertexAttribI3iv		OglVertexAttribI3iv
#define glVertexAttribI4iv		OglVertexAttribI4iv
#define glVertexAttribI1uiv		OglVertexAttribI1uiv
#define glVertexAttribI2uiv		OglVertexAttribI2uiv
#define glVertexAttribI3uiv		OglVertexAttribI3uiv
#define glVertexAttribI4uiv		OglVertexAttribI4uiv
#define glVertexAttribI4bv		OglVertexAttribI4bv
#define glVertexAttribI4sv		OglVertexAttribI4sv
#define glVertexAttribI4ubv		OglVertexAttribI4ubv
#define glVertexAttribI4usv		OglVertexAttribI4usv
#define glGetUniformuiv		OglGetUniformuiv
#define glBindFragDataLocation		OglBindFragDataLocation
#define glGetFragDataLocation		OglGetFragDataLocation
#define glUniform1ui		OglUniform1ui
#define glUniform2ui		OglUniform2ui
#define glUniform3ui		OglUniform3ui
#define glUniform4ui		OglUniform4ui
#define glUniform1uiv		OglUniform1uiv
#define glUniform2uiv		OglUniform2uiv
#define glUniform3uiv		OglUniform3uiv
#define glUniform4uiv		OglUniform4uiv
#define glTexParameterIiv		OglTexParameterIiv
#define glTexParameterIuiv		OglTexParameterIuiv
#define glGetTexParameterIiv		OglGetTexParameterIiv
#define glGetTexParameterIuiv		OglGetTexParameterIuiv
#define glClearefferiv		OglClearefferiv
#define glClearefferuiv		OglClearefferuiv
#define glClearefferfv		OglClearefferfv
#define glClearefferfi		OglClearefferfi
#define glGetStringi		OglGetStringi
#endif	// GL_VERSION_3_0

#ifndef GL_VERSION_3_1
#define GL_VERSION_3_1 1

#define GL_SAMPLER_2D_RECT                0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW         0x8B64
#define GL_SAMPLER_BUFFER                 0x8DC2
#define GL_INT_SAMPLER_2D_RECT            0x8DCD
#define GL_INT_SAMPLER_BUFFER             0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT   0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER    0x8DD8
#define GL_TEXTURE_BUFFER                 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE        0x8C2B
#define GL_TEXTURE_BINDING_BUFFER         0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_RECTANGLE              0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE      0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE        0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE     0x84F8
#define GL_RED_SNORM                      0x8F90
#define GL_RG_SNORM                       0x8F91
#define GL_RGB_SNORM                      0x8F92
#define GL_RGBA_SNORM                     0x8F93
#define GL_R8_SNORM                       0x8F94
#define GL_RG8_SNORM                      0x8F95
#define GL_RGB8_SNORM                     0x8F96
#define GL_RGBA8_SNORM                    0x8F97
#define GL_R16_SNORM                      0x8F98
#define GL_RG16_SNORM                     0x8F99
#define GL_RGB16_SNORM                    0x8F9A
#define GL_RGBA16_SNORM                   0x8F9B
#define GL_SIGNED_NORMALIZED              0x8F9C
#define GL_PRIMITIVE_RESTART              0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX        0x8F9E
// Reuse tokens from ARB_copy_buffer
// reuse GL_COPY_READ_BUFFER
// reuse GL_COPY_WRITE_BUFFER
// Reuse tokens from ARB_draw_instanced (none)
// Reuse tokens from ARB_uniform_buffer_object
// reuse GL_UNIFORM_BUFFER
// reuse GL_UNIFORM_BUFFER_BINDING
// reuse GL_UNIFORM_BUFFER_START
// reuse GL_UNIFORM_BUFFER_SIZE
// reuse GL_MAX_VERTEX_UNIFORM_BLOCKS
// reuse GL_MAX_FRAGMENT_UNIFORM_BLOCKS
// reuse GL_MAX_COMBINED_UNIFORM_BLOCKS
// reuse GL_MAX_UNIFORM_BUFFER_BINDINGS
// reuse GL_MAX_UNIFORM_BLOCK_SIZE
// reuse GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
// reuse GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
// reuse GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
// reuse GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH
// reuse GL_ACTIVE_UNIFORM_BLOCKS
// reuse GL_UNIFORM_TYPE
// reuse GL_UNIFORM_SIZE
// reuse GL_UNIFORM_NAME_LENGTH
// reuse GL_UNIFORM_BLOCK_INDEX
// reuse GL_UNIFORM_OFFSET
// reuse GL_UNIFORM_ARRAY_STRIDE
// reuse GL_UNIFORM_MATRIX_STRIDE
// reuse GL_UNIFORM_IS_ROW_MAJOR
// reuse GL_UNIFORM_BLOCK_BINDING
// reuse GL_UNIFORM_BLOCK_DATA_SIZE
// reuse GL_UNIFORM_BLOCK_NAME_LENGTH
// reuse GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS
// reuse GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES
// reuse GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER
// reuse GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER
// reuse GL_INVALID_INDEX
// OpenGL 3.1 also reuses entry points from these extensions:
// ARB_copy_buffer
// ARB_uniform_buffer_object
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
GLAPI void APIENTRY glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount);
GLAPI void APIENTRY glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer);
GLAPI void APIENTRY glPrimitiveRestartIndex(GLuint index);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC) (GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount);
typedef void (APIENTRYP PFNGLTEXBUFFERPROC) (GLenum target, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC) (GLuint index);
extern PFNGLDRAWARRAYSINSTANCEDPROC OglDrawArraysInstanced;
extern PFNGLDRAWELEMENTSINSTANCEDPROC OglDrawElementsInstanced;
extern PFNGLTEXBUFFERPROC OglTexBuffer;
extern PFNGLPRIMITIVERESTARTINDEXPROC OglPrimitiveRestartIndex;
#define glDrawArraysInstanced		OglDrawArraysInstanced
#define glDrawElementsInstanced		OglDrawElementsInstanced
#define glTexBuffer		OglTexBuffer
#define glPrimitiveRestartIndex		OglPrimitiveRestartIndex
#endif	// GL_VERSION_3_1

#ifndef GL_VERSION_3_2
#define GL_VERSION_3_2 1

#define GL_CONTEXT_CORE_PROFILE_BIT       0x00000001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_LINES_ADJACENCY                0x000A
#define GL_LINE_STRIP_ADJACENCY           0x000B
#define GL_TRIANGLES_ADJACENCY            0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY       0x000D
#define GL_PROGRAM_POINT_SIZE             0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_SHADER                0x8DD9
#define GL_GEOMETRY_VERTICES_OUT          0x8916
#define GL_GEOMETRY_INPUT_TYPE            0x8917
#define GL_GEOMETRY_OUTPUT_TYPE           0x8918
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES   0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS   0x9122
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS  0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS  0x9125
#define GL_CONTEXT_PROFILE_MASK           0x9126
// reuse GL_MAX_VARYING_COMPONENTS
// reuse GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER
// Reuse tokens from ARB_depth_clamp
// reuse GL_DEPTH_CLAMP
// Reuse tokens from ARB_draw_elements_base_vertex (none)
// Reuse tokens from ARB_fragment_coord_conventions (none)
// Reuse tokens from ARB_provoking_vertex
// reuse GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION
// reuse GL_FIRST_VERTEX_CONVENTION
// reuse GL_LAST_VERTEX_CONVENTION
// reuse GL_PROVOKING_VERTEX
// Reuse tokens from ARB_seamless_cube_map
// reuse GL_TEXTURE_CUBE_MAP_SEAMLESS
// Reuse tokens from ARB_sync
// reuse GL_MAX_SERVER_WAIT_TIMEOUT
// reuse GL_OBJECT_TYPE
// reuse GL_SYNC_CONDITION
// reuse GL_SYNC_STATUS
// reuse GL_SYNC_FLAGS
// reuse GL_SYNC_FENCE
// reuse GL_SYNC_GPU_COMMANDS_COMPLETE
// reuse GL_UNSIGNALED
// reuse GL_SIGNALED
// reuse GL_ALREADY_SIGNALED
// reuse GL_TIMEOUT_EXPIRED
// reuse GL_CONDITION_SATISFIED
// reuse GL_WAIT_FAILED
// reuse GL_TIMEOUT_IGNORED
// reuse GL_SYNC_FLUSH_COMMANDS_BIT
// reuse GL_TIMEOUT_IGNORED
// Reuse tokens from ARB_texture_multisample
// reuse GL_SAMPLE_POSITION
// reuse GL_SAMPLE_MASK
// reuse GL_SAMPLE_MASK_VALUE
// reuse GL_MAX_SAMPLE_MASK_WORDS
// reuse GL_TEXTURE_2D_MULTISAMPLE
// reuse GL_PROXY_TEXTURE_2D_MULTISAMPLE
// reuse GL_TEXTURE_2D_MULTISAMPLE_ARRAY
// reuse GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY
// reuse GL_TEXTURE_BINDING_2D_MULTISAMPLE
// reuse GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
// reuse GL_TEXTURE_SAMPLES
// reuse GL_TEXTURE_FIXED_SAMPLE_LOCATIONS
// reuse GL_SAMPLER_2D_MULTISAMPLE
// reuse GL_INT_SAMPLER_2D_MULTISAMPLE
// reuse GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
// reuse GL_SAMPLER_2D_MULTISAMPLE_ARRAY
// reuse GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
// reuse GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
// reuse GL_MAX_COLOR_TEXTURE_SAMPLES
// reuse GL_MAX_DEPTH_TEXTURE_SAMPLES
// reuse GL_MAX_INTEGER_SAMPLES
// Don't need to reuse tokens from ARB_vertex_array_bgra since they're already in 1.2 core
// OpenGL 3.2 also reuses entry points from these extensions:
// ARB_draw_elements_base_vertex
// ARB_provoking_vertex
// ARB_sync
// ARB_texture_multisample
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glGetInteger64i_v(GLenum target, GLuint index, GLint64* data);
GLAPI void APIENTRY glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64* params);
GLAPI void APIENTRY glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLGETINTEGER64I_VPROC) (GLenum target, GLuint index, GLint64* data);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC) (GLenum target, GLenum pname, GLint64* params);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level);
extern PFNGLGETINTEGER64I_VPROC OglGetInteger64i_v;
extern PFNGLGETBUFFERPARAMETERI64VPROC OglGetBufferParameteri64v;
extern PFNGLFRAMEBUFFERTEXTUREPROC OglFramebufferTexture;
#define glGetInteger64i_v		OglGetInteger64i_v
#define glGetBufferParameteri64v		OglGetBufferParameteri64v
#define glFramebufferTexture		OglFramebufferTexture
#endif	// GL_VERSION_3_2

#ifndef GL_VERSION_3_3
#define GL_VERSION_3_3 1

// OpenGL 3.3 also reuses entry points from these extensions:
// ARB_blend_func_extended
// ARB_sampler_objects
// ARB_explicit_attrib_location, but it has none
// ARB_occlusion_query2 (no entry points)
// ARB_shader_bit_encoding (no entry points)
// ARB_texture_rgb10_a2ui (no entry points)
// ARB_texture_swizzle (no entry points)
// ARB_timer_query
// ARB_vertex_type_2_10_10_10_rev
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR    0x88FE
// Reuse tokens from ARB_blend_func_extended
// reuse GL_SRC1_COLOR
// reuse GL_ONE_MINUS_SRC1_COLOR
// reuse GL_ONE_MINUS_SRC1_ALPHA
// reuse GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
// Reuse tokens from ARB_explicit_attrib_location (none)
// Reuse tokens from ARB_occlusion_query2
// reuse GL_ANY_SAMPLES_PASSED
// Reuse tokens from ARB_sampler_objects
// reuse GL_SAMPLER_BINDING
// Reuse tokens from ARB_shader_bit_encoding (none)
// Reuse tokens from ARB_texture_rgb10_a2ui
// reuse GL_RGB10_A2UI
// Reuse tokens from ARB_texture_swizzle
// reuse GL_TEXTURE_SWIZZLE_R
// reuse GL_TEXTURE_SWIZZLE_G
// reuse GL_TEXTURE_SWIZZLE_B
// reuse GL_TEXTURE_SWIZZLE_A
// reuse GL_TEXTURE_SWIZZLE_RGBA
// Reuse tokens from ARB_timer_query
// reuse GL_TIME_ELAPSED
// reuse GL_TIMESTAMP
// Reuse tokens from ARB_vertex_type_2_10_10_10_rev
// reuse GL_INT_2_10_10_10_REV
#ifdef GLCOREARB_PROTOTYPES
GLAPI void APIENTRY glVertexAttribDivisor(GLuint index, GLuint divisor);
#endif // GLCOREARB_PROTOTYPES
typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC) (GLuint index, GLuint divisor);
extern PFNGLVERTEXATTRIBDIVISORPROC OglVertexAttribDivisor;
#define glVertexAttribDivisor		OglVertexAttribDivisor
#endif	// GL_VERSION_3_3

#endif	// NWG_OGL_V3_H