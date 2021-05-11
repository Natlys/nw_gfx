#include "nc_gfx_pch.hpp"
#include "nc_gfx_mesh.h"
#if (defined NC_GAPI)
#	include "../../core/nc_nc_gfx_eng.h"
#	include "../../lib/nc_gfx_lib_core.h"
#	if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	gfx_mesh::gfx_mesh() :
		nc_cmp_tt(), gfx_cmp_t(), nc_iop_cmp_t(), nc_name_owner_t("mesh"),
		m_layt(cmp_sys::get().new_ref<gfx_layt_t>()),
		m_gmtl(cmp_sys::get().new_ref<gfx_mtl_t>())
	{
	}
	gfx_mesh::~gfx_mesh()
	{
		cmp_sys::get().del_ref<gfx_layt_t>(m_layt->get_idx());
		cmp_sys::get().del_ref<gfx_mtl_t>(m_gmtl->get_idx());
	}
	// setters //
	// operators //
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
					if (!get_layt()->get_layt().has_tree_type<v3f_t>()) {
						get_layt()->get_layt().add_node<v3f_t>("vsi_vtx_crd");
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
	// commands //
	v1nil_t gfx_mesh::on_draw()
	{
		m_gmtl->on_draw();
		m_layt->on_draw();
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
#	endif	// GAPI_D3D
#endif	// NC_GAPI