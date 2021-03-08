#include <nwg_pch.hpp>
#include "nwg_load_smp.h"
#if (defined NWG_GAPI)
#include "nwg_load.h"
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	bit ogl_load_smp() {
		glGenSamplers = (pfn_ogl_smp_gen)(ogl_get_proc("glGenSamplers"));
		glDeleteSamplers = (pfn_ogl_smp_del)(ogl_get_proc("glDeleteSamplers"));
		glBindSampler = (pfn_ogl_smp_bind)(ogl_get_proc("glBindSampler"));
		
		return true;
	}
}
namespace NWG
{
	// general
	pfn_ogl_smp_gen ogl_smp_gen = NULL;
	pfn_ogl_smp_del ogl_smp_del = NULL;
	pfn_ogl_smp_bind ogl_smp_bind = NULL;
	// params
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
	//
}
#endif
#endif	// NWG_GAPI