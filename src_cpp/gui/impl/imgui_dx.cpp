#include <nwg_pch.hpp>
#include "imgui_dx.h"
#if (NWG_GAPI & NWG_GAPI_DX)
#include "../imgui_core.hpp"
#include <lib/nwg_dx_loader.h>
namespace GUI
{
    // directx data
    static ID3D11Device* s_pDevice = NULL;
    static ID3D11DeviceContext* s_pContext = NULL;
    static IDXGIFactory* s_pFactory = NULL;
    static ID3D11Buffer* s_pVtxBuf = NULL;
    static ID3D11Buffer* s_pIdxBuf = NULL;
    static ID3D11VertexShader* s_pVtxShader = NULL;
    static ID3D11input_layout* s_pInLayout = NULL;
    static ID3D11Buffer* s_pVtxCBuf = NULL;
    static ID3D11PixelShader* s_pPxlShader = NULL;
    static ID3D11SamplerState* s_pFontSampler = NULL;
    static ID3D11ShaderResourceView* s_pFontTextureView = NULL;
    static ID3D11RasterizerState* s_pRasterizerState = NULL;
    static ID3D11BlendState* s_pBlendState = NULL;
    static ID3D11DepthStencilState* s_pDepthStencilState = NULL;
    static int s_szVtx = 5000, s_szIdx = 10000;

    struct VERTEX_CONSTANT_BUFFER { float matMvp[4][4]; };

    // --==<forward_declarations>==--
    static void Dx11InitPlatformInterface();
    static void Dx11ShutdownPlatformInterface();
    // --==<forward_declarations>==--

    static void Dx11SetupRenderState(ImDrawData* draw_data, ID3D11DeviceContext* ctx)
    {
        // Setup viewport
        D3D11_VIEWPORT vp;
        memset(&vp, 0, sizeof(D3D11_VIEWPORT));
        vp.Width = draw_data->DisplaySize.x;
        vp.Height = draw_data->DisplaySize.y;
        vp.MinDepth = 0.0f;
        vp.MaxDepth = 1.0f;
        vp.TopLeftX = vp.TopLeftY = 0;
        ctx->RSSetViewports(1, &vp);

        // Setup shader and vertex buffers
        unsigned int stride = sizeof(ImDrawVert);
        unsigned int offset = 0;
        ctx->IASetinput_layout(s_pInLayout);
        ctx->IASetVertexBuffers(0, 1, &s_pVtxBuf, &stride, &offset);
        ctx->IASetIndexBuffer(s_pIdxBuf, sizeof(ImDrawIdx) == 2 ? DXGI_FORMAT_R16_UINT : DXGI_FORMAT_R32_UINT, 0);
        ctx->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        ctx->VSSetShader(s_pVtxShader, NULL, 0);
        ctx->VSSetConstantBuffers(0, 1, &s_pVtxCBuf);
        ctx->PSSetShader(s_pPxlShader, NULL, 0);
        ctx->PSSetSamplers(0, 1, &s_pFontSampler);
        ctx->GSSetShader(NULL, NULL, 0);
        ctx->HSSetShader(NULL, NULL, 0); // In theory we should backup and restore this as well.. very infrequently used..
        ctx->DSSetShader(NULL, NULL, 0); // In theory we should backup and restore this as well.. very infrequently used..
        ctx->CSSetShader(NULL, NULL, 0); // In theory we should backup and restore this as well.. very infrequently used..

        // Setup blend state
        const float blend_factor[4] = { 0.f, 0.f, 0.f, 0.f };
        ctx->OMSetBlendState(s_pBlendState, blend_factor, 0xffffffff);
        ctx->OMSetDepthStencilState(s_pDepthStencilState, 0);
        ctx->RSSetState(s_pRasterizerState);
    }

