#include <nwg_pch.hpp>
#include "nwg_texture.h"
#if (defined NWG_GAPI)
#include <nwg_loader.h>
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	Texture::Texture(const char* strName, TextureTypes texType) :
		TDataRes<Texture>(strName), GfxEntity(),
		m_texType(texType), m_unTexSlot(0),
		m_texInfo(TextureInfo()), m_imgInfo(ImageInfo())
	{
		Remake();
	}
	Texture::~Texture() { m_imgInfo.nWidth = -1; Remake(); }
	// --setters
	void Texture::SetInfo(const TextureInfo& rTexInfo) {
		m_texInfo = rTexInfo;
	}
	void Texture::SetInfo(const ImageInfo& rImgInfo) {
		if ((m_texType == TXT_1D || m_texType == TXT_2D || m_texType == TXT_3D) && (m_imgInfo.nWidth < 1)) { return; }
		else if ((m_texType == TXT_2D || m_texType == TXT_3D) && (m_imgInfo.nWidth < 1 || m_imgInfo.nHeight < 1)) { return; }
		else if ((m_texType == TXT_3D) && (m_imgInfo.nWidth < 1 || m_imgInfo.nHeight < 1 || m_imgInfo.nDepth < 1)) { return; }
		m_imgInfo = rImgInfo;
	}
	// --==<core_methods>==--
	void Texture::Bind() const {
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
	// --==<core_methods>==--
	void Texture::Bind(UInt32 unTexSlot) {
		if (m_bIsBound) { return; }
		m_unTexSlot = unTexSlot;
		m_bIsBound = true;
	}
	void Texture::Unbind()
	{
		if (!m_bIsBound) { return; }
		m_unTexSlot = 0;
		m_bIsBound = false;
	}
	void Texture::Remake()
	{
		Unbind();
		if (m_unRId != 0) { m_unRId = 0; }
		if (m_imgInfo.nWidth == -1) { return; }
		switch (m_texType) {
		case TXT_1D:
			if (m_texInfo.bGenSubImage) { }
			break;
		case TXT_2D:
			if (m_texInfo.bGenSubImage) { }
			break;
		case TXT_3D:
			if (m_texInfo.bGenSubImage) { }
		case TXT_2D_MULTISAMPLE:
			break;
		case TXT_3D_MULTISAMPLE:
			break;
		default: NWL_ERR("Undefined texture type"); break;
		}

		if (m_texInfo.bGenMipmap) { }
	}
	void Texture::Clear(Ptr pValue) { }
	// --==</core_methods>==--
}
#endif
#endif	// NWG_GAPI