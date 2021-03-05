#ifndef NWG_STATE_H
#define NWG_STATE_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <core/nwg_cmp.h>
namespace NWG
{
	class NWG_API a_gfx_state : public a_gfx_cmp
	{
	public:
		a_gfx_state();
		virtual ~a_gfx_state();
		// --getters
		// --setters
	private:
	};
}
#endif	// NWG_GAPI
#endif	// NWG_STATE_H