#include "nw_gfx_pch.hpp"
#include "nw_gfx_cmd.h"
#if (defined NW_GAPI)
#	include "../cmp/buf/nw_gfx_buf_vtx.h"
#	include "../cmp/buf/nw_gfx_buf_idx.h"
#	include "../lib/nw_gfx_lib_info.h"
#	include "nw_gfx_engine.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_cmd::gfx_cmd() : a_mem_user(), m_type(NW_NULL), m_prim(NW_NULL), m_cmps(NW_NULL) { }
	gfx_cmd::gfx_cmd(type_tc type, prim_tc prim) : gfx_cmd() { NW_CHECK(remake(type, prim), "remake error!", return); }
	gfx_cmd::gfx_cmd(type_tc type, prim_tc prim, cmp_list_tc& cmps) : gfx_cmd() { NW_CHECK(remake(type, prim, cmps), "remake error!", return); }
	gfx_cmd::gfx_cmd(cmd_tc& copy) : gfx_cmd() { operator=(copy); }
	gfx_cmd::gfx_cmd(cmd_t&& copy) : gfx_cmd() { operator=(copy); }
	gfx_cmd::~gfx_cmd() { set_cmps(); }
	// --setters
	gfx_cmd::cmd_t& gfx_cmd::set_type(type_tc type) { m_type = type; return *this; }
	gfx_cmd::cmd_t& gfx_cmd::set_prim(prim_tc prim) { m_prim = prim; return *this; }
	gfx_cmd::cmd_t& gfx_cmd::set_cmps() { while (m_cmps != NW_NULL) { rmv_cmp(NW_NULL); } return *this; }
	gfx_cmd::cmd_t& gfx_cmd::set_cmps(cmp_list_tc& cmps) { set_cmps(); for (auto& icmp : cmps) { add_cmp(icmp); } return *this; }
	gfx_cmd::cmd_t& gfx_cmd::add_cmp(cmp_tc* cmp) {
		cmps_t next_head = new t_mem_link<cmp_t>();
		next_head->m_link = m_cmps;
		next_head->m_data = const_cast<cmp_t*>(cmp);
		m_cmps = next_head;
		return *this;
	}
	gfx_cmd::cmd_t& gfx_cmd::rmv_cmp(size_tc key) {
		NW_CHECK(has_cmp(key), "index error!", return *this);
		cmps_t next_head = m_cmps->m_link;
		delete m_cmps;
		m_cmps = next_head;
		return *this;
	}
	// --operators
	gfx_cmd::cmd_t& gfx_cmd::operator=(cmd_tc& copy) {
		set_cmps();
		cmps_t temp = copy.get_cmps();
		while (temp != NW_NULL) {
			add_cmp(temp->m_data);
			temp = temp->m_link;
		}
		NW_CHECK(remake(copy.get_type(), copy.get_prim()), "remake error!", return *this);
		return *this;
	}
	gfx_cmd::cmd_t& gfx_cmd::operator=(cmd_t&& copy) {
		set_cmps();
		cmps_t temp = copy.get_cmps();
		while (temp != NW_NULL) {
			add_cmp(temp->m_data);
			temp = temp->m_link;
		}
		NW_CHECK(remake(copy.get_type(), copy.get_prim()), "remake error!", return *this);
		return *this;
	}
	// --==<core_methods>==--
	v1bit gfx_cmd::remake()
	{
		NW_CHECK(has_type(), "no type!", return NW_FALSE);
		//NW_CHECK(has_prim(), "no prim!", return NW_FALSE);
		NW_CHECK(has_cmps(), "no cmps!", return NW_FALSE);
		return NW_TRUE;
	}
	v1nil gfx_cmd::on_draw()
	{
		GLsizei vcount = NW_NULL;
		GLsizei icount = NW_NULL;
		GLenum itype = NW_NULL;
		auto link = get_cmps();
		while (link != NW_NULL) {
			auto icmp = static_cast<gfx_buf*>(link->m_data);
			icmp->on_draw();
			if (gfx_buf_idx* ibuf = icmp->check_cast<gfx_buf_idx>()) {
				icount += ibuf->get_count();
				itype = gfx_info::get_type(ibuf->get_layt().get_type());
			}
			if (gfx_buf_vtx* vbuf = icmp->check_cast<gfx_buf_vtx>()) {
				vcount += vbuf->get_count();
			}
			link = link->m_link;
		}
		if (has_type(NW_GFX_CMD_VTX)) { glDrawArrays(get_prim(), NW_NULL, vcount); }
		if (has_type(NW_GFX_CMD_IDX)) { glDrawElements(get_prim(), icount, itype, NW_NULL); }
	}
	// --==</core_methods>==--
}
namespace NW
{
	gfx_cmd_buf::gfx_cmd_buf() :
		m_list(NW_NULL)
	{
	}
	gfx_cmd_buf::gfx_cmd_buf(cbuf_tc& copy) :
		gfx_cmd_buf()
	{
		operator=(copy);
	}
	gfx_cmd_buf::gfx_cmd_buf(cbuf_t&& copy) :
		gfx_cmd_buf()
	{
		operator=(copy);
	}
	gfx_cmd_buf::~gfx_cmd_buf()
	{
		while (m_list != NW_NULL) { rmv_cmd(NW_NULL); }
	}
	// --setters
	v1nil gfx_cmd_buf::add_cmd(cmd_tc& command) {
		list_t* next_head = new list_t();
		next_head->m_link = m_list;
		next_head->m_data = new cmd_t(command);
		m_list = next_head;
	}
	v1nil gfx_cmd_buf::rmv_cmd(cv1u key) {
		NW_CHECK(has_cmd(key), "index error!", return);
		list_t* next_head = m_list->m_link;
		delete m_list->m_data;
		delete m_list;
		m_list = next_head;
	}
	// --operators
	v1nil gfx_cmd_buf::operator=(cbuf_tc& copy) {
		NW_ERROR("does not work for now", return);
	}
	v1nil gfx_cmd_buf::operator=(cbuf_t&& copy) {
		NW_ERROR("does not work for now", return);
	}
	// --==<core_methods>==--
	v1nil gfx_cmd_buf::on_draw()
	{
		while (m_list != NW_NULL) {
			auto& icmd = *m_list->m_data;
			m_list->m_data->on_draw();
			rmv_cmd(NW_NULL);
		}
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	//
}
#	endif	// GAPI_OGL
#endif	// NW_GAPI