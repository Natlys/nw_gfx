#ifndef GLIB_API_H
#define GLIB_API_H

#include <glib_decl.hpp>

#if (defined GLIB_GAPI)	// This has to be defined anyway
namespace GLIB
{
	/// Abstract GraphicsApplicationProgrammingInterface class
	/// Interface:
	/// -> Create -> use functions as a wrappers of the partucular GAPI:
	/// -> ClearBuffers(): clear the frame buffers
	/// -> SetViewport(int [XYWH]):
	/// Description:
	/// -- This is the tool of the engine renderer
	/// -- Renderer owns an instance of the derrived from this class
	/// -- Renderer is static and he owns any API with which he can draw
	class GLIB_API AGApi
	{
	public:
		virtual ~AGApi() = default;
		
		// --getters
		virtual inline const GApiTypes GetType() const = 0;
		virtual inline const DrawModes GetDrawMode() const = 0;
		virtual inline const GPrimitiveTypes GetPrimitiveType() const = 0;
		// --setters
		virtual void SetModes(bool bEnable, ProcModes unModeId) = 0;
		virtual void SetClearColor(float nRed, float nGreen, float nBlue, float nAlpha = 1.0f) = 0;
		virtual void SetViewport(Int32 nX = 0, Int32 nY = 0, Int32 nW = 800, Int32 nH = 600) = 0;
		virtual void SetLineWidth(UInt16 unPxW) = 0;
		virtual void SetPixelSize(float unPixelSize) = 0;
		virtual void SetDrawMode(DrawModes unDrawModeId, FacePlanes unFacePlaneId) = 0;
		virtual void SetPrimitiveType(GPrimitiveTypes unPrimitiveId) = 0;
		virtual void SetDepthFunc(DepthConfigs unFuncId) = 0;
		virtual void SetStencilFunc(StencilConfigs unFuncId, UInt32 unRefValue, UInt8 unBitMask) = 0;
		virtual void SetBlendFunc(BlendConfigs unSrcFactorId, BlendConfigs unDestFactorId) = 0;
		// --drawing
		virtual void DrawIndexed(UInt32 unIndexCount) = 0;
		virtual void DrawArray(UInt32 unVertexCount) = 0;

		static AGApi* Create(GApiTypes gapiType);
	};
}
#endif	// GLIB_GAPI

#if (GLIB_GAPI & GLIB_GAPI_OGL)
namespace GLIB
{
	/// OpenGL GraphicsApi class : public GraphicsApi_OGL
	/// --Wraps opengl functions
	/// --Draws everything you give him
	/// --Gets data and draws it
	/// --Can draw throught abstraction classes and VBO/VAO/EBO
	class GLIB_API GApiOgl : public AGApi
	{
	public:
		GApiOgl();
		~GApiOgl();

		// --getters
		virtual inline const GApiTypes GetType() const override { return m_gapiType; }
		virtual inline const DrawModes GetDrawMode() const override { return DrawModes(m_unDrawModeId); }
		virtual inline const GPrimitiveTypes GetPrimitiveType() const override { return GPrimitiveTypes(m_unPrimitiveTypeId); }
		// --setters
		virtual inline void SetPrimitiveType(GPrimitiveTypes unPrimitiveId) override { m_unPrimitiveTypeId = unPrimitiveId; }
		virtual void SetDrawMode(DrawModes unDrawModeId, FacePlanes unFacePlaneId) override;
		virtual void SetModes(bool bEnable, ProcModes unModeId) override;
		virtual void SetClearColor(float nRed, float nGreen, float nBlue, float nAlpha = 1.0f) override;
		virtual void SetViewport(Int32 nX = 0, Int32 nY = 0, Int32 nW = 800, Int32 nH = 600) override;
		virtual void SetLineWidth(UInt16 unPxW) override;
		virtual void SetPixelSize(float unPixelSize) override;
		virtual void SetDepthFunc(DepthConfigs unFuncId) override;
		virtual void SetStencilFunc(StencilConfigs unFuncId, UInt32 unRefValue, UInt8 unBitMask) override;
		virtual void SetBlendFunc(BlendConfigs unSrcFactorId, BlendConfigs unDestFactorId) override;
		// --drawing
		virtual void DrawIndexed(UInt32 unIndexCount) override;
		virtual void DrawArray(UInt32 unVertexCount) override;
	private:
		const GApiTypes m_gapiType;
		UInt32 m_unPrimitiveTypeId;
		UInt32 m_unDrawModeId;
	};

}
#endif	// GLIB_API
#endif // GLIB_API_H