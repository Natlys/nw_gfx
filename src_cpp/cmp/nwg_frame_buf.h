#ifndef NWG_FRAME_BUFFER_H
#define NWG_FRAME_BUFFER_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <core/nwg_cmp.h>
#include <cmp/nwg_texture.h>
namespace NWG
{
	struct NWG_API frame_buf_info : public a_info
	{
	public:
		v4si32 viewport = { 0, 0, 1, 1 };
		v4f32 clear_color = { 0.0f, 0.0f, 0.0f, 1.0f };
		bit is_swap_chain_target = false;
		bit has_depth = false;
		bit has_stencil = false;
		darray<ui32> color_ids;
	public:
		// --operators
		virtual out_stream& operator<<(out_stream& stm) const override;
		virtual in_stream& operator>>(in_stream& stm) override;
	};
}
namespace NWG
{
	/// frame_buffer class
	class NWG_API frame_buf : public t_gfx_cmp<frame_buf>, public a_data_res
	{
		using attachments = darray<mem_ref<a_texture>>;
	public:
		frame_buf(gfx_engine& graphics, cstring name);
		virtual ~frame_buf();
		// --getters
		inline si32 get_size_x() const			{ return m_info.viewport[2] - m_info.viewport[0]; }
		inline si32 get_size_y() const			{ return m_info.viewport[3] - m_info.viewport[1]; }
		inline v4si32 get_viewport() const		{ return m_info.viewport; }
		inline v4f32 get_clear_color() const	{ return m_info.clear_color; }
		inline const frame_buf_info& get_info() const { return m_info; }
		inline mem_ref<a_texture>& get_attachment(ui8 idx = 0) { return m_atchs[idx]; }
#if (NWG_GAPI & NWG_GAPI_OGL)
		inline GLuint get_ogl_id() const { return m_ogl_id; }
#endif
		// --setters
		void set_viewport(const v4si32& viewport_rect);
		void set_clear_color(const v4f32& clear_color);
		void attach(mem_ref<a_texture>& ref);
		void detach(ui8 idx);
		// --core_methods
		virtual void on_draw() override;
		void remake(const frame_buf_info& info);
		void clear();
		void read_pixels(ptr data_ptr, ui8 attach_idx, const v4si32& read_rect);
		void draw_pixels(ptr data_ptr, ui8 attach_idx, const v4si32& draw_rect);
		// --data_methods
		virtual bool save_file(cstring file_path) override;
		virtual bool load_file(cstring file_path) override;
	protected:
		frame_buf_info m_info;
		attachments m_atchs;
#if (NWG_GAPI & NWG_GAPI_OGL)
		GLuint m_ogl_id;
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
#endif
	};
}
#endif	// NWG_GAPI
#endif // NWG_FRAME_BUFFER_H