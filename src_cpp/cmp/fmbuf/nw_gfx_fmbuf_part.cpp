#include "nw_gfx_pch.hpp"
#include "nw_gfx_fmbuf_part.h"
#if (defined NW_GAPI)
#	include "../../core/nw_gfx_engine.h"
#	include "../../lib/nw_gfx_lib_fmbuf.h"
#	include "../../lib/nw_gfx_lib_txr.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	a_gfx_fmbuf_part::a_gfx_fmbuf_part() :
		gfx_txr_2d()
	{
	}
	a_gfx_fmbuf_part::~a_gfx_fmbuf_part()
	{
	}
	// --setters
	// --operators
	// --==<core_methods>==--
	v1bit a_gfx_fmbuf_part::remake()
	{
		NW_CHECK(gfx_txr_2d::remake(), "remake error!", return NW_FALSE);

		return NW_TRUE;
	}
	v1nil a_gfx_fmbuf_part::clear(ptr_tc data)
	{
		gfx_txr_2d::clear(data);
	}
	v1nil a_gfx_fmbuf_part::on_draw()
	{
		gfx_txr_2d::on_draw();
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{

}
#	endif	// GAPI_D3D
#endif	// NW_GAPI