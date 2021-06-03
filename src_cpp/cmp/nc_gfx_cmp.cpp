#include "nc_gfx_pch.hpp"
#include "nc_gfx_cmp.hxx"
#if (defined NC_GAPI)
#	include "../core/nc_nc_gfx_eng.hxx"
namespace NC
{
	gfx_cmp_t::gfx_cmp_t() : m_context(&nc_gfx_eng::get().get_context()) {}
	gfx_cmp_t::~gfx_cmp_t() { }
}
#endif	// NC_GAPI