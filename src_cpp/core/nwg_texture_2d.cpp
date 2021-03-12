#include <nwg_pch.hpp>
#include "nwg_texture_2d.h"
#if (defined NW_GAPI)
#include <lib/nwg_load_txr.h>
#define STB_IMAGE_IMPLEMENTATION
#include <lib/nwg_load_img.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	texture_2d::texture_2d(gfx_engine& graphics, cstring name) :
		a_texture(name), t_gfx_res(graphics)
	{
	}
	texture_2d::~texture_2d() { }
	// --setters
	// --operators
	out_stream& texture_2d::operator<<(out_stream& stm) const {
		return stm;
	}
	in_stream& texture_2d::operator>>(in_stream& stm) {
		return stm;
	}
	// --==<core_methods>==--
	void texture_2d::on_draw()
	{
		glActiveTexture(GL_TEXTURE0 + m_slot);
		glBindTexture(GL_TEXTURE_2D, m_ogl_id);
	}
	bit texture_2d::remake(const a_image& img)
	{
		m_size_x = img.get_size_x();
		m_size_y = img.get_size_y();
		m_pxl_fmt = img.get_pxl_fmt();
		m_channels = img.get_channels();
		if (m_ogl_id != 0) { glDeleteTextures(1, &m_ogl_id); m_ogl_id = 0; }
		if (m_samples <= 0 || m_channels <= 0 || m_size_x <= 0 || m_size_y <= 0) { return false; }
		glGenTextures(1, &m_ogl_id);
		glBindTexture(GL_TEXTURE_2D, m_ogl_id);

		v4f border_color = { 0.5f, 0.5f, 0.5f, 1.0f };
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, &border_color[0]);

		if (m_samples == 1) {
			glTexImage2D(GL_TEXTURE_2D, 0, convert_enum<pixel_formats, GLenum>(m_pxl_fmt),
				m_size_x, m_size_y, 0, convert_enum<texture_formats, GLenum>(m_txr_fmt),
				convert_enum<data_types, GLenum>(m_data_type), get_data());
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else if (m_samples > 1) {
			glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, m_samples,
				convert_enum<pixel_formats, GLenum>(m_pxl_fmt),
				m_size_x, m_size_y, false);
		}
		return true;
	}
	void texture_2d::clear(ptr value) {
		glClearTexImage(m_ogl_id, 0,
			convert_enum<pixel_formats, GLenum>(m_pxl_fmt),
			convert_enum<pixel_formats, GLenum>(m_pxl_fmt), value);
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