#include <nwg_pch.hpp>
#include "nwg_load_txr.h"
#if (defined NW_GAPI)
#include "nwg_load.h"
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	bit ogl_load_txr() {
		// general
		glGenTextures = (pfn_ogl_txr_gen)(ogl_get_proc("glGenTextures"));
		glDeleteTextures = (pfn_ogl_txr_del)(ogl_get_proc("glGenTextures"));
		glBindTexture = (pfn_ogl_txr_bind)(ogl_get_proc("glBindTexture"));
		glActiveTexture = (pfn_ogl_txr_active)(ogl_get_proc("glActiveTexture"));
		glGenerateMipmap = (pfn_ogl_txr_mipmap_gen)(ogl_get_proc("glGenerateMipmap"));
		glTexImage1D = (pfn_ogl_txr_img_1d)(ogl_get_proc("glTexImage1D"));
		glTexImage2D = (pfn_ogl_txr_img_2d)(ogl_get_proc("glTexImage2D"));
		glTexImage3D = (pfn_ogl_txr_img_3d)(ogl_get_proc("glTexImage3D"));
		glTexImage2DMultisample = (pfn_ogl_txr_img_2d_mulsmp)(ogl_get_proc("glTexImage2DMultisample"));
		glTexImage3DMultisample = (pfn_ogl_txr_img_3d_mulsmp)(ogl_get_proc("glTexImage3DMultisample"));
		// params
		glTexParameteri = (pfn_ogl_txr_param_i)(ogl_get_proc("glTexParameteri"));
		glTexParameteriv = (pfn_ogl_txr_param_vi)(ogl_get_proc("glTexParameteriv"));
		glTexParameterf = (pfn_ogl_txr_param_f)(ogl_get_proc("glTexParameterf"));
		glTexParameterfv = (pfn_ogl_txr_param_vf)(ogl_get_proc("glTexParameterfv"));
		// other
		glClearTexImage = (pfn_ogl_txr_img_clear)(ogl_get_proc("glClearTexImage"));

		return true;
	}
}
namespace NW
{
	// general
	pfn_ogl_txr_gen glGenTextures = NULL;
	pfn_ogl_txr_del glDeleteTextures = NULL;
	pfn_ogl_txr_bind glBindTexture = NULL;
	pfn_ogl_txr_active glActiveTexture = NULL;
	pfn_ogl_txr_mipmap_gen glGenerateMipmap = NULL;
	pfn_ogl_txr_img_1d glTexImage1D = NULL;
	pfn_ogl_txr_img_2d glTexImage2D = NULL;
	pfn_ogl_txr_img_3d glTexImage3D = NULL;
	pfn_ogl_txr_img_2d_mulsmp glTexImage2DMultisample = NULL;
	pfn_ogl_txr_img_3d_mulsmp glTexImage3DMultisample = NULL;
	// params
	pfn_ogl_txr_param_i glTexParameteri = NULL;
	pfn_ogl_txr_param_vi glTexParameteriv = NULL;
	pfn_ogl_txr_param_f glTexParameterf = NULL;
	pfn_ogl_txr_param_vf glTexParameterfv = NULL;
	// other
	pfn_ogl_txr_img_clear glClearTexImage = NULL;
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	//
}
#endif
#endif	// NW_GAPI