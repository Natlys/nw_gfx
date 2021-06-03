#ifndef NC_GFX_MODE_BLENDING_H
#define NC_GFX_MODE_BLENDING_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#   include "../nc_gfx_cmp.hxx"
#   include "nc_gfx_mode.hxx"
namespace NC
{
    /// graphics_state_blending_type
    class gfx_state_blend_t : public nc_cmp_tt<gfx_state_blend_t>, public gfx_mode_t
    {
    public:
        using blend_t = gfx_state_blend_t;
        using blend_tc = const blend_t;
#   if (NC_GAPI & NC_GAPI_OGL)
        using handle_t = GLuint;
#   endif   // GAPI_OGL
#   if (NC_GAPI & NC_GAPI_D3D)
        using handle_tc = ptr_t;
#   endif   // GAPI_D3D
        using handle_tc = const handle_t;
    public:
        /* ctor_dtor */
        gfx_state_blend_t();
        gfx_state_blend_t(blend_tc& copy);
        gfx_state_blend_t(blend_t&& copy);
        virtual ~gfx_state_blend_t();
        /* getters */
        inline handle_t get_handle() { return m_handle; }
        /* setters */
        /* vetters */
        /* operators */
        inline blend_t& operator=(blend_tc& copy) { gfx_mode_t::operator=(copy); return *this; }
        inline blend_t& operator=(blend_t&& copy) { gfx_mode_t::operator=(copy); return *this; }
        /* commands */
        virtual v1bit_t remake() override;
        virtual v1nil_t on_draw() override;
    protected:
        handle_t m_handle;
    };
}
#endif	// NC_GAPI
#endif	// NC_GFX_MODE_BLENDING_H
