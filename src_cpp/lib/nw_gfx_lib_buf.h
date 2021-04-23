#ifndef NW_GFX_LIB_BUFFER_H
#define NW_GFX_LIB_BUFFER_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_lib_core.h"
namespace NW
{
	extern v1bit gfx_load_buf();
}
#define NW_GFX_MAX_SLOTS_BUF  10u
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	// general
	typedef v1nil(NW_API_ENTRYP pfn_gfx_buf_gen)(GLsizei count, GLuint* buf_ids);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_buf_del)(GLsizei count, const GLuint* buf_ids);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_buf_bind)(GLenum buf_type, GLuint buf_id);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_buf_bind_range)(GLenum buf_type, GLuint bind_idx, GLuint buf_id, GLintptr offset, GLsizeiptr size);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_buf_bind_base)(GLenum buf_type, GLuint bind_idx, GLuint buf_id);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_vbuf_bind)(GLuint bind_idx, GLuint vbuf_id, GLintptr offset, GLsizei stride);
	// data
	typedef v1nil(NW_API_ENTRYP pfn_gfx_buf_data)(GLenum buf_type, GLsizei data_size, const GLvoid* data_ptr, GLenum data_access_type);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_buf_sub_data)(GLenum buf_type, GLsizei offset_size, GLsizei data_size, const GLvoid* data_ptr);
}
namespace NW
{
	// general
	extern pfn_gfx_buf_gen ogl_buf_gen;
	extern pfn_gfx_buf_del ogl_buf_del;
	extern pfn_gfx_buf_bind ogl_buf_bind;
	extern pfn_gfx_buf_bind_range ogl_buf_bind_range;
	extern pfn_gfx_buf_bind_base ogl_buf_bind_base;
	extern pfn_gfx_vbuf_bind ogl_vbuf_bind;
	// data
	extern pfn_gfx_buf_data ogl_buf_data;
	extern pfn_gfx_buf_sub_data ogl_buf_sub_data;
}
// general
#define glGenBuffers ogl_buf_gen
#define glDeleteBuffers ogl_buf_del
#define glBindBuffer ogl_buf_bind
#define glBindBufferRange ogl_buf_bind_range
#define glBindBufferBase ogl_buf_bind_base
#define glBindVertexBuffer ogl_vbuf_bind
// data
#define glBufferData ogl_buf_data
#define glBufferSubData ogl_buf_sub_data

#	ifndef __gl_h__
	// general
#		define GL_BUFFER                         0x82E0
#		define GL_DRAW_BUFFER                    0x0C01
#		define GL_READ_BUFFER                    0x0C02
#		define GL_COPY_READ_BUFFER_BINDING       0x8F36
#		define GL_COPY_READ_BUFFER               GL_COPY_READ_BUFFER_BINDING
#		define GL_COPY_WRITE_BUFFER_BINDING      0x8F37
#		define GL_COPY_WRITE_BUFFER              GL_COPY_WRITE_BUFFER_BINDING
#		define GL_READ_ONLY                      0x88B8
#		define GL_WRITE_ONLY                     0x88B9
#		define GL_READ_WRITE                     0x88BA
#		define GL_BUFFER_ACCESS                  0x88BB
#		define GL_BUFFER_MAPPED                  0x88BC
#		define GL_STREAM_DRAW                    0x88E0
#		define GL_STREAM_READ                    0x88E1
#		define GL_STREAM_COPY                    0x88E2
#		define GL_STATIC_DRAW                    0x88E4
#		define GL_STATIC_READ                    0x88E5
#		define GL_STATIC_COPY                    0x88E6
#		define GL_DYNAMIC_DRAW                   0x88E8
#		define GL_DYNAMIC_READ                   0x88E9
#		define GL_DYNAMIC_COPY                   0x88EA
		// vertex buffer
#		define GL_ARRAY_BUFFER                   0x8892
#		define GL_ARRAY_BUFFER_BINDING           0x8894
		// index buffer
#		define GL_ELEMENT_ARRAY_BUFFER           0x8893
#		define GL_ELEMENT_ARRAY_BUFFER_BINDING   0x8895
		// uniform buffer
#		define GL_UNIFORM_BUFFER                 0x8A11
#		define GL_UNIFORM_BUFFER_BINDING         0x8A28
#		define GL_UNIFORM_BUFFER_START           0x8A29
#		define GL_UNIFORM_BUFFER_SIZE            0x8A2A
#		define GL_MAX_UNIFORM_BUFFER_BINDINGS    0x8A2F
#		define GL_MAX_UNIFORM_BLOCK_SIZE         0x8A30
#		define GL_UNIFORM_BLOCK_BINDING          0x8A3F
#		endif	// __gl_h__
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
struct ID3D11Buffer;
namespace NW
{
	//
}
#	endif	// GAPI_D3D
#endif	// NW_GAPI
#endif	// NW_GFX_LIB_BUFFER_H
