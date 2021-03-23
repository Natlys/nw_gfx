#include <nwg_pch.hpp>
#include "nwg_txr_smp.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#include <lib/nwg_load_smp.h>
#include <lib/nwg_load_txr.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	txr_smp::txr_smp(gfx_engine& graphics) :
		t_cmp(), a_gfx_cmp(graphics),
		m_slot(0),
		m_filter(TXFL_NEAREST),
		m_wrap_s(TXW_REPEAT), m_wrap_t(TXW_REPEAT), m_wrap_r(TXW_REPEAT),
		m_border_color(v4f{ 0.5f, 0.5f, 0.5f, 1.0f })
	{
	}
	txr_smp::~txr_smp() { if (m_handle != 0) { glDeleteSamplers(1, &m_handle); m_handle = 0; } }
	// --setters
	void txr_smp::set_slot(ui8 slot) {
		m_slot = slot;
	}
	// --==<core_methods>==--
	bit txr_smp::remake(fltr filter, wrap wrap_s, wrap wrap_t, wrap wrap_r)
	{
		if (filter != TXFL_DEFAULT) { m_filter = filter; }
		if (wrap_s != TXW_DEFAULT) { m_wrap_s = wrap_s; }
		if (wrap_t != TXW_DEFAULT) { m_wrap_t = wrap_t; }
		if (wrap_r != TXW_DEFAULT) { m_wrap_r = wrap_r; }
		if (m_handle != 0) { glDeleteSamplers(1, &m_handle); m_handle = 0; }

		glGenSamplers(1, &m_handle);
		glSamplerParameteri(m_handle, GL_TEXTURE_MIN_FILTER, convert_enum<txr_filters, GLenum>(m_filter));
		glSamplerParameteri(m_handle, GL_TEXTURE_MAG_FILTER, convert_enum<txr_filters, GLenum>(m_filter));
		glSamplerParameteri(m_handle, GL_TEXTURE_WRAP_S, convert_enum<txr_wraps, GLenum>(m_wrap_s));
		glSamplerParameteri(m_handle, GL_TEXTURE_WRAP_T, convert_enum<txr_wraps, GLenum>(m_wrap_t));
		glSamplerParameteri(m_handle, GL_TEXTURE_WRAP_R, convert_enum<txr_wraps, GLenum>(m_wrap_r));
		glSamplerParameterfv(m_handle, GL_TEXTURE_BORDER_COLOR, &m_border_color[0]);

		return true;
	}
	bit txr_smp::remake(v4f border_color, fltr filter, wrap wrap_s, wrap wrap_t, wrap wrap_r)
	{
		m_border_color = border_color;
		if (filter != TXFL_DEFAULT) { m_filter = filter; }
		if (wrap_s != TXW_DEFAULT) { m_wrap_s = wrap_s; }
		if (wrap_t != TXW_DEFAULT) { m_wrap_t = wrap_t; }
		if (wrap_r != TXW_DEFAULT) { m_wrap_r = wrap_r; }
		if (m_handle != 0) { glDeleteSamplers(1, &m_handle); m_handle = 0; }

		glGenSamplers(1, &m_handle);
		glSamplerParameteri(m_handle, GL_TEXTURE_MIN_FILTER, convert_enum<txr_filters, GLenum>(m_filter));
		glSamplerParameteri(m_handle, GL_TEXTURE_MAG_FILTER, convert_enum<txr_filters, GLenum>(m_filter));
		glSamplerParameteri(m_handle, GL_TEXTURE_WRAP_S, convert_enum<txr_wraps, GLenum>(m_wrap_s));
		glSamplerParameteri(m_handle, GL_TEXTURE_WRAP_T, convert_enum<txr_wraps, GLenum>(m_wrap_t));
		glSamplerParameteri(m_handle, GL_TEXTURE_WRAP_R, convert_enum<txr_wraps, GLenum>(m_wrap_r));
		glSamplerParameterfv(m_handle, GL_TEXTURE_BORDER_COLOR, &m_border_color[0]);

		return true;
	}
	void txr_smp::on_draw()
	{
		glBindSampler(m_slot, m_handle);
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	txr_smp::txr_smp(gfx_engine& graphics) :
		t_cmp(), a_gfx_cmp(graphics),
		m_handle(nullptr),
		m_slot(0),
		m_filter(TXFL_NEAREST),
		m_wrap_s(TXW_REPEAT), m_wrap_t(TXW_REPEAT), m_wrap_r(TXW_REPEAT),
		m_border_color(v4f{ 0.5f, 0.5f, 0.5f, 1.0f })
	{
	}
	txr_smp::~txr_smp() { if (m_handle != nullptr) { m_handle->Release(); m_handle = nullptr; } }
	// --setters
	void txr_smp::set_slot(ui8 slot) {
		m_slot = slot;
	}
	// --==<core_methods>==--
	bit txr_smp::remake(fltr filter, wrap wrap_s, wrap wrap_t, wrap wrap_r)
	{
		if (filter != TXFL_DEFAULT) { m_filter = filter; }
		if (wrap_s != TXW_DEFAULT) { m_wrap_s = wrap_s; }
		if (wrap_t != TXW_DEFAULT) { m_wrap_t = wrap_t; }
		if (wrap_r != TXW_DEFAULT) { m_wrap_r = wrap_r; }
		if (m_handle != nullptr) { m_handle->Release(); m_handle = nullptr; }
		
		D3D11_SAMPLER_DESC smp_desc{ };
		//smp_desc.AddressU = convert_enum<txr_wraps, D3D11_TEXTURE_ADDRESS_MODE>(m_wrap_s);
		//smp_desc.AddressV = convert_enum<txr_wraps, D3D11_TEXTURE_ADDRESS_MODE>(m_wrap_t);
		//smp_desc.AddressW = convert_enum<txr_wraps, D3D11_TEXTURE_ADDRESS_MODE>(m_wrap_r);
		//smp_desc.Filter = convert_enum<txr_filters, D3D11_FILTER>(m_filter);
		smp_desc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
		smp_desc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
		smp_desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
		smp_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
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
		if (m_handle == nullptr) { throw init_error(__FILE__, __LINE__); return false; }

		return true;
	}
	bit txr_smp::remake(v4f border_color, fltr filter, wrap wrap_s, wrap wrap_t, wrap wrap_r)
	{
		m_border_color = border_color;
		if (filter != TXFL_DEFAULT) { m_filter = filter; }
		if (wrap_s != TXW_DEFAULT) { m_wrap_s = wrap_s; }
		if (wrap_t != TXW_DEFAULT) { m_wrap_t = wrap_t; }
		if (wrap_r != TXW_DEFAULT) { m_wrap_r = wrap_r; }
		if (m_handle != nullptr) { m_handle->Release(); m_handle = nullptr; }
		
		D3D11_SAMPLER_DESC smp_desc{ };
		//smp_desc.AddressU = convert_enum<txr_wraps, D3D11_TEXTURE_ADDRESS_MODE>(m_wrap_s);
		//smp_desc.AddressV = convert_enum<txr_wraps, D3D11_TEXTURE_ADDRESS_MODE>(m_wrap_t);
		//smp_desc.AddressW = convert_enum<txr_wraps, D3D11_TEXTURE_ADDRESS_MODE>(m_wrap_r);
		//smp_desc.Filter = convert_enum<txr_filters, D3D11_FILTER>(m_filter);
		smp_desc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
		smp_desc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
		smp_desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
		smp_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
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
		if (m_handle == nullptr) { throw init_error(__FILE__, __LINE__); return false; }

		return true;
	}
	void txr_smp::on_draw()
	{
		m_gfx->get_ctxh()->PSSetSamplers(m_slot, 1, &m_handle);
	}
	// --==</core_methods>==--
}
#endif
#endif	// NW_GAPI