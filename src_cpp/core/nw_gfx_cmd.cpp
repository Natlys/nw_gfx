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
	gfx_cmd::gfx_cmd(type_tc type, prim_tc primitive) :
		a_mem_cmp(),
		m_type(type),
		m_prim(primitive),
		m_list(NW_NULL)
	{
	}
	gfx_cmd::gfx_cmd(cmd_tc& copy) :
		a_mem_cmp(copy),
		m_type(copy.m_type),
		m_prim(copy.m_prim),
		m_list(NW_NULL)
	{
		list_t* temp = copy.m_list;
		while (temp != NW_NULL) {
			add_cmp(temp->m_data);
			temp = temp->m_link;
		}
	}
	gfx_cmd::gfx_cmd(cmd_t&& copy) :
		a_mem_cmp(copy),
		m_type(copy.m_type),
		m_prim(copy.m_prim),
		m_list(NW_NULL)
	{
		list_t* temp = copy.m_list;
		while (temp != NW_NULL) {
			add_cmp(temp->m_data);
			temp = copy.m_list;
		}
	}
	gfx_cmd::~gfx_cmd()
	{
		while (m_list != NW_NULL) { rmv_cmp(NW_NULL); }
	}
	// --setters
	v1nil gfx_cmd::add_cmp(cmp_t* component) {
		list_t* next_head = new list_t();
		next_head->m_link = m_list;
		next_head->m_data = component;
		m_list = next_head;
	}
	v1nil gfx_cmd::rmv_cmp(cv1u key) {
		NW_CHECK(has_cmp(key), "index error!", return);
		list_t* next_head = m_list->m_link;
		delete m_list;
		m_list = next_head;
	}
	// --operators
	v1nil gfx_cmd::operator=(cmd_tc& copy) {
		NW_ERROR("does not work for now", return);
	}
	v1nil gfx_cmd::operator=(cmd_t&& copy) {
		NW_ERROR("does not work for now", return);
	}
	// --==<core_methods>==--
	// --==</core_methods>==--
}
namespace NW
{
	gfx_cmd_buf::gfx_cmd_buf() :
		a_gfx_cmp(),
		m_list(NW_NULL)
	{
	}
	gfx_cmd_buf::gfx_cmd_buf(cbuf_tc& copy) :
		a_gfx_cmp(copy)
	{
		NW_ERROR("does not work for now", return);
	}
	gfx_cmd_buf::gfx_cmd_buf(cbuf_t&& copy) :
		a_gfx_cmp(copy)
	{
		NW_ERROR("does not work for now", return);
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
			GLsizei vcount = NW_NULL;
			GLsizei icount = NW_NULL;
			GLenum itype = NW_NULL;
			while (icmd.m_list != NW_NULL) {
				a_gfx_buf* icmp = static_cast<a_gfx_buf*>(icmd.m_list->m_data);
				icmp->on_draw();
				if (gfx_buf_idx* ibuf = icmp->check_cast<gfx_buf_idx>()) {
					icount += ibuf->get_count();
					itype = gfx_info::get_type(ibuf->get_layt().get_vtype());
				}
				if (gfx_buf_vtx* vbuf = icmp->check_cast<gfx_buf_vtx>()) {
					vcount += vbuf->get_count();
				}
				icmd.rmv_cmp(NW_NULL);
			}
			if (icmd.m_type == NW_GFX_CMD_VTX) {
				glDrawArrays(icmd.m_prim, NW_NULL, vcount);
			}
			if (icmd.m_type == NW_GFX_CMD_IDX) {
				glDrawElements(icmd.m_prim, icount, itype, NW_NULL);
			}
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