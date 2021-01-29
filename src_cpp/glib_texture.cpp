#include <glib_pch.hpp>
#include "glib_texture.h"

#if (defined GLIB_GAPI)
#include <glib_engine.h>
#include <glib_api.h>
#include <stb_image.h>

UByte GLIB::ATexture::s_ClearColorData[4] = { 255, 255, 255, 255 };

namespace GLIB
{
	ATexture::ATexture(const char* strName) :
		ADataRes(strName),
		m_unRId(0), m_unTexSlot(0),
		m_TexInfo(TextureInfo()), m_ImgInfo(ImageInfo()) { ADataRes::AddDataRes<ATexture>(this); }
	ATexture::~ATexture() { ADataRes::RmvDataRes<ATexture>(GetId()); }

	// --==<ATexture1d>==--
	ATexture1d::ATexture1d(const char* strName) :
	ATexture(strName) { ADataRes::AddDataRes<ATexture1d>(this); }
	ATexture1d::~ATexture1d() { ADataRes::RmvDataRes<ATexture1d>(GetId()); }
	
	// --data_methods
	bool ATexture1d::SaveF(const char* strFPath) { return true; }
	bool ATexture1d::LoadF(const char* strFPath)
	{
		String strFile("");
		Size szBytes = 0;
		bool bSuccess = true;

		ImageInfo ImgInfoTemp;
		TextureInfo TexInfoTemp;

		ImgInfoTemp.ClrData = stbi_load(strFPath, &ImgInfoTemp.nWidth, &ImgInfoTemp.nHeight, &ImgInfoTemp.nChannels, 0);
		if (ImgInfoTemp.ClrData == nullptr) {
			ImgInfoTemp.nWidth = ImgInfoTemp.nHeight = ImgInfoTemp.nDepth;
			ImgInfoTemp.nChannels = 4;
			ImgInfoTemp.ClrData = &s_ClearColorData[0];
			bSuccess = false;
		}
		switch (ImgInfoTemp.nChannels) {
		case 1: TexInfoTemp.Format = TC_FORMAT_RED; TexInfoTemp.InterFormat = TC_FORMAT_RED; break;
		case 2: NWL_ERR("Unsupported format!"); break;
		case 3: TexInfoTemp.InterFormat = TC_FORMAT_RGB; TexInfoTemp.Format = TC_FORMAT_RGB; break;
		case 4: TexInfoTemp.Format = TC_FORMAT_RGBA; TexInfoTemp.InterFormat = TC_FORMAT_RGBA8; break;
		}
		TexInfoTemp.FilterMag = TexInfoTemp.FilterMin = TC_FILTER_NEAREST;
		TexInfoTemp.Format = TexInfoTemp.InterFormat = TC_FORMAT_RGBA;
		TexInfoTemp.WrapTypeS = TexInfoTemp.WrapTypeT = TexInfoTemp.WrapTypeR = TC_WRAP_REPEAT;

		SetInfo(TexInfoTemp);
		SetInfo(ImgInfoTemp);
		Remake();

		return bSuccess;
	}

	// --==<ATexture2d>==--
	ATexture2d::ATexture2d(const char* strName) :
		ATexture(strName) { ADataRes::AddDataRes<ATexture2d>(this); }
	ATexture2d::~ATexture2d() { ADataRes::RmvDataRes<ATexture2d>(GetId()); }

	void ATexture2d::SetSubTexs(const DArray<SubTexture2d>& rSubTexs) {
		m_SubTexs = rSubTexs;
		for (auto& rSub : m_SubTexs) { rSub.pOverTex = this; rSub.whOverTexSize = { m_ImgInfo.nWidth, m_ImgInfo.nHeight }; }
	}
	
