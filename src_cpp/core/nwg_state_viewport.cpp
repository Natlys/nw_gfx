#include <nwg_pch.hpp>
#include "nwg_state_viewport.h"
#if (defined NW_GAPI)
#if (NW_GAPI & NW_GAPI_OGL)
#include <lib/nwg_load_base.h>
namespace NW
{
	state_viewport::state_viewport(gfx_engine& graphics) :
		t_gfx_rsc(graphics),
		m_crd{ 0, 0 }, m_size{ 800, 600 }
	{
	}
	state_viewport::~state_viewport() { }
	// --==<core_methods>==--
	void state_viewport::on_draw()
	{
		if (!m_is_enabled) { return; }
		glViewport(m_crd[0], m_crd[0], m_size[0], m_size[1]);
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
#endif
#endif	// NW_GAPI