#include <nwg_pch.hpp>
#include "nwg_fmbuf.h"
#if (defined NW_GAPI)
#include <cmp/txr/nwg_txr.h>
#include <lib/nwg_load_fmbuf.h>
#include <lib/nwg_load_txr.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	fmbuf::fmbuf(gfx_engine& graphics) :
		t_cmp(), a_gfx_cmp(graphics), a_data_cmp(),
		m_handle(0)
	{
	}
	fmbuf::~fmbuf() { if (m_handle != 0) { glDeleteFramebuffers(1, &m_handle); m_handle = 0; } }
	// --setters
	void fmbuf::add_target(target& ref) { m_targets.push_back(ref); }
	void fmbuf::rmv_target(ui8 idx) { m_targets.erase(m_targets.begin() + idx % m_targets.size()); }
	// --operators
	stm_out& fmbuf::operator<<(stm_out& stm) const { return stm; }
	stm_in& fmbuf::operator>>(stm_in& stm) { return stm; }
	// --==<core_methods>==--
	bit fmbuf::remake(v2ui size_xy)
	{
		if (m_handle != 0) { glDeleteFramebuffers(1, &m_handle); m_handle = 0; }
		if (get_size_x() < 1 || get_size_y() < 1) { return false; }

		glGenFramebuffers(1, &m_handle);
		glBindFramebuffer(GL_FRAMEBUFFER, m_handle);

		return true;
	}
	void fmbuf::read_pixels(ptr data_ptr, ui8 target_idx, const v4si& read_rect)
	{
		glReadBuffer(GL_COLOR_ATTACHMENT0 + target_idx);
		// --error is guaranteed, internal and usual formats are different
		glReadPixels(read_rect[0], read_rect[1], read_rect[2], read_rect[3],
			convert_enum<pixel_formats, GLenum>(m_targets[target_idx % m_targets.size()]->get_pxl_fmt()),
			convert_enum<data_types, GLenum>(m_targets[target_idx % m_targets.size()]->get_data_type()),
			data_ptr
		);
	}
	void fmbuf::draw_pixels(ptr data_ptr, ui8 target_idx, const v4si& draw_rect)
	{
		auto& target = get_target(target_idx);
		glDrawBuffer(GL_COLOR_ATTACHMENT0 + target_idx);
		glDrawPixels(draw_rect[2], draw_rect[3],
			convert_enum<pixel_formats, GLenum>(m_targets[target_idx % m_targets.size()]->get_pxl_fmt()),
			convert_enum<data_types, GLenum>(m_targets[target_idx % m_targets.size()]->get_data_type()),
			data_ptr
		);
	}
	void fmbuf::clear() {
		GLenum mask = 0;
		mask |= m_targets.size() > 0 ? GL_COLOR_BUFFER_BIT : 0u;
		mask |= m_depth.is_valid() ? GL_DEPTH_BUFFER_BIT : 0u;
		mask |= m_stencil.is_valid() ? GL_STENCIL_BUFFER_BIT : 0u;
		glClear(mask);
	}
	void fmbuf::on_draw()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_handle);
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	fmbuf::fmbuf(gfx_engine& graphics) :
		t_cmp(), a_gfx_cmp(graphics), a_data_cmp()
	{
	}
	fmbuf::~fmbuf() { }
	// --setters
	void fmbuf::add_target(target& ref) { m_targets.push_back(ref); }
	void fmbuf::rmv_target(ui8 idx) { m_targets.erase(m_targets.begin() + idx % m_targets.size()); }
	// --operators
	// --==<core_methods>==--
	bit fmbuf::remake(v2ui size_xy)
	{
		return true;
	}
	void fmbuf::read_pixels(ptr data_ptr, ui8 target_idx, const v4si& read_rect)
	{
	}
	void fmbuf::draw_pixels(ptr data_ptr, ui8 target_idx, const v4si& draw_rect)
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