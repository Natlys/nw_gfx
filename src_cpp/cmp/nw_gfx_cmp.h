#ifndef NW_GFX_COMPONENT_H
#define NW_GFX_COMPONENT_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#include "core/nw_gfx_rsc.h"
namespace NW
{
	/// abstract graphics_component class
	class NW_API a_gfx_cmp : public a_gfx_rsc
	{
	protected:
		a_gfx_cmp(gfx_engine& graphics);
	public:
		virtual ~a_gfx_cmp();
		// --core_methods
		virtual v1nil on_draw();
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_COMPONENT_H
