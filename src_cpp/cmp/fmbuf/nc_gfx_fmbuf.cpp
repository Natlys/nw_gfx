#include "nc_gfx_pch.hpp"
#include "nc_gfx_fmbuf.hxx"
#if (defined NC_GAPI)
#	include "../../core/nc_nc_gfx_eng.hxx"
#	include "../txr/nc_gfx_txr.hxx"
#	if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	gfx_fmbuf_t::gfx_fmbuf_t() :
		nc_cmp_tt(), gfx_cmp_t(), nc_iop_cmp_t(),
		m_handle(NC_NULL),
		m_size{ 1u, 1u }
	{
	}
	gfx_fmbuf_t::~gfx_fmbuf_t() { if (m_handle != NC_NULL) { get_context()->fmbuf_del(1u, &m_handle); m_handle = NC_NULL; } }
	/* setters */
	v1nil_t gfx_fmbuf_t::set_layt(layt_tc& layout) {
		m_layt = layout;
	}
	v1nil_t gfx_fmbuf_t::set_size_x(v1u_tc size_x) {
		m_size[0] = size_x;
	}
	v1nil_t gfx_fmbuf_t::set_size_y(v1u_tc size_y) {
		m_size[1] = size_y;
	}
	v1nil_t gfx_fmbuf_t::set_size_xy(v1u_tc size_x, v1u_tc size_y) {
		m_size[0] = size_x;
		m_size[1] = size_y;
	}
	v1nil_t gfx_fmbuf_t::set_size_xy(cv2u size_xy) {
		m_size[0] = size_xy[0];
		m_size[1] = size_xy[1];
	}
	v1nil_t gfx_fmbuf_t::add_part(part_t& ref) { m_parts.push_back(ref); }
	v1nil_t gfx_fmbuf_t::rmv_part(v1u_tc key) { m_parts.erase(m_parts.begin() + key % m_parts.size()); }
	/* operators */
	nc_ostream_t& gfx_fmbuf_t::operator<<(nc_ostream_t& stm) const { return stm; }
	nc_istream_t& gfx_fmbuf_t::operator>>(nc_istream_t& stm) { return stm; }
	/* command */
	v1bit_t gfx_fmbuf_t::remake()
	{
		if (m_handle != NC_NULL) { get_context()->fmbuf_del(1u, &m_handle); m_handle = NC_NULL; }
		NC_CHECK(has_size(), "no size!", return NC_FALSE);

		get_context()->fmbuf_new(1, &m_handle);
		get_context()->fmbuf_bind(GL_FRAMEBUFFER, get_handle());

		return NC_TRUTH;
	}
	v1nil_t gfx_fmbuf_t::clear()
	{
		for (auto& ipart : m_parts) { ipart->clear(); }
	}
	v1nil_t gfx_fmbuf_t::on_draw()
	{
		get_context()->fmbuf_bind(GL_FRAMEBUFFER, get_handle());
		// for (auto& ipart : m_parts) { ipart->on_draw(); }
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
namespace NC
{
	fmbuf::fmbuf(nc_gfx_eng& graphics) :
		nc_cmp_tt(), gfx_cmp_t(graphics), a_io_cmp(),
		m_handle(NC_NULL),
		m_size{ 1u, 1u },
		m_depth(depth_t()), m_stenc(stenc_t()), m_targets(targets_t())
	{
	}
	fmbuf::~fmbuf() { }
	/* setters */
	void fmbuf::add_target(target_t& ref) { m_targets.push_back(ref); }
	void fmbuf::rmv_target(v1u_t key) { m_targets.erase(m_targets.begin() + key % m_targets.size()); }
	/* operators */
	/* command */
	v1bit_t fmbuf::remake(v2u size_xy)
	{
		return NC_TRUTH;
	}
	void fmbuf::read_pixels(ptr data_ptr, v1u_t target_idx, const v4s& read_rect)
	{
	}
	void fmbuf::draw_pixels(cptr data_ptr, v1u_t target_idx, const v4s& draw_rect)
	{
	}
	void fmbuf::clear() {
	}
	void fmbuf::on_draw()
	{
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif // NC_GAPI