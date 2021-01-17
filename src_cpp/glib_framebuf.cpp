#include <glib_pch.hpp>
#include "glib_framebuf.h"
#include <glib_texture.h>

#if (defined GLIB_GAPI)
#include <core/glib_engine.h>
#include <core/glib_api.h>
namespace GLIB
{
	AFrameBuf::AFrameBuf(const char* strName, const FrameBufInfo& rfbInfo) :
		AGRes(strName),
		m_unRId(0),
		m_Info(rfbInfo), m_unRIdDepth(0), m_ColorAttach(nullptr)
	{
		String strClrName = strName;
		m_ColorAttach = ATexture2d::Create(&strClrName[0]);
	}
	AFrameBuf::~AFrameBuf() { }

	// --setters
	void AFrameBuf::SetSizeWH(UInt32 unWidth, UInt32 unHeight) {
		m_Info.unWidth = unWidth; m_Info.unHeight = unHeight; Remake();
	}

	AFrameBuf* AFrameBuf::Create(const char* strName, const FrameBufInfo& rfbInfo)
	{
		AFrameBuf* pFB = nullptr;
		switch (GEngine::Get().GetGApi()->GetType())
		{
	#if (GLIB_GAPI & GLIB_GAPI_COUT)
		case GApiTypes::GAPI_COUT:
			pFB = MemSys::NewT<FrameBufCout>(strName, rfbInfo);
			break;
	#endif // GLIB_GAPI
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GApiTypes::GAPI_OPENGL: pFB = new FrameBufOgl(strName, rfbInfo); break;
	#endif // GLIB_GAPI
		default: GLIB_ERR("Graphics API is not defined"); break;
		}
		return pFB;
	}
}
#endif // GLIB_GAPI
#if (GLIB_GAPI & GLIB_GAPI_OGL)
#include <glad/glad.h>
namespace GLIB
{
	// Constructor&Destructor
	FrameBufOgl::FrameBufOgl(const char* strName, const FrameBufInfo& rfbInfo) :
		AFrameBuf(strName, rfbInfo)
	{
		Remake();
	}
	FrameBufOgl::~FrameBufOgl()
	{
		glDeleteFramebuffers(1, &m_unRId);
		glDeleteRenderbuffers(1, &m_unRIdDepth);
	}

	// --==<Core methods>==--
	void FrameBufOgl::Bind() const { glBindFramebuffer(GL_FRAMEBUFFER, m_unRId); }
	void FrameBufOgl::Unbind() const { glBindFramebuffer(GL_FRAMEBUFFER, 0); }

	void FrameBufOgl::Remake()
	{
		if (m_Info.unHeight > 4096 || m_Info.unHeight == 0 ||
			m_Info.unWidth > 4096 || m_Info.unWidth == 0) {
			return;
		}
		if (m_unRId != 0 || m_ColorAttach->GetRenderId() != 0 || m_unRIdDepth != 0) {
			glDeleteFramebuffers(1, &m_unRId);
			glDeleteRenderbuffers(1, &m_unRIdDepth);
		}

		glCreateFramebuffers(1, &m_unRId);
		glBindFramebuffer(GL_FRAMEBUFFER, m_unRId);

		ImageInfo ImgInfo;
		ImgInfo.ClrData = nullptr;
		ImgInfo.nChannels = 4;
		ImgInfo.nDepth = 1;
		ImgInfo.nWidth = static_cast<Int32>(m_Info.unWidth);
		ImgInfo.nHeight = static_cast<Int32>(m_Info.unHeight);
		TextureInfo TexInfo;
		TexInfo.FilterMag = TexInfo.FilterMin = TC_FILTER_LINEAR;
		TexInfo.InterFormat = TC_FORMAT_RGBA8; TexInfo.Format = TC_FORMAT_RGB;
		m_ColorAttach->SetInfo(TexInfo);
		m_ColorAttach->SetInfo(ImgInfo);
		m_ColorAttach->Remake();
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_ColorAttach->GetRenderId(), 0);

		glCreateRenderbuffers(1, &m_unRIdDepth);
		glBindRenderbuffer(GL_RENDERBUFFER, m_unRIdDepth);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8,
			static_cast<Int32>(m_Info.unWidth), static_cast<Int32>(m_Info.unHeight));
		glBindRenderbuffer(GL_RENDERBUFFER, 0);

		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_unRIdDepth);

		bool bIsCompleted = glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE;
		GLIB_ASSERT(bIsCompleted, "FrameBufOgl is not created!");

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}
	void FrameBufOgl::Clear(UInt32 unAttachmentsMask) { glClear(unAttachmentsMask); }
	// --==</Core methods>==--
}
#endif // GLIB_GAPI