#ifndef NC_GFX_MODE_DEPTH_STENCIL_H
#define NC_GFX_MODE_DEPTH_STENCIL_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#   include "../nc_gfx_cmp.h"
#   include "nc_gfx_mode.h"
namespace NC
{
    /// graphics_state_depth_stencil_type
    class NC_API gfx_mode_depst_t : public nc_cmp_tt<gfx_mode_depst_t>, public gfx_mode_t
    {
    public:
        using depst_t = gfx_mode_depst_t;
        using depst_tc = const depst_t;
#   if (NC_GAPI & NC_GAPI_OGL)
        using handle_t = GLuint;
#   endif   // GAPI_OGL
#   if (NC_GAPI & NC_GAPI_D3D)
        using handle_tc = ptr_t;
#   endif   // GAPI_D3D
        using handle_tc = const handle_t;
    public:
        // ctor_dtor //
        gfx_mode_depst_t();
        gfx_mode_depst_t(v1bit_t enable_dept, v1bit_t enable_sten);
        gfx_mode_depst_t(depst_tc& copy);
        gfx_mode_depst_t(depst_t&& copy);
        virtual ~gfx_mode_depst_t();
        // getters //
        inline handle_t get_handle() { return m_handle; }
        // setters //
        depst_t& set_enabled_dept(v1bit_t enable);
        depst_t& set_enabled_sten(v1bit_t enable);
        // predicates //
        inline v1bit_t is_enabled_dept() const { return m_is_enabled_dept; }
        inline v1bit_t is_enabled_sten() const { return m_is_enabled_sten; }
        // operators //
        inline depst_t& operator=(depst_tc& copy) { gfx_mode_t::operator=(copy); return *this; }
        inline depst_t& operator=(depst_t&& copy) { gfx_mode_t::operator=(copy); return *this; }
        // commands //
        virtual v1bit_t remake() override;
        inline v1bit_t remake(v1bit_t enable_dept, v1bit_t enable_sten) { set_enabled_dept(enable_dept).set_enabled_sten(enable_sten); return remake(); }
        virtual v1nil_t on_draw() override;
    protected:
        handle_t m_handle;
        v1bit_t m_is_enabled_dept;
        v1bit_t m_is_enabled_sten;
    };
}
#endif	// NC_GAPI
#endif	// NC_GFX_MODE_DEPTH_STENCIL_H
