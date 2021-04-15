#ifndef NW_GFX_VERTEX_BUFFER_H
#define NW_GFX_VERTEX_BUFFER_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_buf.h"
#	include "mem/nw_mem_buf.h"
namespace NW
{
	/// vertex_buffer class
	class NW_API gfx_buf_vtx : public a_gfx_buf
	{
	public:
		gfx_buf_vtx(gfx_engine& graphics);
		~gfx_buf_vtx();
		// --setters
		virtual v1nil set_data(cv1u count, ptr_tc data, cv1u offset = NW_NULL) override;
		// --core_methods
		virtual v1bit remake(cv1u stride, cv1u count, ptr_tc data = NW_NULL) override;
		virtual v1nil on_draw() override;
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_VERTEX_BUFFER_H
