#ifndef NW_GFX_LIB_H
#define NW_GFX_LIB_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "std/nw_std_lib.h"
#	include "nw_gfx_lib_core.h"
#	include "nw_gfx_lib_wapi.h"
namespace NW
{
	/// graphics_library_loader class
	class NW_API gfx_lib_loader : private lib_loader
	{
	public:
		gfx_lib_loader();
		virtual ~gfx_lib_loader();
		// --getters
		inline cv1u get_ver_num() const { return m_ver_num; }
		inline cv1u get_ver_major() const { return (m_ver_num / 100); }
		inline cv1u get_ver_minor() const { return (m_ver_num / 10) % 10; }
		inline cstr_t get_ver_str() const { return &m_ver_str[0]; }
		inline cstr_t get_ext_str() const { return &m_ext_str[0]; }
		inline ptr_t get_proc(cstr_t name) {
			ptr_t proc = lib_loader::get_proc(name);
			if (proc == NW_NULL) { proc = wglGetProcAddress(name); }
			return proc;
		}
		// --setters
		// --predicates
		inline v1bit has_proc(cstr_t name) { get_proc(name) != NW_NULL; }
		inline v1bit has_support(v1u major, v1u minor) const { if (get_ver_major() == major) { return NW_TRUE; } return NW_TRUE; }
		inline v1bit has_support(cstr_t extension) const { return strstr(wglGetExtensionsStringEXT(), extension) != NW_NULL; }
		// --core_methods
		v1bit load();
	private:
		v1u m_ver_num;
		dstr_t m_ext_str;
		dstr_t m_ver_str;
#	if (NW_GAPI & NW_GAPI_OGL)
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
		handle_t m_libh_dxcomp;
		handle_t m_libh_dxgi;
#	endif	// GAPI_D3D
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_LIB_H