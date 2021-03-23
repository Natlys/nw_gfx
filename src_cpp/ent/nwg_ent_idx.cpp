#include <nwg_pch.hpp>
#include "nwg_ent_idx.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#include <lib/nwg_load_core.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	ent_idx::ent_idx(gfx_engine& graphics) :
		a_gfx_ent(graphics)
	{
	}
	ent_idx::~ent_idx() { }
	// --==<core_methods>==--
	void ent_idx::on_draw()
	{
		a_gfx_ent::on_draw();
		
		m_ibuf->on_draw();
		glDrawElements(convert_enum<gfx_primitives, GLenum>(m_gfx->get_prim_type()),
			m_ibuf->get_data_count(), convert_enum<data_types, GLenum>(m_ibuf->get_data_type()), NULL);
	}
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	ent_idx::ent_idx(gfx_engine& graphics) :
		a_gfx_ent(graphics)
	{
	}
	ent_idx::~ent_idx() { }
	// --==<core_methods>==--
	void ent_idx::on_draw()
	{
		a_gfx_ent::on_draw();

		m_ibuf->on_draw();
		m_gfx->get_ctxh()->DrawIndexed(m_ibuf->get_data_count(), 0u, 0);
	}
}
#endif
#endif	// NW_GAPI