#ifndef NW_GFX_MATERIAL_H
#define NW_GFX_MATERIAL_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "cmp/nw_gfx_cmp.h"
#	include "../shd/nw_gfx_shd.h"
#	include "../txr/nw_gfx_txr.h"
#	include "../buf/nw_gfx_buf_shd.h"
namespace NW
{
	/// material class
	class NW_API gfx_mtl : public t_cmp<gfx_mtl>, public a_gfx_cmp, public a_iop_cmp, public a_name_owner
	{
	public:
		using shd_t = mem_ref<a_gfx_shd>;
		using shd_tc = const shd_t;
		using shds_t = t_darray<shd_t>;
		using shds_tc = const shds_t;
		using buf_t = a_gfx_shd::buf_t;
		using buf_tc = a_gfx_shd::buf_tc;
		using bufs_t = a_gfx_shd::bufs_t;
		using bufs_tc = a_gfx_shd::bufs_tc;
		using txr_t = a_gfx_shd::txr_t;
		using txr_tc = a_gfx_shd::txr_tc;
		using txrs_t = a_gfx_shd::txrs_t;
		using txrs_tc = a_gfx_shd::txrs_tc;
#	if (NW_GAPI & NW_GAPI_OGL)
		using handle_t = GLuint;
#	endif
#	if (NW_GAPI & NW_GAPI_D3D)
		using handle_t = ptr_t;
#	endif
		using handle_tc = const handle_t;
	public:
		gfx_mtl();
		virtual ~gfx_mtl();
		// --getters
		inline handle_t get_handle()    { return m_handle; }
		inline shd_t& get_shd(cv1u key) { NW_CHECK(has_shd(key), "index error!", return shd_t()); return m_shds[key]; }
		// --setters
		v1nil set_buf(cv1u shd_idx, buf_t& ref, cv1u buf_idx);
		v1nil set_txr(cv1u shd_idx, txr_t& ref, cv1u txr_idx);
		v1nil add_shd(shd_t& ref);
		v1nil rmv_shd(cv1u key);
		// --predicates
		inline v1bit has_shd(cv1u key = NW_NULL) const { return m_shds.size() > key; }
		// --operators
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// --core_methods
		v1bit remake();
		virtual v1nil on_draw() override;
	private:
		handle_t m_handle;
		shds_t m_shds;
	};
}

#endif	// NW_GAPI
#endif	// NW_GFX_MATERIAL_H
