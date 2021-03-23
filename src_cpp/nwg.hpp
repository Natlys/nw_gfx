#ifndef NWG_HPP
#define NWG_HPP

#include "nwg_core.hpp"

#include "core/nwg_engine.h"
#include "core/nwg_cmp.h"
#include "core/nwg_ent.h"

#include "ent/nwg_ent_idx.h"
#include "ent/nwg_ent_vtx.h"
#include "ent/nwg_ent_mesh.h"

#include "cmp/mtl/nwg_mtl.h"

#include "cmp/fmbuf/nwg_fmbuf.h"

#include "cmp/stt/nwg_stt.h"
#include "cmp/stt/nwg_stt_scis.h"
#include "cmp/stt/nwg_stt_viewp.h"
#include "cmp/stt/nwg_stt_draw.h"
#include "cmp/stt/nwg_stt_blend.h"
#include "cmp/stt/nwg_stt_stenc.h"
#include "cmp/stt/nwg_stt_depth.h"

#include "cmp/buf/nwg_buf.h"
#include "cmp/buf/nwg_buf_vtx.h"
#include "cmp/buf/nwg_buf_idx.h"
#include "cmp/buf/nwg_buf_shd.h"

#include "cmp/shd/nwg_shd.h"
#include "cmp/shd/nwg_shd_vtx.h"
#include "cmp/shd/nwg_shd_pxl.h"
#include "cmp/shd/nwg_shd_gmt.h"
#include "cmp/shd/nwg_shd_layt.h"
#include "cmp/shd/nwg_shd_rsc.h"

#include "cmp/txr/nwg_txr.h"
#include "cmp/txr/nwg_txr_2d.h"
#include "cmp/txr/nwg_txr_3d.h"
#include "cmp/txr/nwg_txr_smp.h"

#include "lib/nwg_img.h"
#include "lib/nwg_cam_lad.h"
#include "lib/nwg_cam.h"
#include "lib/nwg_switch.h"

#ifdef NW_BUILD_DLL
#	undef NW_BUILD_DLL
#endif

#endif	// NWG_HPP