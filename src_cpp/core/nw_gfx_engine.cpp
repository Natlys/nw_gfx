#include "nw_gfx_pch.hpp"
#include "nw_gfx_engine.h"
#if (defined NW_GAPI)
#	include "nw_gfx.hpp"
#	include "nw_gfx_data.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_engine::gfx_engine() :
		m_context(context_t()),
		m_cmd_buf(cmd_buf_t()),
		m_viewp(NW_NULL),
		m_vsync(NW_NULL)
	{
	}
	gfx_engine::~gfx_engine()
	{
	}
	// --setters
	v1nil gfx_engine::set_window(window_t& window) {
		m_context.set_window(window);
	}
	v1nil gfx_engine::set_fmbuf_size(v1u size_x, v1u size_y) {
		auto& fmbuf = cmp_sys::get().get_ref<gfx_fmbuf>(NW_NULL).get_val<gfx_fmbuf>();
		NW_CHECK(fmbuf.remake(fmbuf.get_layt(), { size_x, size_y }), "failed remake!", return);
	}
	v1nil gfx_engine::set_viewp(v1f crd_x, v1f crd_y, v1f size_x, v1f size_y) {
		m_viewp[0] = crd_x;
		m_viewp[1] = crd_y;
		m_viewp[2] = size_x;
		m_viewp[3] = size_y;
		glViewport(m_viewp[0], m_viewp[1], m_viewp[2], m_viewp[3]);
	}
	v1nil gfx_engine::set_vsync(v1u vsync) {
		m_vsync = vsync;
		wglSwapIntervalEXT(m_vsync);
	}
	// --==<core_methods>==--
	v1bit gfx_engine::init()
	{
		// NW_CHECK(!m_ctxh && !m_dvch && !m_libh, "init is already done!", return NW_FALSE);
		NW_CHECK(m_context.remake(), "failed remake!", return NW_FALSE);
		// set up configs
		if constexpr (NW_TRUE) {
			set_vsync(0u);
			set_viewp(0, 0, 800, 600);
			glClearColor(get_rand<v1f>(0.0f, 0.5f), get_rand<v1f>(0.0f, 0.5f), get_rand<v1f>(0.0f, 0.5f), 1.0f);
		}
		// create default components
		if constexpr (NW_TRUE) {
			// buffers
			if constexpr (NW_TRUE) {
				// layouts
				auto& layt_rect = cmp_sys::get().new_ref<gfx_buf_layt>();
				layt_rect->add_node<v2f>("vsi_vtx_crd");
				// shader buffers
				auto& sbuf_tform = cmp_sys::get().new_ref<gfx_buf_shd>();
				mem_layt sbuf_layt;
				sbuf_layt.add_node<m4f>("cst_model");
				sbuf_layt.add_node<m4f>("cst_view");
				sbuf_layt.add_node<m4f>("cst_proj");
				NW_CHECK(sbuf_tform.get_ref<mem_buf>()->remake(sbuf_layt, 1u), "failed remake", throw init_error());
				// vertex buffers
				auto& vbuf_rect = cmp_sys::get().new_ref<gfx_buf_vtx>();
				NW_CHECK(vbuf_rect.get_ref<mem_buf>()->remake(layt_rect, 4u, vtx_quad_2f), "failed remake!", throw init_error());
				// index buffers
				// layouts again
				NW_CHECK(layt_rect->remake(), "failed remake!", throw init_error());
			}
			// framebuffers
			if constexpr (NW_TRUE) {
				auto& fmbuf = cmp_sys::get().new_ref<gfx_fmbuf>();
				fmbuf->add_part(cmp_sys::get().new_ref<a_gfx_fmbuf_part, gfx_fmbuf_draw>());
				mem_layt layt_fmbuf("fmbuf");
				layt_fmbuf.add_node<v4u08>("draw");
				//layt_fmbuf.add_node<v3u08>("dept");
				//layt_fmbuf.add_node<v1u08>("sten");
				NW_CHECK(fmbuf->remake(layt_fmbuf, v2u{ 128u, 128u }), "failed remake!", return NW_FALSE);
			}
			// textures
			if constexpr (NW_TRUE) {
				auto& smp_nearest = cmp_sys::get().new_ref<gfx_txr_smp>();
				NW_CHECK(
					smp_nearest->remake(NW_GFX_FILTER_NEAREST, NW_GFX_WRAP_BORDER, get_rand<v1f, 4u>(0.0f, 1.0f)),
					"failed remake!", return NW_FALSE
				);
				auto& txr_noise = cmp_sys::get().new_ref<a_gfx_txr, gfx_txr_2d>();
				txr_noise->set_smp(smp_nearest);
				txr_noise->set_layt(t_mem_layt<v4u08>("pixel"));
				txr_noise->set_size_xyz(v3u{ 16u, 16u, 1u });
				NW_CHECK(txr_noise->remake(), "failed remake!", return NW_FALSE);
				for (v1u itr = 0u; itr < txr_noise->get_size(); itr++) { (*txr_noise)[itr] = get_rand<v1u08, 4u>(0u, 255u); }
				NW_CHECK(txr_noise->remake(), "failed remake!", return NW_FALSE);
			}
			// materials
			if constexpr (NW_TRUE) {
				// screen material
				auto& mtl_screen = cmp_sys::get().new_ref<gfx_mtl>();
				auto& vshd_screen = cmp_sys::get().new_ref<a_gfx_shd, gfx_shd_vtx>();
				auto& pshd_screen = cmp_sys::get().new_ref<a_gfx_shd, gfx_shd_pxl>();
				pshd_screen->set_txr(cmp_sys::get().get_ref<a_gfx_txr>(NW_NULL), NW_NULL);
				mtl_screen->add_shd(vshd_screen);
				mtl_screen->add_shd(pshd_screen);
				NW_CHECK(vshd_screen->remake(shd_src_screen_vtx), "failed remake!", return NW_FALSE);
				NW_CHECK(pshd_screen->remake(shd_src_screen_pxl), "failed remake!", return NW_FALSE);
				NW_CHECK(mtl_screen->remake(), "failed remake!", return NW_FALSE);
				// 3d material
				auto& mtl_3d = cmp_sys::get().new_ref<gfx_mtl>();
				auto& vshd_3d = cmp_sys::get().new_ref<a_gfx_shd, gfx_shd_vtx>();
				auto& pshd_3d = cmp_sys::get().new_ref<a_gfx_shd, gfx_shd_pxl>();
				vshd_3d->set_buf(cmp_sys::get().get_ref<gfx_buf_shd>(NW_NULL), NW_NULL);
				pshd_3d->set_txr(cmp_sys::get().get_ref<a_gfx_txr>(1u), NW_NULL);
				mtl_3d->add_shd(vshd_3d);
				mtl_3d->add_shd(pshd_3d);
				NW_CHECK(vshd_3d->remake(shd_src_3d_vtx), "failed remake!", return NW_FALSE);
				NW_CHECK(pshd_3d->remake(shd_src_3d_pxl), "failed remake!", return NW_FALSE);
				NW_CHECK(mtl_3d->remake(), "failed remake!", return NW_FALSE);
			}
		}
		return NW_TRUE;
	}
	v1bit gfx_engine::quit()
	{
		NW_CHECK(has_window(), "quit is already done!", return NW_FALSE);
		m_context = context_t();
		return NW_TRUE;
	}
	v1nil gfx_engine::update()
	{
		gfx_state last_state;

		if constexpr (NW_FALSE) {
			auto& fmbuf = cmp_sys::get().get_ref<gfx_fmbuf>(NW_NULL);
			fmbuf->on_draw();
			fmbuf->clear();
			m_cmd_buf.on_draw();
			glBindFramebuffer(GL_FRAMEBUFFER, NW_NULL);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
			cmp_sys::get().get_ref<gfx_buf_layt>(NW_NULL)->on_draw();
			cmp_sys::get().get_ref<gfx_mtl>(NW_NULL)->on_draw();
			glDrawArrays(GL_QUADS, NW_NULL, 4u);
			m_context.update();
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		}
		else {
			glBindFramebuffer(GL_FRAMEBUFFER, NW_NULL);
			m_cmd_buf.on_draw();
			m_context.update();
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		}
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
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
	}
	// --setters
	v1nil gfx_engine::set_fmbuf_size(v1u size_x, v1u size_y) {
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
	v1bit gfx_engine::init()
	{
		if constexpr (NW_TRUE) {
			if (m_libh != NW_NULL) { return NW_FALSE; }
			m_libh = ::LoadLibrary("d3d11.dll");
			if (m_libh_dxcomp != NW_NULL) { return NW_FALSE; }
			m_libh_dxcomp = ::LoadLibrary(D3DCOMPILER_DLL);
			if (m_libh_dxgi != NW_NULL) { return NW_FALSE; }
			m_libh_dxgi = ::LoadLibrary("dxgi.dll");
			NW_CHECK(gfx_load_wapi(), "failed load!", return NW_FALSE);
		}
		return NW_TRUE;
	}
	v1bit gfx_engine::quit()
	{
		if constexpr (NW_TRUE) {
			if (m_libh == NW_NULL) { return NW_FALSE; }
			::FreeLibrary(m_libh);
			m_libh = NW_NULL;
			if (m_libh_dxcomp == NW_NULL) { return NW_FALSE; }
			::FreeLibrary(m_libh_dxcomp);
			m_libh_dxcomp = NW_NULL;
			if (m_libh_dxgi == NW_NULL) { return NW_FALSE; }
			::FreeLibrary(m_libh_dxgi);
			m_libh_dxgi = NW_NULL;
		}
		return NW_TRUE;
	}
	v1nil gfx_engine::update()
	{
		HRESULT h_result;
		if ((h_result = m_swap_chain->Present(m_swap_delay, 0u)) != S_OK) { throw(run_error("something went wrong")); return; }
		m_ctxh->ClearRenderTargetView(m_draw_target, &m_clear_color[0]);
	}
	ptr_t gfx_engine::get_proc(cstr_t name)
	{
		ptr_t resource = NW_NULL;
		if (resource == NW_NULL) {
			resource = ::GetProcAddress(m_libh_dxcomp, name);
		}
		if (resource == NW_NULL) {
			resource = ::GetProcAddress(m_libh_dxgi, name);
		}
		return resource;
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NW_GAPI