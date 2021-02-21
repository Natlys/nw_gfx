#include <nwg_pch.hpp>
#include "nwg_engine.h"
#if (defined NWG_GAPI)
#include <nwg_tools.h>
#include <nwg_frame_buf.h>
#include <nwg_drawable.h>
#include <nwg_loader.h>
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	GfxEngine::GfxEngine(HWND pWindow) :
		m_gInfo(GfxInfo()), m_gConfig(GfxConfig()),
		m_pWindow(pWindow),
		m_pDevice(nullptr), m_pContext(nullptr)
	{
		if (m_pWindow == nullptr) { NWL_ERR("Window is not correct"); return; }
		// Get device context of the window
		// Get default device context. Only one DC can be used in a single thread at one time.
		m_pDevice = GetWindowDC(m_pWindow);

		// Set deivec pixel format and only then  make render context.
		PIXELFORMATDESCRIPTOR pxfDesc{ 0 };
		pxfDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
		pxfDesc.nVersion = 1;
		pxfDesc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL;
		pxfDesc.iPixelType = PFD_TYPE_RGBA;
		pxfDesc.iLayerType = PFD_MAIN_PLANE;
		pxfDesc.cColorBits = 24;
		pxfDesc.cRedBits = 0; pxfDesc.cGreenBits = 0; pxfDesc.cBlueBits = 0; pxfDesc.cAlphaBits = 0;
		pxfDesc.cRedShift = 0; pxfDesc.cGreenShift = 0; pxfDesc.cBlueShift = 0; pxfDesc.cAlphaShift = 0;
		pxfDesc.cAccumBits = 0;
		pxfDesc.cAccumRedBits = 0; pxfDesc.cAccumGreenBits = 0; pxfDesc.cAccumBlueBits = 0; pxfDesc.cAccumAlphaBits = 0;
		pxfDesc.cAuxBuffers = 0;
		pxfDesc.cDepthBits = 24;
		pxfDesc.cStencilBits = 8;
		pxfDesc.bReserved = 0;
		pxfDesc.dwVisibleMask = 0; pxfDesc.dwLayerMask = 0; pxfDesc.dwDamageMask = 0;
		// Get the best availabple pixel format for device context
		Int32 nPxFormat = ChoosePixelFormat(m_pDevice, &pxfDesc);
		if (nPxFormat == 0) { NWL_ERR("Failed to get a pixel format"); return; }
		// Pixel format can be set to some window only once
		if (!SetPixelFormat(m_pDevice, nPxFormat, &pxfDesc)) { NWL_ERR("Failed to set a pixel format"); return; }
		DescribePixelFormat(m_pDevice, nPxFormat, pxfDesc.nSize, &pxfDesc);
		// Create opengl context and associate that with the device context
		// It will be attached to the current frame and DC so,
		// this is only one current context we can use
		m_pContext = wglCreateContext(m_pDevice);
		wglMakeCurrent(m_pDevice, m_pContext);

		if (!gladLoadGL()) { NWL_ERR("Failed to load graphics library!"); return; }
		strcpy(&m_gInfo.strRenderer[0], &((const char*)glGetString(GL_RENDERER))[0]);
		strcpy(&m_gInfo.strVersion[0], &((const char*)glGetString(GL_VERSION))[0]);
		strcpy(&m_gInfo.strVendor[0], &((const char*)glGetString(GL_VENDOR))[0]);
		strcpy(&m_gInfo.strShdLang[0], &((const char*)glGetString(GL_SHADING_LANGUAGE_VERSION))[0]);
		std::cout << m_gInfo;
	}
	GfxEngine::~GfxEngine()
	{
		// Break the connection between our thread and the rendering context
		wglMakeCurrent(NULL, NULL);
		// Release the associated DC and delete the rendering context
		ReleaseDC(m_pWindow, m_pDevice);
		// Before delete - we need to release that
		// DeleteDC(m_Context);	// delete only created device context
		// Before this call device context must be released or deleted
		wglDeleteContext(m_pContext);
	}
	// --==<setters>==--
	void GfxEngine::SetPrimitive(GfxPrimitives gfxPrimitiveTopology) {
	}
	void GfxEngine::SetModes(Bit bEnable, ProcessingModes pmModes) {

		switch (pmModes) {
		case PM_BLEND:
			m_gConfig.Blending.bEnable = bEnable;
			break;
		case PM_DEPTH_TEST:
			m_gConfig.DepthTest.bEnable = bEnable;
			break;
		case PM_CULL_FACE:
			m_gConfig.Culling.bEnable = bEnable;
			break;
		default: break;
		}
		if (bEnable) {
			glEnable(pmModes);
		}
		else {
			glDisable(pmModes);
		}
	}
	void GfxEngine::SetViewport(Int32 nX, Int32 nY, Int32 nW, Int32 nH) {
		glViewport(nX, nY, nW, nH);
	}
	void GfxEngine::SetDrawMode(DrawModes dMode, FacePlanes facePlane) {
		m_gConfig.General.PolyMode.dMode = dMode;
		m_gConfig.General.PolyMode.facePlane = facePlane;
		glPolygonMode(facePlane, dMode);
	}
	void GfxEngine::SetVariable(GfxVariables gfxVar, Float32 nValue) {
		switch (gfxVar) {
		case GV_LINE_WIDTH:
			m_gConfig.General.nLineWidth = nValue;
			glLineWidth(nValue);
			break;
		case GV_POINT_SIZE:
		m_gConfig.General.nPixelSize = nValue;
			glPointSize(nValue);
			break;
		default:	break;
		}
	}
	void GfxEngine::SetBlendFunc(BlendConfigs bcSrcFactor, BlendConfigs bcDestFactor) {
		m_gConfig.Blending.FactorSrc = bcSrcFactor;
		m_gConfig.Blending.FactorDest = bcDestFactor;
		glBlendFunc(bcSrcFactor, bcDestFactor);
	}
	void GfxEngine::SetDepthFunc(DepthConfigs dcFunc) {
		m_gConfig.DepthTest.Func = dcFunc;
		glDepthFunc(dcFunc);
	}
	void GfxEngine::SetStencilFunc(StencilConfigs scFunc, UInt32 unRefValue, UInt8 unBitMask) {
		m_gConfig.StencilTest.Func = scFunc;
		m_gConfig.StencilTest.nBitMask = unBitMask;
		m_gConfig.StencilTest.nRefValue = unRefValue;
		glStencilFunc(scFunc, unRefValue, unBitMask);
	}
	// --==</setters>==--

	// --==<core_methods>==--
	void GfxEngine::Update()
	{
		SwapBuffers(m_pDevice);
		glClearColor(0.0f, sinf(TimeSys::GetCurrS()), cosf(TimeSys::GetCurrS()), 1.0f);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void GfxEngine::BeginDraw()
	{
		m_gTools.Reset();
	}
	void GfxEngine::EndDraw()
	{
		if (m_gTools.unIdx > 0) {
			glDrawElements(m_gTools.gPrimitive, m_gTools.unIdx, m_gTools.sdIdx, nullptr);
		}
		else if (m_gTools.unVtx > 0) {
			glDrawVertices(m_gTools.gPrimitive, m_gTools.unVtxCount);
		}
	}
	void GfxEngine::Create(RefKeeper<GfxEngine>& rEngine, HWND& rWindow)
	{
		if (rWindow == nullptr) { NWL_ERR("Window is not initialized!"); return; }
		rEngine.MakeRef<GfxEngine>(rWindow);
	}
	// --==</core_methods>==--
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
	GfxEngine::GfxEngine(HWND pWindow) :
		m_pWindow(pWindow),
		m_pDevice(nullptr), m_pContext(nullptr), m_pSwap(nullptr), m_pTarget(nullptr)
	{
		if (m_pWindow == nullptr) { NWL_ERR("The window handler is not correct"); return; }
		DXGI_SWAP_CHAIN_DESC swapDesc{ 0 };
		swapDesc.BufferDesc.Width = 0;
		swapDesc.BufferDesc.Height = 0;
		//swapDesc.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
		swapDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapDesc.BufferDesc.RefreshRate.Numerator = 0;
		swapDesc.BufferDesc.RefreshRate.Denominator = 0;
		swapDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		swapDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		swapDesc.SampleDesc.Count = 1;
		swapDesc.SampleDesc.Quality = 0;
		swapDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapDesc.BufferCount = 1;
		swapDesc.OutputWindow = m_pWindow;
		//swapDesc.Windowed = TRUE;
		swapDesc.Windowed = FALSE;
		swapDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		swapDesc.Flags = 0;
		D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, D3D11_CREATE_DEVICE_DEBUG,
			nullptr, NULL, D3D11_SDK_VERSION, &swapDesc, &m_pSwap, &m_pDevice, nullptr, &m_pContext);
		if (m_pDevice == nullptr || m_pContext == nullptr || m_pSwap == nullptr) { throw WinException("graphics engine is not initialized"); }

		ID3D11Resource* pBackBuf = nullptr;
		m_pSwap->GetBuffer(NULL, __uuidof(ID3D11Resource), reinterpret_cast<Ptr*>(&pBackBuf));
		m_pDevice->CreateRenderTargetView(pBackBuf, nullptr, &m_pTarget);
		m_pContext->OMSetRenderTargets(1u, &m_pTarget, nullptr);
		SetViewport(0, 0, 800, 600);
		SetPrimitive(GPT_TRIANGLES);
	}
	GfxEngine::~GfxEngine()
	{
		if (m_pTarget != nullptr) { m_pTarget->Release(); }
		if (m_pDevice != nullptr) { m_pDevice->Release(); }
		if (m_pContext != nullptr) { m_pContext->Release(); }
		if (m_pSwap != nullptr) { m_pSwap->Release(); }
	}
	// --==<setters>==--
	void GfxEngine::SetPrimitive(GfxPrimitives gPrimitive) { m_pContext->IASetPrimitiveTopology(ConvertEnum<GfxPrimitives, D3D11_PRIMITIVE_TOPOLOGY>(gPrimitive)); }
	void GfxEngine::SetModes(Bit bEnable, ProcessingModes pmModes) {

		switch (pmModes) {
		case PM_BLEND:
			m_gConfig.Blending.bEnable = bEnable;
			break;
		case PM_DEPTH_TEST:
			m_gConfig.DepthTest.bEnable = bEnable;
			break;
		case PM_CULL_FACE:
			m_gConfig.Culling.bEnable = bEnable;
			break;
		default: break;
		}
		if (bEnable) {
		}
		else {
		}
	}
	void GfxEngine::SetViewport(Int32 nX, Int32 nY, Int32 nW, Int32 nH) {
		D3D11_VIEWPORT vp{ 0 };
		vp.TopLeftX = static_cast<Float32>(nX);
		vp.TopLeftY = static_cast<Float32>(nY);
		vp.Width = static_cast<Float32>(nW);
		vp.Height = static_cast<Float32>(nH);
		vp.MaxDepth = 1.0f;
		vp.MinDepth = 0.0f;
		m_pContext->RSSetViewports(1, &vp);
	}
	void GfxEngine::SetDrawMode(DrawModes dMode, FacePlanes facePlane) {
		m_gConfig.General.PolyMode.dMode = dMode;
		m_gConfig.General.PolyMode.facePlane = facePlane;
	}
	void GfxEngine::SetVariable(GfxVariables gfxVar, Float32 nValue) {
		switch(gfxVar) {
		case GV_LINE_WIDTH: m_gConfig.General.nLineWidth = nValue; break;
		case GV_POINT_SIZE: m_gConfig.General.nPixelSize = nValue; break;
		default: break;
		}
	}
	void GfxEngine::SetBlendFunc(BlendConfigs bcSrcFactor, BlendConfigs bcDestFactor) {
		m_gConfig.Blending.FactorSrc = bcSrcFactor;
		m_gConfig.Blending.FactorDest = bcDestFactor;
	}
	void GfxEngine::SetDepthFunc(DepthConfigs dcFunc) {
		m_gConfig.DepthTest.Func = dcFunc;
	}
	void GfxEngine::SetStencilFunc(StencilConfigs scFunc, UInt32 unRefValue, UInt8 unBitMask) {
		m_gConfig.StencilTest.Func = scFunc;
		m_gConfig.StencilTest.nBitMask = unBitMask;
		m_gConfig.StencilTest.nRefValue = unRefValue;
	}
	// --==</setters>==--
	// --==<core_methods>==--
	void GfxEngine::Update()
	{
		HRESULT hresInfo;
		const Float32 rgbaClear[] = { 0.0f, sinf(TimeSys::GetCurrS()), cosf(TimeSys::GetCurrS()), 1.0f };
		
		hresInfo = m_pSwap->Present(m_gConfig.General.unSwapInterval, 0u);
		if (hresInfo == DXGI_ERROR_DEVICE_REMOVED) { throw Exception("device has been removed", hresInfo, __FILE__, __LINE__); }
		m_pContext->ClearRenderTargetView(m_pTarget, rgbaClear);
	}
	void GfxEngine::BeginDraw()
	{
		m_dInfo.Reset();
	}
	void GfxEngine::EndDraw()
	{
		if (m_dInfo.unIdx > 0) { m_pContext->DrawIndexed(m_dInfo.unIdx, 0u, 0u); }
		else if (m_dInfo.unVtx > 0) { m_pContext->Draw(m_dInfo.unVtx, 0u); }
	}
	void GfxEngine::OnDraw(ADrawable& rDrb)
	{
		rDrb.Bind();
		for (auto& itBuf : rDrb.GetVtxBufs()) { }
	}
	void GfxEngine::Create(RefKeeper<GfxEngine>& rEngine, HWND& rWindow)
	{
		if (rWindow == nullptr) { throw Exception("Window is not initialized!"); return; }
		rEngine.MakeRef<GfxEngine>(rWindow);
	}
	// --==</core_methods>==--
}
#endif
#endif	// NWG_GAPI