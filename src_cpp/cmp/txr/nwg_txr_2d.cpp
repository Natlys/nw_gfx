#include <nwg_pch.hpp>
#include "nwg_txr_2d.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#include <lib/nwg_load_txr.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	txr_2d::txr_2d(gfx_engine& graphics) :
		a_txr(graphics)
	{
	}
	txr_2d::~txr_2d() { }
	// --setters
	// --operators
	stm_out& txr_2d::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& txr_2d::operator>>(stm_in& stm) {
		return stm;
	}
	// --==<core_methods>==--
	bit txr_2d::remake(const img_cmp& img)
	{
		set_data(img);
		if (m_handle != 0) { glDeleteTextures(1, &m_handle); m_handle = 0; }
		if (m_channels <= 0 || m_size_x <= 0 || m_size_y <= 0) { return false; }
		glGenTextures(1, &m_handle);
		glBindTexture(GL_TEXTURE_2D, m_handle);

		v4f border_color = { 0.5f, 0.5f, 0.5f, 1.0f };
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, &border_color[0]);

		GLenum ogl_data_type = convert_enum<data_types, GLenum>(m_data_type);
		GLenum ogl_inter_fmt = convert_enum<txr_formats, GLenum>(m_txr_fmt);
		GLenum ogl_img_fmt = convert_enum<txr_formats, GLenum>(m_txr_fmt);
		glTexImage2D(GL_TEXTURE_2D, 0, ogl_inter_fmt, m_size_x, m_size_y, 0, ogl_img_fmt, ogl_data_type, &m_pxl_data[0]);
		glGenerateMipmap(GL_TEXTURE_2D);

		return true;
	}
	void txr_2d::clear(ptr value) {
		glClearTexImage(m_handle, 0,
			convert_enum<pixel_formats, GLenum>(m_pxl_fmt),
			convert_enum<pixel_formats, GLenum>(m_pxl_fmt), value);
	}
	void txr_2d::on_draw()
	{
		a_txr::on_draw();

		glEnable(GL_TEXTURE_2D);
		glActiveTexture(GL_TEXTURE0 + m_slot);
		glBindTexture(GL_TEXTURE_2D, m_handle);
	}
	// --==</core_methods>==--
}
namespace NW
{
	txr_2d_mulsmp::txr_2d_mulsmp(gfx_engine& graphics) :
		txr_2d(graphics),
		m_samples(0)
	{
	}
	txr_2d_mulsmp::~txr_2d_mulsmp() { }
	// --setters
	void txr_2d_mulsmp::set_samples(ui8 samples) {
		m_samples = samples;
	}
	// --operators
	stm_out& txr_2d_mulsmp::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& txr_2d_mulsmp::operator>>(stm_in& stm) {
		return stm;
	}
	// --==<core_methods>==--
	bit txr_2d_mulsmp::remake(const img_cmp& img)
	{
		m_size_x = img.get_size_x();
		m_size_y = img.get_size_y();
		m_pxl_fmt = img.get_pxl_fmt();
		m_channels = img.get_channels();
		if (m_handle != 0) { glDeleteTextures(1, &m_handle); m_handle = 0; }
		if (m_channels <= 0 || m_size_x <= 0 || m_size_y <= 0) { return false; }
		glGenTextures(1, &m_handle);
		glBindTexture(GL_TEXTURE_2D, m_handle);

		glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, m_samples,
			convert_enum<pixel_formats, GLenum>(m_pxl_fmt),
			m_size_x, m_size_y, false);
		return true;
	}
	void txr_2d_mulsmp::on_draw()
	{
		a_txr::on_draw();

		glEnable(GL_MULTISAMPLE);
		glActiveTexture(GL_TEXTURE0 + m_slot);
		glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, m_handle);
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	txr_2d::txr_2d(gfx_engine& graphics) :
		a_txr(graphics),
		m_native(nullptr)
	{
	}
	txr_2d::~txr_2d() { if (m_native != nullptr) { m_native->Release(); m_native = nullptr; } }
	// --setters
	// --operators
	stm_out& txr_2d::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& txr_2d::operator>>(stm_in& stm) {
		return stm;
	}
	// --==<core_methods>==--
	bit txr_2d::remake(const img_cmp& source)
	{
		set_data(source);
		if (m_handle != nullptr) { m_handle->Release(); m_handle = nullptr; }
		if (m_native != nullptr) { m_native->Release(); m_native = nullptr; }
		if (m_size_x <= 0 || m_size_y <= 0 || m_channels <= 0) { return false; }
		
		// create the texture itself
		D3D11_TEXTURE2D_DESC txr_desc{ 0 };
		txr_desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
		//txr_desc.Format = convert_enum<pixel_formats, DXGI_FORMAT>(m_pxl_fmt);
		txr_desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		txr_desc.MiscFlags = 0u;
		txr_desc.Width = m_size_x;
		txr_desc.Height = m_size_y;
		txr_desc.MipLevels = 1;
		txr_desc.ArraySize = 1; 
		txr_desc.SampleDesc.Count = 1;
		txr_desc.SampleDesc.Quality = 0;

		if (get_data() == nullptr) {
			txr_desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
			D3D11_SUBRESOURCE_DATA sub_data{ 0 };
			sub_data.pSysMem = get_data();
			sub_data.SysMemPitch = m_size_x * m_channels;	// bytes of the entire row
			m_gfx->get_dvch()->CreateTexture2D(&txr_desc, &sub_data, &m_native);
		}
		else {
			txr_desc.CPUAccessFlags = 0u;
			m_gfx->get_dvch()->CreateTexture2D(&txr_desc, nullptr, &m_native);
		}
		if (m_native == nullptr) { throw init_error(__FILE__, __LINE__); return false; }

		// create resource view to display the texture
		D3D11_SHADER_RESOURCE_VIEW_DESC shd_rsc_desc{ };
		//shd_rsc_desc.Format = convert_enum<pixel_formats, DXGI_FORMAT>(m_pxl_fmt);
		shd_rsc_desc.Format = txr_desc.Format;
		shd_rsc_desc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
		shd_rsc_desc.Texture2D.MostDetailedMip = 0;
		shd_rsc_desc.Texture2D.MipLevels = 1;

		m_gfx->get_dvch()->CreateShaderResourceView(m_native, &shd_rsc_desc, &m_handle);
		if (m_handle == nullptr) { throw init_error(__FILE__, __LINE__); return false; }

		return true;
	}
	void txr_2d::clear(ptr value)
	{
	}
	void txr_2d::on_draw()
	{
		a_txr::on_draw();

		m_gfx->get_ctxh()->PSSetShaderResources(m_slot, 1, &m_handle);
	}
	// --==</core_methods>==--
}
namespace NW
{
	txr_2d_mulsmp::txr_2d_mulsmp(gfx_engine& graphics) :
		txr_2d(graphics),
		m_samples(0)
	{
	}
	txr_2d_mulsmp::~txr_2d_mulsmp() { if (m_native != nullptr) { m_native->Release(); m_native = nullptr; } }
	// --setters
	void txr_2d_mulsmp::set_samples(ui8 samples) {
		m_samples = samples;
	}
	// --operators
	stm_out& txr_2d_mulsmp::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& txr_2d_mulsmp::operator>>(stm_in& stm) {
		return stm;
	}
	// --==<core_methods>==--
	bit txr_2d_mulsmp::remake(const img_cmp& img)
	{
		m_size_x = img.get_size_x();
		m_size_y = img.get_size_y();
		m_pxl_fmt = img.get_pxl_fmt();
		m_channels = img.get_channels();
		if (m_handle != nullptr) { m_handle->Release(); m_handle = nullptr; }
		if (m_native != nullptr) { m_native->Release(); m_native = nullptr; }
		if (m_channels <= 0 || m_size_x <= 0 || m_size_y <= 0) { return false; }
		
		return true;
	}
	void txr_2d_mulsmp::on_draw()
	{
		a_txr::on_draw();
	}
	// --==</core_methods>==--
}
#endif
#endif	// NW_GAPI