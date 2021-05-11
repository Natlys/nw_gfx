#include "nc_gfx_pch.hpp"
#include "nc_gfx_tform_obj.h"
#if (defined NC_GAPI)
#	include "../../core/nc_nc_gfx_eng.h"
namespace NC
{
	gfx_tform_obj::gfx_tform_obj() : gfx_tform()
	{
		set_layt(layt_tc("tform_obj", layt_t::elem_list_tc
			{
				mem_layt_t("modl", type_info_t::get_type<m4x4f>()),
			}
		)).set_count(1u);
	}
	gfx_tform_obj::gfx_tform_obj(obj_tc& copy) : gfx_tform_obj() { operator=(copy); }
	gfx_tform_obj::gfx_tform_obj(obj_t&& copy) : gfx_tform_obj() { operator=(copy); }
	gfx_tform_obj::~gfx_tform_obj() { }
	// setters //
	// operators //
	// commands //
	v1bit_t gfx_tform_obj::remake()
	{
		NC_CHECK(gfx_tform::remake(), "remake error!", return NC_FALSE);

		return NC_TRUTH;
	}
	v1nil_t gfx_tform_obj::on_draw()
	{
		gfx_tform::on_draw();
		set_modl( m4x4f::make_coord(get_crd()) * m4x4f::make_rotat_xyz(get_rtn()) * m4x4f::make_scale(get_scl()));
	}
	// --==</core_methods>==--
}
#endif	// NC_GAPI