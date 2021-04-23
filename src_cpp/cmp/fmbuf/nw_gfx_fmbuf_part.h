#ifndef NW_GFX_FRAMEBUFFER_PART_H
#define NW_GFX_FRAMEBUFFER_PART_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "../txr/nw_gfx_txr_2d.h"
namespace NW
{
	class NW_API a_gfx_fmbuf_part : public gfx_txr_2d
	{
	public:
		a_gfx_fmbuf_part();
		virtual ~a_gfx_fmbuf_part();
		// --getters
		// --setters
		// --operators
		// --core_methods
		virtual v1bit remake() override;
		virtual v1nil clear(ptr_tc data = NW_NULL) override;
		virtual v1nil on_draw() override;
	protected:
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_FRAMEBUFFER_PART_H