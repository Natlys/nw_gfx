#include <glib_pch.hpp>
#include "core/glib_api.h"

#if (defined GLIB_GAPI)
#include <glib_core.hpp>
#include <core/glib_context.h>
#include <glib_framebuf.h>
namespace GLIB
{
	AGApi* AGApi::Create(GApiTypes GApitype)
	{
		AGApi* pGApi = nullptr;
		switch (GApitype) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case (GAPI_OPENGL): pGApi = new GApiOgl(); break;
	#endif // GLIB_GAPI
		default: GLIB_ERR("This graphics API is not defined"); break;
		}
		return pGApi;
	}
}
#endif	// GLIB_GAPI

#if (GLIB_GAPI & GLIB_GAPI_OGL)
#include <glad/glad.h>

namespace GLIB
{
	GApiOgl::GApiOgl() :
		m_gapiType(GAPI_OPENGL),
		m_unPrimitiveTypeId(PT_TRIANGLES) {}
	GApiOgl::~GApiOgl() = default;

	// --==<setters>==--
	void GApiOgl::SetModes(bool bEnable, ProcModes unModeId) {
		if (bEnable) { glEnable(unModeId); }
		else { glDisable(unModeId); }
	}
	void GApiOgl::SetClearColor(float nRed, float nGreen, float nBlue, float nAlpha) { glClearColor(nRed, nGreen, nBlue, nAlpha); }
	void GApiOgl::SetViewport(Int32 nX, Int32 nY, Int32 nW, Int32 nH) { glViewport(nX, nY, nW, nH); }
	void GApiOgl::SetDrawMode(DrawModes unDrawModeId, FacePlanes unFacePlaneId) { m_unDrawModeId = unDrawModeId; glPolygonMode(unFacePlaneId, m_unDrawModeId); }
	void GApiOgl::SetLineWidth(UInt16 unPxW) { glLineWidth(unPxW); }
	void GApiOgl::SetPixelSize(float unPixelSize) { glPointSize(unPixelSize); }
	void GApiOgl::SetBlendFunc(BlendConfigs unSrcFactorId, BlendConfigs unDestFactorId) { glBlendFunc(unSrcFactorId, unDestFactorId); }
	void GApiOgl::SetDepthFunc(DepthConfigs unDepthFuncId) { glDepthFunc(unDepthFuncId); }
	void GApiOgl::SetStencilFunc(StencilConfigs unFuncId, UInt32 unRefValue, UInt8 unBitMask) { glStencilFunc(unFuncId, unRefValue, unBitMask); }
	// --==</setters>==--

	// --==<drawing>==--
	void GApiOgl::DrawIndexed(UInt32 unIndexCount) { glDrawElements(m_unPrimitiveTypeId, unIndexCount, GL_UNSIGNED_INT, nullptr); }
	void GApiOgl::DrawArray(UInt32 unVertexCount) { glDrawArrays(m_unPrimitiveTypeId, 0, unVertexCount); }
	// --==</drawing>==--

}
#endif // GLIB_GAPI