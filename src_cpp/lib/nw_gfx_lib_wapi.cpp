#include "nw_gfx_pch.hpp"
#include "nw_gfx_lib_wapi.h"
#if (defined NW_GAPI)
#include "nw_gfx_lib.h"
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	v1bit gfx_load_wapi() {
		library_handle libh = gfx_get_lib();
		if (libh == NW_NULL) { return NW_FALSE; }
		// context
		wglCreateContext       = (pfn_gfx_new_context)(::GetProcAddress(libh, "wglCreateContext"));
		wglDeleteContext       = (pfn_gfx_del_context)(::GetProcAddress(libh, "wglDeleteContext"));
		wglGetCurrentContext   = (pfn_gfx_get_context)(::GetProcAddress(libh, "wglGetCurrentContext"));
		wglMakeContextCurrent  = (pfn_gfx_set_context)(::GetProcAddress(libh, "wglMakeCurrent"));
		// device
		wglGetCurrentDC        = (pfn_gfx_get_device)(::GetProcAddress(libh, "wglGetCurrentDC"));
		// other
		wglGetProcAddress      = (pfn_gfx_get_proc)(::GetProcAddress(libh, "wglGetProcAddress"));

		return NW_TRUE;
	}
	
	v1bit gfx_ext_has_support(cstr extension_name) { return strstr(wglGetExtensionsStringEXT(), extension_name) != NW_NULL; }
	
	v1bit gfx_ext_load_wapi()
	{
		if (gfx_get_lib() == NW_NULL) { return NW_FALSE; }

		wglGetExtensionsStringEXT = (pfn_gfx_ext_get_str)(gfx_get_proc("wglGetExtensionsStringEXT"));
		if (gfx_ext_has_support("WGL_EXT_swap_control")) {
			wglGetSwapIntervalEXT = (pfn_gfx_ext_get_vsync)(gfx_get_proc("wglGetSwapIntervalEXT"));
			wglSwapIntervalEXT = (pfn_gfx_ext_set_vsync)(gfx_get_proc("wglSwapIntervalEXT"));
		}

		return NW_TRUE;
	}
}
namespace NW
{
	// context
	pfn_gfx_new_context  wglCreateContext = NW_NULL;
	pfn_gfx_del_context  wglDeleteContext = NW_NULL;
	pfn_gfx_get_context  wglGetCurrentContext = NW_NULL;
	pfn_gfx_set_context  wglMakeContextCurrent = NW_NULL;
	// device
	pfn_gfx_get_device   wglGetCurrentDC = NW_NULL;
	// other
	pfn_gfx_get_proc     wglGetProcAddress = NW_NULL;
	// extensions
	pfn_gfx_ext_get_str   wglGetExtensionsStringEXT = NW_NULL;
	pfn_gfx_ext_get_vsync wglGetSwapIntervalEXT = NW_NULL;
	pfn_gfx_ext_set_vsync wglSwapIntervalEXT = NW_NULL;
}
#endif
#if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	v1bit gfx_load_wapi() {
		library_handle libh = gfx_get_lib();
		if (libh =NW_NULL) { return NW_FALSE; }
		
		return NW_TRUE;
	}

	v1bit gfx_ext_has_support(cstr extension_name) { return NW_FALSE; }

	v1bit gfx_ext_load_wapi()
	{
		if (gfx_get_lib() =NW_NULL) { return NW_FALSE; }

		return NW_TRUE;
	}
}
#endif
#endif	// NW_GAPI