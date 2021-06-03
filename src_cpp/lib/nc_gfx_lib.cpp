#include "nc_gfx_pch.hpp"
#include "nc_gfx_lib.hxx"
#if (defined NC_GAPI)
#	if (NC_GAPI & NC_GAPI_OGL)
#	include "../core/nc_nc_gfx_eng.hxx"
#	include "std/nc_std_error.hxx"
#	include "nc_gfx_lib_wapi.hxx"
#	include "nc_gfx_lib_core.hxx"
namespace NC
{
	gfx_library_t::gfx_library_t() :
		library_t("opengl32.dll")
	{
		wglCreateContext = (pfn_gfx_new_context)library_t::get_proc("wglCreateContext");
		wglDeleteContext = (pfn_gfx_del_context)library_t::get_proc("wglDeleteContext");
		wglGetCurrentContext = (pfn_gfx_get_context)library_t::get_proc("wglGetCurrentContext");
		wglMakeContextCurrent = (pfn_gfx_set_context)library_t::get_proc("wglMakeCurrent");
		// device
		wglGetCurrentDC = (pfn_gfx_get_device)library_t::get_proc("wglGetCurrentDC");
		// other
		wglGetProcAddress = (pfn_gfx_get_proc)library_t::get_proc("wglGetProcAddress");
	}
	gfx_library_t::~gfx_library_t()
	{
		if (has_handle()) { ::FreeLibrary(m_handle); m_handle = NC_NULL; }
	}
	/* setters */
	/* commands */
	// --==</core_methods>==--
}
namespace NC
{ // windows
	// context
	pfn_gfx_new_context  wglCreateContext = NC_NULL;
	pfn_gfx_del_context  wglDeleteContext = NC_NULL;
	pfn_gfx_get_context  wglGetCurrentContext = NC_NULL;
	pfn_gfx_set_context  wglMakeContextCurrent = NC_NULL;
	// device
	pfn_gfx_get_device wglGetCurrentDC = NC_NULL;
	// other
	pfn_gfx_get_proc wglGetProcAddress = NC_NULL;
	// extensions
	pfn_gfx_ext_get_str   wglGetExtensionsStringEXT = NC_NULL;
	pfn_gfx_ext_get_vsync wglGetSwapIntervalEXT = NC_NULL;
	pfn_gfx_ext_set_vsync wglSwapIntervalEXT = NC_NULL;
}
namespace NC
{
	gfx_context_state_t::gfx_context_state_t()
	{
		auto& ctx = nc_gfx_eng::get().get_context();
		// --material
		ctx.get_int(GL_CURRENT_PROGRAM, (GLint*)&this->material_handle);
		// --texture
		ctx.get_int(GL_ACTIVE_TEXTURE, (GLint*)&this->texture_slot);
		ctx.get_int(GL_TEXTURE_BINDING_2D, (GLint*)&this->texture_handle);
		// --sampler
		ctx.get_int(GL_SAMPLER_BINDING, (GLint*)&this->sampler_handle);
		// --buffer
		ctx.get_int(GL_ARRAY_BUFFER_BINDING, (GLint*)&this->buffer_vetex_handle);
		ctx.get_int(GL_VERTEX_ARRAY_BINDING, (GLint*)&this->layout_hadle);
		// --modes
		// // --rasteriser
		this->is_enabled_sciss = ctx.is_enabled(GL_SCISSOR_TEST);
		this->is_enabled_cull = ctx.is_enabled(GL_CULL_FACE);
		ctx.get_int(GL_SCISSOR_BOX, this->sciss_box);
		ctx.get_int(GL_VIEWPORT, this->viewp_box);
		ctx.get_int(GL_POLYGON_MODE, (GLint*)&this->fill_mode);
		// // --depth_stencil
		this->is_enabled_depth = ctx.is_enabled(GL_DEPTH_TEST);
		this->is_enabled_stenc = ctx.is_enabled(GL_STENCIL_TEST);
		// // --blending
		this->is_enabled_blend = ctx.is_enabled(GL_BLEND);
		ctx.get_int(GL_BLEND_SRC_RGB, (GLint*)&this->blend_src_rgb);
		ctx.get_int(GL_BLEND_DST_RGB, (GLint*)&this->blend_dst_rgb);
		ctx.get_int(GL_BLEND_SRC_ALPHA, (GLint*)&this->blend_src_alpha);
		ctx.get_int(GL_BLEND_DST_ALPHA, (GLint*)&this->blend_dst_alpha);
		ctx.get_int(GL_BLEND_EQUATION_RGB, (GLint*)&this->blend_eq_rgb);
		ctx.get_int(GL_BLEND_EQUATION_ALPHA, (GLint*)&this->blend_eq_alpha);
	}
	gfx_context_state_t::~gfx_context_state_t()
	{
		auto& ctx = nc_gfx_eng::get().get_context();
		// --blending
		if (this->is_enabled_blend) { ctx.set_enabled(GL_BLEND); }
		else { ctx.set_disabled(GL_BLEND); }
		if (this->is_enabled_cull) { ctx.set_enabled(GL_CULL_FACE); }
		else { ctx.set_disabled(GL_CULL_FACE); }
		if (this->is_enabled_depth) { ctx.set_enabled(GL_DEPTH_TEST); }
		else { ctx.set_disabled(GL_DEPTH_TEST); }
		if (this->is_enabled_stenc) { ctx.set_enabled(GL_STENCIL_TEST); }
		else { ctx.set_disabled(GL_STENCIL_TEST); }
		if (this->is_enabled_sciss) { ctx.set_enabled(GL_SCISSOR_TEST); }
		else { ctx.set_disabled(GL_SCISSOR_TEST); }
		// --material
		ctx.mtl_bind(this->material_handle);
		// --texute
		ctx.txr_active(this->texture_slot);
		ctx.txr_bind(GL_TEXTURE_2D, this->texture_handle);
		// --sampler
		ctx.smp_bind(0u, this->sampler_handle);
		// --buffer
		ctx.layt_bind(this->layout_hadle);
		ctx.buf_bind(GL_ARRAY_BUFFER, this->buffer_vetex_handle);
		// --modes
		// // --rasterizer
		ctx.set_fill(this->fill_face, this->fill_mode);
		ctx.set_cull(this->cull_mode);
		ctx.set_viewp(this->viewp_box[0], this->viewp_box[1], (GLsizei)this->viewp_box[2], (GLsizei)this->viewp_box[3]);
		ctx.set_sciss(this->sciss_box[0], this->sciss_box[1], (GLsizei)this->sciss_box[2], (GLsizei)this->sciss_box[3]);
		// blending
		ctx.set_blend_equation_separate(this->blend_eq_rgb, this->blend_eq_alpha);
		ctx.set_blend_function_separate(this->blend_src_rgb, this->blend_dst_rgb, this->blend_src_alpha, this->blend_dst_alpha);
	}
}
namespace NC
{
	v1nil_t gfx_clear_err() { while (nc_gfx_eng::get().get_context().get_err() != GL_NO_ERROR); }
	v1bit_t gfx_get_err_log(cstr_t loc, cstr_t fpath, v1u_tc line)
	{
		v1s_t err_code = 0u;
		while ((err_code = nc_gfx_eng::get().get_context().get_err()) != GL_NO_ERROR) {
			switch (err_code) {
			case GL_INVALID_ENUM: throw error_t("INVALID_ENUM", NC_NULL); break;
			case GL_INVALID_VALUE: throw error_t("INVALID_VALUE", NC_NULL); break;
			case GL_INVALID_OPERATION: throw error_t("INVALID_OPERATION", NC_NULL); break;
			case GL_STACK_OVERFLOW: throw error_t("STACK_OVERFLOW", NC_NULL); break;
			case GL_STACK_UNDERFLOW: throw error_t("STACK_UNDERFLOW", NC_NULL); break;
			case GL_OUT_OF_MEMORY: throw error_t("OUT_OF_MEMORY", NC_NULL); break;
			}
			return NC_FALSE;
		}
		return NC_TRUTH;
	}
	v1bit_t gfx_check_shader(v1u_t shd_id) {
		if (shd_id == 0) { return NC_FALSE; }
		v1s_t success_code = 0;
		v1s_t log_size = 0;
		dstr_t log_string;
		if (nc_gfx_eng::get().get_context().is_shader(shd_id)) {
			nc_gfx_eng::get().get_context().shd_get_v1s(shd_id, GL_COMPILE_STATUS, &success_code);
			if (success_code == 0) {
				nc_gfx_eng::get().get_context().shd_get_v1s(shd_id, GL_INFO_LOG_LENGTH, &log_size);
				log_string.resize(log_size);
				nc_gfx_eng::get().get_context().shd_get_info_log(shd_id, log_size, NULL, &log_string[0]);
				throw error_t(&log_string[0], __LINE__);
				return success_code == 1;
			}
		}
		else {
			nc_gfx_eng::get().get_context().mtl_get_iv(shd_id, GL_LINK_STATUS, &success_code);
			if (success_code == 0) {
				nc_gfx_eng::get().get_context().mtl_get_iv(shd_id, GL_INFO_LOG_LENGTH, &log_size);
				log_string.resize(log_size);
				nc_gfx_eng::get().get_context().mtl_get_info_log(shd_id, log_size, NULL, &log_string[0]);
				throw error_t(&log_string[0], __LINE__);
				return NC_FALSE;
			}
		}
		return success_code == 1;
	}
}
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
namespace NC
{
	if constexpr (NC_TRUTH) { // core
		D3D11CreateDevice = (pfn_d3d_new_device_context)get_proc("D3D11CreateDevice");
		D3D11CreateDeviceAndSwapChain = (pfn_d3d_new_device_context_swap)get_proc("D3D11CreateDeviceAndSwapChain");
	}
	if constexpr (NC_TRUTH) { // shaders
		D3DCompile = (pfn_gfx_shd_compile)get_proc("D3DCompile");
	}
}
namespace NC
{ // core
	pfn_d3d_new_device_context D3D11CreateDevice = NULL;
	pfn_d3d_new_device_context_swap D3D11CreateDeviceAndSwapChain = NULL;
}
namespace NC
{ // shaders
	pfn_gfx_shd_compile D3DCompile = NULL;
}
namespace NC
	gfx_context_state_t::~gfx_context_state_t()
{
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
	gfx_context_state_t::~gfx_context_state_t()
	{
		// rasterizer
		s_context->RSSetScissorRects(ScissorRectsCount, ScissorRects);
		s_context->RSSetViewports(ViewportsCount, Viewports);
		s_context->RSSetState(RS);
		if (RS != NC_NULL) { RS->Release(); RS = NC_NULL; }
		// output_manager
		s_context->OMSetBlendState(BlendState, BlendFactor, SampleMask);
		if (BlendState != NC_NULL) { BlendState->Release(); BlendState = NC_NULL; }
		s_context->OMSetDepthStencilState(DepthStencilState, StencilRef);
		if (DepthStencilState != NC_NULL) { DepthStencilState->Release(); DepthStencilState = NC_NULL; }
		// shaders
		s_context->PSSetShaderResources(0, 1, &PSShaderResource);
		s_context->PSSetShader(PS, PSInstances, PSInstancesCount);
		if (PS != NC_NULL) { PS->Release(); PS = NC_NULL; }
		for (UINT i = 0; i < PSInstancesCount; i++) {
			if (PSInstances[i] != NC_NULL) { PSInstances[i]->Release(); PSInstances[i] = NC_NULL; }
		}
		s_context->VSSetShader(VS, VSInstances, VSInstancesCount);
		if (VS != NC_NULL) { VS->Release(); VS = NC_NULL; }
		s_context->GSSetShader(GS, GSInstances, GSInstancesCount);
		if (GS != NC_NULL) { GS->Release(); GS = NC_NULL; }
		for (UINT i = 0; i < VSInstancesCount; i++) {
			if (VSInstances[i] != NC_NULL) { VSInstances[i]->Release(); VSInstances[i] = NC_NULL; }
		}
		// textures
		if (PSShaderResource != NC_NULL) { PSShaderResource->Release(); PSShaderResource = NC_NULL; }
		s_context->PSSetSamplers(0, 1, &PSSampler);
		if (PSSampler != NC_NULL) { PSSampler->Release(); PSSampler = NC_NULL; }
		s_context->VSSetConstantBuffers(0, 1, &VSConstantBuffer);
		if (VSConstantBuffer != NC_NULL) { VSConstantBuffer->Release(); VSConstantBuffer = NC_NULL; }
		// input_assembler
		s_context->IASetPrimitiveTopology(PrimitiveTopology);
		s_context->IASetIndexBuffer(IndexBuffer, IndexBufferFormat, IndexBufferOffset);
		if (IndexBuffer != NC_NULL) { IndexBuffer->Release(); IndexBuffer = NC_NULL; }
		s_context->IASetVertexBuffers(0, 1, &VertexBuffer, &VertexBufferStride, &VertexBufferOffset);
		if (VertexBuffer != NC_NULL) { VertexBuffer->Release(); VertexBuffer = NC_NULL; }
		s_context->IASetInputLayout(input_layout);
		if (input_layout != NC_NULL) { input_layout->Release(); input_layout = NC_NULL; }
	}
}
#	endif	// GAPI_D3D
#endif	// NC_GAPI