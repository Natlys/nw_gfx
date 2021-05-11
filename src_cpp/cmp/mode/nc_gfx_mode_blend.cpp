#include "nc_gfx_pch.hpp"
#include "nc_gfx_mode_blend.h"
#if (defined NC_GAPI)
#   include "../../core/nc_nc_gfx_eng.h"
#   if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
    gfx_state_blend_t::gfx_state_blend_t() : gfx_mode_t() { }
    gfx_state_blend_t::gfx_state_blend_t(blend_tc& copy) : gfx_state_blend_t() { operator=(copy); }
    gfx_state_blend_t::gfx_state_blend_t(blend_t&& copy) : gfx_state_blend_t() { operator=(copy); }
    gfx_state_blend_t::~gfx_state_blend_t() { }
    // setters //
    // operators //
    // commands //
    v1bit_t gfx_state_blend_t::remake()
    {
        NC_CHECK(gfx_mode_t::remake(), "remake error!", return NC_FALSE);
        
        return NC_TRUTH;
    }
    v1nil_t gfx_state_blend_t::on_draw()
    {
        gfx_mode_t::on_draw();
    }
    // --==</core_methods>==--
}
#	endif	// GAPI_OGL
#   if (NC_GAPI & NC_GAPI_D3D)
namespace NC
{
}
#	endif	// GAPI_D3D
#endif	// NC_GAPI