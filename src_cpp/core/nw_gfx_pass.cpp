#include "nw_gfx_pch.hpp"
#include "nw_gfx_pass.h"
#if (defined NW_GAPI)
namespace NW
{
	gfx_pass::gfx_pass() : a_mem_owner(), m_cmds(cmds_t()), m_links(links_t()) { }
	gfx_pass::gfx_pass(cmds_tc& cmds) : gfx_pass()     { NW_CHECK(remake(cmds), "remake error!", return); }
	gfx_pass::gfx_pass(cmd_list_tc& cmds) : gfx_pass() { NW_CHECK(remake(cmds), "remake error!", return); }
	gfx_pass::gfx_pass(links_tc& links) : gfx_pass()     { NW_CHECK(remake(links), "remake error!", return); }
	gfx_pass::gfx_pass(link_list_tc& links) : gfx_pass() { NW_CHECK(remake(links), "remake error!", return); }
	gfx_pass::gfx_pass(cmds_tc& cmds, links_tc& links) : gfx_pass() { NW_CHECK(remake(cmds, links), "remake error!", return); }
	gfx_pass::gfx_pass(cmd_list_tc& cmds, link_list_tc& links) : gfx_pass() { NW_CHECK(remake(cmds, links), "remake error!", return); }
	gfx_pass::gfx_pass(links_tc& links, cmds_tc& cmds) : gfx_pass() { NW_CHECK(remake(links, cmds), "remake error!", return); }
	gfx_pass::gfx_pass(link_list_tc& links, cmd_list_tc& cmds) : gfx_pass() { NW_CHECK(remake(links, cmds), "remake error!", return); }
	gfx_pass::gfx_pass(pass_tc& copy) : gfx_pass() { operator=(copy); }
	gfx_pass::gfx_pass(pass_t&& copy) : gfx_pass() { operator=(copy); }
	gfx_pass::~gfx_pass() { set_cmds().set_links(); }
	// --setters
	gfx_pass::pass_t& gfx_pass::set_cmds() { m_cmds.clear(); return *this; }
	gfx_pass::pass_t& gfx_pass::set_cmds(cmds_tc& cmds) { m_cmds.clear(); for (auto& icmd : cmds) { add_cmd(icmd); } return *this; }
	gfx_pass::pass_t& gfx_pass::set_cmds(cmd_list_tc& cmds) { m_cmds.clear(); for (auto& icmd : cmds) { add_cmd(icmd); } return *this; }
	gfx_pass::pass_t& gfx_pass::add_cmd() { add_cmd(cmd_t()); return *this; }
	gfx_pass::pass_t& gfx_pass::add_cmd(cmd_tc& cmd) { m_cmds.push_back(cmd); return *this; }
	gfx_pass::pass_t& gfx_pass::rmv_cmd() { NW_CHECK(has_cmd(), "no cmds!", return *this); m_cmds.erase(--m_cmds.end()); return *this; }
	gfx_pass::pass_t& gfx_pass::rmv_cmd(size_tc key) {
		size_t itr = 0u; auto icmd = m_cmds.begin();
		while (icmd != m_cmds.end()) { if (itr == key) { m_cmds.erase(icmd); return *this; }icmd++; }
		NW_ERROR("key error!", return *this);
		return *this;
	}
	gfx_pass::pass_t& gfx_pass::set_links() { m_links.clear(); return *this; }
	gfx_pass::pass_t& gfx_pass::set_links(links_tc& links) { for (auto& ilink : links) { add_link(ilink); } m_links.clear(); return *this; }
	gfx_pass::pass_t& gfx_pass::set_links(link_list_tc& links) { for (auto& ilink : links) { add_link(ilink); } m_links.clear(); return *this; }
	gfx_pass::pass_t& gfx_pass::add_link(link_tc link) { m_links.push_back(link); return *this; }
	gfx_pass::pass_t& gfx_pass::rmv_link() { NW_CHECK(has_link(), "no links!", return *this); m_links.erase(--m_links.end()); return *this; }
	gfx_pass::pass_t& gfx_pass::rmv_link(size_tc key) {
		size_t itr = 0u; auto ilink = m_links.begin();
		while (ilink != m_links.end()) { if (itr == key) { m_links.erase(ilink); return *this; } ilink++; }
		NW_ERROR("key error!", return *this);
		return *this;
	}
	// --==<core_methods>==--
	v1bit gfx_pass::remake()
	{
		//NW_CHECK(has_cmd(), "no commands!", return NW_FALSE);
		//NW_CHECK(has_link(), "no links!", return NW_FALSE);
		return NW_TRUE;
	}
	v1nil gfx_pass::on_draw()
	{
		for (auto& icmd : m_cmds) { icmd.on_draw(); }
		for (auto& ilink : m_links) { ilink->on_draw(); }
	}
	// --==</core_methods>==--
}
#endif	// NW_GAPI