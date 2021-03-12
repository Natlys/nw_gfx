#ifndef NW_OGL_LOADER_H
#define NW_OGL_LOADER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#if (NW_GAPI & NW_GAPI_OGL)
#include "nwg_load_wgl.h"
namespace NW
{
	// --getters
	extern ptr ogl_get_proc(cstring name);
	extern library_handle ogl_get_lib();
	// --predicates
	// --==<core_methods>==--
	extern bit ogl_init();
	extern bit ogl_open();
	extern bit ogl_close();
	extern bit ogl_load();
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")
#include <d3dcompiler.h>
#pragma comment(lib, "d3dcompiler.lib")
#endif
#endif	// NW_GAPI
#endif	// NW_OGL_LOADER_H