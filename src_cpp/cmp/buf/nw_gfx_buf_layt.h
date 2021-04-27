#ifndef NW_GFX_BUFFER_LAYOUT_H
#define NW_GFX_BUFFER_LAYOUT_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "../nw_gfx_cmp.h"
#	include "../buf/nw_gfx_buf_vtx.h"
#	include "../buf/nw_gfx_buf_idx.h"
#	include "mem/nw_mem_layt.h"
namespace NW
{
	/// graphics_buffer_layout class
	/// description:
	/// --default input assembler tool for vertex shaders;
	/// --equivalent of the vertex array in opengl;
	class NW_API gfx_buf_layt : public t_cmp<gfx_buf_layt>, public a_gfx_cmp
	{
	public:
		using buf_layt_t = gfx_buf_layt;
		using buf_layt_tc = const buf_layt_t;
		using layt_t = mem_layt;
		using layt_tc = const layt_t;
#	if (NW_GAPI & NW_GAPI_OGL)
		using handle_t = GLuint;
#	endif
#	if (NW_GAPI & NW_GAPI_D3D)
		using handle_t = ID3D11InputLayout*;
#	endif
		using handle_tc = const handle_t;
	public:
		gfx_buf_layt();
		gfx_buf_layt(buf_layt_tc& copy);
		gfx_buf_layt(buf_layt_t&& copy);
		virtual ~gfx_buf_layt();
		// --getters
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		inline layt_t& get_layt()        { return m_layt; }
		inline layt_tc& get_layt() const { return m_layt; }
		// --setters
		buf_layt_t& set_layt(layt_tc& layout);
		// --predicates
		// --operators
		inline operator layt_t* ()        { return &m_layt; }
		inline operator layt_tc* () const { return &m_layt; }
		inline operator layt_t& ()        { return m_layt; }
		inline operator layt_tc& () const { return m_layt; }
		inline buf_layt_t& operator=(buf_layt_tc& copy) { NW_CHECK(remake(copy.get_layt()), "remake error!", return *this); return *this; }
		inline buf_layt_t& operator=(buf_layt_t&& copy) { NW_CHECK(remake(copy.get_layt()), "remake error!", return *this); return *this; }
		// --core_methods
		v1bit remake();
		inline v1bit remake(layt_tc& layout) { set_layt(layout); return remake(); }
		virtual v1nil on_draw() override;
	private:
		handle_t m_handle;
		layt_t m_layt;
	};
}
#endif	// NW_GAPI
#endif	// NW_BUFFER_LAYOUT_H
