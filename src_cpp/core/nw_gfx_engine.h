#ifndef NW_GFX_ENGINE_H
#define NW_GFX_ENGINE_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "../ent/nw_gfx_ent.h"
#	include "../cmp/nw_gfx_cmp.h"
#	include "nw_gfx_cmd.h"
namespace NW
{
	/// graphics_engine class
	class NW_API gfx_engine : public t_ent_sys<a_gfx_ent>, public t_cmp_sys<a_gfx_cmp>, public a_mem_cmp
	{
	public:
		using dvch = device_handle;
		using ctxh = context_handle;
		using wndh = window_handle;
		using cmd_buf_t = gfx_cmd_buf;
		using cmd_buf_tc = const cmd_buf_t;
		using cmd_t = cmd_buf_t::cmd_t;
		using cmd_tc = cmd_buf_t::cmd_tc;
		using vcmd_t = cmd_buf_t::vcmd_t;
		using vcmd_tc = cmd_buf_t::vcmd_tc;
		using icmd_t = cmd_buf_t::icmd_t;
		using icmd_tc = cmd_buf_t::icmd_tc;
#	if (NW_GAPI & NW_GAPI_OGL)
		using prim = GLenum;
#	endif
#if (NW_GAPI & NW_GAPI_D3D)
		using prim = D3D11_PRIMITIVE_TOPOLOGY;
		using swap_chain = IDXGISwapChain*;
		using draw_target = ID3D11RenderTargetView*;
#endif
	public:
		gfx_engine(wndh window);
		gfx_engine(const gfx_engine& copy) = delete;
		virtual ~gfx_engine();
		// --getters
		inline wndh get_wndh()       { return m_wndh; }
		inline wndh get_wndh() const { return m_wndh; }
		inline dvch get_dvch()       { return m_dvch; }
		inline dvch get_dvch() const { return m_dvch; }
		inline ctxh get_ctxh()       { return m_ctxh; }
		inline ctxh get_ctxh() const { return m_ctxh; }
		inline cmd_buf_t& get_cmd_buf()        { return m_cmd_buf; }
		inline cmd_buf_tc& get_cmd_buf() const { return m_cmd_buf; }
		inline cv4f& get_viewport() const  { return m_viewport; }
		inline cv4f& get_clear_clr() const { return m_clear_color; }
		inline v1u get_swap_delay() const  { return m_swap_delay; }
		// --setters
		v1nil set_fbuf_size(v1u size_x, v1u size_y);
		v1nil set_viewport(v4f viewport);
		v1nil set_viewport(v1f crd_x, v1f crd_y, v1f size_x, v1f size_y);
		v1nil set_clear_color(v4f clear_color);
		v1nil set_clear_color(v1f red, v1f green, v1f blue, v1f alpha = 1.0f);
		v1nil set_swap_delay(v1u swap_delay);
		// --predicates
		// --core_methods
		v1nil update();
		// --entity_methods
		template<class tname, typename ... args>
		ent_t<tname> new_ent(args&& ... arguments) {
			NW_CHECK_TYPE_BASE(tname, a_gfx_ent, "tname must inherit a_gfx_ent");
			ent_t<tname> ref;
			ref.make_ref<tname>(*this, std::forward<args>(arguments)...);
			get_ent_reg()[ref->get_type()][ref->get_idx()].set_ref(ref);
			return ref;
		}
		template<class tbase, class tname, typename ... args>
		ent_t<tbase> new_ent(args&& ... arguments) {
			NW_CHECK_TYPE_BASE(tname, a_gfx_ent, "tname must inherit a_gfx_ent");
			NW_CHECK_TYPE_BASE(tbase, a_gfx_ent, "tbase must inherit a_gfx_ent");
			ent_t<tbase> ref;
			ref.make_ref<tname>(*this, std::forward<args>(arguments)...);
			get_ent_reg()[ref->get_type()][ref->get_idx()].set_ref(ref);
			return ref;
		}
		v1nil del_ent(v1u t_id, v1u e_id)             { NW_CHECK(has_ent_ref(t_id, e_id), "nof found!", return); get_ent_tab(t_id).erase(e_id); }
		template<class tname> v1nil del_ent(v1u e_id) { NW_CHECK_TYPE_BASE(tname, a_gfx_ent, "type error!"); del_ent(tname::get_type_static()); }
		// --component_methods
		/// create particular type and get particular ref
		template<class tname, typename ... args>
		cmp_t<tname> new_cmp(args&& ... arguments) {
			NW_CHECK_TYPE_BASE(tname, a_gfx_cmp, "tname must inherit a_gfx_cmp");
			cmp_t<tname> ref;
			ref.make_ref<tname>(*this, std::forward<args&>(arguments)...);
			get_cmp_reg()[ref->get_type()][ref->get_idx()].set_ref(ref);
			return ref;
		}
		/// create particular type but get the abstract ref
		template<class tbase, class tname, typename ... args>
		cmp_t<tbase> new_cmp(args&& ... arguments) {
			NW_CHECK_TYPE_BASE(tname, a_gfx_cmp, "tname must inherit a_gfx_cmp");
			cmp_t<tbase> ref;
			ref.make_ref<tname>(*this, std::forward<args&>(arguments)...);
			get_cmp_reg()[ref->get_type()][ref->get_idx()].set_ref(ref);
			return ref;
		}
		v1nil del_cmp(v1u t_id, v1u c_id)             { NW_CHECK(has_cmp_ref(t_id, c_id), "nof found!", return); get_cmp_tab(t_id).erase(c_id); }
		template<class tname> v1nil del_cmp(v1u c_id) { NW_CHECK_TYPE_BASE(tname, a_gfx_cmp, "type error!"); del_cmp(tname::get_type_static(), c_id); }
	private:
		wndh m_wndh;
		dvch m_dvch;
		ctxh m_ctxh;
		cmd_buf_t m_cmd_buf;
		v4f m_clear_color;
		v4f m_viewport;
		v1u m_swap_delay;
#if (NW_GAPI & NW_GAPI_D3D)
		swap_chain m_swap_chain;
		draw_target m_draw_target;
#endif
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_ENGINE_H
