#ifndef NW_GFX_CONTEXT_H
#define NW_GFX_CONTEXT_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "../lib/nw_gfx_lib.h"
namespace NW
{
	/// graphics_context class
	class NW_API gfx_context : public a_mem_user
	{
	public:
		using handle_t = context_handle;
		using handle_tc = const handle_t;
		using device_t = device_handle;
		using device_tc = const device_t;
		using window_t = window_handle;
		using window_tc = const window_t;
		using loader_t = gfx_lib_loader;
		using loader_tc = const loader_t;
#	if (NW_GAPI & NW_GAPI_D3D)
		using swap_chain = IDXGISwapChain*;
		using draw_target = ID3D11RenderTargetView*;
#	endif
	public:
		gfx_context();
		gfx_context(window_t window);
		~gfx_context();
		// --getters
		inline handle_t& get_handle()        { return m_handle; }
		inline handle_tc& get_handle() const { return m_handle; }
		inline device_t& get_device()        { return m_device; }
		inline device_tc& get_device() const { return m_device; }
		inline window_t& get_window()        { return m_window; }
		inline window_tc& get_window() const { return m_window; }
		inline loader_t& get_loader()        { return m_loader; }
		inline loader_tc& get_loader() const { return m_loader; }
		// // --info
		inline cstr_t get_drawer_str() const { return &m_drawer[0]; }
		inline cstr_t get_vendor_str() const { return &m_vendor[0]; }
		inline cstr_t get_shd_lang() const { return &m_shd_lang[0]; }
		inline cv1u get_max_slot_atb() const { return m_max_slot_atb; }
		inline cv1u get_max_slot_txr() const { return m_max_slot_txr; }
		// --setters
		v1nil set_window(window_t& window);
		// --predicates
		inline v1bit has_handle() const { return m_handle != NW_NULL; }
		inline v1bit has_device() const { return m_device != NW_NULL; }
		inline v1bit has_window() const { return m_window != NW_NULL; }
		// --core_methods
		v1bit remake();
		inline v1bit remake(window_t window) { set_window(window); return remake(); }
		v1nil update();
	private:
		handle_t m_handle;
		device_t m_device;
		window_t m_window;
		loader_t m_loader;
		// info
		dstr_t m_drawer;
		dstr_t m_vendor;
		dstr_t m_shd_lang;
		v1s m_max_slot_atb;
		v1s m_max_slot_txr;
		v1s m_pxl_range;
		v1s m_pxl_gran;
#	if (NW_GAPI & NW_GAPI_D3D)
		swap_chain m_swap_chain;
		draw_target m_draw_target;
#	endif
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_CONTEXT_H