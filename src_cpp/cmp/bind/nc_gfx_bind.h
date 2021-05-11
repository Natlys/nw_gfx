#ifndef NC_GFX_BINDER_H
#define NC_GFX_BINDER_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "../shd/nc_gfx_shd.h"
#	include "../buf/nc_gfx_buf_shd.h"
#	include "../txr/nc_gfx_txr.h"
#	include "../smp/nc_gfx_smp.h"
namespace NC
{
	/// graphics_binder class
	/// description:
	/// --contains all necessary information for connection
	/// between shaders, textures, samplers and 
	class NC_API gfx_bind_t : public nc_cmp_tt<gfx_bind_t>, public gfx_cmp_t
	{
	public:
		// --binds
		using bind_t = gfx_bind_t;
		using bind_tc = const bind_t;
		// --shaders
		using shd_t = mem_ref_t<gfx_shd_t>;
		using shd_tc = const shd_t;
		// --buffers
		using buf_t = mem_ref_t<gfx_buf_shd_t>;
		using buf_tc = const buf_t;
		using bufs_t = array_t<buf_t>;
		using bufs_tc = const bufs_t;
		using buf_list_t = init_list_t<buf_t>;
		using buf_list_tc = const buf_list_t;
		// --textures
		using txr_t = mem_ref_t<gfx_txr_t>;
		using txr_tc = const txr_t;
		using txrs_t = array_t<txr_t>;
		using txrs_tc = const txrs_t;
		using txr_list_t = init_list_t<txr_t>;
		using txr_list_tc = const txr_list_t;
		// --samplers
		using smp_t = mem_ref_t<gfx_smp_t>;
		using smp_tc = const smp_t;
		using smps_t = array_t<smp_t>;
		using smps_tc = const smps_t;
		using smp_list_t = init_list_t<smp_t>;
		using smp_list_tc = const smp_list_t;
	public:
		gfx_bind_t();
		gfx_bind_t(shd_t& shd);
		gfx_bind_t(shd_t& shd, bufs_tc& bufs, txrs_tc& txrs, smps_tc& smps);
		gfx_bind_t(shd_t& shd, buf_list_tc& bufs, txr_list_tc& txrs, smp_list_tc& smps);
		gfx_bind_t(bind_tc& copy);
		gfx_bind_t(bind_t&& copy);
		~gfx_bind_t();
		// getters //
		// // --shader
		inline shd_t& get_shd()        { return m_shd; }
		inline shd_tc& get_shd() const { return m_shd; }
		// // --buffers
		inline bufs_t& get_bufs()        { return m_bufs; }
		inline bufs_tc& get_bufs() const { return m_bufs; }
		inline buf_t& get_buf(size_t key)        { NC_CHECK(has_buf(key), "key error!", return m_bufs[0]); return m_bufs[key]; }
		inline buf_tc& get_buf(size_t key) const { NC_CHECK(has_buf(key), "key error!", return m_bufs[0]); return m_bufs[key]; }
		inline size_tc get_buf_count() const { return m_bufs.size(); }
		// // --textures
		inline txrs_t& get_txrs()        { return m_txrs; }
		inline txrs_tc& get_txrs() const { return m_txrs; }
		inline txr_t& get_txr(size_t key)        { NC_CHECK(has_txr(key), "key error!", return m_txrs[0]); return m_txrs[key]; }
		inline txr_tc& get_txr(size_t key) const { NC_CHECK(has_txr(key), "key error!", return m_txrs[0]); return m_txrs[key]; }
		inline size_tc get_txr_count() const { return m_txrs.size(); }
		// // --samplers
		inline smps_t& get_smps()        { return m_smps; }
		inline smps_tc& get_smps() const { return m_smps; }
		inline smp_t& get_smp(size_t key)        { NC_CHECK(has_smp(key), "key error!", return m_smps[0]); return m_smps[key]; }
		inline smp_tc& get_smp(size_t key) const { NC_CHECK(has_smp(key), "key error!", return m_smps[0]); return m_smps[key]; }
		inline size_tc get_smp_count() const { return m_smps.size(); }
		// setters //
		bind_t& set_shd(shd_tc& ref);
		// // --buffers
		bind_t& set_bufs(bufs_tc& bufs);
		bind_t& set_bufs(buf_list_tc& bufs);
		bind_t& add_buf(buf_tc& ref);
		bind_t& rmv_buf(size_t key);
		// // --textures
		bind_t& set_txrs(txrs_tc& txrs);
		bind_t& set_txrs(txr_list_tc& txrs);
		bind_t& add_txr(txr_tc& ref);
		bind_t& rmv_txr(size_t key);
		// // --samplers
		bind_t& set_smps(smps_tc& smps);
		bind_t& set_smps(smp_list_tc& smps);
		bind_t& add_smp(smp_tc& ref);
		bind_t& rmv_smp(size_t key);
		// predicates //
		inline v1bit_t has_shd() const { return m_shd.is_valid(); }
		// // --buffers
		inline v1bit_t has_bufs() const { return !m_bufs.empty(); }
		inline v1bit_t has_buf(size_t key) const { return get_buf_count() > key; }
		// // --textures
		inline v1bit_t has_txrs() const { return !m_txrs.empty(); }
		inline v1bit_t has_txr(size_t key) const { return get_txr_count() > key; }
		// // --samplers
		inline v1bit_t has_smps() const { return !m_smps.empty(); }
		inline v1bit_t has_smp(size_t key) const { return get_smp_count() > key; }
		// operators //
		inline bind_t& operator=(bind_tc& copy) {
			NC_CHECK(remake(copy.get_shd(), copy.get_bufs(), copy.get_txrs(), copy.get_smps()), "remake error!", return *this);
			return *this;
		}
		inline bind_t& operator=(bind_t&& copy) {
			NC_CHECK(remake(copy.get_shd(), copy.get_bufs(), copy.get_txrs(), copy.get_smps()), "remake error!", return *this);
			return *this;
		}
		// commands //
		v1bit_t remake();
		inline v1bit_t remake(shd_tc& shd) { set_shd(shd); return remake(); }
		inline v1bit_t remake(shd_tc& shd, buf_list_tc& bufs, txr_list_tc& txrs, smp_list_tc& smps) {
			set_bufs(bufs).set_txrs(txrs).set_smps(smps);
			return remake(shd);
		}
		inline v1bit_t remake(shd_tc& shd, bufs_tc& bufs, txrs_tc& txrs, smps_tc& smps) {
			set_bufs(bufs).set_txrs(txrs).set_smps(smps);
			return remake(shd);
		}
		virtual v1nil_t on_draw() override;
	public:
		shd_t m_shd;
		bufs_t m_bufs;
		txrs_t m_txrs;
		smps_t m_smps;
	};
}
#endif
#endif	// NC_GFX_MATERIAL_BINDER_H