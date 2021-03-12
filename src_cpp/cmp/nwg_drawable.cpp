#include <nwg_pch.hpp>
#include "nwg_drawable.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	a_drawable::a_drawable() { }
	a_drawable::~a_drawable() { }
	// --setters
	void a_drawable::add_rsc(rsc_ref& ref) { m_rscs.push_back(ref); }
	void a_drawable::rmv_rsc(ui8 idx) { m_rscs.erase(m_rscs.begin() + idx % m_rscs.size()); }
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