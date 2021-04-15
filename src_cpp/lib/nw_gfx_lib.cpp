#include "nw_gfx_pch.hpp"
#include "nw_gfx_lib.h"
#if (defined NW_GAPI)
#include "nw_gfx_lib_buf.h"
#include "nw_gfx_lib_fmbuf.h"
#include "nw_gfx_lib_layt.h"
#include "nw_gfx_lib_smp.h"
#include "nw_gfx_lib_txr.h"
#include "nw_gfx_lib_shd.h"
#include "nw_gfx_lib_mtl.h"
#include "nw_gfx_lib_wapi.h"
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_lib_loader::gfx_lib_loader() :
		m_handle(NW_NULL),
		m_ver_num(0), m_ver_str("default"),
		m_drawer("default"),
		m_vendor("default"),
		m_shd_lang("default"),
		m_pxl_range(0),
		m_pxl_gran(0),
		m_max_slot_txr(0),
		m_max_slot_atb(0)
	{
	}
	gfx_lib_loader::~gfx_lib_loader()
	{
	}
	// --getters
	ptr_t gfx_lib_loader::get_proc(cstr name) {
		
		ptr_t resource = wglGetProcAddress(name);
		if (resource == NW_NULL) { resource = ::GetProcAddress(m_handle, name); }

		return resource;
	}
	// --==<core_methods>==--
	v1bit gfx_lib_loader::init()
	{
		if (m_handle == NW_NULL) { return NW_FALSE; }

		if (gfx_load_core() == NW_TRUE) {
			if (glGetIntegerv == NW_NULL) { return NW_FALSE; }

			v1s version_nums[2] = { 0, 0 };
			glGetIntegerv(GL_MAJOR_VERSION, &version_nums[0]);
			glGetIntegerv(GL_MINOR_VERSION, &version_nums[1]);
			m_ver_num = (version_nums[0] * 100) + (version_nums[1] * 10);

			m_ver_str = reinterpret_cast<cstr>(glGetString(GL_VERSION));
			//m_ext_str = reinterpret_cast<cstr>(glGetString(GL_EXTENSIONS));
			m_drawer = reinterpret_cast<cstr>(glGetString(GL_RENDERER));
			m_vendor = reinterpret_cast<cstr>(glGetString(GL_VENDOR));
			m_shd_lang = reinterpret_cast<cstr>(glGetString(GL_SHADING_LANGUAGE_VERSION));

			glGetIntegerv(GL_POINT_SIZE_RANGE, &m_pxl_range);
			glGetIntegerv(GL_POINT_SIZE_GRANULARITY, &m_pxl_gran);
			glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &m_max_slot_txr);
			glGetIntegerv(GL_MAX_VERTEX_ATTRIB_BINDINGS, &m_max_slot_atb);
		}
		else { return NW_FALSE; }
		if (gfx_load_buf() == NW_TRUE) {
		}
		else { return NW_FALSE; }
		if (gfx_load_fmbuf() == NW_TRUE) {
		}
		else { return NW_FALSE; }
		if (gfx_load_layt() == NW_TRUE) {
		}
		else { return NW_FALSE; }
		if (gfx_load_smp() == NW_TRUE) {
		}
		else { return NW_FALSE; }
		if (gfx_load_txr() == NW_TRUE) {
		}
		else { return NW_FALSE; }
		if (gfx_load_shd() == NW_TRUE) {
		}
		else { return NW_FALSE; }
		if (gfx_load_mtl() == NW_TRUE) {
		}
		else { return NW_FALSE; }
		// extensions
		if (gfx_ext_load_wapi() == NW_TRUE) {
		}
		else { return NW_FALSE; }

		return NW_TRUE;
	}
	v1bit gfx_lib_loader::quit()
	{
		if (m_handle != NW_NULL) { return NW_FALSE; }
		
		m_ver_str = "default";
		m_drawer = "default";
		m_vendor = "default";
		m_shd_lang = "default";

		m_ver_num = 0;
		m_max_slot_atb = 0;
		m_max_slot_txr = 0;

		return NW_TRUE;
	}
	v1bit gfx_lib_loader::load()
	{
		if (m_handle != NW_NULL) { return NW_FALSE; }

		m_handle = ::LoadLibrary("opengl32.dll");
		if (gfx_load_wapi() == NW_TRUE) {
		}
		else { return NW_FALSE; }

		return NW_TRUE;
	}
	v1bit gfx_lib_loader::free()
	{
		if (m_handle == NW_NULL) { return NW_FALSE; }

		::FreeLibrary(m_handle);
		m_handle = NW_NULL;

		return NW_TRUE;
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_D3D)
#include "dxgi.h"
#include "d3dcompiler.h"
namespace NW
{
	static inline library_handle libh_comp = NW_NULL;
	static inline library_handle libh_dxgi = NW_NULL;

