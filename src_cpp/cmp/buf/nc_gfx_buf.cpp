#include "nc_gfx_pch.hpp"
#include "nc_gfx_buf.h"
#if (defined NC_GAPI)
#	include "core/nc_nc_gfx_eng.h"
#	if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	gfx_buf_t::gfx_buf_t() : nc_cmp_tt(), gfx_cmp_t(), m_handle(NC_NULL) { }
	gfx_buf_t::gfx_buf_t(layt_tc& layout, size_t count) : gfx_buf_t() { NC_CHECK(mem_buf_t::remake(layout, count), "remake error!", return); }
	gfx_buf_t::gfx_buf_t(layt_tc& layout, size_t count, ptr_tc data) : gfx_buf_t() { NC_CHECK(mem_buf_t::remake(layout, count, data), "remake error!", return); }
	gfx_buf_t::gfx_buf_t(gbuf_tc& copy) : gfx_buf_t() { operator=(copy); }
	gfx_buf_t::gfx_buf_t(gbuf_t&& copy) : gfx_buf_t() { operator=(copy); }
	gfx_buf_t::~gfx_buf_t() { if (m_handle != NC_NULL) { get_context()->buf_del(1u, &m_handle); m_handle = NC_NULL; } }
	// setters //
	gfx_buf_t::buf_t& gfx_buf_t::set_data(size_t key, ptr_tc data, size_t count) { mem_buf_t::set_data(key, data, count); return *this; }
	// operators //
	op_stream_t& gfx_buf_t::operator<<(op_stream_t& stm) const { mem_buf_t::operator<<(stm); return stm; }
	ip_stream_t& gfx_buf_t::operator>>(ip_stream_t& stm) { mem_buf_t::operator>>(stm); return stm; }
	// commands //
	v1bit_t gfx_buf_t::remake()
	{
		if (m_handle != NC_NULL) { get_context()->buf_del(1u, &m_handle); m_handle = NC_NULL; }
		NC_CHECK(mem_buf_t::remake(), "remake error!", return NC_FALSE);
		get_context()->buf_new(1u, &m_handle);

		return NC_TRUTH;
	}
	v1nil_t gfx_buf_t::on_draw() { }
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
namespace NC
{
	gfx_buf_t::gfx_buf_t(nc_gfx_eng& graphics) :
		gfx_cmp_t(graphics), mem_elem(),
		m_handle(NC_NULL)
	{
	}
	gfx_buf_t::~gfx_buf_t() { if (m_handle != NC_NULL) { m_handle->Release(); m_handle = NC_NULL; } }
	// commands //
	v1bit_t gfx_buf_t::remake()
	{
		if (m_handle != NC_NULL) { m_handle->Release(); m_handle = NC_NULL; }
		
		return NC_TRUTH;
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NC_API