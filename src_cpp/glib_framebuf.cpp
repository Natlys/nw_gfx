#include <glib_pch.hpp>
#include "glib_framebuf.h"

#if (defined GLIB_GAPI)
#include <glib_engine.h>
#include <glib_api.h>
#include <glib_texture.h>
namespace GLIB
{
	AFrameBuf::AFrameBuf(const char* strName, const FrameBufInfo& rfbInfo) :
		ADataRes(strName),
		m_unRId(0), m_bIsBound(false),
		m_Info(rfbInfo),
		m_DepthAttach(0), m_ColorAttach(RefKeeper<ATexture2d>(GEngine::Get().GetMemory())),
		m_rgbaClear{0.5f, 0.5f, 0.5f, 1.0f}
	{
		String strClrName = strName;
		ATexture2d::Create(&strClrName[0], m_ColorAttach);
		ADataRes::AddDataRes<AFrameBuf>(this);
	}
	AFrameBuf::~AFrameBuf() { ADataRes::RmvDataRes<AFrameBuf>(GetId()); }

	// --setters
	void AFrameBuf::SetSizeWH(UInt32 unWidth, UInt32 unHeight) { m_Info.unWidth = unWidth; m_Info.unHeight = unHeight; Remake(); }
	void AFrameBuf::SetClearColor(V4f rgbaClear) { m_rgbaClear = rgbaClear; }

	// --core_methods
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
		// Constructor&Destructor
		FrameBufOgl::FrameBufOgl(const char* strName, const FrameBufInfo& rfbInfo) :
			AFrameBuf(strName, rfbInfo) { Remake();}
		FrameBufOgl::~FrameBufOgl()
		{ glDeleteFramebuffers(1, &m_unRId); glDeleteRenderbuffers(1, &m_DepthAttach); }

		// --==<Core methods>==--
		void FrameBufOgl::Bind() const {
			if (m_bIsBound) { return; }
			glBindFramebuffer(GL_FRAMEBUFFER, m_unRId);
			glViewport(0, 0, GetWidth(), GetHeight());
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
			if (m_unRId != 0) {
				glDeleteFramebuffers(1, &m_unRId);
				glDeleteRenderbuffers(1, &m_DepthAttach);
			}

			glCreateFramebuffers(1, &m_unRId);
			glBindFramebuffer(GL_FRAMEBUFFER, m_unRId);

			ImageInfo ImgInfo;
			ImgInfo.ClrData = nullptr;
			ImgInfo.nChannels = 4;
			ImgInfo.nWidth = GetWidth();
			ImgInfo.nHeight = GetHeight();
			TextureInfo TexInfo;
			TexInfo.FilterMag = TexInfo.FilterMin = TXF_LINEAR;
			TexInfo.texInterFormat = TXF_RGBA8; TexInfo.texFormat = TXF_RGBA;
			m_ColorAttach->SetInfo(TexInfo);
			m_ColorAttach->SetInfo(ImgInfo);
			m_ColorAttach->Remake();
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_ColorAttach->GetRenderId(), 0);

			glCreateRenderbuffers(1, &m_DepthAttach);
			glBindRenderbuffer(GL_RENDERBUFFER, m_DepthAttach);
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, GetWidth(), GetHeight());
			glBindRenderbuffer(GL_RENDERBUFFER, 0);

			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_DepthAttach);

			bool bIsCompleted = glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE;
			NWL_ASSERT(bIsCompleted, "FrameBufOgl is not created!");

			glBindFramebuffer(GL_FRAMEBUFFER, 0);
		}
		void FrameBufOgl::Clear() {
			UInt32 unMask = 0;
			unMask |= m_ColorAttach.GetRef() != nullptr ? FB_COLOR : 0;
			unMask |= m_DepthAttach != 0 ? FB_DEPTH : 0;
			glClearColor(m_rgbaClear.r, m_rgbaClear.g, m_rgbaClear.b, m_rgbaClear.a);
			glClear(unMask);
		}

		void FrameBufOgl::ReadPixels(Ptr pData, UInt32 unAttachIdx, Int32 nX, Int32 nY, Int32 nW, Int32 nH)
		{
			Bind();
			glReadBuffer(GL_COLOR_ATTACHMENT0);
			glReadPixels(nX, nY, nW, nH, GL_RGBA, GL_UNSIGNED_BYTE, pData);
			Unbind();
		}
		void FrameBufOgl::WritePixels(Ptr pData, Int32 nW, Int32 nH)
		{
			Bind();
			glDrawBuffer(GL_COLOR_ATTACHMENT0);
			glDrawPixels(nW, nH, GL_RGBA, GL_UNSIGNED_BYTE, pData);
			Unbind();
		}
		// --==</core_methods>==--
	}
#endif // GLIB_GAPI