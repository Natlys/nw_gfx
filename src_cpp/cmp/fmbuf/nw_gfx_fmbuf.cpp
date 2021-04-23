#include "nw_gfx_pch.hpp"
#include "nw_gfx_fmbuf.h"
#if (defined NW_GAPI)
#	include "../../lib/nw_gfx_lib_fmbuf.h"
#	include "../../lib/nw_gfx_lib_txr.h"
#	include "../txr/nw_gfx_txr.h"
#	include "../img/nw_gfx_img.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_fmbuf::gfx_fmbuf() :
		t_cmp(), a_gfx_cmp(), a_iop_cmp(),
		m_handle(NW_NULL),
		m_parts(parts_t())
	{
	}
	gfx_fmbuf::~gfx_fmbuf() { if (m_handle != NW_NULL) { glDeleteFramebuffers(1u, &m_handle); m_handle = NW_NULL; } }
	// --setters
	v1nil gfx_fmbuf::set_layt(layt_tc& layout) {
		m_layt = layout;
		NW_CHECK(m_layt.remake(), "failed remake!", return);
		NW_CHECK(m_parts.size() == m_layt.get_count(), "one layout for every single part!", return);
	}
	v1nil gfx_fmbuf::set_size_x(cv1u size_x) {
		m_size[0] = size_x;
	}
	v1nil gfx_fmbuf::set_size_y(cv1u size_y) {
		m_size[1] = size_y;
	}
	v1nil gfx_fmbuf::set_size_xy(cv1u size_x, cv1u size_y) {
		m_size[0] = size_x;
		m_size[1] = size_y;
	}
	v1nil gfx_fmbuf::set_size_xy(cv2u size_xy) {
		m_size[0] = size_xy[0];
		m_size[1] = size_xy[1];
	}
	v1nil gfx_fmbuf::add_part(part_t& ref) {
		m_parts.push_back(ref);
	}
	v1nil gfx_fmbuf::rmv_part(cv1u key) {
		NW_CHECK(has_part(key), "not found!", return); m_parts.erase(m_parts.begin() + key);
	}
	// --operators
	op_stream_t& gfx_fmbuf::operator<<(op_stream_t& stm) const { return stm; }
	ip_stream_t& gfx_fmbuf::operator>>(ip_stream_t& stm) { return stm; }
	// --==<core_methods>==--
	v1bit gfx_fmbuf::remake(layt_tc& layout, cv2u size_xy)
	{
		if (m_handle != NW_NULL) { glDeleteFramebuffers(1u, &m_handle); m_handle = NW_NULL; }
		set_layt(layout);
		set_size_xy(size_xy);
		NW_CHECK(has_size(), "no size!", return NW_FALSE);
		NW_CHECK(has_part(), "no parts!", return NW_FALSE);

		glGenFramebuffers(1u, &m_handle);
		glBindFramebuffer(GL_FRAMEBUFFER, get_handle());

		for (v1u itr = 0u; itr < m_parts.size(); itr++) {
			NW_CHECK(get_part(itr).get_ref<gfx_img>()->remake(layout[itr], size_xy), "failed remake!", return NW_FALSE);
		}

		NW_CHECK(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE, "failed remake!", return NW_FALSE);
		glBindFramebuffer(GL_FRAMEBUFFER, NW_NULL);

		return NW_TRUE;
	}
	v1nil gfx_fmbuf::clear()
	{
		for (auto& ipart : m_parts) { ipart->clear(); }
	}
	v1nil gfx_fmbuf::on_draw()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, get_handle());
		// for (auto& ipart : m_parts) { ipart->on_draw(); }
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	gfx_fmbuf::gfx_fmbuf(gfx_engine& graphics) :
		t_cmp(), a_gfx_cmp(graphics), a_iop_cmp(),
		m_handle(NW_NULL),
		m_size{ 1u, 1u },
		m_depth(depth_t()), m_stenc(stenc_t()), m_draws(draws_t())
	{
	}
	gfx_fmbuf::~gfx_fmbuf() { }
	// --setters
	v1nil gfx_fmbuf::add_draw(draw_t& ref) { m_draws.push_back(ref); }
	v1nil gfx_fmbuf::rmv_draw(v1u key) { m_draws.erase(m_draws.begin() + key % m_draws.size()); }
	// --operators
	// --==<core_methods>==--
	v1b gfx_fmbuf::remake(v2u size_xy)
	{
		return NW_TRUE;
	}
	v1nil gfx_fmbuf::read_pixels(ptr data_ptr, v1u draw_idx, const v4s& read_rect)
	{
	}
	v1nil gfx_fmbuf::draw_pixels(cptr data_ptr, v1u draw_idx, const v4s& draw_rect)
	{
	}
	v1nil gfx_fmbuf::clear() {
	}
	v1nil gfx_fmbuf::on_draw()
	{
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif // NW_GAPI