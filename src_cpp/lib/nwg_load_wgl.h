#ifndef NW_WGL_LOADER_H
#define NW_WGL_LOADER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	extern bit ogl_load_wgl();
}
namespace NW
{
	// context
	typedef context_handle(__stdcall* pfn_ogl_new_context)(device_handle device);
	typedef si32(__stdcall* pfn_ogl_del_context)(context_handle context);
	typedef context_handle(__stdcall* pfn_ogl_get_context)();
	typedef si32(__stdcall* pfn_ogl_set_context)(device_handle device, context_handle context);
	// device
	typedef device_handle(__stdcall* pfn_ogl_get_device)();
	// other
	typedef ptr(__stdcall* pfn_ogl_get_proc)(cstring name);
}
namespace NW
{
	// context
	extern pfn_ogl_new_context ogl_new_context;
	extern pfn_ogl_del_context ogl_del_context;
	extern pfn_ogl_get_context ogl_get_context;
	extern pfn_ogl_set_context ogl_set_context;
	// device
	extern pfn_ogl_get_device ogl_get_device;
	// other
	extern pfn_ogl_get_proc ogl_get_proc_address;
}
// context
#define wglCreateContext ogl_new_context
#define wglDeleteContext ogl_del_context
#define wglGetCurrentContext ogl_get_context
#define wglMakeContextCurrent ogl_set_context
// device
#define wglGetCurrentDC ogl_get_device
// other
#define wglGetProcAddress ogl_get_proc_address
#endif
#if (NW_GAPI & NW_GAPI_DX)
#endif
#endif	// NW_GAPI
#endif	// NW_WGL_LOADER_H