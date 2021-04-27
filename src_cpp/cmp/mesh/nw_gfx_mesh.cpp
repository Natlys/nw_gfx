#include "nw_gfx_pch.hpp"
#include "nw_gfx_mesh.h"
#if (defined NW_GAPI)
#	include "../../core/nw_gfx_engine.h"
#	include "../../lib/nw_gfx_lib_core.h"
#	include "../../lib/nw_gfx_lib_buf.h"
#	include "../../lib/nw_gfx_lib_mtl.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_mesh::gfx_mesh() :
		t_cmp(), a_gfx_cmp(), a_iop_cmp(), a_name_owner("mesh"),
		m_layt(cmp_sys::get().new_ref<gfx_buf_layt>()),
		m_gmtl(cmp_sys::get().new_ref<gfx_mtl>())
	{
	}
	gfx_mesh::~gfx_mesh()
	{
		cmp_sys::get().del_ref<gfx_buf_layt>(m_layt->get_idx());
		cmp_sys::get().del_ref<gfx_mtl>(m_gmtl->get_idx());
	}
	// --setters
	// --operators
	op_stream_t& gfx_mesh::operator<<(op_stream_t& stm) const {
		return stm;
	}
	ip_stream_t& gfx_mesh::operator>>(ip_stream_t& stm) {
		dstr_t word;
		while (stm >> word) {
			if (word == "mtllib") { // material file is found;
				stm >> word;
				// 
			}
			if (word == "g") { // name is found;
				if (has_name("mesh")) { // the name is not set;
					stm >> word;
					this->set_name(&word[0]);
				}
				else { break; }
			}
			else if (word == "usemtl") { // material name is found;
				stm >> word;
				// m_gmtl->set_name(&word[0]);
			}
			else if (word[0] == 'v') { // vertex data processing;
				if (word == "v") { // vertex coordinate;
					if (!get_layt()->get_layt().has_tree_type<v3f>()) {
						get_layt()->get_layt().add_node<v3f>("vsi_vtx_crd");
						get_layt()->remake();
					}
				}
			}
			// index data processing;
			else if (word == "f") {
			}
		}
		return stm;
	}
	// --==<core_methods>==--
	v1nil gfx_mesh::on_draw()
	{
		m_gmtl->on_draw();
		m_layt->on_draw();
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
#	endif	// GAPI_D3D
#endif	// NW_GAPI