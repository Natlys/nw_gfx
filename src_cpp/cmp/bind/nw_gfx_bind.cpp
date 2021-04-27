#include "nw_gfx_pch.hpp"
#include "nw_gfx_bind.h"
#if (defined NW_GAPI)
#	include "../../core/nw_gfx_engine.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_bind::gfx_bind() : m_shd(shd_t()), m_bufs(bufs_t()), m_txrs(txrs_t()), m_smps(smps_t()) { }
	gfx_bind::gfx_bind(shd_t& shd) : gfx_bind() { NW_CHECK(remake(shd), "remake error!", return); }
	gfx_bind::gfx_bind(shd_t& shd, bufs_tc& bufs, txrs_tc& txrs, smps_tc& smps) : gfx_bind() { NW_CHECK(remake(shd, bufs, txrs, smps), "remake error!", return); }
	gfx_bind::gfx_bind(shd_t& shd, buf_list_tc& bufs, txr_list_tc& txrs, smp_list_tc& smps) : gfx_bind() { NW_CHECK(remake(shd, bufs, txrs, smps), "remake error!", return); }
	gfx_bind::gfx_bind(bind_tc& copy) : gfx_bind() { operator=(copy); }
	gfx_bind::gfx_bind(bind_t&& copy) : gfx_bind() { operator=(copy); }
	gfx_bind::~gfx_bind() { }
	// --setters
	gfx_bind::bind_t& gfx_bind::set_shd(shd_tc& ref) { m_shd = ref; return *this; }
	// // --buffers
	gfx_bind::bind_t& gfx_bind::set_bufs(bufs_tc& bufs) { m_bufs.clear(); for (auto& ibuf : bufs) { add_buf(ibuf); } return *this; }
	gfx_bind::bind_t& gfx_bind::set_bufs(buf_list_tc& bufs) { m_bufs.clear(); for (auto& ibuf : bufs) { add_buf(ibuf); } return *this; }
	gfx_bind::bind_t& gfx_bind::add_buf(buf_tc& ref) { m_bufs.push_back(ref); return *this; }
	gfx_bind::bind_t& gfx_bind::rmv_buf(size_t key) { NW_CHECK(has_buf(key), "key error!", return *this); m_txrs.erase(m_txrs.begin() + key); return *this; }
	// // --textures
	gfx_bind::bind_t& gfx_bind::set_txrs(txrs_tc& txrs) { m_txrs.clear(); for (auto& itxr : txrs) { add_txr(itxr); } return *this; }
	gfx_bind::bind_t& gfx_bind::set_txrs(txr_list_tc& txrs) { m_txrs.clear(); for (auto& itxr : txrs) { add_txr(itxr); } return *this; }
	gfx_bind::bind_t& gfx_bind::add_txr(txr_tc& ref) { m_txrs.push_back(ref); return *this; }
	gfx_bind::bind_t& gfx_bind::rmv_txr(size_t key) { NW_CHECK(has_txr(key), "key error!", return *this); m_txrs.erase(m_txrs.begin() + key); return *this; }
	// // --samplers
	gfx_bind::bind_t& gfx_bind::set_smps(smps_tc& smps) { m_smps.clear(); for (auto& ismp : smps) { add_smp(ismp); } return *this; }
	gfx_bind::bind_t& gfx_bind::set_smps(smp_list_tc& smps) { m_smps.clear(); for (auto& ismp : smps) { add_smp(ismp); } return *this; }
	gfx_bind::bind_t& gfx_bind::add_smp(smp_tc& ref) { m_smps.push_back(ref); return *this; }
	gfx_bind::bind_t& gfx_bind::rmv_smp(size_t key) { NW_CHECK(has_smp(key), "key error!", return *this); m_smps.erase(m_smps.begin() + key); return *this; }
	// --==<core_methods>==--
	v1bit gfx_bind::remake()
	{
		NW_CHECK(has_shd(), "remake error!", return NW_FALSE);
		//NW_CHECK(has_bufs(), "remake error!", return NW_FALSE);
		//NW_CHECK(has_txrs(), "remake error!", return NW_FALSE);
		//NW_CHECK(has_smps(), "remake error!", return NW_FALSE);

		return NW_TRUE;
	}
	v1nil gfx_bind::on_draw()
	{
		m_shd->on_draw();
		m_shd->on_bind(*this);
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
#	endif	// GAPI_D3D
#endif	// NW_GAPI