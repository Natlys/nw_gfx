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
		inline const GfxInfo& GetInfo() const { return m_gInfo; }
		inline const GfxConfig& GetConfigs() { return m_gConfig; }
#if (NWG_GAPI & NWG_GAPI_OGL)
		inline HDC GetDevice()				{ return m_pDevice; }
		inline HGLRC GetContext()			{ return m_pContext; }
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
		inline ID3D11Device* GetDevice() { return m_pDevice; }
		inline ID3D11DeviceContext* GetContext() { return m_pContext; }
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
		void CreateVtxBuf(RefKeeper<VertexBuf>& rBuf);
		void CreateIdxBuf(RefKeeper<IndexBuf>& rBuf);
		void CreateShdBuf(RefKeeper<ShaderBuf>& rBuf);
		void CreateTexture(RefKeeper<Texture>& rTexture, const char* strName, TextureTypes texType);
		void CreateFrameBuf(RefKeeper<FrameBuf>& rFrameBuf, const char* strName, FrameBufInfo& rInfo);
		void CreateShader(RefKeeper<Shader>& rShader, const char* strName);
		static void Create(RefKeeper<GfxEngine>& rEngine, HWND& rWindow);
	private:
		GfxInfo m_gInfo;
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

		ID3D11Buffer* m_pVtxBuf;
		ID3D11InputLayout* m_pVtxLayout;
		ID3D11VertexShader* m_pVtxShd;
		ID3D11PixelShader* m_pPxlShd;
#endif
	};
}
#endif	// NWG_GAPI
#endif	// NWG_ENGINE_H