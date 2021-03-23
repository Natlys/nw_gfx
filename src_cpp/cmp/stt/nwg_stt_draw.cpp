#include <nwg_pch.hpp>
#include "nwg_stt_draw.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#include <lib/nwg_load_core.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	stt_draw::stt_draw(gfx_engine& graphics) :
		a_gfx_stt(graphics),
		m_prim(GPT_TRIANGLES)
	{
	}
	stt_draw::~stt_draw() { }
	// --setters
	// --==<core_methods>==--
	void stt_draw::on_draw()
	{
		if (!m_is_enabled) { return; }
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	stt_draw::stt_draw(gfx_engine& graphics) :
		a_gfx_stt(graphics),
		m_prim(GPT_TRIANGLES)
	{
	}
	stt_draw::~stt_draw() { }
	// --setters
	void stt_draw::set_primitive(gfx_primitives primitive_topology) {
		m_prim = static_cast<gfx_primitives>(primitive_topology);
	}
	// --==<core_methods>==--
	void stt_draw::on_draw()
	{
		if (!m_is_enabled) { return; }
		m_gfx->get_ctxh()->IASetPrimitiveTopology(convert_enum<gfx_primitives, D3D11_PRIMITIVE_TOPOLOGY>(m_prim));
	}
	// --==</core_methods>==--
}
#endif
#endif	// NW_GAPI