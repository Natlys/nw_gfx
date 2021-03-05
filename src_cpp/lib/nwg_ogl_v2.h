#ifndef NWG_OGL_V2_H
#define NWG_OGL_V2_H
#include "nwg_ogl_native.h"
namespace NWG
{
	extern void OglLoadV2();
}
#ifndef GL_VERSION_2_0
#define GL_VERSION_2_0 1

#define GL_BLEND_EQUATION_RGB             0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED    0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE       0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE     0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE       0x8625
#define GL_CURRENT_VERTEX_ATTRIB          0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE      0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER    0x8645
#define GL_STENCIL_BACK_FUNC              0x8800
#define GL_STENCIL_BACK_FAIL              0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL   0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS   0x8803
#define GL_MAX_DRAW_BUFFERS               0x8824
#define GL_DRAW_BUFFER0                   0x8825
#define GL_DRAW_BUFFER1                   0x8826
#define GL_DRAW_BUFFER2                   0x8827
#define GL_DRAW_BUFFER3                   0x8828
#define GL_DRAW_BUFFER4                   0x8829
#define GL_DRAW_BUFFER5                   0x882A
#define GL_DRAW_BUFFER6                   0x882B
#define GL_DRAW_BUFFER7                   0x882C
#define GL_DRAW_BUFFER8                   0x882D
#define GL_DRAW_BUFFER9                   0x882E
#define GL_DRAW_BUFFER10                  0x882F
#define GL_DRAW_BUFFER11                  0x8830
#define GL_DRAW_BUFFER12                  0x8831
#define GL_DRAW_BUFFER13                  0x8832
#define GL_DRAW_BUFFER14                  0x8833
#define GL_DRAW_BUFFER15                  0x8834
#define GL_BLEND_EQUATION_ALPHA           0x883D
#define GL_MAX_VERTEX_ATTRIBS             0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS        0x8872
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS  0x8B4A
#define GL_MAX_VARYING_FLOATS             0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE                    0x8B4F
#define GL_FLOAT_VEC2                     0x8B50
#define GL_FLOAT_VEC3                     0x8B51
#define GL_FLOAT_VEC4                     0x8B52
#define GL_INT_VEC2                       0x8B53
#define GL_INT_VEC3                       0x8B54
#define GL_INT_VEC4                       0x8B55
#define GL_BOOL                           0x8B56
#define GL_BOOL_VEC2                      0x8B57
#define GL_BOOL_VEC3                      0x8B58
#define GL_BOOL_VEC4                      0x8B59
#define GL_FLOAT_MAT2                     0x8B5A
#define GL_FLOAT_MAT3                     0x8B5B
#define GL_FLOAT_MAT4                     0x8B5C
#define GL_SAMPLER_1D                     0x8B5D
#define GL_SAMPLER_2D                     0x8B5E
#define GL_SAMPLER_3D                     0x8B5F
#define GL_SAMPLER_CUBE                   0x8B60
#define GL_SAMPLER_1D_SHADOW              0x8B61
#define GL_SAMPLER_2D_SHADOW              0x8B62
#define GL_DELETE_STATUS                  0x8B80
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_VALIDATE_STATUS                0x8B83
#define GL_INFO_LOG_LENGTH                0x8B84
#define GL_ATTACHED_SHADERS               0x8B85
#define GL_ACTIVE_UNIFORMS                0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH      0x8B87
#define GL_SHADER_SOURCE_LENGTH           0x8B88
#define GL_ACTIVE_ATTRIBUTES              0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH    0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION       0x8B8C
#define GL_CURRENT_PROGRAM                0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN      0x8CA0
#define GL_LOWER_LEFT                     0x8CA1
#define GL_UPPER_LEFT                     0x8CA2
#define GL_STENCIL_BACK_REF               0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK        0x8CA4
#define GL_STENCIL_BACK_WRITEMASK         0x8CA5

typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC) (GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLDRAWBUFFERSPROC) (GLsizei n, const GLenum* bufs);
typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEPROC) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC) (GLenum face, GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILMASKSEPARATEPROC) (GLenum face, GLuint mask);
typedef void (APIENTRYP PFNGLATTACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONPROC) (GLuint program, GLuint index, const GLchar* name);
typedef void (APIENTRYP PFNGLCOMPILESHADERPROC) (GLuint shader);
typedef GLuint(APIENTRYP PFNGLCREATEPROGRAMPROC) (void);
typedef GLuint(APIENTRYP PFNGLCREATESHADERPROC) (GLenum type);
typedef void (APIENTRYP PFNGLDELETEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLDELETESHADERPROC) (GLuint shader);
typedef void (APIENTRYP PFNGLDETACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void (APIENTRYP PFNGLGETACTIVEATTRIBPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
typedef void (APIENTRYP PFNGLGETATTACHEDSHADERSPROC) (GLuint program, GLsizei maxCount, GLsizei* count, GLuint* obj);
typedef GLint(APIENTRYP PFNGLGETATTRIBLOCATIONPROC) (GLuint program, const GLchar* name);
typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC) (GLuint program, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC) (GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef void (APIENTRYP PFNGLGETSHADERIVPROC) (GLuint shader, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC) (GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef void (APIENTRYP PFNGLGETSHADERSOURCEPROC) (GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source);
typedef GLint(APIENTRYP PFNGLGETUNIFORMLOCATIONPROC) (GLuint program, const GLchar* name);
typedef void (APIENTRYP PFNGLGETUNIFORMFVPROC) (GLuint program, GLint location, GLfloat* params);
typedef void (APIENTRYP PFNGLGETUNIFORMIVPROC) (GLuint program, GLint location, GLint* params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVPROC) (GLuint index, GLenum pname, GLdouble* params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVPROC) (GLuint index, GLenum pname, GLfloat* params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVPROC) (GLuint index, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC) (GLuint index, GLenum pname, GLvoid** pointer);
typedef GLboolean(APIENTRYP PFNGLISPROGRAMPROC) (GLuint program);
typedef GLboolean(APIENTRYP PFNGLISSHADERPROC) (GLuint shader);
typedef void (APIENTRYP PFNGLLINKPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLSHADERSOURCEPROC) (GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);
typedef void (APIENTRYP PFNGLUSEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLUNIFORM1FPROC) (GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLUNIFORM2FPROC) (GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLUNIFORM3FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLUNIFORM4FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLUNIFORM1IPROC) (GLint location, GLint v0);
typedef void (APIENTRYP PFNGLUNIFORM2IPROC) (GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLUNIFORM3IPROC) (GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLUNIFORM4IPROC) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLUNIFORM1FVPROC) (GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORM2FVPROC) (GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORM3FVPROC) (GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORM4FVPROC) (GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORM1IVPROC) (GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLUNIFORM2IVPROC) (GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLUNIFORM3IVPROC) (GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLUNIFORM4IVPROC) (GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DPROC) (GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVPROC) (GLuint index, const GLdouble* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FPROC) (GLuint index, GLfloat x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVPROC) (GLuint index, const GLfloat* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SPROC) (GLuint index, GLshort x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVPROC) (GLuint index, const GLshort* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVPROC) (GLuint index, const GLdouble* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FPROC) (GLuint index, GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVPROC) (GLuint index, const GLfloat* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SPROC) (GLuint index, GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVPROC) (GLuint index, const GLshort* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVPROC) (GLuint index, const GLdouble* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVPROC) (GLuint index, const GLfloat* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SPROC) (GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVPROC) (GLuint index, const GLshort* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NBVPROC) (GLuint index, const GLbyte* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NIVPROC) (GLuint index, const GLint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NSVPROC) (GLuint index, const GLshort* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBPROC) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBVPROC) (GLuint index, const GLubyte* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUIVPROC) (GLuint index, const GLuint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUSVPROC) (GLuint index, const GLushort* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4BVPROC) (GLuint index, const GLbyte* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVPROC) (GLuint index, const GLdouble* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVPROC) (GLuint index, const GLfloat* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4IVPROC) (GLuint index, const GLint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SPROC) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVPROC) (GLuint index, const GLshort* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVPROC) (GLuint index, const GLubyte* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UIVPROC) (GLuint index, const GLuint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4USVPROC) (GLuint index, const GLushort* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC) (GLuint index, GLint count, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
extern PFNGLBLENDEQUATIONSEPARATEPROC OglBlendEquationSeparate;
extern PFNGLDRAWBUFFERSPROC OglDrawBuffers;
extern PFNGLSTENCILOPSEPARATEPROC OglStencilOpSeparate;
extern PFNGLSTENCILFUNCSEPARATEPROC OglStencilFuncSeparate;
extern PFNGLSTENCILMASKSEPARATEPROC OglStencilMaskSeparate;
extern PFNGLATTACHSHADERPROC OglAttachShader;
extern PFNGLBINDATTRIBLOCATIONPROC OglBindAttribLocation;
extern PFNGLCOMPILESHADERPROC OglCompileShader;
extern PFNGLCREATEPROGRAMPROC OglCreateProgram;
extern PFNGLCREATESHADERPROC OglCreateShader;
extern PFNGLDELETEPROGRAMPROC OglDeleteProgram;
extern PFNGLDELETESHADERPROC OglDeleteShader;
extern PFNGLDETACHSHADERPROC OglDetachShader;
extern PFNGLDISABLEVERTEXATTRIBARRAYPROC OglDisableVertexAttribArray;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC OglEnableVertexAttribArray;
extern PFNGLGETACTIVEATTRIBPROC OglGetActiveAttrib;
extern PFNGLGETACTIVEUNIFORMPROC OglGetActiveUniform;
extern PFNGLGETATTACHEDSHADERSPROC OglGetAttachedShaders;
extern PFNGLGETATTRIBLOCATIONPROC OglGetAttribLocation;
extern PFNGLGETPROGRAMIVPROC OglGetProgramiv;
extern PFNGLGETPROGRAMINFOLOGPROC OglGetProgramInfoLog;
extern PFNGLGETSHADERIVPROC OglGetShaderiv;
extern PFNGLGETSHADERINFOLOGPROC OglGetshader_infoLog;
extern PFNGLGETSHADERSOURCEPROC OglGetShaderSource;
extern PFNGLGETUNIFORMLOCATIONPROC OglGetUniformLocation;
extern PFNGLGETUNIFORMFVPROC OglGetUniformfv;
extern PFNGLGETUNIFORMIVPROC OglGetUniformiv;
extern PFNGLGETVERTEXATTRIBDVPROC OglGetVertexAttribdv;
extern PFNGLGETVERTEXATTRIBFVPROC OglGetVertexAttribfv;
extern PFNGLGETVERTEXATTRIBIVPROC OglGetVertexAttribiv;
extern PFNGLGETVERTEXATTRIBPOINTERVPROC OglGetVertexAttribPointerv;
extern PFNGLISPROGRAMPROC OglIsProgram;
extern PFNGLISSHADERPROC OglIsShader;
extern PFNGLLINKPROGRAMPROC OglLinkProgram;
extern PFNGLSHADERSOURCEPROC OglShaderSource;
extern PFNGLUSEPROGRAMPROC OglUseProgram;
extern PFNGLUNIFORM1FPROC OglUniform1f;
extern PFNGLUNIFORM2FPROC OglUniform2f;
extern PFNGLUNIFORM3FPROC OglUniform3f;
extern PFNGLUNIFORM4FPROC OglUniform4f;
extern PFNGLUNIFORM1IPROC OglUniform1i;
extern PFNGLUNIFORM2IPROC OglUniform2i;
extern PFNGLUNIFORM3IPROC OglUniform3i;
extern PFNGLUNIFORM4IPROC OglUniform4i;
extern PFNGLUNIFORM1FVPROC OglUniform1fv;
extern PFNGLUNIFORM2FVPROC OglUniform2fv;
extern PFNGLUNIFORM3FVPROC OglUniform3fv;
extern PFNGLUNIFORM4FVPROC OglUniform4fv;
extern PFNGLUNIFORM1IVPROC OglUniform1iv;
extern PFNGLUNIFORM2IVPROC OglUniform2iv;
extern PFNGLUNIFORM3IVPROC OglUniform3iv;
extern PFNGLUNIFORM4IVPROC OglUniform4iv;
extern PFNGLUNIFORMMATRIX2FVPROC OglUniformMatrix2fv;
extern PFNGLUNIFORMMATRIX3FVPROC OglUniformMatrix3fv;
extern PFNGLUNIFORMMATRIX4FVPROC OglUniformMatrix4fv;
extern PFNGLVALIDATEPROGRAMPROC OglValidateProgram;
extern PFNGLVERTEXATTRIB1DPROC OglVertexAttrib1d;
extern PFNGLVERTEXATTRIB1DVPROC OglVertexAttrib1dv;
extern PFNGLVERTEXATTRIB1FPROC OglVertexAttrib1f;
extern PFNGLVERTEXATTRIB1FVPROC OglVertexAttrib1fv;
extern PFNGLVERTEXATTRIB1SPROC OglVertexAttrib1s;
extern PFNGLVERTEXATTRIB1SVPROC OglVertexAttrib1sv;
extern PFNGLVERTEXATTRIB2DPROC OglVertexAttrib2d;
extern PFNGLVERTEXATTRIB2DVPROC OglVertexAttrib2dv;
extern PFNGLVERTEXATTRIB2FPROC OglVertexAttrib2f;
extern PFNGLVERTEXATTRIB2FVPROC OglVertexAttrib2fv;
extern PFNGLVERTEXATTRIB2SPROC OglVertexAttrib2s;
extern PFNGLVERTEXATTRIB2SVPROC OglVertexAttrib2sv;
extern PFNGLVERTEXATTRIB3DPROC OglVertexAttrib3d;
extern PFNGLVERTEXATTRIB3DVPROC OglVertexAttrib3dv;
extern PFNGLVERTEXATTRIB3FPROC OglVertexAttrib3f;
extern PFNGLVERTEXATTRIB3FVPROC OglVertexAttrib3fv;
extern PFNGLVERTEXATTRIB3SPROC OglVertexAttrib3s;
extern PFNGLVERTEXATTRIB3SVPROC OglVertexAttrib3sv;
extern PFNGLVERTEXATTRIB4NBVPROC OglVertexAttrib4Nbv;
extern PFNGLVERTEXATTRIB4NIVPROC OglVertexAttrib4Niv;
extern PFNGLVERTEXATTRIB4NSVPROC OglVertexAttrib4Nsv;
extern PFNGLVERTEXATTRIB4NUBPROC OglVertexAttrib4Nub;
extern PFNGLVERTEXATTRIB4NUBVPROC OglVertexAttrib4Nubv;
extern PFNGLVERTEXATTRIB4NUIVPROC OglVertexAttrib4Nuiv;
extern PFNGLVERTEXATTRIB4NUSVPROC OglVertexAttrib4Nusv;
extern PFNGLVERTEXATTRIB4BVPROC OglVertexAttrib4bv;
extern PFNGLVERTEXATTRIB4DPROC OglVertexAttrib4d;
extern PFNGLVERTEXATTRIB4DVPROC OglVertexAttrib4dv;
extern PFNGLVERTEXATTRIB4FPROC OglVertexAttrib4f;
extern PFNGLVERTEXATTRIB4FVPROC OglVertexAttrib4fv;
extern PFNGLVERTEXATTRIB4IVPROC OglVertexAttrib4iv;
extern PFNGLVERTEXATTRIB4SPROC OglVertexAttrib4s;
extern PFNGLVERTEXATTRIB4SVPROC OglVertexAttrib4sv;
extern PFNGLVERTEXATTRIB4UBVPROC OglVertexAttrib4ubv;
extern PFNGLVERTEXATTRIB4UIVPROC OglVertexAttrib4uiv;
extern PFNGLVERTEXATTRIB4USVPROC OglVertexAttrib4usv;
extern PFNGLVERTEXATTRIBPOINTERPROC OglVertexAttribPointer;
#define glBlendEquationSeparate		OglBlendEquationSeparate
#define glDrawBuffers		OglDrawBuffers
#define glStencilOpSeparate		OglStencilOpSeparate
#define glStencilFuncSeparate		OglStencilFuncSeparate
#define glStencilMaskSeparate		OglStencilMaskSeparate
#define glAttachShader		OglAttachShader
#define glBindAttribLocation		OglBindAttribLocation
#define glCompileShader		OglCompileShader
#define glCreateProgram		OglCreateProgram
#define glCreateShader		OglCreateShader
#define glDeleteProgram		OglDeleteProgram
#define glDeleteShader		OglDeleteShader
#define glDetachShader		OglDetachShader
#define glDisableVertexAttribArray		OglDisableVertexAttribArray
#define glEnableVertexAttribArray		OglEnableVertexAttribArray
#define glGetActiveAttrib		OglGetActiveAttrib
#define glGetActiveUniform		OglGetActiveUniform
#define glGetAttachedShaders		OglGetAttachedShaders
#define glGetAttribLocation		OglGetAttribLocation
#define glGetProgramiv		OglGetProgramiv
#define glGetProgramInfoLog		OglGetProgramInfoLog
#define glGetShaderiv		OglGetShaderiv
#define glGetshader_infoLog		OglGetshader_infoLog
#define glGetShaderSource		OglGetShaderSource
#define glGetUniformLocation		OglGetUniformLocation
#define glGetUniformfv		OglGetUniformfv
#define glGetUniformiv		OglGetUniformiv
#define glGetVertexAttribdv		OglGetVertexAttribdv
#define glGetVertexAttribfv		OglGetVertexAttribfv
#define glGetVertexAttribiv		OglGetVertexAttribiv
#define glGetVertexAttribPointerv		OglGetVertexAttribPointerv
#define glIsProgram		OglIsProgram
#define glIsShader		OglIsShader
#define glLinkProgram		OglLinkProgram
#define glShaderSource		OglShaderSource
#define glUseProgram		OglUseProgram
#define glUniform1f		OglUniform1f
#define glUniform2f		OglUniform2f
#define glUniform3f		OglUniform3f
#define glUniform4f		OglUniform4f
#define glUniform1i		OglUniform1i
#define glUniform2i		OglUniform2i
#define glUniform3i		OglUniform3i
#define glUniform4i		OglUniform4i
#define glUniform1ui		OglUniform1ui
#define glUniform2ui		OglUniform2ui
#define glUniform3ui		OglUniform3ui
#define glUniform4ui		OglUniform4ui
#define glUniform1fv		OglUniform1fv
#define glUniform2fv		OglUniform2fv
#define glUniform3fv		OglUniform3fv
#define glUniform4fv		OglUniform4fv
#define glUniform1iv		OglUniform1iv
#define glUniform2iv		OglUniform2iv
#define glUniform3iv		OglUniform3iv
#define glUniform4iv		OglUniform4iv
#define glUniformMatrix2fv		OglUniformMatrix2fv
#define glUniformMatrix3fv		OglUniformMatrix3fv
#define glUniformMatrix4fv		OglUniformMatrix4fv
#define glValidateProgram		OglValidateProgram
#define glVertexAttrib1d		OglVertexAttrib1d
#define glVertexAttrib1dv		OglVertexAttrib1dv
#define glVertexAttrib1f		OglVertexAttrib1f
#define glVertexAttrib1fv		OglVertexAttrib1fv
#define glVertexAttrib1s		OglVertexAttrib1s
#define glVertexAttrib1sv		OglVertexAttrib1sv
#define glVertexAttrib2d		OglVertexAttrib2d
#define glVertexAttrib2dv		OglVertexAttrib2dv
#define glVertexAttrib2f		OglVertexAttrib2f
#define glVertexAttrib2fv		OglVertexAttrib2fv
#define glVertexAttrib2s		OglVertexAttrib2s
#define glVertexAttrib2sv		OglVertexAttrib2sv
#define glVertexAttrib3d		OglVertexAttrib3d
#define glVertexAttrib3dv		OglVertexAttrib3dv
#define glVertexAttrib3f		OglVertexAttrib3f
#define glVertexAttrib3fv		OglVertexAttrib3fv
#define glVertexAttrib3s		OglVertexAttrib3s
#define glVertexAttrib3sv		OglVertexAttrib3sv
#define glVertexAttrib4Nbv		OglVertexAttrib4Nbv
#define glVertexAttrib4Niv		OglVertexAttrib4Niv
#define glVertexAttrib4Nsv		OglVertexAttrib4Nsv
#define glVertexAttrib4Nub		OglVertexAttrib4Nub
#define glVertexAttrib4Nubv		OglVertexAttrib4Nubv
#define glVertexAttrib4Nuiv		OglVertexAttrib4Nuiv
#define glVertexAttrib4Nusv		OglVertexAttrib4Nusv
#define glVertexAttrib4bv		OglVertexAttrib4bv
#define glVertexAttrib4d		OglVertexAttrib4d
#define glVertexAttrib4dv		OglVertexAttrib4dv
#define glVertexAttrib4f		OglVertexAttrib4f
#define glVertexAttrib4fv		OglVertexAttrib4fv
#define glVertexAttrib4iv		OglVertexAttrib4iv
#define glVertexAttrib4s		OglVertexAttrib4s
#define glVertexAttrib4sv		OglVertexAttrib4sv
#define glVertexAttrib4ubv		OglVertexAttrib4ubv
#define glVertexAttrib4uiv		OglVertexAttrib4uiv
#define glVertexAttrib4usv		OglVertexAttrib4usv
#define glVertexAttribPointer		OglVertexAttribPointer
#endif	// GL_VERSION_2_0

#ifndef GL_VERSION_2_1
#define GL_VERSION_2_1 1

#define GL_PIXEL_PACK_BUFFER              0x88EB
#define GL_PIXEL_UNPACK_BUFFER            0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING      0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING    0x88EF
#define GL_FLOAT_MAT2x3                   0x8B65
#define GL_FLOAT_MAT2x4                   0x8B66
#define GL_FLOAT_MAT3x2                   0x8B67
#define GL_FLOAT_MAT3x4                   0x8B68
#define GL_FLOAT_MAT4x2                   0x8B69
#define GL_FLOAT_MAT4x3                   0x8B6A
#define GL_SRGB                           0x8C40
#define GL_SRGB8                          0x8C41
#define GL_SRGB_ALPHA                     0x8C42
#define GL_SRGB8_ALPHA8                   0x8C43
#define GL_COMPRESSED_SRGB                0x8C48
#define GL_COMPRESSED_SRGB_ALPHA          0x8C49

typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern PFNGLUNIFORMMATRIX2X3FVPROC OglUniformMatrix2x3fv;
extern PFNGLUNIFORMMATRIX3X2FVPROC OglUniformMatrix3x2fv;
extern PFNGLUNIFORMMATRIX2X4FVPROC OglUniformMatrix2x4fv;
extern PFNGLUNIFORMMATRIX4X2FVPROC OglUniformMatrix4x2fv;
extern PFNGLUNIFORMMATRIX3X4FVPROC OglUniformMatrix3x4fv;
extern PFNGLUNIFORMMATRIX4X3FVPROC OglUniformMatrix4x3fv;
#define glUniformMatrix2x3fv		OglUniformMatrix2x3fv
#define glUniformMatrix3x2fv		OglUniformMatrix3x2fv
#define glUniformMatrix2x4fv		OglUniformMatrix2x4fv
#define glUniformMatrix4x2fv		OglUniformMatrix4x2fv
#define glUniformMatrix3x4fv		OglUniformMatrix3x4fv
#define glUniformMatrix4x3fv		OglUniformMatrix4x3fv
#endif	// GL_VERSION_2_1

#endif	// NWG_OGL_V2_H