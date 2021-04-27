#include "nw_gfx_pch.hpp"
#include "nw_gfx_shd_vtx.h"
#if (defined NW_GAPI)
#	include "core/nw_gfx_engine.h"
#	include "lib/nw_gfx_lib_shd.h"
#	include "lib/nw_gfx_lib_debug.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_shd_vtx::gfx_shd_vtx() : gfx_shd() { }
	gfx_shd_vtx::gfx_shd_vtx(source_tc& source) : gfx_shd_vtx() { NW_CHECK(gfx_shd::remake(source), "remake error!", return); }
	gfx_shd_vtx::gfx_shd_vtx(vshd_tc& copy) : gfx_shd_vtx() { operator=(copy); }
	gfx_shd_vtx::gfx_shd_vtx(vshd_t&& copy) : gfx_shd_vtx() { operator=(copy); }
	gfx_shd_vtx::~gfx_shd_vtx() { }
	// --setters
	// --operators
	op_stream_t& gfx_shd_vtx::operator<<(op_stream_t& stm) const { gfx_shd::operator<<(stm); return stm; }
	ip_stream_t& gfx_shd_vtx::operator>>(ip_stream_t& stm) { gfx_shd::operator>>(stm); return stm; }
	// --==<core_methods>==--
	v1b gfx_shd_vtx::remake()
	{
		NW_CHECK(gfx_shd::remake(), "remake error!", return NW_FALSE);
		
		m_handle = glCreateShader(GL_VERTEX_SHADER);
		cstr_t final_code = &get_source()[0];
		glShaderSource(get_handle(), 1u, &final_code, NW_NULL);
		glCompileShader(get_handle());

		NW_CHECK(gfx_check_shader(get_handle()), "failed compile!", return NW_FALSE);

		return NW_TRUE;
	}
	v1nil gfx_shd_vtx::on_bind(binder_t& ref) { gfx_shd::on_bind(ref); }
	v1nil gfx_shd_vtx::on_draw() { gfx_shd::on_draw(); }
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	gfx_shd_vtx::gfx_shd_vtx(gfx_engine& graphics) :
		gfx_shd(graphics),
		m_native(NW_NULL)
	{
	}
	gfx_shd_vtx::gfx_shd_vtx(gfx_engine& graphics, cstr source_code) :
		gfx_shd_vtx(graphics)
	{
		if (!remake(source_code)) { throw init_error(__FILE__, __LINE__); return; }
	}
	gfx_shd_vtx::~gfx_shd_vtx() { if (m_native != NW_NULL) { m_native->Release(); m_native = NW_NULL; } }
	// --setters
	// --operators
	stm_out& gfx_shd_vtx::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& gfx_shd_vtx::operator>>(stm_in& stm) {
		return stm;
	}
	// --==<core_methods>==--
	v1b gfx_shd_vtx::remake(cstr source_code)
	{
		if (m_native != NW_NULL) { m_native->Release(); m_native = NW_NULL; }
		
		if (!gfx_shd::remake(source_code)) { return NW_FALSE; }

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
		)) != S_OK) { return NW_FALSE; }
		if (m_handle == NW_NULL) { return NW_FALSE; }

		m_gfx->get_dvch()->CreateVertexShader(m_handle->GetBufferPointer(), m_handle->GetBufferSize(), NULL, &m_native);
		if (m_handle == NW_NULL) { return NW_FALSE; }
		m_gfx->get_ctxh()->VSSetShader(m_native, NULL, NULL);
		
		return NW_TRUE;
	}
	void gfx_shd_vtx::on_draw()
	{
		gfx_shd::on_draw();

		m_gfx->get_ctxh()->VSSetShader(m_native, NULL, NULL);

		ID3D11Buffer* buf_handles[10]{ NW_NULL };
		for (auto& ibuf : m_bufs) {
			if (ibuf.is_valid()) {
				buf_handles[ibuf->get_slot()] = ibuf->get_handle();
			}
		}
		m_gfx->get_ctxh()->VSSetConstantBuffers(0, 10u, &buf_handles[0]);

		ID3D11ShaderResourceView* gfx_txrhandles[10]{ NW_NULL };
		ID3D11SamplerState* smp_handles[10]{ NW_NULL };
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
#endif	// NW_GAPI