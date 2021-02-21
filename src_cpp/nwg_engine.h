#ifndef NWG_ENGINE_H
#define NWG_ENGINE_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <nwg_tools.h>
namespace NWG
{
	/// GraphicsEngine class
	class NWG_API GfxEngine
	{
	public:
		GfxEngine(HWND pWindow);
		GfxEngine(const GfxEngine& rCpy) = delete;
		virtual ~GfxEngine();
		// --getters
		inline GfxContextInfo& GetInfo()	{ return m_gInfo; }
		inline GfxConfig& GetConfigs()		{ return m_gConfig; }
		inline GfxDrawInfo& GetDrawInfo()	{ return m_dInfo; }
#if (NWG_GAPI & NWG_GAPI_OGL)
		inline HDC GetDevice()				{ return m_pDevice; }
		inline HGLRC GetContext()			{ return m_pContext; }
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
		inline ID3D11Device* GetDevice() { return m_pDevice; }
		inline ID3D11DeviceContext* GetContext() { return m_pContext; }
		inline IDXGISwapChain* GetSwapChain() { return m_pSwap; }
#endif
		// --setters
		void SetVariable(GfxVariables gfxVar, Float32 nValue);
		void SetPrimitive(GfxPrimitives gfxPrimitiveTopology);
		void SetModes(Bit bEnable, ProcessingModes pmMode);
		void SetViewport(Int32 nX, Int32 nY, Int32 nWidth, Int32 nHeight);
		void SetDrawMode(DrawModes dmMode, FacePlanes fpFace);
		void SetBlendFunc(BlendConfigs bcFactorSrc, BlendConfigs bcFactorDest);
		void SetDepthFunc(DepthConfigs dcFunc);
		void SetStencilFunc(StencilConfigs scFunc, UInt32 unRefValue, UInt8 unBitMask);
		// --core_methods
		void Update();
		void BeginDraw();
		void EndDraw();
		void OnDraw(ADrawable& rDrb);
		template<class RType, typename ... Args>
		void CreateRes(RefKeeper<RType>& rRes, Args&& ... Arguments);
		template<class ARType, class RType, typename ... Args>
		void CreateRes(RefKeeper<ARType>& rRes, Args&& ... Arguments);
		static void Create(RefKeeper<GfxEngine>& rEngine, HWND& rWindow);
	private:
		GfxContextInfo m_gInfo;
		GfxDrawInfo m_dInfo;
		GfxConfig m_gConfig;
		HWND m_pWindow;
#if (NWG_GAPI & NWG_GAPI_OGL)
		HDC m_pDevice;
		HGLRC m_pContext;
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
		ID3D11Device* m_pDevice;
		ID3D11DeviceContext* m_pContext;
		IDXGISwapChain* m_pSwap;
		ID3D11RenderTargetView* m_pTarget;
#endif
	};
	template<class RType, typename ... Args>
	void GfxEngine::CreateRes(RefKeeper<RType>& rRes, Args&& ... Arguments) {
		rRes.SetRef<RType>(EntSys::AddEnt<RType>(*this, std::forward<Args>(Arguments)...));
	}
	template<class ARType, class RType, typename ... Args>
	void GfxEngine::CreateRes(RefKeeper<ARType>& rRes, Args&& ... Arguments) {
		rRes.SetRef<ARType>(EntSys::AddEnt<RType>(*this, std::forward<Args>(Arguments)...));
	}
}
#endif	// NWG_GAPI
#endif	// NWG_ENGINE_H