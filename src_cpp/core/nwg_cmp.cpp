#include <nwg_pch.hpp>
#include "nwg_cmp.h"
#if (defined NWG_GAPI)
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	a_gfx_cmp::a_gfx_cmp(gfx_engine& graphics) :
		a_cmp(), m_gfx(&graphics) { }
	a_gfx_cmp::~a_gfx_cmp() { }
	// --setters
	// --core_methods
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
	a_gfx_cmp::a_gfx_cmp(gfx_engine& graphics) : a_cmp(), m_gfx(&graphics) { }
	a_gfx_cmp::~a_gfx_cmp() { }
	// --setters
	// --core_methods
}
#endif
#endif	// NWG_GAPI