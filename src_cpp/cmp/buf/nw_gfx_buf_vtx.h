#ifndef NW_GFX_VERTEX_BUFFER_H
#define NW_GFX_VERTEX_BUFFER_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_buf.h"
#	include "mem/nw_mem_buf.h"
namespace NW
{
	/// vertex_buffer class
	class NW_API gfx_buf_vtx : public gfx_buf
	{
	public:
		gfx_buf_vtx();
		gfx_buf_vtx(layt_tc& layout, cv1u count, ptr_tc data = NW_NULL);
		virtual ~gfx_buf_vtx();
		// --setters
		virtual buf_t& set_data(cv1u key = NW_NULL, ptr_tc data = NW_NULL, cv1u count = NW_NULL) override;
		// --core_methods
		virtual v1bit remake() override;
		virtual v1nil on_draw() override;
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_VERTEX_BUFFER_H
