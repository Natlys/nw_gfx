#include "nw_gfx_pch.hpp"
#include "nw_gfx_shd.h"
#if (defined NW_GAPI)
#	include "core/nw_gfx_engine.h"
#	include "lib/nw_gfx_lib_buf.h"
#	include "lib/nw_gfx_lib_txr.h"
#	include "lib/nw_gfx_lib_shd.h"
#	include "lib/nw_gfx_lib_mtl.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	a_gfx_shd::a_gfx_shd() :
		t_cmp(), a_gfx_cmp(), a_iop_cmp(),
		m_handle(NW_DEFAULT_VAL),
		m_source(NW_DEFAULT_STR)
	{
	}
	a_gfx_shd::a_gfx_shd(source_tc& source_code) :
		a_gfx_shd()
	{
		NW_CHECK(remake(source_code), "failed remake!", return);
	}
	a_gfx_shd::~a_gfx_shd() { if (m_handle != NW_NULL) { glDeleteShader(m_handle); m_handle = NW_NULL; } }
	// --setters
	v1nil a_gfx_shd::set_source(source_tc& source_code) {
		m_source = source_code;
	}
	v1nil a_gfx_shd::set_buf(buf_t& ref, cv1u key) {
		if (key >= 10) { throw run_error(__FILE__, __LINE__); }
		if (m_bufs.size() <= key + 1) { m_bufs.resize(key + 1); }
		m_bufs[key] = ref;
	}
	v1nil a_gfx_shd::set_txr(txr_t& ref, cv1u key) {
		if (key >= 10) { throw run_error(__FILE__, __LINE__); }
		if (m_txrs.size() <= key + 1) { m_txrs.resize(key + 1); }
		m_txrs[key] = ref;
	}
	// --operators
	op_stream_t& a_gfx_shd::operator<<(op_stream_t& stm) const {
		return stm;
	}
	ip_stream_t& a_gfx_shd::operator>>(ip_stream_t& stm) {
		return stm;
	}
	// --==<core_methods>==--
	v1bit a_gfx_shd::remake()
	{
		if (m_handle != NW_NULL) { glDeleteShader(m_handle); m_handle = NW_NULL; }

		if (iop_sys::get().is_file(&get_source()[0])) {
			NW_CHECK(iop_sys::get().load_file(&get_source()[0], m_source), "load error!", return NW_FALSE);
		}

		return NW_TRUE;
	}
	v1nil a_gfx_shd::on_draw()
	{
		for (v1s itr = 0; itr < m_bufs.size(); itr++) {
			auto& ibuf = m_bufs[itr];
			if (ibuf.is_valid()) {
				ibuf->on_draw();
				glUniformBlockBinding(m_handle, ibuf->get_handle(), ibuf->get_slot());
			}
		}
		for (v1s itr = 0; itr < m_txrs.size(); itr++) {
			auto& itxr = m_txrs[itr];
			if (itxr.is_valid()) {
				itxr->on_draw();
				glUniform1i(itr, itxr->get_slot());
			}
		}
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	a_gfx_shd::a_gfx_shd(gfx_engine& graphics) :
		t_cmp(), a_gfx_cmp(graphics), a_iop_cmp(),
		m_handle(NW_NULL), m_src_code("default")
	{
	}
	a_gfx_shd::~a_gfx_shd() { if (m_handle != NW_NULL) { m_handle->Release(); m_handle = NW_NULL; } }
	// --setters
	v1nil a_gfx_shd::set_buf(buf& ref, v1u idx) {
		if (idx >= NW_MAX_SLOTS_BUF) { throw run_error(__FILE__, __LINE__); }
		if (m_bufs.size() <= idx + 1) { m_bufs.resize(idx + 1); }
		m_bufs[idx] = ref;
	}
	v1nil a_gfx_shd::set_txr(txr& ref, v1u idx) {
		if (idx >= NW_MAX_SLOTS_TXR) { throw run_error(__FILE__, __LINE__); }
		if (m_txrs.size() <= idx + 1) { m_txrs.resize(idx + 1); }
		m_txrs[idx] = ref;
	}
	// --==<core_methods>==--
	v1bit a_gfx_shd::remake(cstr source_code)
	{
		if (m_handle != NW_NULL) { m_handle->Release(); m_handle = NW_NULL; }
		if (strlen(source_code) <= NW_MAX_PATH) {
			if (iop_sys::get().is_file_path(source_code)) {
				if (!iop_sys::get().load_file(source_code, m_src_code)) { return NW_FALSE; }
			}
			else { m_src_code = source_code; }
		}
		else { m_src_code = source_code; }

		return NW_TRUE;
	}
	v1nil a_gfx_shd::on_draw()
	{
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NW_GAPI