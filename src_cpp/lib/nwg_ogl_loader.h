#ifndef NWG_OGL_LOADER_H
#define NWG_OGL_LOADER_H
#include <nwg_core.hpp>
namespace NWG
{
	struct OglVersion
	{
		int nMajor = 0;
		int nMinor = 0;
	};
}
namespace NWG
{
	// --getters
	extern void* OglGetProc(const char* strProc);
	// --predicates
	extern int OglIsSupported(int nMajor, int nMinor);
	// --==<core_methods>==--
	extern int OglInit();
	extern void OglOpen();
	extern void OglClose();
	extern void OglLoad();
	// --==</core_methods>==--
}

#ifndef NWG_OGL_WGL
#define NWG_OGL_WGL 1
namespace NWG
{
	typedef void* (__stdcall* GetProcAddressOgl)(const char* name);
	extern GetProcAddressOgl OglGetProcAddress;

	typedef gfx_context(__stdcall* CreateContextOgl)(gfx_device device);
	typedef gfx_context(__stdcall* GetCurrContextOgl)();
	typedef int(__stdcall* DeleteContextOgl)(gfx_context context);
	typedef int(__stdcall* MakeContextCurrOgl)(gfx_device device, gfx_context context);
	extern CreateContextOgl OglNewContext;
	extern DeleteContextOgl OglDelContext;
	extern GetCurrContextOgl OglGetCurrContext;
	extern MakeContextCurrOgl OglMakeContextCurr;

	typedef gfx_device(__stdcall* GetCurrDeviceOgl)();
	extern GetCurrDeviceOgl OglGetCurrDevice;
}
#endif	// NWG_OGL_WGL

#endif	// NWG_OGL_LOADER_H