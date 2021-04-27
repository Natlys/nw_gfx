#include "nw_gfx_pch.hpp"
#include "nw_gfx_fmbuf.h"
#if (defined NW_GAPI)
#	include "../txr/nw_gfx_txr.h"
#	include "lib/nw_gfx_lib_fmbuf.h"
#	include "lib/nw_gfx_lib_txr.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_fmbuf::gfx_fmbuf() :
		t_cmp(), a_gfx_cmp(), a_iop_cmp(),
		m_handle(NW_NULL),
		m_size{ 1u, 1u }
	{
	}
	gfx_fmbuf::~gfx_fmbuf() { if (m_handle != NW_NULL) { glDeleteFramebuffers(1u, &m_handle); m_handle = NW_NULL; } }
	// --setters
	v1nil gfx_fmbuf::set_layt(layt_tc& layout) {
		m_layt = layout;
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
	v1nil gfx_fmbuf::add_part(part_t& ref) { m_parts.push_back(ref); }
	v1nil gfx_fmbuf::rmv_part(cv1u key) { m_parts.erase(m_parts.begin() + key % m_parts.size()); }
	// --operators
	op_stream_t& gfx_fmbuf::operator<<(op_stream_t& stm) const { return stm; }
	ip_stream_t& gfx_fmbuf::operator>>(ip_stream_t& stm) { return stm; }
	// --==<core_methods>==--
	v1bit gfx_fmbuf::remake()
	{
		if (m_handle != NW_NULL) { glDeleteFramebuffers(1u, &m_handle); m_handle = NW_NULL; }
		NW_CHECK(has_size(), "no size!", return NW_FALSE);

		glGenFramebuffers(1, &m_handle);
		glBindFramebuffer(GL_FRAMEBUFFER, get_handle());

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
	fmbuf::fmbuf(gfx_engine& graphics) :
		t_cmp(), a_gfx_cmp(graphics), a_io_cmp(),
		m_handle(NW_NULL),
		m_size{ 1u, 1u },
		m_depth(depth_t()), m_stenc(stenc_t()), m_targets(targets_t())
	{
	}
	fmbuf::~fmbuf() { }
	// --setters
	void fmbuf::add_target(target_t& ref) { m_targets.push_back(ref); }
	void fmbuf::rmv_target(v1u key) { m_targets.erase(m_targets.begin() + key % m_targets.size()); }
	// --operators
	// --==<core_methods>==--
	v1b fmbuf::remake(v2u size_xy)
	{
		return NW_TRUE;
	}
	void fmbuf::read_pixels(ptr data_ptr, v1u target_idx, const v4s& read_rect)
	{
	}
	void fmbuf::draw_pixels(cptr data_ptr, v1u target_idx, const v4s& draw_rect)
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
#endif // NW_GAPI