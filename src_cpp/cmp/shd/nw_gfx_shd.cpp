#include "nw_gfx_pch.hpp"
#include "nw_gfx_shd.h"
#if (defined NW_GAPI)
#	include "../../core/nw_gfx_engine.h"
#	include "../../lib/nw_gfx_lib_buf.h"
#	include "../../lib/nw_gfx_lib_txr.h"
#	include "../../lib/nw_gfx_lib_shd.h"
#	include "../../lib/nw_gfx_lib_mtl.h"
#	include "../bind/nw_gfx_bind.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_shd::gfx_shd() : t_cmp(), a_gfx_cmp(), a_iop_cmp(), m_handle(NW_NULL), m_source(NW_DEFAULT_STR) { }
	gfx_shd::gfx_shd(shd_tc& copy) : gfx_shd() { operator=(copy); }
	gfx_shd::gfx_shd(shd_t&& copy) : gfx_shd() { operator=(copy); }
	gfx_shd::gfx_shd(source_tc& source) : gfx_shd() { NW_CHECK(remake(source), "remake error!", return); }
	gfx_shd::~gfx_shd() { if (m_handle != NW_NULL) { glDeleteShader(m_handle); m_handle = NW_NULL; } }
	// --setters
	gfx_shd::shd_t& gfx_shd::set_source(source_tc& source) { m_source = source; return *this; }
	// --operators
	op_stream_t& gfx_shd::operator<<(op_stream_t& stm) const {
		return stm;
	}
	ip_stream_t& gfx_shd::operator>>(ip_stream_t& stm) {
		return stm;
	}
	// --==<core_methods>==--
	v1bit gfx_shd::remake()
	{
		if (m_handle != NW_NULL) { glDeleteShader(m_handle); m_handle = NW_NULL; }
		
		if (iop_sys::get().is_file(&get_source()[0])) {
			if (!iop_sys::get().load_file(&get_source()[0], m_source)) { return NW_FALSE; }
		}

		return NW_TRUE;
	}
	v1nil gfx_shd::on_bind(binder_t& ref)
	{
		for (v1u itr(0u); itr < ref.get_buf_count(); itr++) {
			auto& ibuf = ref.get_buf(itr);
			glUniformBlockBinding(m_handle, ibuf->get_handle(), ibuf->get_slot());
			ibuf->on_draw();
		}
		for (v1u itr(0u); itr < ref.get_txr_count(); itr++) {
			auto& itxr = ref.get_txr(itr);
			glUniform1i(itr, itxr->get_slot());
			itxr->on_draw();
		}
		for (v1u itr(0u); itr < ref.get_smp_count(); itr++) {
			auto& ismp = ref.get_smp(itr);
			ismp->on_draw();
		}
	}
	v1nil gfx_shd::on_draw()
	{
	}
	// --==</core_methods>==--
}
#	endif	// NW_GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	gfx_shd::gfx_shd(gfx_engine& graphics) :
		t_cmp(), a_gfx_cmp(graphics), a_io_cmp(),
		m_handle(NW_NULL), m_src_code("default")
	{
	}
	gfx_shd::~gfx_shd() { if (m_handle != NW_NULL) { m_handle->Release(); m_handle = NW_NULL; } }
	// --setters
	v1nil gfx_shd::set_buf(buf& ref, v1u idx) {
		if (idx >= NW_MAX_SLOTS_BUF) { throw run_error(__FILE__, __LINE__); }
		if (m_bufs.size() <= idx + 1) { m_bufs.resize(idx + 1); }
		m_bufs[idx] = ref;
	}
	v1nil gfx_shd::set_txr(txr& ref, v1u idx) {
		if (idx >= NW_MAX_SLOTS_TXR) { throw run_error(__FILE__, __LINE__); }
		if (m_txrs.size() <= idx + 1) { m_txrs.resize(idx + 1); }
		m_txrs[idx] = ref;
	}
	// --==<core_methods>==--
	v1bit gfx_shd::remake(cstr source_code)
	{
		if (m_handle != NW_NULL) { m_handle->Release(); m_handle = NW_NULL; }
		if (strlen(source_code) <= NW_MAX_PATH) {
			if (io_sys::get().is_file_path(source_code)) {
				if (!io_sys::get().load_file(source_code, m_src_code)) { return NW_FALSE; }
			}
			else { m_src_code = source_code; }
		}
		else { m_src_code = source_code; }

		return NW_TRUE;
	}
	v1nil gfx_shd::on_draw()
	{
	}
	// --==</core_methods>==--
}
#	endif	// NW_GAPI_D3D
#endif	// NW_GAPI