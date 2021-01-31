#include <glib_pch.hpp>
#include "glib_engine.h"

#include <glib_tools.h>
#include <glib_framebuf.h>

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
	GEngine::GEngine() :
		m_Memory(MemArena(nullptr, 0)), m_thrRun(Thread()), m_bIsRunning(false),
		m_Info(GEngineInfo()), m_Config(GEngineConfig()) { }
	GEngine::~GEngine() { }

	// --setters
	void GEngine::SetModes(Bit bEnable, ProcessingModes pm) { if (bEnable) { glEnable(static_cast<UInt32>(pm)); } else { glDisable(static_cast<UInt32>(pm)); } }
	void GEngine::SetViewport(Int32 nX, Int32 nY, Int32 nW, Int32 nH) { glViewport(nX, nY, nW, nH); }
	void GEngine::SetDrawMode(DrawModes dMode, FacePlanes facePlane) { m_Config.General.PolyMode.dMode = dMode; glPolygonMode(facePlane, dMode); }
	void GEngine::SetLineWidth(Float32 nLineWidth) { glLineWidth(nLineWidth); }
	void GEngine::SetPixelSize(Float32 nPxSize) { glPointSize(nPxSize); }
	void GEngine::SetBlendFunc(BlendConfigs unSrcFactorId, BlendConfigs unDestFactorId) { glBlendFunc(unSrcFactorId, unDestFactorId); }
	void GEngine::SetDepthFunc(DepthConfigs unDepthFuncId) { glDepthFunc(unDepthFuncId); }
	void GEngine::SetStencilFunc(StencilConfigs unFuncId, UInt32 unRefValue, UInt8 unBitMask) { glStencilFunc(unFuncId, unRefValue, unBitMask); }
	// --==<core_methods>==--
	void GEngine::Run()
	{
		Init();
		if (!m_bIsRunning) { return; }

		auto& fnUpdate = [this]()->void {
			while (m_bIsRunning) { Update(); }
			Quit();
		};
		m_thrRun = Thread(fnUpdate);
	}
	bool GEngine::Init()
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

		return (m_bIsRunning = true);
	}
	void GEngine::Quit()
	{
		if (!m_bIsRunning) { return; }
		m_bIsRunning = false;

		delete[] GetMemory().GetDataBeg();
		GetMemory() = MemArena(nullptr, 0);
	}
	void GEngine::Update()
	{
	}
	// --==</core_methods>==--

	// --==<drawing_methods>==--
	void GEngine::OnDraw(VertexArr& rVtxArr, GMaterial& rGMtl) {
		rGMtl.Enable();
		rVtxArr.Bind();
		if (rVtxArr.GetIdxBuffer() != nullptr) { glDrawElements(rVtxArr.GetDrawPrimitive(), rVtxArr.GetIdxBuffer()->GetDataSize() / sizeof(UInt32), GL_UNSIGNED_INT, 0); }
		else { glDrawArrays(rVtxArr.GetDrawPrimitive(), 0, rVtxArr.GetVtxBuffers().size()); }
		rVtxArr.Unbind();
		rGMtl.Disable();
	}
	// --==</drawing_methods>==--
}

/// OnDraw (AShape)
	/// Description:
	/// -- Shapes have a vertex data, indices and bound AGMaterial
	/// -- GEngine collects all the Vertex and Index data into some arrays from given object
	/// -- AGMaterial of the object provides GEngine's AGMaterial with textures
	/// -- Every new texture from new AGMaterial will be bound to the current GMtl
	/// -- In the EndDraw it will bind all owned textures and will set their samplerIDs to the own shader
	/// -- There is also default white texture which will be used if we don not have other textures