#include <nwg_pch.hpp>
#include "nwg_image.h"
#if (defined NW_GAPI)
#define STB_IMAGE_IMPLEMENTATION
#include <lib/nwg_load_img.h>
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
		set_data(cpy, offset_x, offset_y, width, height);
	}
	// --setters
	void a_image::set_data(const ubyte* data_ptr) {
		if (data_ptr == nullptr || m_size_x == 0 || m_size_y == 0 || m_channels == 0) { m_pxl_data.clear(); return; }
		else {
			m_pxl_data.resize(get_data_size());
			memcpy(&m_pxl_data[0], &data_ptr[0], get_data_size());
		}
	}
	void a_image::set_data(const a_image& source) {
		m_size_x = source.get_size_x();
		m_size_y = source.get_size_y();
		m_pxl_fmt = source.get_pxl_fmt();
		m_channels = source.get_channels();
		set_data(source.get_data());
	}
	void a_image::set_data(const a_image& source, si32 crd_x, si32 crd_y, si32 size_x, si32 size_y) {
		m_size_x = size_x;
		m_size_y = size_y;
		if (m_size_x == 0 || m_size_y == 0 || m_channels == 0) { m_pxl_data.clear(); return; }
		else { m_pxl_data.resize(get_data_size()); }
		si32 beg_x = crd_x, beg_y = crd_y;
		si32 end_x = beg_x, end_y = beg_y;
		si32 dir_x = +1, dir_y = +1;
		if (size_x < 0) {
			beg_x += m_size_x - 1;
			end_x -= 1;
			dir_x = -1;
		}
		else {
			beg_x += +0;
			end_x += m_size_x;
			dir_x = +1;
		}
		if (size_y < 0) {
			beg_y += m_size_y - 1;
			end_y -= 1;
			dir_y = -1;
		}
		else {
			beg_y += 0;
			end_y += m_size_y;
			dir_y = +1;
		}
		beg_x *= m_channels; beg_y *= m_channels;
		end_x *= m_channels; end_y *= m_channels;
		dir_x *= m_channels; dir_y *= m_channels;
		for (si32 iy = beg_y; iy != end_y; iy += dir_y) {
			for (si32 ix = beg_x; ix != end_x; ix += dir_x) {
				memcpy(&m_pxl_data[NW_XY_TO_X(iy, ix, m_size_x)], &source.get_data()[NW_XY_TO_X(iy, ix, m_size_x)], m_channels);
			}
		}
	}
	// --operators
	// --core_methods
	a_image::data a_image::make_region(si32 crd_x, si32 crd_y, si32 size_x, si32 size_y) const {
		data region;
		if (size_x == 0 || size_y == 0) { throw error("empty metrics"); return region; }
		region.resize(std::abs(size_x) * std::abs(size_y) * m_channels);
		si32 beg_x = crd_x, beg_y = crd_y;
		si32 end_x = beg_x, end_y = beg_y;
		si32 dir_x = +1, dir_y = +1;
		if (size_x < 0) {
			beg_x += size_x - 1;
			end_x -= 1;
			dir_x = -1;
		}
		else {
			beg_x += +0;
			end_x += size_x;
			dir_x = +1;
		}
		if (size_y < 0) {
			beg_y += size_y - 1;
			end_y -= 1;
			dir_y = -1;
		}
		else {
			beg_y += 0;
			end_y += size_y;
			dir_y = +1;
		}
		beg_x *= m_channels; beg_y *= m_channels;
		end_x *= m_channels; end_y *= m_channels;
		dir_x *= m_channels; dir_y *= m_channels;
		for (si32 iy = beg_y; iy != end_y; iy += dir_y) {
			for (si32 ix = beg_x; ix != end_x; ix += dir_x) {
				memcpy(&region[NW_XY_TO_X(ix - beg_x, iy - beg_y, size_x)], &m_pxl_data[NW_XY_TO_X(ix, iy, m_size_x)], m_channels);
			}
		}
		return region;
	}
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
		if (data_info.nof_pixel_bits != 8 && data_info.nof_pixel_bits != 16 &&
			data_info.nof_pixel_bits != 24 && data_info.nof_pixel_bits != 32) {
			throw error("unsupported format");
			return stm;
		}

		m_size_x = get_abs(data_info.width);
		m_size_y = get_abs(data_info.height);

		if (data_info.nof_pixel_bits <= 16) {
			m_channels = 4;
			m_pxl_fmt = pxf_get(m_channels);
			m_pxl_data.resize(data_info.image_size * m_channels);
			darray<ubyte> colors(data_info.clrs_used * m_channels, 0u);
			darray<ubyte> indices(data_info.image_size, 0u);
			stm.read(reinterpret_cast<sbyte*>(&colors[0]), colors.size());
			stm.read(reinterpret_cast<sbyte*>(&indices[0]), indices.size());
			for (si32 idx = 0; idx < indices.size(); idx++) {
				memcpy(&m_pxl_data[idx * m_channels], &colors[indices[idx] * m_channels], m_channels);
			}
		}
		else {
			m_channels = data_info.nof_pixel_bits / 8;
			m_pxl_fmt = pxf_get(m_channels);
			m_pxl_data.resize(get_data_size());
			si32 pad = ((m_size_x * m_channels) % 4) % 4;
			si32 beg_x, beg_y;
			si32 end_x, end_y;
			si32 dir_x, dir_y;
			if (data_info.width < 0) {
				beg_y = m_size_y - 1;
				end_y = -1;
				dir_y = -1;
			}
			else {
				beg_y = +0;
				end_y = +m_size_y;
				dir_y = +1;
			}
			if (data_info.height < 0) {
				beg_x = +m_size_x - 1;
				end_x = -1;
				dir_x = -1;
			}
			else {
				beg_x = +0;
				end_x = +m_size_x;
				dir_x = +1;
			}
			stm.seekg(file_info.data_offset, stm.beg);
			for (si32 iy = beg_y; iy != end_y; iy += dir_y) {
				for (si32 ix = beg_x; ix != end_x; ix += dir_x) {
					si32 get_pos = (iy * m_size_x + ix) * m_channels;
					for (ui8 ich = 0; ich < m_channels; ich++, get_pos++) {
						m_pxl_data[get_pos + ich] = stm.get();
					}
				}
				stm.seekg(pad, stm.cur);
			}
		}
		return stm;
	}

}
namespace NW
{
	image_png::image_png(cstring name) :
		a_image(name)
	{
		ubyte* pdata = stbi_load(name, &m_size_x, &m_size_y, &m_channels, 0);
		if (pdata == nullptr) { throw error("loading error"); }
		set_data(pdata);
	}
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
	image_jpg::image_jpg(cstring name) :
		a_image(name)
	{
		ubyte* pdata = stbi_load(name, &m_size_x, &m_size_y, &m_channels, 0);
		if (pdata == nullptr) { throw error("loading error"); }
		set_data(pdata);
	}
	// --operators
	out_stream& image_jpg::operator<<(out_stream& stm) const {
		return stm;
	}
	in_stream& image_jpg::operator>>(in_stream& stm) {
		return stm;
	}
}
#endif	// NW_GAPI