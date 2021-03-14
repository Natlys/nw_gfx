#ifndef NW_GRAPHICS_STATE_H
#define NW_GRAPHICS_STATE_H
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
		void set_enabled(bit enable);
		// --predicates
		inline bit is_enabled() const { return m_is_enabled; }
	protected:
		bit m_is_enabled;
	};
}
#endif	// NW_GAPI
#endif	// NW_GRAPHICS_STATE_H