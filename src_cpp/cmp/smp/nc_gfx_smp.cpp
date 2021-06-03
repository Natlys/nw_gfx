#include "nc_gfx_pch.hpp"
#include "nc_gfx_smp.hxx"
#if (defined NC_GAPI)
#	include "../../core/nc_nc_gfx_eng.hxx"
#if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	gfx_smp_t::gfx_smp_t() : nc_cmp_tt(), gfx_cmp_t(), m_handle(NC_NULL), m_slot(NC_NULL), m_filter(NC_NULL), m_border(NC_NULL), m_color(NC_NULL) { }
	gfx_smp_t::gfx_smp_t(filter_t filter) : gfx_smp_t() { NC_CHECK(remake(filter), "remake error!", return); }
	gfx_smp_t::gfx_smp_t(filter_t filter, border_t border) : gfx_smp_t() { NC_CHECK(remake(filter, border), "remake error!", return); }
	gfx_smp_t::gfx_smp_t(filter_t filter, border_t border, v4f_tc& color) : gfx_smp_t() { NC_CHECK(remake(filter, border, color), "remake error!", return); }
	gfx_smp_t::gfx_smp_t(smp_tc& copy) : gfx_smp_t() { operator=(copy); }
	gfx_smp_t::gfx_smp_t(smp_t&& copy) : gfx_smp_t() { operator=(copy); }
	gfx_smp_t::~gfx_smp_t() { if (m_handle != NC_NULL) { get_context()->smp_del(1u, &m_handle); m_handle = NC_NULL; } }
	/* setters */
	gfx_smp_t::smp_t& gfx_smp_t::set_slot(v1u_tc slot) { m_slot = slot; return *this; }
	gfx_smp_t::smp_t& gfx_smp_t::set_filter(filter_tc filter) { m_filter = filter; return *this; }
	gfx_smp_t::smp_t& gfx_smp_t::set_border(border_tc border) { m_border = border; return *this; }
	gfx_smp_t::smp_t& gfx_smp_t::set_color(v4f_tc& color) { m_color = color; return *this; }
	/* commands */
	v1bit_t gfx_smp_t::remake()
	{
		get_context()->smp_new(1u, &m_handle);
		get_context()->smp_set_param_n1s(get_handle(), GL_TEXTURE_MIN_FILTER, get_filter());
		get_context()->smp_set_param_n1s(get_handle(), GL_TEXTURE_MAG_FILTER, get_filter());
		get_context()->smp_set_param_n1s(get_handle(), GL_TEXTURE_WRAP_S, get_border());
		get_context()->smp_set_param_n1s(get_handle(), GL_TEXTURE_WRAP_T, get_border());
		get_context()->smp_set_param_n1s(get_handle(), GL_TEXTURE_WRAP_R, get_border());
		get_context()->smp_set_param_v1f(get_handle(), GL_TEXTURE_BORDER_COLOR, &m_color[0]);

		return NC_TRUTH;
	}
	v1nil_t gfx_smp_t::on_draw()
	{
		get_context()->smp_bind(get_slot(), get_handle());
	}
	// --==</core_methods>==--
}
#endif
#if (NC_GAPI & NC_GAPI_D3D)
namespace NC
{
	gfx_smp_t::gfx_smp_t(
		nc_gfx_eng& graphics,
		filter filter_mode,
		wrap wrap_mode,
		v4f_t border_color
	) :
		gfx_cmp_t(graphics), nc_cmp_tt(),
		m_handle(NC_NULL),
		m_slot(NC_NULL),
		m_filter(filter_mode),
		m_wrap(wrap_mode),
		m_border_color(border_color)
	{
		if (!remake(filter_mode, wrap_mode, border_color)) { throw init_error(__FILE__, __LINE__); return; }
	}
	gfx_smp_t::~gfx_smp_t() { if (m_handle != NC_NULL) { m_handle->Release(); m_handle = NC_NULL; } }
	/* setters */
	void gfx_smp_t::set_slot(v1u_t slot) {
		m_slot = slot;
	}
	/* commands */
	v1bit_t gfx_smp_t::remake(filter filter_mode, wrap wrap_mode, v4f_t border_color)
	{
		if (filter_mode != NC_NULL) { m_filter = filter_mode; }
		if (wrap_mode != NC_NULL) { m_wrap = wrap_mode; }
		if (wrap_mode == NC_WRAP_BORDER) { m_border_color = border_color; }
		if (m_handle != NC_NULL) { m_handle->Release(); m_handle = NC_NULL; }
		
		D3D11_SAMPLER_DESC smp_desc{ };
		smp_desc.AddressU = m_wrap;
		smp_desc.AddressV = m_wrap;
		smp_desc.AddressW = m_wrap;
		smp_desc.Filter = m_filter;
		smp_desc.BorderColor[0] = m_border_color[0];
		smp_desc.BorderColor[1] = m_border_color[1];
		smp_desc.BorderColor[2] = m_border_color[2];
		smp_desc.BorderColor[3] = m_border_color[3];
		smp_desc.ComparisonFunc;	//
		smp_desc.MaxAnisotropy;		// for the filter "anostropy"
		smp_desc.MinLOD;			// minimal level of details
		smp_desc.MaxLOD;			// maximal level of details
		smp_desc.MipLODBias;		// level of details for mipmapping
		m_gfx->get_dvch()->CreateSamplerState(&smp_desc, &m_handle);
		if (m_handle == NC_NULL) { throw init_error(__FILE__, __LINE__); return NC_FALSE; }

		return NC_TRUTH;
	}
	void gfx_smp_t::on_draw()
	{
		m_gfx->get_ctxh()->VSSetSamplers(m_slot, 1u, &m_handle);
		m_gfx->get_ctxh()->PSSetSamplers(m_slot, 1u, &m_handle);
		m_gfx->get_ctxh()->GSSetSamplers(m_slot, 1u, &m_handle);
		m_gfx->get_ctxh()->HSSetSamplers(m_slot, 1u, &m_handle);
		m_gfx->get_ctxh()->DSSetSamplers(m_slot, 1u, &m_handle);
	}
	// --==</core_methods>==--
}
#endif
#endif	// NC_GAPI