#include <nwg_pch.hpp>
#include "nwg_rsc.h"
#if (defined NW_GAPI)
namespace NW
{
	a_gfx_rsc::a_gfx_rsc(gfx_engine& graphics) :
		m_gfx(&graphics)
	{
	}
	a_gfx_rsc::~a_gfx_rsc() { }
	// --core_methods
	void a_gfx_rsc::on_draw()
	{
	}
}
#endif	// NW_GAPI