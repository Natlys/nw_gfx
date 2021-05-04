#include "nw_gfx_pch.hpp"
#include "nw_gfx_context.h"
#if (defined NW_GAPI)
#	if (NW_GAPI & NW_GAPI_OGL)
#	include "../lib/nw_gfx_lib_txr.h"
#	include "../lib/nw_gfx_lib_shd.h"
#	include "../lib/nw_gfx_lib_layt.h"
#	include "../lib/nw_gfx_lib_core.h"
namespace NW
{
	gfx_context::gfx_context() :
		a_mem_user(),
		m_handle(NW_NULL),
		m_device(NW_NULL),
		m_window(NW_NULL),
		m_loader(loader_t()),
		m_drawer(NW_DEFAULT_STR),
		m_vendor(NW_DEFAULT_STR),
		m_shd_lang(NW_DEFAULT_STR),
		m_max_slot_atb(NW_DEFAULT_VAL),
		m_max_slot_txr(NW_DEFAULT_VAL),
		m_pxl_gran(NW_DEFAULT_VAL),
		m_pxl_range(NW_DEFAULT_VAL),
		set_point_size(NW_DEFAULT_VAL)
	{
	}
	gfx_context::gfx_context(window_t window) :
		gfx_context()
	{
		NW_CHECK(remake(window), "remake error!", return);
	}
	gfx_context::~gfx_context()
	{
		if (has_handle() && has_device()) {
			wglMakeContextCurrent(NW_NULL, NW_NULL);
			::ReleaseDC(m_window, m_device);
			wglDeleteContext(m_handle);
			m_handle = NW_NULL;
			m_device = NW_NULL;
		}
	}
	// --setters
	v1nil gfx_context::set_window(window_t& window) {
		m_window = window;
	}
	// --==<core_methods>==--
	v1bit gfx_context::remake()
	{
		NW_CHECK(has_window(), "no window!", return NW_FALSE);
		
		// only one context can be used in a single thread at one time;
		if constexpr (NW_TRUE) {
			if (has_handle() && has_device()) {
				wglMakeContextCurrent(NW_NULL, NW_NULL);
				::ReleaseDC(m_window, m_device);
				wglDeleteContext(m_handle);
				m_handle = NW_NULL;
				m_device = NW_NULL;
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
			v1s pxl_format = ::ChoosePixelFormat(m_device, &pxf_desc);
			NW_CHECK(pxl_format != NW_NULL, "no pixel format!", return NW_FALSE);
			// pixel format can be set to some window only once
			NW_CHECK(::SetPixelFormat(m_device, pxl_format, &pxf_desc), "pixel format is not set!", return NW_FALSE);
			::DescribePixelFormat(m_device, pxl_format, pxf_desc.nSize, &pxf_desc);
		}
		// create opengl context and associate that with the device context;
		// it will be attached to the current thread and device context;
		// this is only one current context we can use;
		if constexpr (NW_TRUE) {
			m_handle = wglCreateContext(m_device);
			wglMakeContextCurrent(m_device, m_handle);
			NW_CHECK(m_loader.load(), "failed load!", return NW_FALSE);
#		if (NW_FALSE)
			if constexpr (NW_TRUE) { // core
				// getters
				get_int = (pfn_gfx_get_int_v)m_loader.get_proc("glGetIntegerv");
				get_str = (pfn_gfx_get_string)m_loader.get_proc("glGetString");
				glGetError = (pfn_gfx_get_error)m_loader.get_proc("glGetError");
				// predicates
				glIsEnabled = (pfn_gfx_is_enabled)m_loader.get_proc("glIsEnabled");
				// drawing
				glDrawArrays = (pfn_gfx_draw_vtx)m_loader.get_proc("glDrawArrays");
				glDrawElements = (pfn_gfx_draw_idx)m_loader.get_proc("glDrawElements");
				// configs
				glLineWidth = (pfn_gfx_line_width)m_loader.get_proc("glLineWidth");
				glPointSize = (pfn_gfx_point_size)m_loader.get_proc("glPointSize");
				glViewport = (pfn_gfx_viewport)m_loader.get_proc("glViewport");
				glScissor = (pfn_gfx_scissor)m_loader.get_proc("glScissor");
				glEnable = (pfn_gfx_enable)m_loader.get_proc("glEnable");
				glDisable = (pfn_gfx_disable)m_loader.get_proc("glDisable");
				glBlendEquation = (pfn_gfx_blend_equation)m_loader.get_proc("glBlendEquation");
				glBlendEquationSeparate = (pfn_gfx_blend_equation_separate)m_loader.get_proc("glBlendEquationSeparate");
				glBlendFunc = (pfn_gfx_blend_function)m_loader.get_proc("glBlendFunc");
				glBlendFuncSeparate = (pfn_gfx_blend_function_separate)m_loader.get_proc("glBlendFuncSeparate");
				glDepthMask = (pfn_gfx_depth_mask)m_loader.get_proc("glDepthMask");
				glDepthFunc = (pfn_gfx_depth_func)m_loader.get_proc("glDepthFunc");
				glPolygonMode = (pfn_gfx_polygon_mode)m_loader.get_proc("glPolygonMode");
				// other
				glClearError = (pfn_gfx_clear_error)(m_loader.get_proc("glClearError"));
				if constexpr (NW_TRUE) { // information
					v1s version_nums[2]{ NW_NULL };
					glGetIntegerv(GL_MAJOR_VERSION, &version_nums[0]);
					glGetIntegerv(GL_MINOR_VERSION, &version_nums[1]);
					m_ver_num = (version_nums[0] * 100) + (version_nums[1] * 10);
					m_ver_str = reinterpret_cast<cstr_t>(glGetString(GL_VERSION));
					//m_ext_str = reinterpret_cast<cstr_t>(glGetString(GL_EXTENSIONS));
				}
			}
			if constexpr (NW_TRUE) { // buffers
				// general
				glGenBuffers = (pfn_gfx_buf_gen)(m_loader.get_proc("glGenBuffers"));
				glDeleteBuffers = (pfn_gfx_buf_del)(m_loader.get_proc("glDeleteBuffers"));
				glBindBuffer = (pfn_gfx_buf_bind)(m_loader.get_proc("glBindBuffer"));
				glBindBufferRange = (pfn_gfx_buf_bind_range)(m_loader.get_proc("glBindBufferRange"));
				glBindBufferBase = (pfn_gfx_buf_bind_base)(m_loader.get_proc("glBindBufferBase"));
				// data
				glBufferData = (pfn_gfx_buf_data)(m_loader.get_proc("glBufferData"));
				glBufferSubData = (pfn_gfx_buf_sub_data)(m_loader.get_proc("glBufferSubData"));
			}
			if constexpr (NW_TRUE) { // layouts
				// general
				glGenVertexArrays = (pfn_gfx_layt_gen)(m_loader.get_proc("glGenVertexArrays"));
				glDeleteVertexArrays = (pfn_gfx_layt_del)(m_loader.get_proc("glDeleteVertexArrays"));
				glBindVertexArray = (pfn_gfx_layt_bind)(m_loader.get_proc("glBindVertexArray"));
				// data
				glEnableVertexAttribArray = (pfn_gfx_layt_enable_atb)(m_loader.get_proc("glEnableVertexAttribArray"));
				glDisableVertexAttribArray = (pfn_gfx_layt_disable_atb)(m_loader.get_proc("glEnableVertexAttribArray"));
				glVertexAttribPointer = (pfn_gfx_layt_set_atb)(m_loader.get_proc("glVertexAttribPointer"));
			}
			if constexpr (NW_TRUE) { // textures
				// general
				glGenTextures = (pfn_gfx_txr_gen)(m_loader.get_proc("glGenTextures"));
				glDeleteTextures = (pfn_gfx_txr_del)(m_loader.get_proc("glGenTextures"));
				glBindTexture = (pfn_gfx_txr_bind)(m_loader.get_proc("glBindTexture"));
				glActiveTexture = (pfn_gfx_txr_active)(m_loader.get_proc("glActiveTexture"));
				glGenerateMipmap = (pfn_gfx_txr_mipmap_gen)(m_loader.get_proc("glGenerateMipmap"));
				glTexImage1D = (pfn_gfx_txr_img_1d)(m_loader.get_proc("glTexImage1D"));
				glTexImage2D = (pfn_gfx_txr_img_2d)(m_loader.get_proc("glTexImage2D"));
				glTexImage3D = (pfn_gfx_txr_img_3d)(m_loader.get_proc("glTexImage3D"));
				glTexImage2DMultisample = (pfn_gfx_txr_img_2d_mulsmp)(m_loader.get_proc("glTexImage2DMultisample"));
				glTexImage3DMultisample = (pfn_gfx_txr_img_3d_mulsmp)(m_loader.get_proc("glTexImage3DMultisample"));
				// params
				glTexParameteri = (pfn_gfx_txr_param_i)(m_loader.get_proc("glTexParameteri"));
				glTexParameteriv = (pfn_gfx_txr_param_vi)(m_loader.get_proc("glTexParameteriv"));
				glTexParameterf = (pfn_gfx_txr_param_f)(m_loader.get_proc("glTexParameterf"));
				glTexParameterfv = (pfn_gfx_txr_param_vf)(m_loader.get_proc("glTexParameterfv"));
				// other
				glClearTexImage = (pfn_gfx_txr_img_clear)(m_loader.get_proc("glClearTexImage"));
			}
			if constexpr (NW_TRUE) { // materials
			// general
				glCreateProgram = (pfn_gfx_mtl_crt)(m_loader.get_proc("glCreateProgram"));
				glDeleteProgram = (pfn_gfx_mtl_del)(m_loader.get_proc("glDeleteProgram"));
				glUseProgram = (pfn_gfx_mtl_use)(m_loader.get_proc("glUseProgram"));
				glAttachShader = (pfn_gfx_mtl_attach_shd)(m_loader.get_proc("glAttachShader"));
				glDetachShader = (pfn_gfx_mtl_detach_shd)(m_loader.get_proc("glDetachShader"));
				glLinkProgram = (pfn_gfx_mtl_link_shds)(m_loader.get_proc("glLinkProgram"));
				// getters
				glGetAttribLocation = (pfn_gfx_mtl_get_loc_atb)(m_loader.get_proc("glGetAttribLocation"));
				glGetUniformLocation = (pfn_gfx_mtl_get_loc_unf)(m_loader.get_proc("glGetUniformLocation"));
				glGetProgramiv = (pfn_gfx_mtl_get_iv)(m_loader.get_proc("glGetProgramiv"));
				glGetProgramInfoLog = (pfn_gfx_mtl_get_info_log)(m_loader.get_proc("glGetProgramInfoLog"));
				// uniforms
				glUniform1i = (pfn_gfx_mtl_unf_1si32)(m_loader.get_proc("glUniform1i"));
				glUniform2i = (pfn_gfx_mtl_unf_2si32)(m_loader.get_proc("glUniform2i"));
				glUniform3i = (pfn_gfx_mtl_unf_3si32)(m_loader.get_proc("glUniform3i"));
				glUniform4i = (pfn_gfx_mtl_unf_4si32)(m_loader.get_proc("glUniform4i"));
				glUniform1iv = (pfn_gfx_mtl_unf_v1s32)(m_loader.get_proc("glUniform1iv"));
				glUniform2iv = (pfn_gfx_mtl_unf_v2s32)(m_loader.get_proc("glUniform2iv"));
				glUniform3iv = (pfn_gfx_mtl_unf_v3s32)(m_loader.get_proc("glUniform3iv"));
				glUniform4iv = (pfn_gfx_mtl_unf_v4s32)(m_loader.get_proc("glUniform4iv"));
				glUniform1ui = (pfn_gfx_mtl_unf_1ui32)(m_loader.get_proc("glUniform1ui"));
				glUniform2ui = (pfn_gfx_mtl_unf_2ui32)(m_loader.get_proc("glUniform2ui"));
				glUniform3ui = (pfn_gfx_mtl_unf_3ui32)(m_loader.get_proc("glUniform3ui"));
				glUniform4ui = (pfn_gfx_mtl_unf_4ui32)(m_loader.get_proc("glUniform4ui"));
				glUniform1uiv = (pfn_gfx_mtl_unf_v1u32)(m_loader.get_proc("glUniform1uiv"));
				glUniform2uiv = (pfn_gfx_mtl_unf_v2u32)(m_loader.get_proc("glUniform2uiv"));
				glUniform3uiv = (pfn_gfx_mtl_unf_v3u32)(m_loader.get_proc("glUniform3uiv"));
				glUniform4uiv = (pfn_gfx_mtl_unf_v4u32)(m_loader.get_proc("glUniform4uiv"));
				glUniform1f = (pfn_gfx_mtl_unf_1f32)(m_loader.get_proc("glUniform1f"));
				glUniform2f = (pfn_gfx_mtl_unf_2f32)(m_loader.get_proc("glUniform2f"));
				glUniform3f = (pfn_gfx_mtl_unf_3f32)(m_loader.get_proc("glUniform3f"));
				glUniform4f = (pfn_gfx_mtl_unf_4f32)(m_loader.get_proc("glUniform4f"));
				glUniform1fv = (pfn_gfx_mtl_unf_v1f32)(m_loader.get_proc("glUniform1fv"));
				glUniform2fv = (pfn_gfx_mtl_unf_v2f32)(m_loader.get_proc("glUniform2fv"));
				glUniform3fv = (pfn_gfx_mtl_unf_v3f32)(m_loader.get_proc("glUniform3fv"));
				glUniform4fv = (pfn_gfx_mtl_unf_v4f32)(m_loader.get_proc("glUniform4fv"));
				glUniformMatrix2fv = (pfn_gfx_mtl_unf_m2f32)(m_loader.get_proc("glUniformMatrix2fv"));
				glUniformMatrix3fv = (pfn_gfx_mtl_unf_m3f32)(m_loader.get_proc("glUniformMatrix3fv"));
				glUniformMatrix4fv = (pfn_gfx_mtl_unf_m4f32)(m_loader.get_proc("glUniformMatrix4fv"));
				// uniform blocks
				glUniformBlockBinding = (pfn_gfx_mtl_unfb_binding)(m_loader.get_proc("glUniformBlockBinding"));
			}
			if constexpr (NW_TRUE) { // samplers
				// general
				glGenSamplers = (pfn_gfx_smp_gen)(m_loader.get_proc("glGenSamplers"));
				glDeleteSamplers = (pfn_gfx_smp_del)(m_loader.get_proc("glDeleteSamplers"));
				glBindSampler = (pfn_gfx_smp_bind)(m_loader.get_proc("glBindSampler"));
				// params
				glSamplerParameteri = (pfn_gfx_smp_param_i)(m_loader.get_proc("glSamplerParameteri"));
				glSamplerParameteriv = (pfn_gfx_smp_param_iv)(m_loader.get_proc("glSamplerParameteriv"));
				glSamplerParameterf = (pfn_gfx_smp_param_f)(m_loader.get_proc("glSamplerParameterf"));
				glSamplerParameterfv = (pfn_gfx_smp_param_fv)(m_loader.get_proc("glSamplerParameterfv"));
			}
			if constexpr (NW_TRUE) { // shaders
				// general
				glCreateShader = (pfn_gfx_shd_crt)m_loader.get_proc("glCreateShader");
				glDeleteShader = (pfn_gfx_shd_del)m_loader.get_proc("glDeleteShader");
				glCompileShader = (pfn_gfx_shd_compile)m_loader.get_proc("glCompileShader");
				// getters
				glGetShaderiv = (pfn_gfx_shd_get_iv)m_loader.get_proc("glGetShaderiv");
				glGetShaderInfoLog = (pfn_gfx_shd_get_info_log)m_loader.get_proc("glGetShaderInfoLog");
				// setters
				glShaderSource = (pfn_gfx_shd_set_source)m_loader.get_proc("glShaderSource");
				// predicates
				glIsShader = (pfn_gfx_shd_is_shader)m_loader.get_proc("glIsShader");
			}
			if constexpr (NW_TRUE) { // extensions
				wglGetExtensionsStringEXT = (pfn_gfx_ext_get_str)(m_loader.get_proc("wglGetExtensionsStringEXT"));
				if (has_support("WGL_EXT_swap_control")) {
					wglGetSwapIntervalEXT = (pfn_gfx_ext_get_vsync)(m_loader.get_proc("wglGetSwapIntervalEXT"));
					wglSwapIntervalEXT = (pfn_gfx_ext_set_vsync)(m_loader.get_proc("wglSwapIntervalEXT"));
				}
			}
			if constexpr (NW_TRUE) { // framebuffer
			// general
				glGenFramebuffers = (pfn_gfx_fmbuf_gen)m_loader.get_proc("glGenFramebuffers");
				glDeleteFramebuffers = (pfn_gfx_fmbuf_del)m_loader.get_proc("glDeleteFramebuffers");
				glBindFramebuffer = (pfn_gfx_fmbuf_bind)m_loader.get_proc("glBindFramebuffer");
				glClear = (pfn_gfx_fmbuf_clear)m_loader.get_proc("glClear");
				glClearColor = (pfn_gfx_fmbuf_clear_color)m_loader.get_proc("glClearColor");
				// attachments
				glFramebufferTexture1D = (pfn_gfx_fmbuf_txr_1d)m_loader.get_proc("glFramebufferTexture1D");
				glFramebufferTexture2D = (pfn_gfx_fmbuf_txr_2d)m_loader.get_proc("glFramebufferTexture2D");
				glFramebufferTexture3D = (pfn_gfx_fmbuf_txr_3d)m_loader.get_proc("glFramebufferTexture3D");
				// draw and read
				glDrawBuffer = (pfn_gfx_fmbuf_bind_draw)m_loader.get_proc("glDrawBuffer");
				glReadBuffer = (pfn_gfx_fmbuf_bind_read)m_loader.get_proc("glReadBuffer");
				glDrawBuffers = (pfn_gfx_fmbuf_bind_draws)m_loader.get_proc("glDrawBuffers");
				glReadBuffers = (pfn_gfx_fmbuf_bind_reads)m_loader.get_proc("glReadBuffers");
				glDrawPixels = (pfn_gfx_fmbuf_draw_pixels)m_loader.get_proc("glDrawPixels");
				glReadPixels = (pfn_gfx_fmbuf_read_pixels)m_loader.get_proc("glReadPixels");
				// info
				glCheckFramebufferStatus = (pfn_gfx_fmbuf_check)(m_loader.get_proc("glCheckFramebufferStatus"));
			}
#		endif
		}
		if constexpr (NW_TRUE) { // information
			m_drawer = reinterpret_cast<cstr_t>(glGetString(GL_RENDERER));
			m_vendor = reinterpret_cast<cstr_t>(glGetString(GL_VENDOR));
			m_shd_lang = reinterpret_cast<cstr_t>(glGetString(GL_SHADING_LANGUAGE_VERSION));
			glGetIntegerv(GL_POINT_SIZE_RANGE, &m_pxl_range);
			glGetIntegerv(GL_POINT_SIZE_GRANULARITY, &m_pxl_gran);
			glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &m_max_slot_txr);
			glGetIntegerv(GL_MAX_VERTEX_ATTRIB_BINDINGS, &m_max_slot_atb);
		}

		return NW_TRUE;
	}
	v1nil gfx_context::update()
	{
		::SwapBuffers(m_device);
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
#	include "dxgi.h"
#	include "d3dcompiler.h"
namespace NW
{
	//
}
#	endif	// GAPI_D3D
#endif	// NW_GAPI