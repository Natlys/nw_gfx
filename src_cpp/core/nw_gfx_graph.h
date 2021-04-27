#ifndef NW_GFX_GRAPH_H
#define NW_GFX_GRAPH_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_pass.h"
namespace NW
{
	/// graphics_graph class
	class NW_API gfx_graph : public t_cmp<gfx_graph>, public a_gfx_cmp, public a_mem_owner
	{
	public:
		using graph_t = gfx_graph;
		using graph_tc = const graph_t;
		using pass_t = gfx_pass;
		using pass_tc = const pass_t;
		using passes_t = list2_t<pass_t>;
		using passes_tc = const passes_t;
		using pass_list_t = init_list_t<pass_t>;
		using pass_list_tc = const pass_list_t;
		using root_t = pass_t*;
		using root_tc = const root_t;
	public:
		gfx_graph();
		gfx_graph(passes_tc& passes);
		gfx_graph(pass_list_tc& passes);
		gfx_graph(passes_tc& passes, size_tc root);
		gfx_graph(pass_list_tc& passes, size_tc root);
		gfx_graph(graph_tc& copy);
		gfx_graph(graph_t&& copy);
		~gfx_graph();
		// --getters
		inline passes_t& get_passes()        { return m_passes; }
		inline passes_tc& get_passes() const { return m_passes; }
		inline size_t get_pass_count() const { size_t count = 0u; for (auto& ipass : m_passes) { count++; } return count; }
		inline pass_t& get_pass(size_t key) {
			size_t itr = 0u; auto ipass = m_passes.begin();
			while (ipass != m_passes.end()) { if (itr++ == key) { return *ipass; } ipass++; }
			NW_ERROR("not found!", return *m_passes.begin());
			return *m_passes.begin();
		}
		inline pass_tc& get_pass(size_t key) const {
		size_t itr = 0u; auto ipass = m_passes.begin();
			while (ipass != m_passes.end()) { if (itr++ == key) { return *ipass; } ipass++; }
			NW_ERROR("not found!", return *m_passes.begin());
			return *m_passes.begin();
		}
		inline root_t& get_root()        { return m_root; }
		inline root_tc& get_root() const { return m_root; }
		// --setters
		graph_t& set_passes(passes_tc& passes);
		graph_t& set_passes(pass_list_tc& passes);
		graph_t& set_root(size_t key);
		graph_t& add_pass();
		graph_t& add_pass(pass_tc& pass);
		graph_t& rmv_pass();
		graph_t& rmv_pass(size_t key);
		// --predicates
		inline v1bit has_pass() const              { return !m_passes.empty(); }
		inline v1bit has_pass(size_t key) const    { return get_pass_count() > key; }
		inline v1bit has_pass(pass_tc* pass) const { for (auto& ipass : m_passes) { if (&ipass == pass) { return NW_TRUE; } } return NW_FALSE; }
		inline v1bit has_root() const      { return m_root != NW_NULL; }
		// --operators
		inline graph_t& operator=(graph_tc& copy) { m_root = copy.get_root(); NW_CHECK(remake(copy.get_passes()), "remake error!", return *this); return *this; }
		inline graph_t& operator=(graph_t&& copy) { m_root = copy.get_root(); NW_CHECK(remake(copy.get_passes()), "remake error!", return *this); return *this; }
		// --core_methods
		v1bit remake();
		inline v1bit remake(size_t root_key) { set_root(root_key); return remake(); }
		inline v1bit remake(passes_tc& passes) { set_passes(passes); return remake(0u); }
		inline v1bit remake(pass_list_tc& passes) { set_passes(passes); return remake(0u); }
		inline v1bit remake(passes_tc& passes, size_t root_key) { set_passes(passes); return remake(root_key); }
		inline v1bit remake(pass_list_tc& passes, size_t root_key) { set_passes(passes); return remake(root_key); }
		v1nil on_draw();
	protected:
		passes_t m_passes;
		root_t m_root;
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_GRAPH_H