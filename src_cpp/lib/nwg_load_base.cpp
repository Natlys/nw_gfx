#include <nwg_pch.hpp>
#include "nwg_load_base.h"
#if (defined NW_GAPI)
#include "nwg_load.h"
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	bit ogl_load_base() {
		// getters
		glGetIntegerv = (pfn_ogl_get_int_v)(ogl_get_proc("glGetIntegerv"));
		glGetString = (pfn_ogl_get_string)(ogl_get_proc("glGetString"));
		glGetError = (pfn_ogl_get_error)(ogl_get_proc("glGetString"));
		// predicates
		glIsEnabled = (pfn_ogl_is_enabled)(ogl_get_proc("glIsEnabled"));
		// drawing
		glDrawArrays = (pfn_ogl_draw_vtx)(ogl_get_proc("glDrawArrays"));
		glDrawElements = (pfn_ogl_draw_idx)(ogl_get_proc("glDrawElements"));
		// configs
		glViewport = (pfn_ogl_viewport)(ogl_get_proc("glViewport"));
		glScissor = (pfn_ogl_scissor)(ogl_get_proc("glScissor"));
		glEnable = (pfn_ogl_enable)(ogl_get_proc("glEnable"));
		glDisable = (pfn_ogl_disable)(ogl_get_proc("glDisable"));
		glBlendEquation = (pfn_ogl_blend_equation)(ogl_get_proc("glBlendEquation"));
		glBlendEquationSeparate = (pfn_ogl_blend_equation_separate)(ogl_get_proc("glBlendEquationSeparate"));
		glBlendFunc = (pfn_ogl_blend_function)(ogl_get_proc("glBlendFunc"));
		glBlendFuncSeparate = (pfn_ogl_blend_function_separate)(ogl_get_proc("glBlendFuncSeparate"));
		glDepthMask = (pfn_ogl_depth_mask)(ogl_get_proc("glDepthMask"));
		glDepthFunc = (pfn_ogl_depth_func)(ogl_get_proc("glDepthFunc"));
		glPolygonMode = (pfn_ogl_polygon_mode)(ogl_get_proc("glPolygonMode"));
		// other
		glClearError = (pfn_ogl_clear_error)(ogl_get_proc("glClearError"));

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
	//
}
#endif
#endif	// NW_GAPI