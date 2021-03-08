#ifndef NWG_LOAD_BUF_H
#define NWG_LOAD_BUF_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include "nwg_load_base.h"
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	extern bit ogl_load_buf();
}
namespace NWG
{
	// general
	typedef void (APIENTRYP pfn_ogl_buf_gen)(GLsizei count, GLuint* buf_ids);
	typedef void (APIENTRYP pfn_ogl_buf_del)(GLsizei count, const GLuint* buf_ids);
	typedef void (APIENTRYP pfn_ogl_buf_bind)(GLenum buf_type, GLuint buf_id);
	typedef void (APIENTRYP pfn_ogl_buf_bind_range)(GLenum buf_type, GLuint bind_idx, GLuint buf_id, GLintptr offset, GLsizeiptr size);
	typedef void (APIENTRYP pfn_ogl_buf_bind_base)(GLenum buf_type, GLuint bind_idx, GLuint buf_id);
	typedef void (APIENTRYP pfn_ogl_vbuf_bind)(GLuint bind_idx, GLuint vbuf_id, GLintptr offset, GLsizei stride);
	// data
	typedef void (APIENTRYP pfn_ogl_buf_data)(GLenum buf_type, GLsizei data_size, cptr data_ptr, GLenum data_access_type);
	typedef void (APIENTRYP pfn_ogl_buf_sub_data)(GLenum buf_type, GLsizei offset_size, GLsizei data_size, cptr data_ptr);
}
namespace NWG
{
	// general
	extern pfn_ogl_buf_gen ogl_buf_gen;
	extern pfn_ogl_buf_del ogl_buf_del;
	extern pfn_ogl_buf_bind ogl_buf_bind;
	extern pfn_ogl_buf_bind_range ogl_buf_bind_range;
	extern pfn_ogl_buf_bind_base ogl_buf_bind_base;
	extern pfn_ogl_vbuf_bind ogl_vbuf_bind;
	// data
	extern pfn_ogl_buf_data ogl_buf_data;
	extern pfn_ogl_buf_sub_data ogl_buf_sub_data;
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

#ifndef __gl_h__
// general
#define GL_BUFFER                         0x82E0
#define GL_COPY_READ_BUFFER_BINDING       0x8F36
#define GL_COPY_READ_BUFFER               GL_COPY_READ_BUFFER_BINDING
#define GL_COPY_WRITE_BUFFER_BINDING      0x8F37
#define GL_COPY_WRITE_BUFFER              GL_COPY_WRITE_BUFFER_BINDING
#define GL_READ_ONLY                      0x88B8
#define GL_WRITE_ONLY                     0x88B9
#define GL_READ_WRITE                     0x88BA
#define GL_BUFFER_ACCESS                  0x88BB
#define GL_BUFFER_MAPPED                  0x88BC
#define GL_STREAM_DRAW                    0x88E0
#define GL_STREAM_READ                    0x88E1
#define GL_STREAM_COPY                    0x88E2
#define GL_STATIC_DRAW                    0x88E4
#define GL_STATIC_READ                    0x88E5
#define GL_STATIC_COPY                    0x88E6
#define GL_DYNAMIC_DRAW                   0x88E8
#define GL_DYNAMIC_READ                   0x88E9
#define GL_DYNAMIC_COPY                   0x88EA
// vertex array
#define GL_VERTEX_ARRAY_BINDING           0x85B5
#define GL_VERTEX_ATTRIB_BINDING          0x82D4
#define GL_MAX_VERTEX_ATTRIB_BINDINGS     0x82DA
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_MAX_VERTEX_ATTRIBS             0x8869
// vertex buffer
#define GL_ARRAY_BUFFER                   0x8892
#define GL_ARRAY_BUFFER_BINDING           0x8894
// index buffer
#define GL_ELEMENT_ARRAY_BUFFER           0x8893
#define GL_ELEMENT_ARRAY_BUFFER_BINDING   0x8895
// uniform buffer
#define GL_UNIFORM_BUFFER                 0x8A11
#define GL_UNIFORM_BUFFER_BINDING         0x8A28
#define GL_UNIFORM_BUFFER_START           0x8A29
#define GL_UNIFORM_BUFFER_SIZE            0x8A2A
#define GL_MAX_UNIFORM_BUFFER_BINDINGS    0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE         0x8A30
#define GL_UNIFORM_BLOCK_BINDING          0x8A3F
#endif	// __gl_h__
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
#endif
#endif	// NWG_GAPI
#endif	// NWG_LOAD_BUF_H