#include <nwg_pch.hpp>
#include "nwg_texture_2d.h"
#if (defined NW_GAPI)
#include <lib/nwg_load_txr.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	texture_2d::texture_2d(gfx_engine& graphics, cstring name) :
		a_texture(name), t_gfx_rsc(graphics)
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
	bit texture_2d::remake(const a_image& img)
	{
		set_data(img);
		if (m_ogl_id != 0) { glDeleteTextures(1, &m_ogl_id); m_ogl_id = 0; }
		if (m_channels <= 0 || m_size_x <= 0 || m_size_y <= 0) { return false; }
		glGenTextures(1, &m_ogl_id);
		glBindTexture(GL_TEXTURE_2D, m_ogl_id);

		v4f border_color = { 0.5f, 0.5f, 0.5f, 1.0f };
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, &border_color[0]);

		GLenum ogl_data_type = convert_enum<data_types, GLenum>(m_data_type);
		GLenum ogl_inter_fmt = convert_enum<texture_formats, GLenum>(m_txr_fmt);
		GLenum ogl_img_fmt = convert_enum<texture_formats, GLenum>(m_txr_fmt);
		glTexImage2D(GL_TEXTURE_2D, 0, ogl_inter_fmt, m_size_x, m_size_y, 0, ogl_img_fmt, ogl_data_type, &m_pxl_data[0]);
		glGenerateMipmap(GL_TEXTURE_2D);

		return true;
	}
	void texture_2d::clear(ptr value) {
		glClearTexImage(m_ogl_id, 0,
			convert_enum<pixel_formats, GLenum>(m_pxl_fmt),
			convert_enum<pixel_formats, GLenum>(m_pxl_fmt), value);
	}
	void texture_2d::on_draw()
	{
		glEnable(GL_TEXTURE_2D);
		glActiveTexture(GL_TEXTURE0 + m_slot);
		glBindTexture(GL_TEXTURE_2D, m_ogl_id);
	}
	// --==</core_methods>==--
}
namespace NW
{
	texture_2d_mulsmp::texture_2d_mulsmp(gfx_engine& graphics, cstring name) :
		texture_2d(graphics, name),
		m_samples(0)
	{
	}
	texture_2d_mulsmp::~texture_2d_mulsmp() { }
	// --setters
	void texture_2d_mulsmp::set_samples(ui8 samples) {
		m_samples = samples;
	}
	// --operators
	out_stream& texture_2d_mulsmp::operator<<(out_stream& stm) const {
		return stm;
	}
	in_stream& texture_2d_mulsmp::operator>>(in_stream& stm) {
		return stm;
	}
	// --==<core_methods>==--
	bit texture_2d_mulsmp::remake(const a_image& img)
	{
		m_size_x = img.get_size_x();
		m_size_y = img.get_size_y();
		m_pxl_fmt = img.get_pxl_fmt();
		m_channels = img.get_channels();
		if (m_ogl_id != 0) { glDeleteTextures(1, &m_ogl_id); m_ogl_id = 0; }
		if (m_channels <= 0 || m_size_x <= 0 || m_size_y <= 0) { return false; }
		glGenTextures(1, &m_ogl_id);
		glBindTexture(GL_TEXTURE_2D, m_ogl_id);

		glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, m_samples,
			convert_enum<pixel_formats, GLenum>(m_pxl_fmt),
			m_size_x, m_size_y, false);
		return true;
	}
	void texture_2d_mulsmp::on_draw()
	{
		glEnable(GL_MULTISAMPLE);
		glActiveTexture(GL_TEXTURE0 + m_slot);
		glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, m_ogl_id);
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