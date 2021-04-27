#ifndef NW_GFX_ENGINE_H
#define NW_GFX_ENGINE_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_context.h"
#	include "nw_gfx_cmd.h"
#	include "nw_gfx_pass.h"
#	include "nw_gfx_graph.h"
namespace NW
{
	/// graphics_engine class
	class NW_API gfx_engine : public t_singleton<gfx_engine>, public a_mem_owner
	{
	public:
		using engine_t = gfx_engine;
		using engine_tc = const engine_t;
		using context_t = gfx_context;
		using context_tc = const context_t;
		using window_t = context_t::window_t;
		using window_tc = context_t::window_tc;
		using cmd_t = gfx_cmd;
		using cmd_tc = const cmd_t;
		using cmd_buf_t = gfx_cmd_buf;
		using cmd_buf_tc = const cmd_buf_t;
		using graph_t = gfx_graph;
		using graph_tc = const graph_t;
		using viewp_t = v4f;
		using viewp_tc = const viewp_t;
		using vsync_t = v1u;
		using vsync_tc = const vsync_t;
	public:
		gfx_engine();
		gfx_engine(engine_tc& copy) = delete;
		gfx_engine(engine_t&& copy) = delete;
		~gfx_engine();
		// --getters
		inline context_t& get_context()        { return m_context; }
		inline context_tc& get_context() const { return m_context; }
		inline window_t& get_window()          { return m_context.get_window(); }
		inline window_tc& get_window() const   { return m_context.get_window(); }
		inline cmd_buf_t& get_cmd_buf()        { return m_cmd_buf; }
		inline cmd_buf_tc& get_cmd_buf() const { return m_cmd_buf; }
		inline graph_t& get_graph()        { return m_graph; }
		inline graph_tc& get_graph() const { return m_graph; }
		inline viewp_tc& get_viewp() const { return m_viewp; }
		inline vsync_tc& get_vsync() const { return m_vsync; }
		// --setters
		engine_t& set_window(window_t& window);
		engine_t& set_viewp(viewp_tc& viewp);
		engine_t& set_vsync(vsync_tc& vsync);
		// --predicates
		inline v1bit has_vsync() const { return m_vsync != NW_NULL; }
		inline v1bit has_window() const { return m_context.has_window(); }
		// --operators
		engine_t& operator=(engine_tc& copy) = delete;
		engine_t& operator=(engine_t&& copy) = delete;
		// --core_methods
		v1bit init();
		inline v1bit init(window_t& window) { set_window(window); return init(); }
		v1bit quit();
		v1nil update();
	private:
		context_t m_context;
		cmd_buf_t m_cmd_buf;
		graph_t m_graph;
		viewp_t m_viewp;
		vsync_t m_vsync;
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_ENGINE_H
