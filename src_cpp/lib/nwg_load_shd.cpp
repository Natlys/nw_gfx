#include <nwg_pch.hpp>
#include "nwg_load_shd.h"
#if (defined NW_GAPI)
#include "nwg_load.h"
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	bit ogl_load_shd() {
		// general
		glCreateShader = (pfn_ogl_shd_crt)(ogl_get_proc("glCreateShader"));
		glDeleteShader = (pfn_ogl_shd_del)(ogl_get_proc("glDeleteShader"));
		glCompileShader = (pfn_ogl_shd_compile)(ogl_get_proc("glCompileShader"));
		// getters
		glGetShaderiv = (pfn_ogl_shd_get_iv)(ogl_get_proc("glGetShaderiv"));
		glGetShaderInfoLog = (pfn_ogl_shd_get_info_log)(ogl_get_proc("glGetShaderInfoLog"));
		// setters
		glShaderSource = (pfn_ogl_shd_set_source)(ogl_get_proc("glShaderSource"));
		
		return true;
	}
}
namespace NW
{
	// general
	pfn_ogl_shd_crt glCreateShader = NULL;
	pfn_ogl_shd_del glDeleteShader = NULL;
	pfn_ogl_shd_compile glCompileShader = NULL;
	// getters
	pfn_ogl_shd_get_iv glGetShaderiv = NULL;
	pfn_ogl_shd_get_info_log glGetShaderInfoLog = NULL;

	// setters
	pfn_ogl_shd_set_source glShaderSource = NULL;
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	//
}
#endif
#endif	// NW_GAPI