#include <glib_pch.hpp>
#include "glib_engine.h"

#include <glib_tools.h>
#include <glib_framebuf.h>
#include <glib_drawable.h>

#include <glib_camera.h>
#include <glib_shader.h>
#include <glib_material.h>
#include <glib_texture.h>

#include <stb_image.h>

#include <../src_glsl/shd_screen.hpp>

#if (defined GLIB_GAPI)
#if (GLIB_GAPI & GLIB_GAPI_OGL)
#include <glad/glad.h>
	#if (defined GLIB_WAPI)
	#if (GLIB_WAPI & GLIB_WAPI_GLFW)
	#include <glfw/glfw3.h>
	#endif
	#endif	// GLIB_WAPI
#endif
#endif	// GLIB_GAPI

namespace GLIB
{
	GraphEngine::GraphEngine() :
		AEngine(),
		m_Info(GraphInfo()), m_Config(GraphConfig()),
		m_pfmBuf(nullptr) { }
	GraphEngine::~GraphEngine() { }

	// --setters
	void GraphEngine::SetModes(Bit bEnable, ProcessingModes pModes) { if (bEnable) { glEnable(pModes); } else { glDisable(pModes); } }
	void GraphEngine::SetViewport(Int32 nX, Int32 nY, Int32 nW, Int32 nH) { glViewport(nX, nY, nW, nH); }
	void GraphEngine::SetDrawMode(DrawModes dMode, FacePlanes facePlane) { m_Config.General.PolyMode.dMode = dMode; glPolygonMode(facePlane, dMode); }
	void GraphEngine::SetLineWidth(Float32 nLineWidth) { glLineWidth(nLineWidth); }
	void GraphEngine::SetPixelSize(Float32 nPxSize) { glPointSize(nPxSize); }
	void GraphEngine::SetBlendFunc(BlendConfigs unSrcFactorId, BlendConfigs unDestFactorId) { glBlendFunc(unSrcFactorId, unDestFactorId); }
	void GraphEngine::SetDepthFunc(DepthConfigs unDepthFuncId) { glDepthFunc(unDepthFuncId); }
	void GraphEngine::SetStencilFunc(StencilConfigs unFuncId, UInt32 unRefValue, UInt8 unBitMask) { glStencilFunc(unFuncId, unRefValue, unBitMask); }
	void GraphEngine::SetFrameBuf(FrameBuf* pfmBuf) {
		m_pfmBuf = pfmBuf;
		NWL_ASSERT(pfmBuf->GetAttachment(0) != nullptr, "There must be at least one attachment!");
		m_drbScreen.gMtl->SetTexture(m_pfmBuf->GetAttachment(0));
	}
	// --==<core_methods>==--
	void GraphEngine::Run()
	{
		Init();
		if (!m_bIsRunning) { return; }

		auto& fnUpdate = [this]()->void {
			while (m_bIsRunning) { Update(); }
			Quit();
		};
		m_thrRun = Thread(fnUpdate);
	}
	bool GraphEngine::Init()
	{
		if (m_bIsRunning) { return false; }
		GetMemory() = MemArena(new Byte[1 << 18], 1 << 18);

	#if (defined GLIB_GAPI)
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		GLADloadproc fnLoadProc = nullptr;
		#if (defined GLIB_WAPI)
		#if (GLIB_WAPI& GLIB_WAPI_GLFW)
		fnLoadProc = reinterpret_cast<GLADloadproc>(glfwGetProcAddress);
		#endif
		#endif	// GLIB_WAPI
		gladLoadGLLoader(fnLoadProc);
		{
			{
				const char* str = ((const char*)glGetString(GL_RENDERER));
				strcpy(&m_Info.strRenderer[0], &str[0]);
			}
			{
				const char* str = ((const char*)glGetString(GL_VERSION));
				strcpy(&m_Info.strVersion[0], &str[0]);
			}
			{
				const char* str = ((const char*)glGetString(GL_VENDOR));
				strcpy(&m_Info.strVendor[0], &str[0]);
			}
			{
				const char* str = ((const char*)glGetString(GL_SHADING_LANGUAGE_VERSION));
				strcpy(&m_Info.strShdLang[0], &str[0]);
			}
			std::cout << m_Info;
		}
	#endif
	#endif	// GLIB_GAPI
		{	// textures
			Texture* pTex = nullptr;
			ImageInfo imgInfo;
			TextureInfo texInfo;
			UByte whiteData[] = { 255,	255,	255,	255 };
			imgInfo.pClrData = whiteData;
			imgInfo.nChannels = 1;
			imgInfo.nWidth = imgInfo.nHeight = 1;
			texInfo.bGenMipmap = false;
			texInfo.bGenSubImage= false;
			texInfo.FilterMag = texInfo.FilterMin = TXF_NEAREST;
			texInfo.pxFormat = PXF_UINT32;
			texInfo.texFormat = TXF_RGBA; texInfo.texInterFormat = TXFI_RGBA8;
			texInfo.unSamples = 1;
			texInfo.WrapTypeS = texInfo.WrapTypeT = texInfo.WrapTypeR = TXW_REPEAT;
			pTex = Texture::Create("tex_white_solid", TXT_2D);
			pTex->SetInfo(imgInfo);
			pTex->SetInfo(texInfo);
			pTex->Remake();
		}
		{	// screen drawable info
			VertexArr::Create(m_drbScreen.vtxArr);
			Float32 vtxData[] = {
				-1.0f,	-1.0f,		0.0f,	0.0f,
				-1.0f,	1.0f,		0.0f,	1.0f,
				1.0f,	1.0f,		1.0f,	1.0f,
				1.0f,	-1.0f,		1.0f,	0.0f,
			};
			m_drbScreen.vtxArr->CreateVtxBuffer();
			m_drbScreen.vtxArr->GetVtxBuffer()->SetData(sizeof(vtxData), &vtxData[0]);
			UInt32 idxData[] = { 0,	1,	2,		2,	3,	0 };
			m_drbScreen.vtxArr->CreateIdxBuffer();
			m_drbScreen.vtxArr->GetIdxBuffer()->SetData(sizeof(idxData), &idxData[0]);
			{
				Shader* pShader = Shader::Create("shd_screen_0");
				pShader->SetCode(&strScreenShaderCode[0]);
				if (!pShader->Compile()) { Quit(); return false; }

				m_drbScreen.gMtl = GMaterial::Create("gmt_screen_0");
				m_drbScreen.gMtl->SetShader(pShader);
				m_drbScreen.vtxArr->Remake(pShader->GetVtxLayout());
			}
		}
		{	// screen framebuffer
			FrameBufInfo fbInfo;
			fbInfo.rectViewport = { 0, 0, 1200, 800 };

			if (true) {
				FrameBuf* pfmBuf = FrameBuf::Create("fmb_draw_0", fbInfo);
				RefKeeper<Texture> rTex;
				TextureInfo texInfo;
				texInfo.bGenMipmap = true; texInfo.bGenSubImage = true;
				texInfo.unSamples = 1;

				Texture::Create("fba_draw_color_0", TXT_2D, rTex);
				texInfo.pxFormat = PXF_UINT8;
				texInfo.texFormat = TXF_RGB; texInfo.texInterFormat = TXFI_RGB;
				rTex->SetInfo(texInfo);
				pfmBuf->AttachTexture(rTex);

				Texture::Create("fba_draw_depth_stencil_0", TXT_2D, rTex);
				texInfo.pxFormat = PXF_UINT24_8;
				texInfo.texFormat = TXF_DEPTH_STENCIL; texInfo.texInterFormat = TXFI_DEPTH24_STENCIL8;
				rTex->SetInfo(texInfo);
				pfmBuf->AttachTexture(rTex);

				pfmBuf->Remake();
				GraphEngine::Get().SetFrameBuf(pfmBuf);
			}
		}

		for (auto& itState : m_States) { if (!itState->Init()) { return false; } }

		return (m_bIsRunning = true);
	}
	void GraphEngine::Quit()
	{
		if (!m_bIsRunning) { return; }
		m_bIsRunning = false;

		for (auto& itState : m_States) { itState->OnQuit(); }
		
		m_drbScreen = Drawable();

		auto& rFbs = TDataRes<FrameBuf>::GetStorage();
		for (auto& itFb : rFbs) { if (itFb != nullptr) itFb->~FrameBuf(); }
		auto& rTxs = TDataRes<Texture>::GetStorage();
		for (auto& itTex : rTxs) { if (itTex != nullptr) itTex->~Texture(); }
		auto& rShds = TDataRes<Shader>::GetStorage();
		for (auto& itShd : rShds){ if(itShd != nullptr) itShd->~Shader(); }
		auto& rgMtls = TDataRes<GMaterial>::GetStorage();
		for (auto& itgMtl : rgMtls) { if (itgMtl != nullptr) itgMtl->~GMaterial(); }

		delete[] GetMemory().GetDataBeg();
		GetMemory() = MemArena(nullptr, 0);
	}

