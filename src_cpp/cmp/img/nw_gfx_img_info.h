#ifndef NW_GFX_IMAGE_INFO_H
#define NW_GFX_IMAGE_INFO_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
namespace NW
{
	struct img_pal_info
	{
	public:
		darray_t<byte_t> idx_buf;
		darray_t<byte_t> pxl_buf;
	};
	struct img_bmp_info : public a_iop_cmp
	{
	public:
#pragma pack(push, 1) // add padding 16->14
		struct {
		public:
			v1u16 type_code = 77u;   // two encoded letters;usually "bm"
			v1u32 file_size = 54u;   // size of the entire file in bytes
			v1u16 reserved1 = 0u;    // it is reserved, (can be used by a programmer)
			v1u16 reserved2 = 0u;    // so it is always zero
			v1u32 data_offset = 54u;  // offset to the pixel data
		} file_info; // file information
#pragma pack(pop)
#pragma pack(push, 1)
		struct {
		public:
			v1u32 header_size = 3u;      // size of the header in bytes
			v1s32 width = 1;             // bitmap width in pixels
			v1s32 height = 1;            // bitmap height in pixels
			v1u16 nof_planes = 1u;       // always 1
			v1u16 nof_pixel_bits = 24u;  // bpp
			v1u32 compression_type = 0u; // 24bpp = 0; 32bpp = 3
			v1u32 image_size = 0u;       // 0 for uncompressed
			v1s32 ppm_x = 0;             // don't care
			v1s32 ppm_y = 0;             // don't care
			v1u32 clrs_used = 0u;        // indexed pallete count; zero for all available collors;
			v1u32 clrs_need = 0u;        // required colors for bitmap
		} data_info; // data description
#pragma pack(pop)
		img_pal_info palette;
	public:
		// --operators
		inline virtual op_stream_t& operator<<(op_stream_t& stm) const override {
			stm.write(reinterpret_cast<byte_tc*>(&file_info), sizeof(file_info));
			stm.write(reinterpret_cast<byte_tc*>(&data_info), sizeof(data_info));
			return stm;
		}
		inline virtual ip_stream_t& operator>>(ip_stream_t& stm) override {
			stm.read(reinterpret_cast<byte_t*>(&file_info), sizeof(file_info));
			stm.read(reinterpret_cast<byte_t*>(&data_info), sizeof(data_info));
			return stm;
		}
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_IMAGE_INFO_H