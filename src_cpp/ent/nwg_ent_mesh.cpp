#include <nwg_pch.hpp>
#include "nwg_ent_mesh.h"
#if (defined NW_GAPI)
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	ent_mesh::ent_mesh(gfx_engine& graphics) :
		ent_idx(graphics), a_data_cmp()
	{
	}
	ent_mesh::~ent_mesh() { }
	// --getters
	// --setters
	// --operators
	stm_out& ent_mesh::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& ent_mesh::operator>>(stm_in& stm) {
		return stm;
	}
}
#endif
#endif	// NW_GAPI