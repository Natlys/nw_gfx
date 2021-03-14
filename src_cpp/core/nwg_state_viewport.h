#ifndef NW_VIEWPORT_STATE_H
#define NW_VIEWPORT_STATE_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_state.h>
namespace NW
{
	/// state_viewport class
	class NW_API state_viewport : public a_gfx_state, public t_gfx_rsc<state_viewport>
	{
	public:
		state_viewport(gfx_engine& graphics);
		~state_viewport();
		// --getters
#if (NW_GAPI & NW_GAPI_OGL)
#endif
#if (NW_GAPI & NW_GAPI_DX)
#endif
		// --setters
		// --core_methods
		virtual void on_draw() override;
	private:
		v2si m_crd;
		v2si m_size;
#if (NW_GAPI & NW_GAPI_OGL)
#endif
#if (NW_GAPI & NW_GAPI_DX)
#endif
	};
}
#endif	// NW_GAPI
#endif	// NW_VIEWPORT_STATE_H