#include <nwg_pch.hpp>
#include "nwg_load_fbuf.h"
#if (defined NW_GAPI)
#include "nwg_load.h"
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	bit ogl_load_fbuf() {
		// general
		glGenFramebuffers = (pfn_ogl_fbuf_gen)(ogl_get_proc("glGenFramebuffers"));
		glDeleteFramebuffers = (pfn_ogl_fbuf_del)(ogl_get_proc("glDeleteFramebuffers"));
		glBindFramebuffer = (pfn_ogl_fbuf_bind)(ogl_get_proc("glBindFramebuffer"));
		glClear = (pfn_ogl_fbuf_clear)(ogl_get_proc("glClear"));
		glClearColor = (pfn_ogl_fbuf_clear_color)(ogl_get_proc("glClearColor"));
		// attachments
		glFramebufferTexture1D = (pfn_ogl_fbuf_txr1d)(ogl_get_proc("glFramebufferTexture1D"));
		glFramebufferTexture2D = (pfn_ogl_fbuf_txr2d)(ogl_get_proc("glFramebufferTexture2D"));
		glFramebufferTexture3D = (pfn_ogl_fbuf_txr3d)(ogl_get_proc("glFramebufferTexture3D"));
		// draw and read
		glDrawBuffer = (pfn_ogl_fbuf_bind_draw)(ogl_get_proc("glDrawBuffer"));
		glReadBuffer = (pfn_ogl_fbuf_bind_read)(ogl_get_proc("glReadBuffer"));
		glDrawBuffers = (pfn_ogl_fbuf_bind_draws)(ogl_get_proc("glDrawBuffers"));
		glReadBuffers = (pfn_ogl_fbuf_bind_reads)(ogl_get_proc("glReadBuffers"));
		glDrawPixels = (pfn_ogl_fbuf_draw_pixels)(ogl_get_proc("glDrawPixels"));
		glReadPixels = (pfn_ogl_fbuf_read_pixels)(ogl_get_proc("glReadPixels"));
		// info
		glCheckFramebufferStatus = (pfn_ogl_fbuf_check)(ogl_get_proc("glCheckFramebufferStatus"));
		return true;
	}
}
namespace NW
{
	// general
	pfn_ogl_fbuf_gen glGenFramebuffers = NULL;
	pfn_ogl_fbuf_del glDeleteFramebuffers = NULL;
	pfn_ogl_fbuf_bind glBindFramebuffer = NULL;
	pfn_ogl_fbuf_clear glClear = NULL;
	pfn_ogl_fbuf_clear_color glClearColor = NULL;
	// attachments
	pfn_ogl_fbuf_txr1d glFramebufferTexture1D = NULL;
	pfn_ogl_fbuf_txr2d glFramebufferTexture2D = NULL;
	pfn_ogl_fbuf_txr3d glFramebufferTexture3D = NULL;
	// draw and read
	pfn_ogl_fbuf_bind_draw glDrawBuffer = NULL;
	pfn_ogl_fbuf_bind_read glReadBuffer = NULL;
	pfn_ogl_fbuf_bind_draws glDrawBuffers = NULL;
	pfn_ogl_fbuf_bind_reads glReadBuffers = NULL;
	pfn_ogl_fbuf_draw_pixels glDrawPixels = NULL;
	pfn_ogl_fbuf_read_pixels glReadPixels = NULL;
	// info
	pfn_ogl_fbuf_check glCheckFramebufferStatus = NULL;
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	//
}
#endif
#endif	// NW_GAPI