#include "nw_gfx_pch.hpp"
#include "nw_gfx_mtl.h"
#if (defined NW_GAPI)
#	include "core/nw_gfx_engine.h"
#	include "lib/nw_gfx_lib_txr.h"
#	include "lib/nw_gfx_lib_mtl.h"
#	include "lib/nw_gfx_lib_shd.h"
#	include "lib/nw_gfx_lib_debug.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_mtl::gfx_mtl() :
		t_cmp(), a_gfx_cmp(), a_iop_cmp(), a_name_owner(),
		m_handle(NW_NULL),
		m_shds(shds_t())
	{
	}
	gfx_mtl::~gfx_mtl() { if (m_handle != NW_NULL) { glDeleteProgram(m_handle); m_handle = NW_NULL; } }
	// --setters
	v1nil gfx_mtl::set_buf(cv1u shd_idx, buf_t& ref, cv1u gfx_buf_idx) {
		get_shd(shd_idx)->set_buf(ref, gfx_buf_idx);
	}
	v1nil gfx_mtl::set_txr(cv1u shd_idx, txr_t& ref, cv1u txr_idx) {
		get_shd(shd_idx)->set_txr(ref, txr_idx);
	}
	v1nil gfx_mtl::add_shd(shd_t& ref) {
		m_shds.push_back(ref);
	}
	v1nil gfx_mtl::rmv_shd(cv1u key) {
		NW_CHECK(has_shd(key), "index error!", return);
		m_shds.erase(m_shds.begin() + key);
	}
	// --operators
	op_stream_t& gfx_mtl::operator<<(op_stream_t& stm) const {
		return stm;
	}
	ip_stream_t& gfx_mtl::operator>>(ip_stream_t& stm) {
		return stm;
	}
	// --==<core_methods>==--
	v1nil gfx_mtl::on_draw()
	{
		glUseProgram(get_handle());
		for (auto& ishd : m_shds) { ishd->on_draw(); }
	}
	v1bit gfx_mtl::remake()
	{
		if (m_handle != NW_NULL) { glDeleteProgram(m_handle); m_handle != NW_NULL; }
		NW_CHECK(has_shd(), "no shaders!", return NW_FALSE);

		m_handle = glCreateProgram();
		
		for (auto& ishd : m_shds) { glAttachShader(get_handle(), ishd->get_handle()); }
		glLinkProgram(get_handle());
		
		if (!gfx_check_shader(get_handle())) { return NW_FALSE; }

		return NW_TRUE;
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	gfx_mtl::gfx_mtl(gfx_engine& graphics) :
		t_cmp(), a_gfx_cmp(graphics), a_iop_cmp()
	{
	}
	gfx_mtl::~gfx_mtl() { }
	// --setters
	v1nil gfx_mtl::set_buf(v1u shd_idx, buf& ref, v1u gfx_buf_idx) {
		get_shd(shd_idx)->set_buf(ref, gfx_buf_idx);
	}
	v1nil gfx_mtl::set_txr(v1u shd_idx, txr& ref, v1u txr_idx) {
		get_shd(shd_idx)->set_txr(ref, txr_idx);
	}
	v1nil gfx_mtl::add_shd(shd& ref) {
		m_shds.push_back(ref);
	}
	v1nil gfx_mtl::rmv_shd(v1u idx) {
		m_shds.erase(m_shds.begin() + idx % m_shds.size());
	}
	// --operators
	op_stream_t& gfx_mtl::operator<<(op_stream_t& stm) const {
		return stm;
	}
	ip_stream_t& gfx_mtl::operator>>(ip_stream_t& stm) {
		return stm;
	}
	// --==<core_methods>==--
	v1bit gfx_mtl::remake()
	{

		return NW_TRUE;
	}
	v1nil gfx_mtl::on_draw() {
		for (auto& ishd : m_shds) {
			ishd->on_draw();
		}
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NW_GAPI