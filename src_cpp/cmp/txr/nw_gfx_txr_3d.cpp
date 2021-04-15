#include "nw_gfx_pch.hpp"
#include "nw_gfx_txr_3d.h"
#if (defined NW_GAPI)
#	include "../../core/nw_gfx_engine.h"
#	include "../../lib/nw_gfx_lib_txr.h"
#	include "../../lib/nw_gfx_lib_info.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_txr_cube::gfx_txr_cube(gfx_engine& graphics) :
		a_gfx_txr(graphics)
	{
	}
	gfx_txr_cube::~gfx_txr_cube() { }
	// --setters
	// --operators
	stm_out& gfx_txr_cube::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& gfx_txr_cube::operator>>(stm_in& stm) {
		return stm;
	}
	// --==<core_methods>==--
	v1bit gfx_txr_cube::remake(const gfx_img& img)
	{
		if (!a_gfx_txr::remake(img)) { return NW_FALSE; }
		if (get_count_x() <= 0 || get_count_y() <= 0) { return NW_FALSE; }
		
		glGenTextures(1, &m_handle);
		glBindTexture(GL_TEXTURE_CUBE_MAP, get_handle());

		v4f border_color = { 0.5f, 0.5f, 0.5f, 1.0f };
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_REPEAT);
		glTexParameterfv(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_BORDER_COLOR, &border_color[0]);

		for (v1u ifc = 0; ifc < 6; ifc++) {
			GLenum next = GL_TEXTURE_CUBE_MAP_POSITIVE_X + ifc;
			size_t size_x = get_count_x() / 1;
			size_t size_y = get_count_y() / 6;
			glTexImage2D(next, 0, get_pxl_fmt(), size_x, size_y, 0, get_txr_fmt(), get_vtype(), get_byte(NW_XY_TO_X(size_x, size_y, get_count_x())));
		}

		return NW_TRUE;
	}
	v1nil gfx_txr_cube::clear(ptr_tc buffer)
	{
		glClearTexImage(get_handle(), 0, get_pxl_fmt(), get_vtype(), buffer);
	}
	v1nil gfx_txr_cube::on_draw()
	{
		a_gfx_txr::on_draw();

		glEnable(GL_TEXTURE_CUBE_MAP);
		glActiveTexture(GL_TEXTURE0 + get_slot());
		glBindTexture(GL_TEXTURE_CUBE_MAP, get_handle());
	}
	
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	gfx_txr_cube::gfx_txr_cube(gfx_engine& graphics) :
		a_gfx_txr(graphics)
	{
	}
	gfx_txr_cube::~gfx_txr_cube() { if (m_native != NW_NULL) { m_native->Release(); m_native = NW_NULL; } }
	// --setters
	// --operators
	stm_out& gfx_txr_cube::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& gfx_txr_cube::operator>>(stm_in& stm) {
		return stm;
	}
	// --==<core_methods>==--
	v1bit gfx_txr_cube::remake(const gfx_img& img)
	{
		if (m_native != NW_NULL) { m_native->Release(); m_native = NW_NULL; }
		if (!a_gfx_txr::remake(img)) { return NW_FALSE; }
		if (get_size_x() <= 0 || get_size_y() <= 0) { return NW_FALSE; }
		
		return NW_TRUE;
	}
	v1nil gfx_txr_cube::clear(ptr value)
	{
	}
	v1nil gfx_txr_cube::on_draw()
	{
		a_gfx_txr::on_draw();
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NW_GAPI