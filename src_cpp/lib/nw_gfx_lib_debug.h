#ifndef NW_GFX_LIB_DBG_H
#define NW_GFX_LIB_DBG_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_lib_core.h"
#	include "nw_gfx_lib_shd.h"
#	include "nw_gfx_lib_mtl.h"
namespace NW
{
	inline v1nil gfx_clear_err() { while (glGetError() != GL_NO_ERROR); }
	inline v1bit gfx_get_err_log(cstr_t loc, cstr_t fpath, cv1u line)
	{
		v1s err_code = 0u;
		while ((err_code = glGetError()) != GL_NO_ERROR) {
			switch (err_code) {
			case GL_INVALID_ENUM: throw a_error("INVALID_ENUM"); break;
			case GL_INVALID_VALUE: throw a_error("INVALID_VALUE"); break;
			case GL_INVALID_OPERATION: throw a_error("INVALID_OPERATION"); break;
			case GL_STACK_OVERFLOW: throw a_error("STACK_OVERFLOW"); break;
			case GL_STACK_UNDERFLOW: throw a_error("STACK_UNDERFLOW"); break;
			case GL_OUT_OF_MEMORY: throw a_error("OUT_OF_MEMORY"); break;
			}
			return NW_FALSE;
		}
		return NW_TRUE;
	}
	inline v1bit gfx_check_shader(v1u shd_id) {
		if (shd_id == 0) { return NW_FALSE; }
		v1s success_code = 0;
		v1s log_size = 0;
		dstr_t log_string;
		if (glIsShader(shd_id)) {
			glGetShaderiv(shd_id, GL_COMPILE_STATUS, &success_code);
			if (success_code == 0) {
				glGetShaderiv(shd_id, GL_INFO_LOG_LENGTH, &log_size);
				log_string.resize(log_size);
				glGetShaderInfoLog(shd_id, log_size, NULL, &log_string[0]);
				throw a_error(&log_string[0], __LINE__);
				return success_code == 1;
			}
		}
		else {
			glGetProgramiv(shd_id, GL_LINK_STATUS, &success_code);
			if (success_code == 0) {
				glGetProgramiv(shd_id, GL_INFO_LOG_LENGTH, &log_size);
				log_string.resize(log_size);
				glGetProgramInfoLog(shd_id, log_size, NULL, &log_string[0]);
				throw a_error(&log_string[0], __LINE__);
				return NW_FALSE;
			}
		}
		return success_code == 1;
	}
#	if (defined NW_DEBUG)
#		define NW_GFX_CALL(code)     \
		gfx_clear_err(); (code)      \
		NW_CHECK(gfx_get_err_log     \
		(#code, __FILE__, __LINE__), "graphics error!")
#	else
#		define NW_GFX_CALL(code) ( code )
#	endif
}
#	if (NW_GAPI & NW_GAPI_OGL)
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
#	endif	// GAPI_D3D
#endif // NW_GAPI
#endif // NW_GFX_LIB_DBG_H