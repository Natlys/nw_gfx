#include <nwg_pch.hpp>
#include "nwg_rsc.h"
#if (defined NW_GAPI)
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	a_gfx_rsc::a_gfx_rsc()
	{
	}
	a_gfx_rsc::~a_gfx_rsc() { }
	// --setters
	// --core_methods
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	a_gfx_rsc::a_gfx_rsc(gfx_engine& graphics) : a_cmp(), m_gfx(&graphics) { }
	a_gfx_rsc::~a_gfx_rsc() { }
	// --setters
	// --core_methods
}
#endif
#endif	// NW_GAPI