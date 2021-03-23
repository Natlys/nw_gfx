#include <nwg_pch.hpp>
#include "nwg_load_wgl.h"
#if (defined NW_GAPI)
#include "nwg_load.h"
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	bit gfx_load_wgl() {
		library_handle graphics_library = gfx_get_lib();
		// context
		wglCreateContext = (pfn_ogl_new_context)(::GetProcAddress(graphics_library, "wglCreateContext"));
		wglDeleteContext = (pfn_ogl_del_context)(::GetProcAddress(graphics_library, "wglDeleteContext"));
		wglGetCurrentContext = (pfn_ogl_get_ctxh)(::GetProcAddress(graphics_library, "wglGetCurrentContext"));
		wglMakeContextCurrent = (pfn_ogl_set_context)(::GetProcAddress(graphics_library, "wglMakeCurrent"));
		// device
		wglGetCurrentDC = (pfn_ogl_get_dvch)(::GetProcAddress(graphics_library, "wglGetCurrentDC"));
		// other
		wglGetProcAddress = (pfn_gfx_get_proc)(::GetProcAddress(graphics_library, "wglGetProcAddress"));

		return true;
	}
}
namespace NW
{
	// context
	pfn_ogl_new_context wglCreateContext = NULL;
	pfn_ogl_del_context wglDeleteContext = NULL;
	pfn_ogl_get_ctxh wglGetCurrentContext = NULL;
	pfn_ogl_set_context wglMakeContextCurrent = NULL;
	// device
	pfn_ogl_get_dvch wglGetCurrentDC = NULL;
	// other
	pfn_gfx_get_proc wglGetProcAddress = NULL;
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	bit gfx_load_wgl() {
		return true;
	}
}
#endif
#endif	// NW_GAPI