#ifndef NW_DEPTH_STATE_H
#define NW_DEPTH_STATE_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_state.h>
namespace NW
{
	/// state_depth class
	class NW_API state_depth : public a_gfx_state, public t_gfx_rsc<state_depth>
	{
	public:
		state_depth(gfx_engine& graphics);
		~state_depth();
		// --getters
		inline depth_configs get_function() const	{ return m_function; }
#if (NW_GAPI & NW_GAPI_OGL)
#endif
#if (NW_GAPI & NW_GAPI_DX)
#endif
		// --setters
		void set_mask_enabled(bit enable);
		void set_function(depth_configs function);
		// --predicates
		inline bit is_mask_enabled() const			{ return m_is_mask_enabled; }
		// --core_methods
		virtual void on_draw() override;
	private:
		depth_configs m_function;
		bit m_is_mask_enabled;
#if (NW_GAPI & NW_GAPI_OGL)
#endif
#if (NW_GAPI & NW_GAPI_DX)
#endif
	};
}
#endif	// NW_GAPI
#endif	// NW_DEPTH_STATE_H