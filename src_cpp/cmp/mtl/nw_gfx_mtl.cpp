#include "nw_gfx_pch.hpp"
#include "nw_gfx_mtl.h"
#if (defined NW_GAPI)
#include "core/nw_gfx_engine.h"
#	include "lib/nw_gfx_lib_txr.h"
#	include "lib/nw_gfx_lib_mtl.h"
#	include "lib/nw_gfx_lib_shd.h"
#	include "lib/nw_gfx_lib_debug.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_mtl::gfx_mtl() : t_cmp(), a_gfx_cmp(), a_iop_cmp(), m_handle(NW_NULL), m_binds(binds_t()) { }
	gfx_mtl::gfx_mtl(binds_tc& binds) : gfx_mtl() { NW_CHECK(remake(binds), "remake error!", return); }
	gfx_mtl::gfx_mtl(bind_list_tc& binds) : gfx_mtl() { NW_CHECK(remake(binds), "remake error!", return); }
	gfx_mtl::gfx_mtl(mtl_tc& copy) : gfx_mtl() { operator=(copy); }
	gfx_mtl::gfx_mtl(mtl_t&& copy) : gfx_mtl() { operator=(copy); }
	gfx_mtl::~gfx_mtl() { if (m_handle != NW_NULL) { glDeleteProgram(m_handle); m_handle = NW_NULL; } }
	// --setters
	gfx_mtl::mtl_t& gfx_mtl::set_binds(binds_tc& binds) { m_binds.clear(); for (auto& ibind : binds) { add_bind(ibind); } return *this; }
	gfx_mtl::mtl_t& gfx_mtl::set_binds(bind_list_tc& binds) { m_binds.clear(); for (auto& ibind : binds) { add_bind(ibind); } return *this; }
	gfx_mtl::mtl_t& gfx_mtl::add_bind(bind_tc& ref) { m_binds.push_back(ref); return *this; }
	gfx_mtl::mtl_t& gfx_mtl::rmv_bind(size_tc key) { NW_CHECK(has_bind(key), "key error!", return *this); m_binds.erase(m_binds.begin() + key); return *this; }
	// --operators
	op_stream_t& gfx_mtl::operator<<(op_stream_t& stm) const { return stm; }
	ip_stream_t& gfx_mtl::operator>>(ip_stream_t& stm) { return stm; }
	// --==<core_methods>==--
	v1nil gfx_mtl::on_draw() {
		glUseProgram(get_handle());
		for (auto& ibind : m_binds) { ibind->on_draw(); }
	}
	v1bit gfx_mtl::remake()
	{
		if (m_handle != NW_NULL) { glDeleteProgram(m_handle); m_handle = NW_NULL; }
		NW_CHECK(has_binds(), "no binders!", return NW_FALSE);
		
		m_handle = glCreateProgram();

		for (auto& ibind : m_binds) { glAttachShader(get_handle(), ibind->get_shd()->get_handle()); }
		glLinkProgram(get_handle());
		NW_CHECK(gfx_check_shader(get_handle()), "remake error!", return NW_FALSE);

		return NW_TRUE;
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	gfx_mtl::gfx_mtl(gfx_engine& graphics) :
		t_cmp(), a_gfx_cmp(graphics), a_io_cmp()
	{
	}
	gfx_mtl::~gfx_mtl() { }
	// --setters
	void gfx_mtl::set_buf(v1u shd_idx, buf& ref, v1u gfx_buf_idx) {
		get_shd(shd_idx)->set_buf(ref, gfx_buf_idx);
	}
	void gfx_mtl::set_txr(v1u shd_idx, txr& ref, v1u txr_idx) {
		get_shd(shd_idx)->set_txr(ref, txr_idx);
	}
	void gfx_mtl::add_shd(shd& ref) {
		m_shds.push_back(ref);
	}
	void gfx_mtl::rmv_shd(v1u idx) {
		m_shds.erase(m_shds.begin() + idx % m_shds.size());
	}
	// --operators
	stm_out& gfx_mtl::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& gfx_mtl::operator>>(stm_in& stm) {
		return stm;
	}
	// --==<core_methods>==--
	v1bit gfx_mtl::remake()
	{
		//
		return NW_TRUE;
	}
	void gfx_mtl::on_draw() {
		for (auto& ishd : m_shds) {
			ishd->on_draw();
		}
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NW_GAPI