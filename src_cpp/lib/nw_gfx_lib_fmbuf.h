#ifndef NW_GFX_LIB_FRAMEBUFFER_H
#define NW_GFX_LIB_FRAMEBUFFER_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_lib_core.h"
namespace NW
{
	extern v1bit gfx_load_fmbuf();
}
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	// general
	typedef v1nil(NW_API_ENTRYP pfn_gfx_fmbuf_gen)(GLsizei count, GLuint* fmbuf_ids);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_fmbuf_del)(GLsizei count, const GLuint* fmbuf_ids);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_fmbuf_bind)(GLenum fmbuf_type, GLuint fmbuf_id);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_fmbuf_clear)(GLbitfield attachments_bitmask);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_fmbuf_clear_color)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	// attachments
	typedef v1nil(NW_API_ENTRYP pfn_gfx_fmbuf_txr_1d)(GLenum fmbuf_type, GLenum atch_type, GLenum txr_type, GLuint txr_id, GLint level);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_fmbuf_txr_2d)(GLenum fmbuf_type, GLenum atch_type, GLenum txr_type, GLuint txr_id, GLint level);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_fmbuf_txr_3d)(GLenum fmbuf_type, GLenum atch_type, GLenum txr_type, GLuint txr_id, GLint level, GLint offset_z);
	// draw and read
	typedef v1nil(NW_API_ENTRYP pfn_gfx_fmbuf_bind_draw)(GLenum atch_type);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_fmbuf_bind_read)(GLenum atch_type);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_fmbuf_bind_draws)(GLsizei count, const GLuint* buf_ids);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_fmbuf_bind_reads)(GLsizei count, const GLuint* buf_ids);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_fmbuf_draw_pixels)(GLsizei size_x, GLsizei size_h, GLenum data_format, GLenum data_type, const GLvoid* pixel_buf);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_fmbuf_read_pixels)(GLint crd_x, GLint crd_y, GLsizei size_x, GLsizei size_h, GLenum data_format, GLenum data_type, GLvoid* pixel_buf);
	// info
	typedef GLenum(NW_API_ENTRYP pfn_gfx_fmbuf_check)(GLenum status_type);
}
namespace NW
{
	// general
	extern pfn_gfx_fmbuf_gen ogl_fmbuf_gen;
	extern pfn_gfx_fmbuf_del ogl_fmbuf_del;
	extern pfn_gfx_fmbuf_bind ogl_fmbuf_bind;
	extern pfn_gfx_fmbuf_clear ogl_fmbuf_clear;
	extern pfn_gfx_fmbuf_clear_color ogl_fmbuf_clear_color;
	// attachments
	extern pfn_gfx_fmbuf_txr_1d ogl_fmbuf_txr_1d;
	extern pfn_gfx_fmbuf_txr_2d ogl_fmbuf_txr_2d;
	extern pfn_gfx_fmbuf_txr_3d ogl_fmbuf_txr_3d;
	// draw and read
	extern pfn_gfx_fmbuf_bind_draw ogl_fmbuf_bind_draw;
	extern pfn_gfx_fmbuf_bind_read ogl_fmbuf_bind_read;
	extern pfn_gfx_fmbuf_bind_draws ogl_fmbuf_bind_draws;
	extern pfn_gfx_fmbuf_bind_reads ogl_fmbuf_bind_reads;
	extern pfn_gfx_fmbuf_draw_pixels ogl_fmbuf_draw_pixels;
	extern pfn_gfx_fmbuf_read_pixels ogl_fmbuf_read_pixels;
	// info
	extern pfn_gfx_fmbuf_check ogl_fmbuf_check;
}
// general
#define glGenFramebuffers ogl_fmbuf_gen
#define glDeleteFramebuffers ogl_fmbuf_del
#define glBindFramebuffer ogl_fmbuf_bind
#define glClear ogl_fmbuf_clear
#define glClearColor ogl_fmbuf_clear_color
// attachments
#define glFramebufferTexture1D ogl_fmbuf_txr_1d
#define glFramebufferTexture2D ogl_fmbuf_txr_2d
#define glFramebufferTexture3D ogl_fmbuf_txr_3d
// draw and read
#define glDrawBuffer ogl_fmbuf_bind_draw
#define glReadBuffer ogl_fmbuf_bind_read
#define glReadBuffers ogl_fmbuf_bind_reads
#define glDrawBuffers ogl_fmbuf_bind_draws
#define glDrawPixels ogl_fmbuf_draw_pixels
#define glReadPixels ogl_fmbuf_read_pixels
// info
#define glCheckFramebufferStatus ogl_fmbuf_check

#	ifndef __gl_h__
		// general
#		define GL_FRAMEBUFFER                    0x8D40
#		define GL_READ_FRAMEBUFFER               0x8CA8
#		define GL_MAX_SAMPLES                    0x8D57
#		define GL_DRAW_FRAMEBUFFER               0x8CA9
#		define GL_FRAMEBUFFER_BINDING            0x8CA6
#		define GL_DRAW_FRAMEBUFFER_BINDING       0x8CA6
#		define GL_RENDERBUFFER_BINDING           0x8CA7
#		define GL_READ_FRAMEBUFFER_BINDING       0x8CAA
#		define GL_UNSIGNED_NORMALIZED            0x8C17
		// pixel copy types
#		define GL_COLOR                          0x1800
#		define GL_DEPTH                          0x1801
#		define GL_STENCIL                        0x1802
		// states
#		define GL_FRAMEBUFFER_COMPLETE           0x8CD5
#		define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#		define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#		define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
		// color
