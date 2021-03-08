#include <nwg_pch.hpp>
#include "nwg_load_wgl.h"
#if (defined NWG_GAPI)
#include "nwg_load.h"
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	bit ogl_load_wgl() {
		gfx_lib graphics_library = ogl_get_lib();
		// context
		wglCreateContext = (pfn_ogl_new_context)(::GetProcAddress(graphics_library, "wglCreateContext"));
		wglDeleteContext = (pfn_ogl_del_context)(::GetProcAddress(graphics_library, "wglDeleteContext"));
		wglGetCurrentContext = (pfn_ogl_get_context)(::GetProcAddress(graphics_library, "wglGetCurrentContext"));
		wglMakeContextCurrent = (pfn_ogl_set_context)(::GetProcAddress(graphics_library, "wglMakeCurrent"));
		// device
		wglGetCurrentDC = (pfn_ogl_get_device)(::GetProcAddress(graphics_library, "wglGetCurrentDC"));
		// other
		wglGetProcAddress = (pfn_ogl_get_proc)(::GetProcAddress(graphics_library, "wglGetProcAddress"));

		return true;
	}
}
namespace NWG
{
	// context
	pfn_ogl_new_context wglCreateContext = NULL;
	pfn_ogl_del_context wglDeleteContext = NULL;
	pfn_ogl_get_context wglGetCurrentContext = NULL;
	pfn_ogl_set_context wglMakeContextCurrent = NULL;
	// device
	pfn_ogl_get_device wglGetCurrentDC = NULL;
	// other
	pfn_ogl_get_proc wglGetProcAddress = NULL;
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
#endif
#endif	// NWG_GAPI