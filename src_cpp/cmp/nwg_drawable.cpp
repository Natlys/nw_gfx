#include <nwg_pch.hpp>
#include "nwg_drawable.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	drawable::drawable(gfx_engine& graphics) :
		t_gfx_rsc(graphics)
	{
	}
	drawable::~drawable() { }
	// --setters
	void drawable::add_rsc(rsc_ref& ref) { m_rscs.push_back(ref); }
	void drawable::rmv_rsc(ui8 idx) { m_rscs.erase(m_rscs.begin() + idx % m_rscs.size()); }
	// --operators
	// --==<core_methods>==--
	void drawable::on_draw() {
		m_gmt->on_draw();
		for (auto& irsc : m_rscs) { irsc->on_draw(); }
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
#include <lib/nwg_dx_loader.h>
namespace NW
{
	//
}
#endif
#endif	// NW_GAPI