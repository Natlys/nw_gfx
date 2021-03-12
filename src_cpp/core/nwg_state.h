#ifndef NW_STATE_H
#define NW_STATE_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_rsc.h>
#include <lib/nwg_switch.h>
namespace NW
{
	class NW_API a_gfx_state
	{
	public:
		a_gfx_state();
		virtual ~a_gfx_state();
		// --getters
		// --setters
	private:
	};
}
#endif	// NW_GAPI
#endif	// NW_STATE_H