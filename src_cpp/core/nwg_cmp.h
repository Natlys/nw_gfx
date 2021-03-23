#ifndef NWG_COMPONENT_H
#define NWG_COMPONENT_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include "nwg_rsc.h"
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
		virtual void on_draw();
	};
}
#endif	// NW_GAPI
#endif	// NWG_COMPONENT_H