#include "nc_gfx_pch.hpp"
#include "nc_gfx_mode_rastr.hxx"
#if (defined NC_GAPI)
#   include "../../core/nc_nc_gfx_eng.hxx"
#   if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
    gfx_mode_rastr_t::gfx_mode_rastr_t() : gfx_mode_t() { }
    gfx_mode_rastr_t::gfx_mode_rastr_t(rastr_tc& copy) : gfx_mode_rastr_t() { operator=(copy); }
    gfx_mode_rastr_t::gfx_mode_rastr_t(rastr_t&& copy) : gfx_mode_rastr_t() { operator=(copy); }
    gfx_mode_rastr_t::~gfx_mode_rastr_t() { }
    /* setters */
    /* operators */
    /* command */
    v1bit_t gfx_mode_rastr_t::remake()
    {
        NC_CHECK(gfx_mode_t::remake(), "remake error!", return NC_FALSE);
        
        return NC_TRUTH;
    }
    v1nil_t gfx_mode_rastr_t::on_draw()
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