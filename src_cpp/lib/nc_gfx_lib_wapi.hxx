#ifndef NC_GFX_LIB_WINDOW_API_H
#define NC_GFX_LIB_WINDOW_API_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	// -context
	typedef context_handle(__stdcall* pfn_gfx_new_context) (device_handle device);
	typedef v1s_t(__stdcall* pfn_gfx_del_context)            (context_handle context);
	typedef context_handle(__stdcall* pfn_gfx_get_context) (v1nil_t);
	typedef v1s_t(__stdcall* pfn_gfx_set_context)            (device_handle device, context_handle context);
	// --device
	typedef device_handle(__stdcall* pfn_gfx_get_device)   (v1nil_t);
	// --other
	typedef ptr_t(__stdcall* pfn_gfx_get_proc)       (cstr_t name);
	// --extensions
	typedef cstr_t(__stdcall* pfn_gfx_ext_get_str)   (v1nil_t);
	typedef v1s_t(__stdcall* pfn_gfx_ext_get_vsync)    (v1nil_t);
	typedef v1nil_t(__stdcall* pfn_gfx_ext_set_vsync)  (v1s_t swap_interval);
}
namespace NC
{
	// --context
	extern pfn_gfx_new_context gfx_new_context;
	extern pfn_gfx_del_context gfx_del_context;
	extern pfn_gfx_get_context gfx_get_context;
	extern pfn_gfx_set_context gfx_set_context;
	// --device
	extern pfn_gfx_get_device    gfx_get_device;
	// --other
	extern pfn_gfx_get_proc      gfx_get_proc_address;
	// --extensions
	extern pfn_gfx_ext_get_str   gfx_ext_get_str;
	extern pfn_gfx_ext_get_vsync gfx_ext_get_vsync;
	extern pfn_gfx_ext_set_vsync gfx_ext_set_vsync;
}
// --context
#	define wglCreateContext       gfx_new_context
#	define wglDeleteContext       gfx_del_context
#	define wglGetCurrentContext   gfx_get_context
#	define wglMakeContextCurrent  gfx_set_context
// --device
#	define wglGetCurrentDC        gfx_get_device
// --other
#	define wglGetProcAddress      gfx_get_proc_address
// --extensions
#	define wglGetExtensionsStringEXT gfx_ext_get_str
#	define wglSwapIntervalEXT        gfx_ext_set_vsync
#	define wglGetSwapIntervalEXT     gfx_ext_get_vsync
#	endif	// GAPI_OGL
#endif	// NC_GAPI
#endif	// NC_GFX_LIB_WINDOW_API_H