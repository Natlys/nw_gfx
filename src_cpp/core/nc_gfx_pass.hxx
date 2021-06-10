#ifndef NC_GFX_PASS_H
#define NC_GFX_PASS_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "nc_gfx_cmd.hxx"
namespace NC
{
	/// graphics_pass_type
	class gfx_pass_t : public mem_owner_t, public nc_name_owner_t
	{
	public:
		using pass_t = gfx_pass_t;
		using pass_tc = const pass_t;
		using cmd_t = gfx_cmd_t;
		using cmd_tc = const cmd_t;
		using cmds_t = array_t<cmd_t>;
		using cmds_tc = const cmds_t;
		using cmd_list_t = init_list_t<cmd_t>;
		using cmd_list_tc = const cmd_list_t;
		using link_t = gfx_pass_t*;
		using link_tc = const link_t;
		using links_t = array_t<link_t>;
		using links_tc = const links_t;
		using link_list_t = init_list_t<link_t>;
		using link_list_tc = const link_list_t;
	public:
		gfx_pass_t();
		gfx_pass_t(cmds_tc& cmds);
		gfx_pass_t(cmd_list_tc& cmds);
		gfx_pass_t(links_tc& links);
		gfx_pass_t(link_list_tc& links);
		gfx_pass_t(cmds_tc& cmds, links_tc &links);
		gfx_pass_t(cmd_list_tc& cmds, link_list_tc& links);
		gfx_pass_t(links_tc& links, cmds_tc& cmds);
		gfx_pass_t(link_list_tc& links, cmd_list_tc& cmds);
		gfx_pass_t(pass_tc& copy);
		gfx_pass_t(pass_t&& copy);
		~gfx_pass_t();
		/* getters */
		inline cmds_t& get_cmds()        { return m_cmds; }
		inline cmds_tc& get_cmds() const { return m_cmds; }
		inline size_tc get_cmd_count() const { size_t count = 0u; for (auto& icmd : m_cmds) { count++; } return count; }
		inline cmd_t& get_cmd(size_t key) {
			size_t itr = 0u;
			for (auto& icmd : m_cmds) { if (itr++ == key) { return icmd; } }
			NC_ERROR("key error!", return *m_cmds.begin());
			return *m_cmds.begin();
		}
		inline cmd_tc& get_cmd(size_t key) const {
			size_t itr = 0u;
			for (auto& icmd : m_cmds) { if (itr++ == key) { return icmd; } }
			NC_ERROR("key error!", return *m_cmds.begin());
			return *m_cmds.begin();
		}
		inline links_t& get_links()        { return m_links; }
		inline links_tc& get_links() const { return m_links; }
		inline link_t& get_link(size_t key) {
			size_t itr = 0u;
			for (auto& ilink : m_links) { if (itr++ == key) { return ilink; } }
			NC_ERROR("key error!", return *m_links.begin());
			return *m_links.begin();
		}
		inline link_tc& get_link(size_t key) const {
			size_t itr = 0u;
			for (auto& ilink : m_links) { if (itr++ == key) { return ilink; } }
			NC_ERROR("key error!", return *m_links.begin());
			return *m_links.begin();
		}
		inline size_tc get_link_count() const { size_t count = 0u; for (auto& ilink : m_links) { count++; } return count; }
		/* setters */
		pass_t& set_cmds();
		pass_t& set_cmds(cmds_tc& cmds);
		pass_t& set_cmds(cmd_list_tc& cmds);
		pass_t& add_cmd();
		pass_t& add_cmd(cmd_tc& cmd);
		pass_t& rmv_cmd();
		pass_t& rmv_cmd(size_tc key);
		pass_t& set_links();
		pass_t& set_links(links_tc& links);
		pass_t& set_links(link_list_tc& links);
		pass_t& add_link(link_tc link);
		pass_t& rmv_link();
		pass_t& rmv_link(size_tc key);
		/* vetters */
		inline v1bit_t has_cmd() const            { return !m_cmds.empty(); }
		inline v1bit_t has_cmd(size_t key) const  { return get_cmd_count() > key; }
		inline v1bit_t has_link() const           { return !m_links.empty(); }
		inline v1bit_t has_link(size_t key) const { return get_link_count() > key; }
		/* operators */
		inline pass_t& operator=(pass_tc& copy) { NC_CHECK(remake(copy.get_cmds(), copy.get_links()), "remake error!", return *this); return *this; }
		inline pass_t& operator=(pass_t&& copy) { NC_CHECK(remake(copy.get_cmds(), copy.get_links()), "remake error!", return *this); return *this; }
		/* command */
		v1bit_t remake();
		inline v1bit_t remake(cmds_tc& cmds)       { set_cmds(cmds); return remake(); }
		inline v1bit_t remake(cmd_list_tc& cmds)   { set_cmds(cmds); return remake(); }
		inline v1bit_t remake(link_list_tc& links) { set_links(links); return remake(); }
		inline v1bit_t remake(links_tc& links)     { set_links(links); return remake(); }
		inline v1bit_t remake(cmd_list_tc& cmds, link_list_tc& links) { set_cmds(cmds).set_links(links); return remake(); }
		inline v1bit_t remake(cmds_tc& cmds, links_tc& links)         { set_cmds(cmds).set_links(links); return remake(); }
		inline v1bit_t remake(link_list_tc& links, cmd_list_tc& cmds) { set_links(links).set_cmds(cmds); return remake(); }
		inline v1bit_t remake(links_tc& links, cmds_tc& cmds)         { set_links(links).set_cmds(cmds); return remake(); }
		v1nil_t on_draw();
	public:
		cmds_t m_cmds;
		links_t m_links;
	};
}
#endif	// NC_GAPI
#endif	// NC_GFX_PASS_H