#include "nw_gfx_pch.hpp"
#include "nw_gfx_img.h"
#if (defined NW_GAPI)
namespace NW
{
	gfx_img::gfx_img() :
		mem_buf(),
		m_size(NW_NULL)
	{
	}
	gfx_img::gfx_img(img_tc& copy) :
		mem_buf(copy),
		m_size(copy.m_size)
	{
	}
	gfx_img::gfx_img(img_t&& copy) :
		mem_buf(copy),
		m_size(copy.m_size)
	{
	}
	// --setters
	v1nil gfx_img::set_size_x(cv1u size_x) {
		m_size[0] = size_x;
		mem_buf::set_count(get_size());
	}
	v1nil gfx_img::set_size_y(cv1u size_y) {
		m_size[1] = size_y;
		mem_buf::set_count(get_size());
	}
	v1nil gfx_img::set_size_xy(cv1u size_x, cv1u size_y) {
		m_size[0] = size_x;
		m_size[1] = size_y;
		mem_buf::set_count(get_size());
	}
	v1nil gfx_img::set_size_xy(cv2u size_xy) {
		m_size[0] = size_xy[0];
		m_size[1] = size_xy[1];
		mem_buf::set_count(get_size());
	}
	v1nil gfx_img::set_size_xyz(cv1u size_x, cv1u size_y, cv1u size_z) {
		m_size[0] = size_x;
		m_size[1] = size_y;
		m_size[2] = size_z;
		mem_buf::set_count(get_size());
	}
	v1nil gfx_img::set_size_xyz(cv3u size_xyz) {
		m_size[0] = size_xyz[0];
		m_size[1] = size_xyz[1];
		m_size[2] = size_xyz[2];
		mem_buf::set_count(get_size());
	}
	v1nil gfx_img::set_data(cv1u key, ptr_tc data, cv1u count) {
		mem_buf::set_data(key, data, count);
		NW_CHECK(has_size(), "no size!", return);
	}
	// --operators
	v1nil gfx_img::operator=(img_tc& copy) {
		mem_buf::operator=(copy);
	}
	v1nil gfx_img::operator=(img_t&& copy) {
		mem_buf::operator=(copy);
	}
	op_stream_t& gfx_img::operator<<(op_stream_t& stm) const {
		mem_buf::operator<<(stm);
		return stm;
	}
	ip_stream_t& gfx_img::operator>>(ip_stream_t& stm) {
		// mem_buf::operator>>(stm);

		img_bmp_info bmp;

		if constexpr (NW_TRUE) {
			stm >> bmp;
			NW_CHECK(bmp.data_info.nof_pixel_bits >= 8u && bmp.data_info.nof_pixel_bits <= 32u, "format error!", return stm);
			set_size_xy(NW_MATH_ABS(bmp.data_info.width), NW_MATH_ABS(bmp.data_info.height));
			v1s nof_channels = bmp.data_info.nof_pixel_bits;
			m_layt = mem_layt("pixel", type_info::get_type<v4u08>());
			NW_CHECK(mem_buf::remake(bmp.data_info.image_size / nof_channels, NW_NULL), "failed remake!", return stm);
			if (bmp.data_info.nof_pixel_bits == 8u) {
				nof_channels = 4u;
				bmp.palette.pxl_buf.resize(bmp.data_info.clrs_used * nof_channels, 0u);
				bmp.palette.idx_buf.resize(bmp.data_info.image_size, 0u);
				stm.read(reinterpret_cast<byte_t*>(bmp.palette.pxl_buf.data()), bmp.palette.pxl_buf.size());
				stm.read(reinterpret_cast<byte_t*>(bmp.palette.idx_buf.data()), bmp.palette.idx_buf.size());

				for (v1s idx = 0; idx < bmp.palette.idx_buf.size(); idx++) { get_elem(idx)[idx % 4u] = bmp.palette.pxl_buf[idx]; }
			}
			else {
				v1s pad = ((get_size_x()) % 4) % 4;
				v1s beg_x, beg_y;
				v1s end_x, end_y;
				v1s dir_x, dir_y;
				if (bmp.data_info.width < 0) { beg_x = +bmp.data_info.width - 1; end_x = -1; dir_x = -1; }
				else { beg_x = +0; end_x = +bmp.data_info.width; dir_x = +1; }
				if (bmp.data_info.height < 0) { beg_y = +bmp.data_info.height - 1; end_y = -1; dir_y = -1; }
				else { beg_y = +0; end_y = +bmp.data_info.height; dir_y = +1; }
				stm.seekg(bmp.file_info.data_offset, stm.beg);
				for (v1s iy = beg_y; iy != end_y; iy += dir_y) {
					for (v1s ix = beg_x; ix != end_x; ix += dir_x) {
						stm.read(reinterpret_cast<byte_t*>(get_elem(iy * get_size_x() + ix).get_data()), bmp.data_info.nof_pixel_bits / 4u);
					}
					stm.seekg(pad, stm.cur);
				}
			}
		}
		return stm;
	}
	// --==<core_methods>==--
	v1bit gfx_img::remake()
	{
		NW_CHECK(mem_buf::remake(), "failed remake!", return NW_FALSE);
		if (get_size() == NW_NULL) { set_size_xyz(get_count(), 1u, 1u); }
		NW_CHECK(has_size(), "no size!", return NW_FALSE);
		
		return NW_TRUE;
	}
	// --==</core_methods>==--
}
#endif	// NW_GAPI