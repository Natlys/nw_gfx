#ifndef NWG_LOAD_WINDOWS_GRAPHICS_LIBRARY_H
#define NWG_LOAD_WINDOWS_GRAPHICS_LIBRARY_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
namespace NW
{
	extern bit gfx_load_wgl();
}
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	// context
	typedef context_handle(__stdcall* pfn_ogl_new_context)(device_handle device);
	typedef si32(__stdcall* pfn_ogl_del_context)(context_handle context);
	typedef context_handle(__stdcall* pfn_ogl_get_ctxh)();
	typedef si32(__stdcall* pfn_ogl_set_context)(device_handle device, context_handle context);
	// device
	typedef device_handle(__stdcall* pfn_ogl_get_dvch)();
	// other
	typedef ptr(__stdcall* pfn_gfx_get_proc)(cstr name);
}
namespace NW
{
	// context
	extern pfn_ogl_new_context ogl_new_context;
	extern pfn_ogl_del_context ogl_del_context;
	extern pfn_ogl_get_ctxh ogl_get_ctxh;
	extern pfn_ogl_set_context ogl_set_context;
	// device
	extern pfn_ogl_get_dvch ogl_get_dvch;
	// other
	extern pfn_gfx_get_proc gfx_get_proc_address;
}
// context
#define wglCreateContext ogl_new_context
#define wglDeleteContext ogl_del_context
#define wglGetCurrentContext ogl_get_ctxh
#define wglMakeContextCurrent ogl_set_context
// device
#define wglGetCurrentDC ogl_get_dvch
// other
#define wglGetProcAddress gfx_get_proc_address
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	//
}
#endif
#endif	// NW_GAPI
#endif	// NWG_LOAD_WINDOWS_GRAPHICS_LIBRARY_H