#ifndef NW_GFX_MATERIAL_H
#define NW_GFX_MATERIAL_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "../nw_gfx_cmp.h"
#	include "../bind/nw_gfx_bind.h"
namespace NW
{
	/// material class
	class NW_API gfx_mtl : public t_cmp<gfx_mtl>, public a_gfx_cmp, public a_iop_cmp
	{
	public:
		// --material
		using mtl_t = gfx_mtl;
		using mtl_tc = const mtl_t;
		// --binders
		using bind_t = mem_ref<gfx_bind>;
		using bind_tc = const bind_t;
		using binds_t = darray_t<bind_t>;
		using binds_tc = const binds_t;
		using bind_list_t = init_list_t<bind_t>;
		using bind_list_tc = const bind_list_t;
		// --gfx_api
#	if (NW_GAPI & NW_GAPI_OGL)
		using handle_t = GLuint;
#	endif
#	if (NW_GAPI & NW_GAPI_D3D)
		using handle_t = ptr_t;
#	endif
		using handle_tc = const handle_t;
	public:
		gfx_mtl();
		gfx_mtl(binds_tc& binds);
		gfx_mtl(bind_list_tc& binds);
		gfx_mtl(mtl_tc& copy);
		gfx_mtl(mtl_t&& copy);
		virtual ~gfx_mtl();
		// --getters
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		inline binds_t& get_binds()        { return m_binds; }
		inline binds_tc& get_binds() const { return m_binds; }
		inline size_tc get_bind_count() const { return m_binds.size(); }
		inline bind_t& get_bind(size_t key)        { NW_CHECK(has_bind(key), "key error!", return m_binds[0]); return m_binds[key]; }
		inline bind_tc& get_bind(size_t key) const { NW_CHECK(has_bind(key), "key error!", return m_binds[0]); return m_binds[key]; }
		// --setters
		mtl_t& set_binds(binds_tc& binds);
		mtl_t& set_binds(bind_list_tc& binds);
		mtl_t& add_bind(bind_tc& ref);
		mtl_t& rmv_bind(size_tc key);
		// --predicates
		inline v1bit has_binds() const { return !m_binds.empty(); }
		inline v1bit has_bind(size_t key) const { return get_bind_count() > key; }
		// --operators
		inline mtl_t& operator=(mtl_tc& copy) { NW_CHECK(remake(copy.get_binds()), "remake error!", return *this); return *this; }
		inline mtl_t& operator=(mtl_t&& copy) { NW_CHECK(remake(copy.get_binds()), "remake error!", return *this); return *this; }
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// --core_methods
		v1bit remake();
		inline v1bit remake(binds_tc& binds) { set_binds(binds); return remake(); }
		inline v1bit remake(bind_list_tc& binds) { set_binds(binds); return remake(); }
		virtual v1nil on_draw() override;
	private:
		handle_t m_handle;
		binds_t m_binds;
	};
}

#endif	// NW_GAPI
#endif	// NW_GFX_MATERIAL_H
