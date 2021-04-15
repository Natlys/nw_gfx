#include "nw_gfx_pch.hpp"
#include "nw_gfx_lib_txr.h"
#if (defined NW_GAPI)
#include "nw_gfx_lib.h"
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	v1bit gfx_load_txr() {
		// general
		glGenTextures = (pfn_ogl_gfx_txrgen)(gfx_get_proc("glGenTextures"));
		glDeleteTextures = (pfn_ogl_gfx_txrdel)(gfx_get_proc("glGenTextures"));
		glBindTexture = (pfn_ogl_gfx_txrbind)(gfx_get_proc("glBindTexture"));
		glActiveTexture = (pfn_ogl_gfx_txractive)(gfx_get_proc("glActiveTexture"));
		glGenerateMipmap = (pfn_ogl_gfx_txrmipmap_gen)(gfx_get_proc("glGenerateMipmap"));
		glTexImage1D = (pfn_ogl_gfx_txrimg_1d)(gfx_get_proc("glTexImage1D"));
		glTexImage2D = (pfn_ogl_gfx_txrimg_2d)(gfx_get_proc("glTexImage2D"));
		glTexImage3D = (pfn_ogl_gfx_txrimg_3d)(gfx_get_proc("glTexImage3D"));
		glTexImage2DMultisample = (pfn_ogl_gfx_txrimg_2d_mulsmp)(gfx_get_proc("glTexImage2DMultisample"));
		glTexImage3DMultisample = (pfn_ogl_gfx_txrimg_3d_mulsmp)(gfx_get_proc("glTexImage3DMultisample"));
		// params
		glTexParameteri = (pfn_ogl_gfx_txrparam_i)(gfx_get_proc("glTexParameteri"));
		glTexParameteriv = (pfn_ogl_gfx_txrparam_vi)(gfx_get_proc("glTexParameteriv"));
		glTexParameterf = (pfn_ogl_gfx_txrparam_f)(gfx_get_proc("glTexParameterf"));
		glTexParameterfv = (pfn_ogl_gfx_txrparam_vf)(gfx_get_proc("glTexParameterfv"));
		// other
		glClearTexImage = (pfn_ogl_gfx_txrimg_clear)(gfx_get_proc("glClearTexImage"));

		return TRUE;
	}
}
namespace NW
{
	// general
	pfn_ogl_gfx_txrgen glGenTextures = NULL;
	pfn_ogl_gfx_txrdel glDeleteTextures = NULL;
	pfn_ogl_gfx_txrbind glBindTexture = NULL;
	pfn_ogl_gfx_txractive glActiveTexture = NULL;
	pfn_ogl_gfx_txrmipmap_gen glGenerateMipmap = NULL;
	pfn_ogl_gfx_txrimg_1d glTexImage1D = NULL;
	pfn_ogl_gfx_txrimg_2d glTexImage2D = NULL;
	pfn_ogl_gfx_txrimg_3d glTexImage3D = NULL;
	pfn_ogl_gfx_txrimg_2d_mulsmp glTexImage2DMultisample = NULL;
	pfn_ogl_gfx_txrimg_3d_mulsmp glTexImage3DMultisample = NULL;
	// params
	pfn_ogl_gfx_txrparam_i glTexParameteri = NULL;
	pfn_ogl_gfx_txrparam_vi glTexParameteriv = NULL;
	pfn_ogl_gfx_txrparam_f glTexParameterf = NULL;
	pfn_ogl_gfx_txrparam_vf glTexParameterfv = NULL;
	// other
	pfn_ogl_gfx_txrimg_clear glClearTexImage = NULL;
}
#endif
#if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	v1bit gfx_load_txr()
	{
		return TRUE;
	}
}
#endif
#endif	// NW_GAPI