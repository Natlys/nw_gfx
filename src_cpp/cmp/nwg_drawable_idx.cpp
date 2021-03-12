#include <nwg_pch.hpp>
#include "nwg_drawable_idx.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#if (NW_GAPI & NW_GAPI_OGL)
#include <lib/nwg_load_base.h>
namespace NW
{
	drawable_idx::drawable_idx(gfx_engine& graphics) :
		a_drawable(), t_gfx_res(graphics)
	{
	}
	drawable_idx::~drawable_idx() { }
	// --==<core_methods>==--
	void drawable_idx::on_draw()
	{
		for (auto irsc : m_rscs) {
			irsc->on_draw();
		}
		m_ibuf->on_draw();
		glDrawElements(convert_enum<gfx_primitives, GLenum>(m_gfx->get_configs().prim_type),
			m_ibuf->get_data_count(), convert_enum<data_types, GLenum>(m_ibuf->get_data_type()), NULL);
	}
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
#endif
#endif	// NW_GAPI