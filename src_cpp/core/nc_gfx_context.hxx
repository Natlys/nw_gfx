#ifndef NC_GFX_CONTEXT_H
#define NC_GFX_CONTEXT_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "../lib/nc_gfx_lib.hxx"
namespace NC
{
	/// graphics_context_type
	class gfx_context_t : public mem_user_t
	{
	public:
		using context_t = gfx_context_t;
		using context_tc = const context_t;
		using state_t = gfx_context_state_t;
		using state_tc = const state_t;
		using handle_t = context_handle;
		using handle_tc = const handle_t;
		using device_t = device_handle;
		using device_tc = const device_t;
		using window_t = window_handle;
		using window_tc = const window_t;
		using loader_t = gfx_library_t;
		using loader_tc = const loader_t;
#	if (NC_GAPI & NC_GAPI_D3D)
		using swap_chain = IDXGISwapChain*;
		using draw_target = ID3D11RenderTargetView*;
#	endif
	public:
		gfx_context_t();
		gfx_context_t(window_t window);
		~gfx_context_t();
		/* getters */
		inline handle_t& get_handle()        { return m_handle; }
		inline handle_tc& get_handle() const { return m_handle; }
		inline device_t& get_device()        { return m_device; }
		inline device_tc& get_device() const { return m_device; }
		inline window_t& get_window()        { return m_window; }
		inline window_tc& get_window() const { return m_window; }
		inline loader_t& get_loader()        { return m_loader; }
		inline loader_tc& get_loader() const { return m_loader; }
		context_t& get_state(state_t& state);
		// // --info
		inline cstr_t get_drawer_str() const { return &m_drawer[0]; }
		inline cstr_t get_vendor_str() const { return &m_vendor[0]; }
		inline cstr_t get_shd_lang() const { return &m_shd_lang[0]; }
		inline v1u_tc get_max_slot_atb() const { return m_max_slot_atb; }
		inline v1u_tc get_max_slot_txr() const { return m_max_slot_txr; }
		/* setters */
		context_t& set_window(window_t& window);
		context_t& set_state(state_t& state);
		/* vetters */
		inline v1bit_t has_handle() const { return m_handle != NC_NULL; }
		inline v1bit_t has_device() const { return m_device != NC_NULL; }
		inline v1bit_t has_window() const { return m_window != NC_NULL; }
		/* commands */
		v1bit_t remake();
		inline v1bit_t remake(window_t window) { set_window(window); return remake(); }
		v1bit_t update();
	public:
#	if (NC_GAPI & NC_GAPI_OGL)
		// --api_functions
		// /* getters */
		pfn_gfx_get_int get_int;
		pfn_gfx_get_str get_str;
		pfn_gfx_get_err get_err;
		// /* vetters */
		pfn_gfx_is_enabled is_enabled;
		pfn_gfx_is_shader is_shader;
		/* commands */
		pfn_gfx_draw_vtx draw_vtx;
		pfn_gfx_draw_idx draw_idx;
		pfn_gfx_clear_error clear_error;
		// /* setters */
		/* // */ --general
		pfn_gfx_set_enabled set_enabled;
		pfn_gfx_set_disabled set_disabled;
		/* // */ --rasterizer
		pfn_gfx_rastr_set_viewp set_viewp;
		pfn_gfx_rastr_set_sciss set_sciss;
		pfn_gfx_rastr_set_line_width set_line_width;
		pfn_gfx_rastr_set_point_size set_point_size;
		pfn_gfx_rastr_set_cull set_cull;
		pfn_gfx_rastr_set_fill set_fill;
		/* // */ --depth_stencil
		pfn_gfx_depth_set_mask set_depth_mask;
		pfn_gfx_depth_set_func set_depth_func;
		pfn_gfx_stenc_set_mask set_stenc_mask;
		pfn_gfx_stenc_set_func set_stenc_func;
		/* // */ --blend
		pfn_gfx_blend_set_equation set_blend_equation;
		pfn_gfx_blend_set_equation_separate set_blend_equation_separate;
		pfn_gfx_blend_set_function set_blend_function;
		pfn_gfx_blend_set_function_separate set_blend_function_separate;
		// --buffer
		// // --core
		pfn_gfx_buf_gen buf_new;
		pfn_gfx_buf_del buf_del;
		pfn_gfx_buf_bind buf_bind;
		pfn_gfx_buf_bind_rang buf_bind_rang;
		pfn_gfx_buf_bind_base buf_bind_base;
		pfn_gfx_buf_bind_vert buf_bind_vert;
		// /* setters */
		pfn_gfx_buf_set_data buf_set_data;
		pfn_gfx_buf_set_sub_data buf_set_sub_data;
		// --layout
		// // --core
		pfn_gfx_layt_gen layt_new;
		pfn_gfx_layt_del layt_del;
		pfn_gfx_layt_bind layt_bind;
		// /* setters */
		pfn_gfx_layt_set_atb layt_set_atb;
		pfn_gfx_layt_set_enabled layt_set_enabled;
		pfn_gfx_layt_set_disabled layt_set_disabled;
		// --shader
		// // --core
		pfn_gfx_shd_new shd_new;
		pfn_gfx_shd_del shd_del;
		pfn_gfx_shd_remake shd_remake;
		// /* getters */
		pfn_gfx_shd_get_v1s shd_get_v1s;
		pfn_gfx_shd_get_info_log shd_get_info_log;
		// /* setters */
		pfn_gfx_shd_set_source shd_set_source;
		// --material
		// // --core
		pfn_gfx_mtl_new mtl_new;
		pfn_gfx_mtl_del mtl_del;
		pfn_gfx_mtl_bind mtl_bind;
		pfn_gfx_mtl_remake mtl_remake;
		// /* getters */
		pfn_gfx_mtl_get_iv mtl_get_iv;
		pfn_gfx_mtl_get_info_log mtl_get_info_log;
		pfn_gfx_mtl_get_loc_atb mtl_get_loc_atb;
		pfn_gfx_mtl_get_loc_unf mtl_get_loc_unf;
		// /* setters */
		pfn_gfx_mtl_add_shd mtl_add_shader;
		pfn_gfx_mtl_rmv_shd mtl_rmv_shader;
		pfn_gfx_mtl_set_n1s mtl_set_n1s;
		pfn_gfx_mtl_set_n2s mtl_set_n2s;
		pfn_gfx_mtl_set_n3s mtl_set_n3s;
		pfn_gfx_mtl_set_n4s mtl_set_n4s;
		pfn_gfx_mtl_set_v1s mtl_set_v1s;
		pfn_gfx_mtl_set_v2s mtl_set_v2s;
		pfn_gfx_mtl_set_v3s mtl_set_v3s;
		pfn_gfx_mtl_set_v4s mtl_set_v4s;
		pfn_gfx_mtl_set_n1u mtl_set_n1u;
		pfn_gfx_mtl_set_n2u mtl_set_n2u;
		pfn_gfx_mtl_set_n3u mtl_set_n3u;
		pfn_gfx_mtl_set_n4u mtl_set_n4u;
		pfn_gfx_mtl_set_v1u mtl_set_v1u;
		pfn_gfx_mtl_set_v2u mtl_set_v2u;
		pfn_gfx_mtl_set_v3u mtl_set_v3u;
		pfn_gfx_mtl_set_v4u mtl_set_v4u;
		pfn_gfx_mtl_set_n1f mtl_set_n1f;
		pfn_gfx_mtl_set_n2f mtl_set_n2f;
		pfn_gfx_mtl_set_n3f mtl_set_n3f;
		pfn_gfx_mtl_set_n4f mtl_set_n4f;
		pfn_gfx_mtl_set_v1f mtl_set_v1f;
		pfn_gfx_mtl_set_v2f mtl_set_v2f;
		pfn_gfx_mtl_set_v3f mtl_set_v3f;
		pfn_gfx_mtl_set_v4f mtl_set_v4f;
		pfn_gfx_mtl_set_m2f mtl_set_m2f;
		pfn_gfx_mtl_set_m2f mtl_set_m3f;
		pfn_gfx_mtl_set_m4f mtl_set_m4f;
		pfn_gfx_mtl_set_bind mtl_set_bind;
		// --texture
		// // --core
		pfn_gfx_txr_new txr_new;
		pfn_gfx_txr_new_mipmap txr_new_mipmap;
		pfn_gfx_txr_del txr_del;
		pfn_gfx_txr_bind txr_bind;
		pfn_gfx_txr_active txr_active;
		pfn_gfx_txr_clear txr_clear;
		// /* setters */
		pfn_gfx_txr_set_image_1d txr_set_image_1d;
		pfn_gfx_txr_set_image_2d txr_set_image_2d;
		pfn_gfx_txr_set_image_3d txr_set_image_3d;
		pfn_gfx_txr_set_image_2d_mulsmp txr_set_image_2d_mulsmp;
		pfn_gfx_txr_set_image_3d_mulsmp txr_set_image_3d_mulsmp;
		pfn_gfx_txr_set_param_n1s txr_set_param_n1s;
		pfn_gfx_txr_set_param_v1s txr_set_param_v1s;
		pfn_gfx_txr_set_param_n1f txr_set_param_n1f;
		pfn_gfx_txr_set_param_v1f txr_set_param_v1f;
		// --sampler
		// // --core
		pfn_gfx_smp_gen smp_new;
		pfn_gfx_smp_del smp_del;
		pfn_gfx_smp_bind smp_bind;
		// /* setters */
		pfn_gfx_smp_set_param_n1s smp_set_param_n1s;
		pfn_gfx_smp_set_param_v1s smp_set_param_v1s;
		pfn_gfx_smp_set_param_n1f smp_set_param_n1f;
		pfn_gfx_smp_set_param_v1f smp_set_param_v1f;
		// --framebuffer
		// // --core
		pfn_gfx_fmbuf_new fmbuf_new;
		pfn_gfx_fmbuf_del fmbuf_del;
		pfn_gfx_fmbuf_bind fmbuf_bind;
		pfn_gfx_fmbuf_bind_draw fmbuf_set_draw;
		pfn_gfx_fmbuf_bind_read fmbuf_set_read;
		pfn_gfx_fmbuf_bind_draws fmbuf_set_draws;
		pfn_gfx_fmbuf_bind_reads fmbuf_set_reads;
		// /* getters */
		pfn_gfx_fmbuf_get_status fmbuf_get_status;
		// /* setters */
		pfn_gfx_fmbuf_set_txr_1d fmbuf_set_txr_1d;
		pfn_gfx_fmbuf_set_txr_2d fmbuf_set_txr_2d;
		pfn_gfx_fmbuf_set_txr_3d fmbuf_set_txr_3d;
		pfn_gfx_fmbuf_set_color fmbuf_set_color;
		/* commands */
		pfn_gfx_fmbuf_draw fmbuf_draw;
		pfn_gfx_fmbuf_read fmbuf_read;
		pfn_gfx_fmbuf_clear fmbuf_clear;
#	endif
	private:
		handle_t m_handle;
		device_t m_device;
		window_t m_window;
		loader_t m_loader;
		// --info
		dstr_t m_drawer;
		dstr_t m_vendor;
		dstr_t m_shd_lang;
		v1s_t m_max_slot_atb;
		v1s_t m_max_slot_txr;
		v1s_t m_pxl_range;
		v1s_t m_pxl_gran;
#		if (NC_GAPI & NC_GAPI_D3D)
		swap_chain m_swap_chain;
		draw_target m_draw_target;
#		endif
	};
}
#endif	// NC_GAPI
#endif	// NC_GFX_CONTEXT_H