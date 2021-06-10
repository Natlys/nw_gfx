#include "nc_gfx_pch.hpp"
#include "nc_gfx_cmd.hxx"
#if (defined NC_GAPI)
#	include "../cmp/buf/nc_gfx_buf_vtx.hxx"
#	include "../cmp/buf/nc_gfx_buf_idx.hxx"
#	include "../lib/nc_gfx_lib_info.hxx"
#	include "nc_nc_gfx_eng.hxx"
#	if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	gfx_cmd_t::gfx_cmd_t() : mem_user_t(), m_type(NC_NULL), m_prim(NC_NULL), m_cmps(NC_NULL) { }
	gfx_cmd_t::gfx_cmd_t(type_tc type, prim_tc prim) : gfx_cmd_t() { NC_CHECK(remake(type, prim), "remake error!", return); }
	gfx_cmd_t::gfx_cmd_t(type_tc type, prim_tc prim, cmps_tc& cmps) : gfx_cmd_t() { NC_CHECK(remake(type, prim, cmps), "remake error!", return); }
	gfx_cmd_t::gfx_cmd_t(type_tc type, prim_tc prim, cmp_list_tc& cmps) : gfx_cmd_t() { NC_CHECK(remake(type, prim, cmps), "remake error!", return); }
	gfx_cmd_t::gfx_cmd_t(cmd_tc& copy) : gfx_cmd_t() { operator=(copy); }
	gfx_cmd_t::gfx_cmd_t(cmd_t&& copy) : gfx_cmd_t() { operator=(copy); }
	gfx_cmd_t::~gfx_cmd_t() { set_cmps(); }
	/* setters */
	gfx_cmd_t::cmd_t& gfx_cmd_t::set_type(type_tc type) { m_type = type; return *this; }
	gfx_cmd_t::cmd_t& gfx_cmd_t::set_prim(prim_tc prim) { m_prim = prim; return *this; }
	gfx_cmd_t::cmd_t& gfx_cmd_t::set_cmps() { while (m_cmps != NC_NULL) { rmv_cmp(NC_NULL); } return *this; }
	gfx_cmd_t::cmd_t& gfx_cmd_t::set_cmps(cmps_tc& cmps) { set_cmps(); cmps_t temp = cmps; while (temp) { add_cmp(temp->m_data); temp = temp->m_link; } return *this; }
	gfx_cmd_t::cmd_t& gfx_cmd_t::set_cmps(cmp_list_tc& cmps) { set_cmps(); for (auto& icmp : cmps) { add_cmp(icmp); } return *this; }
	gfx_cmd_t::cmd_t& gfx_cmd_t::add_cmp(cmp_tc* cmp) {
		cmps_t next = new nc_link1_t<nc_cmp_tt>();
		next->m_link = m_cmps;
		next->m_data = const_cast<nc_cmp_tt*>(cmp);
		m_cmps = next;
		return *this;
	}
	gfx_cmd_t::cmd_t& gfx_cmd_t::rmv_cmp(size_tc key) {
		NC_CHECK(has_cmp(key), "index error!", return *this);
		cmps_t next_head = m_cmps->m_link;
		delete m_cmps;
		m_cmps = next_head;
		return *this;
	}
	/* operators */
	/* command */
	v1bit_t gfx_cmd_t::remake()
	{
		NC_CHECK(has_type(), "no type!", return NC_FALSE);
		//NC_CHECK(has_prim(), "no prim!", return NC_FALSE);
		NC_CHECK(has_cmps(), "no cmps!", return NC_FALSE);
		return NC_TRUTH;
	}
	v1nil_t gfx_cmd_t::on_draw()
	{
		GLsizei vcount = NC_NULL;
		GLsizei icount = NC_NULL;
		GLenum itype = NC_NULL;
		auto link = get_cmps();
		while (link != NC_NULL) {
			auto icmp = static_cast<gfx_buf_t*>(link->m_data);
			icmp->on_draw();
			if (gfx_buf_idx_t* ibuf = icmp->check_cast<gfx_buf_idx_t>()) {
				icount += ibuf->get_count();
				itype = gfx_info_t::get_type(ibuf->get_layt().get_type());
			}
			if (gfx_buf_vtx_t* vbuf = icmp->check_cast<gfx_buf_vtx_t>()) {
				vcount += vbuf->get_count();
			}
			link = link->m_link;
		}
		if (has_type(NC_GFX_CMD_VTX)) { nc_gfx_eng::get().get_context().draw_vtx(get_prim(), NC_NULL, vcount); }
		if (has_type(NC_GFX_CMD_IDX)) { nc_gfx_eng::get().get_context().draw_idx(get_prim(), icount, itype, NC_NULL); }
	}
	// --==</core_methods>==--
}
namespace NC
{
	gfx_cmd_buf_t::gfx_cmd_buf_t() :
		m_list(NC_NULL)
	{
	}
	gfx_cmd_buf_t::gfx_cmd_buf_t(cbuf_tc& copy) :
		gfx_cmd_buf_t()
	{
		operator=(copy);
	}
	gfx_cmd_buf_t::gfx_cmd_buf_t(cbuf_t&& copy) :
		gfx_cmd_buf_t()
	{
		operator=(copy);
	}
	gfx_cmd_buf_t::~gfx_cmd_buf_t()
	{
		while (m_list != NC_NULL) { rmv_cmd(NC_NULL); }
	}
	/* setters */
	v1nil_t gfx_cmd_buf_t::add_cmd(cmd_tc& command) {
		list_t* next_head = new list_t();
		next_head->m_link = m_list;
		next_head->m_data = new cmd_t(command);
		m_list = next_head;
	}
	v1nil_t gfx_cmd_buf_t::rmv_cmd(v1u_tc key) {
		NC_CHECK(has_cmd(key), "index error!", return);
		list_t* next_head = m_list->m_link;
		delete m_list->m_data;
		delete m_list;
		m_list = next_head;
	}
	/* operators */
	v1nil_t gfx_cmd_buf_t::operator=(cbuf_tc& copy) {
		NC_ERROR("does not work for now", return);
	}
	v1nil_t gfx_cmd_buf_t::operator=(cbuf_t&& copy) {
		NC_ERROR("does not work for now", return);
	}
	/* command */
	v1nil_t gfx_cmd_buf_t::on_draw()
	{
		while (m_list != NC_NULL) {
			auto& icmd = *m_list->m_data;
			m_list->m_data->on_draw();
			rmv_cmd(NC_NULL);
		}
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
namespace NC
{
	//
}
#	endif	// GAPI_OGL
#endif	// NC_GAPI