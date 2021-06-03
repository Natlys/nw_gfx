#include "nc_gfx_pch.hpp"
#include "nc_gfx_fmbuf_dpst.hxx"
#if (defined NC_GAPI)
#	include "../../core/nc_nc_gfx_eng.hxx"
#	if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	gfx_fmbuf_dpst_t::gfx_fmbuf_dpst_t() :
		gfx_fmbuf_part_t()
	{
	}
	gfx_fmbuf_dpst_t::~gfx_fmbuf_dpst_t()
	{
	}
	/* setters */
	/* operators */
	/* commands */
	v1bit_t gfx_fmbuf_dpst_t::remake()
	{
		NC_CHECK(gfx_fmbuf_part_t::remake(), "remake error!", return NC_FALSE);
		
		get_context()->fmbuf_set_txr_2d(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, get_handle(), 0);

		return NC_TRUTH;
	}
	v1nil_t gfx_fmbuf_dpst_t::clear(ptr_tc data)
	{
		gfx_fmbuf_part_t::clear(data);
		get_context()->fmbuf_clear(GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}
	v1nil_t gfx_fmbuf_dpst_t::on_draw()
	{
		gfx_fmbuf_part_t::on_draw();
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
namespace NC
{
}
#	endif	// GAPI_D3D
#endif	// NC_GAPI