#include <nwg_pch.hpp>
#include "nwg_load_smp.h"
#if (defined NW_GAPI)
#include "nwg_load.h"
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	bit ogl_load_smp()
	{
		// general
		glGenSamplers = (pfn_ogl_smp_gen)(ogl_get_proc("glGenSamplers"));
		glDeleteSamplers = (pfn_ogl_smp_del)(ogl_get_proc("glDeleteSamplers"));
		glBindSampler = (pfn_ogl_smp_bind)(ogl_get_proc("glBindSampler"));
		// params
		glSamplerParameteri = (pfn_ogl_smp_param_i)(ogl_get_proc("glSamplerParameteri"));
		glSamplerParameteriv = (pfn_ogl_smp_param_iv)(ogl_get_proc("glSamplerParameteriv"));
		glSamplerParameterf = (pfn_ogl_smp_param_f)(ogl_get_proc("glSamplerParameterf"));
		glSamplerParameterfv = (pfn_ogl_smp_param_fv)(ogl_get_proc("glSamplerParameterfv"));
		
		return true;
	}
}
namespace NW
{
	// general
	pfn_ogl_smp_gen glGenSamplers = NULL;
	pfn_ogl_smp_del glDeleteSamplers = NULL;
	pfn_ogl_smp_bind glBindSampler = NULL;
	// params
	pfn_ogl_smp_param_i glSamplerParameteri = NULL;
	pfn_ogl_smp_param_iv glSamplerParameteriv = NULL;
	pfn_ogl_smp_param_f glSamplerParameterf = NULL;
	pfn_ogl_smp_param_fv glSamplerParameterfv = NULL;
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	//
}
#endif
#endif	// NW_GAPI