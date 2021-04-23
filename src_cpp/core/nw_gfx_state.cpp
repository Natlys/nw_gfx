#include "nw_gfx_pch.hpp"
#include "nw_gfx_state.h"
#if (defined NW_GAPI)
#   include "../lib/nw_gfx_lib_buf.h"
#   include "../lib/nw_gfx_lib_fmbuf.h"
#   include "../lib/nw_gfx_lib_layt.h"
#   include "../lib/nw_gfx_lib_core.h"
#   include "../lib/nw_gfx_lib_txr.h"
#   include "../lib/nw_gfx_lib_smp.h"
#   include "../lib/nw_gfx_lib_mtl.h"
#   include "../lib/nw_gfx_lib_shd.h"
#   if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
    gfx_state::gfx_state()
    {
        // shaders
        glGetIntegerv(GL_CURRENT_PROGRAM, (GLint*)&last_shd_prog);
        // textures
        glGetIntegerv(GL_ACTIVE_TEXTURE, (GLint*)&last_active_txr);
        glGetIntegerv(GL_TEXTURE_BINDING_2D, (GLint*)&last_bound_txr);
        glGetIntegerv(GL_SAMPLER_BINDING, (GLint*)&last_sampler);
        // vertex data
        glGetIntegerv(GL_ARRAY_BUFFER_BINDING, (GLint*)&last_vbuf);
        glGetIntegerv(GL_VERTEX_ARRAY_BINDING, (GLint*)&last_varr);
        // rasteriser state
        glGetIntegerv(GL_POLYGON_MODE, last_poly_mode);
        glGetIntegerv(GL_VIEWPORT, last_viewport);
        glGetIntegerv(GL_SCISSOR_BOX, last_scissor_box);
        // blending state
        glGetIntegerv(GL_BLEND_SRC_RGB, (GLint*)&last_blend_src_rgb);
        glGetIntegerv(GL_BLEND_DST_RGB, (GLint*)&last_blend_dst_rgb);
        glGetIntegerv(GL_BLEND_SRC_ALPHA, (GLint*)&last_blend_src_aplha);
        glGetIntegerv(GL_BLEND_DST_ALPHA, (GLint*)&last_blend_dst_alpha);
        glGetIntegerv(GL_BLEND_EQUATION_RGB, (GLint*)&last_blend_eq_rgb);
        glGetIntegerv(GL_BLEND_EQUATION_ALPHA, (GLint*)&last_blend_eq_alpha);
        // enable flags
        last_blending = glIsEnabled(GL_BLEND);
        last_culling = glIsEnabled(GL_CULL_FACE);
        last_depth_test = glIsEnabled(GL_DEPTH_TEST);
        last_scissor_test = glIsEnabled(GL_SCISSOR_TEST);
    }
	gfx_state::~gfx_state()
    {
        // enable flags
        if (last_blending) { glEnable(GL_BLEND); }
        else { glDisable(GL_BLEND); }
        if (last_culling) { glEnable(GL_CULL_FACE); }
        else { glDisable(GL_CULL_FACE); }
        if (last_depth_test) { glEnable(GL_DEPTH_TEST); }
        else { glDisable(GL_DEPTH_TEST); }
        if (last_scissor_test) { glEnable(GL_SCISSOR_TEST); }
        else { glDisable(GL_SCISSOR_TEST); }
        // shaders
        glUseProgram(last_shd_prog);
        // texutes
        glBindTexture(GL_TEXTURE_2D, last_bound_txr);
        glBindSampler(0u, last_sampler);
        glActiveTexture(last_bound_txr);
        // vertex data
        glBindVertexArray(last_varr);
        glBindBuffer(GL_ARRAY_BUFFER, last_vbuf);
        // rasterizer
        glPolygonMode(GL_FRONT_AND_BACK, (GLenum)last_poly_mode[0]);
        glViewport(last_viewport[0], last_viewport[1], (GLsizei)last_viewport[2], (GLsizei)last_viewport[3]);
        glScissor(last_scissor_box[0], last_scissor_box[1], (GLsizei)last_scissor_box[2], (GLsizei)last_scissor_box[3]);
        // blending
        glBlendEquationSeparate(last_blend_eq_rgb, last_blend_eq_alpha);
        glBlendFuncSeparate(last_blend_src_rgb, last_blend_dst_rgb, last_blend_src_aplha, last_blend_dst_alpha);
    }
}
#	endif	// GAPI_OGL
#   if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
    gfx_state::gfx_state()
    {
        ScissorRectsCount = ViewportsCount = D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE;
        // rasterizer
        s_context->RSGetScissorRects(&ScissorRectsCount, ScissorRects);
        s_context->RSGetViewports(&ViewportsCount, Viewports);
        s_context->RSGetState(&RS);
        // output_manager
        s_context->OMGetBlendState(&BlendState, BlendFactor, &SampleMask);
        s_context->OMGetDepthStencilState(&DepthStencilState, &StencilRef);
        // shaders
        PSInstancesCount = VSInstancesCount = GSInstancesCount = 256;
        s_context->PSGetShaderResources(0, 1, &PSShaderResource);
        s_context->PSGetSamplers(0, 1, &PSSampler);
        s_context->PSGetShader(&PS, PSInstances, &PSInstancesCount);
        s_context->VSGetShader(&VS, VSInstances, &VSInstancesCount);
        s_context->VSGetConstantBuffers(0, 1, &VSConstantBuffer);
        s_context->GSGetShader(&GS, GSInstances, &GSInstancesCount);
        // input_assembler
        s_context->IAGetPrimitiveTopology(&PrimitiveTopology);
        s_context->IAGetIndexBuffer(&IndexBuffer, &IndexBufferFormat, &IndexBufferOffset);
        s_context->IAGetVertexBuffers(0, 1, &VertexBuffer, &VertexBufferStride, &VertexBufferOffset);
        s_context->IAGetInputLayout(&input_layout);
    }
    gfx_state::~gfx_state()
    {
        // rasterizer
        s_context->RSSetScissorRects(ScissorRectsCount, ScissorRects);
        s_context->RSSetViewports(ViewportsCount, Viewports);
        s_context->RSSetState(RS);
        if (RS != NW_NULL) { RS->Release(); RS = NW_NULL; }
        // output_manager
        s_context->OMSetBlendState(BlendState, BlendFactor, SampleMask);
        if (BlendState != NW_NULL) { BlendState->Release(); BlendState = NW_NULL; }
        s_context->OMSetDepthStencilState(DepthStencilState, StencilRef);
        if (DepthStencilState != NW_NULL) { DepthStencilState->Release(); DepthStencilState = NW_NULL; }
        // shaders
        s_context->PSSetShaderResources(0, 1, &PSShaderResource);
        s_context->PSSetShader(PS, PSInstances, PSInstancesCount);
        if (PS != NW_NULL) { PS->Release(); PS = NW_NULL; }
        for (UINT i = 0; i < PSInstancesCount; i++) {
            if (PSInstances[i] != NW_NULL) { PSInstances[i]->Release(); PSInstances[i] = NW_NULL; }
        }
        s_context->VSSetShader(VS, VSInstances, VSInstancesCount);
        if (VS != NW_NULL) { VS->Release(); VS = NW_NULL; }
        s_context->GSSetShader(GS, GSInstances, GSInstancesCount);
        if (GS != NW_NULL) { GS->Release(); GS = NW_NULL; }
        for (UINT i = 0; i < VSInstancesCount; i++) {
            if (VSInstances[i] != NW_NULL) { VSInstances[i]->Release(); VSInstances[i] = NW_NULL; }
        }
        // textures
        if (PSShaderResource != NW_NULL) { PSShaderResource->Release(); PSShaderResource = NW_NULL; }
        s_context->PSSetSamplers(0, 1, &PSSampler);
        if (PSSampler != NW_NULL) { PSSampler->Release(); PSSampler = NW_NULL; }
        s_context->VSSetConstantBuffers(0, 1, &VSConstantBuffer);
        if (VSConstantBuffer != NW_NULL) { VSConstantBuffer->Release(); VSConstantBuffer = NW_NULL; }
        // input_assembler
        s_context->IASetPrimitiveTopology(PrimitiveTopology);
        s_context->IASetIndexBuffer(IndexBuffer, IndexBufferFormat, IndexBufferOffset);
        if (IndexBuffer != NW_NULL) { IndexBuffer->Release(); IndexBuffer = NW_NULL; }
        s_context->IASetVertexBuffers(0, 1, &VertexBuffer, &VertexBufferStride, &VertexBufferOffset);
        if (VertexBuffer != NW_NULL) { VertexBuffer->Release(); VertexBuffer = NW_NULL; }
        s_context->IASetInputLayout(input_layout);
        if (input_layout != NW_NULL) { input_layout->Release(); input_layout = NW_NULL; }
    }
}
#	endif	// GAPI_D3D
#endif	// NW_GAPI