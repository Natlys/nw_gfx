#include <nwg_pch.hpp>
#include "nwg_load_layt.h"
#if (defined NW_GAPI)
#include "nwg_load.h"
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	bit ogl_load_varr() {
		// general
		glGenVertexArrays = (pfn_ogl_varr_gen)(ogl_get_proc("glGenVertexArrays"));
		glDeleteVertexArrays = (pfn_ogl_varr_del)(ogl_get_proc("glDeleteVertexArrays"));
		glBindVertexArray = (pfn_ogl_varr_bind)(ogl_get_proc("glBindVertexArray"));
		// data
		glEnableVertexAttribArray = (pfn_ogl_varr_enable_atb)(ogl_get_proc("glEnableVertexAttribArray"));
		glDisableVertexAttribArray = (pfn_ogl_varr_disable_atb)(ogl_get_proc("glEnableVertexAttribArray"));
		glVertexAttribPointer = (pfn_ogl_varr_set_atb)(ogl_get_proc("glVertexAttribPointer"));

		return true;
	}
}
namespace NW
{
	// general
	pfn_ogl_varr_gen glGenVertexArrays = NULL;
	pfn_ogl_varr_del glDeleteVertexArrays = NULL;
	pfn_ogl_varr_bind glBindVertexArray = NULL;
	// data
	pfn_ogl_varr_enable_atb glEnableVertexAttribArray = NULL;
	pfn_ogl_varr_disable_atb glDisableVertexAttribArray = NULL;
	pfn_ogl_varr_set_atb glVertexAttribPointer = NULL;
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	//
}
#endif
#endif	// NW_GAPI