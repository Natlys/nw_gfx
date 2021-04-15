#ifndef NW_GFX_MATERIAL_H
#define NW_GFX_MATERIAL_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#include "cmp/nw_gfx_cmp.h"
#include "../shd/nw_gfx_shd.h"
#include "../txr/nw_gfx_txr.h"
#include "../buf/nw_gfx_buf_shd.h"
namespace NW
{
	/// material class
	class NW_API gfx_mtl : public t_cmp<gfx_mtl>, public a_gfx_cmp, public a_io_cmp
	{
	public:
		using shd = mem_ref<a_gfx_shd>;
		using shds = darray<shd>;
		using buf = a_gfx_shd::buf;
		using bufs = a_gfx_shd::bufs;
		using txr = a_gfx_shd::txr;
		using txrs = a_gfx_shd::txrs;
#if (NW_GAPI & NW_GAPI_OGL)
		using handle = GLuint;
#endif
#if (NW_GAPI & NW_GAPI_D3D)
		using handle = ptr;
#endif
	public:
		gfx_mtl(gfx_engine& graphics);
		virtual ~gfx_mtl();
		// --getters
		inline shd& get_shd(v1u idx) { return m_shds[idx % m_shds.size()]; }
		inline handle get_handle()    { return m_handle; }
		// --setters
		void set_buf(v1u shd_idx, buf& ref, v1u gfx_buf_idx);
		void set_txr(v1u shd_idx, txr& ref, v1u gfx_txridx);
		void add_shd(shd& ref);
		void rmv_shd(v1u idx);
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const override;
		virtual stm_in& operator>>(stm_in& stm) override;
		// --core_methods
		v1b remake();
		virtual v1nil on_draw() override;
	private:
		shds m_shds;
		handle m_handle;
	};
}

#endif	// NW_GAPI
#endif	// NW_GFX_MATERIAL_H
