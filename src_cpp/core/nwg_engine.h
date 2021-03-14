#ifndef NW_GRAPHICS_ENGINE_H
#define NW_GRAPHICS_ENGINE_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <lib/nwg_tools.h>
namespace NW
{
	/// graphics_engine class
	class NW_API gfx_engine : public a_mem_user
	{
	public:
		/// storable rscource reference
		using rsc_ref = mem_ref<a_gfx_rsc>;
		/// table for rsc_id - cmp_ref association
		using rsc_tab = dictionary<ui32, rsc_ref>;
		/// table for type_id - cmp_refs association;
		using rsc_reg = dictionary<ui32, rsc_tab>;
	public:
		gfx_engine(const window_handle& wnd);
		gfx_engine(const gfx_engine& copy) = delete;
		virtual ~gfx_engine();
		// --getters
		inline gfx_context_info& get_info()		{ return m_info; }
		inline gfx_config& get_configs()		{ return m_config; }
		inline device_handle* get_device()		{ return &m_device; }
		inline context_handle* get_context()	{ return &m_context; }
		inline rsc_reg& get_registry()						{ return m_reg; }
		inline rsc_tab& get_table(ui32 type_id)				{ return m_reg[type_id]; }
		template<class gtype> rsc_tab& get_table()			{ return get_table(type_indexator::get_id<gtype>()); }
		inline rsc_ref& get_rsc(ui32 type_id, ui32 rsc_id)	{ return m_reg[type_id][rsc_id]; }
		template<class gtype> rsc_ref& get_rsc(ui32 rsc_id)	{ return get_rsc(type_indexator::get_id<gtype>(), rsc_id); }
		inline bit has_rsc(ui32 type_id, ui32 rsc_id)		{ return m_reg[type_id].find(rsc_id) != m_reg[type_id].end(); }
		template<class gtype> bit has_rsc(ui32 rsc_id)		{ return has_rsc(type_indexator::get_id<gtype>(), rsc_id); }
		// --setters
		void set_primitive(gfx_primitives primitive_topology);
		void set_viewport(si32 coord_x, si32 coord_y, si32 size_x, si32 size_y);
		void set_vsync(bit enable);
		// --predicates
		inline bit is_vsync() const		{ return m_config.swap_interval == 1; }
		// --core_methods
		void update();
		/// --create new graphics rscource by the ref of appropriate type
		template<typename gtype, typename ... args> void new_rsc(mem_ref<gtype>& ref, args&& ... arguments);
		/// --create new graphics rscource by the ref of abstract type
		template<typename agtype, typename gtype, typename ... args> void new_rsc(mem_ref<agtype>& ref, args&& ... arguments);
		void del_rsc(ui32 type_id, ui32 rsc_id);
		template<typename gtype> void del_rsc(ui32 rsc_id)	{ del_rsc(type_indexator::get_id<gtype>(), rsc_id); }
	private:
		gfx_context_info m_info;
		gfx_config m_config;
		window_handle m_wnd;
		device_handle m_device;
		context_handle m_context;
		rsc_reg m_reg;
#if (NW_GAPI & NW_GAPI_DX)
		IDXGISwapChain* m_dx_swap;
		ID3D11RenderTargetView* m_dx_target;
#endif
	};
	template<typename gtype, typename ... args> void gfx_engine::new_rsc(mem_ref<gtype>& ref, args&& ... arguments) {
		ref.make_ref<gtype>(*this, std::forward<args>(arguments)...);
		m_reg[ref->get_type_id()][ref->get_rsc_id()].set_ref(ref);
	}
	template<typename agtype, typename gtype, typename ... args> void gfx_engine::new_rsc(mem_ref<agtype>& ref, args&& ... arguments) {
		mem_ref<gtype> temp_ref;
		temp_ref.make_ref<gtype>(*this, std::forward<args>(arguments)...);
		ref.set_ref<gtype>(temp_ref);
		m_reg[temp_ref->get_type_id()][temp_ref->get_rsc_id()].set_ref(temp_ref);
	}
}
#endif	// NW_GAPI
#endif	// NW_GRAPHICS_ENGINE_H