    // Render function
    // (this used to be set in io.RenderDrawListsFn and called by GUI::Render(), but you can now call this directly from your main loop)
    void Dx11RenderDrawData(ImDrawData* draw_data)
    {
        // Avoid rendering when minimized
        if (draw_data->DisplaySize.x <= 0.0f || draw_data->DisplaySize.y <= 0.0f)
            return;

        ID3D11DeviceContext* ctx = s_pContext;

        // Create and grow vertex/index buffers if needed
        if (!s_pVtxBuf || s_szVtx < draw_data->TotalVtxCount)
        {
            if (s_pVtxBuf) { s_pVtxBuf->Release(); s_pVtxBuf = NULL; }
            s_szVtx = draw_data->TotalVtxCount + 5000;
            D3D11_BUFFER_DESC desc;
            memset(&desc, 0, sizeof(D3D11_BUFFER_DESC));
            desc.Usage = D3D11_USAGE_DYNAMIC;
            desc.ByteWidth = s_szVtx * sizeof(ImDrawVert);
            desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
            desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
            desc.MiscFlags = 0;
            if (s_pDevice->CreateBuffer(&desc, NULL, &s_pVtxBuf) < 0) { return; }
        }
        if (!s_pIdxBuf || s_szIdx < draw_data->TotalIdxCount)
        {
            if (s_pIdxBuf) { s_pIdxBuf->Release(); s_pIdxBuf = NULL; }
            s_szIdx = draw_data->TotalIdxCount + 10000;
            D3D11_BUFFER_DESC desc;
            memset(&desc, 0, sizeof(D3D11_BUFFER_DESC));
            desc.Usage = D3D11_USAGE_DYNAMIC;
            desc.ByteWidth = s_szIdx * sizeof(ImDrawIdx);
            desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
            desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
            if (s_pDevice->CreateBuffer(&desc, NULL, &s_pIdxBuf) < 0) { return; }
        }

        // Upload vertex/index data into a single contiguous GPU buffer
        D3D11_MAPPED_SUBRESOURCE vtx_resource, idx_resource;
        if (ctx->Map(s_pVtxBuf, 0, D3D11_MAP_WRITE_DISCARD, 0, &vtx_resource) != S_OK) { return; }
        if (ctx->Map(s_pIdxBuf, 0, D3D11_MAP_WRITE_DISCARD, 0, &idx_resource) != S_OK) { return; }
        ImDrawVert* vtx_dst = (ImDrawVert*)vtx_resource.pData;
        ImDrawIdx* idx_dst = (ImDrawIdx*)idx_resource.pData;
        for (int n = 0; n < draw_data->CmdListsCount; n++) {
            const ImDrawList* cmd_list = draw_data->CmdLists[n];
            memcpy(vtx_dst, cmd_list->VtxBuffer.Data, cmd_list->VtxBuffer.Size * sizeof(ImDrawVert));
            memcpy(idx_dst, cmd_list->IdxBuffer.Data, cmd_list->IdxBuffer.Size * sizeof(ImDrawIdx));
            vtx_dst += cmd_list->VtxBuffer.Size;
            idx_dst += cmd_list->IdxBuffer.Size;
        }
        ctx->Unmap(s_pVtxBuf, 0);
        ctx->Unmap(s_pIdxBuf, 0);

        // Setup orthographic projection matrix into our constant buffer
        // Our visible imgui space lies from draw_data->DisplayPos (top left) to draw_data->DisplayPos+data_data->DisplaySize (bottom right). DisplayPos is (0,0) for single viewport apps.
        {
            D3D11_MAPPED_SUBRESOURCE mapped_resource;
            if (ctx->Map(s_pVtxCBuf, 0, D3D11_MAP_WRITE_DISCARD, 0, &mapped_resource) != S_OK) { return;}
            VERTEX_CONSTANT_BUFFER* constant_buffer = (VERTEX_CONSTANT_BUFFER*)mapped_resource.pData;
            float L = draw_data->DisplayPos.x;
            float R = draw_data->DisplayPos.x + draw_data->DisplaySize.x;
            float T = draw_data->DisplayPos.y;
            float B = draw_data->DisplayPos.y + draw_data->DisplaySize.y;
            float matMvp[4][4] = {
                { 2.0f / (R - L),   0.0f,           0.0f,       0.0f },
                { 0.0f,         2.0f / (T - B),     0.0f,       0.0f },
                { 0.0f,         0.0f,           0.5f,       0.0f },
                { (R + L) / (L - R),  (T + B) / (B - T),    0.5f,       1.0f },
            };
            memcpy(&constant_buffer->matMvp, matMvp, sizeof(matMvp));
            ctx->Unmap(s_pVtxCBuf, 0);
        }

        // Backup DX state that will be modified to restore it afterwards (unfortunately this is very ugly looking and verbose. Close your eyes!)
        struct BACKUP_DX11_STATE
        {
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
            ID3D11input_layout* input_layout;
        };
        BACKUP_DX11_STATE old;
        old.ScissorRectsCount = old.ViewportsCount = D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE;
        ctx->RSGetScissorRects(&old.ScissorRectsCount, old.ScissorRects);
        ctx->RSGetViewports(&old.ViewportsCount, old.Viewports);
        ctx->RSGetState(&old.RS);
        ctx->OMGetBlendState(&old.BlendState, old.BlendFactor, &old.SampleMask);
        ctx->OMGetDepthStencilState(&old.DepthStencilState, &old.StencilRef);
        ctx->PSGetShaderResources(0, 1, &old.PSShaderResource);
        ctx->PSGetSamplers(0, 1, &old.PSSampler);
        old.PSInstancesCount = old.VSInstancesCount = old.GSInstancesCount = 256;
        ctx->PSGetShader(&old.PS, old.PSInstances, &old.PSInstancesCount);
        ctx->VSGetShader(&old.VS, old.VSInstances, &old.VSInstancesCount);
        ctx->VSGetConstantBuffers(0, 1, &old.VSConstantBuffer);
        ctx->GSGetShader(&old.GS, old.GSInstances, &old.GSInstancesCount);

        ctx->IAGetPrimitiveTopology(&old.PrimitiveTopology);
        ctx->IAGetIndexBuffer(&old.IndexBuffer, &old.IndexBufferFormat, &old.IndexBufferOffset);
        ctx->IAGetVertexBuffers(0, 1, &old.VertexBuffer, &old.VertexBufferStride, &old.VertexBufferOffset);
        ctx->IAGetinput_layout(&old.input_layout);

        // Setup desired DX state
        Dx11SetupRenderState(draw_data, ctx);

        // Render command lists
        // (Because we merged all buffers into a single one, we maintain our own offset into them)
        int global_idx_offset = 0;
        int global_vtx_offset = 0;
        ImVec2 clip_off = draw_data->DisplayPos;
        for (int n = 0; n < draw_data->CmdListsCount; n++)
        {
            const ImDrawList* cmd_list = draw_data->CmdLists[n];
            for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++)
            {
                const ImDrawCmd* pcmd = &cmd_list->CmdBuffer[cmd_i];
                if (pcmd->UserCallback != NULL)
                {
                    // User callback, registered via ImDrawList::AddCallback()
                    // (ImDrawCallback_ResetRenderState is a special callback value used by the user to request the renderer to reset render state.)
                    if (pcmd->UserCallback == ImDrawCallback_ResetRenderState)
                        Dx11SetupRenderState(draw_data, ctx);
                    else
                        pcmd->UserCallback(cmd_list, pcmd);
                }
                else
                {
                    // Apply scissor/clipping rectangle
                    const D3D11_RECT r = { (LONG)(pcmd->ClipRect.x - clip_off.x), (LONG)(pcmd->ClipRect.y - clip_off.y), (LONG)(pcmd->ClipRect.z - clip_off.x), (LONG)(pcmd->ClipRect.w - clip_off.y) };
                    ctx->RSSetScissorRects(1, &r);

                    // Bind texture, Draw
                    ID3D11ShaderResourceView* texture_srv = (ID3D11ShaderResourceView*)pcmd->TextureId;
                    ctx->PSSetShaderResources(0, 1, &texture_srv);
                    ctx->DrawIndexed(pcmd->ElemCount, pcmd->IdxOffset + global_idx_offset, pcmd->VtxOffset + global_vtx_offset);
                }
            }
            global_idx_offset += cmd_list->IdxBuffer.Size;
            global_vtx_offset += cmd_list->VtxBuffer.Size;
        }

