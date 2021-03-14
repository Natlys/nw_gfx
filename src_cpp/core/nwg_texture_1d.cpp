#include <nwg_pch.hpp>
#include "nwg_texture_1d.h"
#if (defined NW_GAPI)
#include <lib/nwg_load_txr.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	texture_1d::texture_1d(gfx_engine& graphics, cstring name) :
		a_texture(name), t_gfx_rsc(graphics)
	{
	}
	texture_1d::~texture_1d() { }
	// --setters
	// --operators
	// --operators
	out_stream& texture_1d::operator<<(out_stream& stm) const {
		return stm;
	}
	in_stream& texture_1d::operator>>(in_stream& stm) {
		return stm;
	}
	// --==<core_methods>==--
	bit texture_1d::remake(const a_image& img)
	{
		set_data(img);
		if (m_ogl_id != 0) { glDeleteTextures(1, &m_ogl_id); m_ogl_id = 0; }
		if (m_channels <= 0 || m_size_x <= 0) { return false; }
		glGenTextures(1, &m_ogl_id);
		glBindTexture(GL_TEXTURE_1D, m_ogl_id);

		v4f border_color = { 0.5f, 0.5f, 0.5f, 1.0f };
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterfv(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_BORDER_COLOR, &border_color[0]);

		GLenum ogl_data_type = convert_enum<data_types, GLenum>(m_data_type);
		GLenum ogl_inter_fmt = convert_enum<texture_formats, GLenum>(m_txr_fmt);
		GLenum ogl_img_fmt = convert_enum<texture_formats, GLenum>(m_txr_fmt);
		glTexImage1D(GL_TEXTURE_1D, 0, ogl_inter_fmt, m_size_x, 0, ogl_img_fmt,
			ogl_data_type, &m_pxl_data[0]);

		return true;
	}
	void texture_1d::on_draw()
	{
		glEnable(GL_TEXTURE_1D);
		glActiveTexture(GL_TEXTURE0 + m_slot);
		glBindTexture(GL_TEXTURE_CUBE_MAP, m_ogl_id);
	}
	void texture_1d::clear(ptr value) {
		glClearTexImage(m_ogl_id, 0,
			convert_enum<pixel_formats, GLenum>(m_pxl_fmt),
			convert_enum<data_types, GLenum>(m_data_type), value);
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	//
}
#endif
#endif	// NW_GAPI