#ifndef NW_GFX_CMD_H
#define NW_GFX_CMD_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_rsc.h"
#	include "../lib/nw_gfx_lib_info.h"
#	include "../cmp/buf/nw_gfx_buf_vtx.h"
#	include "../cmp/buf/nw_gfx_buf_idx.h"
#	define NW_GFX_CMD_VTX   1 << 1
#	define NW_GFX_CMD_IDX   1 << 2
namespace NW
{
	/// graphics_command struct
	struct NW_API gfx_cmd : public a_mem_cmp
	{
	public:
		using cmd_t = gfx_cmd;
		using cmd_tc = const cmd_t;
		using type_t = v1u;
		using type_tc = const type_t;
#	if (NW_GAPI & NW_GAPI_OGL)
		using prim_t = GLenum;
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
		using prim = D3D11_PRIMITIVE_TOPOLOGY;
#	endif	// GAPI_D3D
		using prim_tc = const prim_t;
	public:
		gfx_cmd(type_tc type, prim_tc primitive) :
			a_mem_cmp(),
			m_type(type),
			m_prim(primitive)
		{
		}
		virtual ~gfx_cmd() = default;
	public:
		type_t m_type;
		prim_t m_prim;
	};
	/// graphics_command_vtx struct
	struct NW_API gfx_cmd_vtx : public gfx_cmd
	{
	public:
		gfx_cmd_vtx(gfx_buf_vtx* vbuf_array, cv1u vbuf_count = 1u, prim_tc primitive = NW_PRIM_TRIANGLES) :
			gfx_cmd(NW_GFX_CMD_VTX, primitive),
			m_vbuf_first(vbuf_array),
			m_vbuf_last(vbuf_array + vbuf_count)
		{
		}
	public:
		gfx_buf_vtx* m_vbuf_first;
		gfx_buf_vtx* m_vbuf_last;
	};
	/// graphics_command_idx struct
	struct NW_API gfx_cmd_idx : public gfx_cmd
	{
	public:
		gfx_cmd_idx(gfx_buf_idx* ibuf, gfx_buf_vtx* vbuf_array, cv1u vbuf_count = 1u, prim_tc primitive = NW_PRIM_TRIANGLES) :
			gfx_cmd(NW_GFX_CMD_IDX, primitive),
			m_ibuf(ibuf),
			m_vbuf_first(vbuf_array),
			m_vbuf_last(vbuf_array + vbuf_count)
		{
		}
	public:
		gfx_buf_idx* m_ibuf;
		gfx_buf_vtx* m_vbuf_first;
		gfx_buf_vtx* m_vbuf_last;
	};
	/// graphics_command_buffer class
	class NW_API gfx_cmd_buf : public a_gfx_rsc
	{
	public:
		using cmd_t = gfx_cmd;
		using cmd_tc = const cmd_t;
		using vcmd_t = gfx_cmd_vtx;
		using vcmd_tc = const vcmd_t;
		using icmd_t = gfx_cmd_idx;
		using icmd_tc = const icmd_t;
		using list_t = t_mem_link<cmd_t>;
		using list_tc = const list_t;
	public:
		gfx_cmd_buf(gfx_engine& graphics);
		~gfx_cmd_buf();
		// --getters
		// --setters
		v1nil add_cmd(vcmd_tc& command);
		v1nil add_cmd(icmd_tc& command);
		v1nil rmv_cmd(cv1u key);
		// --core_methods
		virtual v1nil on_draw() override;
	private:
		list_t* m_list;
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_CMD_H