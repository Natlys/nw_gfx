#ifndef NC_GFX_MODE_H
#define NC_GFX_MODE_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#   include "../nc_gfx_cmp.h"
namespace NC
{
    /// graphics_state_type
    class NC_API gfx_mode_t : public gfx_cmp_t
    {
    public:
        using mode_t = gfx_mode_t;
        using mode_tc = const mode_t;
#   if (NC_GAPI & NC_GAPI_OGL)
#   endif // GAPI_OGL
#   if (NC_GAPI & NC_GAPI_D3D)
#   endif   // GAPI_D3D
    public:
        // ctor_dtor //
        gfx_mode_t();
        gfx_mode_t(mode_tc& copy);
        gfx_mode_t(mode_t&& copy);
        virtual ~gfx_mode_t();
        // getters //
        // setters //
        // predicates //
        // operators //
        inline mode_t& operator=(mode_tc& copy) { return *this; }
        inline mode_t& operator=(mode_t&& copy) { return *this; }
        // commands //
        virtual v1bit_t remake();
        virtual v1nil_t on_draw() override;
    protected:
    };
}
#endif	// NC_GAPI
#endif	// NC_GFX_MODE_H
