#ifndef NWG_ENGINE_H
#define NWG_ENGINE_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include "nwg_ent.h"
#include "nwg_cmp.h"
#include "../lib/nwg_switch.h"
namespace NW
{
	struct NW_API gfx_engine_info
	{
	public:
		// --core_methods
		void update();
	public:
		sbyte drawer[256];
		sbyte version[256];
		sbyte vendor[256];
		sbyte shd_lang[256];
		ui8 max_vtx_atbs;
		ui8 max_txr_slots;
		ui8 pxl_range;
		ui8 pxl_gran;
	};
}
namespace NW
{
	/// graphics_engine class
	class NW_API gfx_engine : public t_ent_sys<a_gfx_ent>, public t_cmp_sys<a_gfx_cmp>, public a_mem_user
	{
	public:
		using dvch = device_handle;
		using ctxh = context_handle;
		using wndh = window_handle;
		using info = gfx_engine_info;
		using cinfo = const gfx_engine_info;
		using prim_type = gfx_primitives;
#if (NW_GAPI & NW_GAPI_DX)
		using swap_chain = IDXGISwapChain*;
		using draw_target = ID3D11RenderTargetView*;
#endif
	public:
		gfx_engine(wndh window);
		gfx_engine(const gfx_engine& copy) = delete;
		virtual ~gfx_engine();
		// --getters
		inline wndh get_wndh()			{ return m_wndh; }
		inline wndh get_wndh() const	{ return m_wndh; }
		inline dvch get_dvch()			{ return m_dvch; }
		inline dvch get_dvch() const	{ return m_dvch; }
		inline ctxh get_ctxh()			{ return m_ctxh; }
		inline ctxh get_ctxh() const	{ return m_ctxh; }
		inline cinfo& get_info() const	{ return m_info; }
		inline const v4f& get_viewport() const		{ return m_viewport; }
		inline const v4f& get_clear_color() const	{ return m_clear_color; }
		inline prim_type get_prim_type() const		{ return m_prim_type; }
		inline ui8 get_swap_delay() const			{ return m_swap_delay; }
		// --setters
		void set_fbuf_size(si32 size_x, si32 size_y);
		void set_viewport(v4f viewport);
		void set_viewport(f32 crd_x, f32 crd_y, f32 size_x, f32 size_y);
		void set_clear_color(v4f clear_color);
		void set_clear_color(f32 red, f32 green, f32 blue, f32 alpha = 1.0f);
		void set_primitive(prim_type primitive_topology);
		void set_swap_delay(ui8 swap_delay);
		// --predicates
		// --core_methods
		void update();
		// --entity_methods
		template<class et, typename ... args>
		ent<et> new_ent(args&& ... arguments) {
			static_assert(NW_CHECK_TYPE_BASE(a_gfx_ent, et), "entity type must be relative to the a_gfx_ent");
			ent<et> ref;
			ref.make_ref<et>(*this, std::forward<args>(arguments)...);
			m_ent_reg[ref->get_type()][ref->get_id()].set_ref(ref);
			return ref;
		}
		template<class aet, class et, typename ... args>
		ent<aet> new_ent(args&& ... arguments) {
			static_assert(NW_CHECK_TYPE_BASE(a_gfx_ent, et), "entity type must be relative to the a_gfx_ent");
			static_assert(NW_CHECK_TYPE_BASE(a_gfx_ent, aet), "abstract entity type must be relative to the a_gfx_ent");
			ent<aet> ref;
			ref.make_ref<et>(*this, std::forward<args>(arguments)...);
			m_ent_reg[ref->get_type()][ref->get_id()].set_ref(ref);
			return ref;
		}
		void del_ent(ui32 t_id, ui32 e_id) {
			if (!has_ent(t_id, e_id)) { return; }
			m_ent_reg[t_id].erase(e_id);
		}
		template<class et>
		void del_ent(ui32 e_id) {
			if (!has_ent<et>(e_id)) { return; }
			m_ent_reg[et::get_type_static()].erase(e_id);
		}
		// --component_methods
		/// create particular type and get particular ref
		template<class ct, typename ... args>
		cmp<ct> new_cmp(args& ... arguments) {
			static_assert(NW_CHECK_TYPE_BASE(a_gfx_cmp, ct), "component type must be relative to the a_gfx_ent");
			cmp<ct> ref;
			ref.make_ref<ct>(*this, std::forward<args&>(arguments)...);
			m_cmp_reg[ref->get_type()][ref->get_id()].set_ref(ref);
			return ref;
		}
		/// create particular type but get the abstract ref
		template<class act, class ct, typename ... args>
		cmp<act> new_cmp(args& ... arguments) {
			static_assert(NW_CHECK_TYPE_BASE(a_gfx_cmp, ct), "component type must be relative to the a_gfx_ent");
			static_assert(NW_CHECK_TYPE_BASE(a_gfx_cmp, act), "abstract component type must be relative to the a_gfx_ent");
			cmp<act> ref;
			ref.make_ref<ct>(*this, std::forward<args&>(arguments)...);
			m_cmp_reg[ref->get_type()][ref->get_id()].set_ref(ref);
			return ref;
		}
		void del_cmp(ui32 t_id, ui32 c_id) {
			if (!has_cmp(t_id, c_id)) { return; }
			m_cmp_reg[t_id].erase(c_id);
		}
		template<class ct>
		void del_cmp(ui32 c_id) {
			if (!has_cmp<ct>(c_id)) { return; }
			m_cmp_reg[ct::get_type_static()].erase(c_id);
		}
	private:
		wndh m_wndh;
		dvch m_dvch;
		ctxh m_ctxh;
		info m_info;
		v4f m_clear_color;
		v4f m_viewport;
		prim_type m_prim_type;
		ui8 m_swap_delay;
#if (NW_GAPI & NW_GAPI_DX)
		swap_chain m_swap_chain;
		draw_target m_draw_target;
#endif
	};
#if true
#else
	class NW_API gfx_engine : public t_ent_sys<a_gfx_ent>, public t_cmp_sys<a_gfx_cmp>
	{
	public:
		using dvch = device_handle;
		using ctxh = context_handle;
		using wndh = window_handle;
		using info = gfx_engine_info;
		using cinfo = const gfx_engine_info;
		using prim_type = gfx_primitives;
#if (NW_GAPI & NW_GAPI_DX)
		using swap_chain = IDXGISwapChain*;
		using draw_target = ID3D11RenderTargetView*;
#endif
		using ref = mem_ref<a_gfx_rsc>;
		using tab = dictionary<ui32, ref>;
		using reg = dictionary<ui32, tab>;
		template<class rt>
		using rsc = mem_ref<rt>;
	public:
		gfx_engine(wndh window);
		gfx_engine(const gfx_engine& copy) = delete;
		virtual ~gfx_engine();
		// --getters
		inline wndh get_wndh() const	{ return m_wndh; }
		inline dvch get_dvch() const	{ return m_dvch; }
		inline ctxh get_ctxh() const	{ return m_ctxh; }
		inline cinfo& get_info() const	{ return m_info; }
		inline const v4f& get_viewport() const		{ return m_viewport; }
		inline const v4f& get_clear_color() const	{ return m_clear_color; }
		inline prim_type get_prim_type() const		{ return m_prim_type; }
		inline ui8 get_swap_delay() const			{ return m_swap_delay; }
		inline reg& get_reg()							{ return m_reg; }
		inline tab& get_tab(ui32 type_id)				{ return m_reg[type_id]; }
		template<class rt> tab& get_tab()				{ return get_tab(rt::get_type_static()); }
		inline ref& get_ref(ui32 type_id, ui32 rsc_id)	{ return m_reg[type_id][rsc_id]; }
		template<class rt> ref& get_ref(ui32 rsc_id)	{ return get_ref(rt::get_type_static(), rsc_id); }
		template<class rt> rsc<rt> get_rsc(ui32 rsc_id)	{ return cmp<ct>(get_ref<rt>(rsc_id)); }
		// --setters
		void set_fbuf_size(si32 size_x, si32 size_y);
		void set_viewport(v4f viewport);
		void set_viewport(f32 crd_x, f32 crd_y, f32 size_x, f32 size_y);
		void set_clear_color(v4f clear_color);
		void set_clear_color(f32 red, f32 green, f32 blue, f32 alpha = 1.0f);
		void set_primitive(prim_type primitive_topology);
		void set_swap_delay(ui8 swap_delay);
		// --predicates
		inline bit has_rsc(ui32 type_id, ui32 rsc_id)	{ return m_reg[type_id].find(rsc_id) != m_reg[type_id].end(); }
		template<class ct> bit has_rsc(ui32 rsc_id)		{ return has_cmp(ct::get_type_static(), rsc_id); }
		// --core_methods
		void update();
		template<class rt, typename ... args>
		rsc<rt> new_rsc(args& ... arguments);
		template<class art, class rt, typename ... args>
		rsc<art> new_rsc(args& ... arguments);
		void del_rsc(ui32 type_id, ui32 rsc_id);
		template<class ct> void del_rsc(ui32 rsc_id)	{ del_rsc(ct::get_type_static(), rsc_id); }
	private:
		wndh m_wndh;
		dvch m_dvch;
		ctxh m_ctxh;
		info m_info;
		v4f m_clear_color;
		v4f m_viewport;
		prim_type m_prim_type;
		ui8 m_swap_delay;
		reg m_reg;
#if (NW_GAPI & NW_GAPI_DX)
		swap_chain m_swap_chain;
		draw_target m_draw_target;
#endif
	};
	template<class rt, typename ... args>
	gfx_engine::rsc<rt> gfx_engine::new_rsc(args& ... arguments) {
		rsc<rt> ref;
		ref.make_ref<rt>(*this, std::forward<args&>(arguments)...);
		m_reg[ref->get_type()][ref->get_id()].set_ref(ref);
		return ref;
	}
	template<class art, class rt, typename ... args>
	gfx_engine::rsc<art> gfx_engine::new_rsc(args& ... arguments) {
		cmp<art> ref;
		ref.make_ref<ct>(*this, std::forward<args&>(arguments)...);
		m_reg[ref->get_type()][ref->get_id()].set_ref<act>(ref);
		return ref;
	}
#endif
}
#endif	// NW_GAPI
#endif	// NWG_ENGINE_H