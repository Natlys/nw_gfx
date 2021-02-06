#include <glib_pch.hpp>
#include "glib_framebuf.h"

#if (defined GLIB_GAPI)
#include <glib_engine.h>
#include <glib_texture.h>
#endif // GLIB_GAPI
#if (GLIB_GAPI & GLIB_GAPI_OGL)
#include <glad/glad.h>
namespace GLIB
{
	FrameBuf::FrameBuf(const char* strName, const FrameBufInfo& rfbInfo) :
		TDataRes(strName),
		m_unRId(0), m_bIsBound(false),
		m_Info(rfbInfo),
		m_rgbaClear{ 0.5f, 0.5f, 0.5f, 1.0f }
	{ }
	FrameBuf::~FrameBuf()
	{
		SetViewport({ 0, 0, 0, 0 });
		Remake();
	}

	// --setters
	void FrameBuf::SetViewport(V4i rectViewport) { m_Info.rectViewport = rectViewport; }
	void FrameBuf::SetClearColor(V4f rgbaClear) { m_rgbaClear = rgbaClear; }
	void FrameBuf::AttachTexture(RefKeeper<Texture>& rTex) {
		m_Attachments.push_back(rTex);
	}
	void FrameBuf::DetachTexture(UInt32 unIdx) {
		NWL_ASSERT(unIdx <= m_Attachments.size(), "Overflow");
		m_Attachments.erase(m_Attachments.begin() + unIdx);
	}
	// --==<core_methods>==--
	void FrameBuf::Bind() const {
		if (m_bIsBound) { return; }
		glBindFramebuffer(GL_FRAMEBUFFER, m_unRId);
		glViewport(0, 0, GetWidth(), GetHeight());
		m_bIsBound = true;
	}
	void FrameBuf::Unbind() const {
		if (!m_bIsBound) { return; }
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		m_bIsBound = false;
	}

	void FrameBuf::Remake()
	{
		Unbind();
		if (m_unRId != 0) { glDeleteFramebuffers(1, &m_unRId); m_unRId = 0; }
		if (m_Info.GetHeight() < 1 || m_Info.GetWidth() < 1) { return; }

		glCreateFramebuffers(1, &m_unRId);
		Bind();

		m_Info.bHasStencil = m_Info.bHasDepth = false;
		m_Info.unColorCount = 0;
		UInt32 ColorIds[GL_MAX_COLOR_ATTACHMENTS] { 0 };

		for (UInt32 txi = 0; txi < m_Attachments.size(); txi++) {
			if (m_Attachments[txi].GetRef() == nullptr) { NWL_ERR("Null attachment!"); DetachTexture(txi); }
			auto& rTex = *m_Attachments[txi];
			ImageInfo imgInfo = rTex.GetImgInfo();
			if (m_Info.bResizable) {
				imgInfo.nWidth = GetWidth();
				imgInfo.nHeight = GetHeight();
			}
			TextureInfo texInfo = rTex.GetTexInfo();
			rTex.SetInfo(imgInfo);
			rTex.SetInfo(texInfo);
			rTex.Remake();
			rTex.Bind();
			UInt32 unAttachType = 0;
			if ((texInfo.texFormat == TXF_RGBA && texInfo.texInterFormat == TXFI_RGBA8)
				|| (texInfo.texFormat == TXF_RGB && texInfo.texInterFormat == TXFI_RGB)||
				(texInfo.texFormat == TXF_RED_INT && texInfo.texInterFormat == TXFI_RED_INT32))
			{
				unAttachType = GL_COLOR_ATTACHMENT0 + m_Info.unColorCount;
				ColorIds[m_Info.unColorCount] = rTex.GetRenderId();
				m_Info.unColorCount++;
			}
			else if (texInfo.texFormat == TXF_DEPTH && texInfo.texInterFormat == TXFI_DEPTH24)
			{
				m_Info.bHasDepth = true;
				unAttachType = GL_DEPTH_ATTACHMENT;
			}
			else if (texInfo.texFormat == TXF_STENCIL && texInfo.texInterFormat == TXFI_STENCIL8)
			{
				m_Info.bHasStencil = true;
				unAttachType = GL_STENCIL_ATTACHMENT;
			}
			else if (texInfo.texFormat == TXF_DEPTH_STENCIL && texInfo.texInterFormat == TXFI_DEPTH24_STENCIL8)
			{
				m_Info.bHasDepth = m_Info.bHasStencil = true;
				unAttachType = GL_DEPTH_STENCIL_ATTACHMENT;
			}
			glFramebufferTexture2D(GL_FRAMEBUFFER, unAttachType, rTex.GetType(), rTex.GetRenderId(), 0);
			rTex.Unbind();
		}
		if (m_Info.unColorCount > 0) { glDrawBuffers(m_Info.unColorCount, &ColorIds[0]); }
		else { glDrawBuffer(GL_NONE); }

		bool bIsCompleted = glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE;
		NWL_ASSERT(bIsCompleted, "FrameBufOgl is not created!");

		Unbind();
	}
	void FrameBuf::Clear(UInt32 bitMask) {
		glClearColor(m_rgbaClear.r, m_rgbaClear.g, m_rgbaClear.b, m_rgbaClear.a);
		glClear(bitMask);
	}

	void FrameBuf::ReadPixels(Ptr pData, UInt32 unAttachIdx, Int32 nX, Int32 nY, Int32 nW, Int32 nH)
	{
		const TextureInfo& texInfo = GetAttachment()->GetTexInfo();
		Bind();
		glReadBuffer(GL_COLOR_ATTACHMENT0 + unAttachIdx);
		glReadPixels(nX, nY, nW, nH, texInfo.texFormat, texInfo.pxFormat, pData);
		Unbind();
	}
	void FrameBuf::WritePixels(Ptr pData, UInt32 unAttachIdx, Int32 nX, Int32 nY, Int32 nW, Int32 nH)
	{
		const TextureInfo& texInfo = GetAttachment()->GetTexInfo();
		Bind();
		//glDrawBuffer(GL_COLOR_ATTACHMENT0 + unAttachIdx);
		glRasterPos2i(nX, nY);
		glDrawPixels(nW, nH, texInfo.texFormat, texInfo.pxFormat, pData);
		Unbind();
	}

	FrameBuf* FrameBuf::Create(const char* strName, const FrameBufInfo& rfbInfo) {
		return GraphEngine::Get().NewT<FrameBuf>(strName, rfbInfo);
	}
	static void Create(const char* strName, const FrameBufInfo& rfbInfo, RefKeeper<FrameBuf>& rfmBuf) {
		rfmBuf.MakeRef<FrameBuf>(GraphEngine::Get().GetMemory(), strName, rfbInfo);
	}
	// --==</core_methods>==--
}
#endif // GLIB_GAPI