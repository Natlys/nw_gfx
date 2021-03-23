#include <nwg_pch.hpp>
#include "nwg_txr_3d.h"
#if (defined NW_GAPI)
#include <lib/nwg_load_txr.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	txr_cube::txr_cube(gfx_engine& graphics) :
		a_txr(graphics)
	{
	}
	txr_cube::~txr_cube() { }
	// --setters
	// --operators
	stm_out& txr_cube::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& txr_cube::operator>>(stm_in& stm) {
		return stm;
	}
	// --==<core_methods>==--
	bit txr_cube::remake(const img_cmp& img)
	{
		m_channels = img.get_channels();
		set_data(img);
		if (m_handle != 0) { glDeleteTextures(1, &m_handle); m_handle = 0; }
		if (m_channels <= 0 || m_size_x <= 0 || m_size_y <= 0) { return false; }
		glGenTextures(1, &m_handle);
		glBindTexture(GL_TEXTURE_CUBE_MAP, m_handle);

		v4f border_color = { 0.5f, 0.5f, 0.5f, 1.0f };
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_REPEAT);
		glTexParameterfv(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_BORDER_COLOR, &border_color[0]);

		GLenum ogl_data_type = convert_enum<data_types, GLenum>(m_data_type);
		GLenum ogl_inter_fmt = convert_enum<txr_formats, GLenum>(m_txr_fmt);
		GLenum ogl_img_fmt = convert_enum<txr_formats, GLenum>(m_txr_fmt);
		for (ui8 ifc = 0; ifc < 6; ifc++) {
			data face_data = make_region(m_size_x / 6 * 0, m_size_y / 6 * (5 - ifc), m_size_x / 1, m_size_y / 6);
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + ifc, 0, ogl_inter_fmt,
				m_size_x / 1, m_size_y / 6, 0,
				ogl_img_fmt, ogl_data_type, &face_data[0]);
		}

		return true;
	}
	void txr_cube::on_draw()
	{
		a_txr::on_draw();

		glEnable(GL_TEXTURE_CUBE_MAP);
		glActiveTexture(GL_TEXTURE0 + m_slot);
		glBindTexture(GL_TEXTURE_CUBE_MAP, m_handle);
	}
	void txr_cube::clear(ptr value) {
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
	//
}
#endif
#endif	// NW_GAPI