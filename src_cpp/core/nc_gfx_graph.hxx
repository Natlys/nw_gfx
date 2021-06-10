#ifndef NC_GFX_GRAPH_H
#define NC_GFX_GRAPH_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "nc_gfx_pass.hxx"
namespace NC
{
	/// graphics_graph_type
	class gfx_graph_t : public nc_cmp_tt<gfx_graph_t>, public gfx_cmp_t, public mem_user_t
	{
	public:
		using graph_t = gfx_graph_t;
		using graph_tc = const graph_t;
		using pass_t = gfx_pass_t;
		using pass_tc = const pass_t;
		using passes_t = list2_t<pass_t>;
		using passes_tc = const passes_t;
		using pass_list_t = init_list_t<pass_t>;
		using pass_list_tc = const pass_list_t;
		using root_t = pass_t*;
		using root_tc = const root_t;
	public:
		gfx_graph_t();
		gfx_graph_t(passes_tc& passes);
		gfx_graph_t(pass_list_tc& passes);
		gfx_graph_t(passes_tc& passes, size_tc root);
		gfx_graph_t(pass_list_tc& passes, size_tc root);
		gfx_graph_t(graph_tc& copy);
		gfx_graph_t(graph_t&& copy);
		~gfx_graph_t();
		/* getters */
		inline passes_t& get_passes()        { return m_passes; }
		inline passes_tc& get_passes() const { return m_passes; }
		inline size_t get_pass_count() const { size_t count = 0u; for (auto& ipass : m_passes) { count++; } return count; }
		inline pass_t& get_pass(size_t key) {
			size_t itr = 0u; auto ipass = m_passes.begin();
			while (ipass != m_passes.end()) { if (itr++ == key) { return *ipass; } ipass++; }
			NC_ERROR("not found!", return *m_passes.begin());
			return *m_passes.begin();
		}
		inline pass_tc& get_pass(size_t key) const {
		size_t itr = 0u; auto ipass = m_passes.begin();
			while (ipass != m_passes.end()) { if (itr++ == key) { return *ipass; } ipass++; }
			NC_ERROR("not found!", return *m_passes.begin());
			return *m_passes.begin();
		}
		inline root_t& get_root()        { return m_root; }
		inline root_tc& get_root() const { return m_root; }
		/* setters */
		graph_t& set_passes(passes_tc& passes);
		graph_t& set_passes(pass_list_tc& passes);
		graph_t& set_root(size_t key);
		graph_t& add_pass();
		graph_t& add_pass(pass_tc& pass);
		graph_t& rmv_pass();
		graph_t& rmv_pass(size_t key);
		/* vetters */
		inline v1bit_t has_pass() const              { return !m_passes.empty(); }
		inline v1bit_t has_pass(size_t key) const    { return get_pass_count() > key; }
		inline v1bit_t has_pass(pass_tc* pass) const { for (auto& ipass : m_passes) { if (&ipass == pass) { return NC_TRUTH; } } return NC_FALSE; }
		inline v1bit_t has_root() const      { return m_root != NC_NULL; }
		/* operators */
		inline graph_t& operator=(graph_tc& copy) { m_root = copy.get_root(); NC_CHECK(remake(copy.get_passes()), "remake error!", return *this); return *this; }
		inline graph_t& operator=(graph_t&& copy) { m_root = copy.get_root(); NC_CHECK(remake(copy.get_passes()), "remake error!", return *this); return *this; }
		/* command */
		v1bit_t remake();
		inline v1bit_t remake(size_t root_key) { set_root(root_key); return remake(); }
		inline v1bit_t remake(passes_tc& passes) { set_passes(passes); return remake(0u); }
		inline v1bit_t remake(pass_list_tc& passes) { set_passes(passes); return remake(0u); }
		inline v1bit_t remake(passes_tc& passes, size_t root_key) { set_passes(passes); return remake(root_key); }
		inline v1bit_t remake(pass_list_tc& passes, size_t root_key) { set_passes(passes); return remake(root_key); }
		v1nil_t on_draw();
	protected:
		passes_t m_passes;
		root_t m_root;
	};
}
#endif	// NC_GAPI
#endif	// NC_GFX_GRAPH_H