#ifndef NWG_STATE_H
#define NWG_STATE_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <core/nwg_res.h>
namespace NWG
{
	class NWG_API a_gfx_state : public a_gfx_res
	{
	public:
		a_gfx_state(gfx_engine& graphics);
		virtual ~a_gfx_state();
		// --getters
		// --setters
	private:
	};
}
#endif	// NWG_GAPI
#endif	// NWG_STATE_H