#include <nwg_pch.hpp>
#include "nwg_drawable_vtx.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#if (NW_GAPI & NW_GAPI_OGL)
#include <lib/nwg_load_base.h>
namespace NW
{
	drawable_vtx::drawable_vtx(gfx_engine& graphics) :
		a_drawable(), t_gfx_res(graphics)
	{
	}
	drawable_vtx::~drawable_vtx() { }
	// --==<core_methods>==--
	void drawable_vtx::on_draw()
	{
		for (auto& irsc : m_rscs) {
			irsc->on_draw();
		}
		ui32 vtx_count = 0;
		for (auto& ibuf : m_vbufs) {
			vtx_count += ibuf->get_data_count();
			ibuf->on_draw();
		}
		glDrawArrays(convert_enum<gfx_primitives, GLenum>(m_gfx->get_configs().prim_type), 0, vtx_count);
	}
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
#endif
#endif	// NW_GAPI