	gfx_lib_loader::gfx_lib_loader() :
		m_handle(NW_NULL),
		m_ver_num(0), m_ver_str("default"),
		m_drawer("default"),
		m_vendor("default"),
		m_shd_lang("default"),
		m_pxl_range(0),
		m_pxl_gran(0),
		m_max_slot_txr(0),
		m_max_slot_atb(0)
	{
	}
	gfx_lib_loader::~gfx_lib_loader() { quit(); }
	// --getters
	ptr_t gfx_lib_loader::get_proc(cstr name) {
		ptr_t resource = NW_NULL;

		resource = ::GetProcAddress(m_handle, name);
		if (resource == NW_NULL) {
			resource = ::GetProcAddress(libh_dxgi, name);
		}
		if (resource == NW_NULL) {
			resource = ::GetProcAddress(libh_comp, name);
		}

		return resource;
	}
	// --==<core_methods>==--
	v1bit gfx_lib_loader::init() {
		if (m_handle == NW_NULL) { return NW_FALSE; }

		if (gfx_load_core() == NW_TRUE) {
		}
		else { return NW_FALSE; }
		if (gfx_load_buf() == NW_TRUE) {
		}
		else { return NW_FALSE; }
		if (gfx_load_fmbuf() == NW_TRUE) {
		}
		else { return NW_FALSE; }
		if (gfx_load_layt() == NW_TRUE) {
		}
		else { return NW_FALSE; }
		if (gfx_load_smp() == NW_TRUE) {
		}
		else { return NW_FALSE; }
		if (gfx_load_txr() == NW_TRUE) {
		}
		else { return NW_FALSE; }
		if (gfx_load_shd() == NW_TRUE) {
		}
		else { return NW_FALSE; }
		if (gfx_load_mtl() == NW_TRUE) {
		}
		else { return NW_FALSE; }
		// extensions
		if (gfx_ext_load_wapi() == NW_TRUE) {
		}
		else { return NW_FALSE; }

		return NW_TRUE;
	}
	v1bit gfx_lib_loader::quit()
	{
		if (m_handle != NW_NULL) { return NW_FALSE; }
		
		m_ver_str = "default";
		m_drawer = "default";
		m_vendor = "default";
		m_shd_lang = "default";

		m_ver_num = 0;
		m_max_slot_atb = 0;
		m_max_slot_txr = 0;

		return NW_TRUE;
	}
	v1bit gfx_lib_loader::load()
	{
		if (m_handle != NW_NULL) { return NW_FALSE; }
		m_handle = ::LoadLibrary("d3d11.dll");
		
		if (libh_dxgi != NW_NULL) { return NW_FALSE; }
		libh_dxgi = ::LoadLibrary("dxgi.dll");
		
		if (libh_comp != NW_NULL) { return NW_FALSE; }
		libh_comp = ::LoadLibrary(D3DCOMPILER_DLL);

		if (gfx_load_wapi() == NW_TRUE) {
		}
		else { return NW_FALSE; }
		
		return NW_TRUE;
	}
	v1bit gfx_lib_loader::free()
	{
		if (m_handle == NW_NULL) { return NW_FALSE; }
		::FreeLibrary(m_handle);
		m_handle = NW_NULL;

		if (libh_dxgi == NW_NULL) { return NW_FALSE; }
		::FreeLibrary(libh_dxgi);
		libh_dxgi = NW_NULL;

		if (libh_comp == NW_NULL) { return NW_FALSE; }
		::FreeLibrary(libh_comp);
		libh_comp = NW_NULL;

		return NW_TRUE;
	}
	// --==</core_methods>==--
}
#endif
#endif	// NW_GAPI