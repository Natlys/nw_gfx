#ifndef GLIB_AGAPI_H
#define GLIB_AGAPI_H

#include <glib_core.hpp>

#if (defined GLIB_GAPI)	// This has to be defined anyway
namespace GLIB
{
	/// GApiInfo struct
	struct GLIB_API GApiInfo
	{
		const char* strRenderer = "none", * strVersion = "none", * strVendor = "none",
			* strShadingLanguage = "none";
		Int32 nMaxVertexAttribs = 0;
		Int32 nActiveTextureId = 0;
		Int32 nMaxTextures = 0;
	public:
		GApiInfo() = default;
		explicit GApiInfo(const char* sRenderer, const char* sVersion,
			const char* sVendor, const char* sShadingLanguage) :
			strRenderer(sRenderer), strVersion(sVersion),
			strVendor(sVendor), strShadingLanguage(sShadingLanguage) { }
		explicit GApiInfo(const UChar* sRenderer, const UChar* sVersion,
			const UChar* sVendor, const UChar* sShadingLanguage) :
			strRenderer((const char*)sRenderer), strVersion((const char*)sVersion),
			strVendor((const char*)sVendor), strShadingLanguage((const char*)sShadingLanguage) { }
	public:
		// --operators
		inline OutStream& operator<<(OutStream& rStream);
	};
	inline OutStream& GApiInfo::operator<<(OutStream& rStream) {
		rStream << "Graphics Context: GLFW_" << strVersion << std::endl <<
			"OpenGL Renderer: " << strRenderer << std::endl <<
			"OpenGL Version: " << strVersion << std::endl <<
			"OpenGL Vendor: " << strVendor << std::endl <<
			"OpenGL Shading Language: " << strShadingLanguage << "\n\n";
		return rStream;
	}
	inline OutStream& operator<<(OutStream& rStream, GApiInfo& rgInfo) { return rgInfo.operator<<(rStream); }
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
		AGApi(GApiTypes gapiType);
		AGApi(AGApi& rCpy) = delete;
		virtual ~AGApi() = default;
		
		// --getters
		inline const GApiTypes GetType() const { return m_gapiType; }
		inline const DrawModes GetDrawMode() const { return DrawModes(m_unDrawModeId); }
		inline const GPrimitiveTypes GetPrimitiveType() const { return GPrimitiveTypes(m_unPrimitiveTypeId); }
		inline const GApiInfo& GetInfo() const { return m_Info; }
		// --setters
		virtual void SetModes(bool bEnable, ProcModes unModeId) = 0;
		virtual void SetViewport(Int32 nX = 0, Int32 nY = 0, Int32 nW = 800, Int32 nH = 600) = 0;
		virtual void SetLineWidth(UInt16 unPxW) = 0;
		virtual void SetPixelSize(float unPixelSize) = 0;
		virtual void SetDrawMode(DrawModes unDrawModeId, FacePlanes unFacePlaneId) = 0;
		virtual void SetPrimitiveType(GPrimitiveTypes unPrimitiveId) = 0;
		virtual void SetDepthFunc(DepthConfigs unFuncId) = 0;
		virtual void SetStencilFunc(StencilConfigs unFuncId, UInt32 unRefValue, UInt8 unBitMask) = 0;
		virtual void SetBlendFunc(BlendConfigs unSrcFactorId, BlendConfigs unDestFactorId) = 0;
		// --core_methods
		virtual bool Init() = 0;
		virtual void OnQuit() = 0;
		virtual void DrawIndexed(UInt32 unIndexCount) = 0;
		virtual void DrawArray(UInt32 unVertexCount) = 0;
		
		static AGApi* Create();
		static void Create(RefOwner<AGApi>& rGApi);
		static void Create(RefKeeper<AGApi>& rGApi);
	protected:
		const GApiTypes m_gapiType;
		UInt32 m_unPrimitiveTypeId;
		UInt32 m_unDrawModeId;
		GApiInfo m_Info;
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
		GApiOgl(GApiOgl& rCpy) = delete;
		~GApiOgl();

		// --setters
		virtual inline void SetPrimitiveType(GPrimitiveTypes unPrimitiveId) override { m_unPrimitiveTypeId = unPrimitiveId; }
		virtual void SetDrawMode(DrawModes unDrawModeId, FacePlanes unFacePlaneId) override;
		virtual void SetModes(bool bEnable, ProcModes unModeId) override;
		virtual void SetViewport(Int32 nX = 0, Int32 nY = 0, Int32 nW = 800, Int32 nH = 600) override;
		virtual void SetLineWidth(UInt16 unPxW) override;
		virtual void SetPixelSize(float unPixelSize) override;
		virtual void SetDepthFunc(DepthConfigs unFuncId) override;
		virtual void SetStencilFunc(StencilConfigs unFuncId, UInt32 unRefValue, UInt8 unBitMask) override;
		virtual void SetBlendFunc(BlendConfigs unSrcFactorId, BlendConfigs unDestFactorId) override;
		// --core_methods
		virtual bool Init() override;
		virtual void OnQuit() override;
		// --drawing
		virtual void DrawIndexed(UInt32 unIndexCount) override;
		virtual void DrawArray(UInt32 unVertexCount) override;

	};
}
#endif	// GLIB_GAPI
#endif // GLIB_AGAPI_H