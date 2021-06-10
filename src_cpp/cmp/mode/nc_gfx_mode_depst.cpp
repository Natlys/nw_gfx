#include "nc_gfx_pch.hpp"
#include "nc_gfx_mode_depst.hxx"
#if (defined NC_GAPI)
#   include "../../core/nc_nc_gfx_eng.hxx"
#   if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
    gfx_mode_depst_t::gfx_mode_depst_t() : gfx_mode_t(), m_is_enabled_dept(NC_TRUTH), m_is_enabled_sten(NC_TRUTH) { }
    gfx_mode_depst_t::gfx_mode_depst_t(v1bit_t enable_dept, v1bit_t enable_sten) : gfx_mode_depst_t() { NC_CHECK(remake(enable_dept, enable_sten), "remake error!", return); }
    gfx_mode_depst_t::gfx_mode_depst_t(depst_tc& copy) : gfx_mode_depst_t() { operator=(copy); }
    gfx_mode_depst_t::gfx_mode_depst_t(depst_t&& copy) : gfx_mode_depst_t() { operator=(copy); }
    gfx_mode_depst_t::~gfx_mode_depst_t() { }
    /* setters */
    gfx_mode_depst_t::depst_t& gfx_mode_depst_t::set_enabled_dept(v1bit_t enable) { m_is_enabled_dept = enable; return *this; }
    gfx_mode_depst_t::depst_t& gfx_mode_depst_t::set_enabled_sten(v1bit_t enable) { m_is_enabled_sten = enable; return *this; }
    /* operators */
    /* command */
    v1bit_t gfx_mode_depst_t::remake()
    {
        NC_CHECK(gfx_mode_t::remake(), "remake error!", return NC_FALSE);
        
        return NC_TRUTH;
    }
    v1nil_t gfx_mode_depst_t::on_draw()
    {
        gfx_mode_t::on_draw();

        if (m_is_enabled_dept) { get_context()->set_enabled(GL_DEPTH_TEST); }
        else { get_context()->set_disabled(GL_DEPTH_TEST); }
        if (m_is_enabled_sten) { get_context()->set_enabled(GL_STENCIL_TEST); }
        else { get_context()->set_disabled(GL_STENCIL_TEST); }
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