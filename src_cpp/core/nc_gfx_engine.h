#ifndef NC_GFX_ENGINE_H
#define NC_GFX_ENGINE_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "std/nc_std_engine.h"
#	include "nc_gfx_context.h"
#	include "nc_gfx_cmd.h"
#	include "nc_gfx_pass.h"
#	include "nc_gfx_graph.h"
namespace NC
{
	/// graphics_engine class
	class NC_API nc_gfx_eng : public std_engine_t<nc_gfx_eng>
	{
	public:
		using context_t = gfx_context_t;
		using context_tc = const context_t;
		using window_t = context_t::window_t;
		using window_tc = context_t::window_tc;
		using cmd_t = gfx_cmd_t;
		using cmd_tc = const cmd_t;
		using cmd_buf_t = gfx_cmd_buf_t;
		using cmd_buf_tc = const cmd_buf_t;
		using graph_t = gfx_graph_t;
		using graph_tc = const graph_t;
		using viewp_t = v4f_t;
		using viewp_tc = const viewp_t;
		using vsync_t = v1u_t;
		using vsync_tc = const vsync_t;
	public:
		// ctor_dtor //
		nc_gfx_eng();
		~nc_gfx_eng();
		// getters //
		inline context_t& get_context()        { return m_context; }
		inline context_tc& get_context() const { return m_context; }
		inline window_t& get_window()          { return m_context.get_window(); }
		inline window_tc& get_window() const   { return m_context.get_window(); }
		inline viewp_tc& get_viewp() const { return m_viewp; }
		inline vsync_tc& get_vsync() const { return m_vsync; }
		// setters //
		engine_t& set_window(window_t& window);
		engine_t& set_viewp(viewp_tc& viewp);
		engine_t& set_vsync(vsync_tc& vsync);
		// predicates //
		inline v1bit_t has_vsync() const { return m_vsync != NC_NULL; }
		inline v1bit_t has_window() const { return m_context.has_window(); }
		// operators //
		// commands //
		virtual v1bit_t init() override;
		virtual v1bit_t quit() override;
		virtual v1bit_t work() override;
	private:
		context_t m_context;
		viewp_t m_viewp;
		vsync_t m_vsync;
	};
}
#endif	// NC_GAPI
#endif	// NC_GFX_ENGINE_H
