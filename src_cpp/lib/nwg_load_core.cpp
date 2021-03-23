#include <nwg_pch.hpp>
#include "nwg_load_core.h"
#if (defined NW_GAPI)
#include "nwg_load.h"
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	bit gfx_load_core() {
		// getters
		glGetIntegerv = (pfn_ogl_get_int_v)(gfx_get_proc("glGetIntegerv"));
		glGetString = (pfn_ogl_get_string)(gfx_get_proc("glGetString"));
		glGetError = (pfn_ogl_get_error)(gfx_get_proc("glGetString"));
		// predicates
		glIsEnabled = (pfn_ogl_is_enabled)(gfx_get_proc("glIsEnabled"));
		// drawing
		glDrawArrays = (pfn_ogl_draw_vtx)(gfx_get_proc("glDrawArrays"));
		glDrawElements = (pfn_ogl_draw_idx)(gfx_get_proc("glDrawElements"));
		// configs
		glViewport = (pfn_ogl_viewport)(gfx_get_proc("glViewport"));
		glScissor = (pfn_ogl_scissor)(gfx_get_proc("glScissor"));
		glEnable = (pfn_ogl_enable)(gfx_get_proc("glEnable"));
		glDisable = (pfn_ogl_disable)(gfx_get_proc("glDisable"));
		glBlendEquation = (pfn_ogl_blend_equation)(gfx_get_proc("glBlendEquation"));
		glBlendEquationSeparate = (pfn_ogl_blend_equation_separate)(gfx_get_proc("glBlendEquationSeparate"));
		glBlendFunc = (pfn_ogl_blend_function)(gfx_get_proc("glBlendFunc"));
		glBlendFuncSeparate = (pfn_ogl_blend_function_separate)(gfx_get_proc("glBlendFuncSeparate"));
		glDepthMask = (pfn_ogl_depth_mask)(gfx_get_proc("glDepthMask"));
		glDepthFunc = (pfn_ogl_depth_func)(gfx_get_proc("glDepthFunc"));
		glPolygonMode = (pfn_ogl_polygon_mode)(gfx_get_proc("glPolygonMode"));
		// other
		glClearError = (pfn_ogl_clear_error)(gfx_get_proc("glClearError"));

		return true;
	}
	void gfx_clear_err() { while (glGetError() != GL_NO_ERROR); }
	bit gfx_get_err_log(cstr strLoc, cstr strFile, si32 nLine)
	{
		si32 err_code = 0u;
		while ((err_code = glGetError()) != GL_NO_ERROR) {
			dstr err_comment;
			switch (err_code) {
			case GL_INVALID_ENUM: err_comment = "INVALID_ENUM"; break;
			case GL_INVALID_VALUE: err_comment = "INVALID_VALUE"; break;
			case GL_INVALID_OPERATION: err_comment = "INVALID_OPERATION"; break;
			case GL_STACK_OVERFLOW: err_comment = "STACK_OVERFLOW"; break;
			case GL_STACK_UNDERFLOW: err_comment = "STACK_UNDERFLOW"; break;
			case GL_OUT_OF_MEMORY: err_comment = "OUT_OF_MEMORY"; break;
			}
			throw (a_error(&err_comment[0], err_code, strLoc, nLine));
			return false;
		}
		return true;
	}
}
namespace NW
{
	// getters
	pfn_ogl_get_int_v glGetIntegerv = NULL;
	pfn_ogl_get_string glGetString = NULL;
	pfn_ogl_get_error glGetError = NULL;
	// predicates
	pfn_ogl_is_enabled glIsEnabled = NULL;
	// drawing
	pfn_ogl_draw_vtx glDrawArrays = NULL;
	pfn_ogl_draw_idx glDrawElements = NULL;
	// configs
	pfn_ogl_viewport glViewport = NULL;
	pfn_ogl_scissor glScissor = NULL;
	pfn_ogl_enable glEnable = NULL;
	pfn_ogl_disable glDisable = NULL;
	pfn_ogl_blend_equation glBlendEquation = NULL;
	pfn_ogl_blend_equation_separate glBlendEquationSeparate = NULL;
	pfn_ogl_blend_function glBlendFunc = NULL;
	pfn_ogl_blend_function_separate glBlendFuncSeparate = NULL;
	pfn_ogl_depth_mask glDepthMask = NULL;
	pfn_ogl_depth_func glDepthFunc = NULL;
	pfn_ogl_polygon_mode glPolygonMode = NULL;
	// other
	pfn_ogl_clear_error glClearError = NULL;
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	bit gfx_load_core() {
		if (gfx_get_lib() == NULL) { return false; }
		gfx_new_context_and_swap_chain = (PFN_D3D11_CREATE_DEVICE_AND_SWAP_CHAIN)gfx_get_proc("D3D11CreateDeviceAndSwapChain");
		
		return true;
	}
	void gfx_err_log() {
		//
	}
	bit gfx_err_log(cstr stinfo, cstr strFile, int nLine) {
		return false;
	}
}
namespace NW
{
	PFN_D3D11_CREATE_DEVICE_AND_SWAP_CHAIN gfx_new_context_and_swap_chain = NULL;
}
#endif
#endif	// NW_GAPI