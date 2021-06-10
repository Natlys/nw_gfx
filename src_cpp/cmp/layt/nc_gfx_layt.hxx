#ifndef NC_GFX_LAYOUT_H
#define NC_GFX_LAYOUT_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "../nc_gfx_cmp.hxx"
#	include "../buf/nc_gfx_buf_vtx.hxx"
#	include "../buf/nc_gfx_buf_idx.hxx"
#	include "mem/nc_mem_layt.hxx"
namespace NC
{
	/// graphics_layout_type
	/// description:
	/// --default input assembler tool for vertex shaders;
	/// --equivalent of the vertex array in opengl;
	class gfx_layt_t : public nc_cmp_tt<gfx_layt_t>, public gfx_cmp_t
	{
	public:
		using buf_layt_t = gfx_layt_t;
		using buf_layt_tc = const buf_layt_t;
		using layt_t = mem_layt_t;
		using layt_tc = const layt_t;
#	if (NC_GAPI & NC_GAPI_OGL)
		using handle_t = GLuint;
#	endif
#	if (NC_GAPI & NC_GAPI_D3D)
		using handle_t = ID3D11InputLayout*;
#	endif
		using handle_tc = const handle_t;
	public:
		/* codetor */
		gfx_layt_t();
		gfx_layt_t(buf_layt_tc& copy);
		gfx_layt_t(buf_layt_t&& copy);
		virtual ~gfx_layt_t();
		/* getters */
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		inline layt_t& get_layt()        { return m_layt; }
		inline layt_tc& get_layt() const { return m_layt; }
		/* setters */
		buf_layt_t& set_layt(layt_tc& layout);
		/* vetters */
		/* operators */
		inline operator layt_t* ()        { return &m_layt; }
		inline operator layt_tc* () const { return &m_layt; }
		inline operator layt_t& ()        { return m_layt; }
		inline operator layt_tc& () const { return m_layt; }
		inline buf_layt_t& operator=(buf_layt_tc& copy) { NC_CHECK(remake(copy.get_layt()), "remake error!", return *this); return *this; }
		inline buf_layt_t& operator=(buf_layt_t&& copy) { NC_CHECK(remake(copy.get_layt()), "remake error!", return *this); return *this; }
		/* command */
		v1bit_t remake();
		inline v1bit_t remake(layt_tc& layout) { set_layt(layout); return remake(); }
		virtual v1nil_t on_draw() override;
	private:
		handle_t m_handle;
		layt_t m_layt;
	};
}
#endif	// NC_GAPI
#endif	// NC_GFX_LAYOUT_H
