#ifndef NW_GFX_COMPONENT_H
#define NW_GFX_COMPONENT_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
namespace NW
{
	/// abstract graphics_component class
	class NW_API a_gfx_cmp
	{
	protected:
		a_gfx_cmp();
	public:
		virtual ~a_gfx_cmp();
		// --core_methods
		virtual v1nil on_draw() = 0;
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_COMPONENT_H
