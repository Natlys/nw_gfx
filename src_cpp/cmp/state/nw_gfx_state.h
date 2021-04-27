#ifndef NW_GFX_STATE_H
#define NW_GFX_STATE_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#   include "../nw_gfx_cmp.h"
namespace NW
{
    /// graphics_state class
    class NW_API gfx_state : public a_gfx_cmp
    {
    public:
        using state_t = gfx_state;
        using state_tc = const state_t;
#   if (NW_GAPI & NW_GAPI_OGL)
#   endif   // GAPI_OGL
#   if (NW_GAPI & NW_GAPI_D3D)
#   endif   // GAPI_D3D
    public:
        gfx_state();
        gfx_state(state_tc& copy);
        gfx_state(state_t&& copy);
        virtual ~gfx_state();
        // --getters
        // --setters
        // --predicates
        // --operators
        inline state_t& operator=(state_tc& copy) { return *this; }
        inline state_t& operator=(state_t&& copy) { return *this; }
        // --core_methods
        virtual v1bit remake();
        virtual v1nil on_draw() override;
    protected:
    };
}
namespace NW
{
    /// graphics_state_depth_stencil class
    class NW_API gfx_state_depst : public t_cmp<gfx_state_depst>, public gfx_state
    {
    public:
        using depst_t = gfx_state_depst;
        using depst_tc = const depst_t;
#   if (NW_GAPI & NW_GAPI_OGL)
        using handle_t = GLuint;
#   endif   // GAPI_OGL
#   if (NW_GAPI & NW_GAPI_D3D)
        using handle_tc = ptr_t;
#   endif   // GAPI_D3D
        using handle_tc = const handle_t;
    public:
        gfx_state_depst();
        gfx_state_depst(v1bit enable_dept, v1bit enable_sten);
        gfx_state_depst(depst_tc& copy);
        gfx_state_depst(depst_t&& copy);
        virtual ~gfx_state_depst();
        // --getters
        inline handle_t get_handle() { return m_handle; }
        // --setters
        depst_t& set_enabled_dept(v1bit enable);
        depst_t& set_enabled_sten(v1bit enable);
        // --predicates
        inline v1bit is_enabled_dept() const { return m_is_enabled_dept; }
        inline v1bit is_enabled_sten() const { return m_is_enabled_sten; }
        // --operators
        inline depst_t& operator=(depst_tc& copy) { gfx_state::operator=(copy); return *this; }
        inline depst_t& operator=(depst_t&& copy) { gfx_state::operator=(copy); return *this; }
        // --core_methods
        virtual v1bit remake() override;
        inline v1bit remake(v1bit enable_dept, v1bit enable_sten) { set_enabled_dept(enable_dept).set_enabled_sten(enable_sten); return remake(); }
        virtual v1nil on_draw() override;
    protected:
        handle_t m_handle;
        v1bit m_is_enabled_dept;
        v1bit m_is_enabled_sten;
    };
}
namespace NW
{
    /// graphics_state_raterizer class
    class NW_API gfx_state_rastr : public t_cmp<gfx_state_rastr>, public gfx_state
    {
    public:
        using rastr_t = gfx_state_rastr;
        using rastr_tc = const rastr_t;
#   if (NW_GAPI & NW_GAPI_OGL)
        using handle_t = GLuint;
#   endif   // GAPI_OGL
#   if (NW_GAPI & NW_GAPI_D3D)
        using handle_tc = ptr_t;
#   endif   // GAPI_D3D
    using handle_tc = const handle_t;
    public:
        gfx_state_rastr();
        gfx_state_rastr(rastr_tc& copy);
        gfx_state_rastr(rastr_t&& copy);
        virtual  ~gfx_state_rastr();
        // --getters
        inline handle_t get_handle() { return m_handle; }
        // --setters
        // --predicates
        // --operators
        inline rastr_t& operator=(rastr_tc& copy) { gfx_state::operator=(copy); return *this; }
        inline rastr_t& operator=(rastr_t&& copy) { gfx_state::operator=(copy); return *this; }
        // --core_methods
        virtual v1bit remake() override;
        virtual v1nil on_draw() override;
    protected:
        handle_t m_handle;
    };
}
namespace NW
{
    /// graphics_state_blending class
    class NW_API gfx_state_blend : public t_cmp<gfx_state_blend>, public gfx_state
    {
    public:
        using blend_t = gfx_state_blend;
        using blend_tc = const blend_t;
#   if (NW_GAPI & NW_GAPI_OGL)
        using handle_t = GLuint;
#   endif   // GAPI_OGL
#   if (NW_GAPI & NW_GAPI_D3D)
        using handle_tc = ptr_t;
#   endif   // GAPI_D3D
        using handle_tc = const handle_t;
    public:
        gfx_state_blend();
        gfx_state_blend(blend_tc& copy);
        gfx_state_blend(blend_t&& copy);
        virtual ~gfx_state_blend();
        // --getters
        inline handle_t get_handle() { return m_handle; }
        // --setters
        // --predicates
        // --operators
        inline blend_t& operator=(blend_tc& copy) { gfx_state::operator=(copy); return *this; }
        inline blend_t& operator=(blend_t&& copy) { gfx_state::operator=(copy); return *this; }
        // --core_methods
        virtual v1bit remake() override;
        virtual v1nil on_draw() override;
    protected:
        handle_t m_handle;
    };
}
namespace NW
{
    /// graphics_context_state struct
    /// automatically backups and restores graphical state
    struct NW_API gfx_state_context
    {
    public:
        gfx_state_context();
        ~gfx_state_context();
    public:
#   if (NW_GAPI & NW_GAPI_OGL)
        // shaders
        GLuint last_shd_prog;
        // textures
        GLenum last_active_txr;
        GLuint last_bound_txr;
        GLuint last_sampler;
        // vertexdata
        GLuint last_vbuf;
        GLuint last_varr;
        // rasterizer
        GLint last_viewport[4];
        GLint last_scissor_box[4];
        GLint last_poly_mode[2];
        // blending
        GLenum last_blend_src_rgb;
        GLenum last_blend_dst_rgb;
        GLenum last_blend_src_aplha;
        GLenum last_blend_dst_alpha;
        GLenum last_blend_eq_rgb;
        GLenum last_blend_eq_alpha;
        // enable flags
        GLboolean last_blending;
        GLboolean last_culling;
        GLboolean last_depth_test;
        GLboolean last_scissor_test;
#   endif   // GAPI_OGL
#   if (NW_GAPI & NW_GAPI_D3D)
        UINT                        ScissorRectsCount, ViewportsCount;
        D3D11_RECT                  ScissorRects[D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE];
        D3D11_VIEWPORT              Viewports[D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE];
        ID3D11RasterizerState* RS;
        ID3D11BlendState* BlendState;
        FLOAT                       BlendFactor[4];
        UINT                        SampleMask;
        UINT                        StencilRef;
        ID3D11DepthStencilState* DepthStencilState;
        ID3D11ShaderResourceView* PSShaderResource;
        ID3D11SamplerState* PSSampler;
        ID3D11PixelShader* PS;
        ID3D11VertexShader* VS;
        ID3D11GeometryShader* GS;
        UINT                        PSInstancesCount, VSInstancesCount, GSInstancesCount;
        ID3D11ClassInstance* PSInstances[256], * VSInstances[256], * GSInstances[256];   // 256 is max according to PSSetShader documentation
        D3D11_PRIMITIVE_TOPOLOGY    PrimitiveTopology;
        ID3D11Buffer* IndexBuffer, * VertexBuffer, * VSConstantBuffer;
        UINT                        IndexBufferOffset, VertexBufferStride, VertexBufferOffset;
        DXGI_FORMAT                 IndexBufferFormat;
        ID3D11InputLayout* input_layout;
#   endif   // GAPI_D3D
    };
}
#endif	// NW_GAPI
#endif	// NW_GFX_STATE_H