#ifndef NW_GFX_LIB_LAYOUT_H
#define NW_GFX_LIB_LAYOUT_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#include "nw_gfx_lib_core.h"
namespace NW
{
	extern v1bit gfx_load_layt();
}
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	// general
	typedef void (NW_API_ENTRYP pfn_ogl_varr_gen)(GLsizei count, GLuint* vtx_arr_ids);
	typedef void (NW_API_ENTRYP pfn_ogl_varr_del)(GLsizei count, const GLuint* vtx_arr_ids);
	typedef void (NW_API_ENTRYP pfn_ogl_varr_bind)(GLuint vtx_arr_id);
	// data
	typedef void (NW_API_ENTRYP pfn_ogl_varr_enable_atb)(GLuint vtx_atb_idx);
	typedef void (NW_API_ENTRYP pfn_ogl_varr_disable_atb)(GLuint vtx_atb_idx);
	typedef void (NW_API_ENTRYP pfn_ogl_varr_set_atb)(GLuint vtx_atb_idx, GLint count, GLenum data_type, GLboolean is_normalized, GLsizei stride_size, const GLvoid* offset);
}
namespace NW
{
	// general
	extern pfn_ogl_varr_gen ogl_varr_gen;
	extern pfn_ogl_varr_del ogl_varr_del;
	extern pfn_ogl_varr_bind ogl_varr_bind;
	// data
	extern pfn_ogl_varr_enable_atb ogl_varr_enable_atb;
	extern pfn_ogl_varr_disable_atb ogl_varr_disable_atb;
	extern pfn_ogl_varr_set_atb ogl_varr_set_atb;
}
// general
#define glGenVertexArrays ogl_varr_gen
#define glDeleteVertexArrays ogl_varr_del
#define glBindVertexArray ogl_varr_bind
// data
#define glEnableVertexAttribArray ogl_varr_enable_atb
#define glDisableVertexAttribArray ogl_varr_disable_atb
#define glVertexAttribPointer ogl_varr_set_atb

#ifndef __gl_h__
// general
#define GL_VERTEX_ARRAY_BINDING           0x85B5
#define GL_VERTEX_ATTRIB_BINDING          0x82D4
#define GL_MAX_VERTEX_ATTRIB_BINDINGS     0x82DA
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_MAX_VERTEX_ATTRIBS             0x8869
#endif	// __gl_h__
#endif
#if (NW_GAPI & NW_GAPI_D3D)
struct ID3D11InputLayout;
namespace NW
{
	//
}
#endif
#endif	// NW_GAPI
#endif	// NW_GFX_LIB_LAYOUT_H
