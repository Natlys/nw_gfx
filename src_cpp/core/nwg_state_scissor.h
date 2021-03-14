#ifndef NW_SCISSOR_STATE_H
#define NW_SCISSOR_STATE_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_state.h>
namespace NW
{
	/// scissor_state class
	class NW_API state_scissor : public a_gfx_state, public t_gfx_rsc<state_scissor>
	{
	public:
		state_scissor(gfx_engine& graphics);
		~state_scissor();
		// --getters
#if (NW_GAPI & NW_GAPI_OGL)
#endif
#if (NW_GAPI & NW_GAPI_DX)
#endif
		// --setters
		// --core_methods
		virtual void on_draw() override;
	private:
		v2si  m_crd;
		v2si m_size;
#if (NW_GAPI & NW_GAPI_OGL)
#endif
#if (NW_GAPI & NW_GAPI_DX)
#endif
	};
}
#endif	// NW_GAPI
#endif	// NW_SCISSOR_STATE_H