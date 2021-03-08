#ifndef NWG_ENGINE_H
#define NWG_ENGINE_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <core/nwg_tools.h>
namespace NWG
{
	/// graphics_engine class
	class NWG_API gfx_engine : public a_mem_user
	{
	public:
		/// storable resource reference
		using res_ref = mem_ref<a_gfx_res>;
		/// table for res_id - cmp_ref association
		using res_tab = dictionary<ui32, res_ref>;
		/// table for type_id - cmp_refs association;
		using res_reg = dictionary<ui32, res_tab>;
	public:
		gfx_engine(gfx_window& wnd);
		gfx_engine(const gfx_engine& copy) = delete;
		virtual ~gfx_engine();
		// --getters
		inline gfx_context_info& get_info()	{ return m_info; }
		inline gfx_config& get_configs()	{ return m_config; }
		inline gfx_device* get_device()		{ return &m_device; }
		inline gfx_context* get_context()	{ return &m_context; }
		inline res_reg& get_registry()						{ return m_reg; }
		inline res_tab& get_table(ui32 type_id)				{ return m_reg[type_id]; }
		template<class gtype> res_tab& get_table()			{ return get_table(type_indexator::get_id<gtype>()); }
		inline res_ref& get_res(ui32 type_id, ui32 res_id)	{ return m_reg[type_id][res_id]; }
		template<class gtype> res_ref& get_res(ui32 res_id)	{ return get_res(type_indexator::get_id<gtype>(), res_id); }
		// --setters
		void set_primitive(gfx_primitives primitive_topology);
		void set_viewport(si32 coord_x, si32 coord_y, si32 size_x, si32 size_y);
		void set_vsync(bit enable);
		// --predicates
		inline bit is_vsync() const { return m_config.swap_interval == 1; }
		inline bit has_res(ui32 type_id, ui32 res_id)		{ return m_reg[type_id].find(res_id) != m_reg[type_id].end(); }
		template<class gtype> bit has_res(ui32 res_id)		{ return has_res(type_indexator::get_id<gtype>(), res_id); }
		// --core_methods
		void update();
		/// --create new graphics resource by the ref of appropriate type
		template<typename gtype, typename ... args> void new_res(mem_ref<gtype>& ref, args&& ... arguments);
		/// --create new graphics resource by the ref of abstract type
		template<typename agtype, typename gtype, typename ... args> void new_res(mem_ref<agtype>& ref, args&& ... arguments);
		void del_res(ui32 type_id, ui32 res_id);
		template<typename gtype> void del_res(ui32 res_id)	{ del_res(type_indexator::get_id<gtype>(), res_id); }
	private:
		gfx_context_info m_info;
		gfx_config m_config;
		gfx_window m_wnd;
		gfx_device m_device;
		gfx_context m_context;
		res_reg m_reg;
#if (NWG_GAPI & NWG_GAPI_DX)
		IDXGISwapChain* m_swap;
		ID3D11RenderTargetView* m_target;
#endif
	};
	template<typename gtype, typename ... args> void gfx_engine::new_res(mem_ref<gtype>& ref, args&& ... arguments) {
		ref.make_ref<gtype>(*this, std::forward<args>(arguments)...);
		m_reg[ref->get_type_id()][ref->get_res_id()].set_ref(ref);
	}
	template<typename agtype, typename gtype, typename ... args> void gfx_engine::new_res(mem_ref<agtype>& ref, args&& ... arguments) {
		mem_ref<gtype> temp_ref;
		temp_ref.make_ref<gtype>(*this, std::forward<args>(arguments)...);
		ref.set_ref<gtype>(temp_ref);
		m_reg[temp_ref->get_type_id()][temp_ref->get_res_id()].set_ref(temp_ref);
	}
}
#endif	// NWG_GAPI
#endif	// NWG_ENGINE_H