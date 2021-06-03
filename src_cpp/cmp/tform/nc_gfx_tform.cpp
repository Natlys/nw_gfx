#include "nc_gfx_pch.hpp"
#include "nc_gfx_tform.hxx"
#if (defined NC_GAPI)
#	include "../../core/nc_nc_gfx_eng.hxx"
namespace NC
{
	gfx_tform::gfx_tform() : gfx_buf_shd_t(), m_crd(0.0f), m_rtn(0.0f), m_scl(1.0f) { }
	gfx_tform::gfx_tform(tform_tc& copy) : gfx_tform() { operator=(copy); }
	gfx_tform::gfx_tform(tform_t&& copy) : gfx_tform() { operator=(copy); }
	gfx_tform::~gfx_tform() { }
	/* setters */
	gfx_tform::tform_t& gfx_tform::set_crd(v3f_tc& coord) { m_crd = coord; return *this; }
	gfx_tform::tform_t& gfx_tform::set_rtn(v3f_tc& rotat) { m_rtn = rotat; return *this; }
	gfx_tform::tform_t& gfx_tform::set_scl(v3f_tc& scale) { m_scl = scale; return *this; }
	gfx_tform::tform_t& gfx_tform::set_modl(cm4x4f& model) { get_elem("modl").set<m4x4f>(model); return *this; }
	/* operators */
	/* commands */
	v1bit_t gfx_tform::remake()
	{
		NC_CHECK(gfx_buf_shd_t::remake(), "remake error!", return NC_FALSE);
		NC_CHECK(has_elem("modl"), "no model!", return NC_FALSE);

		return NC_TRUTH;
	}
	v1nil_t gfx_tform::on_draw()
	{
		gfx_buf_shd_t::on_draw();
		gfx_buf_shd_t::set_data();
	}
	// --==</core_methods>==--
}
#endif	// NC_GAPI