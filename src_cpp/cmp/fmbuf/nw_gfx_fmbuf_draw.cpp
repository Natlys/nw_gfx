#include "nw_gfx_pch.hpp"
#include "nw_gfx_fmbuf_draw.h"
#if (defined NW_GAPI)
#	include "../../core/nw_gfx_engine.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_fmbuf_draw::gfx_fmbuf_draw() :
		a_gfx_fmbuf_part()
	{
	}
	gfx_fmbuf_draw::~gfx_fmbuf_draw()
	{
	}
	// --setters
	// --operators
	// --==<core_methods>==--
	v1nil gfx_fmbuf_draw::read_pixels(ptr_t data, cv4s& rect)
	{
		glReadBuffer(GL_COLOR_ATTACHMENT0 + get_slot());
		glReadPixels(rect[0], rect[1], rect[2], rect[3], get_format(), get_pxtype(), data);
	}
	v1nil gfx_fmbuf_draw::draw_pixels(ptr_tc data, cv4s& rect)
	{
		glDrawBuffer(GL_COLOR_ATTACHMENT0 + get_slot());
		glDrawPixels(rect[2], rect[3], get_format(), get_pxtype(), data);
	}
	v1bit gfx_fmbuf_draw::remake()
	{
		NW_CHECK(a_gfx_fmbuf_part::remake(), "failed remake!", return NW_FALSE);

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + get_slot(), GL_TEXTURE_2D, get_handle(), 0);

		return NW_TRUE;
	}
	v1nil gfx_fmbuf_draw::clear(ptr_tc data)
	{
		a_gfx_fmbuf_part::clear(data);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	v1nil gfx_fmbuf_draw::on_draw()
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