#ifndef NW_GFX_INDEX_BUFFER_H
#define NW_GFX_INDEX_BUFFER_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_buf.h"
namespace NW
{
	/// index_buffer class
	class NW_API gfx_buf_idx : public a_gfx_buf
	{
	public:
		gfx_buf_idx();
		gfx_buf_idx(layt_tc& layout, cv1u count, ptr_tc data = NW_NULL);
		virtual ~gfx_buf_idx();
		// --getters
		// --setters
		virtual v1nil set_data(cv1u key = NW_NULL, ptr_tc data = NW_NULL, cv1u count = NW_NULL) override;
		// --core_methods
		virtual v1bit remake() override;
		virtual v1nil on_draw() override;
	};
}
#endif	// NW_GAPI
#endif	// NW_INDEX_BUFFER_H