#ifndef NW_GFX_STATE_H
#define NW_GFX_STATE_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
namespace NW
{
    /// graphics_context_state struct
    /// automatically backups and restores graphical state
    struct gfx_state
    {
    public:
        gfx_state();
        ~gfx_state();
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