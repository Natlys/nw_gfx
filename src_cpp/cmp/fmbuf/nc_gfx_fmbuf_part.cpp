#include "nc_gfx_pch.hpp"
#include "nc_gfx_fmbuf_part.hxx"
#if (defined NC_GAPI)
#	include "../../core/nc_nc_gfx_eng.hxx"
#	if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	gfx_fmbuf_part_t::gfx_fmbuf_part_t() :
		gfx_txr2d_t()
	{
	}
	gfx_fmbuf_part_t::~gfx_fmbuf_part_t()
	{
	}
	/* setters */
	/* operators */
	/* commands */
	v1bit_t gfx_fmbuf_part_t::remake()
	{
		NC_CHECK(gfx_txr2d_t::remake(), "remake error!", return NC_FALSE);

		return NC_TRUTH;
	}
	v1nil_t gfx_fmbuf_part_t::clear(ptr_tc data)
	{
		gfx_txr2d_t::clear(data);
	}
	v1nil_t gfx_fmbuf_part_t::on_draw()
	{
		gfx_txr2d_t::on_draw();
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