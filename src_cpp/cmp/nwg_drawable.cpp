#include <nwg_pch.hpp>
#include "nwg_drawable.h"
#if (defined NWG_GAPI)
#include <core/nwg_engine.h>
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	a_drawable::a_drawable() { }
	a_drawable::~a_drawable() { }
	// --setters
	void a_drawable::add_res(res_ref& ref) { m_rscs.push_back(ref); }
	void a_drawable::rmv_res(ui8 idx) { m_rscs.erase(m_rscs.begin() + idx % m_rscs.size()); }
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
#include <lib/nwg_dx_loader.h>
namespace NWG
{
	//
}
#endif
#endif	// NWG_GAPI