#include <nwg_pch.hpp>
#include "nwg_state_depth.h"
#if (defined NW_GAPI)
#if (NW_GAPI & NW_GAPI_OGL)
#include <lib/nwg_load_base.h>
#include <lib/nwg_load_fbuf.h>
namespace NW
{
	state_depth::state_depth(gfx_engine& graphics) :
		t_gfx_rsc(graphics),
		m_is_mask_enabled(true), m_function(DTC_LESS)
	{
	}
	state_depth::~state_depth() { }
	// --setters
	void state_depth::set_mask_enabled(bit enable) {
		m_is_mask_enabled = enable;
	}
	void state_depth::set_function(depth_configs function) {
		m_function = function;
	}
	// --==<core_methods>==--
	void state_depth::on_draw()
	{
		if (m_is_enabled) { glEnable(GL_DEPTH_TEST); }
		else { glDisable(GL_DEPTH_TEST); return; }
		glDepthMask(m_is_mask_enabled ? GL_TRUE : GL_FALSE);
		glDepthFunc(convert_enum<depth_configs, GLenum>(m_function));
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
#endif
#endif	// NW_GAPI