#ifndef NC_GFX_MATERIAL_H
#define NC_GFX_MATERIAL_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "../nc_gfx_cmp.hxx"
#	include "../bind/nc_gfx_bind.hxx"
namespace NC
{
	/// graphics_material_type
	class gfx_mtl_t : public nc_cmp_tt<gfx_mtl_t>, public gfx_cmp_t, public nc_iop_cmp_t
	{
	public:
		// --material
		using mtl_t = gfx_mtl_t;
		using mtl_tc = const mtl_t;
		// --binders
		using bind_t = nc_ref_t<gfx_bind_t>;
		using bind_tc = const bind_t;
		using binds_t = array_t<bind_t>;
		using binds_tc = const binds_t;
		using bind_list_t = init_list_t<bind_t>;
		using bind_list_tc = const bind_list_t;
		// --gfx_api
#	if (NC_GAPI & NC_GAPI_OGL)
		using handle_t = GLuint;
#	endif
#	if (NC_GAPI & NC_GAPI_D3D)
		using handle_t = ptr_t;
#	endif
		using handle_tc = const handle_t;
	public:
		gfx_mtl_t();
		gfx_mtl_t(binds_tc& binds);
		gfx_mtl_t(bind_list_tc& binds);
		gfx_mtl_t(mtl_tc& copy);
		gfx_mtl_t(mtl_t&& copy);
		virtual ~gfx_mtl_t();
		/* getters */
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		inline binds_t& get_binds()        { return m_binds; }
		inline binds_tc& get_binds() const { return m_binds; }
		inline size_tc get_bind_count() const { return m_binds.size(); }
		inline bind_t& get_bind(size_t key)        { NC_CHECK(has_bind(key), "key error!", return m_binds[0]); return m_binds[key]; }
		inline bind_tc& get_bind(size_t key) const { NC_CHECK(has_bind(key), "key error!", return m_binds[0]); return m_binds[key]; }
		/* setters */
		mtl_t& set_binds(binds_tc& binds);
		mtl_t& set_binds(bind_list_tc& binds);
		mtl_t& add_bind(bind_tc& ref);
		mtl_t& rmv_bind(size_tc key);
		/* vetters */
		inline v1bit_t has_binds() const { return !m_binds.empty(); }
		inline v1bit_t has_bind(size_t key) const { return get_bind_count() > key; }
		/* operators */
		inline mtl_t& operator=(mtl_tc& copy) { NC_CHECK(remake(copy.get_binds()), "remake error!", return *this); return *this; }
		inline mtl_t& operator=(mtl_t&& copy) { NC_CHECK(remake(copy.get_binds()), "remake error!", return *this); return *this; }
		virtual nc_ostream_t& operator<<(nc_ostream_t& stm) const override;
		virtual nc_istream_t& operator>>(nc_istream_t& stm) override;
		/* command */
		v1bit_t remake();
		inline v1bit_t remake(binds_tc& binds) { set_binds(binds); return remake(); }
		inline v1bit_t remake(bind_list_tc& binds) { set_binds(binds); return remake(); }
		virtual v1nil_t on_draw() override;
	private:
		handle_t m_handle;
		binds_t m_binds;
	};
}

#endif	// NC_GAPI
#endif	// NC_GFX_MATERIAL_H
