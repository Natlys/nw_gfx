#ifndef NW_GFX_SHADER_LAYOUT_H
#define NW_GFX_SHADER_LAYOUT_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "../nw_gfx_cmp.h"
#	include "mem/nw_mem_layt.h"
#	include "../buf/nw_gfx_buf_vtx.h"
#	include "../buf/nw_gfx_buf_idx.h"
namespace NW
{
	/// graphics_buffer_layout class
	/// description:
	/// --default input assembler tool for vertex shaders;
	/// --equivalent of the vertex array in opengl;
	class NW_API gfx_buf_layt : public t_cmp<gfx_buf_layt>, public a_gfx_cmp, public mem_layt
	{
		using vbuf_t = mem_ref<gfx_buf_vtx>;
		using vbuf_tc = const vbuf_t;
		using vbufs_t = darray<vbuf_t>;
		using vbufs_tc = const vbufs_t;
		using ibuf_t = mem_ref<gfx_buf_idx>;
		using ibuf_tc = const ibuf_t;
#if (NW_GAPI & NW_GAPI_OGL)
		using handle_t = GLuint;
#endif
#if (NW_GAPI & NW_GAPI_D3D)
		using handle_t = ID3D11InputLayout*;
#endif
		using handle_tc = const handle_t;
	public:
		gfx_buf_layt(gfx_engine& graphics);
		virtual ~gfx_buf_layt();
		// --getters
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		inline vbufs_t& get_vbufs()        { return m_vbufs; }
		inline vbufs_tc& get_vbufs() const { return m_vbufs; }
		inline vbuf_t& get_vbuf(cv1u key = 0u)        { NW_CHECK(has_vbuf(key), "not found!", return vbuf_t()); return m_vbufs[key]; }
		inline vbuf_tc& get_vbuf(cv1u key = 0u) const { NW_CHECK(has_vbuf(key), "not found!", return vbuf_t()); return m_vbufs[key]; }
		inline ibuf_t& get_ibuf()        { return m_ibuf; }
		inline ibuf_tc& get_ibuf() const { return m_ibuf; }
		// --setters
		v1nil add_vbuf(vbuf_tc& ref);
		v1nil rmv_vbuf(cv1u key);
		v1nil set_ibuf(ibuf_tc& ref);
		// --predicates
		inline v1bit has_vbuf(cv1u key = 0u) const { return m_vbufs.size() > key; }
		inline v1bit has_ibuf() const { return m_ibuf.is_valid(); }
		// --core_methods
		v1bit remake();
		virtual v1nil on_draw() override;
	private:
		handle_t m_handle;
		vbufs_t m_vbufs;
		ibuf_t m_ibuf;
	};
}
#endif	// NW_GAPI
#endif	// NW_SHADER_LAYOUT_H