	void GraphEngine::Update()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		OnDraw(m_drbScreen);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		for (auto& itState : m_States) { itState->Update(); }
	}

	void GraphEngine::OnEvent(AEvent& rEvt)
	{
		if (rEvt.IsInCategory(EC_MOUSE)) {
			MouseEvent* pmEvt = static_cast<MouseEvent*>(&rEvt);
			switch (pmEvt->evType) {
			case ET_MOUSE_MOVE:
				break;
			case ET_MOUSE_SCROLL:
				break;
			case ET_MOUSE_RELEASE:
				break;
			case ET_MOUSE_PRESS:
				break;
			}
			if (rEvt.bIsHandled) return;
			for (auto& itState : m_States) { itState->OnEvent(*pmEvt); }
		}
		else if (rEvt.IsInCategory(EC_KEYBOARD)) {
			KeyboardEvent* pkEvt = static_cast<KeyboardEvent*>(&rEvt);
			switch (pkEvt->evType) {
			case ET_KEY_RELEASE:
				switch (pkEvt->unKeyCode) {
				case KC_ENTER: break;
				default: break;
				}
				break;
			case ET_KEY_PRESS:
				switch (pkEvt->unKeyCode) {
				case KC_ENTER: break;
				default: break;
				}
				break;
			case ET_KEY_CHAR:
				break;
				if (rEvt.bIsHandled) { return; }
				for (auto& itState : m_States) { itState->OnEvent(*pkEvt); }
			}
		}
		else if (rEvt.IsInCategory(EC_WINDOW)) {
			WindowEvent* pwEvt = static_cast<WindowEvent*>(&rEvt);
			switch (pwEvt->evType) {
			case ET_WINDOW_RESIZE:
				m_pfmBuf->SetViewport({ 0, 0, pwEvt->nX, pwEvt->nY });
				m_pfmBuf->Remake();
				break;
			case ET_WINDOW_MOVE:
				break;
			case ET_WINDOW_FOCUS:
				break;
			case ET_WINDOW_CLOSE:
				StopRunning();
				rEvt.bIsHandled = true;
				break;
			}
			if (rEvt.bIsHandled) { return; }
			for (auto& itState : m_States) { itState->OnEvent(*pwEvt); }
		}
	}
	// --==</core_methods>==--

	// --==<drawing_methods>==--
	void GraphEngine::OnDraw(VertexArr& rVtxArr, GMaterial& rgMtl) {
		rgMtl.Enable();
		rVtxArr.Bind();
		if (rVtxArr.GetIdxBuffer() != nullptr) {
			glDrawElements(rVtxArr.GetDrawPrimitive(), rVtxArr.GetIdxBuffer()->GetDataSize() / sizeof(UInt32), GL_UNSIGNED_INT, 0);
		}
		else {
			glDrawArrays(rVtxArr.GetDrawPrimitive(), 0, rVtxArr.GetVtxBuffers().size());
		}
		rVtxArr.Unbind();
		rgMtl.Disable();
	}
	void GraphEngine::OnDraw(Drawable& rDrb) {
		rDrb.gMtl->Enable();
		rDrb.vtxArr->Bind();
		if (rDrb.vtxArr->GetVtxBuffer() != nullptr) {
			glDrawElements(rDrb.vtxArr->GetDrawPrimitive(), rDrb.vtxArr->GetIdxBuffer()->GetDataSize() / sizeof(UInt32), GL_UNSIGNED_INT, 0);
		}
		else {
			glDrawArrays(rDrb.vtxArr->GetDrawPrimitive(), 0, rDrb.vtxArr->GetVtxBuffers().size());
		}
		rDrb.vtxArr->Unbind();
		rDrb.gMtl->Disable();
	}
	// --==</drawing_methods>==--
}

/// OnDraw (AShape)
	/// Description:
	/// -- Shapes have a vertex data, indices and bound AGMaterial
	/// -- GraphEngine collects all the Vertex and Index data into some arrays from given object
	/// -- AGMaterial of the object provides GraphEngine's AGMaterial with textures
	/// -- Every new texture from new AGMaterial will be bound to the current gMtl
	/// -- In the EndDraw it will bind all owned textures and will set their samplerIDs to the own shader
	/// -- There is also default white texture which will be used if we don not have other textures