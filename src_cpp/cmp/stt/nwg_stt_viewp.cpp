#include <nwg_pch.hpp>
#include "nwg_stt_viewp.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#include <lib/nwg_load_core.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	stt_viewp::stt_viewp(gfx_engine& graphics) :
		a_gfx_stt(graphics),
		m_crd{ 0, 0 }, m_size{ 800, 600 }
	{
	}
	stt_viewp::~stt_viewp() { }
	// --setters
	void stt_viewp::set_coord(v2si coord) {
		m_crd = coord;
	}
	void stt_viewp::set_size(v2si size) {
		m_size = size;
	}
	// --==<core_methods>==--
	void stt_viewp::on_draw()
	{
		if (!m_is_enabled) { return; }
		glViewport(m_crd[0], m_crd[0], m_size[0], m_size[1]);
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	stt_viewp::stt_viewp(gfx_engine& graphics) :
		a_gfx_stt(graphics),
		m_crd{ 0, 0 }, m_size{ 800, 600 }
	{
	}
	stt_viewp::~stt_viewp() { }
	// --setters
	void stt_viewp::set_coord(v2si coord) {
		m_crd = coord;
	}
	void stt_viewp::set_size(v2si size) {
		m_size = size;
	}
	// --==<core_methods>==--
	void stt_viewp::on_draw()
	{
		if (!m_is_enabled) { return; }
		D3D11_VIEWPORT dx_viewport = { 0 };
		dx_viewport.TopLeftX = m_crd[0];
		dx_viewport.TopLeftY = m_crd[1];
		dx_viewport.Width = m_size[0];
		dx_viewport.Height = m_size[1];
		dx_viewport.MinDepth = 0.01f;
		dx_viewport.MaxDepth = 1.00f;
		m_gfx->get_ctxh()->RSSetViewports(1, &dx_viewport);
	}
	// --==</core_methods>==--
}
#endif
#endif	// NW_GAPI