#include <nwg_pch.hpp>
#include "nwg_texture.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#include <lib/nwg_load_txr.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	a_texture::a_texture(cstring name) :
		a_image(name),
		m_slot(0u),
		m_samples(1u),
		m_txr_fmt(TXF_RGBA),
		m_ogl_id(0u)
	{
	}
	a_texture::~a_texture() { if (m_ogl_id != 0) { glDeleteTextures(1, &m_ogl_id); m_ogl_id = 0; } }
	// --setters
	void a_texture::set_slot(ui8 texture_slot) { m_slot = texture_slot; }
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
#include <lib/nwg_dx_loader.h>
namespace NW
{
	a_texture::a_texture(gfx_engine& graphics, const char* name, texture_types txr_type) :
		a_gfx_rsc(graphics), a_data_rsc(name),
		m_info(texture_info()), m_unSlot(0),
		m_pRes(nullptr), m_pSampler(nullptr)
	{
	}
	a_texture::~a_texture() {
		if (m_pRes != nullptr) { m_pRes->Release(); m_pRes = nullptr; }
		if (m_pSampler != nullptr) { m_pSampler->Release(); m_pSampler = nullptr; }
	}
	// --setters
	void a_texture::SetSlot(ui8 unSlot) { m_unSlot = unSlot; }
}
namespace NW
{
	texture_2d::texture_2d(gfx_engine& graphics, const char* name) :
		a_texture(graphics, name, TXT_2D) { }
	texture_2d::~texture_2d() { }
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
				io_stream_str stm_file(strFile);
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
#endif	// NW_GAPI