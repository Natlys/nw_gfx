#include <nwg_pch.hpp>
#include "nwg_ent_vtx.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#include <lib/nwg_load_core.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	ent_vtx::ent_vtx(gfx_engine& graphics) :
		a_gfx_ent(graphics)
	{
	}
	ent_vtx::~ent_vtx() { }
	// --setters
	void ent_vtx::add_vbuf(vbuf& ref) {
		m_vbufs.push_back(ref);
	}
	void ent_vtx::rmv_vbuf(ui8 idx) {
		m_vbufs.erase(m_vbufs.begin() + idx % m_vbufs.size());
	}
	// --==<core_methods>==--
	void ent_vtx::on_draw()
	{
		a_gfx_ent::on_draw();
		ui32 vtx_count = 0;
		for (auto& ibuf : m_vbufs) {
			vtx_count += ibuf->get_data_count();
			ibuf->on_draw();
		}
		glDrawArrays(convert_enum<gfx_primitives, GLenum>(m_gfx->get_prim_type()), 0, vtx_count);
	}
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	ent_vtx::ent_vtx(gfx_engine& graphics) :
		a_gfx_ent(graphics)
	{
	}
	ent_vtx::~ent_vtx() { }
	// --setters
	void ent_vtx::add_vbuf(vbuf& ref) {
		m_vbufs.push_back(ref);
	}
	void ent_vtx::rmv_vbuf(ui8 idx) {
		m_vbufs.erase(m_vbufs.begin() + idx % m_vbufs.size());
	}
	// --==<core_methods>==--
	void ent_vtx::on_draw()
	{
		a_gfx_ent::on_draw();
		ui32 vtx_count = 0;
		for (auto& ibuf : m_vbufs) {
			vtx_count += ibuf->get_data_count();
			ibuf->on_draw();
		}
		m_gfx->get_ctxh()->Draw(vtx_count, 0);
	}
}
#endif
#endif	// NW_GAPI