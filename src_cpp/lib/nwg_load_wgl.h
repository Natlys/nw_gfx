#ifndef NWG_WGL_LOADER_H
#define NWG_WGL_LOADER_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	extern bit ogl_load_wgl();
}
namespace NWG
{
	// context
	typedef gfx_context(__stdcall* pfn_ogl_new_context)(gfx_device device);
	typedef si32(__stdcall* pfn_ogl_del_context)(gfx_context context);
	typedef gfx_context(__stdcall* pfn_ogl_get_context)();
	typedef si32(__stdcall* pfn_ogl_set_context)(gfx_device device, gfx_context context);
	// device
	typedef gfx_device(__stdcall* pfn_ogl_get_device)();
	// other
	typedef ptr(__stdcall* pfn_ogl_get_proc)(cstring name);
}
namespace NWG
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
#if (NWG_GAPI & NWG_GAPI_DX)
#endif
#endif	// NWG_GAPI
#endif	// NWG_WGL_LOADER_H