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
		using vtype_t = v1u;
		using vtype_tc = const vtype_t;
	public:
		gfx_buf_idx(gfx_engine& graphics);
		virtual ~gfx_buf_idx();
		// --getters
		inline vtype_tc get_vtype() const { return m_vtype; }
		// --setters
		v1nil set_vtype(vtype_tc type);
		virtual v1nil set_data(cv1u count, ptr_tc data, cv1u offset) override;
		// --core_methods
		virtual v1bit remake(cv1u stride, cv1u count, ptr_tc data = NW_NULL) override;
		virtual v1nil on_draw() override;
	private:
		vtype_t m_vtype;
	};
}
#endif	// NW_GAPI
#endif	// NW_INDEX_BUFFER_H