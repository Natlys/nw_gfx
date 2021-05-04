#ifndef NW_GFX_FRAMEBUFFER_H
#define NW_GFX_FRAMEBUFFER_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "../nw_gfx_cmp.h"
#	include "nw_gfx_fmbuf_part.h"
namespace NW
{
	/// graphics_framebuffer class
	class NW_API gfx_fmbuf : public t_cmp<gfx_fmbuf>, public a_gfx_cmp, public a_iop_cmp
	{
		using layt_t = mem_layt;
		using layt_tc = const layt_t;
		using part_t = mem_ref<a_gfx_fmbuf_part>;
		using part_tc = const part_t;
		using parts_t = darray_t<part_t>;
		using parts_tc = const parts_t;
#	if (NW_GAPI & NW_GAPI_OGL)
		using handle_t = GLuint;
#	endif
#	if (NW_GAPI & NW_GAPI_D3D)
		using handle_t = ID3D11RenderTargetView*;
#	endif
		using handle_tc = const handle_t;
	public:
		gfx_fmbuf();
		virtual ~gfx_fmbuf();
		// --getters
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		inline layt_t& get_layt()        { return m_layt; }
		inline layt_tc& get_layt() const { return m_layt; }
		inline cv1u get_size() const    { return m_size[0] * m_size[1]; }
		inline cv1u get_size_x() const  { return m_size[0]; }
		inline cv1u get_size_y() const  { return m_size[1]; }
		inline cv2u get_size_xy() const { return m_size; }
		inline part_t& get_part(cv1u key = NW_NULL)        { NW_CHECK(has_part(key), "not found!", return m_parts[0]); return m_parts[key]; }
		inline part_tc& get_part(cv1u key = NW_NULL) const { NW_CHECK(has_part(key), "not found!", return m_parts[0]); return m_parts[key]; }
		// --setters
		v1nil set_layt(layt_tc& layout);
		v1nil set_size_x(cv1u size_x);
		v1nil set_size_y(cv1u size_y);
		v1nil set_size_xy(cv1u size_x, cv1u size_y);
		v1nil set_size_xy(cv2u size_xy);
		v1nil add_part(part_t& ref);
		v1nil rmv_part(cv1u key);
		// --predicates
		inline v1bit has_size(cv1u size = 1u) const { return get_size() >= size; }
		inline v1bit has_size_x(cv1u size_x = 1u) const { return get_size_x() >= size_x; }
		inline v1bit has_size_y(cv1u size_y = 1u) const { return get_size_y() >= size_y; }
		inline v1bit has_size_xy(cv1u size_x = 1u, cv1u size_y = 1u) const { return has_size_x(size_x) && has_size_y(size_y); }
		inline v1bit has_part(cv1u key = NW_NULL) const { return m_parts.size() > key; }
		// --operators
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// --core_methods
		v1bit remake();
		inline v1bit remake(layt_tc& layt, cv2u size_xy) { set_layt(layt); set_size_xy(size_xy); return remake(); }
		v1nil clear();
		virtual v1nil on_draw() override;
	protected:
		handle_t m_handle;
		parts_t m_parts;
		layt_t m_layt;
		v2u m_size;
	};
}
#endif	// NW_GAPI
#endif // NW_GFX_FRAMEBUFFER_H
