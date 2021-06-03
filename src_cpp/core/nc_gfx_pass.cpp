#include "nc_gfx_pch.hpp"
#include "nc_gfx_pass.hxx"
#if (defined NC_GAPI)
namespace NC
{
	gfx_pass_t::gfx_pass_t() : mem_owner_t(), m_cmds(cmds_t()), m_links(links_t()) { }
	gfx_pass_t::gfx_pass_t(cmds_tc& cmds) : gfx_pass_t()     { NC_CHECK(remake(cmds), "remake error!", return); }
	gfx_pass_t::gfx_pass_t(cmd_list_tc& cmds) : gfx_pass_t() { NC_CHECK(remake(cmds), "remake error!", return); }
	gfx_pass_t::gfx_pass_t(links_tc& links) : gfx_pass_t()     { NC_CHECK(remake(links), "remake error!", return); }
	gfx_pass_t::gfx_pass_t(link_list_tc& links) : gfx_pass_t() { NC_CHECK(remake(links), "remake error!", return); }
	gfx_pass_t::gfx_pass_t(cmds_tc& cmds, links_tc& links) : gfx_pass_t() { NC_CHECK(remake(cmds, links), "remake error!", return); }
	gfx_pass_t::gfx_pass_t(cmd_list_tc& cmds, link_list_tc& links) : gfx_pass_t() { NC_CHECK(remake(cmds, links), "remake error!", return); }
	gfx_pass_t::gfx_pass_t(links_tc& links, cmds_tc& cmds) : gfx_pass_t() { NC_CHECK(remake(links, cmds), "remake error!", return); }
	gfx_pass_t::gfx_pass_t(link_list_tc& links, cmd_list_tc& cmds) : gfx_pass_t() { NC_CHECK(remake(links, cmds), "remake error!", return); }
	gfx_pass_t::gfx_pass_t(pass_tc& copy) : gfx_pass_t() { operator=(copy); }
	gfx_pass_t::gfx_pass_t(pass_t&& copy) : gfx_pass_t() { operator=(copy); }
	gfx_pass_t::~gfx_pass_t() { set_cmds().set_links(); }
	/* setters */
	gfx_pass_t::pass_t& gfx_pass_t::set_cmds() { m_cmds.clear(); return *this; }
	gfx_pass_t::pass_t& gfx_pass_t::set_cmds(cmds_tc& cmds) { m_cmds.clear(); for (auto& icmd : cmds) { add_cmd(icmd); } return *this; }
	gfx_pass_t::pass_t& gfx_pass_t::set_cmds(cmd_list_tc& cmds) { m_cmds.clear(); for (auto& icmd : cmds) { add_cmd(icmd); } return *this; }
	gfx_pass_t::pass_t& gfx_pass_t::add_cmd() { add_cmd(cmd_t()); return *this; }
	gfx_pass_t::pass_t& gfx_pass_t::add_cmd(cmd_tc& cmd) { m_cmds.push_back(cmd); return *this; }
	gfx_pass_t::pass_t& gfx_pass_t::rmv_cmd() { NC_CHECK(has_cmd(), "no cmds!", return *this); m_cmds.erase(--m_cmds.end()); return *this; }
	gfx_pass_t::pass_t& gfx_pass_t::rmv_cmd(size_tc key) {
		size_t itr = 0u; auto icmd = m_cmds.begin();
		while (icmd != m_cmds.end()) { if (itr == key) { m_cmds.erase(icmd); return *this; }icmd++; }
		NC_ERROR("key error!", return *this);
		return *this;
	}
	gfx_pass_t::pass_t& gfx_pass_t::set_links() { m_links.clear(); return *this; }
	gfx_pass_t::pass_t& gfx_pass_t::set_links(links_tc& links) { for (auto& ilink : links) { add_link(ilink); } m_links.clear(); return *this; }
	gfx_pass_t::pass_t& gfx_pass_t::set_links(link_list_tc& links) { for (auto& ilink : links) { add_link(ilink); } m_links.clear(); return *this; }
	gfx_pass_t::pass_t& gfx_pass_t::add_link(link_tc link) { m_links.push_back(link); return *this; }
	gfx_pass_t::pass_t& gfx_pass_t::rmv_link() { NC_CHECK(has_link(), "no links!", return *this); m_links.erase(--m_links.end()); return *this; }
	gfx_pass_t::pass_t& gfx_pass_t::rmv_link(size_tc key) {
		size_t itr = 0u; auto ilink = m_links.begin();
		while (ilink != m_links.end()) { if (itr == key) { m_links.erase(ilink); return *this; } ilink++; }
		NC_ERROR("key error!", return *this);
		return *this;
	}
	/* commands */
	v1bit_t gfx_pass_t::remake()
	{
		//NC_CHECK(has_cmd(), "no commands!", return NC_FALSE);
		//NC_CHECK(has_link(), "no links!", return NC_FALSE);
		return NC_TRUTH;
	}
	v1nil_t gfx_pass_t::on_draw()
	{
		for (auto& icmd : m_cmds) { icmd.on_draw(); }
		for (auto& ilink : m_links) { ilink->on_draw(); }
	}
	// --==</core_methods>==--
}
#endif	// NC_GAPI