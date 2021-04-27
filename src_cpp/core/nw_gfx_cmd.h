#ifndef NW_GFX_CMD_H
#define NW_GFX_CMD_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "../lib/nw_gfx_lib_info.h"
#	include "../cmp/buf/nw_gfx_buf_vtx.h"
#	include "../cmp/buf/nw_gfx_buf_idx.h"
#	define NW_GFX_CMD_VTX   1 << 1
#	define NW_GFX_CMD_IDX   1 << 2
namespace NW
{
	/// graphics_command class
	class NW_API gfx_cmd : public a_mem_user
	{
	public:
		using cmd_t = gfx_cmd;
		using cmd_tc = const cmd_t;
		using type_t = v1s;
		using type_tc = const type_t;
		using cmp_t = a_gfx_cmp;
		using cmp_tc = const cmp_t;
		using cmps_t = t_mem_link<cmp_t>*;
		using cmps_tc = const cmps_t;
		using cmp_list_t = init_list_t<cmp_t*>;
		using cmp_list_tc = const cmp_list_t;
#	if (NW_GAPI & NW_GAPI_OGL)
		using prim_t = GLenum;
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
		using prim = D3D11_PRIMITIVE_TOPOLOGY;
#	endif	// GAPI_D3D
		using prim_tc = const prim_t;
	public:
		gfx_cmd();
		gfx_cmd(type_tc type, prim_tc prim);
		gfx_cmd(type_tc type, prim_tc prim, cmp_list_tc& cmps);
		gfx_cmd(cmd_tc& copy);
		gfx_cmd(cmd_t&& copy);
		~gfx_cmd();
		// --getters
		inline type_tc get_type() const { return m_type; }
		inline prim_tc get_prim() const { return m_prim; }
		inline cmps_t get_cmps()        { return m_cmps; }
		inline cmps_tc get_cmps() const { return m_cmps; }
		inline size_tc get_cmp_count() const {
			size_t count(0u); cmps_t link(m_cmps);
			while (link) { count++; link = link->m_link; }
			return count;
		}
		// --setters
		cmd_t& set_type(type_tc type);
		cmd_t& set_prim(prim_tc prim);
		cmd_t& set_cmps();
		cmd_t& set_cmps(cmp_list_tc& cmps);
		cmd_t& add_cmp(cmp_tc* cmp);
		cmd_t& rmv_cmp(size_tc key = 0u);
		// --predicates
		inline v1bit has_type() const             { return m_type != NW_NULL; }
		inline v1bit has_type(type_tc type) const { return m_type == type; }
		inline v1bit has_prim() const             { return m_prim != NW_NULL; }
		inline v1bit has_prim(prim_tc prim) const { return m_prim == prim; }
		inline v1bit has_cmps() const           { return m_cmps != NW_NULL; }
		inline v1bit has_cmp(size_tc key) const { return get_cmp_count() > key; }
		// --operators
		cmd_t& operator=(cmd_tc& copy);
		cmd_t& operator=(cmd_t&& copy);
		// --core_methods
		v1bit remake();
		inline v1bit remake(type_tc type, prim_tc prim) { set_type(type).set_prim(prim); return remake(); }
		inline v1bit remake(type_tc type, prim_tc prim, cmp_list_tc& cmps) { set_type(type).set_prim(prim).set_cmps(cmps); return remake(); }
		v1nil on_draw();
	private:
		type_t m_type;
		prim_t m_prim;
		cmps_t m_cmps;
	};
	/// graphics_command_buffer class
	class NW_API gfx_cmd_buf : public a_mem_owner
	{
	public:
		using cmd_t = gfx_cmd;
		using cmd_tc = const cmd_t;
		using cbuf_t = gfx_cmd_buf;
		using cbuf_tc = const cbuf_t;
		using list_t = t_mem_link<cmd_t>;
		using list_tc = const list_t;
	public:
		gfx_cmd_buf();
		gfx_cmd_buf(cbuf_tc& copy);
		gfx_cmd_buf(cbuf_t&& copy);
		~gfx_cmd_buf();
		// --getters
		inline cv1u get_cmd_count() const {
			v1u count = NW_NULL;
			list_t* temp = m_list;
			while (temp != NW_NULL) { count++; temp = m_list->m_link; }
			return count;
		}
		// --setters
		v1nil add_cmd(cmd_tc& command);
		v1nil rmv_cmd(cv1u key = NW_NULL);
		// --predicates
		inline v1bit has_cmd(cv1u key = NW_NULL) const { return get_cmd_count() > key; }
		// --operators
		v1nil operator=(cbuf_tc& copy);
		v1nil operator=(cbuf_t&& copy);
		// --core_methods
		v1nil on_draw();
	private:
		list_t* m_list;
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_CMD_H