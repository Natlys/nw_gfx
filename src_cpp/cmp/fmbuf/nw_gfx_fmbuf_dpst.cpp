#include "nw_gfx_pch.hpp"
#include "nw_gfx_fmbuf_dpst.h"
#if (defined NW_GAPI)
#	include "../../core/nw_gfx_engine.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_fmbuf_dpst::gfx_fmbuf_dpst() :
		a_gfx_fmbuf_part()
	{
	}
	gfx_fmbuf_dpst::~gfx_fmbuf_dpst()
	{
	}
	// --setters
	// --operators
	// --==<core_methods>==--
	v1bit gfx_fmbuf_dpst::remake()
	{
		NW_CHECK(a_gfx_fmbuf_part::remake(), "remake error!", return NW_FALSE);
		
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, get_handle(), 0);

		return NW_TRUE;
	}
	v1nil gfx_fmbuf_dpst::clear(ptr_tc data)
	{
		a_gfx_fmbuf_part::clear(data);
		glClear(GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}
	v1nil gfx_fmbuf_dpst::on_draw()
	{
		a_gfx_fmbuf_part::on_draw();
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
}
#	endif	// GAPI_D3D
#endif	// NW_GAPI