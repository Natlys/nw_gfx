#include "nc_gfx_pch.hpp"
#include "nc_gfx_shd.hxx"
#if (defined NC_GAPI)
#	include "../../core/nc_nc_gfx_eng.hxx"
#	include "../bind/nc_gfx_bind.hxx"
#	if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	gfx_shd_t::gfx_shd_t() : nc_cmp_tt(), gfx_cmp_t(), nc_iop_cmp_t(), m_handle(NC_NULL), m_source(NC_VOID_STR) { }
	gfx_shd_t::gfx_shd_t(shd_tc& copy) : gfx_shd_t() { operator=(copy); }
	gfx_shd_t::gfx_shd_t(shd_t&& copy) : gfx_shd_t() { operator=(copy); }
	gfx_shd_t::gfx_shd_t(source_tc& source) : gfx_shd_t() { NC_CHECK(remake(source), "remake error!", return); }
	gfx_shd_t::~gfx_shd_t() { if (m_handle != NC_NULL) { get_context()->shd_del(m_handle); m_handle = NC_NULL; } }
	/* setters */
	gfx_shd_t::shd_t& gfx_shd_t::set_source(source_tc& source) { m_source = source; return *this; }
	/* operators */
	nc_ostream_t& gfx_shd_t::operator<<(nc_ostream_t& stm) const {
		return stm;
	}
	nc_istream_t& gfx_shd_t::operator>>(nc_istream_t& stm) {
		return stm;
	}
	/* command */
	v1bit_t gfx_shd_t::remake()
	{
		if (m_handle != NC_NULL) { get_context()->shd_del(m_handle); m_handle = NC_NULL; }
		
		if (iop_sys::get().is_file(&get_source()[0])) {
			if (!iop_sys::get().load_file(&get_source()[0], m_source)) { return NC_FALSE; }
		}

		return NC_TRUTH;
	}
	v1nil_t gfx_shd_t::on_bind(binder_t& ref)
	{
		for (v1u_t itr(0u); itr < ref.get_buf_count(); itr++) {
			auto& ibuf = ref.get_buf(itr);
			get_context()->mtl_set_bind(m_handle, ibuf->get_handle(), ibuf->get_slot());
			ibuf->set_slot(itr);
			ibuf->on_draw();
		}
		for (v1u_t itr(0u); itr < ref.get_txr_count(); itr++) {
			auto& itxr = ref.get_txr(itr);
			get_context()->mtl_set_n1s(itr, itxr->get_slot());
			itxr->set_slot(itr);
			itxr->on_draw();
		}
		for (v1u_t itr(0u); itr < ref.get_smp_count(); itr++) {
			auto& ismp = ref.get_smp(itr);
			ismp->set_slot(itr);
			ismp->on_draw();
		}
	}
	v1nil_t gfx_shd_t::on_draw()
	{
	}
	// --==</core_methods>==--
}
#	endif	// NC_GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
namespace NC
{
	gfx_shd_t::gfx_shd_t(nc_gfx_eng& graphics) :
		nc_cmp_tt(), gfx_cmp_t(graphics), a_io_cmp(),
		m_handle(NC_NULL), m_src_code("default")
	{
	}
	gfx_shd_t::~gfx_shd_t() { if (m_handle != NC_NULL) { m_handle->Release(); m_handle = NC_NULL; } }
	/* setters */
	v1nil_t gfx_shd_t::set_buf(buf& ref, v1u_t idx) {
		if (idx >= NC_MAX_SLOTS_BUF) { throw run_error(__FILE__, __LINE__); }
		if (m_bufs.size() <= idx + 1) { m_bufs.resize(idx + 1); }
		m_bufs[idx] = ref;
	}
	v1nil_t gfx_shd_t::set_txr(txr& ref, v1u_t idx) {
		if (idx >= NC_MAX_SLOTS_TXR) { throw run_error(__FILE__, __LINE__); }
		if (m_txrs.size() <= idx + 1) { m_txrs.resize(idx + 1); }
		m_txrs[idx] = ref;
	}
	/* command */
	v1bit_t gfx_shd_t::remake(cstr source_code)
	{
		if (m_handle != NC_NULL) { m_handle->Release(); m_handle = NC_NULL; }
		if (strlen(source_code) <= NC_MAX_PATH) {
			if (io_sys::get().is_file_path(source_code)) {
				if (!io_sys::get().load_file(source_code, m_src_code)) { return NC_FALSE; }
			}
			else { m_src_code = source_code; }
		}
		else { m_src_code = source_code; }

		return NC_TRUTH;
	}
	v1nil_t gfx_shd_t::on_draw()
	{
	}
	// --==</core_methods>==--
}
#	endif	// NC_GAPI_D3D
#endif	// NC_GAPI