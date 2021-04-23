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
	/// graphics_command struct
	struct NW_API gfx_cmd : public a_mem_cmp
	{
	public:
		using cmd_t = gfx_cmd;
		using cmd_tc = const cmd_t;
		using type_t = v1u;
		using type_tc = const type_t;
		using cmp_t = a_gfx_cmp;
		using cmp_tc = const cmp_t;
		using list_t = t_mem_link<cmp_t>;
		using list_tc = const list_t;
#	if (NW_GAPI & NW_GAPI_OGL)
		using prim_t = GLenum;
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
		using prim = D3D11_PRIMITIVE_TOPOLOGY;
#	endif	// GAPI_D3D
		using prim_tc = const prim_t;
	public:
		gfx_cmd(type_tc type, prim_tc primitive);
		template<size_tc count>
		gfx_cmd(type_tc type, prim_tc primitive, t_sarray<cmp_t*, count>& cmps) :
			gfx_cmd(type, primitive) { for (auto& icmp : cmps) { add_cmp(icmp); } }
		gfx_cmd(cmd_tc& copy);
		gfx_cmd(cmd_t&& copy);
		~gfx_cmd();
		// --getters
		inline cv1u get_cmp_count() const {
			v1u count = NW_NULL;
			list_t* temp = m_list;
			while (temp != NW_NULL) { count++; temp = temp->m_link; }
			return count;
		}
		// --setters
		v1nil add_cmp(cmp_t* component);
		v1nil rmv_cmp(cv1u key = NW_NULL);
		// --predicates
		inline v1bit has_cmp(cv1u key = NW_NULL) const { return get_cmp_count() > key; }
		// --operators
		v1nil operator=(cmd_tc& copy);
		v1nil operator=(cmd_t&& copy);
	public:
		type_t m_type;
		prim_t m_prim;
		list_t* m_list;
	};
	/// graphics_command_buffer class
	class NW_API gfx_cmd_buf : public a_gfx_cmp
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
		virtual v1nil on_draw() override;
	private:
		list_t* m_list;
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_CMD_H