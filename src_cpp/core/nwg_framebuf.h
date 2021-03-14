#ifndef NW_FRAME_BUFFER_H
#define NW_FRAME_BUFFER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_rsc.h>
#include <core/nwg_texture.h>
namespace NW
{
	/// framebuffer class
	class NW_API framebuf : public t_gfx_rsc<framebuf>, public a_data_rsc
	{
		using depth = mem_ref<a_texture>;
		using stencil = mem_ref<a_texture>;
		using draw_target = mem_ref<a_texture>;
		using draw_targets = darray<draw_target>;
	public:
		framebuf(gfx_engine& graphics, cstring name);
		virtual ~framebuf();
		// --getters
		inline si32 get_size_x() const			{ return m_viewport[2] - m_viewport[0]; }
		inline si32 get_size_y() const			{ return m_viewport[3] - m_viewport[1]; }
		inline v4si get_viewport() const		{ return m_viewport; }
		inline v4f get_clear_color() const		{ return m_clear_color; }
		inline depth& get_depth_buf()					{ return m_depth; }
		inline depth& get_stencil_buf()					{ return m_stencil; }
		inline draw_target& get_draw_buf(ui8 idx = 0)	{ return m_targets[idx % m_targets.size()]; }
#if (NW_GAPI & NW_GAPI_OGL)
		inline GLuint get_ogl_id() const			{ return m_ogl_id; }
#endif
#if (NW_GAPI & NW_GAPI_DX)
		inline ID3D11RenderTargetView* get_view()	{ return m_view; }
#endif
		// --setters
		void set_viewport(const v4si& viewport_rect);
		void set_clear_color(const v4f& clear_color);
		void add_draw_target(draw_target& ref);
		void rmv_draw_target(ui8 idx);
		// --operators
		virtual out_stream& operator<<(out_stream& stm) const override;
		virtual in_stream& operator>>(in_stream& stm) override;
		// --core_methods
		bit remake();
		void clear();
		void read_pixels(ptr data_ptr, ui8 attach_idx, const v4si& read_rect);
		void draw_pixels(ptr data_ptr, ui8 attach_idx, const v4si& draw_rect);
		virtual void on_draw() override;
	protected:
		v4f m_clear_color;
		v4si m_viewport;
		bit is_swap_chain_target;
		depth m_depth;
		stencil m_stencil;
		draw_targets m_targets;
		darray<ui32> color_ids;
#if (NW_GAPI & NW_GAPI_OGL)
		GLuint m_ogl_id;
#endif
#if (NW_GAPI & NW_GAPI_DX)
		ID3D11RenderTargetView m_view;
#endif
	};
}
#endif	// NW_GAPI
#endif // NW_FRAME_BUFFER_H