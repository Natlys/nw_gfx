#ifndef NW_GFX_IMAGE_H
#define NW_GFX_IMAGE_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "../nw_gfx_cmp.h"
#	include "mem/nw_mem_buf.h"
namespace NW
{
	/// image class
	class NW_API gfx_img : public a_io_cmp, public mem_arr
	{
	public:
		using img_t = gfx_img;
		using img_tc = const img_t;
	public:
		gfx_img();
		gfx_img(img_tc& copy);
		gfx_img(img_tc& copy, v1s crd_x, v1s crd_y, v1s size_x, v1s size_y);
		gfx_img(img_t&& copy);
		// --getters
		inline size_tc get_count_x() const  { return m_size_x; }
		inline size_tc get_count_y() const  { return m_size_y; }
		// --setters
		v1nil set_count_x(cv1u count_x);
		v1nil set_count_y(cv1u count_y);
		v1nil set_count_xy(cv1u count_x, cv1u count_y);
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const override;
		virtual stm_in& operator>>(stm_in& stm) override;
	protected:
		v1s m_size_x;
		v1s m_size_y;
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_IMAGE_H