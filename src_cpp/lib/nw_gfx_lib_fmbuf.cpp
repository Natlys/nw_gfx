#include "nw_gfx_pch.hpp"
#include "nw_gfx_lib_fmbuf.h"
#if (defined NW_GAPI)
#include "nw_gfx_lib.h"
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	v1bit gfx_load_fmbuf() {
		// general
		glGenFramebuffers = (pfn_ogl_fmbuf_gen)(gfx_get_proc("glGenFramebuffers"));
		glDeleteFramebuffers = (pfn_ogl_fmbuf_del)(gfx_get_proc("glDeleteFramebuffers"));
		glBindFramebuffer = (pfn_ogl_fmbuf_bind)(gfx_get_proc("glBindFramebuffer"));
		glClear = (pfn_ogl_fmbuf_clear)(gfx_get_proc("glClear"));
		glClearColor = (pfn_ogl_fmbuf_clear_color)(gfx_get_proc("glClearColor"));
		// attachments
		glFramebufferTexture1D = (pfn_ogl_fmbuf_txr_1d)(gfx_get_proc("glFramebufferTexture1D"));
		glFramebufferTexture2D = (pfn_ogl_fmbuf_txr_2d)(gfx_get_proc("glFramebufferTexture2D"));
		glFramebufferTexture3D = (pfn_ogl_fmbuf_txr_3d)(gfx_get_proc("glFramebufferTexture3D"));
		// draw and read
		glDrawBuffer = (pfn_ogl_fmbuf_bind_draw)(gfx_get_proc("glDrawBuffer"));
		glReadBuffer = (pfn_ogl_fmbuf_bind_read)(gfx_get_proc("glReadBuffer"));
		glDrawBuffers = (pfn_ogl_fmbuf_bind_draws)(gfx_get_proc("glDrawBuffers"));
		glReadBuffers = (pfn_ogl_fmbuf_bind_reads)(gfx_get_proc("glReadBuffers"));
		glDrawPixels = (pfn_ogl_fmbuf_draw_pixels)(gfx_get_proc("glDrawPixels"));
		glReadPixels = (pfn_ogl_fmbuf_read_pixels)(gfx_get_proc("glReadPixels"));
		// info
		glCheckFramebufferStatus = (pfn_ogl_fmbuf_check)(gfx_get_proc("glCheckFramebufferStatus"));
		return NW_TRUE;
	}
}
namespace NW
{
	// general
	pfn_ogl_fmbuf_gen glGenFramebuffers = NULL;
	pfn_ogl_fmbuf_del glDeleteFramebuffers = NULL;
	pfn_ogl_fmbuf_bind glBindFramebuffer = NULL;
	pfn_ogl_fmbuf_clear glClear = NULL;
	pfn_ogl_fmbuf_clear_color glClearColor = NULL;
	// attachments
	pfn_ogl_fmbuf_txr_1d glFramebufferTexture1D = NULL;
	pfn_ogl_fmbuf_txr_2d glFramebufferTexture2D = NULL;
	pfn_ogl_fmbuf_txr_3d glFramebufferTexture3D = NULL;
	// draw and read
	pfn_ogl_fmbuf_bind_draw glDrawBuffer = NULL;
	pfn_ogl_fmbuf_bind_read glReadBuffer = NULL;
	pfn_ogl_fmbuf_bind_draws glDrawBuffers = NULL;
	pfn_ogl_fmbuf_bind_reads glReadBuffers = NULL;
	pfn_ogl_fmbuf_draw_pixels glDrawPixels = NULL;
	pfn_ogl_fmbuf_read_pixels glReadPixels = NULL;
	// info
	pfn_ogl_fmbuf_check glCheckFramebufferStatus = NULL;
}
#endif
#if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	v1bit gfx_load_fmbuf() {
		return NW_TRUE;
	}
}
#endif
#endif	// NW_GAPI