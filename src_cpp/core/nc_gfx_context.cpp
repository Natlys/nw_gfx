#include "nc_gfx_pch.hpp"
#include "nc_gfx_context.hxx"
#if (defined NC_GAPI)
#	if (NC_GAPI & NC_GAPI_OGL)
#	include "../lib/nc_gfx_lib_core.hxx"
namespace NC
{
	gfx_context_t::gfx_context_t() :
		mem_user_t(),
		m_handle(NC_NULL),
		m_device(NC_NULL),
		m_window(NC_NULL),
		m_loader(loader_t()),
		m_drawer(NC_VOID_STR),
		m_vendor(NC_VOID_STR),
		m_shd_lang(NC_VOID_STR),
		m_max_slot_atb(NC_VOID_VAL),
		m_max_slot_txr(NC_VOID_VAL),
		m_pxl_gran(NC_VOID_VAL),
		m_pxl_range(NC_VOID_VAL),
		set_point_size(NC_VOID_VAL)
	{
	}
	gfx_context_t::gfx_context_t(window_t window) : gfx_context_t() { NC_CHECK(remake(window), "remake error!", return); }
	gfx_context_t::~gfx_context_t()
	{
		if (has_handle() && has_device()) {
			wglMakeContextCurrent(NC_NULL, NC_NULL);
			::ReleaseDC(m_window, m_device);
			wglDeleteContext(m_handle);
			m_handle = NC_NULL;
			m_device = NC_NULL;
		}
	}
	/* setters */
	gfx_context_t::context_t& gfx_context_t::set_window(window_t& window) { m_window = window; return *this; }
	/* commands */
	v1bit_t gfx_context_t::remake()
	{
		NC_CHECK(has_window(), "no window!", return NC_FALSE);
		
		// only one context can be used in a single thread at one time;
		if constexpr (NC_TRUTH) {
			if (has_handle() && has_device()) {
				wglMakeContextCurrent(NC_NULL, NC_NULL);
				::ReleaseDC(m_window, m_device);
				wglDeleteContext(m_handle);
				m_handle = NC_NULL;
				m_device = NC_NULL;
			}
			// get device context of the window;
			m_device = ::GetWindowDC(m_window);
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
			v1s_t pxl_format = ::ChoosePixelFormat(m_device, &pxf_desc);
			NC_CHECK(pxl_format != NC_NULL, "no pixel format!", return NC_FALSE);
			// pixel format can be set to some window only once
			NC_CHECK(::SetPixelFormat(m_device, pxl_format, &pxf_desc), "pixel format is not set!", return NC_FALSE);
			::DescribePixelFormat(m_device, pxl_format, pxf_desc.nSize, &pxf_desc);
		}
		// create opengl context and associate that with the device context;
		// it will be attached to the current thread and device context;
		// this is only one current context we can use;
		if constexpr (NC_TRUTH) {
			m_handle = wglCreateContext(m_device);
			wglMakeContextCurrent(m_device, m_handle);
			// --core
			if constexpr (NC_TRUTH) {
				/* getters */
				get_int = (pfn_gfx_get_int)m_loader.get_proc("glGetIntegerv");
				get_str = (pfn_gfx_get_str)m_loader.get_proc("glGetString");
				get_err = (pfn_gfx_get_err)m_loader.get_proc("glGetError");
				/* setters */
				set_enabled = (pfn_gfx_set_enabled)m_loader.get_proc("glEnable");
				set_disabled = (pfn_gfx_set_disabled)m_loader.get_proc("glDisable");
				/* vetters */
				is_enabled = (pfn_gfx_is_enabled)m_loader.get_proc("glIsEnabled");
				is_shader = (pfn_gfx_is_shader)m_loader.get_proc("glIsShader");
				/* commands */
				draw_vtx = (pfn_gfx_draw_vtx)m_loader.get_proc("glDrawArrays");
				draw_idx = (pfn_gfx_draw_idx)m_loader.get_proc("glDrawElements");
				clear_error = (pfn_gfx_clear_error)(m_loader.get_proc("glClearError"));
				if constexpr (NC_TRUTH) { // information
					v1s_t version_nums[2]{ NC_NULL };
					get_int(GL_MAJOR_VERSION, &version_nums[0]);
					get_int(GL_MINOR_VERSION, &version_nums[1]);
					//m_ver_num = (version_nums[0] * 100) + (version_nums[1] * 10);
					//m_ver_str = reinterpret_cast<cstr_t>(glGetString(GL_VERSION));
					//m_ext_str = reinterpret_cast<cstr_t>(glGetString(GL_EXTENSIONS));
				}
			}
			// --rasterizer
			if constexpr (NC_TRUTH) {
				/* setters */
				set_line_width = (pfn_gfx_rastr_set_line_width)m_loader.get_proc("glLineWidth");
				set_point_size = (pfn_gfx_rastr_set_point_size)m_loader.get_proc("glPointSize");
				set_viewp = (pfn_gfx_rastr_set_viewp)m_loader.get_proc("glViewport");
				set_sciss = (pfn_gfx_rastr_set_sciss)m_loader.get_proc("glScissor");
				set_cull = (pfn_gfx_rastr_set_cull)m_loader.get_proc("glPolygonMode");
				set_fill = (pfn_gfx_rastr_set_fill)m_loader.get_proc("glPolygonMode");
			}
			// --blending
			if constexpr (NC_TRUTH) {
				/* setters */
				set_blend_equation = (pfn_gfx_blend_set_equation)m_loader.get_proc("glBlendEquation");
				set_blend_equation_separate = (pfn_gfx_blend_set_equation_separate)m_loader.get_proc("glBlendEquationSeparate");
				set_blend_function = (pfn_gfx_blend_set_function)m_loader.get_proc("glBlendFunc");
				set_blend_function_separate = (pfn_gfx_blend_set_function_separate)m_loader.get_proc("glBlendFuncSeparate");
			}
			// --depth_stencil
			if constexpr (NC_TRUTH) {
				/* setters */
				set_depth_mask = (pfn_gfx_depth_set_mask)m_loader.get_proc("glDepthMask");
				set_depth_func = (pfn_gfx_depth_set_func)m_loader.get_proc("glDepthFunc");
				set_stenc_mask = (pfn_gfx_stenc_set_mask)m_loader.get_proc("glStencilMask");
				set_stenc_func = (pfn_gfx_stenc_set_func)m_loader.get_proc("glStencilFunc");
			}
			// --buffer
			if constexpr (NC_TRUTH) {
				// --core
				buf_new = (pfn_gfx_buf_gen)(m_loader.get_proc("glGenBuffers"));
				buf_del = (pfn_gfx_buf_del)(m_loader.get_proc("glDeleteBuffers"));
				buf_bind = (pfn_gfx_buf_bind)(m_loader.get_proc("glBindBuffer"));
				buf_bind_rang = (pfn_gfx_buf_bind_rang)(m_loader.get_proc("glBindBufferRange"));
				buf_bind_base = (pfn_gfx_buf_bind_base)(m_loader.get_proc("glBindBufferBase"));
				buf_bind_vert = (pfn_gfx_buf_bind_vert)(m_loader.get_proc("glBindBufferBase"));
				/* setters */
				buf_set_data = (pfn_gfx_buf_set_data)(m_loader.get_proc("glBufferData"));
				buf_set_sub_data = (pfn_gfx_buf_set_sub_data)(m_loader.get_proc("glBufferSubData"));
			}
			// --layout
			if constexpr (NC_TRUTH) {
				// --core
				layt_new = (pfn_gfx_layt_gen)(m_loader.get_proc("glGenVertexArrays"));
				layt_del = (pfn_gfx_layt_del)(m_loader.get_proc("glDeleteVertexArrays"));
				layt_bind = (pfn_gfx_layt_bind)(m_loader.get_proc("glBindVertexArray"));
				/* setters */
				layt_set_atb = (pfn_gfx_layt_set_atb)(m_loader.get_proc("glVertexAttribPointer"));
				layt_set_enabled = (pfn_gfx_layt_set_enabled)(m_loader.get_proc("glEnableVertexAttribArray"));
				layt_set_disabled = (pfn_gfx_layt_set_disabled)(m_loader.get_proc("glEnableVertexAttribArray"));
			}
			// --texture
			if constexpr (NC_TRUTH) {
				// --general
				txr_new = (pfn_gfx_txr_new)(m_loader.get_proc("glGenTextures"));
				txr_new_mipmap = (pfn_gfx_txr_new_mipmap)(m_loader.get_proc("glGenerateMipmap"));
				txr_del = (pfn_gfx_txr_del)(m_loader.get_proc("glGenTextures"));
				txr_bind = (pfn_gfx_txr_bind)(m_loader.get_proc("glBindTexture"));
				txr_active = (pfn_gfx_txr_active)(m_loader.get_proc("glActiveTexture"));
				txr_clear = (pfn_gfx_txr_clear)(m_loader.get_proc("glClearTexImage"));
				/* setters */
				txr_set_image_1d = (pfn_gfx_txr_set_image_1d)(m_loader.get_proc("glTexImage1D"));
				txr_set_image_2d = (pfn_gfx_txr_set_image_2d)(m_loader.get_proc("glTexImage2D"));
				txr_set_image_3d = (pfn_gfx_txr_set_image_3d)(m_loader.get_proc("glTexImage3D"));
				txr_set_image_2d_mulsmp = (pfn_gfx_txr_set_image_2d_mulsmp)(m_loader.get_proc("glTexImage2DMultisample"));
				txr_set_image_3d_mulsmp = (pfn_gfx_txr_set_image_3d_mulsmp)(m_loader.get_proc("glTexImage3DMultisample"));
				txr_set_param_n1s = (pfn_gfx_txr_set_param_n1s)(m_loader.get_proc("glTexParameteri"));
				txr_set_param_v1s = (pfn_gfx_txr_set_param_v1s)(m_loader.get_proc("glTexParameteriv"));
				txr_set_param_n1f = (pfn_gfx_txr_set_param_n1f)(m_loader.get_proc("glTexParameterf"));
				txr_set_param_v1f = (pfn_gfx_txr_set_param_v1f)(m_loader.get_proc("glTexParameterfv"));
			}
			// --samplers
			if constexpr (NC_TRUTH) {
				// --core
				smp_new = (pfn_gfx_smp_gen)(m_loader.get_proc("glGenSamplers"));
				smp_del = (pfn_gfx_smp_del)(m_loader.get_proc("glDeleteSamplers"));
				smp_bind = (pfn_gfx_smp_bind)(m_loader.get_proc("glBindSampler"));
				/* setters */
				smp_set_param_n1s = (pfn_gfx_smp_set_param_n1s)(m_loader.get_proc("glSamplerParameteri"));
				smp_set_param_v1s = (pfn_gfx_smp_set_param_v1s)(m_loader.get_proc("glSamplerParameteriv"));
				smp_set_param_n1f = (pfn_gfx_smp_set_param_n1f)(m_loader.get_proc("glSamplerParameterf"));
				smp_set_param_v1f = (pfn_gfx_smp_set_param_v1f)(m_loader.get_proc("glSamplerParameterfv"));
			}
			// shaders
			if constexpr (NC_TRUTH) {
				// --core
				shd_new = (pfn_gfx_shd_new)m_loader.get_proc("glCreateShader");
				shd_del = (pfn_gfx_shd_del)m_loader.get_proc("glDeleteShader");
				shd_remake = (pfn_gfx_shd_remake)m_loader.get_proc("glCompileShader");
				/* getters */
				shd_get_v1s = (pfn_gfx_shd_get_v1s)m_loader.get_proc("glGetShaderiv");
				shd_get_info_log = (pfn_gfx_shd_get_info_log)m_loader.get_proc("glGetShaderInfoLog");
				/* setters */
				shd_set_source = (pfn_gfx_shd_set_source)m_loader.get_proc("glShaderSource");
			}
			if constexpr (NC_TRUTH) { // materials
				// --core
				mtl_new = (pfn_gfx_mtl_new)(m_loader.get_proc("glCreateProgram"));
				mtl_del = (pfn_gfx_mtl_del)(m_loader.get_proc("glDeleteProgram"));
				mtl_bind = (pfn_gfx_mtl_bind)(m_loader.get_proc("glUseProgram"));
				mtl_remake = (pfn_gfx_mtl_remake)(m_loader.get_proc("glLinkProgram"));
				/* getters */
				mtl_get_iv = (pfn_gfx_mtl_get_iv)(m_loader.get_proc("glGetProgramiv"));
				mtl_get_info_log = (pfn_gfx_mtl_get_info_log)(m_loader.get_proc("glGetProgramInfoLog"));
				mtl_get_loc_atb = (pfn_gfx_mtl_get_loc_atb)(m_loader.get_proc("glGetAttribLocation"));
				mtl_get_loc_unf = (pfn_gfx_mtl_get_loc_unf)(m_loader.get_proc("glGetUniformLocation"));
				/* setters */
				mtl_add_shader = (pfn_gfx_mtl_add_shd)(m_loader.get_proc("glAttachShader"));
				mtl_rmv_shader = (pfn_gfx_mtl_rmv_shd)(m_loader.get_proc("glDetachShader"));
				// // --uniforms
				mtl_set_n1s = (pfn_gfx_mtl_set_n1s)(m_loader.get_proc("glUniform1i"));
				mtl_set_n2s = (pfn_gfx_mtl_set_n2s)(m_loader.get_proc("glUniform2i"));
				mtl_set_n3s = (pfn_gfx_mtl_set_n3s)(m_loader.get_proc("glUniform3i"));
				mtl_set_n4s = (pfn_gfx_mtl_set_n4s)(m_loader.get_proc("glUniform4i"));
				mtl_set_v1s = (pfn_gfx_mtl_set_v1s)(m_loader.get_proc("glUniform1iv"));
				mtl_set_v2s = (pfn_gfx_mtl_set_v2s)(m_loader.get_proc("glUniform2iv"));
				mtl_set_v3s = (pfn_gfx_mtl_set_v3s)(m_loader.get_proc("glUniform3iv"));
				mtl_set_v4s = (pfn_gfx_mtl_set_v4s)(m_loader.get_proc("glUniform4iv"));
				mtl_set_n1u = (pfn_gfx_mtl_set_n1u)(m_loader.get_proc("glUniform1ui"));
				mtl_set_n2u = (pfn_gfx_mtl_set_n2u)(m_loader.get_proc("glUniform2ui"));
				mtl_set_n3u = (pfn_gfx_mtl_set_n3u)(m_loader.get_proc("glUniform3ui"));
				mtl_set_n4u = (pfn_gfx_mtl_set_n4u)(m_loader.get_proc("glUniform4ui"));
				mtl_set_v1u = (pfn_gfx_mtl_set_v1u)(m_loader.get_proc("glUniform1uiv"));
				mtl_set_v2u = (pfn_gfx_mtl_set_v2u)(m_loader.get_proc("glUniform2uiv"));
				mtl_set_v3u = (pfn_gfx_mtl_set_v3u)(m_loader.get_proc("glUniform3uiv"));
				mtl_set_v4u = (pfn_gfx_mtl_set_v4u)(m_loader.get_proc("glUniform4uiv"));
				mtl_set_n1f = (pfn_gfx_mtl_set_n1f)(m_loader.get_proc("glUniform1f"));
				mtl_set_n2f = (pfn_gfx_mtl_set_n2f)(m_loader.get_proc("glUniform2f"));
				mtl_set_n3f = (pfn_gfx_mtl_set_n3f)(m_loader.get_proc("glUniform3f"));
				mtl_set_n4f = (pfn_gfx_mtl_set_n4f)(m_loader.get_proc("glUniform4f"));
				mtl_set_v1f = (pfn_gfx_mtl_set_v1f)(m_loader.get_proc("glUniform1fv"));
				mtl_set_v2f = (pfn_gfx_mtl_set_v2f)(m_loader.get_proc("glUniform2fv"));
				mtl_set_v3f = (pfn_gfx_mtl_set_v3f)(m_loader.get_proc("glUniform3fv"));
				mtl_set_v4f = (pfn_gfx_mtl_set_v4f)(m_loader.get_proc("glUniform4fv"));
				mtl_set_m2f = (pfn_gfx_mtl_set_m2f)(m_loader.get_proc("glUniformMatrix2fv"));
				mtl_set_m3f = (pfn_gfx_mtl_set_m3f)(m_loader.get_proc("glUniformMatrix3fv"));
				mtl_set_m4f = (pfn_gfx_mtl_set_m4f)(m_loader.get_proc("glUniformMatrix4fv"));
				mtl_set_bind = (pfn_gfx_mtl_set_bind)(m_loader.get_proc("glUniformBlockBinding"));
			}
			if constexpr (NC_TRUTH) { // framebuffer
				// --core
				fmbuf_new = (pfn_gfx_fmbuf_new)m_loader.get_proc("glGenFramebuffers");
				fmbuf_del = (pfn_gfx_fmbuf_del)m_loader.get_proc("glDeleteFramebuffers");
				fmbuf_bind = (pfn_gfx_fmbuf_bind)m_loader.get_proc("glBindFramebuffer");
				fmbuf_set_draw = (pfn_gfx_fmbuf_bind_draw)m_loader.get_proc("glDrawBuffer");
				fmbuf_set_read = (pfn_gfx_fmbuf_bind_read)m_loader.get_proc("glReadBuffer");
				fmbuf_set_draws = (pfn_gfx_fmbuf_bind_draws)m_loader.get_proc("glDrawBuffers");
				fmbuf_set_reads = (pfn_gfx_fmbuf_bind_reads)m_loader.get_proc("glReadBuffers");
				fmbuf_draw = (pfn_gfx_fmbuf_draw)m_loader.get_proc("glDrawPixels");
				fmbuf_read = (pfn_gfx_fmbuf_read)m_loader.get_proc("glReadPixels");
				fmbuf_clear = (pfn_gfx_fmbuf_clear)m_loader.get_proc("glClear");
				/* getters */
				fmbuf_get_status = (pfn_gfx_fmbuf_get_status)(m_loader.get_proc("glCheckFramebufferStatus"));
				/* setters */
				fmbuf_set_txr_1d = (pfn_gfx_fmbuf_set_txr_1d)m_loader.get_proc("glFramebufferTexture1D");
				fmbuf_set_txr_2d = (pfn_gfx_fmbuf_set_txr_2d)m_loader.get_proc("glFramebufferTexture2D");
				fmbuf_set_txr_3d = (pfn_gfx_fmbuf_set_txr_3d)m_loader.get_proc("glFramebufferTexture3D");
				fmbuf_set_color = (pfn_gfx_fmbuf_set_color)m_loader.get_proc("glClearColor");
			}
			if constexpr (NC_TRUTH) { // extensions
				wglGetExtensionsStringEXT = (pfn_gfx_ext_get_str)(m_loader.get_proc("wglGetExtensionsStringEXT"));
				if (m_loader.has_support("WGL_EXT_swap_control")) {
					wglGetSwapIntervalEXT = (pfn_gfx_ext_get_vsync)(m_loader.get_proc("wglGetSwapIntervalEXT"));
					wglSwapIntervalEXT = (pfn_gfx_ext_set_vsync)(m_loader.get_proc("wglSwapIntervalEXT"));
				}
			}
		}
		if constexpr (NC_TRUTH) { // information
			m_drawer = reinterpret_cast<cstr_t>(get_str(GL_RENDERER));
			m_vendor = reinterpret_cast<cstr_t>(get_str(GL_VENDOR));
			m_shd_lang = reinterpret_cast<cstr_t>(get_str(GL_SHADING_LANGUAGE_VERSION));
			get_int(GL_POINT_SIZE_RANGE, &m_pxl_range);
			get_int(GL_POINT_SIZE_GRANULARITY, &m_pxl_gran);
			get_int(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &m_max_slot_txr);
			get_int(GL_MAX_VERTEX_ATTRIB_BINDINGS, &m_max_slot_atb);
		}

		return NC_TRUTH;
	}
	v1bit_t gfx_context_t::update()
	{
		::SwapBuffers(m_device);
		
		return NC_TRUTH;
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
#	include "dxgi.hxx"
#	include "d3dcompiler.hxx"
namespace NC
{
	//
}
#	endif	// GAPI_D3D
#endif	// NC_GAPI