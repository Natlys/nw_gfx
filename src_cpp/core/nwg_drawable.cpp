#include <nwg_pch.hpp>
#include "nwg_drawable.h"
#if (defined NWG_GAPI)
#include <core/nwg_engine.h>
#if (NWG_GAPI & NWG_GAPI_OGL)
#include <lib/nwg_ogl_v1.h>
namespace NWG
{
	a_drawable::a_drawable(gfx_engine& graphics) :
		m_gfx(&graphics), m_order(0) { m_gfx->get_registry()[get_ent_id()]; }
	a_drawable::~a_drawable() { m_gfx->get_registry().erase(get_ent_id()); }
	// --getters
	a_drawable::cmps& a_drawable::get_cmps() { return m_gfx->get_registry()[get_ent_id()]; }
	a_drawable::cmp_ref& a_drawable::get_cmp(ui32 type_id) { return m_gfx->get_cmp(get_ent_id(), type_id); }
	// --setters
	void a_drawable::set_order(ui8 order) { m_order = order; }
	void a_drawable::add_cmp(cmp_ref& ref) { m_gfx->get_cmps(get_ent_id())[ref->get_type_id()].set_ref(ref); }
	void a_drawable::rmv_cmp(ui32 type_id) { m_gfx->get_cmps(get_ent_id()).erase(type_id); }
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