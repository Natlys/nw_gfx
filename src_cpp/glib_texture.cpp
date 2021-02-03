#include <glib_pch.hpp>
#include "glib_texture.h"

#if (defined GLIB_GAPI)
#include <glib_engine.h>
#include <stb_image.h>
#endif	// GLIB_GAPI
#if (GLIB_GAPI & GLIB_GAPI_OGL)
#include <glad/glad.h>
namespace GLIB
{
	Texture::Texture(const char* strName, TextureTypes texType) :
		ADataRes(strName),
		m_texType(texType), m_unRId(0), m_unTexSlot(0), m_bIsBound(false),
		m_texInfo(TextureInfo()), m_imgInfo(ImageInfo())
	{
		ADataRes::AddDataRes<Texture>(this);
	}
	Texture::~Texture()
	{
		m_imgInfo.nWidth = -1;
		Remake();
		ADataRes::RmvDataRes<Texture>(GetId());
	}
	
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
	void Texture::Bind(UInt32 unTexSlot) {
		if (m_bIsBound) { return; }
		m_unTexSlot = unTexSlot;
		glActiveTexture(GL_TEXTURE0 + m_unTexSlot);
		glBindTexture(m_texType, m_unRId);
		m_bIsBound = true;
	}
	void Texture::Unbind()
	{
		if (!m_bIsBound) { return; }
		glActiveTexture(GL_TEXTURE0 + m_unTexSlot);
		glBindTexture(m_texType, 0);
		m_unTexSlot = 0;
		m_bIsBound = false;
	}
	void Texture::Remake()
	{
		Unbind();
		if (m_unRId != 0) { glDeleteTextures(1, &m_unRId); m_unRId = 0; }
		if (m_imgInfo.nWidth == -1) { return; }
		
		glCreateTextures(m_texType, 1, &m_unRId);
		Bind();
		switch (m_texType) {
		case TXT_1D:
			glTextureParameteri(m_unRId, GL_TEXTURE_MIN_FILTER, m_texInfo.FilterMin);
			glTextureParameteri(m_unRId, GL_TEXTURE_MAG_FILTER, m_texInfo.FilterMag);
			glTextureParameteri(m_unRId, GL_TEXTURE_WRAP_S, m_texInfo.WrapTypeS);
			glTexImage1D(GL_TEXTURE_1D, 0, m_texInfo.texInterFormat,
				m_imgInfo.nWidth, 0,
				m_texInfo.texFormat, m_texInfo.pxFormat, &m_imgInfo.ClrData[0]);
			if (m_texInfo.bGenSubImage) {
				glTexSubImage1D(GL_TEXTURE_1D, 0,
					0, m_imgInfo.nWidth,
					m_texInfo.texFormat, m_texInfo.pxFormat, &m_imgInfo.ClrData[0]);
			}
			break;
		case TXT_2D:
			glTextureParameteri(m_unRId, GL_TEXTURE_MIN_FILTER, m_texInfo.FilterMin);
			glTextureParameteri(m_unRId, GL_TEXTURE_MAG_FILTER, m_texInfo.FilterMag);
			glTextureParameteri(m_unRId, GL_TEXTURE_WRAP_S, m_texInfo.WrapTypeS);
			glTextureParameteri(m_unRId, GL_TEXTURE_WRAP_T, m_texInfo.WrapTypeT);
			glTexImage2D(GL_TEXTURE_2D, 0, m_texInfo.texInterFormat,
				m_imgInfo.nWidth, m_imgInfo.nHeight, 0,
				m_texInfo.texFormat, m_texInfo.pxFormat, &m_imgInfo.ClrData[0]);
			if (m_texInfo.bGenSubImage) {
				glTexSubImage2D(GL_TEXTURE_2D, 0,
					0, 0, m_imgInfo.nWidth, m_imgInfo.nHeight,
					m_texInfo.texFormat, m_texInfo.pxFormat, &m_imgInfo.ClrData[0]);
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
				m_texInfo.texFormat, m_texInfo.pxFormat, &m_imgInfo.ClrData[0]);
			if (m_texInfo.bGenSubImage) {
				glTexSubImage3D(GL_TEXTURE_3D, 0,
					0, 0, 0, m_imgInfo.nWidth, m_imgInfo.nHeight, m_imgInfo.nDepth,
					m_texInfo.texFormat, m_texInfo.pxFormat, &m_imgInfo.ClrData[0]);
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

		Unbind();
	}
	Texture* Texture::Create(const char* strName, TextureTypes texType) { return GraphEngine::Get().NewT<Texture>(strName, texType); }
	void Texture::Create(const char* strName, TextureTypes texType, RefKeeper<Texture>& rTex) {
		rTex.MakeRef<Texture>(GraphEngine::Get().GetMemory(), strName, texType);
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

		imgInfo.ClrData = stbi_load(strFPath, &imgInfo.nWidth, &imgInfo.nHeight, &imgInfo.nChannels, 0);
		if (imgInfo.ClrData == nullptr) { bSuccess = false; }
		switch (imgInfo.nChannels) {
		case 1: texInfo.texFormat = TXF_RED; texInfo.texInterFormat = TXFI_RED_UINT32; break;
		case 3: texInfo.texFormat = TXF_RGB; texInfo.texInterFormat = TXFI_RGB; break;
		case 4: texInfo.texFormat = TXF_RGBA; texInfo.texInterFormat = TXFI_RGBA8; break;
		default: NWL_ERR("Unsupported format!"); bSuccess = false; break;
		}
		if (!bSuccess) {
			imgInfo.nWidth = imgInfo.nHeight = imgInfo.nDepth = 1;
			imgInfo.nChannels = 4;
			imgInfo.ClrData = s_texErr;
			texInfo.texFormat = TXF_RGBA; texInfo.texInterFormat = TXFI_RGBA8;
			texInfo.FilterMag = texInfo.FilterMin = TXF_NEAREST;
			texInfo.WrapTypeS = texInfo.WrapTypeT = texInfo.WrapTypeR = TXW_REPEAT;
		}

		SetInfo(texInfo);
		SetInfo(imgInfo);
		Remake();
		if (bSuccess) { stbi_image_free(imgInfo.ClrData); }

		return bSuccess;
	}
	// --==</data_methods>==--
	// --==</Texture>==--
}
#endif // GLIB_GAPI