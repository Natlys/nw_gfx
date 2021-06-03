#include "nc_gfx_pch.hpp"
#include "nc_nc_gfx_eng.hxx"
#if (defined NC_GAPI)
#	include "nc_gfx.hpp"
#	include "nc_gfx_data.hxx"
#	if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	nc_gfx_eng::nc_gfx_eng() : std_engine_t(), m_context(context_t()), m_viewp(NC_NULL), m_vsync(NC_NULL) { }
	nc_gfx_eng::~nc_gfx_eng() { }
	/* setters */
	nc_gfx_eng::engine_t& nc_gfx_eng::set_window(window_t& window) {
		m_context.set_window(window);
		return *this;
	}
	nc_gfx_eng::engine_t& nc_gfx_eng::set_viewp(viewp_tc& viewp) {
		m_viewp[0] = viewp[0];
		m_viewp[1] = viewp[1];
		m_viewp[2] = viewp[2];
		m_viewp[3] = viewp[3];
		get_context().set_viewp(m_viewp[0], m_viewp[1], m_viewp[2], m_viewp[3]);
		return *this;
	}
	nc_gfx_eng::engine_t& nc_gfx_eng::set_vsync(vsync_tc& vsync) {
		m_vsync = vsync;
		wglSwapIntervalEXT(m_vsync);
		return *this;
	}
	/* commands */
	v1bit_t nc_gfx_eng::init()
	{
		// initialize something
		if constexpr (NC_TRUTH) {
			NC_CHECK(m_context.remake(), "remake error!", return NC_FALSE);
		}
		// setup configs
		if constexpr (NC_TRUTH) {
			set_vsync(vsync_t{ NC_NULL });
			set_viewp(viewp_t{ 0, 0, 800, 600 });
			get_context().fmbuf_set_color(get_rand<v1f_t>(0.0f, 0.5f), get_rand<v1f_t>(0.0f, 0.5f), get_rand<v1f_t>(0.0f, 0.5f), 1.0f);
		}
		// create components
		if constexpr (NC_TRUTH) {
			// buffers
			if constexpr (NC_TRUTH) {
				// vertex layouts
				if constexpr (NC_TRUTH) {
					// rectangle
					if constexpr (NC_TRUTH) {
						auto& layt = cmp_sys::get().new_ref<gfx_layt_t>().get_val();
						auto& vbuf = cmp_sys::get().new_ref<gfx_buf_vtx_t>().get_val<mem_buf_t>();
						layt.get_layt().add_node<v2f_t>("vsi_vtx_crd");
						NC_CHECK(vbuf.remake(layt, 4u, vtx_quad_2f), "remake error!", return NC_FALSE);
						NC_CHECK(layt.remake(), "remake error!", return NC_FALSE);
					}
				}
			}
			// framebuffers
			if constexpr (NC_FALSE) {
				auto& fmbuf = cmp_sys::get().new_ref<gfx_fmbuf_t>();
				fmbuf->add_part(cmp_sys::get().new_ref<gfx_fmbuf_part_t, gfx_fmbuf_draw_t>());
				mem_layt_t layt_fmbuf("fmbuf");
				layt_fmbuf.add_node<v4u08>("draw");
				//layt_fmbuf.add_node<v3u08>("dept");
				//layt_fmbuf.add_node<v1u08_t>("sten");
				NC_CHECK(fmbuf->remake(layt_fmbuf, v2u{ 128u, 128u }), "remake error!", return NC_FALSE);
			}
			// states
			if constexpr (NC_TRUTH) {
				auto& depst0 = cmp_sys::get().new_ref<gfx_mode_depst_t>(NC_FALSE, NC_FALSE);
				auto& depst1 = cmp_sys::get().new_ref<gfx_mode_depst_t>(NC_TRUTH, NC_FALSE);
			}
			// samplers
			if constexpr (NC_TRUTH) {
				auto& smp_nearest = cmp_sys::get().new_ref<gfx_smp_t>(NC_GFX_FILTER_NEAREST, NC_GFX_WRAP_BORDER, v4f_t::make_rand(0.0f, 1.0f));
			}
			// textures
			if constexpr (NC_TRUTH) {
				auto& txr_noise = cmp_sys::get().new_ref<gfx_txr_t, gfx_txr2d_t>();
				txr_noise->set_layt(mem_layt_tt<v4u08>("pixel"));
				txr_noise->set_size(v3u{ 16u, 16u, 1u });
				NC_CHECK(txr_noise->remake(), "remake error!", return NC_FALSE);
				for (v1u_t itr = 0u; itr < txr_noise->get_size(); itr++) { (*txr_noise)[itr] = v4u08::make_rand(0u, 255u); }
				NC_CHECK(txr_noise->remake(), "remake error!", return NC_FALSE);
			}
			// materials
			if constexpr (NC_TRUTH) {
				// screen material
				if constexpr (NC_FALSE) {
					auto& vshd = cmp_sys::get().new_ref<gfx_shd_t, gfx_shd_vtx_t>(shd_src_screen_vtx);
					auto& pshd = cmp_sys::get().new_ref<gfx_shd_t, gfx_shd_pxl_t>(shd_src_screen_pxl);
					auto& vshd_bind = cmp_sys::get().new_ref<gfx_bind_t>(vshd);
					auto& pshd_bind = cmp_sys::get().new_ref<gfx_bind_t>(
						pshd,
						gfx_bind_t::bufs_t{ },
						gfx_bind_t::txrs_t{ },
						gfx_bind_t::smps_t{ }
					);
					auto& gmtl = cmp_sys::get().new_ref<gfx_mtl_t>(gfx_mtl_t::bind_list_t{ vshd_bind, pshd_bind });
				}
			}
		}

		NC_CHECK(std_engine_t::init(), "init error!", return NC_FALSE);
		
		return NC_TRUTH;
	}
	v1bit_t nc_gfx_eng::quit()
	{
		
		NC_CHECK(std_engine_t::quit(), "quit error!", return NC_FALSE);
		
		m_context = context_t();
		
		return NC_TRUTH;
	}
	v1bit_t nc_gfx_eng::work()
	{

		gfx_context_state_t last_state;
		get_context().fmbuf_bind(GL_FRAMEBUFFER, NC_NULL);
		cmp_sys::get().get_ref<gfx_graph_t>(0u)->on_draw();
		m_context.update();
		get_context().fmbuf_clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		
		NC_CHECK(std_engine_t::work(), "work error!", return NC_FALSE);
		
		return NC_TRUTH;
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
namespace NC
{
	nc_gfx_eng::nc_gfx_eng(wndh window) :
		m_wndh(window),
		m_dvch(NC_NC_NULL),
		m_ctxh(NC_NC_NULL),
		m_viewport{ 0.0f, 0.0f, 800.0f, 600.0f },
		m_clear_color{ 1.0f, 1.0f, 1.0f, 1.0f },
		m_swap_delay(0u),
		m_prim(NC_PRIM_TRIANGLES),
		m_swap_chain(NC_NC_NULL),
		m_draw_target(NC_NC_NULL)
	{
		if (m_wndh == NC_NC_NULL) { throw init_error(__FILE__, __LINE__); return; }
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

		if (!gfx_library_t::get().load()) { throw init_error(__FILE__, __LINE__); return; }
		if (!gfx_library_t::get().init()) { throw init_error(__FILE__, __LINE__); return; }
		D3D11CreateDeviceAndSwapChain(
			NC_NC_NULL,
			D3D_DRIVER_TYPE_HARDWARE,
			NC_NC_NULL,
			D3D11_CREATE_DEVICE_DEBUG,
			NC_NC_NULL,
			0u,
			D3D11_SDK_VERSION,
			&swap_desc,
			&m_swap_chain,
			&m_dvch,
			NC_NC_NULL,
			&m_ctxh
		);
		if (m_dvch == NC_NC_NULL) { throw init_error(__FILE__, __LINE__); }
		if (m_ctxh == NC_NC_NULL) { throw init_error(__FILE__, __LINE__); }
		if (m_swap_chain == NC_NC_NULL) { throw init_error(__FILE__, __LINE__); }
		// configuration
		if constexpr (NC_TRUTH) {
			// other stuff
			if constexpr (NC_TRUTH) {
				set_swap_delay(0u);
				set_viewp(0, 0, 800, 600);
				set_fbuf_size(800, 600);
				set_clear_color(0.3f, 0.3f, 0.3f, 1.0f);
				set_prim(NC_PRIM_TRIANGLES);
			}
		}
	}
	nc_gfx_eng::~nc_gfx_eng()
	{
		if (m_draw_target != NC_NC_NULL) { m_draw_target->Release(); m_draw_target = NC_NC_NULL; }
		if (m_swap_chain != NC_NC_NULL) { m_swap_chain->Release(); m_swap_chain = NC_NC_NULL; }
		if (m_dvch != NC_NC_NULL) { m_dvch->Release(); m_dvch = NC_NC_NULL; }
		if (m_ctxh != NC_NC_NULL) { m_ctxh->Release(); m_ctxh = NC_NC_NULL; }
		
		m_ent_reg.clear();
		m_cmp_reg.clear();
	}
<<<<<<< HEAD
	/* setters */
	v1nil_t nc_gfx_eng::set_fmbuf_size(v1u_t size_x, v1u_t size_y) {
=======
	// -- setters
	v1nil_t nc_gfx_eng::set_fbuf_size(v1u_t size_x, v1u_t size_y) {
>>>>>>> 5ec48b78bf51cdaf84eb36840c5ed9ec4bcddd88
		if (m_draw_target != NC_NC_NULL) { m_draw_target->Release(); m_draw_target = NC_NC_NULL; }
		
		m_ctxh->OMSetRenderTargets(0u, NC_NC_NULL, NC_NC_NULL);
		ID3D11Resource* back_buf = NC_NC_NULL;
		m_swap_chain->ResizeBuffers(1u, size_x, size_y, DXGI_FORMAT_UNKNOWN, 0u);
		m_swap_chain->GetBuffer(0u, __uuidof(ID3D11Resource), reinterpret_cast<ptr*>(&back_buf));
		m_dvch->CreateRenderTargetView(back_buf, NC_NC_NULL, &m_draw_target);
		back_buf->Release();
		if (m_draw_target == NC_NC_NULL) { throw init_error(__FILE__, __LINE__); return; }
		
		m_ctxh->OMSetRenderTargets(1u, &m_draw_target, NC_NC_NULL);
	}
	v1nil_t nc_gfx_eng::set_viewp(v4f_t viewport) {
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
	v1nil_t nc_gfx_eng::set_viewp(v1f_t crd_x, v1f_t crd_y, v1f_t size_x, v1f_t size_y) {
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
	v1nil_t nc_gfx_eng::set_clear_color(v4f_t clear_color) {
		m_clear_color = clear_color;
	};
	v1nil_t nc_gfx_eng::set_clear_color(v1f_t red, v1f_t green, v1f_t blue, v1f_t alpha) {
		m_clear_color[0] = red;
		m_clear_color[1] = green;
		m_clear_color[2] = blue;
		m_clear_color[3] = alpha;
	};
	v1nil_t nc_gfx_eng::set_swap_delay(v1u_t swap_delay) {
		m_swap_delay = swap_delay;
	}
	v1nil_t nc_gfx_eng::set_prim(prim primitive) {
		m_prim = convert<primitives, prim>(primitive);
		m_ctxh->IASetPrimitiveTopology(convert<primitives, D3D11_PRIMITIVE_TOPOLOGY>(primitive));
	}
	/* commands */
<<<<<<< HEAD
	v1bit_t nc_gfx_eng::init()
	{
		if constexpr (NC_TRUTH) {
			if (m_libh != NC_NULL) { return NC_FALSE; }
			m_libh = ::LoadLibrary("d3d11.dll");
			if (m_libh_dxcomp != NC_NULL) { return NC_FALSE; }
			m_libh_dxcomp = ::LoadLibrary(D3DCOMPILER_DLL);
			if (m_libh_dxgi != NC_NULL) { return NC_FALSE; }
			m_libh_dxgi = ::LoadLibrary("dxgi.dll");
			NC_CHECK(gfx_load_wapi(), "failed load!", return NC_FALSE);
		}
		return NC_TRUTH;
	}
	v1bit_t nc_gfx_eng::quit()
=======
	v1nil_t nc_gfx_eng::update()
	{
		HRESULT h_result;
		if ((h_result = m_swap_chain->Present(m_swap_delay, 0u)) != S_OK) { throw(run_error("something went wrong")); return; }
		m_ctxh->ClearRenderTargetView(m_draw_target, &m_clear_color[0]);
	}
	v1nil_t nc_gfx_eng::draw_vtx(gfx_buf_vtx_t* buffer)
	{
		m_ctxh->Draw(buffer->get_count(), buffer->get_offset() / buffer->get_stride());
	}
	v1nil_t nc_gfx_eng::draw_vtx(v1u_t buffer_id)
>>>>>>> 5ec48b78bf51cdaf84eb36840c5ed9ec4bcddd88
	{
		if constexpr (NC_TRUTH) {
			if (m_libh == NC_NULL) { return NC_FALSE; }
			::FreeLibrary(m_libh);
			m_libh = NC_NULL;
			if (m_libh_dxcomp == NC_NULL) { return NC_FALSE; }
			::FreeLibrary(m_libh_dxcomp);
			m_libh_dxcomp = NC_NULL;
			if (m_libh_dxgi == NC_NULL) { return NC_FALSE; }
			::FreeLibrary(m_libh_dxgi);
			m_libh_dxgi = NC_NULL;
		}
		return NC_TRUTH;
	}
<<<<<<< HEAD
	v1nil_t nc_gfx_eng::update()
=======
	v1nil_t nc_gfx_eng::draw_idx(gfx_buf_idx_t* buffer)
>>>>>>> 5ec48b78bf51cdaf84eb36840c5ed9ec4bcddd88
	{
		HRESULT h_result;
		if ((h_result = m_swap_chain->Present(m_swap_delay, 0u)) != S_OK) { throw(run_error("something went wrong")); return; }
		m_ctxh->ClearRenderTargetView(m_draw_target, &m_clear_color[0]);
	}
<<<<<<< HEAD
	ptr_t nc_gfx_eng::get_proc(cstr_t name)
=======
	v1nil_t nc_gfx_eng::draw_idx(v1u_t buffer_id)
>>>>>>> 5ec48b78bf51cdaf84eb36840c5ed9ec4bcddd88
	{
		ptr_t resource = NC_NULL;
		if (resource == NC_NULL) {
			resource = ::GetProcAddress(m_libh_dxcomp, name);
		}
		if (resource == NC_NULL) {
			resource = ::GetProcAddress(m_libh_dxgi, name);
		}
		return resource;
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NC_GAPI