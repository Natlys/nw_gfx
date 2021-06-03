#include "nc_gfx_pch.hpp"
#include "nc_gfx_graph.hxx"
#if (defined NC_GAPI)
namespace NC
{
	gfx_graph_t::gfx_graph_t() : nc_cmp_tt(), gfx_cmp_t(), mem_user_t(), m_passes(passes_t()), m_root(NC_NULL) { }
	gfx_graph_t::gfx_graph_t(passes_tc& passes) : gfx_graph_t() { NC_CHECK(remake(passes), "remake error!", return); }
	gfx_graph_t::gfx_graph_t(pass_list_tc& passes) : gfx_graph_t() { NC_CHECK(remake(passes), "remake error!", return); }
	gfx_graph_t::gfx_graph_t(passes_tc& passes, size_tc root_key) : gfx_graph_t() { NC_CHECK(remake(passes, root_key), "remake error!", return); }
	gfx_graph_t::gfx_graph_t(pass_list_tc& passes, size_tc root_key) : gfx_graph_t() { NC_CHECK(remake(passes, root_key), "remake error!", return); }
	gfx_graph_t::gfx_graph_t(graph_tc& copy) : gfx_graph_t() { operator=(copy); }
	gfx_graph_t::gfx_graph_t(graph_t&& copy) : gfx_graph_t() { operator=(copy); }
	gfx_graph_t::~gfx_graph_t() { }
	/* setters */
	gfx_graph_t::graph_t& gfx_graph_t::set_passes(passes_tc& passes) { m_passes.clear(); for (auto& ipass : passes) { add_pass(ipass); } return *this; }
	gfx_graph_t::graph_t& gfx_graph_t::set_passes(pass_list_tc& passes) { m_passes.clear(); for (auto& ipass : passes) { add_pass(ipass); } return *this; }
	gfx_graph_t::graph_t& gfx_graph_t::set_root(size_t key) { m_root = &get_pass(key); return *this; }
	gfx_graph_t::graph_t& gfx_graph_t::add_pass() { return add_pass(pass_t()); }
	gfx_graph_t::graph_t& gfx_graph_t::add_pass(pass_tc& pass) {
		NC_CHECK(!has_pass(&pass), "already used pass!", return *this);
		//if (pass.has_link()) { for (auto& ipass : pass.get_links()) { add_pass(ipass); } }
		m_passes.push_back(pass);
		return *this;
	}
	gfx_graph_t::graph_t& gfx_graph_t::rmv_pass() {
		NC_CHECK(has_pass(), "no passes!", return *this);
		m_passes.erase(--m_passes.end());
		return *this;
	}
	gfx_graph_t::graph_t& gfx_graph_t::rmv_pass(size_t key) {
		NC_CHECK(has_pass(), "no passes!", return *this);
		size_t itr = 0u; auto& ipass = m_passes.begin();
		while (ipass != m_passes.end()) { if (itr++ == key) { m_passes.erase(ipass); return *this; } ipass++; }
		NC_ERROR("key error!", return *this);
		return *this;
	}
	/* commands */
	v1bit_t gfx_graph_t::remake()
	{
		NC_CHECK(has_pass(), "no passes!", return NC_FALSE);
		NC_CHECK(has_root(), "no root pass!", return NC_FALSE);

		for (auto& ipass : m_passes) { NC_CHECK(ipass.remake(), "remake error!", return NC_FALSE); }

		return NC_TRUTH;
	}
	v1nil_t gfx_graph_t::on_draw()
	{
		if (m_root != NC_NULL) { m_root->on_draw(); }
	}
	// --==</core_methods>==--
}
#endif	// NC_GAPI