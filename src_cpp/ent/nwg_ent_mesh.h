#ifndef NWG_MESH_ENTITY_H
#define NWG_MESH_ENTITY_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include "nwg_ent_idx.h"
#include <lib/nwg_data.h>
namespace NW
{
	class NW_API ent_mesh : public ent_idx, public a_data_cmp
	{
	public:
		ent_mesh(gfx_engine& graphics);
		~ent_mesh();
		// --getters
		// --setters
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const override;
		virtual stm_in& operator>>(stm_in& stm) override;
		// --core_methods
	};
}
#endif	// NW_GAPI
#endif	// NWG_MESH_ENTITY_H