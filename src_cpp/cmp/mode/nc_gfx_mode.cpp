#include "nc_gfx_pch.hpp"
#include "nc_gfx_mode.h"
#if (defined NC_GAPI)
#   include "../../core/nc_nc_gfx_eng.h"
#   if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
    // ctor_dtor //
    gfx_mode_t::gfx_mode_t() : gfx_cmp_t() { }
    gfx_mode_t::gfx_mode_t(mode_tc& copy) : gfx_mode_t() { operator=(copy); }
    gfx_mode_t::gfx_mode_t(mode_t&& copy) : gfx_mode_t() { operator=(copy); }
    gfx_mode_t::~gfx_mode_t() { }
    // setters //
    // operators //
    // commands //
    v1bit_t gfx_mode_t::remake() { return NC_TRUTH; }
    v1nil_t gfx_mode_t::on_draw() { }
    // --==</core_methods>==--
}
#   endif   // GAPI_OGL
#   if (NC_GAPI & NC_GAPI_D3D)
namespace NC
{
    // ctor_dtor //
    gfx_mode_t::gfx_mode_t() : gfx_cmp_t() { }
    gfx_mode_t::gfx_mode_t(mode_tc& copy) : gfx_mode_t() { operator=(copy); }
    gfx_mode_t::gfx_mode_t(mode_t&& copy) : gfx_mode_t() { operator=(copy); }
    gfx_mode_t::~gfx_mode_t() { }
    // setters //
    // operators //
    // commands //
    v1bit_t gfx_mode_t::remake() { return NC_TRUTH; }
    v1nil_t gfx_mode_t::on_draw() { }
    // --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NC_GAPI