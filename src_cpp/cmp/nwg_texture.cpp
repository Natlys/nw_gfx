#include <nwg_pch.hpp>
#include "nwg_texture.h"
#if (defined NWG_GAPI)
#include <core/nwg_engine.h>
namespace NWG
{
	// --operators
	texture_info& texture_info::operator=(const image_bmp_info& info) {
		image_info::operator=(info);
		return *this;
	}
	texture_info& texture_info::operator=(const image_png_info& info) {
		image_info::operator=(info);
		return *this;
	}
	texture_info& texture_info::operator=(const image_info& info) {
		image_info::operator=(info);
		return *this;
	}
	out_stream& texture_info::operator<<(out_stream& stm) const { return stm; }
	in_stream& texture_info::operator>>(in_stream& stm) { return image_info::operator>>(stm); }
}
#if (NWG_GAPI & NWG_GAPI_OGL)
#include <lib/nwg_ogl_v1.h>
#include <lib/nwg_ogl_v4.h>
#include <lib/nwg_ogl_arb.h>
namespace NWG
{
	a_texture::a_texture(gfx_engine& graphics, cstring name, texture_types txr_type) :
		t_gfx_cmp(graphics), a_data_res(name),
		m_info(texture_info()), m_slot(0),
		m_ogl_id(0) { if (m_ogl_id != 0) { glDeleteTextures(1, &m_ogl_id); m_ogl_id = 0; } }
	a_texture::~a_texture() { }
	// --setters
	void a_texture::set_txr_slot(ui8 texture_slot) { m_slot = texture_slot; }
}
namespace NWG
{
	texture2d::texture2d(gfx_engine& graphics, cstring name) :
		a_texture(graphics, name, TXT_2D) { }
	texture2d::~texture2d() { }
	// --==<core_methods>==--
	void texture2d::on_draw()
	{
		glActiveTexture(GL_TEXTURE0 + m_slot);
		glBindTexture(GL_TEXTURE_2D, m_ogl_id);
	}
	bit texture2d::remake(const texture_info& info)
	{
		if (m_ogl_id != 0) { glDeleteTextures(1, &m_ogl_id); m_ogl_id = 0; }
		if (m_info.nof_samples == 0) { return false; }
		if (m_info.size_x <= 0 || m_info.size_y <= 0 || m_info.nof_channels <= 0) { return false; }
		glGenTextures(1, &m_ogl_id);
		glBindTexture(GL_TEXTURE_2D, m_ogl_id);

		if (m_info.nof_samples == 1) {
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, convert_enum<texture_filters, GLenum>(m_info.filter));
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, convert_enum<texture_filters, GLenum>(m_info.filter));
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, convert_enum<texture_wraps, GLenum>(m_info.wrap_s));
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, convert_enum<texture_wraps, GLenum>(m_info.wrap_t));
			glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, &m_info.border_color[0]);
			glTexImage2D(GL_TEXTURE_2D, 0, convert_enum<texture_formats, GLenum>(m_info.txr_format),
				m_info.size_x, m_info.size_y, 0,
				convert_enum<texture_formats, GLenum>(m_info.txr_format), GL_UNSIGNED_BYTE, &m_info.pxl_data[0]);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else if (m_info.nof_samples > 1) {
			glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, m_info.nof_samples,
				convert_enum<pixel_formats, GLenum>(m_info.pxl_format),
				m_info.size_x, m_info.size_y, false);
		}
		return true;
	}
	void texture2d::clear(ptr value) {
		glClearTexImage(m_ogl_id, 0,
			convert_enum<pixel_formats, GLenum>(m_info.pxl_format),
			convert_enum<pixel_formats, GLenum>(m_info.pxl_format), value);
	}
	// --==</core_methods>==--
	// --==<data_methods>==--
	bit texture2d::save_file(cstring file_path) { return true; }
	bit texture2d::load_file(cstring file_path)
	{
		cstring file_format = str_part_left(&file_path[0], '.');
		if (str_is_equal(file_format, ".txr")) {
			if (!data_sys::load_file(file_path, m_info)) { return false; }
		}
		else if (str_is_equal(file_format, ".bmp")) {
			image_bmp_info bmpInfo;
			if (!data_sys::load_file(file_path, bmpInfo)) { return false; }
			m_info = bmpInfo;
		}
		else if (str_is_equal(file_format, ".png")) {
		}
		return remake(m_info);
	}
	// --==</data_methods>==--
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
#include <lib/nwg_dx_loader.h>
namespace NWG
{
	a_texture::a_texture(gfx_engine& graphics, const char* name, texture_types txr_type) :
		a_gfx_cmp(graphics), a_data_res(name),
		m_info(texture_info()), m_unSlot(0),
		m_pRes(nullptr), m_pSampler(nullptr) { }
	a_texture::~a_texture() {
		if (m_pRes != nullptr) { m_pRes->Release(); m_pRes = nullptr; }
		if (m_pSampler != nullptr) { m_pSampler->Release(); m_pSampler = nullptr; }
	}
	// --setters
	void a_texture::SetSlot(ui8 unSlot) { m_unSlot = unSlot; }
}
namespace NWG
{
	Texture2d::Texture2d(gfx_engine& graphics, const char* name) :
		a_texture(graphics, name, TXT_2D) { }
	Texture2d::~Texture2d() { }
	// --==<core_methods>==--
	void Texture2d::Bind()
	{
		m_gfx->GetContext()->PSSetShaderResources(0, 1, &m_pRes);
		m_gfx->GetContext()->PSSetSamplers(0, 1, &m_pSampler);
	}
	bool Texture2d::Remake(const texture_info& info)
	{
		if (m_pRes != nullptr) { m_pRes->Release(); m_pRes = nullptr; }
		if (m_native != nullptr) { m_native->Release(); m_native = nullptr; }
		if (m_pSampler != nullptr) { m_pSampler->Release(); m_pSampler = nullptr; }
		
		if (m_info.width<= 0 || m_info.height <= 0 || m_info.nChannels <= 0) { return false; }
		if (m_info.wrap_s == TXW_DEFAULT || m_info.wrap_t == TXW_DEFAULT || m_info.wrap_r == TXW_DEFAULT) { return false; }
		if (m_info.Filter == TXF_DEFAULT) { return false; }
		// create texture itself
		D3D11_TEXTURE2D_DESC texDesc{ 0 };
		texDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
		texDesc.CPUAccessFlags = m_Image.GetData() == nullptr ? D3D11_CPU_ACCESS_WRITE : 0u;
		texDesc.Format = convert_enum<pixel_formats, DXGI_FORMAT>(m_info.pxl_format);
		texDesc.MiscFlags = 0u;
		texDesc.Width = m_info.width;
		texDesc.Height = m_info.height;
		texDesc.MipLevels = 1;
		texDesc.ArraySize = 1;
		texDesc.SampleDesc.Count = 1;
		texDesc.SampleDesc.Quality = 0;

		D3D11_SUBRESOURCE_DATA subData{ 0 };
		subData.pSysMem = m_Image.GetData() == nullptr ? m_Image.GetData() : mem_sys::GetMemory().GetDataBeg();
		subData.SysMemPitch = m_info.width* m_info.nChannels;	// adjacent bytes between rows

		ID3D11Texture2D* pTexture = nullptr;
		m_gfx->GetDevice()->CreateTexture2D(&texDesc, &subData, &pTexture);
		if (pTexture == nullptr) { throw error("failed to create a texture"); }

		// create resource view to display the texture
		D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc{ };
		srvDesc.Format = convert_enum<pixel_formats, DXGI_FORMAT>(m_info.pxl_format);
		srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
		srvDesc.Texture2D.MostDetailedMip = 0;
		srvDesc.Texture2D.MipLevels = 1;

		m_gfx->GetDevice()->CreateShaderResourceView(pTexture, &srvDesc, &m_pRes);
		pTexture->Release();
		if (m_native == nullptr) { throw error("unsupported texture type"); return false; }
		
		// create sampler for right texture representation
		D3D11_SAMPLER_DESC smpDesc{ };
		smpDesc.AddressU = convert_enum<texture_wraps, D3D11_TEXTURE_ADDRESS_MODE>(m_info.wrap_s);
		smpDesc.AddressV = convert_enum<texture_wraps, D3D11_TEXTURE_ADDRESS_MODE>(m_info.wrap_t);
		smpDesc.AddressW = convert_enum<texture_wraps, D3D11_TEXTURE_ADDRESS_MODE>(m_info.wrap_r);
		smpDesc.Filter = convert_enum<texture_filters, D3D11_FILTER>(m_info.Filter);
		smpDesc.BorderColor;	// for the "border" wrapper
		smpDesc.ComparisonFunc;	//
		smpDesc.MaxAnisotropy;	// for the filter "anostropy"
		smpDesc.MinLOD;			// minimal level of details
		smpDesc.MaxLOD;			// maximal level of details
		smpDesc.MipLODBias;		// level of details for mipmapping
		m_gfx->GetDevice()->CreateSamplerState(&smpDesc, &m_pSampler);
		if (m_native == nullptr) { throw error("sampler was not created"); return false; }
		
		return true;
	}
	void Texture2d::Clear(Ptr pValue) { }
	// --==</core_methods>==--
	// --==<data_methods>==--
	bool Texture2d::SaveF(const char* file_path) { return true; }
	bool Texture2d::LoadF(const char* file_path)
	{
		String strFile("");
		UByte s_texErr[] = {
			0u,	255u,	0u,		255u,
			0u,	0u,		255u,	255u,
			0u,	0u,		255u,	255u,
			0u,	255u,	0u,		255u
		};
		image_info imgInfo(2, 2, 4);
		Image imgData = Image(imgInfo, &s_texErr[0]);

		if (!data_sys::LoadFImage(file_path, imgData)) {
			if (!data_sys::LoadFString(file_path, strFile)) {
				m_info.Filter = TXF_NEAREST;
				m_info.wrap_s = m_info.wrap_t = m_info.wrap_r = TXW_REPEAT;
				return false;
			}
			else {
				str_stream stm_file(strFile);
				stm_file >> m_info;
				imgInfo.width= m_info.width;
				imgInfo.height = m_info.height;
				imgInfo.nChannels = m_info.nChannels;
				imgInfo.pxl_format = m_info.pxl_format;
				UByte* pData = mem_sys::new_arr<UByte>(imgInfo.GetSize());
				imgData.SetData(pData, imgInfo);
			}
		}
		return Remake(m_info);
	}
	// --==</data_methods>==--
}
#endif
#endif	// NWG_GAPI