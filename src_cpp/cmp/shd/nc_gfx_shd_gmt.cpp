#include "nc_gfx_pch.hpp"
#include "nc_gfx_shd_gmt.hxx"
#if (defined NC_GAPI)
#	include "core/nc_nc_gfx_eng.hxx"
#	if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	gfx_shd_gmt_t::gfx_shd_gmt_t() : gfx_shd_t() { }
	gfx_shd_gmt_t::gfx_shd_gmt_t(source_tc& source) : gfx_shd_t(source) { }
	gfx_shd_gmt_t::gfx_shd_gmt_t(gshd_tc& copy) : gfx_shd_gmt_t() { operator=(copy); }
	gfx_shd_gmt_t::gfx_shd_gmt_t(gshd_t&& copy) : gfx_shd_gmt_t() { operator=(copy); }
	gfx_shd_gmt_t::~gfx_shd_gmt_t() { }
	/* setters */
	/* operators */
	nc_ostream_t& gfx_shd_gmt_t::operator<<(nc_ostream_t& stm) const { gfx_shd_t::operator<<(stm); return stm; }
	nc_istream_t& gfx_shd_gmt_t::operator>>(nc_istream_t& stm) { gfx_shd_t::operator>>(stm); return stm; }
	/* commands */
	v1bit_t gfx_shd_gmt_t::remake()
	{
		NC_CHECK(gfx_shd_t::remake(), "remake error!", return NC_FALSE);

		m_handle = get_context()->shd_new(GL_GEOMETRY_SHADER);
		cstr_t final_code = &get_source()[0];
		get_context()->shd_set_source(get_handle(), 1, &final_code, NC_NULL);
		get_context()->shd_remake(get_handle());

		if (!gfx_check_shader(get_handle())) { return NC_FALSE; }

		return NC_TRUTH;
	}
	v1nil_t gfx_shd_gmt_t::on_bind(binder_t& ref) { gfx_shd_t::on_bind(ref); }
	v1nil_t gfx_shd_gmt_t::on_draw() { gfx_shd_t::on_draw(); }
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
namespace NC
{
	gfx_shd_gmt_t::gfx_shd_gmt_t(nc_gfx_eng& graphics) :
		gfx_shd_t(graphics),
		m_native(NC_NULL)
	{
	}
	gfx_shd_gmt_t::gfx_shd_gmt_t(nc_gfx_eng& graphics, cstr source_code) :
		gfx_shd_gmt_t(graphics)
	{
		if (!remake(source_code)) { throw init_error(__FILE__, __LINE__); return; }
	}
	gfx_shd_gmt_t::~gfx_shd_gmt_t() { if (m_native != NC_NULL) { m_native->Release(); m_native = NC_NULL; } }
	/* setters */
	/* operators */
	nc_ostream_t& gfx_shd_gmt_t::operator<<(nc_ostream_t& stm) const {
		return stm;
	}
	nc_istream_t& gfx_shd_gmt_t::operator>>(nc_istream_t& stm) {
		return stm;
	}
	/* commands */
	v1bit_t gfx_shd_gmt_t::remake(cstr source_code)
	{
		if (m_native != NC_NULL) { m_native->Release(); m_native = NC_NULL; }
		
		if (!gfx_shd_t::remake(source_code)) { return NC_FALSE; }
		
		return NC_TRUTH;
	}
	v1nil_t gfx_shd_gmt_t::on_draw()
	{
		gfx_shd_t::on_draw();

		m_gfx->get_ctxh()->GSSetShader(m_native, NULL, NULL);

		ID3D11Buffer* buf_handles[10]{ NC_NULL };
		for (auto& ibuf : m_bufs) {
			if (ibuf.is_valid()) {
				buf_handles[ibuf->get_slot()] = ibuf->get_handle();
			}
		}
		m_gfx->get_ctxh()->GSSetConstantBuffers(0, 10u, &buf_handles[0]);

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
		m_gfx->get_ctxh()->GSSetShaderResources(0u, 10u, &gfx_txrhandles[0]);
		m_gfx->get_ctxh()->GSSetSamplers(0u, 10u, &smp_handles[0]);
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NC_GAPI