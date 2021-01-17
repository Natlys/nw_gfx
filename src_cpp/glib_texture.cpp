#include <glib_pch.hpp>
#include "glib_texture.h"

#if (defined GLIB_GAPI)
#include <core/glib_engine.h>
#include <core/glib_api.h>

GLIB::UByte GLIB::ATexture::s_ClearColorData[4] = { 255, 255, 255, 255 };

namespace GLIB
{
	ATexture::ATexture(const char* strName) :
		AGRes(strName),
		m_unRId(0), m_unTexSlot(0),
		m_TexInfo(TextureInfo()), m_ImgInfo(ImageInfo()) { GEngine::Get().AddGRes<ATexture>(this); }
	ATexture::ATexture(ATexture& rCpy) : ATexture(&rCpy.m_strName[0]) {}
	ATexture::~ATexture() { GEngine::Get().RmvGRes<ATexture>(GetId()); }

	// --==<ATexture1d>==--
	ATexture1d::ATexture1d(const char* strName) :
	ATexture(strName) { GEngine::Get().AddGRes<ATexture1d>(this); }
	ATexture1d::ATexture1d(ATexture1d& rCpy) : ATexture1d(&rCpy.m_strName[0]) {}
	ATexture1d::~ATexture1d() { GEngine::Get().RmvGRes<ATexture1d>(GetId()); }
	
