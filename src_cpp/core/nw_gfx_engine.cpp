#include "nw_gfx_pch.hpp"
#include "nw_gfx_engine.h"
#if (defined NW_GAPI)
#include "nw_gfx.hpp"
#include "nw_gfx_data.h"
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_engine::gfx_engine(wndh window) :
		m_wndh(window),
		m_dvch(::GetWindowDC(window)),
		m_ctxh(NW_NULL),
		m_cmd_buf(*this),
		m_viewport{ 0.0f, 0.0f, 800.0f, 600.0f },
		m_clear_color{ 1.0f, 1.0f, 1.0f, 1.0f },
		m_swap_delay(0u)
	{
		if (m_wndh == NW_NULL) { throw init_error(__FILE__, __LINE__); return; }
		// get device context of the window;
		// get default device context;
		// only one devic context can be used in a single thread at one time;
		// setup device pixel format and only then make render context;
		if constexpr (NW_TRUE) {
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
			v1s pxl_format = ::ChoosePixelFormat(m_dvch, &pxf_desc);
			if (pxl_format == 0) { throw init_error(__FILE__, __LINE__); return; }
			// pixel format can be set to some window only once
			if (!::SetPixelFormat(m_dvch, pxl_format, &pxf_desc)) { throw init_error(__FILE__, __LINE__); return; }
			::DescribePixelFormat(m_dvch, pxl_format, pxf_desc.nSize, &pxf_desc);
			// create opengl context and associate that with the device context;
			// it will be attached to the current thread and dc;
			// this is only one current context we can use;
			if (!gfx_lib_loader::get().load()) { throw init_error(__FILE__, __LINE__); return; }
			m_ctxh = wglCreateContext(m_dvch);
			wglMakeContextCurrent(m_dvch, m_ctxh);
			if (!gfx_lib_loader::get().init()) { throw init_error(__FILE__, __LINE__); return; }
		}
		if constexpr (NW_TRUE) {
			set_swap_delay(0u);
			set_viewport(0, 0, 800, 600);
			set_clear_color(0.3f, 0.3f, 0.3f, 1.0f);
		}
	}
	gfx_engine::~gfx_engine()
	{
		// break the connection between our thread and the rendering context;
		wglMakeContextCurrent(NW_NULL, NW_NULL);
		// release the associated dc and delete the rendering context;
		ReleaseDC(m_wndh, m_dvch);
		// before delete - we need to release that;
		// DeleteDC(m_ctxh);	// delete only created device context;
		// before this call device context must be released or deleted;
		wglDeleteContext(m_ctxh);
		
		m_ent_reg.clear();
		m_cmp_reg.clear();
		
		gfx_lib_loader::get().free();
		gfx_lib_loader::get().quit();
	}
	// --setters
	v1nil gfx_engine::set_fbuf_size(v1u size_x, v1u size_y) {
		//
	}
	v1nil gfx_engine::set_viewport(v4f viewport) {
		m_viewport = viewport;
		glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);
	}
	v1nil gfx_engine::set_viewport(v1f crd_x, v1f crd_y, v1f size_x, v1f size_y) {
		m_viewport[0] = crd_x;
		m_viewport[1] = crd_y;
		m_viewport[2] = size_x;
		m_viewport[3] = size_y;
		glViewport(crd_x, crd_y, size_x, size_y);
	}
	v1nil gfx_engine::set_clear_color(v1f red, v1f green, v1f blue, v1f alpha) {
		m_clear_color[0] = red;
		m_clear_color[1] = green;
		m_clear_color[2] = blue;
		m_clear_color[3] = alpha;
	};
	v1nil gfx_engine::set_swap_delay(v1u swap_delay) {
		m_swap_delay = swap_delay;
		wglSwapIntervalEXT(m_swap_delay);
	}
	// --==<core_methods>==--
	v1nil gfx_engine::update()
	{
		::SwapBuffers(m_dvch);
		glClearColor(m_clear_color[0], m_clear_color[1], m_clear_color[2], m_clear_color[3]);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		m_cmd_buf.on_draw();
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	gfx_engine::gfx_engine(wndh window) :
		m_wndh(window),
		m_dvch(NW_NW_NULL),
		m_ctxh(NW_NW_NULL),
		m_viewport{ 0.0f, 0.0f, 800.0f, 600.0f },
		m_clear_color{ 1.0f, 1.0f, 1.0f, 1.0f },
		m_swap_delay(0u),
		m_prim(NW_PRIM_TRIANGLES),
		m_swap_chain(NW_NW_NULL),
		m_draw_target(NW_NW_NULL)
	{
		if (m_wndh == NW_NW_NULL) { throw init_error(__FILE__, __LINE__); return; }
		DXGI_SWAP_CHAIN_DESC swap_desc{ 0 };
		swap_desc.BufferDesc.Width = 0u;
		swap_desc.BufferDesc.Height = 0u;
		swap_desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swap_desc.BufferDesc.RefreshRate.Numerator = 0u;
		swap_desc.BufferDesc.RefreshRate.Denominator = 0u;
		swap_desc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		swap_desc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		swap_desc.SampleDesc.Count = 1;
		swap_desc.SampleDesc.Quality = 0;
		swap_desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swap_desc.BufferCount = 1;
		swap_desc.OutputWindow = window;
		swap_desc.Windowed = TRUE;
		swap_desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		swap_desc.Flags = 0;

		if (!gfx_lib_loader::get().load()) { throw init_error(__FILE__, __LINE__); return; }
		if (!gfx_lib_loader::get().init()) { throw init_error(__FILE__, __LINE__); return; }
		D3D11CreateDeviceAndSwapChain(
			NW_NW_NULL,
			D3D_DRIVER_TYPE_HARDWARE,
			NW_NW_NULL,
			D3D11_CREATE_DEVICE_DEBUG,
			NW_NW_NULL,
			0u,
			D3D11_SDK_VERSION,
			&swap_desc,
			&m_swap_chain,
			&m_dvch,
			NW_NW_NULL,
			&m_ctxh
		);
		if (m_dvch == NW_NW_NULL) { throw init_error(__FILE__, __LINE__); }
		if (m_ctxh == NW_NW_NULL) { throw init_error(__FILE__, __LINE__); }
		if (m_swap_chain == NW_NW_NULL) { throw init_error(__FILE__, __LINE__); }
		// configuration
		if constexpr (NW_TRUE) {
			// other stuff
			if constexpr (NW_TRUE) {
				set_swap_delay(0u);
				set_viewport(0, 0, 800, 600);
				set_fbuf_size(800, 600);
				set_clear_color(0.3f, 0.3f, 0.3f, 1.0f);
				set_prim(NW_PRIM_TRIANGLES);
			}
		}
	}
	gfx_engine::~gfx_engine()
	{
		if (m_draw_target != NW_NW_NULL) { m_draw_target->Release(); m_draw_target = NW_NW_NULL; }
		if (m_swap_chain != NW_NW_NULL) { m_swap_chain->Release(); m_swap_chain = NW_NW_NULL; }
		if (m_dvch != NW_NW_NULL) { m_dvch->Release(); m_dvch = NW_NW_NULL; }
		if (m_ctxh != NW_NW_NULL) { m_ctxh->Release(); m_ctxh = NW_NW_NULL; }
		
		m_ent_reg.clear();
		m_cmp_reg.clear();

		gfx_lib_loader::get().free();
		gfx_lib_loader::get().quit();
	}
	// -- setters
	v1nil gfx_engine::set_fbuf_size(v1u size_x, v1u size_y) {
		if (m_draw_target != NW_NW_NULL) { m_draw_target->Release(); m_draw_target = NW_NW_NULL; }
		
		m_ctxh->OMSetRenderTargets(0u, NW_NW_NULL, NW_NW_NULL);
		ID3D11Resource* back_buf = NW_NW_NULL;
		m_swap_chain->ResizeBuffers(1u, size_x, size_y, DXGI_FORMAT_UNKNOWN, 0u);
		m_swap_chain->GetBuffer(0u, __uuidof(ID3D11Resource), reinterpret_cast<ptr*>(&back_buf));
		m_dvch->CreateRenderTargetView(back_buf, NW_NW_NULL, &m_draw_target);
		back_buf->Release();
		if (m_draw_target == NW_NW_NULL) { throw init_error(__FILE__, __LINE__); return; }
		
		m_ctxh->OMSetRenderTargets(1u, &m_draw_target, NW_NW_NULL);
	}
	v1nil gfx_engine::set_viewport(v4f viewport) {
		m_viewport = viewport;
		D3D11_VIEWPORT dx_viewport;
		dx_viewport.TopLeftX = -viewport[0] / 2.0f;
		dx_viewport.TopLeftY = -viewport[1] / 2.0f;
		dx_viewport.Width = +viewport[2] / 2.0f;
		dx_viewport.Height = +viewport[3] / 2.0f;
		dx_viewport.MinDepth = 0.01f;
		dx_viewport.MaxDepth = 1.00f;
		m_ctxh->RSSetViewports(1u, &dx_viewport);
	}
	v1nil gfx_engine::set_viewport(v1f crd_x, v1f crd_y, v1f size_x, v1f size_y) {
		if (size_x <= 1.0f || size_y <= 1.0f) { return; }
		m_viewport[0] = crd_x;
		m_viewport[1] = crd_y;
		m_viewport[2] = size_x;
		m_viewport[3] = size_y;
		D3D11_VIEWPORT dx_viewport;
		dx_viewport.TopLeftX = crd_x;
		dx_viewport.TopLeftY = crd_y;
		dx_viewport.Width = size_x;
		dx_viewport.Height = size_y;
		dx_viewport.MinDepth = 0.01f;
		dx_viewport.MaxDepth = 1.00f;
		m_ctxh->RSSetViewports(1u, &dx_viewport);
	}
	v1nil gfx_engine::set_clear_color(v4f clear_color) {
		m_clear_color = clear_color;
	};
	v1nil gfx_engine::set_clear_color(v1f red, v1f green, v1f blue, v1f alpha) {
		m_clear_color[0] = red;
		m_clear_color[1] = green;
		m_clear_color[2] = blue;
		m_clear_color[3] = alpha;
	};
	v1nil gfx_engine::set_swap_delay(v1u swap_delay) {
		m_swap_delay = swap_delay;
	}
	v1nil gfx_engine::set_prim(prim primitive) {
		m_prim = convert<primitives, prim>(primitive);
		m_ctxh->IASetPrimitiveTopology(convert<primitives, D3D11_PRIMITIVE_TOPOLOGY>(primitive));
	}
	// --==<core_methods>==--
	v1nil gfx_engine::update()
	{
		HRESULT h_result;
		if ((h_result = m_swap_chain->Present(m_swap_delay, 0u)) != S_OK) { throw(run_error("something went wrong")); return; }
		m_ctxh->ClearRenderTargetView(m_draw_target, &m_clear_color[0]);
	}
	v1nil gfx_engine::draw_vtx(gfx_buf_vtx* buffer)
	{
		m_ctxh->Draw(buffer->get_count(), buffer->get_offset() / buffer->get_stride());
	}
	v1nil gfx_engine::draw_vtx(v1u buffer_id)
	{
		if (gfx_buf_vtx* vbuf = this->get_cmp_ref<gfx_buf_vtx>(buffer_id).get_ref<gfx_buf_vtx>()->check_cast<gfx_buf_vtx>()) {
			m_ctxh->Draw(vbuf->get_count(), vbuf->get_offset() / vbuf->get_stride());
		}
	}
	v1nil gfx_engine::draw_idx(gfx_buf_idx* buffer)
	{
		m_ctxh->DrawIndexed(buffer->get_count(), buffer->get_offset() / buffer->get_stride(), 0u);
	}
	v1nil gfx_engine::draw_idx(v1u buffer_id)
	{
		if (gfx_buf_idx* ibuf = this->get_cmp_ref<gfx_buf_idx>(buffer_id).get_ref<gfx_buf_idx>()->check_cast<gfx_buf_idx>()) {
			m_ctxh->DrawIndexed(ibuf->get_count(), ibuf->get_offset() / ibuf->get_stride(), 0u);
		}
	}
	// --==</core_methods>==--
}
#endif
#endif	// NW_GAPI