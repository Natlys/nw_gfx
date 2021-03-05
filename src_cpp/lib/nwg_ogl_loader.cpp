#include <nwg_pch.hpp>
#include "nwg_ogl_loader.h"
#include "nwg_ogl_v1.h"
#include "nwg_ogl_v2.h"
#include "nwg_ogl_v3.h"
#include "nwg_ogl_v4.h"
#include "nwg_ogl_arb.h"
namespace NWG
{
	static gfx_lib s_libOgl = NULL;
	static OglVersion s_version{ 0 };

	GetProcAddressOgl OglGetProcAddress = NULL;

	CreateContextOgl OglNewContext = NULL;
	DeleteContextOgl OglDelContext = NULL;
	GetCurrContextOgl OglGetCurrContext = NULL;
	MakeContextCurrOgl OglMakeContextCurr = NULL;

	GetCurrDeviceOgl OglGetCurrDevice = NULL;
}
namespace NWG
{
	// --getters
	void* OglGetProc(const char* strProc) {
		void* pResource = nullptr;
		pResource = OglGetProcAddress(strProc);
		if (pResource == nullptr) { pResource = GetProcAddress(s_libOgl, strProc); }
		return pResource;
	}
	// --predicates
	int OglIsSupported(int nMajor, int nMinor) {
		if (nMajor < 3) { return GL_FALSE; }
		if (s_version.nMajor == nMajor) { return s_version.nMinor >= nMinor; }
		return s_version.nMajor >= nMajor;
	}
	// --==<core_methods>==--
	void OglOpen()
	{
		if (s_libOgl != NULL) { return; }
		s_libOgl = LoadLibraryA("opengl32.dll");
		if (s_libOgl == NULL) { assert(false); return; }

		OglGetProcAddress = (GetProcAddressOgl)(GetProcAddress(s_libOgl, "wglGetProcAddress"));
		
		OglNewContext = (CreateContextOgl)(GetProcAddress(s_libOgl, "wglCreateContext"));
		OglDelContext = (DeleteContextOgl)(GetProcAddress(s_libOgl, "wglDeleteContext"));
		OglGetCurrContext = (GetCurrContextOgl)(GetProcAddress(s_libOgl, "wglGetCurrentContext"));
		OglMakeContextCurr = (MakeContextCurrOgl)(GetProcAddress(s_libOgl, "wglMakeCurrent"));
		
		OglGetCurrDevice = (GetCurrDeviceOgl)(GetProcAddress(s_libOgl, "wglGetCurrentDC"));
	}
	void OglClose()
	{
		if (s_libOgl == NULL) { return; }
		FreeLibrary(s_libOgl);
		s_libOgl = NULL;
	}

	int OglInit() {
		OglOpen();
		OglLoad();
		OglClose();

		if (OglGetIntegerv == NULL) { return GL_FALSE; }
		OglGetIntegerv(GL_MAJOR_VERSION, &s_version.nMajor);
		OglGetIntegerv(GL_MINOR_VERSION, &s_version.nMinor);
		if (s_version.nMajor < 3) { return GL_FALSE; }
		return GL_TRUE;
	}
	void OglLoad()
	{
		OglLoadV1();
		OglLoadV2();
		OglLoadV3();
		OglLoadV4();
		OglLoadArb();
	}
	// --==</core_methods>==--
}