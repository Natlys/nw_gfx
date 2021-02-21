#include <nwg_pch.hpp>
#include "nwg_texture.h"
#if (defined NWG_GAPI)
#include <nwg_engine.h>
#include <nwg_loader.h>
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	Texture::Texture(const char* strName, TextureTypes texType) :
		TEntity(), AGfxRes(), ADataRes(strName),
		m_texType(texType), m_unTexSlot(0),
		m_texInfo(TextureInfo()), m_imgInfo(ImageInfo())
	{
		Remake();
	}
	Texture::~Texture() { m_imgInfo.nWidth = -1; Remake(); }
	// --setters
	void Texture::SetInfo(const TextureInfo& rTexInfo) { m_texInfo = rTexInfo; }
	void Texture::SetInfo(const ImageInfo& rImgInfo) {
		if ((m_texType == TXT_1D || m_texType == TXT_2D || m_texType == TXT_3D) && (m_imgInfo.nWidth < 1)) { return; }
		else if ((m_texType == TXT_2D || m_texType == TXT_3D) && (m_imgInfo.nWidth < 1 || m_imgInfo.nHeight < 1)) { return; }
		else if ((m_texType == TXT_3D) && (m_imgInfo.nWidth < 1 || m_imgInfo.nHeight < 1 || m_imgInfo.nDepth < 1)) { return; }
		m_imgInfo = rImgInfo;
	}
	// --==<core_methods>==--
	void Texture::Bind() {
		glActiveTexture(GL_TEXTURE0 + m_unTexSlot);
		glBindTexture(m_texType, m_unRId);
	}
	void Texture::Remake()
	{
		if (m_unRId != 0) { glDeleteTextures(1, &m_unRId); m_unRId = 0; }
		if (m_imgInfo.nWidth == -1) { return; }
		
		glCreateTextures(m_texType, 1, &m_unRId);
		glBindTexture(m_texType, m_unRId);
		switch (m_texType) {
		case TXT_1D:
			glTextureParameteri(m_unRId, GL_TEXTURE_MIN_FILTER, m_texInfo.FilterMin);
			glTextureParameteri(m_unRId, GL_TEXTURE_MAG_FILTER, m_texInfo.FilterMag);
			glTextureParameteri(m_unRId, GL_TEXTURE_WRAP_S, m_texInfo.WrapTypeS);
			glTexImage1D(GL_TEXTURE_1D, 0, m_texInfo.texInterFormat,
				m_imgInfo.nWidth, 0,
				m_texInfo.texFormat, m_texInfo.pxFormat, &m_imgInfo.pClrData[0]);
			if (m_texInfo.bGenSubImage) {
				glTexSubImage1D(GL_TEXTURE_1D, 0,
					0, m_imgInfo.nWidth,
					m_texInfo.texFormat, m_texInfo.pxFormat, &m_imgInfo.pClrData[0]);
			}
			break;
		case TXT_2D:
			glTextureParameteri(m_unRId, GL_TEXTURE_MIN_FILTER, m_texInfo.FilterMin);
			glTextureParameteri(m_unRId, GL_TEXTURE_MAG_FILTER, m_texInfo.FilterMag);
			glTextureParameteri(m_unRId, GL_TEXTURE_WRAP_S, m_texInfo.WrapTypeS);
			glTextureParameteri(m_unRId, GL_TEXTURE_WRAP_T, m_texInfo.WrapTypeT);
			glTexImage2D(GL_TEXTURE_2D, 0, m_texInfo.texInterFormat,
				m_imgInfo.nWidth, m_imgInfo.nHeight, 0,
				m_texInfo.texFormat, m_texInfo.pxFormat, &m_imgInfo.pClrData[0]);
			if (m_texInfo.bGenSubImage) {
				glTexSubImage2D(GL_TEXTURE_2D, 0,
					0, 0, m_imgInfo.nWidth, m_imgInfo.nHeight,
					m_texInfo.texFormat, m_texInfo.pxFormat, &m_imgInfo.pClrData[0]);
			}
			break;
		case TXT_3D:
			glTextureParameteri(m_unRId, GL_TEXTURE_MIN_FILTER, m_texInfo.FilterMin);
			glTextureParameteri(m_unRId, GL_TEXTURE_MAG_FILTER, m_texInfo.FilterMag);
			glTextureParameteri(m_unRId, GL_TEXTURE_WRAP_S, m_texInfo.WrapTypeS);
			glTextureParameteri(m_unRId, GL_TEXTURE_WRAP_T, m_texInfo.WrapTypeT);
			glTextureParameteri(m_unRId, GL_TEXTURE_WRAP_R, m_texInfo.WrapTypeR);
			glTexImage3D(GL_TEXTURE_3D, 0, m_texInfo.texInterFormat,
				m_imgInfo.nWidth, m_imgInfo.nHeight, m_imgInfo.nDepth, 0,
				m_texInfo.texFormat, m_texInfo.pxFormat, &m_imgInfo.pClrData[0]);
			if (m_texInfo.bGenSubImage) {
				glTexSubImage3D(GL_TEXTURE_3D, 0,
					0, 0, 0, m_imgInfo.nWidth, m_imgInfo.nHeight, m_imgInfo.nDepth,
					m_texInfo.texFormat, m_texInfo.pxFormat, &m_imgInfo.pClrData[0]);
			}
		case TXT_2D_MULTISAMPLE:
			glTexImage2DMultisample(m_texType, m_texInfo.unSamples, m_texInfo.texInterFormat,
				m_imgInfo.nWidth, m_imgInfo.nHeight, false);
			break;
		case TXT_3D_MULTISAMPLE:
			glTexImage3DMultisample(m_texType, m_texInfo.unSamples, m_texInfo.texInterFormat,
				m_imgInfo.nWidth, m_imgInfo.nHeight, m_imgInfo.nDepth, false);
			break;
		default: NWL_ERR("Undefined texture type"); break;
		}

		if (m_texInfo.bGenMipmap) { glGenerateMipmap(m_texType); }
	}
	void Texture::Clear(Ptr pValue) {
		glClearTexImage(m_unRId, 0, m_texInfo.texFormat, m_texInfo.pxFormat, pValue);
	}
	// --==</core_methods>==--
		// --==<data_methods>==--
	bool Texture::SaveF(const char* strFPath) { return true; }
	bool Texture::LoadF(const char* strFPath)
	{
		String strFile("");
		Size szBytes = 0;
		bool bSuccess = true;
		UByte s_texErr[4 * 4] = {
			0,	255,	0,		255,
			0,	0,		255,	255,
			0,	0,		255,	255,
			0,	255,	0,		255
		};

		ImageInfo imgInfo;
		TextureInfo texInfo;

		if (!DataSys::LoadFImage(strFPath, imgInfo)) { bSuccess = false; }
		switch (imgInfo.nChannels) {
		case 1: texInfo.texFormat = TXF_RED; texInfo.texInterFormat = TXFI_RED_UINT32; break;
		case 3: texInfo.texFormat = TXF_RGB; texInfo.texInterFormat = TXFI_RGB; break;
		case 4: texInfo.texFormat = TXF_RGBA; texInfo.texInterFormat = TXFI_RGBA8; break;
		default: NWL_ERR("Unsupported format!"); bSuccess = false; break;
		}
		if (!bSuccess) {
			imgInfo.nWidth = imgInfo.nHeight = imgInfo.nDepth = 1;
			imgInfo.nChannels = 4;
			imgInfo.pClrData = s_texErr;
			texInfo.texFormat = TXF_RGBA; texInfo.texInterFormat = TXFI_RGBA8;
			texInfo.FilterMag = texInfo.FilterMin = TXF_NEAREST;
			texInfo.WrapTypeS = texInfo.WrapTypeT = texInfo.WrapTypeR = TXW_REPEAT;
		}

		SetInfo(texInfo);
		SetInfo(imgInfo);
		Remake();
		if (bSuccess) { delete[] imgInfo.pClrData; }

		return bSuccess;
	}
	// --==</data_methods>==--
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
	Texture::Texture(GfxEngine& rGfx, const char* strName, TextureTypes texType) :
		TEntity(), AGfxRes(rGfx), ADataRes(strName),
		m_texType(texType), m_unSlot(0),
		m_imgInfo(ImageInfo()),
		m_pNative(nullptr), m_pSampler(nullptr)
	{
		m_WrapS = TXW_REPEAT;
		m_WrapT = TXW_REPEAT;
		m_WrapR = TXW_REPEAT;
		m_Filter = TXF_NEAREST;
	}
	Texture::~Texture() { m_imgInfo.nWidth = -1; Remake(); }
	// --setters
	void Texture::SetSlot(UInt8 unSlot) { m_unSlot = unSlot; }
	void Texture::SetInfo(const ImageInfo& rImgInfo) {
		if ((m_texType == TXT_1D || m_texType == TXT_2D || m_texType == TXT_3D) && (m_imgInfo.nWidth < 1)) { return; }
		else if ((m_texType == TXT_2D || m_texType == TXT_3D) && (m_imgInfo.nWidth < 1 || m_imgInfo.nHeight < 1)) { return; }
		else if ((m_texType == TXT_3D) && (m_imgInfo.nWidth < 1 || m_imgInfo.nHeight < 1 || m_imgInfo.nDepth < 1)) { return; }
		m_imgInfo = rImgInfo;
	}
	// --==<core_methods>==--
	void Texture::Bind() {
		m_pGfx->GetContext()->PSSetShaderResources(m_unSlot, 1u, &m_pNative);
		m_pGfx->GetContext()->PSSetSamplers(m_unSlot, 1u, &m_pSampler);
	}
	void Texture::Remake()
	{
		if (m_pNative != nullptr) { m_pNative->Release(); m_pNative = nullptr; }
		if (m_pSampler != nullptr) { m_pSampler->Release(); m_pSampler = nullptr; }
		if (m_imgInfo.nWidth <= 0 || m_imgInfo.nHeight <= 0 || m_imgInfo.nDepth <= 0 || m_imgInfo.nChannels <= 0) { return; }
		if (m_WrapS == TXW_DEFAULT || m_WrapT == TXW_DEFAULT || m_WrapR == TXW_DEFAULT) { return; }
		if (m_Filter == TXF_DEFAULT) { return; }
		// create texture itself
		switch (m_texType) {
		case TXT_1D: {
			break;
		}
		case TXT_2D: {
			D3D11_TEXTURE2D_DESC texDesc{ 0 };
			texDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
			texDesc.CPUAccessFlags = m_imgInfo.pClrData == nullptr ? D3D11_CPU_ACCESS_WRITE : 0u;
			texDesc.Format = ConvertEnum<PixelFormats, DXGI_FORMAT>(m_imgInfo.pxFormat);
			texDesc.MiscFlags = 0u;
			texDesc.Width = m_imgInfo.nWidth;
			texDesc.Height = m_imgInfo.nHeight;
			texDesc.MipLevels = 1;
			texDesc.ArraySize = 1;
			texDesc.SampleDesc.Count = 1;
			texDesc.SampleDesc.Quality = 0;

			D3D11_SUBRESOURCE_DATA subData{ 0 };
			subData.pSysMem = m_imgInfo.pClrData == nullptr ? m_imgInfo.pClrData : MemSys::GetMemory().GetDataBeg();
			subData.SysMemPitch = m_imgInfo.nWidth * m_imgInfo.nChannels;	// adjacent bytes between rows
			subData.SysMemSlicePitch = m_imgInfo.nHeight * m_imgInfo.nChannels;	// adjacent bytes between rows

			ID3D11Texture2D* pTexture = nullptr;
			m_pGfx->GetDevice()->CreateTexture2D(&texDesc, &subData, &pTexture);
			if (pTexture == nullptr) { throw Exception("failed to create a texture"); }

			// create resource view to display the texture
			D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc{ };
			srvDesc.Format = ConvertEnum<PixelFormats, DXGI_FORMAT>(m_imgInfo.pxFormat);
			srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
			srvDesc.Texture2D.MostDetailedMip = 0;
			srvDesc.Texture2D.MipLevels = 1;
			
			m_pGfx->GetDevice()->CreateShaderResourceView(pTexture, &srvDesc, &m_pNative);
			pTexture->Release();
			if (m_pNative == nullptr) { throw Exception("unsupported texture type"); }
			break;
		}
		case TXT_3D: {
			break;
		}
		default: throw Exception("unsupported texture type"); break;
		}
		// create sampler for right texture representation
		D3D11_SAMPLER_DESC smpDesc{ };
		smpDesc.AddressU = ConvertEnum<TextureWraps, D3D11_TEXTURE_ADDRESS_MODE>(m_WrapS);
		smpDesc.AddressV = ConvertEnum<TextureWraps, D3D11_TEXTURE_ADDRESS_MODE>(m_WrapT);
		smpDesc.AddressW = ConvertEnum<TextureWraps, D3D11_TEXTURE_ADDRESS_MODE>(m_WrapR);
		smpDesc.Filter = ConvertEnum<TextureFilters, D3D11_FILTER>(m_Filter);
		smpDesc.BorderColor;	// for the "border" wrapper
		smpDesc.ComparisonFunc;	//
		smpDesc.MaxAnisotropy;	// for the filter "anostropy"
		smpDesc.MinLOD;			// minimal level of details
		smpDesc.MaxLOD;			// maximal level of details
		smpDesc.MipLODBias;		// level of details for mipmapping
		m_pGfx->GetDevice()->CreateSamplerState(&smpDesc, &m_pSampler);
		if (m_pNative == nullptr) { throw Exception("sampler was not created"); }
	}
	void Texture::Clear(Ptr pValue) { }
	// --==</core_methods>==--
	// --==<data_methods>==--
	bool Texture::SaveF(const char* strFPath) { return true; }
	bool Texture::LoadF(const char* strFPath) {
		ImageInfo imgInfo;
		String strFile("");
		if (!DataSys::LoadFImage(strFPath, imgInfo)) {
			if (!DataSys::LoadFString(strFPath, strFile)) { return false; }
			StrStream stmFile(strFile);
			while (std::getline(stmFile, strFile, ':')) {
				if (strFile == "gapi") {
					std::getline(stmFile, strFile, ';');
					if (strFile == "directx") {}
					else { return false; }
				}
				else if (strFile == "name") {
					std::getline(stmFile, strFile, ';');
					SetName(&strFile[0]);
				}
				else if (strFile == "size") {
					std::getline(stmFile, strFile, ';');
				}
				else if (strFile == "channels") {
					std::getline(stmFile, strFile, ';');
				}
				else if (strFile == "pixel_format") {
					std::getline(stmFile, strFile, ';');
				}
				else if (strFile == "tex_wrap_repeat") {
					std::getline(stmFile, strFile, ';');
				}
				else if (strFile == "border_color") {
					std::getline(stmFile, strFile, ';');
				}
				else if (strFile == "tex_wrap") {
					std::getline(stmFile, strFile, ';');
				}
				else if (strFile == "tex_filter") {
					std::getline(stmFile, strFile, ';');
				}
				else if (strFile == "img_file") {
					std::getline(stmFile, strFile, ';');
					if (!DataSys::LoadFImage(&strFile[0], imgInfo)) { return false; }
				}
				else {}
				stmFile.get();
			}
		}

		if (imgInfo.nChannels == 1) { imgInfo.pxFormat = PXF_R32_UINT32; }
		else if (imgInfo.nChannels == 2) { imgInfo.pxFormat = PXF_R8G8_UINT16; }
		else if (imgInfo.nChannels == 3) { imgInfo.pxFormat = PXF_R8G8B8_UINT32; }
		else if (imgInfo.nChannels == 4) { imgInfo.pxFormat = PXF_R8G8B8A8_UINT32; }
		else { return false; }
		SetInfo(imgInfo);
		Remake();
		if (MemSys::GetMemory().HasBlock(imgInfo.pClrData)) { MemSys::Dealloc(imgInfo.pClrData, imgInfo.GetDataSize()); }
		else { delete[] imgInfo.pClrData; }

		return true;
	}
	// --==</data_methods>==--
}
#endif
#endif	// NWG_GAPI