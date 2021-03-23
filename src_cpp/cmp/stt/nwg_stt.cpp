#include <nwg_pch.hpp>
#include "nwg_stt.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#include <lib/nwg_load_core.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	a_gfx_stt::a_gfx_stt(gfx_engine& graphics) :
		t_cmp(), a_gfx_cmp(graphics),
		m_is_enabled(true)
	{
	}
	a_gfx_stt::~a_gfx_stt() { }
	// --setters
	void a_gfx_stt::set_enabled(bit enable) {
		m_is_enabled = enable;
	}
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	a_gfx_stt::a_gfx_stt(gfx_engine& graphics) :
		t_cmp(), a_gfx_cmp(graphics),
		m_is_enabled(true)
	{
	}
	a_gfx_stt::~a_gfx_stt() { }
	// --setters
	void a_gfx_stt::set_enabled(bit enable) {
		m_is_enabled = enable;
	}
}
#endif
#endif	// NW_GAPI