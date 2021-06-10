#ifndef NC_GFX_SHADER_BUFFER_H
#define NC_GFX_SHADER_BUFFER_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "nc_gfx_buf.hxx"
#	include "mem/nc_mem_buf.hxx"
namespace NC
{
	/// shader_buffer class
	/// description:
	/// --it is used by shaders as opengl uniform buffer, or as directx constant buffer;
	class gfx_buf_shd_t : public gfx_buf_t
	{
	public:
		using gsbuf_t = gfx_buf_shd_t;
		using gsbuf_tc = const gsbuf_t;
	public:
		gfx_buf_shd_t();
		gfx_buf_shd_t(gsbuf_tc& copy);
		gfx_buf_shd_t(gsbuf_t&& copy);
		gfx_buf_shd_t(layt_tc& layout, size_t count);
		gfx_buf_shd_t(layt_tc& layout, size_t count, ptr_tc data);
		virtual ~gfx_buf_shd_t();
		/* getters */
		inline v1u_tc get_slot() const { return m_slot; }
		/* setters */
		gsbuf_t& set_slot(v1u_tc slot);
		inline gsbuf_t& set_data() { mem_buf_t::set_data(); return *this; }
		inline gsbuf_t& set_data(ptr_tc data) { mem_buf_t::set_data(data); return *this; }
		inline gsbuf_t& set_data(size_t key, ptr_tc data) { mem_buf_t::set_data(key, data); return *this; }
		inline gsbuf_t& set_data(ptr_tc data, size_t count) { mem_buf_t::set_data(data, count); return *this; }
		virtual buf_t& set_data(size_t key, ptr_tc data, size_t count) override;
		/* vetters */
		/* operators */
		inline gsbuf_t& operator=(gsbuf_tc& copy) { NC_CHECK(remake(copy.get_layt(), copy.get_count(), copy.get_data()), "remake error!", return *this); return set_slot(copy.get_slot()); }
		inline gsbuf_t& operator=(gsbuf_t&& copy) { NC_CHECK(remake(copy.get_layt(), copy.get_count(), copy.get_data()), "remake error!", return *this); return set_slot(copy.get_slot()); }
		virtual nc_ostream_t& operator<<(nc_ostream_t& stm) const override;
		virtual nc_istream_t& operator>>(nc_istream_t& stm) override;
		/* command */
		inline v1bit_t remake(layt_tc& layout, size_t count) { return gfx_buf_t::remake(layout, count); }
		inline v1bit_t remake(layt_tc& layout, size_t count, ptr_tc data) { return gfx_buf_t::remake(layout, count, data); }
		virtual v1bit_t remake() override;
		virtual v1nil_t on_draw() override;
	private:
		v1u_t m_slot;
	};
}
#endif	// NC_GAPI
#endif	// NC_GFX_SHADER_BUFFER_H
