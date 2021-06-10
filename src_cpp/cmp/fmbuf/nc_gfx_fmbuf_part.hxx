#ifndef NC_GFX_FRAMEBUFFER_PART_H
#define NC_GFX_FRAMEBUFFER_PART_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "../txr/nc_gfx_txr_2d.hxx"
namespace NC
{
	/// graphics_framebuffer_part_type
	class gfx_fmbuf_part_t : public gfx_txr2d_t
	{
	public:
		gfx_fmbuf_part_t();
		virtual ~gfx_fmbuf_part_t();
		/* getters */
		/* setters */
		/* operators */
		/* command */
		virtual v1bit_t remake() override;
		virtual v1nil_t clear(ptr_tc data = NC_NULL) override;
		virtual v1nil_t on_draw() override;
	protected:
	};
}
#endif	// NC_GAPI
#endif	// NC_GFX_FRAMEBUFFER_PART_H