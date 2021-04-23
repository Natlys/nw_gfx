#ifndef NW_GFX_FRAMEBUFFER_DRAW_H
#define NW_GFX_FRAMEBUFFER_DRAW_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_fmbuf_part.h"
namespace NW
{
	/// graphics_framebuffer_draw class
	class NW_API gfx_fmbuf_draw : public a_gfx_fmbuf_part
	{
	public:
#	if (NW_GAPI & NW_GAPI_OGL)
#	endif
#	if (NW_GAPI & NW_GAPI_D3D)
#	endif
	public:
		gfx_fmbuf_draw();
		virtual ~gfx_fmbuf_draw();
		// --getters
		// --setters
		// --predicates
		// --core_methods
		v1nil read_pixels(ptr_t data, cv4s& rect);
		v1nil draw_pixels(ptr_tc data, cv4s& rect);
		virtual v1bit remake() override;
		virtual v1nil clear(ptr_tc data = NW_NULL) override;
		virtual v1nil on_draw() override;
	private:
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_FRAMEBUFFER_DRAW_H