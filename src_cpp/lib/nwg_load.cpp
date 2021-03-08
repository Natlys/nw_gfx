#include <nwg_pch.hpp>
#include "nwg_load.h"
#include "nwg_load_buf.h"
#include "nwg_load_fbuf.h"
#include "nwg_load_txr.h"
#include "nwg_load_shd.h"
namespace NWG
{
	struct ogl_version
	{
		si32 major = 0;
		si32 minor = 0;
		// --predicates
		inline bit is_supported(si32 major_ver, si32 minor_ver) {
			if (major_ver < 3) { return false; }
			if (major == minor_ver) { return minor >= minor_ver; }
			return major >= major_ver;
		}
	};

	static gfx_lib s_ogl_lib = NULL;
	static ogl_version s_version{ 0 };
}
namespace NWG
{
	// --getters
	ptr ogl_get_proc(cstring name) {
		ptr resource = NULL;

		resource = wglGetProcAddress(name);
		if (resource == NULL) { resource = ::GetProcAddress(s_ogl_lib, name); }

		return resource;
	}
	gfx_lib ogl_get_lib() { return s_ogl_lib; }
	// --==<core_methods>==--
	bit ogl_init() {
		if (ogl_open() == FALSE) { return FALSE; }
		if (ogl_load() == FALSE) { return FALSE; }
		if (ogl_close() == FALSE) { return FALSE; }

		if (glGetIntegerv == NULL) { return FALSE; }
		glGetIntegerv(GL_MAJOR_VERSION, &s_version.major);
		glGetIntegerv(GL_MINOR_VERSION, &s_version.minor);
		if (s_version.major < 3) { return FALSE; }

		return TRUE;
	}
	bit ogl_open()
	{
		if (s_ogl_lib != NULL) { return FALSE; }
		s_ogl_lib = ::LoadLibraryA("opengl32.dll");
		return TRUE;
	}
	bit ogl_close()
	{
		if (s_ogl_lib == NULL) { return FALSE; }
		::FreeLibrary(s_ogl_lib); s_ogl_lib = NULL;
		return TRUE;
	}
	bit ogl_load()
	{
		if (ogl_load_wgl() == FALSE) { return FALSE; }
		if (ogl_load_base() == FALSE) { return FALSE; }
		if (ogl_load_buf() == FALSE) { return FALSE; }
		if (ogl_load_fbuf() == FALSE) { return FALSE; }
		if (ogl_load_txr() == FALSE) { return FALSE; }
		if (ogl_load_shd() == FALSE) { return FALSE; }

		return TRUE;
	}
	// --==</core_methods>==--
}