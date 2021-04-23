#ifndef NW_GFX_LIB_MATERIAL_H
#define NW_GFX_LIB_MATERIAL_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#include "nw_gfx_lib_core.h"
namespace NW
{
	extern v1bit gfx_load_mtl();
}
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	// general
	typedef GLuint(NW_API_ENTRYP pfn_gfx_mtl_crt)(GLvoid);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_del)(GLuint mtl_id);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_use)(GLuint mtl_id);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_attach_shd)(GLuint mtl_id, GLuint shd_id);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_detach_shd)(GLuint mtl_id, GLuint shd_id);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_link_shds)(GLuint mtl_id);
	// getters
	typedef GLint(NW_API_ENTRYP pfn_gfx_mtl_get_loc_atb)(GLuint mtl_id, const GLchar* atb_name);
	typedef GLint(NW_API_ENTRYP pfn_gfx_mtl_get_loc_unf)(GLuint mtl_id, const GLchar* unf_name);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_get_iv)(GLuint shd_id, GLenum param_type, GLint* param_buf);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_get_info_log)(GLuint shd_id, GLsizei max_length, GLsizei* length, GLchar* info_log_buf);
	// uniforms
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_1si32)(GLint loc_idx, GLint val0);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_2si32)(GLint loc_idx, GLint val0, GLint val1);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_3si32)(GLint loc_idx, GLint val0, GLint val1, GLint val2);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_4si32)(GLint loc_idx, GLint val0, GLint val1, GLint val2, GLint val3);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_v1s32)(GLint loc_idx, GLsizei count, const GLint* val);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_v2s32)(GLint loc_idx, GLsizei count, const GLint* val);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_v3s32)(GLint loc_idx, GLsizei count, const GLint* val);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_v4s32)(GLint loc_idx, GLsizei count, const GLint* val);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_1ui32)(GLint loc_idx, GLuint val0);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_2ui32)(GLint loc_idx, GLuint val0, GLuint val1);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_3ui32)(GLint loc_idx, GLuint val0, GLuint val1, GLuint val2);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_4ui32)(GLint loc_idx, GLuint val0, GLuint val1, GLuint val2, GLuint val3);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_v1u32)(GLint loc_idx, GLsizei count, const GLuint* val);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_v2u32)(GLint loc_idx, GLsizei count, const GLuint* val);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_v3u32)(GLint loc_idx, GLsizei count, const GLuint* val);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_v4u32)(GLint loc_idx, GLsizei count, const GLuint* val);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_1f32)(GLint loc_idx, GLfloat val0);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_2f32)(GLint loc_idx, GLfloat val0, GLfloat val1);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_3f32)(GLint loc_idx, GLfloat val0, GLfloat val1, GLfloat val2);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_4f32)(GLint loc_idx, GLfloat val0, GLfloat val1, GLfloat val2, GLfloat val3);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_v1f32)(GLint loc_idx, GLsizei count, const GLfloat* val);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_v2f32)(GLint loc_idx, GLsizei count, const GLfloat* val);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_v3f32)(GLint loc_idx, GLsizei count, const GLfloat* val);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_v4f32)(GLint loc_idx, GLsizei count, const GLfloat* val);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_m2f32)(GLint loc_idx, GLsizei coiunt, GLboolean transpose, const GLfloat* val);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_m3f32)(GLint loc_idx, GLsizei count, GLboolean transpose, const GLfloat* val);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unf_m4f32)(GLint loc_idx, GLsizei count, GLboolean transpose, const GLfloat* val);
	// uniform blocks
	typedef v1nil(NW_API_ENTRYP pfn_gfx_mtl_unfb_binding)(GLuint mtl_id, GLuint unf_block_idx, GLuint unf_block_binding);
}
namespace NW
{
	// general
	extern pfn_gfx_mtl_crt ogl_mtl_crt;
	extern pfn_gfx_mtl_del ogl_mtl_del;
	extern pfn_gfx_mtl_use ogl_mtl_use;
	extern pfn_gfx_mtl_attach_shd ogl_mtl_attach_shd;
	extern pfn_gfx_mtl_detach_shd ogl_mtl_detach_shd;
	extern pfn_gfx_mtl_link_shds ogl_mtl_link;
	// getters
	extern pfn_gfx_mtl_get_loc_atb ogl_mtl_get_loc_atb;
	extern pfn_gfx_mtl_get_loc_unf ogl_mtl_get_loc_unf;
	extern pfn_gfx_mtl_get_iv ogl_mtl_get_iv;
	extern pfn_gfx_mtl_get_info_log ogl_mtl_get_info_log;
	// uniforms
	extern pfn_gfx_mtl_unf_1si32 ogl_mtl_unf_1si32;
	extern pfn_gfx_mtl_unf_2si32 ogl_mtl_unf_2si32;
	extern pfn_gfx_mtl_unf_3si32 ogl_mtl_unf_3si32;
	extern pfn_gfx_mtl_unf_4si32 ogl_mtl_unf_4si32;
	extern pfn_gfx_mtl_unf_v1s32 ogl_mtl_unf_v1s32;
	extern pfn_gfx_mtl_unf_v2s32 ogl_mtl_unf_v2s32;
	extern pfn_gfx_mtl_unf_v3s32 ogl_mtl_unf_v3s32;
	extern pfn_gfx_mtl_unf_v4s32 ogl_mtl_unf_v4s32;
	extern pfn_gfx_mtl_unf_1ui32 ogl_mtl_unf_1ui32;
	extern pfn_gfx_mtl_unf_2ui32 ogl_mtl_unf_2ui32;
	extern pfn_gfx_mtl_unf_3ui32 ogl_mtl_unf_3ui32;
	extern pfn_gfx_mtl_unf_4ui32 ogl_mtl_unf_4ui32;
	extern pfn_gfx_mtl_unf_v1u32 ogl_mtl_unf_v1u32;
	extern pfn_gfx_mtl_unf_v2u32 ogl_mtl_unf_v2u32;
	extern pfn_gfx_mtl_unf_v3u32 ogl_mtl_unf_v3u32;
	extern pfn_gfx_mtl_unf_v4u32 ogl_mtl_unf_v4u32;
	extern pfn_gfx_mtl_unf_1f32 ogl_mtl_unf_1f32;
	extern pfn_gfx_mtl_unf_2f32 ogl_mtl_unf_2f32;
	extern pfn_gfx_mtl_unf_3f32 ogl_mtl_unf_3f32;
	extern pfn_gfx_mtl_unf_4f32 ogl_mtl_unf_4f32;
	extern pfn_gfx_mtl_unf_v1f32 ogl_mtl_unf_v1f32;
	extern pfn_gfx_mtl_unf_v2f32 ogl_mtl_unf_v2f32;
	extern pfn_gfx_mtl_unf_v3f32 ogl_mtl_unf_v3f32;
	extern pfn_gfx_mtl_unf_v4f32 ogl_mtl_unf_v4f32;
	extern pfn_gfx_mtl_unf_m2f32 ogl_mtl_unf_m2f32;
	extern pfn_gfx_mtl_unf_m2f32 ogl_mtl_unf_m3f32;
	extern pfn_gfx_mtl_unf_m4f32 ogl_mtl_unf_m4f32;
	// uniform blocks
	extern pfn_gfx_mtl_unfb_binding ogl_mtl_unfb_binding;

}
// general
#define glCreateProgram ogl_mtl_crt
#define glDeleteProgram ogl_mtl_del
#define glUseProgram ogl_mtl_use
#define glAttachShader ogl_mtl_attach_shd
#define glDetachShader ogl_mtl_detach_shd
#define glLinkProgram ogl_mtl_link
// getters
#define glGetAttribLocation ogl_mtl_get_loc_atb
#define glGetUniformLocation ogl_mtl_get_loc_unf
#define glGetProgramiv ogl_mtl_get_iv
#define glGetProgramInfoLog ogl_mtl_get_info_log
// uniforms
#define glUniform1i ogl_mtl_unf_1si32
#define glUniform2i ogl_mtl_unf_2si32
#define glUniform3i ogl_mtl_unf_3si32
#define glUniform4i ogl_mtl_unf_4si32
#define glUniform1iv ogl_mtl_unf_v1s32
#define glUniform2iv ogl_mtl_unf_v2s32
#define glUniform3iv ogl_mtl_unf_v3s32
#define glUniform4iv ogl_mtl_unf_v4s32
#define glUniform1ui ogl_mtl_unf_1ui32
#define glUniform2ui ogl_mtl_unf_2ui32
#define glUniform3ui ogl_mtl_unf_3ui32
#define glUniform4ui ogl_mtl_unf_4ui32
#define glUniform1uiv ogl_mtl_unf_v1u32
#define glUniform2uiv ogl_mtl_unf_v2u32
#define glUniform3uiv ogl_mtl_unf_v3u32
#define glUniform4uiv ogl_mtl_unf_v4u32
#define glUniform1f ogl_mtl_unf_1f32
#define glUniform2f ogl_mtl_unf_2f32
#define glUniform3f ogl_mtl_unf_3f32
#define glUniform4f ogl_mtl_unf_4f32
#define glUniform1fv ogl_mtl_unf_v1f32
#define glUniform2fv ogl_mtl_unf_v2f32
#define glUniform3fv ogl_mtl_unf_v3f32
#define glUniform4fv ogl_mtl_unf_v4f32
#define glUniformMatrix2fv ogl_mtl_unf_m2f32
#define glUniformMatrix3fv ogl_mtl_unf_m3f32
#define glUniformMatrix4fv ogl_mtl_unf_m4f32
// unfirom blocks
#define glUniformBlockBinding ogl_mtl_unfb_binding

#ifndef __gl_h__
#endif	// __gl_h__
#endif
#if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
}
#endif
#endif	// NW_GAPI
#endif	// NW_LOAD_MATERIAL_H