#ifndef NW_GFX_FRAMEBUFFER_STENCIL_H
#define NW_GFX_FRAMEBUFFER_STENCIL_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_fmbuf_part.h"
namespace NW
{
	/// graphics_framebuffer_stencil class
	class NW_API gfx_fmbuf_sten : public a_gfx_fmbuf_part
	{
	public:
#	if (NW_GAPI & NW_GAPI_OGL)
#	endif
#	if (NW_GAPI & NW_GAPI_D3D)
#	endif
	public:
		gfx_fmbuf_sten();
		virtual ~gfx_fmbuf_sten();
		// --getters
		// --setters
		// --predicates
		// --core_methods
		virtual v1bit remake() override;
		virtual v1nil clear(ptr_tc data) override;
		virtual v1nil on_draw() override;
	private:
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_FRAMEBUFFER_STENCIL_H