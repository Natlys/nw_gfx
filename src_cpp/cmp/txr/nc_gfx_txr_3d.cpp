#include "nc_gfx_pch.hpp"
#include "nc_gfx_txr_3d.hxx"
#if (defined NC_GAPI)
#	include "../../core/nc_nc_gfx_eng.hxx"
#	include "../../lib/nc_gfx_lib_info.hxx"
#	if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	gfx_txr3d_cube_t::gfx_txr3d_cube_t() : gfx_txr_t() { }
	gfx_txr3d_cube_t::~gfx_txr3d_cube_t() { }
	/* setters */
	/* operators */
	nc_ostream_t& gfx_txr3d_cube_t::operator<<(nc_ostream_t& stm) const { return stm; }
	nc_istream_t& gfx_txr3d_cube_t::operator>>(nc_istream_t& stm) { return stm; }
	/* commands */
	v1bit_t gfx_txr3d_cube_t::remake()
	{
		NC_CHECK(gfx_txr_t::remake(), "remake error!", return NC_FALSE);
		NC_CHECK(has_size(), "no size!", return NC_FALSE);
		
		get_context()->txr_new(1, &m_handle);
		get_context()->txr_bind(GL_TEXTURE_CUBE_MAP, get_handle());

		v4f_t border_color = { 0.5f, 0.5f, 0.5f, 1.0f };
		get_context()->txr_set_param_n1s(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		get_context()->txr_set_param_n1s(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		get_context()->txr_set_param_n1s(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_REPEAT);
		get_context()->txr_set_param_n1s(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_REPEAT);
		get_context()->txr_set_param_n1s(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_REPEAT);
		get_context()->txr_set_param_v1f(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_BORDER_COLOR, &border_color[0]);

		for (v1u_t ifc = 0; ifc < 6; ifc++) {
			GLenum next = GL_TEXTURE_CUBE_MAP_POSITIVE_X + ifc;
			size_t size_x = get_size_x() / 1;
			size_t size_y = get_size_y() / 6;
			get_context()->txr_set_image_2d(next, 0, get_format(), size_x, size_y, 0, get_format(), get_pxtype(), get_data(NC_NUM_2D_1D(size_x, size_y, get_size_x())));
		}

		return NC_TRUTH;
	}
	v1nil_t gfx_txr3d_cube_t::clear(ptr_tc buffer)
	{
		gfx_txr_t::clear(buffer);
	}
	v1nil_t gfx_txr3d_cube_t::on_draw()
	{
		gfx_txr_t::on_draw();

		// get_context()->set_enabled(GL_TEXTURE_CUBE_MAP);
		get_context()->txr_bind(GL_TEXTURE_CUBE_MAP, get_handle());
	}
	
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
namespace NC
{
	gfx_txr3d_cube_t::gfx_txr3d_cube_t(nc_gfx_eng& graphics) :
		gfx_txr_t(graphics)
	{
	}
	gfx_txr3d_cube_t::~gfx_txr3d_cube_t() { if (m_native != NC_NULL) { m_native->Release(); m_native = NC_NULL; } }
	/* setters */
	/* operators */
	stm_out& gfx_txr3d_cube_t::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& gfx_txr3d_cube_t::operator>>(stm_in& stm) {
		return stm;
	}
	/* commands */
	v1bit_t gfx_txr3d_cube_t::remake(const gfx_img_t& img)
	{
		if (m_native != NC_NULL) { m_native->Release(); m_native = NC_NULL; }
		if (!gfx_txr_t::remake(img)) { return NC_FALSE; }
		if (get_size_x() <= 0 || get_size_y() <= 0) { return NC_FALSE; }
		
		return NC_TRUTH;
	}
	v1nil_t gfx_txr3d_cube_t::clear(ptr value)
	{
	}
	v1nil_t gfx_txr3d_cube_t::on_draw()
	{
		gfx_txr_t::on_draw();
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NC_GAPI