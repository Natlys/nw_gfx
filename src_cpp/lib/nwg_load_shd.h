#ifndef NWG_LOAD_SHD_H
#define NWG_LOAD_SHD_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include "nwg_load_base.h"
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	extern bit ogl_load_shd();
}
namespace NWG
{
	// general
	typedef GLuint (APIENTRYP pfn_ogl_shd_crt)(GLenum shd_type);
	typedef void (APIENTRYP pfn_ogl_shd_del)(GLuint shd_id);
	typedef void (APIENTRYP pfn_ogl_shd_compile)(GLuint shd_id);
	// getters
	typedef void (APIENTRYP pfn_ogl_shd_get_iv)(GLuint shd_id, GLenum param_type, GLint* param_buf);
	typedef void (APIENTRYP pfn_ogl_shd_get_info_log)(GLuint shd_id, GLsizei max_length, GLsizei* length, GLchar* info_log_buf);
	// setters
	typedef void (APIENTRYP pfn_ogl_shd_set_source)(GLuint shd_id, GLsizei shd_count, const GLchar* const* src_string, const GLint* src_length);
}
namespace NWG
{
	// general
	extern pfn_ogl_shd_crt ogl_shd_crt;
	extern pfn_ogl_shd_del ogl_shd_del;
	extern pfn_ogl_shd_compile ogl_shd_compile;
	// getters
	extern pfn_ogl_shd_get_iv ogl_shd_get_iv;
	extern pfn_ogl_shd_get_info_log ogl_shd_get_info_log;

	// setters
	extern pfn_ogl_shd_set_source ogl_shd_set_source;
}
// general
#define glCreateShader ogl_shd_crt
#define glDeleteShader ogl_shd_del
#define glCompileShader ogl_shd_compile
// getters
#define glGetShaderiv ogl_shd_get_iv
#define glGetShaderInfoLog ogl_shd_get_info_log
// setters
#define glShaderSource ogl_shd_set_source

#ifndef __gl_h__
// general
#define GL_SHADER                         0x82E1
#define GL_PROGRAM                        0x82E2
#define GL_VERTEX_SHADER                  0x8B31
#define GL_GEOMETRY_SHADER                0x8DD9
#define GL_COMPUTE_SHADER                 0x91B9
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_ACTIVE_PROGRAM                 0x825
#define GL_CURRENT_PROGRAM                0x8B8D
#define GL_UNIFORM                        0x92E1
#define GL_UNIFORM_BLOCK                  0x92E2
#define GL_PROGRAM_INPUT                  0x92E3
#define GL_PROGRAM_OUTPUT                 0x92E4
// params
#define GL_MAX_UNIFORM_LOCATIONS          0x826E
#define GL_INFO_LOG_LENGTH                0x8B84
// info
#define GL_SHADING_LANGUAGE_VERSION       0x8B8C
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#endif	// __gl_h__
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
}
#endif
#endif	// NWG_GAPI
#endif	// NWG_LOAD_SHD_H