	// --data_methods
	bool ATexture2d::SaveF(const char* strFPath) { return true; }
	bool ATexture2d::LoadF(const char* strFPath)
	{
		String strFile("");
		Size szBytes = 0;
		bool bSuccess = true;

		ImageInfo ImgInfoTemp;
		TextureInfo TexInfoTemp;

		ImgInfoTemp.ClrData = stbi_load(strFPath, &ImgInfoTemp.nWidth, &ImgInfoTemp.nHeight, &ImgInfoTemp.nChannels, 0);
		if (ImgInfoTemp.ClrData == nullptr) {
			ImgInfoTemp.nWidth = ImgInfoTemp.nHeight = ImgInfoTemp.nDepth;
			ImgInfoTemp.nChannels = 4;
			ImgInfoTemp.ClrData = &s_ClearColorData[0];
			bSuccess = false;
		}
		switch (ImgInfoTemp.nChannels) {
		case 1: TexInfoTemp.Format = TC_FORMAT_RED; TexInfoTemp.InterFormat = TC_FORMAT_RED; break;
		case 2: NWL_ERR("Unsupported format!"); break;
		case 3: TexInfoTemp.InterFormat = TC_FORMAT_RGB; TexInfoTemp.Format = TC_FORMAT_RGB; break;
		case 4: TexInfoTemp.Format = TC_FORMAT_RGBA; TexInfoTemp.InterFormat = TC_FORMAT_RGBA8; break;
		}
		TexInfoTemp.FilterMag = TexInfoTemp.FilterMin = TC_FILTER_NEAREST;
		TexInfoTemp.Format = TexInfoTemp.InterFormat = TC_FORMAT_RGBA;
		TexInfoTemp.WrapTypeS = TexInfoTemp.WrapTypeT = TexInfoTemp.WrapTypeR = TC_WRAP_REPEAT;

		SetInfo(TexInfoTemp);
		SetInfo(ImgInfoTemp);
		Remake();

		return bSuccess;
	}
	// --==</ATexture2d>==--

	// --==<ATexture3d>==--
	ATexture3d::ATexture3d(const char* strName) :
		ATexture(strName) { ADataRes::AddDataRes<ATexture3d>(this); }
	ATexture3d::~ATexture3d() { ADataRes::RmvDataRes<ATexture3d>(GetId()); }

	// --data_methods
	bool ATexture3d::SaveF(const char* strFPath) { return true; }
	bool ATexture3d::LoadF(const char* strFPath)
	{
		String strFile("");
		Size szBytes = 0;
		bool bSuccess = true;

		ImageInfo ImgInfoTemp;
		TextureInfo TexInfoTemp;

		ImgInfoTemp.ClrData = stbi_load(strFPath, &ImgInfoTemp.nWidth, &ImgInfoTemp.nHeight, &ImgInfoTemp.nChannels, 0);
		if (ImgInfoTemp.ClrData == nullptr) {
			ImgInfoTemp.nWidth = ImgInfoTemp.nHeight = ImgInfoTemp.nDepth;
			ImgInfoTemp.nChannels = 4;
			ImgInfoTemp.ClrData = &s_ClearColorData[0];
			bSuccess = false;
		}
		switch (ImgInfoTemp.nChannels) {
		case 1: TexInfoTemp.Format = TC_FORMAT_RED; TexInfoTemp.InterFormat = TC_FORMAT_RED; break;
		case 2: NWL_ERR("Unsupported format!"); break;
		case 3: TexInfoTemp.InterFormat = TC_FORMAT_RGB; TexInfoTemp.Format = TC_FORMAT_RGB; break;
		case 4: TexInfoTemp.Format = TC_FORMAT_RGBA; TexInfoTemp.InterFormat = TC_FORMAT_RGBA8; break;
		}
		TexInfoTemp.FilterMag = TexInfoTemp.FilterMin = TC_FILTER_NEAREST;
		TexInfoTemp.Format = TexInfoTemp.InterFormat = TC_FORMAT_RGBA;
		TexInfoTemp.WrapTypeS = TexInfoTemp.WrapTypeT = TexInfoTemp.WrapTypeR = TC_WRAP_REPEAT;

		SetInfo(TexInfoTemp);
		SetInfo(ImgInfoTemp);
		Remake();

		return bSuccess;
	}
	// --==</ATexture3d>==--

	ATexture1d* ATexture1d::Create(const char* strName) {
		ATexture1d* pTex = nullptr;
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GAPI_OPENGL: pTex = GEngine::Get().NewT<Texture1dOgl>(strName); break;
	#endif	// GLIB_GAPI
		default: break;
		}
		return pTex;
	}
	void ATexture1d::Create(const char* strName, RefKeeper<ATexture1d>& rTex) {
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GAPI_OPENGL: rTex.MakeRef<Texture1dOgl>(strName); break;
	#endif	// GLIB_GAPI
		default: break;
		}
	}

	ATexture2d* ATexture2d::Create(const char* strName) {
		ATexture2d* pTex = nullptr;
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GAPI_OPENGL: pTex = GEngine::Get().NewT<Texture2dOgl>(strName); break;
	#endif	// GLIB_GAPI
		default: break;
		}
		return pTex;
	}
	void ATexture2d::Create(const char* strName, RefKeeper<ATexture2d>& rTex) {
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GAPI_OPENGL: rTex.MakeRef<Texture2dOgl>(strName); break;
	#endif	// GLIB_GAPI
		default: break;
		}
	}
	ATexture3d* ATexture3d::Create(const char* strName) {
		ATexture3d* pTex = nullptr;
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GAPI_OPENGL: pTex = GEngine::Get().NewT<Texture3dOgl>(strName); break;
	#endif	// GLIB_GAPI
		default: break;
		}
		return pTex;
	}
	void ATexture3d::Create(const char* strName, RefKeeper<ATexture3d>& rTex) {
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GAPI_OPENGL: rTex.MakeRef<Texture3dOgl>(strName); break;
	#endif	// GLIB_GAPI
		default: break;
		}
	}
}
#endif	// GLIB_GAPI
#if (GLIB_GAPI & GLIB_GAPI_OGL)
#include <glad/glad.h>
namespace GLIB
{
	// Texture1d
	Texture1dOgl::Texture1dOgl(const char* strName) :
		ATexture1d(strName) { }
	Texture1dOgl::~Texture1dOgl() { }

