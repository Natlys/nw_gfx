#include <nwg_pch.hpp>
#include "nwg_texture_3d.h"
#if (defined NW_GAPI)
#include <lib/nwg_load_txr.h>
#include <lib/nwg_load_img.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	texture_cube::texture_cube(gfx_engine& graphics, cstring name) :
		a_texture(name), t_gfx_res(graphics)
	{
	}
	texture_cube::~texture_cube() { }
	// --setters
	// --operators
	out_stream& texture_cube::operator<<(out_stream& stm) const {
		return stm;
	}
	in_stream& texture_cube::operator>>(in_stream& stm) {
		return stm;
	}
	// --==<core_methods>==--
	bit texture_cube::remake(const a_image& img)
	{
		if (m_ogl_id != 0) { glDeleteTextures(1, &m_ogl_id); m_ogl_id = 0; }
		if (m_samples <= 0 || m_channels <= 0 || m_size_x <= 0 || m_size_y <= 0) { return false; }
		glGenTextures(1, &m_ogl_id);
		glBindTexture(GL_TEXTURE_CUBE_MAP, m_ogl_id);

		v4f border_color = { 0.5f, 0.5f, 0.5f, 1.0f };
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_REPEAT);
		glTexParameterfv(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_BORDER_COLOR, &border_color[0]);

		for (ui8 ifc = 0; ifc < 6; ifc++) {
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + ifc, 0,
				convert_enum<pixel_formats, GLenum>(m_pxl_fmt), m_size_x, m_size_y, 0, convert_enum<texture_formats, GLenum>(m_txr_fmt),
				convert_enum<data_types, GLenum>(m_data_type), get_data());
		}

		return true;
	}
	void texture_cube::on_draw()
	{
		glActiveTexture(GL_TEXTURE0 + m_slot);
		glBindTexture(GL_TEXTURE_CUBE_MAP, m_ogl_id);
	}
	void texture_cube::clear(ptr value) {
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