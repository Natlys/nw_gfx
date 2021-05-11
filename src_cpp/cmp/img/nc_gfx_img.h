#ifndef NC_GFX_IMAGE_H
#define NC_GFX_IMAGE_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "mem/nc_mem_buf.h"
namespace NC
{
	/// graphics_image_type
	class NC_API gfx_img_t : public mem_buf_t
	{
	public:
		using img_t = gfx_img_t;
		using img_tc = const img_t;
	public:
		gfx_img_t();
		gfx_img_t(img_tc& copy);
		gfx_img_t(img_t&& copy);
		virtual ~gfx_img_t();
		// getters //
		inline v1u_tc get_size() const    { return v1u_t{ m_size[0] * m_size[1] * m_size[2] }; }
		inline v1u_tc get_size_x() const   { return v1u_t{ m_size[0] }; }
		inline v1u_tc get_size_y() const   { return v1u_t{ m_size[1] }; }
		inline v1u_tc get_size_z() const   { return v1u_t{ m_size[2] }; }
		inline cv2u get_size_xy() const  { return v2u{ m_size[0], m_size[1], m_size[2] }; }
		inline cv3u get_size_xyz() const { return v3u{ m_size[0], m_size[1], m_size[2] }; }
		// setters //
		gfx_img_t& set_size(v1u_tc size_x);
		gfx_img_t& set_size(v1u_tc size_x, v1u_tc size_y);
		gfx_img_t& set_size(cv2u size);
		gfx_img_t& set_size(v1u_tc size_x, v1u_tc size_y, v1u_tc size_z);
		gfx_img_t& set_size(cv3u size);
		inline gfx_img_t& set_data(v1u_tc key, ptr_tc data) { mem_buf_t::set_data(key * get_stride(), data); return *this; }
		inline gfx_img_t& set_data(ptr_tc data, v1u_tc size) { mem_buf_t::set_data(data, size * get_stride()); return *this; }
		inline gfx_img_t& set_data(ptr_tc data) { mem_buf_t::set_data(data); return *this; }
		inline gfx_img_t& set_data() { mem_buf_t::set_data(); return *this; }
		virtual buf_t& set_data(size_t key, ptr_tc data, size_t space) override;
		// predicates //
		inline v1bit_t has_size() const { return get_size() > 0u; }
		inline v1bit_t has_size(v1u_tc size) const { return get_size() >= size; }
		inline v1bit_t has_size_x(v1u_tc size_x) const { return get_size_x() >= size_x; }
		inline v1bit_t has_size_y(v1u_tc size_y) const { return get_size_y() >= size_y; }
		inline v1bit_t has_size_z(v1u_tc size_z) const { return get_size_z() >= size_z; }
		inline v1bit_t has_size_xy(v1u_tc size_x, v1u_tc size_y) const { return has_size_x(size_x) && has_size_y(size_y); }
		inline v1bit_t has_size_xy(cv2u size_xy) const { return has_size_xy(size_xy[0], size_xy[1]); }
		inline v1bit_t has_size_xyz(v1u_tc size_x, v1u_tc size_y, v1u_tc size_z) const { return has_size_x(size_x) && has_size_y(size_y) && has_size_z(size_z); }
		inline v1bit_t has_size_xyz(cv3u size_xyz) const { return has_size_xyz(size_xyz[0], size_xyz[1], size_xyz[2]); }
		// operators //
		inline img_t& operator=(img_tc& copy) { NC_CHECK(remake(copy.get_layt(), copy.get_size_xyz(), copy.get_data()), "remake error!", return *this); return *this; }
		inline img_t& operator=(img_t&& copy) { NC_CHECK(remake(copy.get_layt(), copy.get_size_xyz(), copy.get_data()), "remake error!", return *this); return *this; }
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// commands //
		inline v1bit_t remake(cv2u size) { set_size(size[0], size[1], 1u); return remake(); }
		inline v1bit_t remake(cv3u size) { set_size(size[0], size[1], size[2]); return remake(); }
		inline v1bit_t remake(layt_tc& layout, cv2u size) { set_layt(layout); set_size(size); return remake(); }
		inline v1bit_t remake(layt_tc& layout, cv3u size) { set_layt(layout); set_size(size); return remake(); }
		inline v1bit_t remake(layt_tc& layout, cv2u size, ptr_tc data) { set_layt(layout); set_size(size); set_data(data); return remake(); }
		inline v1bit_t remake(layt_tc& layout, cv3u size, ptr_tc data) { set_layt(layout); set_size(size); set_data(data); return remake(); }
		virtual v1bit_t remake() override;
	protected:
		v3u m_size;
	};
}
#endif	// NC_GAPI
#endif	// NC_GFX_IMAGE_H