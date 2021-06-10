#include "nc_gfx_pch.hpp"
#include "nc_gfx_img.hxx"
#if (defined NC_GAPI)
#	include "nc_gfx_img_info.hxx"
namespace NC
{
	gfx_img_t::gfx_img_t() : mem_buf_t(), m_size(1) { }
	gfx_img_t::gfx_img_t(img_tc& copy) : gfx_img_t() { operator=(copy); }
	gfx_img_t::gfx_img_t(img_t&& copy) : gfx_img_t() { operator=(copy); }
	gfx_img_t::~gfx_img_t() {}
	/* setters */
	gfx_img_t::img_t& gfx_img_t::set_size(v1u_tc size) { m_size[0] = size; mem_buf_t::set_count(get_size()); return *this; }
	gfx_img_t::img_t& gfx_img_t::set_size(v1u_tc size_x, v1u_tc size_y) { m_size[0] = size_x; m_size[1] = size_y; mem_buf_t::set_count(get_size()); return *this; }
	gfx_img_t::img_t& gfx_img_t::set_size(cv2u size_xy) { m_size[0] = size_xy[0]; m_size[1] = size_xy[1]; mem_buf_t::set_count(get_size()); return *this; }
	gfx_img_t::img_t& gfx_img_t::set_size(v1u_tc size_x, v1u_tc size_y, v1u_tc size_z) { m_size[0] = size_x; m_size[1] = size_y; m_size[2] = size_z; mem_buf_t::set_count(get_size()); return *this; }
	gfx_img_t::img_t& gfx_img_t::set_size(cv3u size) { m_size[0] = size[0]; m_size[1] = size[1]; m_size[2] = size[2]; mem_buf_t::set_count(get_size()); return *this; }
	gfx_img_t::buf_t& gfx_img_t::set_data(size_t key, ptr_tc data, size_t count) { mem_buf_t::set_data(key, data, count); NC_CHECK(has_size(), "no size!", return *this); remake(); return *this; }
	/* operators */
	nc_ostream_t& gfx_img_t::operator<<(nc_ostream_t& stm) const {
		// mem_buf_t::operator<<(stm);
		if constexpr (NC_TRUTH) {
			img_bmp_info bmp;
			// file
			bmp.file_info.type_code = 0x4d;
			bmp.file_info.file_size = 54u + get_space();
			bmp.file_info.reserved1 = 0u;
			bmp.file_info.reserved2 = 0u;
			bmp.file_info.data_offset = 54u;
			// data
			bmp.data_info.header_size = 3u;
			bmp.data_info.width = get_size_x();
			bmp.data_info.height = get_size_y();
			bmp.data_info.nof_planes = 0u;
			bmp.data_info.nof_pixel_bits = 24u;
			bmp.data_info.compression_type = 0u;
			bmp.data_info.image_size = get_space();
			bmp.data_info.ppm_x = 0u;
			bmp.data_info.ppm_y = 0u;
			bmp.data_info.clrs_need = 0u;
			bmp.data_info.clrs_used = 0u;
			stm << bmp;
			stm.seekp(bmp.file_info.data_offset, std::ios_base::beg);
			stm.write(get_data(), get_space());
		}
		return stm;
	}
	nc_istream_t& gfx_img_t::operator>>(nc_istream_t& stm) {
		// mem_buf_t::operator>>(stm);
		if constexpr (NC_TRUTH) {
			img_bmp_info bmp;
			stm >> bmp;
			NC_CHECK(bmp.data_info.nof_pixel_bits >= 8u && bmp.data_info.nof_pixel_bits <= 32u, "format error!", return stm);
			set_size(NC_NUM_FABS(bmp.data_info.width), NC_NUM_FABS(bmp.data_info.height));
			v1s_t nof_channels = bmp.data_info.nof_pixel_bits;
			m_layt = mem_layt_t("pixel", type_info_t::get_type<v4u08>());
			NC_CHECK(mem_buf_t::remake(bmp.data_info.image_size / nof_channels, NC_NULL), "remake error!", return stm);
			if (bmp.data_info.nof_pixel_bits == 8u) {
				nof_channels = 4u;
				bmp.palette.pxl_buf.resize(bmp.data_info.clrs_used * nof_channels, 0u);
				bmp.palette.idx_buf.resize(bmp.data_info.image_size, 0u);
				stm.read(reinterpret_cast<byte_t*>(bmp.palette.pxl_buf.data()), bmp.palette.pxl_buf.size());
				stm.read(reinterpret_cast<byte_t*>(bmp.palette.idx_buf.data()), bmp.palette.idx_buf.size());

				for (v1s_t idx = 0; idx < bmp.palette.idx_buf.size(); idx++) { get_elem(idx)[idx % 4u] = bmp.palette.pxl_buf[idx]; }
			}
			else {
				v1s_t pad = ((get_size_x()) % 4) % 4;
				v1s_t beg_x, beg_y;
				v1s_t end_x, end_y;
				v1s_t dir_x, dir_y;
				if (bmp.data_info.width < 0) { beg_x = +bmp.data_info.width - 1; end_x = -1; dir_x = -1; }
				else { beg_x = +0; end_x = +bmp.data_info.width; dir_x = +1; }
				if (bmp.data_info.height < 0) { beg_y = +bmp.data_info.height - 1; end_y = -1; dir_y = -1; }
				else { beg_y = +0; end_y = +bmp.data_info.height; dir_y = +1; }
				stm.seekg(bmp.file_info.data_offset, stm.beg);
				for (v1s_t iy = beg_y; iy != end_y; iy += dir_y) {
					for (v1s_t ix = beg_x; ix != end_x; ix += dir_x) {
						stm.read(reinterpret_cast<byte_t*>(get_elem(iy * get_size_x() + ix).get_data()), bmp.data_info.nof_pixel_bits / 4u);
					}
					stm.seekg(pad, stm.cur);
				}
			}
		}
		return stm;
	}
	/* command */
	v1bit_t gfx_img_t::remake()
	{
		NC_CHECK(mem_buf_t::remake(), "remake error!", return NC_FALSE);
		NC_CHECK(has_size(), "no size!", return NC_FALSE);
		
		return NC_TRUTH;
	}
	// --==</core_methods>==--
}
#endif	// NC_GAPI