	// --data_methods
	bool ATexture1d::SaveF(const char* strFPath) { return true; }
	bool ATexture1d::LoadF(const char* strFPath)
	{
		String strFile("");
		Size szBytes = 0;
		bool bSuccess = true;

		ImageInfo ImgInfoTemp;
		TextureInfo TexInfoTemp;

		if (!GEngine::Get().LoadFImage(strFPath, &ImgInfoTemp)) {
			TexInfoTemp.FilterMag = TexInfoTemp.FilterMin = TC_FILTER_NEAREST;
			TexInfoTemp.Format = TexInfoTemp.InterFormat = TC_FORMAT_RGBA;
			TexInfoTemp.WrapTypeS = TexInfoTemp.WrapTypeT = TexInfoTemp.WrapTypeR = TC_WRAP_REPEAT;

			ImgInfoTemp.nWidth = ImgInfoTemp.nHeight = ImgInfoTemp.nDepth;
			ImgInfoTemp.nChannels = 4;
			ImgInfoTemp.ClrData = &s_ClearColorData[0];

			bSuccess = false;
		}
		switch (ImgInfoTemp.nChannels) {
		case 1: TexInfoTemp.Format = TC_FORMAT_RED; TexInfoTemp.InterFormat = TC_FORMAT_RED; break;
		case 2: GLIB_ERR("Unsupported format!"); break;
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
	// --==</ATexture1d>==--

	// --==<ATexture2d>==--
	ATexture2d::ATexture2d(const char* strName) :
		ATexture(strName) { }
	ATexture2d::ATexture2d(ATexture2d& rCpy) : ATexture2d(&rCpy.m_strName[0]) {}
	ATexture2d::~ATexture2d() { GEngine::Get().RmvGRes<ATexture2d>(GetId()); }

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

		if (!GEngine::Get().LoadFImage(strFPath, &ImgInfoTemp)) {
			TexInfoTemp.FilterMag = TexInfoTemp.FilterMin = TC_FILTER_NEAREST;
			TexInfoTemp.Format = TexInfoTemp.InterFormat = TC_FORMAT_RGBA;
			TexInfoTemp.WrapTypeS = TexInfoTemp.WrapTypeT = TexInfoTemp.WrapTypeR = TC_WRAP_REPEAT;

			ImgInfoTemp.nWidth = ImgInfoTemp.nHeight = ImgInfoTemp.nDepth;
			ImgInfoTemp.nChannels = 4;
			ImgInfoTemp.ClrData = &s_ClearColorData[0];

			bSuccess = false;
		}
		switch (ImgInfoTemp.nChannels) {
		case 1: TexInfoTemp.Format = TC_FORMAT_RED; TexInfoTemp.InterFormat = TC_FORMAT_RED; break;
		case 2: GLIB_ERR("Unsupported format!"); break;
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
		ATexture(strName) { GEngine::Get().AddGRes<ATexture3d>(this); }
	ATexture3d::ATexture3d(ATexture3d& rCpy) : ATexture3d(&rCpy.m_strName[0]) { }
	ATexture3d::~ATexture3d() { GEngine::Get().RmvGRes<ATexture3d>(GetId()); }

	// --data_methods
	bool ATexture3d::SaveF(const char* strFPath) { return true; }
	bool ATexture3d::LoadF(const char* strFPath)
	{
		String strFile("");
		Size szBytes = 0;
		bool bSuccess = true;

		ImageInfo ImgInfoTemp;
		TextureInfo TexInfoTemp;

		if (!GEngine::Get().LoadFImage(strFPath, &ImgInfoTemp)) {
			TexInfoTemp.FilterMag = TexInfoTemp.FilterMin = TC_FILTER_NEAREST;
			TexInfoTemp.Format = TexInfoTemp.InterFormat = TC_FORMAT_RGBA;
			TexInfoTemp.WrapTypeS = TexInfoTemp.WrapTypeT = TexInfoTemp.WrapTypeR = TC_WRAP_REPEAT;

			ImgInfoTemp.nWidth = ImgInfoTemp.nHeight = ImgInfoTemp.nDepth;
			ImgInfoTemp.nChannels = 4;
			ImgInfoTemp.ClrData = &s_ClearColorData[0];

			bSuccess = false;
		}
		switch (ImgInfoTemp.nChannels) {
		case 1: TexInfoTemp.Format = TC_FORMAT_RED; TexInfoTemp.InterFormat = TC_FORMAT_RED; break;
		case 2: GLIB_ERR("Unsupported format!"); break;
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
		switch (GEngine::Get().GetGApi()->GetType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GAPI_OPENGL: pTex = new Texture1dOgl(strName); break;
	#endif	// GLIB_GAPI
		default: break;
		}
		return pTex;
	}
	ATexture2d* ATexture2d::Create(const char* strName) {
		ATexture2d* pTex = nullptr;
		switch (GEngine::Get().GetGApi()->GetType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GAPI_OPENGL: pTex = new Texture2dOgl(strName); break;
	#endif	// GLIB_GAPI
		default: break;
		}
		return pTex;
	}
	ATexture3d* ATexture3d::Create(const char* strName) {
		ATexture3d* pTex = nullptr;
		switch (GEngine::Get().GetGApi()->GetType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GAPI_OPENGL: pTex = new Texture3dOgl(strName); break;
	#endif	// GLIB_GAPI
		default: break;
		}
		return pTex;
	}
}
#endif	// GLIB_GAPI
#if (GLIB_GAPI & GLIB_GAPI_OGL)
#include <glad/glad.h>
namespace GLIB
{
	// Texture1d
	Texture1dOgl::Texture1dOgl(const char* strName) :
		ATexture1d(strName)
	{ }
	Texture1dOgl::~Texture1dOgl()
	{ }

	// --setters
	void Texture1dOgl::SetInfo(const TextureInfo& rTexInfo) {
		m_TexInfo = rTexInfo;
	}
	void Texture1dOgl::SetInfo(const ImageInfo& rImgInfo) {
		if (rImgInfo.nWidth < 1 || rImgInfo.nHeight < 1 || rImgInfo.nChannels < 1) { return; }
		if (m_ImgInfo.ClrData != &s_ClearColorData[0] && m_ImgInfo.ClrData != rImgInfo.ClrData && m_ImgInfo.ClrData != nullptr) {
			delete[] m_ImgInfo.ClrData;
			m_ImgInfo.ClrData = nullptr;
		}

		m_ImgInfo = rImgInfo;
	}

	// --==<Interface Methods>==--
	void Texture1dOgl::Bind(UInt32 unTexSlot)
	{
		m_unTexSlot = unTexSlot;
		glActiveTexture(GL_TEXTURE0 + m_unTexSlot);
		glBindTexture(GL_TEXTURE_1D, m_unRId);
	}
	void Texture1dOgl::Unbind()
	{
		glActiveTexture(GL_TEXTURE0 + m_unTexSlot);
		glBindTexture(GL_TEXTURE_1D, 0);
		m_unTexSlot = 0;
	}
	void Texture1dOgl::Remake()
	{
		if (m_unRId != 0) { glDeleteTextures(1, &m_unRId); m_unRId = 0; }
		glCreateTextures(GL_TEXTURE_1D, 1, &m_unRId);

		switch (m_ImgInfo.nChannels) {
		case 1: m_TexInfo.InterFormat = m_TexInfo.Format = TC_FORMAT_RED; break;
		case 2: GLIB_ERR("Unknown format!"); break;
		case 3: m_TexInfo.InterFormat = m_TexInfo.Format = TC_FORMAT_RGB; break;
		case 4: m_TexInfo.InterFormat = m_TexInfo.Format = TC_FORMAT_RGBA; break;
		default: return;
		}
		Bind(m_unTexSlot);
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
		Unbind();
	}
	// --==</core_methods>==--
	// Texture2d
	Texture2dOgl::Texture2dOgl(const char* strName) :
		ATexture2d(strName)
	{ }
	Texture2dOgl::~Texture2dOgl()
	{ }

	// --setters
	void Texture2dOgl::SetInfo(const TextureInfo& rTexInfo) {
		m_TexInfo = rTexInfo;
	}
	void Texture2dOgl::SetInfo(const ImageInfo& rImgInfo) {
		if (rImgInfo.nWidth < 1 || rImgInfo.nHeight < 1 || rImgInfo.nChannels < 1) { return; }
		if (m_ImgInfo.ClrData != &s_ClearColorData[0] && m_ImgInfo.ClrData != rImgInfo.ClrData && m_ImgInfo.ClrData != nullptr) {
			delete [] m_ImgInfo.ClrData;
			m_ImgInfo.ClrData = nullptr;
		}
		m_ImgInfo = rImgInfo;
		SetSubTexs(GetSubTexs());
	}

	// --==<Interface Methods>==--
	void Texture2dOgl::Bind(UInt32 unTexSlot)
	{
		m_unTexSlot = unTexSlot;
		glActiveTexture(GL_TEXTURE0 + m_unTexSlot);
		glBindTexture(GL_TEXTURE_2D, m_unRId);
	}
	void Texture2dOgl::Unbind()
	{
		glActiveTexture(GL_TEXTURE0 + m_unTexSlot);
		glBindTexture(GL_TEXTURE_2D, 0);
		m_unTexSlot = 0;
	}
	void Texture2dOgl::Remake()
	{
		if (m_unRId != 0) { glDeleteTextures(1, &m_unRId); m_unRId = 0; }
		glCreateTextures(GL_TEXTURE_2D, 1, &m_unRId);

		Bind(m_unTexSlot);
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
		Unbind();
	}
	// --==</core_methods>==--
	
	// Texture3d
	Texture3dOgl::Texture3dOgl(const char* strName) :
		ATexture3d(strName)
	{ }
	Texture3dOgl::~Texture3dOgl() { }

	// --setters
	void Texture3dOgl::SetInfo(const TextureInfo& rTexInfo) {
		m_TexInfo = rTexInfo;
	}
	void Texture3dOgl::SetInfo(const ImageInfo& rImgInfo) {
		if (rImgInfo.nWidth < 1 || rImgInfo.nHeight < 1 || rImgInfo.nChannels < 1) { return; }
		if (m_ImgInfo.ClrData != &s_ClearColorData[0] && m_ImgInfo.ClrData != rImgInfo.ClrData && m_ImgInfo.ClrData != nullptr) {
			delete [] m_ImgInfo.ClrData;
		}
		m_ImgInfo = rImgInfo;
	}

	// --==<Interface Methods>==--
	void Texture3dOgl::Bind(UInt32 unTexSlot)
	{
		m_unTexSlot = unTexSlot;
		glActiveTexture(GL_TEXTURE0 + m_unTexSlot);
		glBindTexture(GL_TEXTURE_3D, m_unRId);
	}
	void Texture3dOgl::Unbind()
	{
		glActiveTexture(GL_TEXTURE0 + m_unTexSlot);
		glBindTexture(GL_TEXTURE_3D, 0);
		m_unTexSlot = 0;
	}
	void Texture3dOgl::Remake()
	{
		if (m_unRId != 0) { glDeleteTextures(1, &m_unRId); m_unRId = 0; }
		glCreateTextures(GL_TEXTURE_3D, 1, &m_unRId);

		switch (m_ImgInfo.nChannels) {
		case 1: m_TexInfo.InterFormat = m_TexInfo.Format = TC_FORMAT_RED;
			break;
		case 3: m_TexInfo.InterFormat = m_TexInfo.Format = TC_FORMAT_RGB;
			break;
		case 4: m_TexInfo.InterFormat = m_TexInfo.Format = TC_FORMAT_RGBA;
			break;
		default: return;
		}
		Bind(m_unTexSlot);
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
		Unbind();
	}
	// --==</core_methods>==--
}
#endif // GLIB_GAPI