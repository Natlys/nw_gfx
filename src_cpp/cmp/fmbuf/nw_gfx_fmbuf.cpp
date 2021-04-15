#include "nw_gfx_pch.hpp"
#include "nw_gfx_fmbuf.h"
#if (defined NW_GAPI)
#include "../txr/nw_gfx_txr.h"
#include "lib/nw_gfx_lib_fmbuf.h"
#include "lib/nw_gfx_lib_txr.h"
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	fmbuf::fmbuf(gfx_engine& graphics) :
		t_cmp(), a_gfx_cmp(graphics), a_io_cmp(),
		m_handle(NW_NULL),
		m_size{ 1u, 1u },
		m_depth(depth_t()), m_stenc(stenc_t()), m_targets(targets_t())
	{
	}
	fmbuf::~fmbuf() { if (m_handle != NW_NULL) { glDeleteFramebuffers(1u, &m_handle); m_handle = NW_NULL; } }
	// --setters
	void fmbuf::add_target(target_t& ref) { m_targets.push_back(ref); }
	void fmbuf::rmv_target(v1u idx) { m_targets.erase(m_targets.begin() + idx % m_targets.size()); }
	// --operators
	stm_out& fmbuf::operator<<(stm_out& stm) const { return stm; }
	stm_in& fmbuf::operator>>(stm_in& stm) { return stm; }
	// --==<core_methods>==--
	v1bit fmbuf::remake(v2u size_xy)
	{
		if (m_handle != 0) { glDeleteFramebuffers(1, &m_handle); m_handle = 0; }
		if (get_size_x() < 1 || get_size_y() < 1) { return NW_FALSE; }

		glGenFramebuffers(1, &m_handle);
		glBindFramebuffer(GL_FRAMEBUFFER, m_handle);

		return NW_TRUE;
	}
	v1nil fmbuf::read_pixels(ptr_t buffer, v1u key, cv4s& rect)
	{
		glReadBuffer(GL_COLOR_ATTACHMENT0 + key);
		// --error is guaranteed, internal and usual formats are different
		glReadPixels(rect[0], rect[1], rect[2], rect[3],
			m_targets[key % m_targets.size()]->get_pxl_fmt(),
			m_targets[key % m_targets.size()]->get_pxl_fmt(),
			buffer
		);
	}
	v1nil fmbuf::draw_pixels(ptr_tc buffer, v1u key, cv4s& draw_rect)
	{
		auto& target = get_target(key);
		glDrawBuffer(GL_COLOR_ATTACHMENT0 + key);
		glDrawPixels(draw_rect[2], draw_rect[3],
			target->get_pxl_fmt(),
			target->get_pxl_fmt(),
			buffer
		);
	}
	void fmbuf::clear() {
		GLenum mask = 0u;
		mask |= m_targets.size() > 0u ? GL_COLOR_BUFFER_BIT : 0u;
		mask |= m_depth.is_valid() ? GL_DEPTH_BUFFER_BIT : 0u;
		mask |= m_stenc.is_valid() ? GL_STENCIL_BUFFER_BIT : 0u;
		glClear(mask);
	}
	void fmbuf::on_draw()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_handle);
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_D3D)
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
#endif
#endif // NW_GAPI