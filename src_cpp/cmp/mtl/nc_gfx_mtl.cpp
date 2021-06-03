#include "nc_gfx_pch.hpp"
#include "nc_gfx_mtl.hxx"
#if (defined NC_GAPI)
#include "core/nc_nc_gfx_eng.hxx"
#	if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	gfx_mtl_t::gfx_mtl_t() : nc_cmp_tt(), gfx_cmp_t(), nc_iop_cmp_t(), m_handle(NC_NULL), m_binds(binds_t()) { }
	gfx_mtl_t::gfx_mtl_t(binds_tc& binds) : gfx_mtl_t() { NC_CHECK(remake(binds), "remake error!", return); }
	gfx_mtl_t::gfx_mtl_t(bind_list_tc& binds) : gfx_mtl_t() { NC_CHECK(remake(binds), "remake error!", return); }
	gfx_mtl_t::gfx_mtl_t(mtl_tc& copy) : gfx_mtl_t() { operator=(copy); }
	gfx_mtl_t::gfx_mtl_t(mtl_t&& copy) : gfx_mtl_t() { operator=(copy); }
	gfx_mtl_t::~gfx_mtl_t() { if (m_handle != NC_NULL) { get_context()->mtl_del(m_handle); m_handle = NC_NULL; } }
	/* setters */
	gfx_mtl_t::mtl_t& gfx_mtl_t::set_binds(binds_tc& binds) { m_binds.clear(); for (auto& ibind : binds) { add_bind(ibind); } return *this; }
	gfx_mtl_t::mtl_t& gfx_mtl_t::set_binds(bind_list_tc& binds) { m_binds.clear(); for (auto& ibind : binds) { add_bind(ibind); } return *this; }
	gfx_mtl_t::mtl_t& gfx_mtl_t::add_bind(bind_tc& ref) { m_binds.push_back(ref); return *this; }
	gfx_mtl_t::mtl_t& gfx_mtl_t::rmv_bind(size_tc key) { NC_CHECK(has_bind(key), "key error!", return *this); m_binds.erase(m_binds.begin() + key); return *this; }
	/* operators */
	nc_ostream_t& gfx_mtl_t::operator<<(nc_ostream_t& stm) const { return stm; }
	nc_istream_t& gfx_mtl_t::operator>>(nc_istream_t& stm) { return stm; }
	/* commands */
	v1nil_t gfx_mtl_t::on_draw()
	{
		get_context()->mtl_bind(get_handle());
		for (auto& ibind : m_binds) { ibind->on_draw(); }
	}
	v1bit_t gfx_mtl_t::remake()
	{
		if (m_handle != NC_NULL) { get_context()->mtl_del(m_handle); m_handle = NC_NULL; }
		NC_CHECK(has_binds(), "no binders!", return NC_FALSE);
		
		m_handle = get_context()->mtl_new();

		for (auto& ibind : m_binds) { get_context()->mtl_add_shader(get_handle(), ibind->get_shd()->get_handle()); }
		get_context()->mtl_remake(get_handle());
		NC_CHECK(gfx_check_shader(get_handle()), "remake error!", return NC_FALSE);

		return NC_TRUTH;
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
namespace NC
{
	gfx_mtl_t::gfx_mtl_t(nc_gfx_eng& graphics) :
		nc_cmp_tt(), gfx_cmp_t(graphics), a_io_cmp()
	{
	}
	gfx_mtl_t::~gfx_mtl_t() { }
	/* setters */
	void gfx_mtl_t::set_buf(v1u_t shd_idx, buf& ref, v1u_t gfx_buf_idx_t) {
		get_shd(shd_idx)->set_buf(ref, gfx_buf_idx_t);
	}
	void gfx_mtl_t::set_txr(v1u_t shd_idx, txr& ref, v1u_t txr_idx) {
		get_shd(shd_idx)->set_txr(ref, txr_idx);
	}
	void gfx_mtl_t::add_shd(shd& ref) {
		m_shds.push_back(ref);
	}
	void gfx_mtl_t::rmv_shd(v1u_t idx) {
		m_shds.erase(m_shds.begin() + idx % m_shds.size());
	}
	/* operators */
	stm_out& gfx_mtl_t::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& gfx_mtl_t::operator>>(stm_in& stm) {
		return stm;
	}
	/* commands */
	v1bit_t gfx_mtl_t::remake()
	{
		//
		return NC_TRUTH;
	}
	void gfx_mtl_t::on_draw() {
		for (auto& ishd : m_shds) {
			ishd->on_draw();
		}
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NC_GAPI