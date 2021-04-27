#ifndef NW_GFX_IMAGE_H
#define NW_GFX_IMAGE_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "mem/nw_mem_buf.h"
namespace NW
{
	/// graphics_image class
	class NW_API gfx_img : public mem_buf
	{
	public:
		using img_t = gfx_img;
		using img_tc = const img_t;
	public:
		gfx_img();
		gfx_img(img_tc& copy);
		gfx_img(img_t&& copy);
		~gfx_img();
		// --getters
		inline cv1u get_size() const     { return v1u{ m_size[0] * m_size[1] * m_size[2] }; }
		inline cv1u get_size_x() const   { return v1u{ m_size[0] }; }
		inline cv1u get_size_y() const   { return v1u{ m_size[1] }; }
		inline cv1u get_size_z() const   { return v1u{ m_size[2] }; }
		inline cv2u get_size_xy() const  { return v2u{ m_size[0], m_size[1], m_size[2] }; }
		inline cv3u get_size_xyz() const { return v3u{ m_size[0], m_size[1], m_size[2] }; }
		// --setters
		v1nil set_size_x(cv1u size_x);
		v1nil set_size_y(cv1u size_y);
		v1nil set_size_xy(cv1u size_x, cv1u size_y);
		v1nil set_size_xy(cv2u size_xy);
		v1nil set_size_xyz(cv1u size_x, cv1u size_y, cv1u size_z);
		v1nil set_size_xyz(cv3u size_xyz);
		virtual buf_t& set_data(cv1u key, ptr_tc data, cv1u count) override;
		// --predicates
		inline v1bit has_size(cv1u size = 1u) const { return get_size() >= size; }
		inline v1bit has_size_x(cv1u size_x = 1u) const { return get_size_x() >= size_x; }
		inline v1bit has_size_y(cv1u size_y = 1u) const { return get_size_y() >= size_y; }
		inline v1bit has_size_z(cv1u size_z = 1u) const { return get_size_z() >= size_z; }
		inline v1bit has_size_xy(cv1u size_x = 1u, cv1u size_y = 1u) const { return has_size_x(size_x) && has_size_y(size_y); }
		inline v1bit has_size_xyz(cv1u size_x = 1u, cv1u size_y = 1u, cv1u size_z = 1u) const {
			return has_size_x(size_x) && has_size_y(size_y) && has_size_z(size_z);
		}
		// --operators
		inline img_t& operator=(img_tc& copy) { mem_buf::operator=(copy); return *this; }
		inline img_t& operator=(img_t&& copy) { mem_buf::operator=(copy); return *this; }
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// --core_methods
		virtual v1bit remake() override;
		inline v1bit remake(cv2u size_xy) { set_size_xyz(size_xy[0], size_xy[1], 1u); return remake(); }
		inline v1bit remake(cv3u size_xyz) { set_size_xyz(size_xyz[0], size_xyz[1], size_xyz[2]); return remake(); }
		inline v1bit remake(layt_tc& layout, cv2u size_xy) { set_layt(layout); return remake(size_xy); }
		inline v1bit remake(layt_tc& layout, cv3u size_xyz) { set_layt(layout); return remake(size_xyz); }
		inline v1bit remake(layt_tc& layout, cv2u size_xy, ptr_tc data) {
			set_size_xy(size_xy);
			mem_buf::set_layt(layout).set_data(data);
			return remake();
		}
		inline v1bit remake(layt_tc& layout, cv3u size_xyz, ptr_tc data) {
			set_size_xyz(size_xyz);
			mem_buf::set_layt(layout).set_data(data);
			return remake();
		}
	protected:
		v3u m_size;
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_IMAGE_H