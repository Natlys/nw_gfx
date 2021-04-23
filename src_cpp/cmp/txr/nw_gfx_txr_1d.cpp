#include "nw_gfx_pch.hpp"
#include "nw_gfx_txr_1d.h"
#if (defined NW_GAPI)
#	include "../../core/nw_gfx_engine.h"
#	include "../../lib/nw_gfx_lib_txr.h"
#	include "../img/nw_gfx_img.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_txr_1d::gfx_txr_1d() :
		a_gfx_txr()
	{
	}
	gfx_txr_1d::~gfx_txr_1d()
	{
	}
	// --setters
	// --operators
	op_stream_t& gfx_txr_1d::operator<<(op_stream_t& stm) const {
		a_gfx_txr::operator<<(stm);
		return stm;
	}
	ip_stream_t& gfx_txr_1d::operator>>(ip_stream_t& stm) {
		a_gfx_txr::operator>>(stm);
		return stm;
	}
	// --==<core_methods>==--
	v1bit gfx_txr_1d::remake()
	{
		NW_CHECK(a_gfx_txr::remake(), "failed remake!", return NW_FALSE);
		NW_CHECK(get_size() > 0, "no size!", return NW_FALSE);

		glBindTexture(GL_TEXTURE_1D, get_handle());

		v4f border_color = { 0.5f, 0.5f, 0.5f, 1.0f };
		glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterfv(GL_TEXTURE_1D, GL_TEXTURE_BORDER_COLOR, &border_color[0]);

		glTexImage1D(
			GL_TEXTURE_1D, 0, get_format(),
			get_size_x(), 0,
			get_format(), get_pxtype(), get_data()
		);
		glGenerateMipmap(GL_TEXTURE_1D);

		return NW_TRUE;
	}
	v1nil gfx_txr_1d::clear(ptr_tc data)
	{
		a_gfx_txr::clear(data);
	}
	v1nil gfx_txr_1d::on_draw()
	{
		a_gfx_txr::on_draw();

		// glEnable(GL_TEXTURE_1D);
		glBindTexture(GL_TEXTURE_1D, get_handle());
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	gfx_txr_1d::gfx_txr_1d(gfx_engine& graphics) :
		a_gfx_txr(graphics)
	{
	}
	gfx_txr_1d::~gfx_txr_1d() { if (m_native != NW_NULL) { m_native->Release(); m_native = NW_NULL; } }
	// --setters
	// --operators
	// --operators
	op_stream_t& gfx_txr_1d::operator<<(op_stream_t& stm) const {
		return stm;
	}
	ip_stream_t& gfx_txr_1d::operator>>(ip_stream_t& stm) {
		return stm;
	}
	// --==<core_methods>==--
	v1bit gfx_txr_1d::remake(const gfx_img& img)
	{
		if (m_native != NW_NULL) { m_native->Release(); m_native = NW_NULL; }

		if (!a_gfx_txr::remake(img)) { return NW_FALSE; }
		if (m_size_x <= 0) { return NW_FALSE; }
		// texture
		{
			D3D11_TEXTURE1D_DESC desc{ 0 };
			desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
			desc.MiscFlags = 0u;
			desc.Format = m_pxl_fmt;
			desc.Width = m_size_x;
			desc.ArraySize = 1u;
			desc.MipLevels = 1u;
			if (get_data() == NW_NULL){
				desc.Usage = D3D11_USAGE_DYNAMIC;
				desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
				m_gfx->get_dvch()->CreateTexture1D(&desc, NW_NULL, &m_native);
			}
			else {
				desc.Usage = D3D11_USAGE_DEFAULT;
				desc.CPUAccessFlags = 0u;
				D3D11_SUBRESOURCE_DATA data{ 0 };
				data.pSysMem = get_data();
				data.SysMemPitch = m_size_x * m_channels;
				data.SysMemSlicePitch = m_size_x * m_channels;
				m_gfx->get_dvch()->CreateTexture1D(&desc, &data, &m_native);
			}
			if (m_handle == NW_NULL) { throw init_error(__FILE__, __LINE__); return NW_FALSE; }
		}
		// shader_resource_view
		{
			D3D11_SHADER_RESOURCE_VIEW_DESC desc{ };
			desc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE1D;
			desc.Format = m_pxl_fmt;
			desc.Texture1D.MipLevels = 1u;
			desc.Texture1D.MostDetailedMip = 0u;
			m_gfx->get_dvch()->CreateShaderResourceView(m_native, &desc, &m_handle);
			if (m_handle == NW_NULL) { throw init_error(__FILE__, __LINE__); return NW_FALSE; }
		}

		return NW_TRUE;
	}
	v1nil gfx_txr_1d::clear(ptr value)
	{
	}
	v1nil gfx_txr_1d::on_draw()
	{
		a_gfx_txr::on_draw();
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NW_GAPI