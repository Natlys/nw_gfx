#include "nw_gfx_pch.hpp"
#include "nw_gfx_img.h"
#if (defined NW_GAPI)
namespace NW
{
	gfx_img::gfx_img() :
		mem_arr(), a_io_cmp(),
		m_size_x(0u), m_size_y(0u)
	{
	}
	gfx_img::gfx_img(img_tc& copy) :
		mem_arr(copy), a_io_cmp(copy),
		m_size_x(0u), m_size_y(0u)
	{
	}
	gfx_img::gfx_img(img_tc& copy, v1s crd_x, v1s crd_y, v1s size_x, v1s size_y) :
		mem_arr(copy), a_io_cmp(copy),
		m_size_x(size_x), m_size_y(size_y)
	{
	}
	gfx_img::gfx_img(img_t&& copy) :
		mem_arr(copy), a_io_cmp(copy),
		m_size_x(copy.m_size_x), m_size_y(copy.m_size_y)
	{
	}
	// --setters
	v1nil gfx_img::set_count_x(cv1u count_x) {
		m_size_x = count_x;
	}
	v1nil gfx_img::set_count_y(cv1u count_y) {
		m_size_y = count_y;
	}
	v1nil gfx_img::set_count_xy(cv1u count_x, cv1u count_y) {
		m_size_x = count_x;
		m_size_y = count_y;
	}
	// --operators
	stm_out& gfx_img::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& gfx_img::operator>>(stm_in& stm) {
		return stm;
	}

	// --==<core_methods>==--
	// --==</core_methods>==--
}
#endif	// NW_GAPI