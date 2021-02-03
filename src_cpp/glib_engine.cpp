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
	void GraphEngine::SetModes(Bit bEnable, ProcessingModes pm) { if (bEnable) { glEnable(static_cast<UInt32>(pm)); } else { glDisable(static_cast<UInt32>(pm)); } }
	void GraphEngine::SetViewport(Int32 nX, Int32 nY, Int32 nW, Int32 nH) { glViewport(nX, nY, nW, nH); }
	void GraphEngine::SetDrawMode(DrawModes dMode, FacePlanes facePlane) { m_Config.General.PolyMode.dMode = dMode; glPolygonMode(facePlane, dMode); }
	void GraphEngine::SetLineWidth(Float32 nLineWidth) { glLineWidth(nLineWidth); }
	void GraphEngine::SetPixelSize(Float32 nPxSize) { glPointSize(nPxSize); }
	void GraphEngine::SetBlendFunc(BlendConfigs unSrcFactorId, BlendConfigs unDestFactorId) { glBlendFunc(unSrcFactorId, unDestFactorId); }
	void GraphEngine::SetDepthFunc(DepthConfigs unDepthFuncId) { glDepthFunc(unDepthFuncId); }
	void GraphEngine::SetStencilFunc(StencilConfigs unFuncId, UInt32 unRefValue, UInt8 unBitMask) { glStencilFunc(unFuncId, unRefValue, unBitMask); }
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
		GetMemory() = MemArena(new Byte[1 << 16], 1 << 16);

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

		for (auto& itState : m_States) { if (!itState->Init()) { return false; } }

		return (m_bIsRunning = true);
	}
	void GraphEngine::Quit()
	{
		if (!m_bIsRunning) { return; }
		m_bIsRunning = false;

		for (auto& itState : m_States) { itState->OnQuit(); }

		auto& rFbs = ADataRes::GetDataResources<FrameBuf>();
		while (!rFbs.empty()) { rFbs.begin()->second->~FrameBuf(); }
		auto& rTxs = ADataRes::GetDataResources<Texture>();
		while (!rTxs.empty()) { rTxs.begin()->second->~Texture(); }
		auto& rShds = ADataRes::GetDataResources<Shader>();
		while (!rShds.empty()) { rShds.begin()->second->~Shader(); }
		auto& rGMtls = ADataRes::GetDataResources<GMaterial>();
		while (!rGMtls.empty()) { rGMtls.begin()->second->~GMaterial(); }

		delete[] GetMemory().GetDataBeg();
		GetMemory() = MemArena(nullptr, 0);
	}
	void GraphEngine::Update()
	{
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
					break;
				default: break;
				}
				break;
			case ET_KEY_PRESS:
				switch (pkEvt->unKeyCode) {
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
	void GraphEngine::OnDraw(VertexArr& rVtxArr, GMaterial& rGMtl) {
		rGMtl.Enable();
		rVtxArr.Bind();
		if (rVtxArr.GetIdxBuffer() != nullptr) {
			glDrawElements(rVtxArr.GetDrawPrimitive(), rVtxArr.GetIdxBuffer()->GetDataSize() / sizeof(UInt32), GL_UNSIGNED_INT, 0);
		}
		else {
			glDrawArrays(rVtxArr.GetDrawPrimitive(), 0, rVtxArr.GetVtxBuffers().size());
		}
		rVtxArr.Unbind();
		rGMtl.Disable();
	}
	void GraphEngine::OnDraw(Drawable& rDrb) {
		rDrb.gMtl->Enable();
		rDrb.vtxArr->Bind();
		if (rDrb.idxBuf.GetRef() != nullptr) {
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
	/// -- Every new texture from new AGMaterial will be bound to the current GMtl
	/// -- In the EndDraw it will bind all owned textures and will set their samplerIDs to the own shader
	/// -- There is also default white texture which will be used if we don not have other textures