#include "nw_gfx_pch.hpp"
#include "nw_gfx_txr_2d.h"
#if (defined NW_GAPI)
#	include "../../core/nw_gfx_engine.h"
#	include "../../lib/nw_gfx_lib_txr.h"
	#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_txr_2d::gfx_txr_2d() :
		gfx_txr()
	{
	}
	gfx_txr_2d::~gfx_txr_2d() { }
	// --setters
	// --operators
	op_stream_t& gfx_txr_2d::operator<<(op_stream_t& stm) const {
		gfx_txr::operator<<(stm);
		return stm;
	}
	ip_stream_t& gfx_txr_2d::operator>>(ip_stream_t& stm) {
		gfx_txr::operator>>(stm);
		return stm;
	}
	// --==<core_methods>==--
	v1bit gfx_txr_2d::remake()
	{
		NW_CHECK(gfx_txr::remake(), "remake error!", return NW_FALSE);
		NW_CHECK(has_size(), "no size!", return NW_FALSE);
		
		glBindTexture(GL_TEXTURE_2D, get_handle());

		v4f border_color = { 0.5f, 0.5f, 0.5f, 1.0f };
		glBindTexture(GL_TEXTURE_2D, get_handle());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, &border_color[0]);

		glTexImage2D(GL_TEXTURE_2D, 0, get_format(), get_size_x(), get_size_y(), 0, get_format(), get_pxtype(), get_data());
		glGenerateMipmap(GL_TEXTURE_2D);

		return NW_TRUE;
	}
	v1nil gfx_txr_2d::clear(ptr_tc data)
	{
		gfx_txr::clear(data);
	}
	v1nil gfx_txr_2d::on_draw()
	{
		gfx_txr::on_draw();

		// glEnable(GL_TEXTURE_2D);
		glActiveTexture(GL_TEXTURE0 + get_slot());
		glBindTexture(GL_TEXTURE_2D, get_handle());
	}
	// --==</core_methods>==--
}
namespace NW
{
	gfx_txr_2d_mulsmp::gfx_txr_2d_mulsmp() :
		gfx_txr_2d(),
		m_samples(NW_NULL)
	{
	}
	gfx_txr_2d_mulsmp::~gfx_txr_2d_mulsmp() { }
	// --setters
	v1nil gfx_txr_2d_mulsmp::set_samples(v1u samples) {
		m_samples = samples;
	}
	// --operators
	op_stream_t& gfx_txr_2d_mulsmp::operator<<(op_stream_t& stm) const {
		return stm;
	}
	ip_stream_t& gfx_txr_2d_mulsmp::operator>>(ip_stream_t& stm) {
		return stm;
	}
	// --==<core_methods>==--
	v1bit gfx_txr_2d_mulsmp::remake()
	{
		NW_CHECK(gfx_txr::remake(), "remake error!", return NW_FALSE);
		NW_CHECK(has_size(), "no size!", return NW_FALSE);
		
		glGenTextures(1, &m_handle);
		glBindTexture(GL_TEXTURE_2D, get_handle());

		glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, get_samples(), get_format(), get_size_x(), get_size_y(), GL_FALSE);

		return NW_TRUE;
	}
	v1nil gfx_txr_2d_mulsmp::on_draw()
	{
		gfx_txr::on_draw();

		// glEnable(GL_MULTISAMPLE);
		glActiveTexture(GL_TEXTURE0 + get_slot());
		glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, get_handle());
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	gfx_txr_2d::gfx_txr_2d(gfx_engine& graphics) :
		gfx_txr(graphics),
		m_native(NW_NULL)
	{
	}
	gfx_txr_2d::~gfx_txr_2d() { if (m_native != NW_NULL) { m_native->Release(); m_native = NW_NULL; } }
	// --setters
	// --operators
	stm_out& gfx_txr_2d::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& gfx_txr_2d::operator>>(stm_in& stm) {
		return stm;
	}
	// --==<core_methods>==--
	v1bit gfx_txr_2d::remake(const gfx_img& source)
	{
		if (m_native != NW_NULL) { m_native->Release(); m_native = NW_NULL; }

		if (!gfx_txr::remake(source)) { return NW_FALSE; }
		if (get_size_x() <= 0 || get_size_y() <= 0) { return NW_FALSE; }
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

			if (get_data() == NW_NULL) {
				desc.Usage = D3D11_USAGE_DYNAMIC;
				desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
				m_gfx->get_dvch()->CreateTexture2D(&desc, NW_NULL, &m_native);
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
			if (m_native == NW_NULL) { throw init_error(__FILE__, __LINE__); return NW_FALSE; }
		}
		// shader_resource_view
		{
			D3D11_SHADER_RESOURCE_VIEW_DESC desc{ };
			desc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
			desc.Format = m_pxl_fmt;
			desc.Texture2D.MostDetailedMip = 0u;
			desc.Texture2D.MipLevels = 1u;
			m_gfx->get_dvch()->CreateShaderResourceView(m_native, &desc, &m_handle);
			if (m_handle == NW_NULL) { throw init_error(__FILE__, __LINE__); return NW_FALSE; }
		}

		return NW_TRUE;
	}
	void gfx_txr_2d::clear(ptr value)
	{
	}
	void gfx_txr_2d::on_draw()
	{
		gfx_txr::on_draw();
	}
	// --==</core_methods>==--
}
namespace NW
{
	gfx_txr_2d_mulsmp::gfx_txr_2d_mulsmp(gfx_engine& graphics) :
		gfx_txr_2d(graphics),
		m_samples(0)
	{
	}
	gfx_txr_2d_mulsmp::~gfx_txr_2d_mulsmp() { if (m_native != NW_NULL) { m_native->Release(); m_native = NW_NULL; } }
	// --setters
	void gfx_txr_2d_mulsmp::set_samples(v1u samples) {
		m_samples = samples;
	}
	// --operators
	stm_out& gfx_txr_2d_mulsmp::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& gfx_txr_2d_mulsmp::operator>>(stm_in& stm) {
		return stm;
	}
	// --==<core_methods>==--
	v1bit gfx_txr_2d_mulsmp::remake(const gfx_img& img)
	{
		if (m_native != NW_NULL) { m_native->Release(); m_native = NW_NULL; }
		
		if (!gfx_txr::remake(img)) { return NW_FALSE; }
		if (get_size_x() <= 0 || get_size_y() <= 0) { return NW_FALSE; }
		
		return NW_TRUE;
	}
	void gfx_txr_2d_mulsmp::on_draw()
	{
		gfx_txr::on_draw();
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NW_GAPI