#include "nc_gfx_pch.hpp"
#include "nc_gfx_txr_1d.hxx"
#if (defined NC_GAPI)
#	include "../../core/nc_nc_gfx_eng.hxx"
#	include "../img/nc_gfx_img.hxx"
#	if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	gfx_txr1d_t::gfx_txr1d_t() :
		gfx_txr_t()
	{
	}
	gfx_txr1d_t::~gfx_txr1d_t()
	{
	}
	/* setters */
	/* operators */
	nc_ostream_t& gfx_txr1d_t::operator<<(nc_ostream_t& stm) const {
		gfx_txr_t::operator<<(stm);
		return stm;
	}
	nc_istream_t& gfx_txr1d_t::operator>>(nc_istream_t& stm) {
		gfx_txr_t::operator>>(stm);
		return stm;
	}
	/* command */
	v1bit_t gfx_txr1d_t::remake()
	{
		NC_CHECK(gfx_txr_t::remake(), "remake error!", return NC_FALSE);
		NC_CHECK(get_size() > 0, "no size!", return NC_FALSE);

		get_context()->txr_bind(GL_TEXTURE_1D, get_handle());

		v4f_t border_color = { 0.5f, 0.5f, 0.5f, 1.0f };
		get_context()->txr_set_param_n1s(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		get_context()->txr_set_param_n1s(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		get_context()->txr_set_param_n1s(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		get_context()->txr_set_param_v1f(GL_TEXTURE_1D, GL_TEXTURE_BORDER_COLOR, &border_color[0]);

		get_context()->txr_set_image_1d(
			GL_TEXTURE_1D, 0, get_format(),
			get_size_x(), 0,
			get_format(), get_pxtype(), get_data()
		);
		get_context()->txr_new_mipmap(GL_TEXTURE_1D);

		return NC_TRUTH;
	}
	v1nil_t gfx_txr1d_t::clear(ptr_tc data)
	{
		gfx_txr_t::clear(data);
	}
	v1nil_t gfx_txr1d_t::on_draw()
	{
		gfx_txr_t::on_draw();

		// get_context()->set_enabled(GL_TEXTURE_1D);
		get_context()->txr_bind(GL_TEXTURE_1D, get_handle());
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
namespace NC
{
	gfx_txr1d_t::gfx_txr1d_t(nc_gfx_eng& graphics) :
		gfx_txr_t(graphics)
	{
	}
	gfx_txr1d_t::~gfx_txr1d_t() { if (m_native != NC_NULL) { m_native->Release(); m_native = NC_NULL; } }
	/* setters */
	/* operators */
	/* operators */
	nc_ostream_t& gfx_txr1d_t::operator<<(nc_ostream_t& stm) const {
		return stm;
	}
	nc_istream_t& gfx_txr1d_t::operator>>(nc_istream_t& stm) {
		return stm;
	}
	/* command */
	v1bit_t gfx_txr1d_t::remake(const gfx_img_t& img)
	{
		if (m_native != NC_NULL) { m_native->Release(); m_native = NC_NULL; }

		if (!gfx_txr_t::remake(img)) { return NC_FALSE; }
		if (m_size_x <= 0) { return NC_FALSE; }
		// texture
		{
			D3D11_TEXTURE1D_DESC desc{ 0 };
			desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
			desc.MiscFlags = 0u;
			desc.Format = m_pxl_fmt;
			desc.Width = m_size_x;
			desc.ArraySize = 1u;
			desc.MipLevels = 1u;
			if (get_data() == NC_NULL){
				desc.Usage = D3D11_USAGE_DYNAMIC;
				desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
				m_gfx->get_dvch()->CreateTexture1D(&desc, NC_NULL, &m_native);
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
			if (m_handle == NC_NULL) { throw init_error(__FILE__, __LINE__); return NC_FALSE; }
		}
		// shader_resource_view
		{
			D3D11_SHADER_RESOURCE_VIEW_DESC desc{ };
			desc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE1D;
			desc.Format = m_pxl_fmt;
			desc.Texture1D.MipLevels = 1u;
			desc.Texture1D.MostDetailedMip = 0u;
			m_gfx->get_dvch()->CreateShaderResourceView(m_native, &desc, &m_handle);
			if (m_handle == NC_NULL) { throw init_error(__FILE__, __LINE__); return NC_FALSE; }
		}

		return NC_TRUTH;
	}
	v1nil_t gfx_txr1d_t::clear(ptr value)
	{
	}
	v1nil_t gfx_txr1d_t::on_draw()
	{
		gfx_txr_t::on_draw();
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NC_GAPI