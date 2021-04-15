#include "nw_gfx_pch.hpp"
#include "nw_gfx_ent.h"
#if (defined NW_GAPI)
#include "../lib/nw_gfx_lib_core.h"
namespace NW
{
	a_gfx_ent::a_gfx_ent(gfx_engine& graphics) :
		t_ent(), a_gfx_rsc(graphics),
		m_prim(NW_PRIM_TRIANGLES)
	{
	}
	a_gfx_ent::~a_gfx_ent()
	{
	}
	// --setters
	void a_gfx_ent::set_prim(prim primitive) {
		m_prim = primitive;
	}
	// --==<core_methods>==--
	void a_gfx_ent::on_draw()
	{
		for (auto& icmp : get_cmp_tab()) { icmp->on_draw(); }
	}
	// --==</core_methods>==--
}
#endif	// NW_GAPI