#		define GL_COLOR_ATTACHMENT0              0x8CE0
#		define GL_COLOR_ATTACHMENT1              0x8CE1
#		define GL_COLOR_ATTACHMENT2              0x8CE2
#		define GL_COLOR_ATTACHMENT3              0x8CE3
#		define GL_COLOR_ATTACHMENT4              0x8CE4
#		define GL_COLOR_ATTACHMENT5              0x8CE5
#		define GL_COLOR_ATTACHMENT6              0x8CE6
#		define GL_COLOR_ATTACHMENT7              0x8CE7
#		define GL_COLOR_ATTACHMENT8              0x8CE8
#		define GL_COLOR_ATTACHMENT9              0x8CE9
#		define GL_COLOR_ATTACHMENT10             0x8CEA
#		define GL_COLOR_ATTACHMENT11             0x8CEB
#		define GL_COLOR_ATTACHMENT12             0x8CEC
#		define GL_COLOR_ATTACHMENT13             0x8CED
#		define GL_COLOR_ATTACHMENT14             0x8CEE
#		define GL_COLOR_ATTACHMENT15             0x8CEF
#		define GL_MAX_COLOR_ATTACHMENTS          0x8CDF
		// depth
#		define GL_DEPTH_RANGE                    0x0B70
#		define GL_DEPTH_TEST                     0x0B71
#		define GL_DEPTH_WRITEMASK                0x0B72
#		define GL_DEPTH_CLEAR_VALUE              0x0B73
#		define GL_DEPTH_FUNC                     0x0B74
#		define GL_ACCUM_CLEAR_VALUE              0x0B80
#		define GL_DEPTH_ATTACHMENT               0x8D00
#		define GL_DEPTH_COMPONENT                0x1902
#		define GL_DEPTH_COMPONENT16              0x81A5
#		define GL_DEPTH_COMPONENT24              0x81A6
#		define GL_DEPTH_COMPONENT32              0x81A7
		// stencil
#		define GL_STENCIL_ATTACHMENT             0x8D20
#		define GL_STENCIL_INDEX                  0x1901
#		define GL_STENCIL_INDEX1                 0x8D46
#		define GL_STENCIL_INDEX4                 0x8D47
#		define GL_STENCIL_INDEX8                 0x8D48
#		define GL_STENCIL_INDEX16                0x8D49
#		define GL_STENCIL_TEST                   0x0B90
#		define GL_STENCIL_CLEAR_VALUE            0x0B91
#		define GL_STENCIL_FUNC                   0x0B92
#		define GL_STENCIL_VALUE_MASK             0x0B93
#		define GL_STENCIL_FAIL                   0x0B94
#		define GL_STENCIL_PASS_DEPTH_FAIL        0x0B95
#		define GL_STENCIL_PASS_DEPTH_PASS        0x0B96
#		define GL_STENCIL_REF                    0x0B97
#		define GL_STENCIL_WRITEMASK              0x0B98
		// depth and stencil
#		define GL_DEPTH_STENCIL_ATTACHMENT       0x821A
#		define GL_DEPTH_STENCIL                  0x84F9
#		define GL_DEPTH24_STENCIL8               0x88F0
#		define GL_UNSIGNED_INT_24_8              0x84FA
		// renderbuffer
#		define GL_RENDERBUFFER                   0x8D41
#		define GL_RENDERBUFFER_WIDTH             0x8D42
#		define GL_RENDERBUFFER_HEIGHT            0x8D43
#		define GL_RENDERBUFFER_INTERNAL_FORMAT   0x8D44
#		define GL_RENDERBUFFER_RED_SIZE          0x8D50
#		define GL_RENDERBUFFER_GREEN_SIZE        0x8D51
#		define GL_RENDERBUFFER_BLUE_SIZE         0x8D52
#		define GL_RENDERBUFFER_ALPHA_SIZE        0x8D53
#		define GL_RENDERBUFFER_DEPTH_SIZE        0x8D54
#		define GL_RENDERBUFFER_STENCIL_SIZE      0x8D55
#		define GL_RENDERBUFFER_SAMPLES           0x8CAB
		// bit mask
#		define GL_DEPTH_BUFFER_BIT               0x00000100
#		define GL_ACCUM_BUFFER_BIT               0x00000200
#		define GL_STENCIL_BUFFER_BIT             0x00000400
#		define GL_COLOR_BUFFER_BIT               0x00004000
		// format
#		define GL_DEPTH_COMPONENT32F             0x8CAC
#		define GL_DEPTH32F_STENCIL8              0x8CAD
#		define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
		// drawbuffers
#		define GL_MAX_DRAW_BUFFERS               0x8824
#		define GL_DRAW_BUFFER0                   0x8825
#		define GL_DRAW_BUFFER1                   0x8826
#		define GL_DRAW_BUFFER2                   0x8827
#		define GL_DRAW_BUFFER3                   0x8828
#		define GL_DRAW_BUFFER4                   0x8829
#		define GL_DRAW_BUFFER5                   0x882A
#		define GL_DRAW_BUFFER6                   0x882B
#		define GL_DRAW_BUFFER7                   0x882C
#		define GL_DRAW_BUFFER8                   0x882D
#		define GL_DRAW_BUFFER9                   0x882E
#		define GL_DRAW_BUFFER10                  0x882F
#		define GL_DRAW_BUFFER11                  0x8830
#		define GL_DRAW_BUFFER12                  0x8831
#		define GL_DRAW_BUFFER13                  0x8832
#		define GL_DRAW_BUFFER14                  0x8833
#		define GL_DRAW_BUFFER15                  0x8834
#		endif	// __gl_h__
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
struct ID3D11RenderTarget;
struct ID3D11RenderTargetView;
namespace NW
{
}
#	endif	// GAPI_D3D
#endif	// NW_GAPI
#endif	// NW_GFX_LIB_FRAMEBUFFER_H
