#ifndef GLIB_ENGINE_H
#define GLIB_ENGINE_H

#include <nwlib/nwl_engine.h>

#include <glib_tools.h>
#include <glib_drawable.h>
#include <glib_material.h>
#include <glib_core.hpp>

namespace GLIB
{
	struct GLIB_API GraphConfig {
		struct {
			struct {
				DrawModes dMode = DM_FILL;
				FacePlanes facePlane = FP_FRONT_AND_BACK;
			} PolyMode;
			Float32 nLineWidth = 0.5f;
			Float32 nPixelSize = 0.5f;
		} General;
		struct {
			Bit bEnable = false;
			BlendConfigs FactorSrc = BC_SRC_ALPHA;
			BlendConfigs FactorDest = BC_ONE_MINUS_SRC_ALPHA;
		} Blending;
		struct {
			Bit bEnable = false;
			DepthConfigs Func = DC_GREATER;
		} DepthTest;
	public:
		inline void Reset() {
			General.PolyMode.dMode = DM_FILL;
			General.PolyMode.facePlane = FP_FRONT_AND_BACK;

			General.nLineWidth = 0.5f;
			General.nPixelSize = 0.5f;

			Blending.bEnable = false;
			Blending.FactorSrc = BC_SRC_ALPHA;
			Blending.FactorDest = BC_ONE_MINUS_SRC_ALPHA;

			DepthTest.bEnable = false;
			DepthTest.Func = DC_GREATER;
		}
	};
	/// GraphicsEngineInfo struct
	struct GLIB_API GraphInfo
	{
	public:
		Char strRenderer[256], strVersion[256], strVendor[256], strShdLang[256];
		Int32 nMaxVertexAttribs = 0;
		Int32 nActiveTextureId = 0;
		Int32 nMaxTextures = 0;
		// --counters
		Size szVtx = 0;
		Size unVtx = 0;
		Size szIdx = 0;
		Size unIdx = 0;
		Size szShd = 0;
		UInt32 unTex = 0;
		// --drawing
		UInt16 unDrawCalls = 0;
	public:
		GraphInfo() : strRenderer("none"), strVersion("none"), strVendor("none"), strShdLang("none") {}
		// --setters
		inline void Reset() {
			szVtx = szIdx = szShd = 0;
			unVtx = unIdx = unTex = 0;
			unDrawCalls = 0;
		}
		// --operators
		inline OStream& operator<<(OStream& rStream);
	};
	inline OStream& GraphInfo::operator<<(OStream& rStream) {
		rStream <<
			"====<graphics_info>====" << std::endl <<
			"graphics context: " << &strVersion[0] << std::endl <<
			"renderer: " << &strRenderer[0] << std::endl <<
			"version: " << &strVersion[0] << std::endl <<
			"vendor: " << &strVendor[0] << std::endl <<
			"shading language: " << &strShdLang[0] << std::endl <<
			"====<graphics_info>====" << std::endl;
		return rStream;
	}
	inline OStream& operator<<(OStream& rStream, GraphInfo& rgInfo) { return rgInfo.operator<<(rStream); }
}
namespace GLIB
{
	/// GraphicsEngine class
	/// -- Depending on the specification during the build
	class GLIB_API GraphEngine : public AEngine<GraphEngine, AEngineState>
	{
	public:
		GraphEngine();
		~GraphEngine();
		
		// --getters
		inline const GraphInfo& GetInfo() const { return m_Info; }
		inline const GraphConfig& GetConfigs() { return m_Config; }
		inline FrameBuf* GetFrameBuf() { return m_pfmBuf; }
		// --setters
		void SetModes(Bit bEnable, ProcessingModes pModes);
		void SetViewport(Int32 nX, Int32 nY, Int32 nWidth, Int32 nHeight);
		void SetDrawMode(DrawModes dMode, FacePlanes facePlane);
		void SetLineWidth(Float32 nLineWidth);
		void SetPixelSize(Float32 nPxSize);
		void SetBlendFunc(BlendConfigs factorSrc, BlendConfigs factorDest);
		void SetDepthFunc(DepthConfigs funcId);
		void SetStencilFunc(StencilConfigs funcId, UInt32 unRefValue, UInt8 unBitMask);
		void SetFrameBuf(FrameBuf* pfmBuf);
		// --core_methods
		virtual void Run() override;
		virtual bool Init() override;
		virtual void Quit() override;
		virtual void Update() override;
		virtual void OnEvent(AEvent& rEvt) override;
		// --drawing_methods
		void OnDraw(VertexArr& rVtxArray, GMaterial& rgMtl);
		void OnDraw(Drawable& rDrb);
	private:
		GraphInfo m_Info;
		GraphConfig m_Config;
		
		FrameBuf* m_pfmBuf;
		Drawable m_drbScreen;
	};
}

#endif // GLIB_ENGINE_H