#include "nw_gfx_pch.hpp"
#include "nw_gfx_txr_3d.h"
#if (defined NW_GAPI)
#	include "../../core/nw_gfx_engine.h"
#	include "../../lib/nw_gfx_lib_txr.h"
#	include "../img/nw_gfx_img.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_txr_3d::gfx_txr_3d() :
		a_gfx_txr()
	{
	}
	gfx_txr_3d::~gfx_txr_3d() { }
	// --setters
	// --operators
	op_stream_t& gfx_txr_3d::operator<<(op_stream_t& stm) const {
		a_gfx_txr::operator<<(stm);
		return stm;
	}
	ip_stream_t& gfx_txr_3d::operator>>(ip_stream_t& stm) {
		a_gfx_txr::operator>>(stm);
		return stm;
	}
	// --==<core_methods>==--
	v1bit gfx_txr_3d::remake()
	{
		NW_CHECK(a_gfx_txr::remake(), "failed remake!", return NW_FALSE);
		NW_CHECK(has_size(), "no size!", return NW_FALSE);
		
		glBindTexture(GL_TEXTURE_3D, get_handle());

		v4f border_color = { 0.5f, 0.5f, 0.5f, 1.0f };
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_REPEAT);
		glTexParameterfv(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_BORDER_COLOR, &border_color[0]);

		for (v1u ifc = 0; ifc < 6; ifc++) {
			glTexImage3D(
				GL_TEXTURE_3D, 0, get_format(),
				get_size_x(), get_size_y(), get_size_z(), 0,
				get_format(), get_pxtype(), get_data()
			);
		}
		glGenerateMipmap(GL_TEXTURE_CUBE_MAP);

		return NW_TRUE;
	}
	v1nil gfx_txr_3d::clear(ptr_tc data)
	{
		a_gfx_txr::clear(data);
	}
	v1nil gfx_txr_3d::on_draw()
	{
		a_gfx_txr::on_draw();

		// glEnable(GL_TEXTURE_3D);
		glBindTexture(GL_TEXTURE_3D, get_handle());
	}
	// --==</core_methods>==--
}
namespace NW
{
	gfx_txr_cube::gfx_txr_cube() :
		a_gfx_txr()
	{
	}
	gfx_txr_cube::~gfx_txr_cube() { }
	// --setters
	// --operators
	op_stream_t& gfx_txr_cube::operator<<(op_stream_t& stm) const {
		a_gfx_txr::operator<<(stm);
		return stm;
	}
	ip_stream_t& gfx_txr_cube::operator>>(ip_stream_t& stm) {
		a_gfx_txr::operator>>(stm);
		return stm;
	}
	// --==<core_methods>==--
	v1bit gfx_txr_cube::remake()
	{
		NW_CHECK(a_gfx_txr::remake(), "failed remake!", return NW_FALSE);
		NW_CHECK(has_size(), "no size!", return NW_FALSE);
		NW_CHECK(get_size_z() == 6u, "wrong size!", return NW_FALSE);
		
		glBindTexture(GL_TEXTURE_CUBE_MAP, get_handle());

		v4f border_color = { 0.5f, 0.5f, 0.5f, 1.0f };
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_REPEAT);
		glTexParameterfv(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_BORDER_COLOR, &border_color[0]);

		for (v1u ifc = 0; ifc < 6; ifc++) {
			glTexImage2D(
				GL_TEXTURE_CUBE_MAP_POSITIVE_X + ifc, 0, get_format(),
				get_size_x() / 1, get_size_y() / 6, 0,
				get_format(), get_pxtype(), get_data()
			);
		}
		glGenerateMipmap(GL_TEXTURE_CUBE_MAP);

		return NW_TRUE;
	}
	v1nil gfx_txr_cube::clear(ptr_tc data)
	{
		a_gfx_txr::clear(data);
	}
	v1nil gfx_txr_cube::on_draw()
	{
		a_gfx_txr::on_draw();

		// glEnable(GL_TEXTURE_CUBE_MAP);
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
	op_stream_t& gfx_txr_cube::operator<<(op_stream_t& stm) const {
		return stm;
	}
	ip_stream_t& gfx_txr_cube::operator>>(ip_stream_t& stm) {
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