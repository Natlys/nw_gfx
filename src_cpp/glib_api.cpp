#include <glib_pch.hpp>
#include "glib_api.h"

#if (defined GLIB_GAPI)
#include <glib_engine.h>
#include <glib_framebuf.h>
namespace GLIB
{
	AGApi::AGApi(GApiTypes gapiType) :
		m_gapiType(gapiType),
		m_unDrawModeId(DM_FILL), m_unPrimitiveTypeId(PT_TRIANGLES) { }
	
	// --core_methods
	AGApi* AGApi::Create()
	{
		AGApi* pGApi = nullptr;
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case (GAPI_OPENGL): pGApi = GEngine::Get().NewT<GApiOgl>(); break;
	#endif // GLIB_GAPI
		default: NWL_ERR("This graphics API is not defined"); break;
		}
		return pGApi;
	}
	void AGApi::Create(RefOwner<AGApi>& rGApi)
	{
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case (GAPI_OPENGL): rGApi.MakeRef<GApiOgl>(); break;
	#endif // GLIB_GAPI
		default: NWL_ERR("This graphics API is not defined"); break;
		}
	}
	void AGApi::Create(RefKeeper<AGApi>& rGApi)
	{
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case (GAPI_OPENGL): rGApi.MakeRef<GApiOgl>(); break;
	#endif // GLIB_GAPI
		default: NWL_ERR("This graphics API is not defined"); break;
		}
	}
}
#endif	// GLIB_GAPI
#if (GLIB_GAPI & GLIB_GAPI_OGL)
#include <glad/glad.h>
#if (GLIB_WAPI & GLIB_WAPI_GLFW)
#include <glfw/glfw3.h>
#endif	// GLIB_WAPI
namespace GLIB
{
	GApiOgl::GApiOgl() :
		AGApi(GApiTypes::GAPI_OPENGL) { }
	GApiOgl::~GApiOgl() = default;

	// --==<setters>==--
	void GApiOgl::SetModes(bool bEnable, ProcModes unModeId) { if (bEnable) { glEnable(unModeId); } else { glDisable(unModeId); } }
	void GApiOgl::SetViewport(Int32 nX, Int32 nY, Int32 nW, Int32 nH) { glViewport(nX, nY, nW, nH); }
	void GApiOgl::SetDrawMode(DrawModes unDrawModeId, FacePlanes unFacePlaneId) { m_unDrawModeId = unDrawModeId; glPolygonMode(unFacePlaneId, m_unDrawModeId); }
	void GApiOgl::SetLineWidth(UInt16 unPxW) { glLineWidth(unPxW); }
	void GApiOgl::SetPixelSize(float unPixelSize) { glPointSize(unPixelSize); }
	void GApiOgl::SetBlendFunc(BlendConfigs unSrcFactorId, BlendConfigs unDestFactorId) { glBlendFunc(unSrcFactorId, unDestFactorId); }
	void GApiOgl::SetDepthFunc(DepthConfigs unDepthFuncId) { glDepthFunc(unDepthFuncId); }
	void GApiOgl::SetStencilFunc(StencilConfigs unFuncId, UInt32 unRefValue, UInt8 unBitMask) { glStencilFunc(unFuncId, unRefValue, unBitMask); }
	// --==</setters>==--

	// --==<core_methods>==--
	bool GApiOgl::Init()
	{
	#if ((GLIB_WAPI & GLIB_WAPI_GLFW) && (GLIB_GAPI & GLIB_GAPI_OGL))
		gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress));

		m_Info = GApiInfo(glGetString(GL_RENDERER), glGetString(GL_VERSION),
			glGetString(GL_VENDOR), glGetString(GL_SHADING_LANGUAGE_VERSION));
		glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &m_Info.nMaxTextures);
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &m_Info.nMaxVertexAttribs);
		std::cout << m_Info;
	#endif	// GLIB_WINDOW
		return true;
	}
	void GApiOgl::OnQuit()
	{ }
	// --==</core_methods>==--
	// --==<drawing>==--
	void GApiOgl::DrawIndexed(UInt32 unIndexCount) { glDrawElements(m_unPrimitiveTypeId, unIndexCount, GL_UNSIGNED_INT, nullptr); }
	void GApiOgl::DrawArray(UInt32 unVertexCount) { glDrawArrays(m_unPrimitiveTypeId, 0, unVertexCount); }
	// --==</drawing>==--
}
#endif // GLIB_GAPI