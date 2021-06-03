#ifndef NC_GFX_FRAMEBUFFER_STENCIL_H
#define NC_GFX_FRAMEBUFFER_STENCIL_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "nc_gfx_fmbuf_part.hxx"
namespace NC
{
	/// graphics_framebuffer_stencil_type
	class gfx_fmbuf_sten_t : public gfx_fmbuf_part_t
	{
	public:
#	if (NC_GAPI & NC_GAPI_OGL)
#	endif
#	if (NC_GAPI & NC_GAPI_D3D)
#	endif
	public:
		gfx_fmbuf_sten_t();
		virtual ~gfx_fmbuf_sten_t();
		/* getters */
		/* setters */
		/* vetters */
		/* commands */
		virtual v1bit_t remake() override;
		virtual v1nil_t clear(ptr_tc data) override;
		virtual v1nil_t on_draw() override;
	private:
	};
}
#endif	// NC_GAPI
#endif	// NC_GFX_FRAMEBUFFER_STENCIL_H