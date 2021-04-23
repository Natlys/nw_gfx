#ifndef NW_GFX_ENGINE_H
#define NW_GFX_ENGINE_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_context.h"
#	include "nw_gfx_cmd.h"
namespace NW
{
	/// graphics_engine class
	class NW_API gfx_engine : public t_singleton<gfx_engine>
	{
	public:
		using engine_t = gfx_engine;
		using engine_tc = const engine_t;
		using context_t = gfx_context;
		using context_tc = const context_t;
		using window_t = context_t::window_t;
		using window_tc = context_t::window_tc;
		using cmd_buf_t = gfx_cmd_buf;
		using cmd_buf_tc = const cmd_buf_t;
		using cmd_t = cmd_buf_t::cmd_t;
		using cmd_tc = cmd_buf_t::cmd_tc;
	public:
		gfx_engine();
		virtual ~gfx_engine();
		// --getters
		inline context_t& get_context()        { return m_context; }
		inline context_tc& get_context() const { return m_context; }
		inline window_t& get_window()          { return m_context.get_window(); }
		inline window_tc& get_window() const   { return m_context.get_window(); }
		inline cmd_buf_t& get_cmd_buf()        { return m_cmd_buf; }
		inline cmd_buf_tc& get_cmd_buf() const { return m_cmd_buf; }
		inline cv4f& get_viewp() const { return m_viewp; }
		inline cv1u& get_vsync() const { return m_vsync; }
		// --setters
		v1nil set_window(window_t& window);
		v1nil set_fmbuf_size(v1u size_x, v1u size_y);
		v1nil set_viewp(v1f crd_x, v1f crd_y, v1f size_x, v1f size_y);
		inline v1nil set_viewp(v4f viewp) { set_viewp(viewp[0], viewp[1], viewp[2], viewp[3]); }
		v1nil set_vsync(v1u vsync);
		// --predicates
		inline v1bit has_vsync() const { return m_vsync != NW_NULL; }
		inline v1bit has_window() const { return m_context.has_window(); }
		// --operators
		// --core_methods
		v1bit init();
		inline v1bit init(window_t& window) { set_window(window); return init(); }
		v1bit quit();
		v1nil update();
	private:
		context_t m_context;
		cmd_buf_t m_cmd_buf;
		v4f m_viewp;
		v1u m_vsync;
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_ENGINE_H
