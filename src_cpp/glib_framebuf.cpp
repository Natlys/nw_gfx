#include <glib_pch.hpp>
#include "glib_framebuf.h"

#if (defined GLIB_GAPI)
#include <glib_engine.h>
#include <glib_texture.h>
#include <glib_api.h>
namespace GLIB
{
	AFrameBuf::AFrameBuf(const char* strName, const FrameBufInfo& rfbInfo) :
		ADataRes(strName),
		m_unRId(0), m_bIsBound(false),
		m_texColor(RefKeeper<ATexture2d>(GEngine::Get().GetMemory())),
		m_texDepth(RefKeeper<ATexture2d>(GEngine::Get().GetMemory())),
		m_texStencil(RefKeeper<ATexture2d>(GEngine::Get().GetMemory())),
		m_Info(rfbInfo),
		m_rgbaClear { 0.5f, 0.5f, 0.5f, 1.0f }
	{
		String strAtchName = "fbc_" + m_strName;
		ATexture2d::Create(&strAtchName[0], m_texColor);
		strAtchName = "fbd_" + m_strName;
		ATexture2d::Create(&strAtchName[0], m_texDepth);
		strAtchName = "fbs_" + m_strName;
		ATexture2d::Create(&strAtchName[0], m_texStencil);

		ADataRes::AddDataRes<AFrameBuf>(this);
	}
	AFrameBuf::~AFrameBuf() { ADataRes::RmvDataRes<AFrameBuf>(GetId()); }

	AFrameBuf* AFrameBuf::Create(const char* strName, const FrameBufInfo& rfbInfo)
	{
		AFrameBuf* pFB = nullptr;
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GApiTypes::GAPI_OPENGL: pFB = GEngine::Get().NewT<FrameBufOgl>(strName, rfbInfo); break;
	#endif // GLIB_GAPI
		default: NWL_ERR("Graphics API is not defined"); break;
		}
		return pFB;
	}
	void AFrameBuf::Create(const char* strName, const FrameBufInfo& rfbInfo, RefOwner<AFrameBuf>& rfBuf)
	{
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GApiTypes::GAPI_OPENGL: rfBuf.MakeRef<FrameBufOgl>(strName, rfbInfo); break;
	#endif // GLIB_GAPI
		default: NWL_ERR("Graphics API is not defined"); break;
		}
	}
	void AFrameBuf::Create(const char* strName, const FrameBufInfo& rfbInfo, RefKeeper<AFrameBuf>& rfBuf)
	{
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GApiTypes::GAPI_OPENGL: rfBuf.MakeRef<FrameBufOgl>(strName, rfbInfo); break;
	#endif // GLIB_GAPI
		default: NWL_ERR("Graphics API is not defined"); break;
		}
	}
}
#endif // GLIB_GAPI
#if (GLIB_GAPI & GLIB_GAPI_OGL)
#include <glad/glad.h>
namespace GLIB
{
	FrameBufOgl::FrameBufOgl(const char* strName, const FrameBufInfo& rfbInfo) :
		AFrameBuf(strName, rfbInfo) { Remake(); }
	FrameBufOgl::~FrameBufOgl() { glDeleteFramebuffers(1, &m_unRId); }

	// --setters
	void FrameBufOgl::SetSizeWH(UInt32 unWidth, UInt32 unHeight) {
		m_Info.unWidth = unWidth; m_Info.unHeight = unHeight; Remake();
	}
	void FrameBufOgl::SetClearColor(V4f rgbaClear) { m_rgbaClear = rgbaClear; glClearColor(rgbaClear.r, rgbaClear.g, rgbaClear.b, rgbaClear.a); }

	// --==<core_methods>==--
	void FrameBufOgl::Bind() const {
		if (m_bIsBound) { return; }
		glBindFramebuffer(GL_FRAMEBUFFER, m_unRId);
		m_bIsBound = true;
	}
	void FrameBufOgl::Unbind() const {
		if (!m_bIsBound) { return; }
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		m_bIsBound = false;
	}

	void FrameBufOgl::Remake()
	{
		if (m_Info.unHeight > 4096 || m_Info.unHeight == 0 ||
			m_Info.unWidth > 4096 || m_Info.unWidth == 0) { return; }
		if (m_unRId != 0) { glDeleteFramebuffers(1, &m_unRId); }

		glCreateFramebuffers(1, &m_unRId);
		glBindFramebuffer(GL_FRAMEBUFFER, m_unRId);

		ImageInfo ImgInfo;
		TextureInfo TexInfo;

		ImgInfo.ClrData = nullptr;
		ImgInfo.nDepth = 1;
		ImgInfo.nWidth = GetWidth();
		ImgInfo.nHeight = GetHeight();
		
		if (true) {
			ImgInfo.nChannels = 4;
			TexInfo.FilterMag = TexInfo.FilterMin = TC_FILTER_LINEAR;
			TexInfo.InterFormat = TC_FORMAT_RGBA8; TexInfo.Format = TC_FORMAT_RGBA8;
			m_texColor->SetInfo(TexInfo);
			m_texColor->SetInfo(ImgInfo);
			m_texColor->Remake();
			m_texColor->Bind(0);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_texColor->GetRenderId(), 0);
			m_texColor->Unbind();
		}
		if (false) {
			ImgInfo.nChannels = 1;
			TexInfo.FilterMag = TexInfo.FilterMin = TC_FILTER_LINEAR;
			TexInfo.InterFormat = TC_FORMAT_UINT_24_8; TexInfo.Format = TC_FORMAT_DEPTH_STENCIL;
			m_texDepth->SetInfo(TexInfo);
			m_texDepth->SetInfo(ImgInfo);
			m_texDepth->Remake();
			m_texDepth->Bind(0);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, m_texDepth->GetRenderId(), 0);
			m_texDepth->Unbind();
		}
		if (false) {
			ImgInfo.nChannels = 1;
			TexInfo.FilterMag = TexInfo.FilterMin = TC_FILTER_LINEAR;
			TexInfo.InterFormat = TC_FORMAT_UINT_24_8; TexInfo.Format = TC_FORMAT_RED;
			m_texStencil->SetInfo(TexInfo);
			m_texStencil->SetInfo(ImgInfo);
			m_texStencil->Remake();
			m_texStencil->Bind(0);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_TEXTURE_2D, m_texStencil->GetRenderId(), 0);
			m_texStencil->Unbind();
		}

		bool bIsCompleted = glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE;
		NWL_ASSERT(bIsCompleted, "FrameBufOgl is not created!");
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}
	void FrameBufOgl::Clear(UInt32 unAttachmentsMask) { glClear(unAttachmentsMask); }
	// --==</Core methods>==--
}
#endif // GLIB_GAPI