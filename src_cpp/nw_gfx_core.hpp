#ifndef NW_GFX_CORE_HPP
#define NW_GFX_CORE_HPP

// --==<core_configuration>==--
// --==</core_configuration>==--

#include "nw_gfx_pch.hpp"

namespace NW
{
	using namespace NW;
	class NW_API gfx_engine;
	class NW_API a_gfx_cmp;

	class NW_API a_gfx_ent;
	class NW_API gfx_ent_vtx;
	class NW_API gfx_ent_idx;

	class NW_API gfx_mtl;

	class NW_API fmbuf;

	class NW_API gfx_buf_vtx;
	class NW_API gfx_buf_idx;
	class NW_API gfx_buf_shd;

	class NW_API a_gfx_shd;
	class NW_API gfx_shd_vtx;
	class NW_API gfx_shd_pxl;
	class NW_API gfx_shd_gmt;

	class NW_API gfx_img;
	class NW_API a_gfx_txr;
	class NW_API gfx_txr_1d;
	class NW_API gfx_txr_2d;
	class NW_API gfx_txr_2d_mulsmp;
	class NW_API gfx_txrfont;
	class NW_API gfx_txr_cube;
	class NW_API gfx_txr_smp;

	class NW_API a_gfx_stt;
	class NW_API gfx_stt_ds;
	class NW_API stt_stenc;
	class NW_API gfx_stt_draw;
	class NW_API stt_cull;
	class NW_API stt_blend;
	class NW_API stt_scis;
	class NW_API stt_viewp;

	class NW_API gfx_cam;
	class NW_API gfx_cam_lad;
}
// --==<configuration>==--
// --==</configuration>==--

#endif	// NW_GFX_CORE_HPP