#include "nw_gfx_pch.hpp"
#include "nw_gfx_shd_gmt.h"
#if (defined NW_GAPI)
#include "core/nw_gfx_engine.h"
#include "lib/nw_gfx_lib_shd.h"
#include "lib/nw_gfx_lib_mtl.h"
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_shd_gmt::gfx_shd_gmt(gfx_engine& graphics) :
		a_gfx_shd(graphics)
	{
	}
	gfx_shd_gmt::gfx_shd_gmt(gfx_engine& graphics, cstr source_code) :
		gfx_shd_gmt(graphics)
	{
		if (!remake(source_code)) { throw init_error(__FILE__, __LINE__); return; }
	}
	gfx_shd_gmt::~gfx_shd_gmt() { }
	// --setters
	// --operators
	stm_out& gfx_shd_gmt::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& gfx_shd_gmt::operator>>(stm_in& stm) {
		return stm;
	}
	// --==<core_methods>==--
	v1b gfx_shd_gmt::remake(cstr source_code)
	{
		if (!a_gfx_shd::remake(source_code)) { return NW_FALSE; }

		m_handle = glCreateShader(GL_GEOMETRY_SHADER);
		cstr final_code = &m_src_code[0];
		glShaderSource(m_handle, 1, &final_code, NW_NULL);
		glCompileShader(m_handle);

		if (!gfx_check_shader(m_handle)) { return NW_FALSE; }

		return NW_TRUE;
	}
	void gfx_shd_gmt::on_draw()
	{
		a_gfx_shd::on_draw();
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	gfx_shd_gmt::gfx_shd_gmt(gfx_engine& graphics) :
		a_gfx_shd(graphics),
		m_native(NW_NULL)
	{
	}
	gfx_shd_gmt::gfx_shd_gmt(gfx_engine& graphics, cstr source_code) :
		gfx_shd_gmt(graphics)
	{
		if (!remake(source_code)) { throw init_error(__FILE__, __LINE__); return; }
	}
	gfx_shd_gmt::~gfx_shd_gmt() { if (m_native != NW_NULL) { m_native->Release(); m_native = NW_NULL; } }
	// --setters
	// --operators
	stm_out& gfx_shd_gmt::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& gfx_shd_gmt::operator>>(stm_in& stm) {
		return stm;
	}
	// --==<core_methods>==--
	v1b gfx_shd_gmt::remake(cstr source_code)
	{
		if (m_native != NW_NULL) { m_native->Release(); m_native = NW_NULL; }
		
		if (!a_gfx_shd::remake(source_code)) { return NW_FALSE; }
		
		return NW_TRUE;
	}
	void gfx_shd_gmt::on_draw()
	{
		a_gfx_shd::on_draw();

		m_gfx->get_ctxh()->GSSetShader(m_native, NULL, NULL);

		ID3D11Buffer* buf_handles[10]{ NW_NULL };
		for (auto& ibuf : m_bufs) {
			if (ibuf.is_valid()) {
				buf_handles[ibuf->get_slot()] = ibuf->get_handle();
			}
		}
		m_gfx->get_ctxh()->GSSetConstantBuffers(0, 10u, &buf_handles[0]);

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
		m_gfx->get_ctxh()->GSSetShaderResources(0u, 10u, &gfx_txrhandles[0]);
		m_gfx->get_ctxh()->GSSetSamplers(0u, 10u, &smp_handles[0]);
	}
	// --==</core_methods>==--
}
#endif
#endif	// NW_GAPI