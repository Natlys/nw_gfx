#include <nwg_pch.hpp>
#include "nwg_drawable_idx.h"
#if (defined NWG_GAPI)
#include <core/nwg_engine.h>
#if (NWG_GAPI & NWG_GAPI_OGL)
#include <lib/nwg_load_base.h>
namespace NWG
{
	idx_drawable::idx_drawable(gfx_engine& graphics) :
		a_drawable(), t_gfx_res(graphics)
	{
	}
	idx_drawable::~idx_drawable() { }
	// --==<core_methods>==--
	void idx_drawable::on_draw()
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
#if (NWG_GAPI & NWG_GAPI_DX)
#endif
#endif	// NWG_GAPI