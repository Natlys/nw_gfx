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
		virtual ~gfx_context();
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
#	if (NW_GAPI & NW_GAPI_OGL)
		// --api_functions
		// // --getters
		pfn_gfx_get_int_v get_int;
		pfn_gfx_get_string get_str;
		pfn_gfx_get_error get_error;
		// // --predicates
		pfn_gfx_is_enabled is_enabled;
		// // --commands
		pfn_gfx_draw_vtx draw_vtx;
		pfn_gfx_draw_idx draw_idx;
		pfn_gfx_clear_error clear_error;
		// // --setters
		// // // --general
		pfn_gfx_enable set_enabled;
		pfn_gfx_disable set_disabled;
		// // // --rasterizer
		pfn_gfx_viewport set_viewport;
		pfn_gfx_scissor set_scissor;
		pfn_gfx_line_width set_line_width;
		pfn_gfx_point_size set_point_size;
		pfn_gfx_polygon_mode set_polygon_mode;
		// // // --depth
		pfn_gfx_depth_mask set_depth_mask;
		pfn_gfx_depth_func set_depth_func;
		// // // --blend
		pfn_gfx_blend_equation set_blend_equation;
		pfn_gfx_blend_equation_separate set_blend_equation_separate;
		pfn_gfx_blend_function set_blend_function;
		pfn_gfx_blend_function_separate set_blend_function_separate;
#	endif
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