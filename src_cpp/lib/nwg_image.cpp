#include <nwg_pch.hpp>
#include "nwg_image.h"
#if (defined NW_GAPI)
namespace NW
{
	a_image::a_image(cstring name) :
		a_data_rsc(name),
		m_size_x(1), m_size_y(1),
		m_channels(4),
		m_pxl_fmt(PXF_R8G8B8A8_UINT32), m_data_type(DT_UINT8),
		m_pxl_data{ data{ 255u, 255u, 255u, 255u } }
	{
	}
	a_image::a_image(const a_image& cpy) :
		a_data_rsc(cpy),
		m_size_x(cpy.m_size_x), m_size_y(cpy.m_size_y),
		m_channels(cpy.m_channels),
		m_pxl_fmt(cpy.m_pxl_fmt),
		m_pxl_data(cpy.m_pxl_data)
	{
	}
	a_image::a_image(const a_image& cpy, si32 offset_x, si32 offset_y, si32 width, si32 height) :
		a_data_rsc(cpy),
		m_size_x(width), m_size_y(height),
		m_pxl_fmt(cpy.m_pxl_fmt)
	{
		set_data(&cpy.m_pxl_data[0], offset_x, offset_y, width, height);
	}
	// --setters
	void a_image::set_data(const ubyte* data_ptr) {
		if (data_ptr == nullptr || m_size_x == 0 || m_size_y == 0 || m_channels == 0) { m_pxl_data.clear(); return; }
		else {
			m_pxl_data.resize(get_data_size());
			memcpy(&m_pxl_data[0], &data_ptr[0], get_data_size());
		}
	}
	void a_image::set_data(const ubyte* data_ptr, si32 offset_x, si32 offset_y, si32 width, si32 height) {
		m_size_x = width;
		m_size_y = height;
		if (data_ptr == nullptr || m_size_x == 0 || m_size_y == 0 || m_channels == 0) { m_pxl_data.clear(); return; }
		else { m_pxl_data.resize(get_data_size()); }
		si32 beg_x = abs(offset_x), beg_y = abs(offset_y);
		si32 end_x = beg_x, end_y = beg_y;
		si32 dir_x = +1, dir_y = +1;
		if (width < 0) {
			beg_x += +m_size_x - 1;
			end_x = -1;
			dir_x = -1;
		}
		else {
			beg_x += 0;
			end_x = +m_size_x;
			dir_x = +1;
		}
		if (height < 0) {
			beg_y += +m_size_y - 1;
			end_y = -1;
			dir_y = -1;
		}
		else {
			beg_y += +0;
			end_y = +m_size_y;
			dir_y = +1;
		}
		size get_pos = 0;
		for (si32 iy = beg_y; iy != end_y; iy += dir_y) {
			get_pos += iy * m_channels * m_size_x;
			for (si32 ix = beg_x; ix != end_x; ix += dir_x) {
				get_pos += ix * m_channels;
				memcpy(&m_pxl_data[get_pos], &data_ptr[get_pos], m_channels);
			}
		}
	}
	// --operators
}
namespace NW
{
	image_bmp::image_bmp(cstring name) :
		a_image(name)
	{
	}
	// --operators
	out_stream& image_bmp::operator<<(out_stream& stm) const {
		return stm;
	}
	in_stream& image_bmp::operator>>(in_stream& stm) {
		stm.read(reinterpret_cast<sbyte*>(&file_info), sizeof(file_info));
		stm.read(reinterpret_cast<sbyte*>(&data_info), sizeof(data_info));
		if (data_info.nof_pixel_bits != 8 && data_info.nof_pixel_bits != 24 && data_info.nof_pixel_bits != 32) { throw error("unsupported format"); }
		stm.seekg(file_info.data_offset, stm.beg);

		m_size_x = std::abs(data_info.width);
		m_size_y = std::abs(data_info.height);
		m_channels = data_info.nof_pixel_bits / 8;
		m_pxl_fmt = pxf_get(m_channels);
		m_pxl_data.resize(get_data_size());

		darray<ubyte> pxl_buf;
		pxl_buf.resize(data_info.image_size);
		stm.read(reinterpret_cast<sbyte*>(&pxl_buf[0]), pxl_buf.size());
		if (m_channels == 1) {	// indexed bitmap;
			m_channels = 4;
			m_pxl_fmt = pxf_get(m_channels);
			// pxl_buf contains indices; we need to load our colors there;
			darray<ubyte> indices(std::move(pxl_buf));
			darray<ubyte> colors(data_info.clrs_used * m_channels, 0u);
			pxl_buf.resize(get_data_size());
			// our rgba palette is allocated after file header, dbi header and optional color masks
			stm.seekg(-static_cast<si32>(stm.gcount() + colors.size()), stm.cur);
			stm.read(reinterpret_cast<sbyte*>(&colors[0]), colors.size());
			// write all colors from palette into the buffer via indices
			for (si32 n = 0; n < indices.size(); n += 1) {
				memcpy(&pxl_buf[n * m_channels], &colors[indices[n]], m_channels);
			}
			set_data(&pxl_buf[0]);
		}
		else {	// simple rgb/rgba
			si32 pad = ((m_size_x * m_channels) % 4) % 4;
			si32 beg_x, beg_y;
			si32 end_x, end_y;
			si32 dir_x, dir_y;
			// sometimes bmp format uses negative size_y
			if (data_info.width < 0) {
				beg_y = m_size_y - 1;
				end_y = -1;
				dir_y = -1;
			}
			else {
				beg_y = 0;
				end_y = +m_size_y;
				dir_y = +1;
			}
			// maybe bmp format uses negative size_x
			if (data_info.height < 0) {
				beg_x = +m_size_x- 1;
				end_x = -1;
				dir_x = -1;
			}
			else {
				beg_x = 0;
				end_x = +m_size_x;
				dir_x = +1;
			}
			si32 get_pos = 0;
			for (si32 iy = beg_y; iy != end_y; iy += dir_y) {
				si32 offset_y = iy * m_size_x;
				for (si32 ix = beg_x; ix != end_x; ix += dir_x) {
					memcpy(&m_pxl_data[offset_y + ix], &pxl_buf[get_pos], m_channels);
				}
				get_pos += pad;
			}
		}
		return stm;
	}

}
namespace NW
{
	// --operators
	out_stream& image_png::operator<<(out_stream& stm) const {
		return stm;
	}
	in_stream& image_png::operator>>(in_stream& stm) {
		return stm;
	}
}
namespace NW
{
	// --operators
	out_stream& image_jpg::operator<<(out_stream& stm) const {
		return stm;
	}
	in_stream& image_jpg::operator>>(in_stream& stm) {
		return stm;
	}
}
#endif	// NW_GAPI