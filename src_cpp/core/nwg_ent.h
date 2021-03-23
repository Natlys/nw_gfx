#ifndef NWG_ENTITY_H
#define NWG_ENTITY_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include "core/nwg_cmp.h"
namespace NW
{
	/// abstract graphics_entity class
	class NW_API a_gfx_ent : public t_ent<a_gfx_ent, a_gfx_cmp>, public a_gfx_rsc
	{
	protected:
		a_gfx_ent(gfx_engine& graphics);
	public:
		virtual ~a_gfx_ent();
		// --core_methods
		virtual void on_draw();
	};
}
#endif	// NW_GAPI
#endif	// NWG_ENTITY_H