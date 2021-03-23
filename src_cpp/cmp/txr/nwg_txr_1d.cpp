#include <nwg_pch.hpp>
#include "nwg_txr_1d.h"
#if (defined NW_GAPI)
#include <lib/nwg_load_txr.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	txr_1d::txr_1d(gfx_engine& graphics) :
		a_txr(graphics)
	{
	}
	txr_1d::~txr_1d() { }
	// --setters
	// --operators
	// --operators
	stm_out& txr_1d::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& txr_1d::operator>>(stm_in& stm) {
		return stm;
	}
	// --==<core_methods>==--
	bit txr_1d::remake(const img_cmp& img)
	{
		set_data(img);
		if (m_handle != 0) { glDeleteTextures(1, &m_handle); m_handle = 0; }
		if (m_channels <= 0 || m_size_x <= 0) { return false; }
		glGenTextures(1, &m_handle);
		glBindTexture(GL_TEXTURE_1D, m_handle);

		v4f border_color = { 0.5f, 0.5f, 0.5f, 1.0f };
		glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterfv(GL_TEXTURE_1D, GL_TEXTURE_BORDER_COLOR, &border_color[0]);

		GLenum ogl_data_type = convert_enum<data_types, GLenum>(m_data_type);
		GLenum ogl_inter_fmt = convert_enum<txr_formats, GLenum>(m_txr_fmt);
		GLenum ogl_img_fmt = convert_enum<txr_formats, GLenum>(m_txr_fmt);
		glTexImage1D(GL_TEXTURE_1D, 0, ogl_inter_fmt, m_size_x, 0, ogl_img_fmt,
			ogl_data_type, &m_pxl_data[0]);

		return true;
	}
	void txr_1d::on_draw()
	{
		a_txr::on_draw();
		glEnable(GL_TEXTURE_1D);
		glActiveTexture(GL_TEXTURE0 + m_slot);
		glBindTexture(GL_TEXTURE_1D, m_handle);
	}
	void txr_1d::clear(ptr value) {
		glClearTexImage(m_handle, 0,
			convert_enum<pixel_formats, GLenum>(m_pxl_fmt),
			convert_enum<data_types, GLenum>(m_data_type), value);
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	txr_1d::txr_1d(gfx_engine& graphics) :
		a_txr(graphics)
	{
	}
	txr_1d::~txr_1d() { if (m_native != nullptr) { m_native->Release(); m_native = nullptr; } }
	// --setters
	// --operators
	// --operators
	stm_out& txr_1d::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& txr_1d::operator>>(stm_in& stm) {
		return stm;
	}
	// --==<core_methods>==--
	bit txr_1d::remake(const img_cmp& img)
	{
		set_data(img);
		if (m_handle != nullptr) { m_handle->Release(); m_handle = nullptr; }
		if (m_native != nullptr) { m_native->Release(); m_native = nullptr; }
		if (m_channels <= 0 || m_size_x <= 0) { return false; }
		return true;
	}
	void txr_1d::on_draw()
	{
		a_txr::on_draw();
	}
	void txr_1d::clear(ptr value) {
	}
	// --==</core_methods>==--
}
#endif
#endif	// NW_GAPI