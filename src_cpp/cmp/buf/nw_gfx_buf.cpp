#include "nw_gfx_pch.hpp"
#include "nw_gfx_buf.h"
#if (defined NW_GAPI)
#	include "core/nw_gfx_engine.h"
#	include "lib/nw_gfx_lib_buf.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_buf::gfx_buf() :
		t_cmp(), a_gfx_cmp(),
		m_handle(NW_NULL)
	{
	}
	gfx_buf::gfx_buf(layt_tc& layout, cv1u count, ptr_tc data) :
		gfx_buf()
	{
		NW_CHECK(mem_buf::remake(layout, count, data), "remake error!", return);
	}
	gfx_buf::~gfx_buf() { if (m_handle != NW_NULL) { glDeleteBuffers(1u, &m_handle); m_handle = NW_NULL; } }
	// --setters
	gfx_buf::buf_t& gfx_buf::set_data(cv1u count, ptr_tc data, cv1u offset) {
		mem_buf::set_data(count, data, offset);
		return *this;
	}
	// --operators
	// --==<core_methods>==--
	v1bit gfx_buf::remake()
	{
		if (m_handle != NW_NULL) { glDeleteBuffers(1u, &m_handle); m_handle = NW_NULL; }
		NW_CHECK(mem_buf::remake(), "remake error!", return NW_FALSE);
		glGenBuffers(1u, &m_handle);

		return NW_TRUE;
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	gfx_buf::gfx_buf(gfx_engine& graphics) :
		a_gfx_cmp(graphics), mem_elem(),
		m_handle(NW_NULL)
	{
	}
	gfx_buf::~gfx_buf() { if (m_handle != NW_NULL) { m_handle->Release(); m_handle = NW_NULL; } }
	// --==<core_methods>==--
	v1bit gfx_buf::remake()
	{
		if (m_handle != NW_NULL) { m_handle->Release(); m_handle = NW_NULL; }
		
		return NW_TRUE;
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NW_API