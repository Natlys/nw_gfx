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
	class NW_API gfx_buf_layt : public t_cmp<gfx_buf_layt>, public a_gfx_cmp, public mem_layt
	{
	public:
#	if (NW_GAPI & NW_GAPI_OGL)
		using handle_t = GLuint;
#	endif
#	if (NW_GAPI & NW_GAPI_D3D)
		using handle_t = ID3D11InputLayout*;
#	endif
		using handle_tc = const handle_t;
	public:
		gfx_buf_layt();
		virtual ~gfx_buf_layt();
		// --getters
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		// --setters
		// --predicates
		// --core_methods
		v1bit remake();
		virtual v1nil on_draw() override;
	private:
		handle_t m_handle;
	};
}
#endif	// NW_GAPI
#endif	// NW_BUFFER_LAYOUT_H