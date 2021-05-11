#include "nc_gfx_pch.hpp"
#include "nc_gfx_shd_vtx.h"
#if (defined NC_GAPI)
#	include "core/nc_nc_gfx_eng.h"
#	if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	gfx_shd_vtx_t::gfx_shd_vtx_t() : gfx_shd_t() { }
	gfx_shd_vtx_t::gfx_shd_vtx_t(source_tc& source) : gfx_shd_vtx_t() { NC_CHECK(gfx_shd_t::remake(source), "remake error!", return); }
	gfx_shd_vtx_t::gfx_shd_vtx_t(vshd_tc& copy) : gfx_shd_vtx_t() { operator=(copy); }
	gfx_shd_vtx_t::gfx_shd_vtx_t(vshd_t&& copy) : gfx_shd_vtx_t() { operator=(copy); }
	gfx_shd_vtx_t::~gfx_shd_vtx_t() { }
	// setters //
	// operators //
	op_stream_t& gfx_shd_vtx_t::operator<<(op_stream_t& stm) const { gfx_shd_t::operator<<(stm); return stm; }
	ip_stream_t& gfx_shd_vtx_t::operator>>(ip_stream_t& stm) { gfx_shd_t::operator>>(stm); return stm; }
	// commands //
	v1bit_t gfx_shd_vtx_t::remake()
	{
		NC_CHECK(gfx_shd_t::remake(), "remake error!", return NC_FALSE);
		
		m_handle = get_context()->shd_new(GL_VERTEX_SHADER);
		cstr_t final_code = &get_source()[0];
		get_context()->shd_set_source(get_handle(), 1u, &final_code, NC_NULL);
		get_context()->shd_remake(get_handle());

		NC_CHECK(gfx_check_shader(get_handle()), "failed compile!", return NC_FALSE);

		return NC_TRUTH;
	}
	v1nil_t gfx_shd_vtx_t::on_bind(binder_t& ref) { gfx_shd_t::on_bind(ref); }
	v1nil_t gfx_shd_vtx_t::on_draw() { gfx_shd_t::on_draw(); }
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
namespace NC
{
	gfx_shd_vtx_t::gfx_shd_vtx_t(nc_gfx_eng& graphics) :
		gfx_shd_t(graphics),
		m_native(NC_NULL)
	{
	}
	gfx_shd_vtx_t::gfx_shd_vtx_t(nc_gfx_eng& graphics, cstr source_code) :
		gfx_shd_vtx_t(graphics)
	{
		if (!remake(source_code)) { throw init_error(__FILE__, __LINE__); return; }
	}
	gfx_shd_vtx_t::~gfx_shd_vtx_t() { if (m_native != NC_NULL) { m_native->Release(); m_native = NC_NULL; } }
	// setters //
	// operators //
	stm_out& gfx_shd_vtx_t::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& gfx_shd_vtx_t::operator>>(stm_in& stm) {
		return stm;
	}
	// commands //
	v1bit_t gfx_shd_vtx_t::remake(cstr source_code)
	{
		if (m_native != NC_NULL) { m_native->Release(); m_native = NC_NULL; }
		
		if (!gfx_shd_t::remake(source_code)) { return NC_FALSE; }

		HRESULT h_result = 0;
		if ((h_result = D3DCompile(
			&m_src_code[0],		// source code
			m_src_code.size(),	// source code length
			NULL,				// source name
			NULL,				// defines
			NULL,				// includes
			"main",				// entry point name
			"vs_4_0",			// version
			0u,					// flags1
			0u,					// flags2
			&m_handle,			// where to store the code
			NULL				// blob for error messages
		)) != S_OK) { return NC_FALSE; }
		if (m_handle == NC_NULL) { return NC_FALSE; }

		m_gfx->get_dvch()->CreateVertexShader(m_handle->GetBufferPointer(), m_handle->GetBufferSize(), NULL, &m_native);
		if (m_handle == NC_NULL) { return NC_FALSE; }
		m_gfx->get_ctxh()->VSSetShader(m_native, NULL, NULL);
		
		return NC_TRUTH;
	}
	void gfx_shd_vtx_t::on_draw()
	{
		gfx_shd_t::on_draw();

		m_gfx->get_ctxh()->VSSetShader(m_native, NULL, NULL);

		ID3D11Buffer* buf_handles[10]{ NC_NULL };
		for (auto& ibuf : m_bufs) {
			if (ibuf.is_valid()) {
				buf_handles[ibuf->get_slot()] = ibuf->get_handle();
			}
		}
		m_gfx->get_ctxh()->VSSetConstantBuffers(0, 10u, &buf_handles[0]);

		ID3D11ShaderResourceView* gfx_txrhandles[10]{ NC_NULL };
		ID3D11SamplerState* smp_handles[10]{ NC_NULL };
		for (auto& itxr : m_txrs) {
			if (itxr.is_valid()) {
				gfx_txrhandles[itxr->get_slot()] = itxr->get_handle();
				auto& ismp = itxr->get_smp();
				if (ismp.is_valid()) {
					smp_handles[ismp->get_slot()] = ismp->get_handle();
				}
			}
		}
		m_gfx->get_ctxh()->VSSetShaderResources(0u, 10u, &gfx_txrhandles[0]);
		m_gfx->get_ctxh()->VSSetSamplers(0u, 10u, &smp_handles[0]);
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NC_GAPI