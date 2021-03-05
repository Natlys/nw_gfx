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
		/// component reference
		using cmp_ref = mem_ref<a_gfx_cmp>;
		/// ent_id - ref association
		using cmps = dictionary<ui32, cmp_ref>;
		/// type_id - components association;
		using cmp_reg = dictionary<ui32, cmps>;
	public:
		gfx_engine(gfx_window& wnd);
		gfx_engine(const gfx_engine& copy) = delete;
		virtual ~gfx_engine();
		// --getters
		inline gfx_context_info& get_info()	{ return m_info; }
		inline gfx_config& get_configs()	{ return m_config; }
		inline gfx_device get_device()		{ return m_device; }
		inline gfx_context get_context()	{ return m_context; }
		inline cmp_reg& get_registry()						{ return m_reg; }
		inline cmps& get_cmps(ui32 type_id)					{ return m_reg[type_id]; }
		template<class gtype> cmps& get_cmps()				{ return m_reg[type_indexator::get_id<gtype>()]; }
		inline cmp_ref& get_cmp(ui32 type_id, ui32 cmp_id)	{ return m_reg[type_id][cmp_id]; }
		template<class gtype> cmp_ref& get_cmp(ui32 cmp_id)	{ return m_reg[type_indexator::get_id<gtype>()][cmp_id]; }
		// --setters
		void set_primitive(gfx_primitives primitive_topology);
		void set_viewport(si32 coord_x, si32 coord_y, si32 size_x, si32 size_y);
		void set_vsync(bit enable);
		// --predicates
		inline bit is_vsync() const { return m_config.swap_interval == 1; }
		// --core_methods
		void update();
		void begin_draw();
		void end_draw();
		void on_draw_vtx(ui32 ent_id);
		void on_draw_idx(ui32 ent_id);
		/// --create new graphical resource by the ref of appropriate type
		template<typename gtype, typename ... args>
		void new_cmp(args&& ... arguments);
		void rmv_cmp(ui32 type_id, ui32 cmp_id);
	private:
		gfx_context_info m_info;
		gfx_config m_config;
		gfx_window m_wnd;
		gfx_device m_device;
		gfx_context m_context;
		cmp_reg m_reg;
#if (NWG_GAPI & NWG_GAPI_DX)
		IDXGISwapChain* m_swap;
		ID3D11RenderTargetView* m_target;
#endif
	};
	template<typename gtype, typename ... args>
	void gfx_engine::new_cmp(args&& ... arguments) {
		cmp_ref temp_cmp;
		temp_cmp.make_ref<gtype>(*this, std::forward<args>(arguments)...);
		m_reg[gtype::get_type_id_static()][temp_cmp->get_cmp_id()].set_ref(temp_cmp);
	}
}
#endif	// NWG_GAPI
#endif	// NWG_ENGINE_H