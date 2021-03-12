#ifndef NW_IMAGE_H
#define NW_IMAGE_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
namespace NW
{
	/// image class
	class NW_API a_image : public a_data_rsc
	{
	public:
		using pxl_fmt = pixel_formats;
		using data = darray<ubyte>;
	public:
		a_image(cstring name);
		a_image(const a_image& cpy);
		a_image(const a_image& cpy, si32 offset_x, si32 offset_y, si32 width, si32 height);
		// --getters
		inline si32 get_size_x() const		{ return m_size_x; }
		inline si32 get_size_y() const		{ return m_size_y; }
		inline si32 get_channels() const	{ return m_channels; }
		inline size get_data_size() const	{ return static_cast<size>(abs(m_size_x)) * static_cast<size>(abs(m_size_y)) * static_cast<size>(abs(m_channels)); }
		inline ui64 get_pxl_size() const	{ return static_cast<size>(abs(m_size_x)) * static_cast<size>(abs(m_size_y)); }
		inline pxl_fmt get_pxl_fmt() const	{ return m_pxl_fmt; }
		inline data_types get_data_type() const			{ return m_data_type; }
		inline ubyte* get_data()						{ return &m_pxl_data[0]; }
		inline const ubyte* get_data() const			{ return &m_pxl_data[0]; }
		inline ubyte* get_data(ui32 pxl_x, ui32 pxl_y)	{ return &m_pxl_data[NW_XY_TO_X(pxl_x * m_channels, pxl_y * m_channels, m_size_x) % get_data_size()]; }
		// --setters
		void set_data(const ubyte* data_ptr);
		void set_data(const ubyte* data_ptr, si32 offset_x, si32 offset_y, si32 width, si32 height);
		// --operators
		virtual out_stream& operator<<(out_stream& stm) const = 0;
		virtual in_stream& operator>>(in_stream& stm) = 0;
	protected:
		si32 m_size_x;
		si32 m_size_y;
		si32 m_channels;
		pxl_fmt m_pxl_fmt;
		data_types m_data_type;
		data m_pxl_data;
	};
}
namespace NW
{
	/// image_bmp class
	/// description:
	/// --used for loading of .bmp formatted files
	/// interface:
	/// ->load a bitmap as binary file->read headers "file" and "data"
	/// ->if the image is indexed - load color pallete
	/// ->read pixel data with offset which is defined in "file" header
	/// ->in the case of 24bit and not multiple-of-4 sizes, we need to consider padding
	class NW_API image_bmp : public a_image
	{
	public:
#pragma pack(push, 1) // add padding 16->14
		struct {
			ui16 type_code = 0x4d;		// two encoded letters;usually "bm"
			ui32 header_size = 14;		// size of the file in bytes
			ui16 reserved1 = 0;			// it is reserved, (can be used by a programmer)
			ui16 reserved2 = 0;			// so it is always zero
			ui32 data_offset = 54;		// offset to the pixel data
		} file_info;	// file info
#pragma pack(pop)
#pragma pack(push, 1)
		struct {
			ui32 header_size = 3;	// size of the header in bytes
			si32 width = 1;			// bitmap width in pixels
			si32 height = 1;		// bitmap height in pixels
			ui16 nof_planes = 1;		// always 1
			ui16 nof_pixel_bits = 24;	// bpp
			ui32 compression_type = 0;	// 24bpp = 0; 32bpp = 3
			ui32 image_size = 0;		// 0 for uncompressed
			si32 ppm_x = 0;
			si32 ppm_y = 0;
			ui32 clrs_used = 0;	// indexed pallete count; zero for all available collors;
			ui32 clrs_need = 0;	// required colors for bitmap
		} data_info;	// description
#pragma pack(pop)
	public:
		image_bmp(cstring name);
		// --operators
		virtual out_stream& operator<<(out_stream& stm) const override;
		virtual in_stream& operator>>(in_stream& stm) override;
	};
}
namespace NW
{
	/// image_png class
	class NW_API image_png : public a_image
	{
	public:
		image_png(cstring name);
		// --operators
		virtual out_stream& operator<<(out_stream& stm) const override;
		virtual in_stream& operator>>(in_stream& stm) override;
	};
}
namespace NW
{
	/// image_jpg class
	class NW_API image_jpg : public a_image
	{
	public:
		image_jpg(cstring name);
		// --operators
		virtual out_stream& operator<<(out_stream& stm) const override;
		virtual in_stream& operator>>(in_stream& stm) override;
	};
}
#endif	// NW_GAPI
#endif	// NW_IMAGE_H