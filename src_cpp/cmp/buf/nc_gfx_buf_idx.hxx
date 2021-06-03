#ifndef NC_GFX_INDEX_BUFFER_H
#define NC_GFX_INDEX_BUFFER_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "nc_gfx_buf.hxx"
namespace NC
{
	/// graphics_index_buffer_type
	class gfx_buf_idx_t : public gfx_buf_t
	{
	public:
		using gibuf_t = gfx_buf_idx_t;
		using gibuf_tc = const gibuf_t;
	public:
		gfx_buf_idx_t();
		gfx_buf_idx_t(layt_tc& layout, size_t count);
		gfx_buf_idx_t(layt_tc& layout, size_t count, ptr_tc data);
		gfx_buf_idx_t(gibuf_tc& copy);
		gfx_buf_idx_t(gibuf_t&& copy);
		virtual ~gfx_buf_idx_t();
		/* getters */
		/* setters */
		inline gibuf_t& set_data() { mem_buf_t::set_data(); return *this; }
		inline gibuf_t& set_data(ptr_tc data) { mem_buf_t::set_data(data); return *this; }
		inline gibuf_t& set_data(size_t key, ptr_tc data) { mem_buf_t::set_data(key, data); return *this; }
		inline gibuf_t& set_data(ptr_tc data, size_t count) { mem_buf_t::set_data(data, count); return *this; }
		virtual buf_t& set_data(size_t key, ptr_tc data, size_t space) override;
		/* vetters */
		/* operators */
		inline gibuf_t& operator=(gibuf_tc& copy) { NC_CHECK(remake(copy.get_layt(), copy.get_count(), copy.get_data()), "remake error!", return *this); return *this; }
		inline gibuf_t& operator=(gibuf_t&& copy) { NC_CHECK(remake(copy.get_layt(), copy.get_count(), copy.get_data()), "remake error!", return *this); return *this; }
		virtual nc_ostream_t& operator<<(nc_ostream_t& stm) const override;
		virtual nc_istream_t& operator>>(nc_istream_t& stm) override;
		/* commands */
		inline v1bit_t remake(layt_tc& layout, size_t count) { return gfx_buf_t::remake(layout, count); }
		inline v1bit_t remake(layt_tc& layout, size_t count, ptr_tc data) { return gfx_buf_t::remake(layout, count, data); }
		virtual v1bit_t remake() override;
		virtual v1nil_t on_draw() override;
	};
}
#endif	// NC_GAPI
#endif	// NC_INDEX_BUFFER_H