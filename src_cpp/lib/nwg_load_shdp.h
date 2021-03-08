#ifndef NWG_LOAD_SHDP_H
#define NWG_LOAD_SHDP_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include "nwg_load_base.h"
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	extern bit ogl_load_shdp();
}
namespace NWG
{
	// general
	typedef GLuint(APIENTRYP pfn_ogl_shdp_crt)(GLvoid);
	typedef void (APIENTRYP pfn_ogl_shdp_del)(GLuint shdp_id);
	typedef void (APIENTRYP pfn_ogl_shdp_use)(GLuint shdp_id);
	typedef void (APIENTRYP pfn_ogl_shdp_attach_shd)(GLuint shdp_id, GLuint shd_id);
	typedef void (APIENTRYP pfn_ogl_shdp_detach_shd)(GLuint shdp_id, GLuint shd_id);
	typedef void (APIENTRYP pfn_ogl_shdp_link)(GLuint shdp_id);
	// getters
	typedef GLint(APIENTRYP pfn_ogl_shdp_get_loc_atb)(GLuint shdp_id, const GLchar* atb_name);
	typedef GLint(APIENTRYP pfn_ogl_shdp_get_loc_unf)(GLuint shdp_id, const GLchar* unf_name);
	typedef void (APIENTRYP pfn_ogl_shdp_get_iv)(GLuint shd_id, GLenum param_type, GLint* param_buf);
	typedef void (APIENTRYP pfn_ogl_shdp_get_info_log)(GLuint shd_id, GLsizei max_length, GLsizei* length, GLchar* info_log_buf);
	// uniforms
	typedef void (APIENTRYP pfn_ogl_shdp_unf_1si32)(GLint loc_idx, GLint val0);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_2si32)(GLint loc_idx, GLint val0, GLint val1);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_3si32)(GLint loc_idx, GLint val0, GLint val1, GLint val2);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_4si32)(GLint loc_idx, GLint val0, GLint val1, GLint val2, GLint val3);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_v1si32)(GLint loc_idx, GLsizei count, const GLint* val);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_v2si32)(GLint loc_idx, GLsizei count, const GLint* val);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_v3si32)(GLint loc_idx, GLsizei count, const GLint* val);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_v4si32)(GLint loc_idx, GLsizei count, const GLint* val);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_1ui32)(GLint loc_idx, GLuint val0);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_2ui32)(GLint loc_idx, GLuint val0, GLuint val1);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_3ui32)(GLint loc_idx, GLuint val0, GLuint val1, GLuint val2);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_4ui32)(GLint loc_idx, GLuint val0, GLuint val1, GLuint val2, GLuint val3);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_v1ui32)(GLint loc_idx, GLsizei count, const GLuint* val);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_v2ui32)(GLint loc_idx, GLsizei count, const GLuint* val);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_v3ui32)(GLint loc_idx, GLsizei count, const GLuint* val);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_v4ui32)(GLint loc_idx, GLsizei count, const GLuint* val);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_1f32)(GLint loc_idx, GLfloat val0);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_2f32)(GLint loc_idx, GLfloat val0, GLfloat val1);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_3f32)(GLint loc_idx, GLfloat val0, GLfloat val1, GLfloat val2);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_4f32)(GLint loc_idx, GLfloat val0, GLfloat val1, GLfloat val2, GLfloat val3);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_v1f32)(GLint loc_idx, GLsizei count, const GLfloat* val);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_v2f32)(GLint loc_idx, GLsizei count, const GLfloat* val);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_v3f32)(GLint loc_idx, GLsizei count, const GLfloat* val);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_v4f32)(GLint loc_idx, GLsizei count, const GLfloat* val);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_m2f32)(GLint loc_idx, GLsizei coiunt, GLboolean transpose, const GLfloat* val);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_m3f32)(GLint loc_idx, GLsizei count, GLboolean transpose, const GLfloat* val);
	typedef void (APIENTRYP pfn_ogl_shdp_unf_m4f32)(GLint loc_idx, GLsizei count, GLboolean transpose, const GLfloat* val);
	// uniform blocks
	typedef void (APIENTRYP pfn_ogl_shdp_unfb_binding)(GLuint shdp_id, GLuint unf_block_idx, GLuint unf_block_binding);
}
namespace NWG
{
	// general
	extern pfn_ogl_shdp_crt ogl_shdp_crt;
	extern pfn_ogl_shdp_del ogl_shdp_del;
	extern pfn_ogl_shdp_use ogl_shdp_use;
	extern pfn_ogl_shdp_attach_shd ogl_shdp_attach_shd;
	extern pfn_ogl_shdp_detach_shd ogl_shdp_detach_shd;
	extern pfn_ogl_shdp_link ogl_shdp_link;
	// getters
	extern pfn_ogl_shdp_get_loc_atb ogl_shdp_get_loc_atb;
	extern pfn_ogl_shdp_get_loc_unf ogl_shdp_get_loc_unf;
	extern pfn_ogl_shdp_get_iv ogl_shdp_get_iv;
	extern pfn_ogl_shdp_get_info_log ogl_shdp_get_info_log;
	// uniforms
	extern pfn_ogl_shdp_unf_1si32 ogl_shdp_unf_1si32;
	extern pfn_ogl_shdp_unf_2si32 ogl_shdp_unf_2si32;
	extern pfn_ogl_shdp_unf_3si32 ogl_shdp_unf_3si32;
	extern pfn_ogl_shdp_unf_4si32 ogl_shdp_unf_4si32;
	extern pfn_ogl_shdp_unf_v1si32 ogl_shdp_unf_v1si32;
	extern pfn_ogl_shdp_unf_v2si32 ogl_shdp_unf_v2si32;
	extern pfn_ogl_shdp_unf_v3si32 ogl_shdp_unf_v3si32;
	extern pfn_ogl_shdp_unf_v4si32 ogl_shdp_unf_v4si32;
	extern pfn_ogl_shdp_unf_1ui32 ogl_shdp_unf_1ui32;
	extern pfn_ogl_shdp_unf_2ui32 ogl_shdp_unf_2ui32;
	extern pfn_ogl_shdp_unf_3ui32 ogl_shdp_unf_3ui32;
	extern pfn_ogl_shdp_unf_4ui32 ogl_shdp_unf_4ui32;
	extern pfn_ogl_shdp_unf_v1ui32 ogl_shdp_unf_v1ui32;
	extern pfn_ogl_shdp_unf_v2ui32 ogl_shdp_unf_v2ui32;
	extern pfn_ogl_shdp_unf_v3ui32 ogl_shdp_unf_v3ui32;
	extern pfn_ogl_shdp_unf_v4ui32 ogl_shdp_unf_v4ui32;
	extern pfn_ogl_shdp_unf_1f32 ogl_shdp_unf_1f32;
	extern pfn_ogl_shdp_unf_2f32 ogl_shdp_unf_2f32;
	extern pfn_ogl_shdp_unf_3f32 ogl_shdp_unf_3f32;
	extern pfn_ogl_shdp_unf_4f32 ogl_shdp_unf_4f32;
	extern pfn_ogl_shdp_unf_v1f32 ogl_shdp_unf_v1f32;
	extern pfn_ogl_shdp_unf_v2f32 ogl_shdp_unf_v2f32;
	extern pfn_ogl_shdp_unf_v3f32 ogl_shdp_unf_v3f32;
	extern pfn_ogl_shdp_unf_v4f32 ogl_shdp_unf_v4f32;
	extern pfn_ogl_shdp_unf_m2f32 ogl_shdp_unf_m2f32;
	extern pfn_ogl_shdp_unf_m2f32 ogl_shdp_unf_m3f32;
	extern pfn_ogl_shdp_unf_m4f32 ogl_shdp_unf_m4f32;
	// uniform blocks
	extern pfn_ogl_shdp_unfb_binding ogl_shdp_unfb_binding;

}
// general
#define glCreateProgram ogl_shdp_crt
#define glDeleteProgram ogl_shdp_del
#define glUseProgram ogl_shdp_use
#define glAttachShader ogl_shdp_attach_shd
#define glDetachShader ogl_shdp_detach_shd
#define glLinkProgram ogl_shdp_link
// getters
#define glGetAttribLocation ogl_shdp_get_loc_atb
#define glGetUniformLocation ogl_shdp_get_loc_unf
#define glGetProgramiv ogl_shdp_get_iv
#define glGetProgramInfoLog ogl_shdp_get_info_log
// uniforms
#define glUniform1i ogl_shdp_unf_1si32
#define glUniform2i ogl_shdp_unf_2si32
#define glUniform3i ogl_shdp_unf_3si32
#define glUniform4i ogl_shdp_unf_4si32
#define glUniform1iv ogl_shdp_unf_v1si32
#define glUniform2iv ogl_shdp_unf_v2si32
#define glUniform3iv ogl_shdp_unf_v3si32
#define glUniform4iv ogl_shdp_unf_v4si32
#define glUniform1ui ogl_shdp_unf_1ui32
#define glUniform2ui ogl_shdp_unf_2ui32
#define glUniform3ui ogl_shdp_unf_3ui32
#define glUniform4ui ogl_shdp_unf_4ui32
#define glUniform1uiv ogl_shdp_unf_v1ui32
#define glUniform2uiv ogl_shdp_unf_v2ui32
#define glUniform3uiv ogl_shdp_unf_v3ui32
#define glUniform4uiv ogl_shdp_unf_v4ui32
#define glUniform1f ogl_shdp_unf_1f32
#define glUniform2f ogl_shdp_unf_2f32
#define glUniform3f ogl_shdp_unf_3f32
#define glUniform4f ogl_shdp_unf_4f32
#define glUniform1fv ogl_shdp_unf_v1f32
#define glUniform2fv ogl_shdp_unf_v2f32
#define glUniform3fv ogl_shdp_unf_v3f32
#define glUniform4fv ogl_shdp_unf_v4f32
#define glUniformMatrix2fv ogl_shdp_unf_m2f32
#define glUniformMatrix3fv ogl_shdp_unf_m3f32
#define glUniformMatrix4fv ogl_shdp_unf_m4f32
// unfirom blocks
#define glUniformBlockBinding ogl_shdp_unfb_binding

#ifndef __gl_h__
#endif	// __gl_h__
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
}
#endif
#endif	// NWG_GAPI
#endif	// NWG_LOAD_SHDP_H