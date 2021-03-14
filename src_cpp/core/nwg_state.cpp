#include <nwg_pch.hpp>
#include "nwg_state.h"
#if (defined NW_GAPI)
#if (NW_GAPI & NW_GAPI_OGL)
#include <lib/nwg_load_base.h>
namespace NW
{
	a_gfx_state::a_gfx_state() :
		m_is_enabled(true)
	{
	}
	a_gfx_state::~a_gfx_state() { }
	// --setters
	void a_gfx_state::set_enabled(bit enable) { m_is_enabled = enable; }
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	//
}
#endif
#endif	// NW_GAPI