#ifndef NC_GFX_TEXTURE_3D_H
#define NC_GFX_TEXTURE_3D_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "nc_gfx_txr.hxx"
namespace NC
{
	/// gfx_texture3d_cube_type
	/// description:
	class gfx_txr3d_cube_t : public gfx_txr_t
	{
	public:
		gfx_txr3d_cube_t();
		virtual ~gfx_txr3d_cube_t();
		/* operators */
		virtual nc_ostream_t& operator<<(nc_ostream_t& stm) const override;
		virtual nc_istream_t& operator>>(nc_istream_t& stm) override;
		/* commands */
		virtual v1bit_t remake() override;
		virtual v1nil_t clear(ptr_tc buffer) override;
		virtual v1nil_t on_draw() override;
	private:
#if (NC_GAPI & NC_GAPI_D3D)
		ID3D11Texture3D * m_native;
#endif
	};
}
#endif	// NC_GAPI
#endif	// NC_GFX_TEXTURE_3D_H
