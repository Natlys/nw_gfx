#include <nwg_pch.hpp>
#include "nwg_engine.h"
#if (defined NW_GAPI)
#include <lib/nwg_load.h>
#include <lib/nwg_load_core.h>
#include <lib/nwg_load_fmbuf.h>
#include <lib/nwg_load_buf.h>
#include <lib/nwg_load_layt.h>
#include <lib/nwg_load_txr.h>
#include <lib/nwg_load_smp.h>
#include <lib/nwg_load_shd.h>
#include <lib/nwg_load_mtl.h>
#if (NW_GAPI & NW_GAPI_OGL)
#include <lib/nwg_load_wgl.h>
namespace NW
{
	void gfx_engine_info::update() {
		strcpy_s(drawer, reinterpret_cast<cstr>(glGetString(GL_RENDERER)) );
		strcpy_s(version, reinterpret_cast<cstr>(glGetString(GL_VERSION)) );
		strcpy_s(vendor, reinterpret_cast<cstr>(glGetString(GL_VENDOR)) );
		strcpy_s(shd_lang, reinterpret_cast<cstr>(glGetString(GL_SHADING_LANGUAGE_VERSION)) );
		
		si32 temp = 0;
		glGetIntegerv(GL_POINT_SIZE_RANGE, &temp); pxl_range = static_cast<ui8>(temp);
		glGetIntegerv(GL_POINT_SIZE_GRANULARITY, &temp); pxl_gran = static_cast<ui8>(temp);
		glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &temp); max_txr_slots = static_cast<ui8>(temp);
		glGetIntegerv(GL_MAX_VERTEX_ATTRIB_BINDINGS, &temp); max_vtx_atbs = static_cast<ui8>(temp);
	}
}
namespace NW
{
	gfx_engine::gfx_engine(wndh window) :
		m_wndh(window), m_dvch(::GetWindowDC(window)), m_ctxh(NULL),
		m_clear_color{ 0.35f, 0.2f, 0.3f, 1.0f }
	{
		if (m_wndh == NULL) { throw init_error(__FILE__, __LINE__); return; }
		// get device context of the window;
		// get default device context;
		// only one devic context can be used in a single thread at one time;
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
		si32 pxl_format = ::ChoosePixelFormat(m_dvch, &pxf_desc);
		if (pxl_format == 0) { NW_ERR("Failed to get a pixel format"); return; }
		// pixel format can be set to some window only once
		if (!::SetPixelFormat(m_dvch, pxl_format, &pxf_desc)) { throw init_error(__FILE__, __LINE__); return; }
		::DescribePixelFormat(m_dvch, pxl_format, pxf_desc.nSize, &pxf_desc);
		// create opengl context and associate that with the device context;
		// it will be attached to the current thread and dc;
		// this is only one current context we can use;
		if (!gfx_open_lib()) { throw init_error(__FILE__, __LINE__); return; }
		m_ctxh = wglCreateContext(m_dvch);
		wglMakeContextCurrent(m_dvch, m_ctxh);
		if (!gfx_load_lib()) { throw init_error(__FILE__, __LINE__); return; }

		glDisable(GL_CULL_FACE);
		glDisable(GL_DEPTH_TEST);
		
		set_swap_delay(0u);
		set_viewport(0, 0, 800, 600);
		set_clear_color(0.6f, 0.6f, 0.3f, 1.0f);
		set_primitive(GPT_TRIANGLES);
	}
	gfx_engine::~gfx_engine()
	{
		// break the connection between our thread and the rendering context;
		wglMakeContextCurrent(NULL, NULL);
		// release the associated dc and delete the rendering context;
		ReleaseDC(m_wndh, m_dvch);
		// before delete - we need to release that;
		// DeleteDC(m_ctxh);	// delete only created device context;
		// before this call device context must be released or deleted;
		wglDeleteContext(m_ctxh);
		m_ent_reg.clear();
		m_cmp_reg.clear();
		if (!gfx_close_lib()) { quit_error(__FILE__, __LINE__); }
	}
	// --setters
	void gfx_engine::set_fbuf_size(si32 size_x, si32 size_y) {
		//
	}
	void gfx_engine::set_viewport(v4f viewport) {
		m_viewport = viewport;
		glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);
	}
	void gfx_engine::set_viewport(f32 crd_x, f32 crd_y, f32 size_x, f32 size_y) {
		m_viewport[0] = crd_x;
		m_viewport[1] = crd_y;
		m_viewport[2] = size_x;
		m_viewport[3] = size_y;
		glViewport(crd_x, crd_y, size_x, size_y);
	}
	void gfx_engine::set_clear_color(f32 red, f32 green, f32 blue, f32 alpha) {
		m_clear_color[0] = red;
		m_clear_color[1] = green;
		m_clear_color[2] = blue;
		m_clear_color[3] = alpha;
	};
	void gfx_engine::set_primitive(prim_type primitive_topology) {
		m_prim_type = primitive_topology;
	}
	void gfx_engine::set_swap_delay(ui8 swap_delay) {
		m_swap_delay = swap_delay;
	}
	// --==<core_methods>==--
	void gfx_engine::update()
	{
		SwapBuffers(m_dvch);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glClearColor(m_clear_color[0], m_clear_color[1], m_clear_color[2], m_clear_color[3]);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	gfx_engine::gfx_engine(wndh window) :
		m_wndh(window),
		m_dvch(nullptr), m_ctxh(nullptr),
		m_viewport{ 0.0f, 0.0f, 800.0f, 600.0f }, m_clear_color{ 1.0f, 1.0f, 1.0f, 1.0f }, m_swap_delay(0), m_prim_type(GPT_TRIANGLES),
		m_swap_chain(nullptr), m_draw_target(nullptr)
	{
		if (m_wndh == nullptr) { throw init_error(__FILE__, __LINE__); return; }
		DXGI_SWAP_CHAIN_DESC swap_desc{ 0 };
		swap_desc.BufferDesc.Width = 0;
		swap_desc.BufferDesc.Height = 0;
		//swap_desc.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
		swap_desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swap_desc.BufferDesc.RefreshRate.Numerator = 0;
		swap_desc.BufferDesc.RefreshRate.Denominator = 0;
		swap_desc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		swap_desc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		swap_desc.SampleDesc.Count = 1;
		swap_desc.SampleDesc.Quality = 0;
		swap_desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swap_desc.BufferCount = 1;
		swap_desc.OutputWindow = window;
		swap_desc.Windowed = TRUE;
		//swap_desc.Windowed = FALSE;
		swap_desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		swap_desc.Flags = 0;

		if (!gfx_open_lib()) { throw init_error(__FILE__, __LINE__); return; }
		if (!gfx_load_lib()) { throw init_error(__FILE__, __LINE__); return; }
		gfx_new_context_and_swap_chain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, D3D11_CREATE_DEVICE_DEBUG,
			nullptr, NULL, D3D11_SDK_VERSION, &swap_desc, &m_swap_chain, &m_dvch, nullptr, &m_ctxh);
		if (m_dvch == nullptr) { throw init_error(__FILE__, __LINE__); }
		if (m_ctxh == nullptr) { throw init_error(__FILE__, __LINE__); }
		if (m_swap_chain == nullptr) { throw init_error(__FILE__, __LINE__); }

		ID3D11Resource* back_buf = nullptr;
		m_swap_chain->GetBuffer(0u, __uuidof(ID3D11Resource), reinterpret_cast<ptr*>(&back_buf));
		m_dvch->CreateRenderTargetView(back_buf, nullptr, &m_draw_target);
		m_ctxh->OMSetRenderTargets(1u, &m_draw_target, nullptr);
		if (m_draw_target == nullptr) { throw init_error(__FILE__, __LINE__); return; }
		
		set_swap_delay(0u);
		set_viewport(0, 0, 800, 600);
		set_clear_color(0.4f, 0.2f, 0.1f, 1.0f);
		set_primitive(GPT_TRIANGLES);
	}
	gfx_engine::~gfx_engine()
	{
		if (m_draw_target != nullptr) { m_draw_target->Release(); }
		if (m_swap_chain != nullptr) { m_swap_chain->Release(); }
		if (m_dvch != nullptr) { m_dvch->Release(); }
		if (m_ctxh != nullptr) { m_ctxh->Release(); }
		if (!gfx_close_lib()) { quit_error(__FILE__, __LINE__); return; }
	}
	// -- setters
	void gfx_engine::set_fbuf_size(si32 size_x, si32 size_y) {
		if (m_draw_target != nullptr) { m_draw_target->Release(); m_draw_target = nullptr; }
		m_swap_chain->ResizeBuffers(1u, size_x, size_y, DXGI_FORMAT_UNKNOWN, 0u);

		ID3D11Resource* back_buf = nullptr;
		m_swap_chain->GetBuffer(0u, __uuidof(ID3D11Resource), reinterpret_cast<ptr*>(&back_buf));
		m_dvch->CreateRenderTargetView(back_buf, nullptr, &m_draw_target);
		m_ctxh->OMSetRenderTargets(1u, &m_draw_target, nullptr);
		if (m_draw_target == nullptr) { throw init_error(__FILE__, __LINE__); return; }
	}
	void gfx_engine::set_viewport(v4f viewport) {
		m_viewport = viewport;
		D3D11_VIEWPORT dx_viewport;
		dx_viewport.TopLeftX = viewport[0];
		dx_viewport.TopLeftY = viewport[1];
		dx_viewport.Width = viewport[2];
		dx_viewport.Height = viewport[3];
		dx_viewport.MinDepth = 0.01f;
		dx_viewport.MaxDepth = 1.00f;
		m_ctxh->RSSetViewports(1, &dx_viewport);
	}
	void gfx_engine::set_viewport(f32 crd_x, f32 crd_y, f32 size_x, f32 size_y) {
		if (size_x <= 1.0f || size_y <= 1.0f) { return; }
		m_viewport[0] = crd_x;
		m_viewport[1] = crd_y;
		m_viewport[2] = size_x;
		m_viewport[3] = size_y;
		D3D11_VIEWPORT dx_viewport;
		dx_viewport.TopLeftX = crd_x;
		dx_viewport.TopLeftY = crd_y;
		dx_viewport.Width = size_y;
		dx_viewport.Height = size_y;
		dx_viewport.MinDepth = 0.01f;
		dx_viewport.MaxDepth = 1.00f;
		m_ctxh->RSSetViewports(1, &dx_viewport);
	}
	void gfx_engine::set_clear_color(v4f clear_color) {
		m_clear_color = clear_color;
	};
	void gfx_engine::set_clear_color(f32 red, f32 green, f32 blue, f32 alpha) {
		m_clear_color[0] = red;
		m_clear_color[1] = green;
		m_clear_color[2] = blue;
		m_clear_color[3] = alpha;
	};
	void gfx_engine::set_primitive(gfx_primitives primitive_topology) {
		m_prim_type = primitive_topology;
		m_ctxh->IASetPrimitiveTopology(convert_enum<gfx_primitives, D3D11_PRIMITIVE_TOPOLOGY>(primitive_topology));
	}
	void gfx_engine::set_swap_delay(ui8 swap_delay) {
		m_swap_delay = swap_delay;
	}
	// --==<core_methods>==--
	void gfx_engine::update()
	{
		HRESULT h_result;
		if ((h_result = m_swap_chain->Present(m_swap_delay, 0u)) != S_OK) { throw(run_error("something went wrong")); return; }
		m_ctxh->ClearRenderTargetView(m_draw_target, &m_clear_color[0]);
	}
	// --==</core_methods>==--
}
#endif
#endif	// NW_GAPI