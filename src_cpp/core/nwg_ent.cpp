#include <nwg_pch.hpp>
#include "nwg_ent.h"
#if (defined NW_GAPI)
namespace NW
{
	a_gfx_ent::a_gfx_ent(gfx_engine& graphics) :
		t_ent(), a_gfx_rsc(graphics)
	{
	}
	a_gfx_ent::~a_gfx_ent() { }
	// --setters
	// --==<core_methods>==--
	void a_gfx_ent::on_draw()
	{
		for (auto& icmp : m_tab) { icmp->on_draw(); }
	}
	// --==</core_methods>==--
}
#endif	// NW_GAPI