#ifndef NC_GFX_FRAMEBUFFER_H
#define NC_GFX_FRAMEBUFFER_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "../nc_gfx_cmp.h"
#	include "nc_gfx_fmbuf_part.h"
namespace NC
{
	/// graphics_framebuffer class
	class NC_API gfx_fmbuf_t : public nc_cmp_tt<gfx_fmbuf_t>, public gfx_cmp_t, public nc_iop_cmp_t
	{
		using layt_t = mem_layt_t;
		using layt_tc = const layt_t;
		using part_t = mem_ref_t<gfx_fmbuf_part_t>;
		using part_tc = const part_t;
		using parts_t = array_t<part_t>;
		using parts_tc = const parts_t;
#	if (NC_GAPI & NC_GAPI_OGL)
		using handle_t = GLuint;
#	endif
#	if (NC_GAPI & NC_GAPI_D3D)
		using handle_t = ID3D11RenderTargetView*;
#	endif
		using handle_tc = const handle_t;
	public:
		gfx_fmbuf_t();
		virtual ~gfx_fmbuf_t();
		// getters //
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		inline layt_t& get_layt()        { return m_layt; }
		inline layt_tc& get_layt() const { return m_layt; }
		inline v1u_tc get_size() const    { return m_size[0] * m_size[1]; }
		inline v1u_tc get_size_x() const  { return m_size[0]; }
		inline v1u_tc get_size_y() const  { return m_size[1]; }
		inline cv2u get_size_xy() const { return m_size; }
		inline part_t& get_part(v1u_tc key = NC_NULL)        { NC_CHECK(has_part(key), "not found!", return m_parts[0]); return m_parts[key]; }
		inline part_tc& get_part(v1u_tc key = NC_NULL) const { NC_CHECK(has_part(key), "not found!", return m_parts[0]); return m_parts[key]; }
		// setters //
		v1nil_t set_layt(layt_tc& layout);
		v1nil_t set_size_x(v1u_tc size_x);
		v1nil_t set_size_y(v1u_tc size_y);
		v1nil_t set_size_xy(v1u_tc size_x, v1u_tc size_y);
		v1nil_t set_size_xy(cv2u size_xy);
		v1nil_t add_part(part_t& ref);
		v1nil_t rmv_part(v1u_tc key);
		// predicates //
		inline v1bit_t has_size(v1u_tc size = 1u) const { return get_size() >= size; }
		inline v1bit_t has_size_x(v1u_tc size_x = 1u) const { return get_size_x() >= size_x; }
		inline v1bit_t has_size_y(v1u_tc size_y = 1u) const { return get_size_y() >= size_y; }
		inline v1bit_t has_size_xy(v1u_tc size_x = 1u, v1u_tc size_y = 1u) const { return has_size_x(size_x) && has_size_y(size_y); }
		inline v1bit_t has_part(v1u_tc key = NC_NULL) const { return m_parts.size() > key; }
		// operators //
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// commands //
		v1bit_t remake();
		inline v1bit_t remake(layt_tc& layt, cv2u size_xy) { set_layt(layt); set_size_xy(size_xy); return remake(); }
		v1nil_t clear();
		virtual v1nil_t on_draw() override;
	protected:
		handle_t m_handle;
		parts_t m_parts;
		layt_t m_layt;
		v2u m_size;
	};
}
#endif	// NC_GAPI
#endif // NC_GFX_FRAMEBUFFER_H
