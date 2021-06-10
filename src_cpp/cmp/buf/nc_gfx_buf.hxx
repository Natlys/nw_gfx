#ifndef NC_GFX_BUFFER_H
#define NC_GFX_BUFFER_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "../nc_gfx_cmp.hxx"
#	include "mem/nc_mem_buf.hxx"
namespace NC
{
	/// graphics_buffer_type
	class gfx_buf_t : public nc_cmp_tt<gfx_buf_t>, public gfx_cmp_t, public mem_buf_t
	{
	public:
		using gbuf_t = gfx_buf_t;
		using gbuf_tc = const gbuf_t;
#	if (NC_GAPI & NC_GAPI_OGL)
		using handle_t = GLuint;
#	endif
#	if (NC_GAPI & NC_GAPI_D3D)
		using handle_t = ID3D11Buffer*;
#	endif
		using handle_tc = const handle_t;
	public:
		gfx_buf_t();
		gfx_buf_t(layt_tc& layout, size_t count);
		gfx_buf_t(layt_tc& layout, size_t count, ptr_tc data);
		gfx_buf_t(gbuf_tc& copy);
		gfx_buf_t(gbuf_t&& copy);
		virtual ~gfx_buf_t();
		/* getters */
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		/* setters */
		inline gbuf_t& set_data() { mem_buf_t::set_data(); return *this; }
		inline gbuf_t& set_data(ptr_tc data) { mem_buf_t::set_data(data); return *this; }
		inline gbuf_t& set_data(size_t key, ptr_tc data) { mem_buf_t::set_data(key, data); return *this; }
		inline gbuf_t& set_data(ptr_tc data, size_t count) { mem_buf_t::set_data(data, count); return *this; }
		virtual buf_t& set_data(size_t key, ptr_tc data, size_t count) override;
		/* operators */
		inline gbuf_t& operator=(gbuf_tc& copy) { NC_CHECK(remake(copy.get_layt(), copy.get_count(), copy.get_data()), "remake error!", return *this); return *this; }
		inline gbuf_t& operator=(gbuf_t&& copy) { NC_CHECK(remake(copy.get_layt(), copy.get_count(), copy.get_data()), "remake error!", return *this); return *this; }
		virtual nc_ostream_t& operator<<(nc_ostream_t& stm) const override;
		virtual nc_istream_t& operator>>(nc_istream_t& stm) override;
		/* command */
		inline v1bit_t remake(layt_tc& layout, size_t count) { return mem_buf_t::remake(layout, count); }
		inline v1bit_t remake(layt_tc& layout, size_t count, ptr_tc data) { return mem_buf_t::remake(layout, count, data); }
		virtual v1bit_t remake() override;
		virtual v1nil_t on_draw() override;
	protected:
		handle_t m_handle;
	};
}
#endif	// NC_GAPI
#endif	// NC_GFX_BUFFER_H
