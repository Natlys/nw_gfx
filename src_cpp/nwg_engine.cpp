#include <nwg_pch.hpp>
#include "nwg_engine.h"
#if (defined NWG_GAPI)
#include <nwg_tools.h>
#include <nwg_framebuf.h>
#include <nwg_drawable.h>
#include <nwg_camera.h>
#include <nwg_shader.h>
#include <nwg_material.h>
#include <nwg_texture.h>
#include <nwg_loader.h>
#if (NWG_GAPI & NWG_GAPI_OGL)
#include <../src_glsl/shd_screen.glsl>
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
		//
	}
	void GfxEngine::EndDraw()
	{
		//
	}
	void GfxEngine::CreateVtxBuf(RefKeeper<VertexBuf>& rBuf)
	{
		rBuf.MakeRef<VertexBuf>();
	}
	void GfxEngine::CreateIdxBuf(RefKeeper<IndexBuf>& rBuf)
	{
		rBuf.MakeRef<IndexBuf>();
	}
	void GfxEngine::CreateShdBuf(RefKeeper<ShaderBuf>& rBuf)
	{
		rBuf.MakeRef<ShaderBuf>();
	}
	void GfxEngine::CreateTexture(RefKeeper<Texture>& rTexture, const char* strName, TextureTypes texType)
	{
		rTexture.MakeRef<Texture>(strName, texType);
	}
	void GfxEngine::CreateFrameBuf(RefKeeper<FrameBuf>& rFrameBuf, const char* strName, FrameBufInfo& rInfo)
	{
		rFrameBuf.MakeRef<FrameBuf>(strName, rInfo);
	}
	void GfxEngine::CreateShader(RefKeeper<Shader>& rShader, const char* strName)
	{
		rShader.MakeRef<Shader>(strName);
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
		m_pDevice(nullptr), m_pContext(nullptr), m_pSwap(nullptr), m_pTarget(nullptr),
		m_pVtxBuf(nullptr), m_pVtxShd(nullptr)
	{
		if (m_pWindow == nullptr) { NWL_ERR("The window handler is not correct"); return; }
		{	// describe a swapchain
			DXGI_SWAP_CHAIN_DESC swapDesc{ 0 };
			swapDesc.BufferDesc.Width = 0;
			swapDesc.BufferDesc.Height = 0;
			swapDesc.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
			swapDesc.BufferDesc.RefreshRate.Numerator = 0;
			swapDesc.BufferDesc.RefreshRate.Denominator = 0;
			swapDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
			swapDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
			swapDesc.SampleDesc.Count = 1;
			swapDesc.SampleDesc.Quality = 0;
			swapDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
			swapDesc.BufferCount = 1;
			swapDesc.OutputWindow = m_pWindow;
			swapDesc.Windowed = TRUE;
			swapDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
			swapDesc.Flags = 0;

			D3D11CreateDeviceAndSwapChain(
				nullptr,					// default adapter
				D3D_DRIVER_TYPE_HARDWARE,	// hardware device
				nullptr,					// the hmodule binary we want to load
				D3D11_CREATE_DEVICE_DEBUG,	// flags; one of them is for debug layer
				nullptr,					// any feature levels
				NULL,						// any levels...
				D3D11_SDK_VERSION,			// soft development kit version of the system
				&swapDesc,					// descriptor for the swap chain
				&m_pSwap,					// swap chain pointer to pointer
				&m_pDevice,					// device pointer to pointer
				nullptr,					// output feature level pointer
				&m_pContext					// prt to prt for the context
			);
		}
		{	// get a swapchain texture buffer and create render target view from it
			ID3D11Resource* pBackBuf = nullptr;
			m_pSwap->GetBuffer(
				NULL,
				__uuidof(ID3D11Resource),
				reinterpret_cast<Ptr*>(&pBackBuf)
			);
			// create a texture where we do render
			m_pDevice->CreateRenderTargetView(
				pBackBuf,			// where is source
				nullptr,			// how is it described
				&m_pTarget
			);
		}
		{
			const V2f vtxDataTrig[] = {
				{ -1.0f, -1.0f },
				{ 0.0f, 1.0f },
				{ 1.0f, 0.0f }
			};
			const UInt32 szStride = sizeof(V2f);
			const UInt32 szOffset = 0u;

			// specify this abstract buffer
			D3D11_BUFFER_DESC vbDesc = { 0 };
			vbDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;	// how to bind this
			vbDesc.Usage = D3D11_USAGE_DEFAULT;				// same as OpenGL STATIC/DYNAMIC/STREAM draw
			vbDesc.ByteWidth = sizeof(vtxDataTrig);			// size of the buffer
			vbDesc.MiscFlags = NULL;						// unknown stuff
			vbDesc.StructureByteStride = szStride;			// every next vertex throught sizeof(V2f)

			D3D11_SUBRESOURCE_DATA subData = { 0 };
			subData.pSysMem = &vtxDataTrig[0];		// address in the cpu
			subData.SysMemPitch;					// unknown black box
			subData.SysMemSlicePitch;				// unknown

			m_pDevice->CreateBuffer(
				&vbDesc,		// how to set up the buffer
				&subData,		// cpy data to load into the gpu buffer
				&m_pVtxBuf		// the buffer location
			);
			// bind buffers to the pipeline
			m_pContext->IASetVertexBuffers(
				0,				// start: start from the first one
				1,				// count: set only one
				&m_pVtxBuf,		// buffers: use the address of our buffer
				&szStride,		// strides: the offsets between verices of every buffer
				&szOffset		// offset: the offsets from the beginning of every buffer
			);
		}
		{	// create shaders
			// load some compiled code of the vertex shader
			ID3DBlob* pBlob = nullptr;
			D3DReadFileToBlob(L"bin/shd_0_vtx.cso", &pBlob);
			// create shader object with the source code
			m_pDevice->CreateVertexShader(
				pBlob->GetBufferPointer(),	// void* ptr to a bunch of bytes
				pBlob->GetBufferSize(),		// the size of compiled blob
				nullptr,					// no class linkage
				&m_pVtxShd					// where to create
			);
			// bind the shader to pipeline: shader ptr itself, class instances, num of instances
			m_pContext->VSSetShader(m_pVtxShd, nullptr, NULL);
			{	// input vertex layout
				D3D11_INPUT_ELEMENT_DESC elemDesc{ 0 };
				elemDesc.SemanticName = "coord";						// default vertex semantic
				elemDesc.SemanticIndex = 0;								// there can be Position1/2/3
				elemDesc.Format = DXGI_FORMAT_R32G32_FLOAT;				// how the data is represented: 2 floats in 32 bit each
				elemDesc.InputSlot = 0;									// bind to the first
				elemDesc.AlignedByteOffset = 0;							// offset from the beginning of this structure
				elemDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;	// can be set for instanced rendering
				elemDesc.InstanceDataStepRate = 0;						// doesn't matter
				// array pointer->size->bytecode_of_shader->byte_code_length->where_is_layout
				m_pDevice->CreateInputLayout(&elemDesc, 1, pBlob->GetBufferPointer(), pBlob->GetBufferSize(), &m_pVtxLayout);
				m_pContext->IASetInputLayout(m_pVtxLayout);
			}
			pBlob->Release();
		}
		{	// same applies for the pixel shader
			ID3DBlob* pBlob = nullptr;
			D3DReadFileToBlob(L"bin/shd_0_pxl.cso", &pBlob);
			m_pDevice->CreatePixelShader(
				pBlob->GetBufferPointer(),
				pBlob->GetBufferSize(),
				nullptr,
				&m_pPxlShd
			);
			pBlob->Release();
			m_pContext->PSSetShader(m_pPxlShd, nullptr, NULL);
		}
		{	// bind our target view to the render target; setup viewport
			m_pContext->OMSetRenderTargets(1u, &m_pTarget, nullptr);
			// set the rasterizer's viewports
			SetViewport(0, 0, 800, 600);
			// set the primitive typology
			SetPrimitive(GPT_TRIANGLES);
		}
	}
	GfxEngine::~GfxEngine()
	{
		if (m_pVtxBuf != nullptr) {
			m_pVtxBuf->Release();
		}
		if (m_pVtxLayout != nullptr) {
			m_pVtxLayout->Release();
		}
		if (m_pVtxShd != nullptr) {
			m_pVtxShd->Release();
		}
		if (m_pPxlShd != nullptr) {
			m_pPxlShd->Release();
		}
		if (m_pTarget != nullptr) {
			m_pTarget->Release();
		}
		if (m_pDevice != nullptr) {
			m_pDevice->Release();
		}
		if (m_pContext != nullptr) {
			m_pContext->Release();
		}
		if (m_pSwap != nullptr) {
			m_pSwap->Release();
		}
	}
	// --==<setters>==--
	void GfxEngine::SetPrimitive(GfxPrimitives gfxPrimitiveTopology) {
		m_pContext->IASetPrimitiveTopology(static_cast<D3D11_PRIMITIVE_TOPOLOGY>(gfxPrimitiveTopology));
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
	void GfxEngine::SetLineWidth(Float32 nLineWidth) {
		m_gConfig.General.nLineWidth = nLineWidth;
	}
	void GfxEngine::SetPixelSize(Float32 nPxSize) {
		m_gConfig.General.nPixelSize = nPxSize;
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
		if (hresInfo == DXGI_ERROR_DEVICE_REMOVED) { throw CodeException("device has been removed", hresInfo, __FILE__, __LINE__); }
		m_pContext->ClearRenderTargetView(m_pTarget, rgbaClear);
		
		m_pContext->Draw(3u, 0u);
	}
	void GfxEngine::CreateVtxBuf(RefKeeper<VertexBuf>& rBuf)
	{
		//
	}
	void GfxEngine::CreateIdxBuf(RefKeeper<IndexBuf>& rBuf)
	{
		//
	}
	void GfxEngine::CreateShdBuf(RefKeeper<ShaderBuf>& rBuf)
	{
		//
	}
	void GfxEngine::CreateTexture(RefKeeper<Texture>& rTex, const char* strName, TextureTypes texType)
	{
		//
	}
	void GfxEngine::CreateFrameBuf(RefKeeper<FrameBuf>& rFrameBuf, const char* strName, FrameBufInfo& rInfo)
	{
		//
	}
	void GfxEngine::CreateShader(RefKeeper<Shader>& rShader, const char* strName)
	{
		//
	}
	// --==</core_methods>==--
}
#endif
#endif	// NWG_GAPI