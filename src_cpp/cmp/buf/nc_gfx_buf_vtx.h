#ifndef NC_GFX_VERTEX_BUFFER_H
#define NC_GFX_VERTEX_BUFFER_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "nc_gfx_buf.h"
#	include "mem/nc_mem_buf.h"
namespace NC
{
	/// vertex_buffer class
	class NC_API gfx_buf_vtx_t : public gfx_buf_t
	{
	public:
		using gvbuf_t = gfx_buf_vtx_t;
		using gvbuf_tc = const gvbuf_t;
	public:
		gfx_buf_vtx_t();
		gfx_buf_vtx_t(gvbuf_tc& copy);
		gfx_buf_vtx_t(gvbuf_t&& copy);
		gfx_buf_vtx_t(layt_tc& layout, size_t count);
		gfx_buf_vtx_t(layt_tc& layout, size_t count, ptr_tc data);
		virtual ~gfx_buf_vtx_t();
		// getters //
		// setters //
		inline gvbuf_t& set_data() { mem_buf_t::set_data(); return *this; }
		inline gvbuf_t& set_data(ptr_tc data) { mem_buf_t::set_data(data); return *this; }
		inline gvbuf_t& set_data(size_t key, ptr_tc data) { mem_buf_t::set_data(key, data); return *this; }
		inline gvbuf_t& set_data(ptr_tc data, size_t count) { mem_buf_t::set_data(data, count); return *this; }
		virtual buf_t& set_data(size_t key, ptr_tc data, size_t count) override;
		// predicates //
		// operators //
		inline gvbuf_t& operator=(gvbuf_tc& copy) { NC_CHECK(remake(copy.get_layt(), copy.get_count(), copy.get_data()), "remake error!", return *this); return *this; }
		inline gvbuf_t& operator=(gvbuf_t&& copy) { NC_CHECK(remake(copy.get_layt(), copy.get_count(), copy.get_data()), "remake error!", return *this); return *this; }
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// commands //
		inline v1bit_t remake(layt_tc& layout, size_t count) { return gfx_buf_t::remake(layout, count); }
		inline v1bit_t remake(layt_tc& layout, size_t count, ptr_tc data) { return gfx_buf_t::remake(layout, count, data); }
		virtual v1bit_t remake() override;
		virtual v1nil_t on_draw() override;
	};
}
#endif	// NC_GAPI
#endif	// NC_GFX_VERTEX_BUFFER_H