	// --setters
	void Texture1dOgl::SetInfo(const TextureInfo& rTexInfo) {
		m_TexInfo = rTexInfo;
	}
	void Texture1dOgl::SetInfo(const ImageInfo& rImgInfo) {
		if (rImgInfo.nWidth < 1 || rImgInfo.nHeight < 1 || rImgInfo.nChannels < 1) { return; }
		m_ImgInfo = rImgInfo;
	}

	// --==<Interface Methods>==--
	void Texture1dOgl::Bind(UInt32 unTexSlot) {
		if (m_bIsBound) { return; }
		m_unTexSlot = unTexSlot;
		glActiveTexture(GL_TEXTURE0 + m_unTexSlot);
		glBindTexture(GL_TEXTURE_1D, m_unRId);
		m_bIsBound = true;
	}
	void Texture1dOgl::Unbind()
	{
		if (!m_bIsBound) { return; }
		glActiveTexture(GL_TEXTURE0 + m_unTexSlot);
		glBindTexture(GL_TEXTURE_1D, 0);
		m_unTexSlot = 0;
		m_bIsBound = false;
	}
	void Texture1dOgl::Remake()
	{
		if (m_unRId != 0) { glDeleteTextures(1, &m_unRId); m_unRId = 0; }
		glCreateTextures(GL_TEXTURE_1D, 1, &m_unRId);

		glBindTexture(GL_TEXTURE_1D, m_unRId);
		glTextureParameteri(m_unRId, GL_TEXTURE_MIN_FILTER, m_TexInfo.FilterMin);
		glTextureParameteri(m_unRId, GL_TEXTURE_MAG_FILTER, m_TexInfo.FilterMag);
		glTextureParameteri(m_unRId, GL_TEXTURE_WRAP_S, m_TexInfo.WrapTypeS);
		glTexImage1D(GL_TEXTURE_1D, 0, m_TexInfo.InterFormat,
			m_ImgInfo.nWidth, 0,
			m_TexInfo.Format, GL_UNSIGNED_BYTE, &m_ImgInfo.ClrData[0]);
		glTexSubImage1D(GL_TEXTURE_1D, 0,
			0, m_ImgInfo.nWidth,
			m_TexInfo.Format, GL_UNSIGNED_BYTE, &m_ImgInfo.ClrData[0]);
		glGenerateMipmap(GL_TEXTURE_1D);
		glBindTexture(GL_TEXTURE_1D, 0);
	}
	// --==</core_methods>==--
	// Texture2d
	Texture2dOgl::Texture2dOgl(const char* strName) :
		ATexture2d(strName) { }
	Texture2dOgl::~Texture2dOgl() { }

	// --setters
	void Texture2dOgl::SetInfo(const TextureInfo& rTexInfo) {
		m_TexInfo = rTexInfo;
	}
	void Texture2dOgl::SetInfo(const ImageInfo& rImgInfo) {
		if (rImgInfo.nWidth < 1 || rImgInfo.nHeight < 1 || rImgInfo.nChannels < 1) { return; }
		m_ImgInfo = rImgInfo;
		SetSubTexs(GetSubTexs());
	}

