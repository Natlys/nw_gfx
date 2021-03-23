#include <nwg_pch.hpp>
#include "nwg_txr.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#include <lib/nwg_load_txr.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	a_txr::a_txr(gfx_engine& graphics) :
		img_cmp(), a_gfx_cmp(graphics),
		m_handle(0u),
		m_slot(0u),
		m_txr_fmt(TXF_RGBA),
		m_smp(smp())
	{
	}
	a_txr::~a_txr() { if (m_handle != 0) { glDeleteTextures(1, &m_handle); m_handle = 0; } }
	// --setters
	void a_txr::set_slot(ui8 slot) {
		m_slot = slot;
		m_smp->set_slot(slot);
	}
	void a_txr::set_smp(smp& ref) {
		m_smp = ref;
	}
	// --==<core_methods>==--
	void a_txr::on_draw() {
		m_smp->set_slot(m_slot);
		m_smp->on_draw();
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	a_txr::a_txr(gfx_engine& graphics) :
		img_cmp(), a_gfx_cmp(graphics),
		m_handle(nullptr),
		m_slot(0),
		m_txr_fmt(TXF_RGBA),
		m_smp(smp())
	{
	}
	a_txr::~a_txr()
	{
		if (m_handle != nullptr) { m_handle->Release(); m_handle = nullptr; }
	}
	// --setters
	void a_txr::set_slot(ui8 slot) {
		m_slot = slot;
		m_smp->set_slot(slot);
	}
	void a_txr::set_smp(smp& ref) {
		m_smp = ref;
	}
	// --==<core_methods>==--
	void a_txr::on_draw() {
		m_smp->set_slot(m_slot);
		m_smp->on_draw();
	}
	// --==</core_methods>==--
}
#endif
#endif	// NW_GAPI