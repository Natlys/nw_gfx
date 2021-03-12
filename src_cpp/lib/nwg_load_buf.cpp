#include <nwg_pch.hpp>
#include "nwg_load_buf.h"
#if (defined NW_GAPI)
#include "nwg_load.h"
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	bit ogl_load_buf() {
		// general
		glGenBuffers = (pfn_ogl_buf_gen)(ogl_get_proc("glGenBuffers"));
		glDeleteBuffers = (pfn_ogl_buf_del)(ogl_get_proc("glDeleteBuffers"));
		glBindBuffer = (pfn_ogl_buf_bind)(ogl_get_proc("glBindBuffer"));
		glBindBufferRange = (pfn_ogl_buf_bind_range)(ogl_get_proc("glBindBufferRange"));
		glBindBufferBase = (pfn_ogl_buf_bind_base)(ogl_get_proc("glBindBufferBase"));
		// data
		glBufferData = (pfn_ogl_buf_data)(ogl_get_proc("glBufferData"));
		glBufferSubData = (pfn_ogl_buf_sub_data)(ogl_get_proc("glBufferSubData"));

		return true;
	}
}
namespace NW
{
	// general
	pfn_ogl_buf_gen glGenBuffers= NULL;
	pfn_ogl_buf_del glDeleteBuffers = NULL;
	pfn_ogl_buf_bind glBindBuffer = NULL;
	pfn_ogl_buf_bind_range glBindBufferRange = NULL;
	pfn_ogl_buf_bind_base glBindBufferBase = NULL;
	pfn_ogl_vbuf_bind glBindVertexBuffer = NULL;
	// data
	pfn_ogl_buf_data glBufferData = NULL;
	pfn_ogl_buf_sub_data glBufferSubData = NULL;
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	//
}
#endif
#endif	// NW_GAPI