#ifndef NC_GFX_FRAMEBUFFER_DRAW_H
#define NC_GFX_FRAMEBUFFER_DRAW_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "nc_gfx_fmbuf_part.hxx"
namespace NC
{
	/// graphics_framebuffer_draw_type
	class gfx_fmbuf_draw_t : public gfx_fmbuf_part_t
	{
	public:
#	if (NC_GAPI & NC_GAPI_OGL)
#	endif
#	if (NC_GAPI & NC_GAPI_D3D)
#	endif
	public:
		gfx_fmbuf_draw_t();
		virtual ~gfx_fmbuf_draw_t();
		/* getters */
		/* setters */
		/* vetters */
		/* commands */
		v1nil_t read_pixels(ptr_t data, cv4s& rect);
		v1nil_t draw_pixels(ptr_tc data, cv4s& rect);
		virtual v1bit_t remake() override;
		virtual v1nil_t clear(ptr_tc data = NC_NULL) override;
		virtual v1nil_t on_draw() override;
	private:
	};
}
#endif	// NC_GAPI
#endif	// NC_GFX_FRAMEBUFFER_DRAW_H