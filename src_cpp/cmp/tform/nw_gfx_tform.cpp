#include "nw_gfx_pch.hpp"
#include "nw_gfx_tform.h"
#if (defined NW_GAPI)
#	include "../../core/nw_gfx_engine.h"
namespace NW
{
	gfx_tform::gfx_tform() : gfx_buf_shd(), m_crd(0.0f), m_rtn(0.0f), m_scl(1.0f) { }
	gfx_tform::gfx_tform(tform_tc& copy) : gfx_tform() { operator=(copy); }
	gfx_tform::gfx_tform(tform_t&& copy) : gfx_tform() { operator=(copy); }
	gfx_tform::~gfx_tform() { }
	// --setters
	gfx_tform::tform_t& gfx_tform::set_crd(cv3f& coord) { m_crd = coord; return *this; }
	gfx_tform::tform_t& gfx_tform::set_rtn(cv3f& rotat) { m_rtn = rotat; return *this; }
	gfx_tform::tform_t& gfx_tform::set_scl(cv3f& scale) { m_scl = scale; return *this; }
	gfx_tform::tform_t& gfx_tform::set_modl(cm4f& model) { get_elem("modl").set<m4f>(model); return *this; }
	// --operators
	// --==<core_methods>==--
	v1bit gfx_tform::remake()
	{
		NW_CHECK(gfx_buf_shd::remake(), "remake error!", return NW_FALSE);
		NW_CHECK(has_elem("modl"), "no model!", return NW_FALSE);

		return NW_TRUE;
	}
	v1nil gfx_tform::on_draw()
	{
		gfx_buf_shd::on_draw();
		gfx_buf_shd::set_data();
	}
	// --==</core_methods>==--
}
#endif	// NW_GAPI