#include "nc_gfx_pch.hpp"
#include "nc_gfx_txr_2d.h"
#if (defined NC_GAPI)
#	include "../../core/nc_nc_gfx_eng.h"
	#if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	gfx_txr2d_t::gfx_txr2d_t() :
		gfx_txr_t()
	{
	}
	gfx_txr2d_t::~gfx_txr2d_t() { }
	// setters //
	// operators //
	op_stream_t& gfx_txr2d_t::operator<<(op_stream_t& stm) const {
		gfx_txr_t::operator<<(stm);
		return stm;
	}
	ip_stream_t& gfx_txr2d_t::operator>>(ip_stream_t& stm) {
		gfx_txr_t::operator>>(stm);
		return stm;
	}
	// commands //
	v1bit_t gfx_txr2d_t::remake()
	{
		NC_CHECK(gfx_txr_t::remake(), "remake error!", return NC_FALSE);
		NC_CHECK(has_size(), "no size!", return NC_FALSE);
		
		get_context()->txr_bind(GL_TEXTURE_2D, get_handle());

		v4f_t border_color = { 0.5f, 0.5f, 0.5f, 1.0f };
		get_context()->txr_bind(GL_TEXTURE_2D, get_handle());
		get_context()->txr_set_param_n1s(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		get_context()->txr_set_param_n1s(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		get_context()->txr_set_param_n1s(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		get_context()->txr_set_param_n1s(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		get_context()->txr_set_param_v1f(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, &border_color[0]);

		get_context()->txr_set_image_2d(GL_TEXTURE_2D, 0, get_format(), get_size_x(), get_size_y(), 0, get_format(), get_pxtype(), get_data());
		get_context()->txr_new_mipmap(GL_TEXTURE_2D);

		return NC_TRUTH;
	}
	v1nil_t gfx_txr2d_t::clear(ptr_tc data)
	{
		gfx_txr_t::clear(data);
	}
	v1nil_t gfx_txr2d_t::on_draw()
	{
		gfx_txr_t::on_draw();

		// get_context()->set_enabled(GL_TEXTURE_2D);
		get_context()->txr_bind(GL_TEXTURE_2D, get_handle());
	}
	// --==</core_methods>==--
}
namespace NC
{
	gfx_txr2d_mulsmp_t::gfx_txr2d_mulsmp_t() :
		gfx_txr2d_t(),
		m_samples(NC_NULL)
	{
	}
	gfx_txr2d_mulsmp_t::~gfx_txr2d_mulsmp_t() { }
	// setters //
	v1nil_t gfx_txr2d_mulsmp_t::set_samples(v1u_t samples) {
		m_samples = samples;
	}
	// operators //
	op_stream_t& gfx_txr2d_mulsmp_t::operator<<(op_stream_t& stm) const {
		return stm;
	}
	ip_stream_t& gfx_txr2d_mulsmp_t::operator>>(ip_stream_t& stm) {
		return stm;
	}
	// commands //
	v1bit_t gfx_txr2d_mulsmp_t::remake()
	{
		NC_CHECK(gfx_txr_t::remake(), "remake error!", return NC_FALSE);
		NC_CHECK(has_size(), "no size!", return NC_FALSE);
		
		get_context()->txr_new(1, &m_handle);
		get_context()->txr_bind(GL_TEXTURE_2D, get_handle());

		get_context()->txr_set_image_2d_mulsmp(GL_TEXTURE_2D_MULTISAMPLE, get_samples(), get_format(), get_size_x(), get_size_y(), GL_FALSE);

		return NC_TRUTH;
	}
	v1nil_t gfx_txr2d_mulsmp_t::on_draw()
	{
		gfx_txr_t::on_draw();

		// get_context()->set_enabled(GL_MULTISAMPLE);
		get_context()->txr_bind(GL_TEXTURE_2D_MULTISAMPLE, get_handle());
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
namespace NC
{
	gfx_txr2d_t::gfx_txr2d_t(nc_gfx_eng& graphics) :
		gfx_txr_t(graphics),
		m_native(NC_NULL)
	{
	}
	gfx_txr2d_t::~gfx_txr2d_t() { if (m_native != NC_NULL) { m_native->Release(); m_native = NC_NULL; } }
	// setters //
	// operators //
	stm_out& gfx_txr2d_t::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& gfx_txr2d_t::operator>>(stm_in& stm) {
		return stm;
	}
	// commands //
	v1bit_t gfx_txr2d_t::remake(const gfx_img_t& source)
	{
		if (m_native != NC_NULL) { m_native->Release(); m_native = NC_NULL; }

		if (!gfx_txr_t::remake(source)) { return NC_FALSE; }
		if (get_size_x() <= 0 || get_size_y() <= 0) { return NC_FALSE; }
		// texture
		{
			D3D11_TEXTURE2D_DESC desc{ 0 };
			desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
			desc.Format = m_pxl_fmt;
			desc.Width = get_size_x();
			desc.Height = get_size_y();
			desc.MipLevels = 1u;
			desc.ArraySize = 1u;
			desc.SampleDesc.Count = 1u;
			desc.SampleDesc.Quality = 0u;
			desc.MiscFlags = 0u;

			if (get_data() == NC_NULL) {
				desc.Usage = D3D11_USAGE_DYNAMIC;
				desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
				m_gfx->get_dvch()->CreateTexture2D(&desc, NC_NULL, &m_native);
			}
			else {
				desc.Usage = D3D11_USAGE_DEFAULT;
				desc.CPUAccessFlags = 0u;
				D3D11_SUBRESOURCE_DATA data{ 0 };
				data.pSysMem = get_data();
				data.SysMemPitch = get_size_x() * m_channels;
				data.SysMemSlicePitch = get_size_x() * get_size_y() * m_channels;
				m_gfx->get_dvch()->CreateTexture2D(&desc, &data, &m_native);
			}
			if (m_native == NC_NULL) { throw init_error(__FILE__, __LINE__); return NC_FALSE; }
		}
		// shader_resource_view
		{
			D3D11_SHADER_RESOURCE_VIEW_DESC desc{ };
			desc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
			desc.Format = m_pxl_fmt;
			desc.Texture2D.MostDetailedMip = 0u;
			desc.Texture2D.MipLevels = 1u;
			m_gfx->get_dvch()->CreateShaderResourceView(m_native, &desc, &m_handle);
			if (m_handle == NC_NULL) { throw init_error(__FILE__, __LINE__); return NC_FALSE; }
		}

		return NC_TRUTH;
	}
	void gfx_txr2d_t::clear(ptr value)
	{
	}
	void gfx_txr2d_t::on_draw()
	{
		gfx_txr_t::on_draw();
	}
	// --==</core_methods>==--
}
namespace NC
{
	gfx_txr2d_mulsmp_t::gfx_txr2d_mulsmp_t(nc_gfx_eng& graphics) :
		gfx_txr2d_t(graphics),
		m_samples(0)
	{
	}
	gfx_txr2d_mulsmp_t::~gfx_txr2d_mulsmp_t() { if (m_native != NC_NULL) { m_native->Release(); m_native = NC_NULL; } }
	// setters //
	void gfx_txr2d_mulsmp_t::set_samples(v1u_t samples) {
		m_samples = samples;
	}
	// operators //
	stm_out& gfx_txr2d_mulsmp_t::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& gfx_txr2d_mulsmp_t::operator>>(stm_in& stm) {
		return stm;
	}
	// commands //
	v1bit_t gfx_txr2d_mulsmp_t::remake(const gfx_img_t& img)
	{
		if (m_native != NC_NULL) { m_native->Release(); m_native = NC_NULL; }
		
		if (!gfx_txr_t::remake(img)) { return NC_FALSE; }
		if (get_size_x() <= 0 || get_size_y() <= 0) { return NC_FALSE; }
		
		return NC_TRUTH;
	}
	void gfx_txr2d_mulsmp_t::on_draw()
	{
		gfx_txr_t::on_draw();
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NC_GAPI