#include "nw_gfx_pch.hpp"
#include "nw_gfx_txr_smp.h"
#if (defined NW_GAPI)
#	include "core/nw_gfx_engine.h"
#	include "lib/nw_gfx_lib_smp.h"
#	include "lib/nw_gfx_lib_txr.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_txr_smp::gfx_txr_smp() :
		t_cmp(), a_gfx_cmp(),
		m_handle(NW_NULL),
		m_slot(NW_NULL),
		m_filter(NW_NULL),
		m_border(NW_NULL),
		m_color(NW_NULL)
	{
	}
	gfx_txr_smp::~gfx_txr_smp() { if (m_handle != NW_NULL) { glDeleteSamplers(1u, &m_handle); m_handle = NW_NULL; } }
	// --setters
	v1nil gfx_txr_smp::set_slot(cv1u slot) {
		m_slot = slot;
	}
	v1nil gfx_txr_smp::set_filter(filter_tc filter) {
		m_filter = filter;
	}
	v1nil gfx_txr_smp::set_border(border_tc border) {
		m_border = border;
	}
	v1nil gfx_txr_smp::set_color(cv4f& color) {
		m_color = color;
	}
	// --==<core_methods>==--
	v1bit gfx_txr_smp::remake()
	{
		if (m_handle != NW_NULL) { glDeleteSamplers(1, &m_handle); m_handle = NW_NULL; }

		glGenSamplers(1, &m_handle);
		glSamplerParameteri(get_handle(), GL_TEXTURE_MIN_FILTER, get_filter());
		glSamplerParameteri(get_handle(), GL_TEXTURE_MAG_FILTER, get_filter());
		glSamplerParameteri(get_handle(), GL_TEXTURE_WRAP_S, get_border());
		glSamplerParameteri(get_handle(), GL_TEXTURE_WRAP_T, get_border());
		glSamplerParameteri(get_handle(), GL_TEXTURE_WRAP_R, get_border());
		glSamplerParameterfv(get_handle(), GL_TEXTURE_BORDER_COLOR, &m_color[0]);

		return NW_TRUE;
	}
	v1nil gfx_txr_smp::on_draw()
	{
		glBindSampler(get_slot(), get_handle());
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	gfx_txr_smp::gfx_txr_smp(
		gfx_engine& graphics,
		filter filter_mode,
		wrap wrap_mode,
		v4f border_color
	) :
		a_gfx_cmp(graphics), t_cmp(),
		m_handle(NW_NULL),
		m_slot(NW_NULL),
		m_filter(filter_mode),
		m_wrap(wrap_mode),
		m_border_color(border_color)
	{
		if (!remake(filter_mode, wrap_mode, border_color)) { throw init_error(__FILE__, __LINE__); return; }
	}
	gfx_txr_smp::~gfx_txr_smp() { if (m_handle != NW_NULL) { m_handle->Release(); m_handle = NW_NULL; } }
	// --setters
	v1nil gfx_txr_smp::set_slot(v1u slot) {
		m_slot = slot;
	}
	// --==<core_methods>==--
	v1bit gfx_txr_smp::remake(filter filter_mode, wrap wrap_mode, v4f border_color)
	{
		if (filter_mode != NW_NULL) { m_filter = filter_mode; }
		if (wrap_mode != NW_NULL) { m_wrap = wrap_mode; }
		if (wrap_mode == NW_WRAP_BORDER) { m_border_color = border_color; }
		if (m_handle != NW_NULL) { m_handle->Release(); m_handle = NW_NULL; }
		
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
		if (m_handle == NW_NULL) { throw init_error(__FILE__, __LINE__); return NW_FALSE; }

		return NW_TRUE;
	}
	v1nil gfx_txr_smp::on_draw()
	{
		m_gfx->get_ctxh()->VSSetSamplers(m_slot, 1u, &m_handle);
		m_gfx->get_ctxh()->PSSetSamplers(m_slot, 1u, &m_handle);
		m_gfx->get_ctxh()->GSSetSamplers(m_slot, 1u, &m_handle);
		m_gfx->get_ctxh()->HSSetSamplers(m_slot, 1u, &m_handle);
		m_gfx->get_ctxh()->DSSetSamplers(m_slot, 1u, &m_handle);
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NW_GAPI