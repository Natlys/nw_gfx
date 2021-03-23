#ifndef NWG_STATE_H
#define NWG_STATE_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_cmp.h>
#include <lib/nwg_switch.h>
namespace NW
{
	class NW_API a_gfx_stt : public t_cmp<a_gfx_stt>, public a_gfx_cmp
	{
	public:
		a_gfx_stt(gfx_engine& graphics);
		virtual ~a_gfx_stt();
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
#endif	// NWG_STATE_H