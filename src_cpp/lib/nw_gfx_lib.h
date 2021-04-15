#ifndef NW_GFX_LIB_H
#define NW_GFX_LIB_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
namespace NW
{
	/// graphics_library
	class NW_API gfx_lib_loader : public singleton_t<gfx_lib_loader>
	{
	public:
		using handle_t = library_handle;
		using handle_tc = const handle_t;
		friend class singleton_t<gfx_lib_loader>;
	private:
		gfx_lib_loader();
	public:
		~gfx_lib_loader();
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		ptr_t get_proc(cstr proc_name);
		// --getters
		inline cv1u get_ver_num() const   { return m_ver_num; }
		inline cv1u get_ver_major() const { return (m_ver_num / 100); }
		inline cv1u get_ver_minor() const { return (m_ver_num / 10) % 10; }
		inline cstr get_ver_str() const    { return &m_ver_str[0]; }
		inline cstr get_ext_str() const    { return &m_ext_str[0]; }
		inline cstr get_drawer_str() const { return &m_drawer[0]; }
		inline cstr get_vendor_str() const { return &m_vendor[0]; }
		inline cstr get_shd_lang() const   { return &m_shd_lang[0]; }
		inline cv1u get_max_slot_atb() const { return m_max_slot_atb; }
		inline cv1u get_max_slot_txr() const { return m_max_slot_txr; }
		// --predicates
		inline v1bit has_support(v1u major, v1u minor) const {
			if (get_ver_major() == major) { return NW_TRUE; } return NW_TRUE;
		}
		// --core_methods
		v1bit init();
		v1bit quit();
		v1bit load();
		v1bit free();
	private:
		handle_t m_handle;
		v1u m_ver_num;
		dstr m_ext_str;
		dstr m_ver_str;
		dstr m_drawer;
		dstr m_vendor;
		dstr m_shd_lang;
		v1s m_max_slot_atb;
		v1s m_max_slot_txr;
		v1s m_pxl_range;
		v1s m_pxl_gran;
	};
	inline gfx_lib_loader::handle_t gfx_get_lib() { return gfx_lib_loader::get().get_handle(); }
	inline ptr_t gfx_get_proc(cstr proc_name)     { return gfx_lib_loader::get().get_proc(proc_name); }
}
#endif	// NW_GAPI
#endif	// NW_GFX_LIB_H
