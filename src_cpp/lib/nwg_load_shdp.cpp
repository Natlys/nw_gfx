#include <nwg_pch.hpp>
#include "nwg_load_shdp.h"
#if (defined NWG_GAPI)
#include "nwg_load.h"
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	bit ogl_load_shdp() {
		// general
		glCreateProgram = (pfn_ogl_shdp_crt)(ogl_get_proc("glCreateProgram"));
		glDeleteProgram = (pfn_ogl_shdp_del)(ogl_get_proc("glDeleteProgram"));
		glUseProgram = (pfn_ogl_shdp_use)(ogl_get_proc("glUseProgram"));
		glAttachShader = (pfn_ogl_shdp_attach_shd)(ogl_get_proc("glAttachShader"));
		glDetachShader = (pfn_ogl_shdp_detach_shd)(ogl_get_proc("glDetachShader"));
		glLinkProgram = (pfn_ogl_shdp_use)(ogl_get_proc("glLinkProgram"));
		// getters
		glGetAttribLocation = (pfn_ogl_shdp_get_loc_atb)(ogl_get_proc("glGetAttribLocation"));
		glGetUniformLocation = (pfn_ogl_shdp_get_loc_unf)(ogl_get_proc("glGetUniformLocation"));
		glGetProgramiv = (pfn_ogl_shdp_get_iv)(ogl_get_proc("glGetProgramiv"));
		glGetProgramInfoLog = (pfn_ogl_shdp_get_info_log)(ogl_get_proc("glGetProgramInfoLog"));
		// uniforms
		glUniform1i = (pfn_ogl_shdp_unf_1si32)(ogl_get_proc("glUniform1i"));
		glUniform2i = (pfn_ogl_shdp_unf_2si32)(ogl_get_proc("glUniform2i"));
		glUniform3i = (pfn_ogl_shdp_unf_3si32)(ogl_get_proc("glUniform3i"));
		glUniform4i = (pfn_ogl_shdp_unf_4si32)(ogl_get_proc("glUniform4i"));
		glUniform1iv = (pfn_ogl_shdp_unf_v1si32)(ogl_get_proc("glUniform1iv"));
		glUniform2iv = (pfn_ogl_shdp_unf_v2si32)(ogl_get_proc("glUniform2iv"));
		glUniform3iv = (pfn_ogl_shdp_unf_v3si32)(ogl_get_proc("glUniform3iv"));
		glUniform4iv = (pfn_ogl_shdp_unf_v4si32)(ogl_get_proc("glUniform4iv"));
		glUniform1ui = (pfn_ogl_shdp_unf_1ui32)(ogl_get_proc("glUniform1ui"));
		glUniform2ui = (pfn_ogl_shdp_unf_2ui32)(ogl_get_proc("glUniform2ui"));
		glUniform3ui = (pfn_ogl_shdp_unf_3ui32)(ogl_get_proc("glUniform3ui"));
		glUniform4ui = (pfn_ogl_shdp_unf_4ui32)(ogl_get_proc("glUniform4ui"));
		glUniform1uiv = (pfn_ogl_shdp_unf_v1ui32)(ogl_get_proc("glUniform1uiv"));
		glUniform2uiv = (pfn_ogl_shdp_unf_v2ui32)(ogl_get_proc("glUniform2uiv"));
		glUniform3uiv = (pfn_ogl_shdp_unf_v3ui32)(ogl_get_proc("glUniform3uiv"));
		glUniform4uiv = (pfn_ogl_shdp_unf_v4ui32)(ogl_get_proc("glUniform4uiv"));
		glUniform1f = (pfn_ogl_shdp_unf_1f32)(ogl_get_proc("glUniform1f"));
		glUniform2f = (pfn_ogl_shdp_unf_2f32)(ogl_get_proc("glUniform2f"));
		glUniform3f = (pfn_ogl_shdp_unf_3f32)(ogl_get_proc("glUniform3f"));
		glUniform4f = (pfn_ogl_shdp_unf_4f32)(ogl_get_proc("glUniform4f"));
		glUniform1fv = (pfn_ogl_shdp_unf_v1f32)(ogl_get_proc("glUniform1fv"));
		glUniform2fv = (pfn_ogl_shdp_unf_v2f32)(ogl_get_proc("glUniform2fv"));
		glUniform3fv = (pfn_ogl_shdp_unf_v3f32)(ogl_get_proc("glUniform3fv"));
		glUniform4fv = (pfn_ogl_shdp_unf_v4f32)(ogl_get_proc("glUniform4fv"));
		glUniformMatrix2fv = (pfn_ogl_shdp_unf_m2f32)(ogl_get_proc("glUniformMatrix2fv"));
		glUniformMatrix3fv = (pfn_ogl_shdp_unf_m3f32)(ogl_get_proc("glUniformMatrix3fv"));
		glUniformMatrix4fv = (pfn_ogl_shdp_unf_m4f32)(ogl_get_proc("glUniformMatrix4fv"));
		// uniform blocks
		glUniformBlockBinding = (pfn_ogl_shdp_unfb_binding)(ogl_get_proc("glUniformBlockBinding"));

		return true;
	}
}
namespace NWG
{
	// general
	pfn_ogl_shdp_crt glCreateProgram = NULL;
	pfn_ogl_shdp_del glDeleteProgram = NULL;
	pfn_ogl_shdp_use glUseProgram = NULL;
	pfn_ogl_shdp_attach_shd glAttachShader = NULL;
	pfn_ogl_shdp_detach_shd glDetachShader = NULL;
	pfn_ogl_shdp_link glLinkProgram = NULL;
	// getters
	pfn_ogl_shdp_get_loc_atb glGetAttribLocation = NULL;
	pfn_ogl_shdp_get_loc_unf glGetUniformLocation = NULL;
	pfn_ogl_shdp_get_iv glGetProgramiv = NULL;
	pfn_ogl_shdp_get_info_log glGetProgramInfoLog = NULL;
	// uniforms
	pfn_ogl_shdp_unf_1si32 glUniform1i = NULL;
	pfn_ogl_shdp_unf_2si32 glUniform2i = NULL;
	pfn_ogl_shdp_unf_3si32 glUniform3i = NULL;
	pfn_ogl_shdp_unf_4si32 glUniform4i = NULL;
	pfn_ogl_shdp_unf_v1si32 glUniform1iv = NULL;
	pfn_ogl_shdp_unf_v2si32 glUniform2iv = NULL;
	pfn_ogl_shdp_unf_v3si32 glUniform3iv = NULL;
	pfn_ogl_shdp_unf_v4si32 glUniform4iv = NULL;
	pfn_ogl_shdp_unf_1ui32 glUniform1ui = NULL;
	pfn_ogl_shdp_unf_2ui32 glUniform2ui = NULL;
	pfn_ogl_shdp_unf_3ui32 glUniform3ui = NULL;
	pfn_ogl_shdp_unf_4ui32 glUniform4ui = NULL;
	pfn_ogl_shdp_unf_v1ui32 glUniform1uiv = NULL;
	pfn_ogl_shdp_unf_v2ui32 glUniform2uiv = NULL;
	pfn_ogl_shdp_unf_v3ui32 glUniform3uiv = NULL;
	pfn_ogl_shdp_unf_v4ui32 glUniform4uiv = NULL;
	pfn_ogl_shdp_unf_1f32 glUniform1f = NULL;
	pfn_ogl_shdp_unf_2f32 glUniform2f = NULL;
	pfn_ogl_shdp_unf_3f32 glUniform3f = NULL;
	pfn_ogl_shdp_unf_4f32 glUniform4f = NULL;
	pfn_ogl_shdp_unf_v1f32 glUniform1fv = NULL;
	pfn_ogl_shdp_unf_v2f32 glUniform2fv = NULL;
	pfn_ogl_shdp_unf_v3f32 glUniform3fv = NULL;
	pfn_ogl_shdp_unf_v4f32 glUniform4fv = NULL;
	pfn_ogl_shdp_unf_m2f32 glUniformMatrix2fv = NULL;
	pfn_ogl_shdp_unf_m3f32 glUniformMatrix3fv = NULL;
	pfn_ogl_shdp_unf_m4f32 glUniformMatrix4fv = NULL;
	// uniform blocks
	pfn_ogl_shdp_unfb_binding glUniformBlockBinding = NULL;
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
	//
}
#endif
#endif	// NWG_GAPI