	// --==<Interface Methods>==--
	void Texture2dOgl::Bind(UInt32 unTexSlot) {
		if (m_bIsBound) { return; }
		m_unTexSlot = unTexSlot;
		glActiveTexture(GL_TEXTURE0 + m_unTexSlot);
		glBindTexture(GL_TEXTURE_2D, m_unRId);
		m_bIsBound = true;
	}
	void Texture2dOgl::Unbind() {
		if (!m_bIsBound) { return; }
		glActiveTexture(GL_TEXTURE0 + m_unTexSlot);
		glBindTexture(GL_TEXTURE_2D, 0);
		m_unTexSlot = 0;
		m_bIsBound = false;
	}
	void Texture2dOgl::Remake()
	{
		if (m_unRId != 0) { glDeleteTextures(1, &m_unRId); m_unRId = 0; }
		glCreateTextures(GL_TEXTURE_2D, 1, &m_unRId);

		glBindTexture(GL_TEXTURE_2D, m_unRId);
		glTextureParameteri(m_unRId, GL_TEXTURE_MIN_FILTER, m_TexInfo.FilterMin);
		glTextureParameteri(m_unRId, GL_TEXTURE_MAG_FILTER, m_TexInfo.FilterMag);
		glTextureParameteri(m_unRId, GL_TEXTURE_WRAP_S, m_TexInfo.WrapTypeS);
		glTextureParameteri(m_unRId, GL_TEXTURE_WRAP_T, m_TexInfo.WrapTypeT);
		glTexImage2D(GL_TEXTURE_2D, 0, m_TexInfo.InterFormat,
			m_ImgInfo.nWidth, m_ImgInfo.nHeight, 0,
			m_TexInfo.Format, GL_UNSIGNED_BYTE, &m_ImgInfo.ClrData[0]);
		glTexSubImage2D(GL_TEXTURE_2D, 0,
			0, 0, m_ImgInfo.nWidth, m_ImgInfo.nHeight,
			m_TexInfo.Format, GL_UNSIGNED_BYTE, &m_ImgInfo.ClrData[0]);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	// --==</core_methods>==--
	
	// Texture3d
	Texture3dOgl::Texture3dOgl(const char* strName) :
		ATexture3d(strName) { }
	Texture3dOgl::~Texture3dOgl() { }

	// --setters
	void Texture3dOgl::SetInfo(const TextureInfo& rTexInfo) {
		m_TexInfo = rTexInfo;
	}
	void Texture3dOgl::SetInfo(const ImageInfo& rImgInfo) {
		if (rImgInfo.nWidth < 1 || rImgInfo.nHeight < 1 || rImgInfo.nChannels < 1) { return; }
		m_ImgInfo = rImgInfo;
	}

	// --==<Interface Methods>==--
	void Texture3dOgl::Bind(UInt32 unTexSlot)
	{
		if (m_bIsBound) { return; }
		m_unTexSlot = unTexSlot;
		glActiveTexture(GL_TEXTURE0 + m_unTexSlot);
		glBindTexture(GL_TEXTURE_3D, m_unRId);
		m_bIsBound = true;
	}
	void Texture3dOgl::Unbind()
	{
		if (!m_bIsBound) { return; }
		glActiveTexture(GL_TEXTURE0 + m_unTexSlot);
		glBindTexture(GL_TEXTURE_3D, 0);
		m_unTexSlot = 0;
		m_bIsBound = false;
	}
	void Texture3dOgl::Remake()
	{
		if (m_unRId != 0) { glDeleteTextures(1, &m_unRId); m_unRId = 0; }
		glCreateTextures(GL_TEXTURE_3D, 1, &m_unRId);
		
		glBindTexture(GL_TEXTURE_2D, m_unRId);
		glTextureParameteri(m_unRId, GL_TEXTURE_MIN_FILTER, m_TexInfo.FilterMin);
		glTextureParameteri(m_unRId, GL_TEXTURE_MAG_FILTER, m_TexInfo.FilterMag);
		glTextureParameteri(m_unRId, GL_TEXTURE_WRAP_S, m_TexInfo.WrapTypeS);
		glTextureParameteri(m_unRId, GL_TEXTURE_WRAP_T, m_TexInfo.WrapTypeT);
		glTextureParameteri(m_unRId, GL_TEXTURE_WRAP_R, m_TexInfo.WrapTypeR);
		glTexImage3D(GL_TEXTURE_3D, 0, m_TexInfo.InterFormat,
			m_ImgInfo.nWidth, m_ImgInfo.nHeight, m_ImgInfo.nDepth, 0,
			m_TexInfo.Format, GL_UNSIGNED_BYTE, &m_ImgInfo.ClrData[0]);
		glTexSubImage3D(GL_TEXTURE_3D, 0,
			0, 0, 0, m_ImgInfo.nWidth, m_ImgInfo.nHeight, m_ImgInfo.nDepth,
			m_TexInfo.Format, GL_UNSIGNED_BYTE, &m_ImgInfo.ClrData[0]);
		glGenerateMipmap(GL_TEXTURE_3D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	// --==</core_methods>==--
}
#endif // GLIB_GAPI