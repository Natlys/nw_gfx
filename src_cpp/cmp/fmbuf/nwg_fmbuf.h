#ifndef NWG_FRAMEBUFFER_H
#define NWG_FRAMEBUFFER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_cmp.h>
#include <cmp/txr/nwg_txr.h>
namespace NW
{
	/// framebuffer class
	class NW_API fmbuf : public t_cmp<fmbuf>, public a_gfx_cmp, public a_data_cmp
	{
		using depth = mem_ref<a_txr>;
		using stencil = mem_ref<a_txr>;
		using target = mem_ref<a_txr>;
		using targets = darray<target>;
#if (NW_GAPI & NW_GAPI_OGL)
		using handle = GLuint;
#endif
#if (NW_GAPI & NW_GAPI_DX)
		using handle = ID3D11RenderTargetView*;
#endif
	public:
		fmbuf(gfx_engine& graphics);
		virtual ~fmbuf();
		// --getters
		inline handle get_handle()			{ return m_handle; }
		inline si32 get_size_x() const		{ return m_size.x; }
		inline si32 get_size_y() const		{ return m_size.y; }
		inline depth& get_depth()			{ return m_depth; }
		inline stencil& get_stencil()		{ return m_stencil; }
		inline target& get_target(ui8 idx)	{ return m_targets[idx % m_targets.size()]; }
		// --setters
		void add_target(target& ref);
		void rmv_target(ui8 idx);
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const override;
		virtual stm_in& operator>>(stm_in& stm) override;
		// --core_methods
		bit remake(v2ui size_xy);
		void read_pixels(ptr data_ptr, ui8 target_idx, const v4si& read_rect);
		void draw_pixels(ptr data_ptr, ui8 target_idx, const v4si& draw_rect);
		void clear();
		virtual void on_draw() override;
	protected:
		handle m_handle;
		v2ui m_size;
		depth m_depth;
		stencil m_stencil;
		targets m_targets;
	};
}
#endif	// NW_GAPI
#endif // NWG_FRAMEBUFFER_H