#include <nwg_pch.hpp>
#include "nwg_cmp.h"
#if (defined NW_GAPI)
namespace NW
{
	a_gfx_cmp::a_gfx_cmp(gfx_engine& graphics) :
		a_gfx_rsc(graphics)
	{
	}
	a_gfx_cmp::~a_gfx_cmp() { }
	// --core_methods
	void a_gfx_cmp::on_draw()
	{
	}
}
#endif	// NW_GAPI