#ifndef NC_GFX_CMD_H
#define NC_GFX_CMD_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "std/nc_std_list.hxx"
#	include "../lib/nc_gfx_lib_info.hxx"
#	include "../cmp/buf/nc_gfx_buf_vtx.hxx"
#	include "../cmp/buf/nc_gfx_buf_idx.hxx"
#	define NC_GFX_CMD_VTX   1 << 1
#	define NC_GFX_CMD_IDX   1 << 2
namespace NC
{
	/// graphics_command_type
	class gfx_cmd_t : public mem_user_t
	{
	public:
		using cmd_t = gfx_cmd_t;
		using cmd_tc = const cmd_t;
		using type_t = v1s_t;
		using type_tc = const type_t;
		using nc_cmp_tt = gfx_cmp_t;
		using cmp_tc = const nc_cmp_tt;
		using cmps_t = nc_link1_t<nc_cmp_tt>*;
		using cmps_tc = const cmps_t;
		using cmp_list_t = init_list_t<nc_cmp_tt*>;
		using cmp_list_tc = const cmp_list_t;
#	if (NC_GAPI & NC_GAPI_OGL)
		using prim_t = GLenum;
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
		using prim = D3D11_PRIMITIVE_TOPOLOGY;
#	endif	// GAPI_D3D
		using prim_tc = const prim_t;
	public:
		gfx_cmd_t();
		gfx_cmd_t(type_tc type, prim_tc prim);
		gfx_cmd_t(type_tc type, prim_tc prim, cmps_tc& cmps);
		gfx_cmd_t(type_tc type, prim_tc prim, cmp_list_tc& cmps);
		gfx_cmd_t(cmd_tc& copy);
		gfx_cmd_t(cmd_t&& copy);
		~gfx_cmd_t();
		/* getters */
		inline type_tc get_type() const { return m_type; }
		inline prim_tc get_prim() const { return m_prim; }
		inline cmps_t get_cmps()        { return m_cmps; }
		inline cmps_tc get_cmps() const { return m_cmps; }
		inline size_tc get_cmp_count() const { size_t count(0u); cmps_t link(m_cmps); while (link) { count++; link = link->m_link; } return count; }
		/* setters */
		cmd_t& set_type(type_tc type);
		cmd_t& set_prim(prim_tc prim);
		cmd_t& set_cmps();
		cmd_t& set_cmps(cmps_tc& cmps);
		cmd_t& set_cmps(cmp_list_tc& cmps);
		cmd_t& add_cmp(cmp_tc* cmp);
		cmd_t& rmv_cmp(size_tc key = 0u);
		/* vetters */
		inline v1bit_t has_type() const             { return m_type != NC_NULL; }
		inline v1bit_t has_type(type_tc type) const { return m_type == type; }
		inline v1bit_t has_prim() const             { return m_prim != NC_NULL; }
		inline v1bit_t has_prim(prim_tc prim) const { return m_prim == prim; }
		inline v1bit_t has_cmps() const           { return m_cmps != NC_NULL; }
		inline v1bit_t has_cmp(size_tc key) const { return get_cmp_count() > key; }
		/* operators */
		inline cmd_t& operator=(cmd_tc& copy) { NC_CHECK(remake(copy.get_type(), copy.get_prim(), copy.get_cmps()), "remake error!", return *this); return *this; }
		inline cmd_t& operator=(cmd_t&& copy) { NC_CHECK(remake(copy.get_type(), copy.get_prim(), copy.get_cmps()), "remake error!", return *this); return *this; }
		/* commands */
		v1bit_t remake();
		inline v1bit_t remake(type_tc type, prim_tc prim) { set_type(type).set_prim(prim); return remake(); }
		inline v1bit_t remake(type_tc type, prim_tc prim, cmps_tc& cmps) { set_type(type).set_prim(prim).set_cmps(cmps); return remake(); }
		inline v1bit_t remake(type_tc type, prim_tc prim, cmp_list_tc& cmps) { set_type(type).set_prim(prim).set_cmps(cmps); return remake(); }
		v1nil_t on_draw();
	private:
		type_t m_type;
		prim_t m_prim;
		cmps_t m_cmps;
	};
	/// graphics_command_buffer_type
	class gfx_cmd_buf_t : public mem_owner_t
	{
	public:
		using cmd_t = gfx_cmd_t;
		using cmd_tc = const cmd_t;
		using cbuf_t = gfx_cmd_buf_t;
		using cbuf_tc = const cbuf_t;
		using list_t = nc_link1_t<cmd_t>;
		using list_tc = const list_t;
	public:
		gfx_cmd_buf_t();
		gfx_cmd_buf_t(cbuf_tc& copy);
		gfx_cmd_buf_t(cbuf_t&& copy);
		~gfx_cmd_buf_t();
		/* getters */
		inline v1u_tc get_cmd_count() const {
			v1u_t count = NC_NULL;
			list_t* temp = m_list;
			while (temp != NC_NULL) { count++; temp = m_list->m_link; }
			return count;
		}
		/* setters */
		v1nil_t add_cmd(cmd_tc& command);
		v1nil_t rmv_cmd(v1u_tc key = NC_NULL);
		/* vetters */
		inline v1bit_t has_cmd(v1u_tc key = NC_NULL) const { return get_cmd_count() > key; }
		/* operators */
		v1nil_t operator=(cbuf_tc& copy);
		v1nil_t operator=(cbuf_t&& copy);
		/* commands */
		v1nil_t on_draw();
	private:
		list_t* m_list;
	};
}
#endif	// NC_GAPI
#endif	// NC_GFX_CMD_H