#include "nw_gfx_pch.hpp"
#include "nw_gfx_lib.h"
#if (defined NW_GAPI)
#	if (NW_GAPI & NW_GAPI_OGL)
#	include "nw_gfx_lib_wapi.h"
#	include "nw_gfx_lib_core.h"
#	include "nw_gfx_lib_buf.h"
#	include "nw_gfx_lib_fmbuf.h"
#	include "nw_gfx_lib_txr.h"
#	include "nw_gfx_lib_smp.h"
#	include "nw_gfx_lib_mtl.h"
#	include "nw_gfx_lib_shd.h"
#	include "nw_gfx_lib_layt.h"
namespace NW
{
	gfx_lib_loader::gfx_lib_loader() :
		lib_loader("opengl32.dll")
	{
		wglCreateContext = (pfn_gfx_new_context)lib_loader::get_proc("wglCreateContext");
		wglDeleteContext = (pfn_gfx_del_context)lib_loader::get_proc("wglDeleteContext");
		wglGetCurrentContext = (pfn_gfx_get_context)lib_loader::get_proc("wglGetCurrentContext");
		wglMakeContextCurrent = (pfn_gfx_set_context)lib_loader::get_proc("wglMakeCurrent");
		// device
		wglGetCurrentDC = (pfn_gfx_get_device)lib_loader::get_proc("wglGetCurrentDC");
		// other
		wglGetProcAddress = (pfn_gfx_get_proc)lib_loader::get_proc("wglGetProcAddress");
	}
	gfx_lib_loader::~gfx_lib_loader()
	{
		if (has_handle()) { ::FreeLibrary(m_handle); m_handle = NW_NULL; }
	}
	// --setters
	// --==<core_methods>==--
	v1bit gfx_lib_loader::load()
	{
		if constexpr (NW_TRUE) { // core
			// getters
			glGetIntegerv = (pfn_gfx_get_int_v)get_proc("glGetIntegerv");
			glGetString = (pfn_gfx_get_string)get_proc("glGetString");
			glGetError = (pfn_gfx_get_error)get_proc("glGetError");
			// predicates
			glIsEnabled = (pfn_gfx_is_enabled)get_proc("glIsEnabled");
			// drawing
			glDrawArrays = (pfn_gfx_draw_vtx)get_proc("glDrawArrays");
			glDrawElements = (pfn_gfx_draw_idx)get_proc("glDrawElements");
			// configs
			glLineWidth = (pfn_gfx_line_width)get_proc("glLineWidth");
			glPointSize = (pfn_gfx_point_size)get_proc("glPointSize");
			glViewport = (pfn_gfx_viewport)get_proc("glViewport");
			glScissor = (pfn_gfx_scissor)get_proc("glScissor");
			glEnable = (pfn_gfx_enable)get_proc("glEnable");
			glDisable = (pfn_gfx_disable)get_proc("glDisable");
			glBlendEquation = (pfn_gfx_blend_equation)get_proc("glBlendEquation");
			glBlendEquationSeparate = (pfn_gfx_blend_equation_separate)get_proc("glBlendEquationSeparate");
			glBlendFunc = (pfn_gfx_blend_function)get_proc("glBlendFunc");
			glBlendFuncSeparate = (pfn_gfx_blend_function_separate)get_proc("glBlendFuncSeparate");
			glDepthMask = (pfn_gfx_depth_mask)get_proc("glDepthMask");
			glDepthFunc = (pfn_gfx_depth_func)get_proc("glDepthFunc");
			glPolygonMode = (pfn_gfx_polygon_mode)get_proc("glPolygonMode");
			// other
			glClearError = (pfn_gfx_clear_error)(get_proc("glClearError"));
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
			glGenBuffers = (pfn_gfx_buf_gen)(get_proc("glGenBuffers"));
			glDeleteBuffers = (pfn_gfx_buf_del)(get_proc("glDeleteBuffers"));
			glBindBuffer = (pfn_gfx_buf_bind)(get_proc("glBindBuffer"));
			glBindBufferRange = (pfn_gfx_buf_bind_range)(get_proc("glBindBufferRange"));
			glBindBufferBase = (pfn_gfx_buf_bind_base)(get_proc("glBindBufferBase"));
			// data
			glBufferData = (pfn_gfx_buf_data)(get_proc("glBufferData"));
			glBufferSubData = (pfn_gfx_buf_sub_data)(get_proc("glBufferSubData"));
		}
		if constexpr (NW_TRUE) { // layouts
			// general
			glGenVertexArrays = (pfn_gfx_layt_gen)(get_proc("glGenVertexArrays"));
			glDeleteVertexArrays = (pfn_gfx_layt_del)(get_proc("glDeleteVertexArrays"));
			glBindVertexArray = (pfn_gfx_layt_bind)(get_proc("glBindVertexArray"));
			// data
			glEnableVertexAttribArray = (pfn_gfx_layt_enable_atb)(get_proc("glEnableVertexAttribArray"));
			glDisableVertexAttribArray = (pfn_gfx_layt_disable_atb)(get_proc("glEnableVertexAttribArray"));
			glVertexAttribPointer = (pfn_gfx_layt_set_atb)(get_proc("glVertexAttribPointer"));
		}
		if constexpr (NW_TRUE) { // textures
			// general
			glGenTextures = (pfn_gfx_txr_gen)(get_proc("glGenTextures"));
			glDeleteTextures = (pfn_gfx_txr_del)(get_proc("glGenTextures"));
			glBindTexture = (pfn_gfx_txr_bind)(get_proc("glBindTexture"));
			glActiveTexture = (pfn_gfx_txr_active)(get_proc("glActiveTexture"));
			glGenerateMipmap = (pfn_gfx_txr_mipmap_gen)(get_proc("glGenerateMipmap"));
			glTexImage1D = (pfn_gfx_txr_img_1d)(get_proc("glTexImage1D"));
			glTexImage2D = (pfn_gfx_txr_img_2d)(get_proc("glTexImage2D"));
			glTexImage3D = (pfn_gfx_txr_img_3d)(get_proc("glTexImage3D"));
			glTexImage2DMultisample = (pfn_gfx_txr_img_2d_mulsmp)(get_proc("glTexImage2DMultisample"));
			glTexImage3DMultisample = (pfn_gfx_txr_img_3d_mulsmp)(get_proc("glTexImage3DMultisample"));
			// params
			glTexParameteri = (pfn_gfx_txr_param_i)(get_proc("glTexParameteri"));
			glTexParameteriv = (pfn_gfx_txr_param_vi)(get_proc("glTexParameteriv"));
			glTexParameterf = (pfn_gfx_txr_param_f)(get_proc("glTexParameterf"));
			glTexParameterfv = (pfn_gfx_txr_param_vf)(get_proc("glTexParameterfv"));
			// other
			glClearTexImage = (pfn_gfx_txr_img_clear)(get_proc("glClearTexImage"));
		}
		if constexpr (NW_TRUE) { // materials
		// general
			glCreateProgram = (pfn_gfx_mtl_crt)(get_proc("glCreateProgram"));
			glDeleteProgram = (pfn_gfx_mtl_del)(get_proc("glDeleteProgram"));
			glUseProgram = (pfn_gfx_mtl_use)(get_proc("glUseProgram"));
			glAttachShader = (pfn_gfx_mtl_attach_shd)(get_proc("glAttachShader"));
			glDetachShader = (pfn_gfx_mtl_detach_shd)(get_proc("glDetachShader"));
			glLinkProgram = (pfn_gfx_mtl_link_shds)(get_proc("glLinkProgram"));
			// getters
			glGetAttribLocation = (pfn_gfx_mtl_get_loc_atb)(get_proc("glGetAttribLocation"));
			glGetUniformLocation = (pfn_gfx_mtl_get_loc_unf)(get_proc("glGetUniformLocation"));
			glGetProgramiv = (pfn_gfx_mtl_get_iv)(get_proc("glGetProgramiv"));
			glGetProgramInfoLog = (pfn_gfx_mtl_get_info_log)(get_proc("glGetProgramInfoLog"));
			// uniforms
			glUniform1i = (pfn_gfx_mtl_unf_1si32)(get_proc("glUniform1i"));
			glUniform2i = (pfn_gfx_mtl_unf_2si32)(get_proc("glUniform2i"));
			glUniform3i = (pfn_gfx_mtl_unf_3si32)(get_proc("glUniform3i"));
			glUniform4i = (pfn_gfx_mtl_unf_4si32)(get_proc("glUniform4i"));
			glUniform1iv = (pfn_gfx_mtl_unf_v1s32)(get_proc("glUniform1iv"));
			glUniform2iv = (pfn_gfx_mtl_unf_v2s32)(get_proc("glUniform2iv"));
			glUniform3iv = (pfn_gfx_mtl_unf_v3s32)(get_proc("glUniform3iv"));
			glUniform4iv = (pfn_gfx_mtl_unf_v4s32)(get_proc("glUniform4iv"));
			glUniform1ui = (pfn_gfx_mtl_unf_1ui32)(get_proc("glUniform1ui"));
			glUniform2ui = (pfn_gfx_mtl_unf_2ui32)(get_proc("glUniform2ui"));
			glUniform3ui = (pfn_gfx_mtl_unf_3ui32)(get_proc("glUniform3ui"));
			glUniform4ui = (pfn_gfx_mtl_unf_4ui32)(get_proc("glUniform4ui"));
			glUniform1uiv = (pfn_gfx_mtl_unf_v1u32)(get_proc("glUniform1uiv"));
			glUniform2uiv = (pfn_gfx_mtl_unf_v2u32)(get_proc("glUniform2uiv"));
			glUniform3uiv = (pfn_gfx_mtl_unf_v3u32)(get_proc("glUniform3uiv"));
			glUniform4uiv = (pfn_gfx_mtl_unf_v4u32)(get_proc("glUniform4uiv"));
			glUniform1f = (pfn_gfx_mtl_unf_1f32)(get_proc("glUniform1f"));
			glUniform2f = (pfn_gfx_mtl_unf_2f32)(get_proc("glUniform2f"));
			glUniform3f = (pfn_gfx_mtl_unf_3f32)(get_proc("glUniform3f"));
			glUniform4f = (pfn_gfx_mtl_unf_4f32)(get_proc("glUniform4f"));
			glUniform1fv = (pfn_gfx_mtl_unf_v1f32)(get_proc("glUniform1fv"));
			glUniform2fv = (pfn_gfx_mtl_unf_v2f32)(get_proc("glUniform2fv"));
			glUniform3fv = (pfn_gfx_mtl_unf_v3f32)(get_proc("glUniform3fv"));
			glUniform4fv = (pfn_gfx_mtl_unf_v4f32)(get_proc("glUniform4fv"));
			glUniformMatrix2fv = (pfn_gfx_mtl_unf_m2f32)(get_proc("glUniformMatrix2fv"));
			glUniformMatrix3fv = (pfn_gfx_mtl_unf_m3f32)(get_proc("glUniformMatrix3fv"));
			glUniformMatrix4fv = (pfn_gfx_mtl_unf_m4f32)(get_proc("glUniformMatrix4fv"));
			// uniform blocks
			glUniformBlockBinding = (pfn_gfx_mtl_unfb_binding)(get_proc("glUniformBlockBinding"));
		}
		if constexpr (NW_TRUE) { // samplers
			// general
			glGenSamplers = (pfn_gfx_smp_gen)(get_proc("glGenSamplers"));
			glDeleteSamplers = (pfn_gfx_smp_del)(get_proc("glDeleteSamplers"));
			glBindSampler = (pfn_gfx_smp_bind)(get_proc("glBindSampler"));
			// params
			glSamplerParameteri = (pfn_gfx_smp_param_i)(get_proc("glSamplerParameteri"));
			glSamplerParameteriv = (pfn_gfx_smp_param_iv)(get_proc("glSamplerParameteriv"));
			glSamplerParameterf = (pfn_gfx_smp_param_f)(get_proc("glSamplerParameterf"));
			glSamplerParameterfv = (pfn_gfx_smp_param_fv)(get_proc("glSamplerParameterfv"));
		}
		if constexpr (NW_TRUE) { // shaders
			// general
			glCreateShader = (pfn_gfx_shd_crt)get_proc("glCreateShader");
			glDeleteShader = (pfn_gfx_shd_del)get_proc("glDeleteShader");
			glCompileShader = (pfn_gfx_shd_compile)get_proc("glCompileShader");
			// getters
			glGetShaderiv = (pfn_gfx_shd_get_iv)get_proc("glGetShaderiv");
			glGetShaderInfoLog = (pfn_gfx_shd_get_info_log)get_proc("glGetShaderInfoLog");
			// setters
			glShaderSource = (pfn_gfx_shd_set_source)get_proc("glShaderSource");
			// predicates
			glIsShader = (pfn_gfx_shd_is_shader)get_proc("glIsShader");
		}
		if constexpr (NW_TRUE) { // extensions
			wglGetExtensionsStringEXT = (pfn_gfx_ext_get_str)(get_proc("wglGetExtensionsStringEXT"));
			if (has_support("WGL_EXT_swap_control")) {
				wglGetSwapIntervalEXT = (pfn_gfx_ext_get_vsync)(get_proc("wglGetSwapIntervalEXT"));
				wglSwapIntervalEXT = (pfn_gfx_ext_set_vsync)(get_proc("wglSwapIntervalEXT"));
			}
		}
		if constexpr (NW_TRUE) { // framebuffer
		// general
			glGenFramebuffers = (pfn_gfx_fmbuf_gen)get_proc("glGenFramebuffers");
			glDeleteFramebuffers = (pfn_gfx_fmbuf_del)get_proc("glDeleteFramebuffers");
			glBindFramebuffer = (pfn_gfx_fmbuf_bind)get_proc("glBindFramebuffer");
			glClear = (pfn_gfx_fmbuf_clear)get_proc("glClear");
			glClearColor = (pfn_gfx_fmbuf_clear_color)get_proc("glClearColor");
			// attachments
			glFramebufferTexture1D = (pfn_gfx_fmbuf_txr_1d)get_proc("glFramebufferTexture1D");
			glFramebufferTexture2D = (pfn_gfx_fmbuf_txr_2d)get_proc("glFramebufferTexture2D");
			glFramebufferTexture3D = (pfn_gfx_fmbuf_txr_3d)get_proc("glFramebufferTexture3D");
			// draw and read
			glDrawBuffer = (pfn_gfx_fmbuf_bind_draw)get_proc("glDrawBuffer");
			glReadBuffer = (pfn_gfx_fmbuf_bind_read)get_proc("glReadBuffer");
			glDrawBuffers = (pfn_gfx_fmbuf_bind_draws)get_proc("glDrawBuffers");
			glReadBuffers = (pfn_gfx_fmbuf_bind_reads)get_proc("glReadBuffers");
			glDrawPixels = (pfn_gfx_fmbuf_draw_pixels)get_proc("glDrawPixels");
			glReadPixels = (pfn_gfx_fmbuf_read_pixels)get_proc("glReadPixels");
			// info
			glCheckFramebufferStatus = (pfn_gfx_fmbuf_check)(get_proc("glCheckFramebufferStatus"));
		}
		return NW_TRUE;
	}
	// --==</core_methods>==--
}
namespace NW
{ // windows
	// context
	pfn_gfx_new_context  wglCreateContext = NW_NULL;
	pfn_gfx_del_context  wglDeleteContext = NW_NULL;
	pfn_gfx_get_context  wglGetCurrentContext = NW_NULL;
	pfn_gfx_set_context  wglMakeContextCurrent = NW_NULL;
	// device
	pfn_gfx_get_device wglGetCurrentDC = NW_NULL;
	// other
	pfn_gfx_get_proc wglGetProcAddress = NW_NULL;
	// extensions
	pfn_gfx_ext_get_str   wglGetExtensionsStringEXT = NW_NULL;
	pfn_gfx_ext_get_vsync wglGetSwapIntervalEXT = NW_NULL;
	pfn_gfx_ext_set_vsync wglSwapIntervalEXT = NW_NULL;
}
namespace NW
{ // core
	// getters
	pfn_gfx_get_int_v glGetIntegerv = NULL;
	pfn_gfx_get_string glGetString = NULL;
	pfn_gfx_get_error glGetError = NULL;
	// predicates
	pfn_gfx_is_enabled glIsEnabled = NULL;
	// drawing
	pfn_gfx_draw_vtx glDrawArrays = NULL;
	pfn_gfx_draw_idx glDrawElements = NULL;
	// configs
	pfn_gfx_line_width glLineWidth = NULL;
	pfn_gfx_point_size glPointSize = NULL;
	pfn_gfx_viewport glViewport = NULL;
	pfn_gfx_scissor glScissor = NULL;
	pfn_gfx_enable glEnable = NULL;
	pfn_gfx_disable glDisable = NULL;
	pfn_gfx_blend_equation glBlendEquation = NULL;
	pfn_gfx_blend_equation_separate glBlendEquationSeparate = NULL;
	pfn_gfx_blend_function glBlendFunc = NULL;
	pfn_gfx_blend_function_separate glBlendFuncSeparate = NULL;
	pfn_gfx_depth_mask glDepthMask = NULL;
	pfn_gfx_depth_func glDepthFunc = NULL;
	pfn_gfx_polygon_mode glPolygonMode = NULL;
	// other
	pfn_gfx_clear_error glClearError = NULL;
}
namespace NW
{ // buffers
		// general
	pfn_gfx_buf_gen glGenBuffers = NULL;
	pfn_gfx_buf_del glDeleteBuffers = NULL;
	pfn_gfx_buf_bind glBindBuffer = NULL;
	pfn_gfx_buf_bind_range glBindBufferRange = NULL;
	pfn_gfx_buf_bind_base glBindBufferBase = NULL;
	pfn_gfx_vbuf_bind glBindVertexBuffer = NULL;
	// data
	pfn_gfx_buf_data glBufferData = NULL;
	pfn_gfx_buf_sub_data glBufferSubData = NULL;
}
namespace NW
{ // layout
	// general
	pfn_gfx_layt_gen glGenVertexArrays = NULL;
	pfn_gfx_layt_del glDeleteVertexArrays = NULL;
	pfn_gfx_layt_bind glBindVertexArray = NULL;
	// data
	pfn_gfx_layt_enable_atb glEnableVertexAttribArray = NULL;
	pfn_gfx_layt_disable_atb glDisableVertexAttribArray = NULL;
	pfn_gfx_layt_set_atb glVertexAttribPointer = NULL;
}
namespace NW
{ // shaders
	// general
	pfn_gfx_shd_crt glCreateShader = NULL;
	pfn_gfx_shd_del glDeleteShader = NULL;
	pfn_gfx_shd_compile glCompileShader = NULL;
	// getters
	pfn_gfx_shd_get_iv glGetShaderiv = NULL;
	pfn_gfx_shd_get_info_log glGetShaderInfoLog = NULL;
	// setters
	pfn_gfx_shd_set_source glShaderSource = NULL;
	// predicates
	pfn_gfx_shd_is_shader glIsShader = NULL;
}
namespace NW
{ // textures
	// general
	pfn_gfx_txr_gen glGenTextures = NULL;
	pfn_gfx_txr_del glDeleteTextures = NULL;
	pfn_gfx_txr_bind glBindTexture = NULL;
	pfn_gfx_txr_active glActiveTexture = NULL;
	pfn_gfx_txr_mipmap_gen glGenerateMipmap = NULL;
	pfn_gfx_txr_img_1d glTexImage1D = NULL;
	pfn_gfx_txr_img_2d glTexImage2D = NULL;
	pfn_gfx_txr_img_3d glTexImage3D = NULL;
	pfn_gfx_txr_img_2d_mulsmp glTexImage2DMultisample = NULL;
	pfn_gfx_txr_img_3d_mulsmp glTexImage3DMultisample = NULL;
	// params
	pfn_gfx_txr_param_i glTexParameteri = NULL;
	pfn_gfx_txr_param_vi glTexParameteriv = NULL;
	pfn_gfx_txr_param_f glTexParameterf = NULL;
	pfn_gfx_txr_param_vf glTexParameterfv = NULL;
	// other
	pfn_gfx_txr_img_clear glClearTexImage = NULL;
}
namespace NW
{ // materials
	// general
	pfn_gfx_mtl_crt glCreateProgram = NULL;
	pfn_gfx_mtl_del glDeleteProgram = NULL;
	pfn_gfx_mtl_use glUseProgram = NULL;
	pfn_gfx_mtl_attach_shd glAttachShader = NULL;
	pfn_gfx_mtl_detach_shd glDetachShader = NULL;
	pfn_gfx_mtl_link_shds glLinkProgram = NULL;
	// getters
	pfn_gfx_mtl_get_loc_atb glGetAttribLocation = NULL;
	pfn_gfx_mtl_get_loc_unf glGetUniformLocation = NULL;
	pfn_gfx_mtl_get_iv glGetProgramiv = NULL;
	pfn_gfx_mtl_get_info_log glGetProgramInfoLog = NULL;
	// uniforms
	pfn_gfx_mtl_unf_1si32 glUniform1i = NULL;
	pfn_gfx_mtl_unf_2si32 glUniform2i = NULL;
	pfn_gfx_mtl_unf_3si32 glUniform3i = NULL;
	pfn_gfx_mtl_unf_4si32 glUniform4i = NULL;
	pfn_gfx_mtl_unf_v1s32 glUniform1iv = NULL;
	pfn_gfx_mtl_unf_v2s32 glUniform2iv = NULL;
	pfn_gfx_mtl_unf_v3s32 glUniform3iv = NULL;
	pfn_gfx_mtl_unf_v4s32 glUniform4iv = NULL;
	pfn_gfx_mtl_unf_1ui32 glUniform1ui = NULL;
	pfn_gfx_mtl_unf_2ui32 glUniform2ui = NULL;
	pfn_gfx_mtl_unf_3ui32 glUniform3ui = NULL;
	pfn_gfx_mtl_unf_4ui32 glUniform4ui = NULL;
	pfn_gfx_mtl_unf_v1u32 glUniform1uiv = NULL;
	pfn_gfx_mtl_unf_v2u32 glUniform2uiv = NULL;
	pfn_gfx_mtl_unf_v3u32 glUniform3uiv = NULL;
	pfn_gfx_mtl_unf_v4u32 glUniform4uiv = NULL;
	pfn_gfx_mtl_unf_1f32 glUniform1f = NULL;
	pfn_gfx_mtl_unf_2f32 glUniform2f = NULL;
	pfn_gfx_mtl_unf_3f32 glUniform3f = NULL;
	pfn_gfx_mtl_unf_4f32 glUniform4f = NULL;
	pfn_gfx_mtl_unf_v1f32 glUniform1fv = NULL;
	pfn_gfx_mtl_unf_v2f32 glUniform2fv = NULL;
	pfn_gfx_mtl_unf_v3f32 glUniform3fv = NULL;
	pfn_gfx_mtl_unf_v4f32 glUniform4fv = NULL;
	pfn_gfx_mtl_unf_m2f32 glUniformMatrix2fv = NULL;
	pfn_gfx_mtl_unf_m3f32 glUniformMatrix3fv = NULL;
	pfn_gfx_mtl_unf_m4f32 glUniformMatrix4fv = NULL;
	// uniform blocks
	pfn_gfx_mtl_unfb_binding glUniformBlockBinding = NULL;
}
namespace NW
{ // samplers
	// general
	pfn_gfx_smp_gen glGenSamplers = NULL;
	pfn_gfx_smp_del glDeleteSamplers = NULL;
	pfn_gfx_smp_bind glBindSampler = NULL;
	// params
	pfn_gfx_smp_param_i glSamplerParameteri = NULL;
	pfn_gfx_smp_param_iv glSamplerParameteriv = NULL;
	pfn_gfx_smp_param_f glSamplerParameterf = NULL;
	pfn_gfx_smp_param_fv glSamplerParameterfv = NULL;
}
namespace NW
{ // framebuffer
	// general
	pfn_gfx_fmbuf_gen glGenFramebuffers = NULL;
	pfn_gfx_fmbuf_del glDeleteFramebuffers = NULL;
	pfn_gfx_fmbuf_bind glBindFramebuffer = NULL;
	pfn_gfx_fmbuf_clear glClear = NULL;
	pfn_gfx_fmbuf_clear_color glClearColor = NULL;
	// attachments
	pfn_gfx_fmbuf_txr_1d glFramebufferTexture1D = NULL;
	pfn_gfx_fmbuf_txr_2d glFramebufferTexture2D = NULL;
	pfn_gfx_fmbuf_txr_3d glFramebufferTexture3D = NULL;
	// draw and read
	pfn_gfx_fmbuf_bind_draw glDrawBuffer = NULL;
	pfn_gfx_fmbuf_bind_read glReadBuffer = NULL;
	pfn_gfx_fmbuf_bind_draws glDrawBuffers = NULL;
	pfn_gfx_fmbuf_bind_reads glReadBuffers = NULL;
	pfn_gfx_fmbuf_draw_pixels glDrawPixels = NULL;
	pfn_gfx_fmbuf_read_pixels glReadPixels = NULL;
	// info
	pfn_gfx_fmbuf_check glCheckFramebufferStatus = NULL;
}

#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	if constexpr (NW_TRUE) { // core
		D3D11CreateDevice = (pfn_d3d_new_device_context)get_proc("D3D11CreateDevice");
		D3D11CreateDeviceAndSwapChain = (pfn_d3d_new_device_context_swap)get_proc("D3D11CreateDeviceAndSwapChain");
	}
	if constexpr (NW_TRUE) { // shaders
		D3DCompile = (pfn_gfx_shd_compile)get_proc("D3DCompile");
	}
}
namespace NW
{ // core
	pfn_d3d_new_device_context D3D11CreateDevice = NULL;
	pfn_d3d_new_device_context_swap D3D11CreateDeviceAndSwapChain = NULL;
}
namespace NW
{ // shaders
	pfn_gfx_shd_compile D3DCompile = NULL;
}
#	endif	// GAPI_D3D
#endif	// NW_GAPI