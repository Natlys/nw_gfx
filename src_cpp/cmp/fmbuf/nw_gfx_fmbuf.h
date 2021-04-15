#ifndef NW_GFX_FRAMEBUFFER_H
#define NW_GFX_FRAMEBUFFER_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#include "cmp/nw_gfx_cmp.h"
#include "../txr/nw_gfx_txr.h"
namespace NW
{
	/// framebuffer class
	class NW_API fmbuf : public t_cmp<fmbuf>, public a_gfx_cmp, public a_io_cmp
	{
		using depth_t = mem_ref<a_gfx_txr>;
		using depth_tc = const depth_t;
		using stenc_t = mem_ref<a_gfx_txr>;
		using stenc_tc = const stenc_t;
		using target_t = mem_ref<a_gfx_txr>;
		using target_tc = const target_t;
		using targets_t = darray<target_t>;
#if (NW_GAPI & NW_GAPI_OGL)
		using handle_t = GLuint;
#endif
#if (NW_GAPI & NW_GAPI_D3D)
		using handle_t = ID3D11RenderTargetView*;
#endif
		using handle_tc = const handle_t;
	public:
		fmbuf(gfx_engine& graphics);
		virtual ~fmbuf();
		// --getters
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		inline v1s get_size_x() const { return m_size[0]; }
		inline v1s get_size_y() const { return m_size[1]; }
		inline depth_t& get_depth()          { return m_depth; }
		inline stenc_t& get_stenc()          { return m_stenc; }
		inline target_t& get_target(v1u key) { return m_targets[key % m_targets.size()]; }
		// --setters
		v1nil add_target(target_t& ref);
		v1nil rmv_target(v1u idx);
		// --predicates
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const override;
		virtual stm_in& operator>>(stm_in& stm) override;
		// --core_methods
		v1bit remake(v2u size_xy);
		v1nil read_pixels(ptr_t buffer, v1u key, cv4s& rect);
		v1nil draw_pixels(ptr_tc buffer, v1u key, cv4s& rect);
		v1nil clear();
		virtual v1nil on_draw() override;
	protected:
		handle_t m_handle;
		v2u m_size;
		depth_t m_depth;
		stenc_t m_stenc;
		targets_t m_targets;
	};
}
#endif	// NW_GAPI
#endif // NW_GFX_FRAMEBUFFER_H