        // Restore modified DX state
        ctx->RSSetScissorRects(old.ScissorRectsCount, old.ScissorRects);
        ctx->RSSetViewports(old.ViewportsCount, old.Viewports);
        ctx->RSSetState(old.RS); if (old.RS) old.RS->Release();
        ctx->OMSetBlendState(old.BlendState, old.BlendFactor, old.SampleMask); if (old.BlendState) old.BlendState->Release();
        ctx->OMSetDepthStencilState(old.DepthStencilState, old.StencilRef); if (old.DepthStencilState) old.DepthStencilState->Release();
        ctx->PSSetShaderResources(0, 1, &old.PSShaderResource); if (old.PSShaderResource) old.PSShaderResource->Release();
        ctx->PSSetSamplers(0, 1, &old.PSSampler); if (old.PSSampler) old.PSSampler->Release();
        ctx->PSSetShader(old.PS, old.PSInstances, old.PSInstancesCount); if (old.PS) old.PS->Release();
        for (UINT i = 0; i < old.PSInstancesCount; i++) if (old.PSInstances[i]) old.PSInstances[i]->Release();
        ctx->VSSetShader(old.VS, old.VSInstances, old.VSInstancesCount); if (old.VS) old.VS->Release();
        ctx->VSSetConstantBuffers(0, 1, &old.VSConstantBuffer); if (old.VSConstantBuffer) old.VSConstantBuffer->Release();
        ctx->GSSetShader(old.GS, old.GSInstances, old.GSInstancesCount); if (old.GS) old.GS->Release();
        for (UINT i = 0; i < old.VSInstancesCount; i++) if (old.VSInstances[i]) old.VSInstances[i]->Release();
        ctx->IASetPrimitiveTopology(old.PrimitiveTopology);
        ctx->IASetIndexBuffer(old.IndexBuffer, old.IndexBufferFormat, old.IndexBufferOffset); if (old.IndexBuffer) old.IndexBuffer->Release();
        ctx->IASetVertexBuffers(0, 1, &old.VertexBuffer, &old.VertexBufferStride, &old.VertexBufferOffset); if (old.VertexBuffer) old.VertexBuffer->Release();
        ctx->IASetinput_layout(old.input_layout); if (old.input_layout) old.input_layout->Release();
    }

    static void Dx11CreateFontsTexture()
    {
        // Build texture atlas
        ImGuiIO& io = GUI::GetIO();
        unsigned char* pixels;
        int width, height;
        io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);

        // Upload texture to graphics system
        {
            D3D11_TEXTURE2D_DESC desc;
            ZeroMemory(&desc, sizeof(desc));
            desc.Width = width;
            desc.Height = height;
            desc.MipLevels = 1;
            desc.ArraySize = 1;
            desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            desc.SampleDesc.Count = 1;
            desc.Usage = D3D11_USAGE_DEFAULT;
            desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
            desc.CPUAccessFlags = 0;

            ID3D11Texture2D* pTexture = NULL;
            D3D11_SUBRESOURCE_DATA subResource;
            subResource.pSysMem = pixels;
            subResource.SysMemPitch = desc.Width * 4;
            subResource.SysMemSlicePitch = 0;
            s_pDevice->CreateTexture2D(&desc, &subResource, &pTexture);

            // Create texture view
            D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
            ZeroMemory(&srvDesc, sizeof(srvDesc));
            srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
            srvDesc.Texture2D.MipLevels = desc.MipLevels;
            srvDesc.Texture2D.MostDetailedMip = 0;
            s_pDevice->CreateShaderResourceView(pTexture, &srvDesc, &s_pFontTextureView);
            pTexture->Release();
        }

        // Store our identifier
        io.Fonts->TexID = (ImTextureID)s_pFontTextureView;

        // Create texture sampler
        {
            D3D11_SAMPLER_DESC desc;
            ZeroMemory(&desc, sizeof(desc));
            desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
            desc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
            desc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
            desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
            desc.MipLODBias = 0.f;
            desc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
            desc.MinLOD = 0.f;
            desc.MaxLOD = 0.f;
            s_pDevice->CreateSamplerState(&desc, &s_pFontSampler);
        }
    }

    bool    Dx11CreateDeviceObjects()
    {
        if (!s_pDevice)
            return false;
        if (s_pFontSampler)
            Dx11InvalidateDeviceObjects();

        // By using D3DCompile() from <d3dcompiler.h> / d3dcompiler.lib, we introduce a dependency to a given version of d3dcompiler_XX.dll (see D3DCOMPILER_DLL_A)
        // If you would like to use this DX11 sample code but remove this dependency you can:
        //  1) compile once, save the compiled shader blobs into a file or source code and pass them to CreateVertexShader()/CreatePixelShader() [preferred solution]
        //  2) use code to detect any version of the DLL and grab a pointer to D3DCompile from the DLL.
        // See https://github.com/ocornut/imgui/pull/638 for sources and details.

        // Create the vertex shader
        {
            static const char* vertexShader =
                "cbuffer vertexBuffer : register(b0) \
            {\
              float4x4 ProjectionMatrix; \
            };\
            struct VS_INPUT\
            {\
              float2 pos : POSITION;\
              float4 col : COLOR0;\
              float2 uv  : TEXCOORD0;\
            };\
            \
            struct PS_INPUT\
            {\
              float4 pos : SV_POSITION;\
              float4 col : COLOR0;\
              float2 uv  : TEXCOORD0;\
            };\
            \
            PS_INPUT main(VS_INPUT input)\
            {\
              PS_INPUT output;\
              output.pos = mul( ProjectionMatrix, float4(input.pos.xy, 0.f, 1.f));\
              output.col = input.col;\
              output.uv  = input.uv;\
              return output;\
            }";

            ID3DBlob* vertexShaderBlob;
            if (FAILED(D3DCompile(vertexShader, strlen(vertexShader), NULL, NULL, NULL, "main", "vs_4_0", 0, 0, &vertexShaderBlob, NULL)))
                return false; // NB: Pass ID3DBlob* pErrorBlob to D3DCompile() to get error showing in (const char*)pErrorBlob->GetBufferPointer(). Make sure to Release() the blob!
            if (s_pDevice->CreateVertexShader(vertexShaderBlob->GetBufferPointer(), vertexShaderBlob->GetBufferSize(), NULL, &s_pVtxShader) != S_OK)
            {
                vertexShaderBlob->Release();
                return false;
            }

            // Create the input layout
            D3D11_INPUT_ELEMENT_DESC local_layout[] =
            {
                { "POSITION", 0, DXGI_FORMAT_R32G32_FLOAT,   0, (UINT)IM_OFFSETOF(ImDrawVert, pos), D3D11_INPUT_PER_VERTEX_DATA, 0 },
                { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,   0, (UINT)IM_OFFSETOF(ImDrawVert, uv),  D3D11_INPUT_PER_VERTEX_DATA, 0 },
                { "COLOR",    0, DXGI_FORMAT_R8G8B8A8_UNORM, 0, (UINT)IM_OFFSETOF(ImDrawVert, col), D3D11_INPUT_PER_VERTEX_DATA, 0 },
            };
            if (s_pDevice->Createinput_layout(local_layout, 3, vertexShaderBlob->GetBufferPointer(), vertexShaderBlob->GetBufferSize(), &s_pInLayout) != S_OK)
            {
                vertexShaderBlob->Release();
                return false;
            }
            vertexShaderBlob->Release();

            // Create the constant buffer
            {
                D3D11_BUFFER_DESC desc;
                desc.ByteWidth = sizeof(VERTEX_CONSTANT_BUFFER);
                desc.Usage = D3D11_USAGE_DYNAMIC;
                desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
                desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
                desc.MiscFlags = 0;
                s_pDevice->CreateBuffer(&desc, NULL, &s_pVtxCBuf);
            }
        }

        // Create the pixel shader
        {
            static const char* pixelShader =
                "struct PS_INPUT\
            {\
            float4 pos : SV_POSITION;\
            float4 col : COLOR0;\
            float2 uv  : TEXCOORD0;\
            };\
            sampler sampler0;\
            Texture2D texture0;\
            \
            float4 main(PS_INPUT input) : SV_Target\
            {\
            float4 out_col = input.col * texture0.Sample(sampler0, input.uv); \
            return out_col; \
            }";

            ID3DBlob* pixelShaderBlob;
            if (FAILED(D3DCompile(pixelShader, strlen(pixelShader), NULL, NULL, NULL, "main", "ps_4_0", 0, 0, &pixelShaderBlob, NULL)))
                return false; // NB: Pass ID3DBlob* pErrorBlob to D3DCompile() to get error showing in (const char*)pErrorBlob->GetBufferPointer(). Make sure to Release() the blob!
            if (s_pDevice->CreatePixelShader(pixelShaderBlob->GetBufferPointer(), pixelShaderBlob->GetBufferSize(), NULL, &s_pPxlShader) != S_OK)
            {
                pixelShaderBlob->Release();
                return false;
            }
            pixelShaderBlob->Release();
        }

        // Create the blending setup
        {
            D3D11_BLEND_DESC desc;
            ZeroMemory(&desc, sizeof(desc));
            desc.AlphaToCoverageEnable = false;
            desc.RenderTarget[0].BlendEnable = true;
            desc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
            desc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
            desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
            desc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_INV_SRC_ALPHA;
            desc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
            desc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
            desc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
            s_pDevice->CreateBlendState(&desc, &s_pBlendState);
        }

        // Create the rasterizer state
        {
            D3D11_RASTERIZER_DESC desc;
            ZeroMemory(&desc, sizeof(desc));
            desc.FillMode = D3D11_FILL_SOLID;
            desc.CullMode = D3D11_CULL_NONE;
            desc.ScissorEnable = true;
            desc.DepthClipEnable = true;
            s_pDevice->CreateRasterizerState(&desc, &s_pRasterizerState);
        }

        // Create depth-stencil State
        {
            D3D11_DEPTH_STENCIL_DESC desc;
            ZeroMemory(&desc, sizeof(desc));
            desc.DepthEnable = false;
            desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
            desc.DepthFunc = D3D11_COMPARISON_ALWAYS;
            desc.StencilEnable = false;
            desc.FrontFace.StencilFailOp = desc.FrontFace.StencilDepthFailOp = desc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
            desc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
            desc.BackFace = desc.FrontFace;
            s_pDevice->CreateDepthStencilState(&desc, &s_pDepthStencilState);
        }

        Dx11CreateFontsTexture();

        return true;
    }

    void    Dx11InvalidateDeviceObjects()
    {
        if (!s_pDevice)
            return;

        if (s_pFontSampler) { s_pFontSampler->Release(); s_pFontSampler = NULL; }
        if (s_pFontTextureView) { s_pFontTextureView->Release(); s_pFontTextureView = NULL; GUI::GetIO().Fonts->TexID = NULL; } // We copied s_pFontTextureView to io.Fonts->TexID so let's clear that as well.
        if (s_pIdxBuf) { s_pIdxBuf->Release(); s_pIdxBuf = NULL; }
        if (s_pVtxBuf) { s_pVtxBuf->Release(); s_pVtxBuf = NULL; }

        if (s_pBlendState) { s_pBlendState->Release(); s_pBlendState = NULL; }
        if (s_pDepthStencilState) { s_pDepthStencilState->Release(); s_pDepthStencilState = NULL; }
        if (s_pRasterizerState) { s_pRasterizerState->Release(); s_pRasterizerState = NULL; }
        if (s_pPxlShader) { s_pPxlShader->Release(); s_pPxlShader = NULL; }
        if (s_pVtxCBuf) { s_pVtxCBuf->Release(); s_pVtxCBuf = NULL; }
        if (s_pInLayout) { s_pInLayout->Release(); s_pInLayout = NULL; }
        if (s_pVtxShader) { s_pVtxShader->Release(); s_pVtxShader = NULL; }
    }

    bool Dx11Init(ID3D11Device* device, ID3D11DeviceContext* device_context)
    {
        // Setup back-end capabilities flags
        ImGuiIO& io = GUI::GetIO();
        io.BackendRendererName = "imgui_impl_dx11";
        io.BackendFlags |= ImGuiBackendFlags_RendererHasVtxOffset;  // We can honor the ImDrawCmd::VtxOffset field, allowing for large meshes.
        io.BackendFlags |= ImGuiBackendFlags_RendererHasViewports;  // We can create multi-viewports on the Renderer side (optional)

        // Get factory from device
        IDXGIDevice* pDXGIDevice = NULL;
        IDXGIAdapter* pDXGIAdapter = NULL;
        IDXGIFactory* pFactory = NULL;

        if (device->QueryInterface(IID_PPV_ARGS(&pDXGIDevice)) == S_OK)
            if (pDXGIDevice->GetParent(IID_PPV_ARGS(&pDXGIAdapter)) == S_OK)
                if (pDXGIAdapter->GetParent(IID_PPV_ARGS(&pFactory)) == S_OK)
                {
                    s_pDevice = device;
                    s_pContext = device_context;
                    s_pFactory = pFactory;
                }
        if (pDXGIDevice) pDXGIDevice->Release();
        if (pDXGIAdapter) pDXGIAdapter->Release();
        s_pDevice->AddRef();
        s_pContext->AddRef();

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
            Dx11InitPlatformInterface();

        return true;
    }
    void Dx11Shutdown()
    {
        Dx11ShutdownPlatformInterface();
        Dx11InvalidateDeviceObjects();
        if (s_pFactory) { s_pFactory->Release(); s_pFactory = NULL; }
        if (s_pDevice) { s_pDevice->Release(); s_pDevice = NULL; }
        if (s_pContext) { s_pContext->Release(); s_pContext = NULL; }
    }

    void Dx11NewFrame()
    {
        if (!s_pFontSampler)
            Dx11CreateDeviceObjects();
    }

    //--------------------------------------------------------------------------------------------------------
    // MULTI-VIEWPORT / PLATFORM INTERFACE SUPPORT
    // This is an _advanced_ and _optional_ feature, allowing the back-end to create and handle multiple viewports simultaneously.
    // If you are new to dear imgui or creating a new binding for dear imgui, it is recommended that you completely ignore this section first..
    //--------------------------------------------------------------------------------------------------------

    // Helper structure we store in the void* RenderUserData field of each ImGuiViewport to easily retrieve our backend data.
    struct Dx11iVewportData
    {
        IDXGISwapChain* SwapChain;
        ID3D11RenderTargetView* RTView;

        Dx11iVewportData() { SwapChain = NULL; RTView = NULL; }
        ~Dx11iVewportData() { IM_ASSERT(SwapChain == NULL && RTView == NULL); }
    };

    static void Dx11CreateWindow(ImGuiViewport* viewport)
    {
        Dx11iVewportData* data = IM_NEW(Dx11iVewportData)();
        viewport->RendererUserData = data;

        // PlatformHandleRaw should always be a HWND, whereas PlatformHandle might be a higher-level handle (e.g. GLFWWindow*, SDL_Window*).
        // Some back-end will leave PlatformHandleRaw NULL, in which case we assume PlatformHandle will contain the HWND.
        HWND hwnd = viewport->PlatformHandleRaw ? (HWND)viewport->PlatformHandleRaw : (HWND)viewport->PlatformHandle;
        IM_ASSERT(hwnd != 0);

        // Create swap chain
        DXGI_SWAP_CHAIN_DESC sd;
        ZeroMemory(&sd, sizeof(sd));
        sd.BufferDesc.Width = (UINT)viewport->Size.x;
        sd.BufferDesc.Height = (UINT)viewport->Size.y;
        sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        sd.SampleDesc.Count = 1;
        sd.SampleDesc.Quality = 0;
        sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        sd.BufferCount = 1;
        sd.OutputWindow = hwnd;
        sd.Windowed = TRUE;
        sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
        sd.Flags = 0;

        IM_ASSERT(data->SwapChain == NULL && data->RTView == NULL);
        s_pFactory->CreateSwapChain(s_pDevice, &sd, &data->SwapChain);

        // Create the render target
        if (data->SwapChain)
        {
            ID3D11Texture2D* pBackBuffer;
            data->SwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
            s_pDevice->CreateRenderTargetView(pBackBuffer, NULL, &data->RTView);
            pBackBuffer->Release();
        }
    }
    static void Dx11DestroyWindow(ImGuiViewport* viewport)
    {
        // The main viewport (owned by the application) will always have RendererUserData == NULL since we didn't create the data for it.
        if (Dx11iVewportData* data = (Dx11iVewportData*)viewport->RendererUserData)
        {
            if (data->SwapChain)
                data->SwapChain->Release();
            data->SwapChain = NULL;
            if (data->RTView)
                data->RTView->Release();
            data->RTView = NULL;
            IM_DELETE(data);
        }
        viewport->RendererUserData = NULL;
    }

    static void Dx11SetWindowSize(ImGuiViewport* viewport, ImVec2 size)
    {
        Dx11iVewportData* data = (Dx11iVewportData*)viewport->RendererUserData;
        if (data->RTView)
        {
            data->RTView->Release();
            data->RTView = NULL;
        }
        if (data->SwapChain)
        {
            ID3D11Texture2D* pBackBuffer = NULL;
            data->SwapChain->ResizeBuffers(0, (UINT)size.x, (UINT)size.y, DXGI_FORMAT_UNKNOWN, 0);
            data->SwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
            if (pBackBuffer == NULL) { fprintf(stderr, "Dx11SetWindowSize() failed creating buffers.\n"); return; }
            s_pDevice->CreateRenderTargetView(pBackBuffer, NULL, &data->RTView);
            pBackBuffer->Release();
        }
    }

    static void Dx11RenderWindow(ImGuiViewport* viewport, void*)
    {
        Dx11iVewportData* data = (Dx11iVewportData*)viewport->RendererUserData;
        ImVec4 clear_color = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
        s_pContext->OMSetRenderTargets(1, &data->RTView, NULL);
        if (!(viewport->Flags & ImGuiViewportFlags_NoRendererClear)) {
            s_pContext->ClearRenderTargetView(data->RTView, (float*)&clear_color);
        }
        Dx11RenderDrawData(viewport->DrawData);
    }

    static void Dx11SwapBuffers(ImGuiViewport* viewport, void*)
    {
        Dx11iVewportData* data = reinterpret_cast<Dx11iVewportData*>(viewport->RendererUserData);
        data->SwapChain->Present(0, 0); // Present without vsync
    }

    static void Dx11InitPlatformInterface()
    {
        ImGuiPlatformIO& platform_io = GUI::GetPlatformIO();
        platform_io.Renderer_CreateWindow = Dx11CreateWindow;
        platform_io.Renderer_DestroyWindow = Dx11DestroyWindow;
        platform_io.Renderer_SetWindowSize = Dx11SetWindowSize;
        platform_io.Renderer_RenderWindow = Dx11RenderWindow;
        platform_io.Renderer_SwapBuffers = Dx11SwapBuffers;
    }
    static void Dx11ShutdownPlatformInterface() { GUI::DestroyPlatformWindows(); }
}
#endif  // NWG_GAPI