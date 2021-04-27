#include "nw_gfx_pch.hpp"
#include "nw_gfx_graph.h"
#if (defined NW_GAPI)
namespace NW
{
	gfx_graph::gfx_graph() : a_mem_owner(), m_passes(passes_t()), m_root(NW_NULL) { }
	gfx_graph::gfx_graph(passes_tc& passes) : gfx_graph() { NW_CHECK(remake(passes), "remake error!", return); }
	gfx_graph::gfx_graph(pass_list_tc& passes) : gfx_graph() { NW_CHECK(remake(passes), "remake error!", return); }
	gfx_graph::gfx_graph(passes_tc& passes, size_tc root_key) : gfx_graph() { NW_CHECK(remake(passes, root_key), "remake error!", return); }
	gfx_graph::gfx_graph(pass_list_tc& passes, size_tc root_key) : gfx_graph() { NW_CHECK(remake(passes, root_key), "remake error!", return); }
	gfx_graph::gfx_graph(graph_tc& copy) : gfx_graph() { operator=(copy); }
	gfx_graph::gfx_graph(graph_t&& copy) : gfx_graph() { operator=(copy); }
	gfx_graph::~gfx_graph() { }
	// --setters
	gfx_graph::graph_t& gfx_graph::set_passes(passes_tc& passes) { m_passes.clear(); for (auto& ipass : passes) { add_pass(ipass); } return *this; }
	gfx_graph::graph_t& gfx_graph::set_passes(pass_list_tc& passes) { m_passes.clear(); for (auto& ipass : passes) { add_pass(ipass); } return *this; }
	gfx_graph::graph_t& gfx_graph::set_root(size_t key) {
		m_root = &get_pass(key);
		return *this;
	}
	gfx_graph::graph_t& gfx_graph::add_pass() {
		return add_pass(pass_t());
	}
	gfx_graph::graph_t& gfx_graph::add_pass(pass_tc& pass) {
		NW_CHECK(!has_pass(&pass), "already used pass!", return *this);
		//if (pass.has_link()) { for (auto& ipass : pass.get_links()) { add_pass(ipass); } }
		m_passes.push_back(pass);
		return *this;
	}
	gfx_graph::graph_t& gfx_graph::rmv_pass() {
		NW_CHECK(has_pass(), "no passes!", return *this);
		m_passes.erase(--m_passes.end());
		return *this;
	}
	gfx_graph::graph_t& gfx_graph::rmv_pass(size_t key) {
		NW_CHECK(has_pass(), "no passes!", return *this);
		size_t itr = 0u; auto& ipass = m_passes.begin();
		while (ipass != m_passes.end()) { if (itr++ == key) { m_passes.erase(ipass); return *this; } ipass++; }
		NW_ERROR("key error!", return *this);
		return *this;
	}
	// --==<core_methods>==--
	v1bit gfx_graph::remake()
	{
		NW_CHECK(has_pass(), "no passes!", return NW_FALSE);
		NW_CHECK(has_root(), "no root pass!", return NW_FALSE);

		for (auto& ipass : m_passes) { NW_CHECK(ipass.remake(), "remake error!", return NW_FALSE); }

		return NW_TRUE;
	}
	v1nil gfx_graph::on_draw()
	{
		m_root->on_draw();
	}
	// --==</core_methods>==--
}
#endif	// NW_GAPI