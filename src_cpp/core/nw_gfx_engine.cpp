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
	gfx_engine::engine_t& gfx_engine::set_window(window_t& window) {
		m_context.set_window(window);
		return *this;
	}
	gfx_engine::engine_t& gfx_engine::set_viewp(viewp_tc& viewp) {
		m_viewp[0] = viewp[0];
		m_viewp[1] = viewp[1];
		m_viewp[2] = viewp[2];
		m_viewp[3] = viewp[3];
		glViewport(m_viewp[0], m_viewp[1], m_viewp[2], m_viewp[3]);
		return *this;
	}
	gfx_engine::engine_t& gfx_engine::set_vsync(vsync_tc& vsync) {
		m_vsync = vsync;
		wglSwapIntervalEXT(m_vsync);
		return *this;
	}
	// --==<core_methods>==--
	v1bit gfx_engine::init()
	{
		// NW_CHECK(!m_ctxh && !m_dvch && !m_libh, "init is already done!", return NW_FALSE);
		NW_CHECK(m_context.remake(), "remake error!", return NW_FALSE);
		// set up configs
		if constexpr (NW_TRUE) {
			set_vsync(vsync_t{ NW_NULL });
			set_viewp(viewp_t{ 0, 0, 800, 600 });
			glClearColor(get_rand<v1f>(0.0f, 0.5f), get_rand<v1f>(0.0f, 0.5f), get_rand<v1f>(0.0f, 0.5f), 1.0f);
		}
		// create components
		if constexpr (NW_TRUE) {
			// buffers
			if constexpr (NW_TRUE) {
				// shader buffers
				if constexpr (NW_TRUE) {
					// cam_tform
					if constexpr (NW_TRUE) {
						auto& sbuf = cmp_sys::get().new_ref<gfx_buf_shd>().get_val<mem_buf>();
						mem_layt layt;
						layt.add_node<m4f>("cam_modl").add_node<m4f>("cam_view").add_node<m4f>("cam_proj");
						NW_CHECK(sbuf.remake(layt, 1u), "failed remake", return NW_FALSE);
					}
					// obj_tform
					if constexpr (NW_TRUE) {
						auto& sbuf = cmp_sys::get().new_ref<gfx_buf_shd>().get_val<mem_buf>();
						mem_layt layt;
						layt.add_node<m4f>("obj_modl");
						NW_CHECK(sbuf.remake(layt, 1u), "failed remake", return NW_FALSE);
					}
				}
				// vertex layouts
				if constexpr (NW_TRUE) {
					// rectangle
					if constexpr (NW_TRUE) {
						auto& layt = cmp_sys::get().new_ref<gfx_buf_layt>().get_val();
						auto& vbuf = cmp_sys::get().new_ref<gfx_buf_vtx>().get_val<mem_buf>();
						layt.get_layt().add_node<v2f>("vsi_vtx_crd");
						NW_CHECK(vbuf.remake(layt, 4u, vtx_quad_2f), "remake error!", return NW_FALSE);
						NW_CHECK(layt.remake(), "remake error!", throw init_error());
					}
				}
			}
			// framebuffers
			if constexpr (NW_FALSE) {
				auto& fmbuf = cmp_sys::get().new_ref<gfx_fmbuf>();
				fmbuf->add_part(cmp_sys::get().new_ref<a_gfx_fmbuf_part, gfx_fmbuf_draw>());
				mem_layt layt_fmbuf("fmbuf");
				layt_fmbuf.add_node<v4u08>("draw");
				//layt_fmbuf.add_node<v3u08>("dept");
				//layt_fmbuf.add_node<v1u08>("sten");
				NW_CHECK(fmbuf->remake(layt_fmbuf, v2u{ 128u, 128u }), "remake error!", return NW_FALSE);
			}
			// states
			if constexpr (NW_TRUE) {
				auto& depst0 = cmp_sys::get().new_ref<gfx_state_depst>(NW_FALSE, NW_FALSE);
				auto& depst1 = cmp_sys::get().new_ref<gfx_state_depst>(NW_TRUE, NW_FALSE);
			}
			// samplers
			if constexpr (NW_TRUE) {
				auto& smp_nearest = cmp_sys::get().new_ref<gfx_smp>(NW_GFX_FILTER_NEAREST, NW_GFX_WRAP_BORDER, get_rand<v1f, 4u>(0.0f, 1.0f));
			}
			// textures
			if constexpr (NW_TRUE) {
				auto& txr_noise = cmp_sys::get().new_ref<gfx_txr, gfx_txr_2d>();
				txr_noise->set_layt(t_mem_layt<v4u08>("pixel"));
				txr_noise->set_size_xyz(v3u{ 16u, 16u, 1u });
				NW_CHECK(txr_noise->remake(), "remake error!", return NW_FALSE);
				for (v1u itr = 0u; itr < txr_noise->get_size(); itr++) { (*txr_noise)[itr] = get_rand<v1u08, 4u>(0u, 255u); }
				NW_CHECK(txr_noise->remake(), "remake error!", return NW_FALSE);
			}
			// materials
			if constexpr (NW_TRUE) {
				// screen material
				if constexpr (NW_FALSE) {
					auto& vshd = cmp_sys::get().new_ref<gfx_shd, gfx_shd_vtx>(shd_src_screen_vtx);
					auto& pshd = cmp_sys::get().new_ref<gfx_shd, gfx_shd_pxl>(shd_src_screen_pxl);
					auto& vshd_bind = cmp_sys::get().new_ref<gfx_bind>(vshd);
					auto& pshd_bind = cmp_sys::get().new_ref<gfx_bind>(
						pshd,
						gfx_bind::bufs_t{ },
						gfx_bind::txrs_t{ },
						gfx_bind::smps_t{ }
					);
					auto& gmtl = cmp_sys::get().new_ref<gfx_mtl>(gfx_mtl::bind_list_t{ vshd_bind, pshd_bind });
				}
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
		gfx_state_context last_state;

		if constexpr (NW_FALSE) {
			auto& fmbuf = cmp_sys::get().get_ref<gfx_fmbuf>(NW_NULL);
			fmbuf->on_draw();
			fmbuf->clear();
			m_cmd_buf.on_draw();
			m_graph.on_draw();
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
			m_graph.on_draw();
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
<<<<<<< HEAD
	// --setters
	v1nil gfx_engine::set_fmbuf_size(v1u size_x, v1u size_y) {
=======
	// -- setters
	v1nil gfx_engine::set_fbuf_size(v1u size_x, v1u size_y) {
>>>>>>> 5ec48b78bf51cdaf84eb36840c5ed9ec4bcddd88
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
<<<<<<< HEAD
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
=======
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
>>>>>>> 5ec48b78bf51cdaf84eb36840c5ed9ec4bcddd88
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
<<<<<<< HEAD
	v1nil gfx_engine::update()
=======
	v1nil gfx_engine::draw_idx(gfx_buf_idx* buffer)
>>>>>>> 5ec48b78bf51cdaf84eb36840c5ed9ec4bcddd88
	{
		HRESULT h_result;
		if ((h_result = m_swap_chain->Present(m_swap_delay, 0u)) != S_OK) { throw(run_error("something went wrong")); return; }
		m_ctxh->ClearRenderTargetView(m_draw_target, &m_clear_color[0]);
	}
<<<<<<< HEAD
	ptr_t gfx_engine::get_proc(cstr_t name)
=======
	v1nil gfx_engine::draw_idx(v1u buffer_id)
>>>>>>> 5ec48b78bf51cdaf84eb36840c5ed9ec4bcddd88
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