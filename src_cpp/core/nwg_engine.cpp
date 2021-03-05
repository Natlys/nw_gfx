#include <nwg_pch.hpp>
#include "nwg_engine.h"
#if (defined NWG_GAPI)
#include <core/nwg_cmp.h>
#include <core/nwg_drawable.h>
#if (NWG_GAPI & NWG_GAPI_OGL)
#include <lib/nwg_ogl_loader.h>
#include <lib/nwg_ogl_v1.h>
#include <lib/nwg_ogl_v2.h>
#include <lib/nwg_ogl_v3.h>
#include <lib/nwg_ogl_v4.h>
#include <lib/nwg_ogl_arb.h>
namespace NWG
{
	gfx_engine::gfx_engine(gfx_window& wnd) :
		m_info(gfx_context_info()), m_config(gfx_config()),
		m_wnd(wnd),
		m_device(nullptr), m_context(nullptr)
	{
		if (m_wnd == nullptr) { throw error("not correct window handle"); return; }
		OglOpen();
		// get device context of the window;
		// get default device context;
		// only one devic context can be used in a single thread at one time;
		m_device = ::GetWindowDC(m_wnd);
		// setup device pixel format and only then make render context;
		PIXELFORMATDESCRIPTOR pxf_desc{ 0 };
		pxf_desc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
		pxf_desc.nVersion = 1;
		pxf_desc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL;
		pxf_desc.iPixelType = PFD_TYPE_RGBA;
		pxf_desc.iLayerType = PFD_MAIN_PLANE;
		pxf_desc.cColorBits = 24;
		pxf_desc.cRedBits = 0; pxf_desc.cGreenBits = 0; pxf_desc.cBlueBits = 0; pxf_desc.cAlphaBits = 0;
		pxf_desc.cRedShift = 0; pxf_desc.cGreenShift = 0; pxf_desc.cBlueShift = 0; pxf_desc.cAlphaShift = 0;
		pxf_desc.cAccumBits = 0;
		pxf_desc.cAccumRedBits = 0; pxf_desc.cAccumGreenBits = 0; pxf_desc.cAccumBlueBits = 0; pxf_desc.cAccumAlphaBits = 0;
		pxf_desc.cAuxBuffers = 0;
		pxf_desc.cDepthBits = 24;
		pxf_desc.cStencilBits = 8;
		pxf_desc.bReserved = 0;
		pxf_desc.dwVisibleMask = 0; pxf_desc.dwLayerMask = 0; pxf_desc.dwDamageMask = 0;
		// get the best availabple pixel format for device context;
		si32 pxl_format = ::ChoosePixelFormat(m_device, &pxf_desc);
		if (pxl_format == 0) { NWL_ERR("Failed to get a pixel format"); return; }
		// Pixel format can be set to some window only once
		if (!::SetPixelFormat(m_device, pxl_format, &pxf_desc)) { NWL_ERR("Failed to set a pixel format"); return; }
		::DescribePixelFormat(m_device, pxl_format, pxf_desc.nSize, &pxf_desc);
		// create opengl context and associate that with the device context;
		// it will be attached to the current thread and dc;
		// this is only one current context we can use;
		m_context = OglNewContext(m_device);
		OglMakeContextCurr(m_device, m_context);
		OglClose();

		if (!OglInit()) { throw error("failed to load graphics library!"); return; }
		strcpy(&m_info.renderer[0], &((cstring)glGetString(GL_RENDERER))[0]);
		strcpy(&m_info.version[0], &((cstring)glGetString(GL_VERSION))[0]);
		strcpy(&m_info.vendor[0], &((cstring)glGetString(GL_VENDOR))[0]);
		strcpy(&m_info.shader_language[0], &((cstring)glGetString(GL_SHADING_LANGUAGE_VERSION))[0]);
		std::cout << m_info;

		set_primitive(GPT_TRIANGLES);
		set_viewport(0, 0, 800, 600);
	}
	gfx_engine::~gfx_engine()
	{
		// break the connection between our thread and the rendering context;
		OglMakeContextCurr(NULL, NULL);
		// release the associated dc and delete the rendering context;
		ReleaseDC(m_wnd, m_device);
		// before delete - we need to release that;
		// DeleteDC(m_context);	// delete only created device context;
		// before this call device context must be released or deleted;
		OglDelContext(m_context);
	}
	// --setters
	void gfx_engine::set_primitive(gfx_primitives primitive_topology) {
		m_config.prim_type = primitive_topology;
	}
	void gfx_engine::set_viewport(si32 x0, si32 y0, si32 x1, si32 y1) {
		m_config.viewport = { x0, y0, x1, y1 };
		glViewport(x0, y0, x1, y1);
	}
	void gfx_engine::set_vsync(bit enable) {
		m_config.swap_interval = (enable == true) ? 1u : 0u;
	}
	// --==<core_methods>==--
	void gfx_engine::update()
	{
		SwapBuffers(m_device);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glClearColor(
			m_config.clear_color[0], m_config.clear_color[1],
			m_config.clear_color[2], m_config.clear_color[3]);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void gfx_engine::begin_draw()
	{
	}
	void gfx_engine::end_draw()
	{
	}
	void gfx_engine::on_draw_vtx(ui32 ent_id)
	{
		auto& cmps = get_cmps(ent_id);
		size data_size = 0;
		ui32 data_count = 0;
		for (auto& icmp : cmps) {
			if (icmp.second->check_type_id<a_gfx_buf>()) {
				vtx_buf* buf = icmp.second.get_ref<vtx_buf>();
				data_size += buf->get_data_size();
				data_count += buf->get_data_count();
			}
			icmp.second->on_draw();
		}
		glDrawArrays(convert_enum<gfx_primitives, GLenum>(m_config.prim_type), data_count, data_size);
	}
	void gfx_engine::on_draw_idx(ui32 ent_id)
	{
		auto& cmps = get_cmps(ent_id);
		GLuint count = 0;
		GLenum type = DT_DEFAULT;
		for (auto& icmp : cmps) {
			if (icmp.second->check_type_id<a_gfx_buf>()) {
				idx_buf* buf = icmp.second.get_ref<idx_buf>();
				count += buf->get_data_count();
				type = convert_enum<data_types, GLenum>(buf->get_data_type());
			}
			icmp.second->on_draw();
		}
		glDrawElements(convert_enum<gfx_primitives, GLenum>(m_config.prim_type), count, type, nullptr);
	}

	void gfx_engine::rmv_cmp(ui32 ent_id, ui32 type_id)
	{
		m_reg[ent_id].erase(type_id);
	}
	// --==</core_methods>==--
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
#include <lib/nwg_dx_loader.h>
namespace NWG
{
	gfx_engine::gfx_engine(HWND pWindow) :
		m_pWindow(pWindow),
		m_device(nullptr), m_context(nullptr), m_pSwap(nullptr), m_pTarget(nullptr)
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
		swapDesc.Windowed = TRUE;
		//swapDesc.Windowed = FALSE;
		swapDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		swapDesc.Flags = 0;
		D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, D3D11_CREATE_DEVICE_DEBUG,
			nullptr, NULL, D3D11_SDK_VERSION, &swapDesc, &m_pSwap, &m_device, nullptr, &m_context);
		if (m_device == nullptr || m_context == nullptr || m_pSwap == nullptr) { throw error("graphics engine is not initialized"); }

		ID3D11Resource* pBackBuf = nullptr;
		m_pSwap->GetBuffer(NULL, __uuidof(ID3D11Resource), reinterpret_cast<Ptr*>(&pBackBuf));
		m_device->CreateRenderTargetView(pBackBuf, nullptr, &m_pTarget);
		m_context->OMSetRenderTargets(1u, &m_pTarget, nullptr);
		SetViewport(0, 0, 800, 600);
		SetPrimitive(GPT_TRIANGLES);
	}
	gfx_engine::~gfx_engine()
	{
		if (m_pTarget != nullptr) { m_pTarget->Release(); }
		if (m_device != nullptr) { m_device->Release(); }
		if (m_context != nullptr) { m_context->Release(); }
		if (m_pSwap != nullptr) { m_pSwap->Release(); }
	}
	// --==<setters>==--
	void gfx_engine::SetPrimitive(gfx_primitives gPrimitive) { m_context->IASetPrimitiveTopology(convert_enum<gfx_primitives, D3D11_PRIMITIVE_TOPOLOGY>(gPrimitive)); }
	void gfx_engine::SetModes(Bit bEnable, processing_modes pmModes) {

		switch (pmModes) {
		case PM_BLEND:
			m_config.Blending.bEnable = bEnable;
			break;
		case PM_DEPTH_TEST:
			m_config.DepthTest.bEnable = bEnable;
			break;
		case PM_CULL_FACE:
			m_config.Culling.bEnable = bEnable;
			break;
		default: break;
		}
		if (bEnable) {
		}
		else {
		}
	}
	void gfx_engine::SetViewport(si32 nX0, si32 nY0, si32 nX1, si32 nY1) {
		m_config.General.rectViewport = { nX0, nY0, nX1, nY1 };
		D3D11_VIEWPORT vp{ 0 };
		vp.TopLeftX = static_cast<Float32>(nX0);
		vp.TopLeftY = static_cast<Float32>(nY0);
		vp.Width = static_cast<Float32>(nX1 - nX0);
		vp.Height = static_cast<Float32>(nY1 - nY0);
		vp.MaxDepth = 1.0f;
		vp.MinDepth = 0.0f;
		m_context->RSSetViewports(1, &vp);
	}
	void gfx_engine::SetDrawMode(draw_modes dMode, faces facePlane) {
		m_config.General.DrawMode.dMode = dMode;
		m_config.General.DrawMode.facePlane = facePlane;
	}
	void gfx_engine::SetVariable(GfxVariables gfxVar, Float32 nValue) {
		switch(gfxVar) {
		case GV_LINE_WIDTH: m_config.General.nLineWidth = nValue; break;
		case GV_POINT_SIZE: m_config.General.nPixelSize = nValue; break;
		default: break;
		}
	}
	void gfx_engine::SetBlendFunc(blend_configs bcSrcFactor, blend_configs bcDestFactor) {
		m_config.Blending.FactorSrc = bcSrcFactor;
		m_config.Blending.FactorDest = bcDestFactor;
	}
	void gfx_engine::SetDepthFunc(depth_configs dcFunc) {
		m_config.DepthTest.Func = dcFunc;
	}
	void gfx_engine::SetStencilFunc(stencil_configs scFunc, si32 unRefValue, ui8 unBitMask) {
		m_config.StencilTest.Func = scFunc;
		m_config.StencilTest.nBitMask = unBitMask;
		m_config.StencilTest.nRefValue = unRefValue;
	}
	void gfx_engine::SetVSync(Bit bSynchronize) {
		m_config.General.unSwapInterval = bSynchronize;
	}
	// --==</setters>==--
	// --==<core_methods>==--
	void gfx_engine::Update()
	{
		HRESULT hRes;
		const Float32 rgbaClear[] = { sinf(TimeSys::GetCurr(0.1)), sinf(TimeSys::GetCurr(0.5)), cosf(TimeSys::GetCurr(0.3)), 1.0f };
		
		if ((hRes = m_pSwap->Present(m_config.General.unSwapInterval, 0u)) < 0) { throw(error("something went wrong")); }
		m_context->ClearRenderTargetView(m_pTarget, rgbaClear);
	}
	void gfx_engine::BeginDraw()
	{
		m_dInfo.Reset();
	}
	void gfx_engine::EndDraw()
	{
		if (m_dInfo.idx > 0) { m_context->DrawIndexed(m_dInfo.idx, 0u, 0u); }
		else if (m_dInfo.unVtx > 0) { m_context->Draw(m_dInfo.unVtx, 0u); }
	}
	void gfx_engine::on_draw(Drawable& rDrb)
	{
		rDrb.Bind();
		for (auto& itBuf : rDrb.GetResources()) { }
	}
	void gfx_engine::Create(mem_ref<gfx_engine>& rEngine, HWND& rWindow)
	{
		if (rWindow == nullptr) { throw error("Window is not initialized!"); return; }
		rEngine.MakeRef<gfx_engine>(rWindow);
	}
	// --==</core_methods>==--
}
#endif
#endif	// NWG_GAPI