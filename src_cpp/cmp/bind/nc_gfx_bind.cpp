#include "nc_gfx_pch.hpp"
#include "nc_gfx_bind.hxx"
#if (defined NC_GAPI)
#	include "../../core/nc_nc_gfx_eng.hxx"
#	if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	gfx_bind_t::gfx_bind_t() : m_shd(shd_t()), m_bufs(bufs_t()), m_txrs(txrs_t()), m_smps(smps_t()) { }
	gfx_bind_t::gfx_bind_t(shd_t& shd) : gfx_bind_t() { NC_CHECK(remake(shd), "remake error!", return); }
	gfx_bind_t::gfx_bind_t(shd_t& shd, bufs_tc& bufs, txrs_tc& txrs, smps_tc& smps) : gfx_bind_t() { NC_CHECK(remake(shd, bufs, txrs, smps), "remake error!", return); }
	gfx_bind_t::gfx_bind_t(shd_t& shd, buf_list_tc& bufs, txr_list_tc& txrs, smp_list_tc& smps) : gfx_bind_t() { NC_CHECK(remake(shd, bufs, txrs, smps), "remake error!", return); }
	gfx_bind_t::gfx_bind_t(bind_tc& copy) : gfx_bind_t() { operator=(copy); }
	gfx_bind_t::gfx_bind_t(bind_t&& copy) : gfx_bind_t() { operator=(copy); }
	gfx_bind_t::~gfx_bind_t() { }
	/* setters */
	gfx_bind_t::bind_t& gfx_bind_t::set_shd(shd_tc& ref) { m_shd = ref; return *this; }
	// // --buffers
	gfx_bind_t::bind_t& gfx_bind_t::set_bufs(bufs_tc& bufs) { m_bufs.clear(); for (auto& ibuf : bufs) { add_buf(ibuf); } return *this; }
	gfx_bind_t::bind_t& gfx_bind_t::set_bufs(buf_list_tc& bufs) { m_bufs.clear(); for (auto& ibuf : bufs) { add_buf(ibuf); } return *this; }
	gfx_bind_t::bind_t& gfx_bind_t::add_buf(buf_tc& ref) { m_bufs.push_back(ref); return *this; }
	gfx_bind_t::bind_t& gfx_bind_t::rmv_buf(size_t key) { NC_CHECK(has_buf(key), "key error!", return *this); m_txrs.erase(m_txrs.begin() + key); return *this; }
	// // --textures
	gfx_bind_t::bind_t& gfx_bind_t::set_txrs(txrs_tc& txrs) { m_txrs.clear(); for (auto& itxr : txrs) { add_txr(itxr); } return *this; }
	gfx_bind_t::bind_t& gfx_bind_t::set_txrs(txr_list_tc& txrs) { m_txrs.clear(); for (auto& itxr : txrs) { add_txr(itxr); } return *this; }
	gfx_bind_t::bind_t& gfx_bind_t::add_txr(txr_tc& ref) { m_txrs.push_back(ref); return *this; }
	gfx_bind_t::bind_t& gfx_bind_t::rmv_txr(size_t key) { NC_CHECK(has_txr(key), "key error!", return *this); m_txrs.erase(m_txrs.begin() + key); return *this; }
	// // --samplers
	gfx_bind_t::bind_t& gfx_bind_t::set_smps(smps_tc& smps) { m_smps.clear(); for (auto& ismp : smps) { add_smp(ismp); } return *this; }
	gfx_bind_t::bind_t& gfx_bind_t::set_smps(smp_list_tc& smps) { m_smps.clear(); for (auto& ismp : smps) { add_smp(ismp); } return *this; }
	gfx_bind_t::bind_t& gfx_bind_t::add_smp(smp_tc& ref) { m_smps.push_back(ref); return *this; }
	gfx_bind_t::bind_t& gfx_bind_t::rmv_smp(size_t key) { NC_CHECK(has_smp(key), "key error!", return *this); m_smps.erase(m_smps.begin() + key); return *this; }
	/* commands */
	v1bit_t gfx_bind_t::remake()
	{
		NC_CHECK(has_shd(), "remake error!", return NC_FALSE);
		//NC_CHECK(has_bufs(), "remake error!", return NC_FALSE);
		//NC_CHECK(has_txrs(), "remake error!", return NC_FALSE);
		//NC_CHECK(has_smps(), "remake error!", return NC_FALSE);

		return NC_TRUTH;
	}
	v1nil_t gfx_bind_t::on_draw()
	{
		m_shd->on_draw();
		m_shd->on_bind(*this);
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
#	endif	// GAPI_D3D
#endif	// NC_GAPI