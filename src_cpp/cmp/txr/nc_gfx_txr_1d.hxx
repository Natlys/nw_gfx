#ifndef NC_TEXTURE_1D_H
#define NC_TEXTURE_1D_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "nc_gfx_txr.hxx"
namespace NC
{
	/// graphics_texture1d_type
	/// description:
	class gfx_txr1d_t : public gfx_txr_t
	{
	public:
		gfx_txr1d_t();
		virtual ~gfx_txr1d_t();
		/* getters */
		/* setters */
		/* vetters */
		/* operators */
		virtual nc_ostream_t& operator<<(nc_ostream_t& stm) const override;
		virtual nc_istream_t& operator>>(nc_istream_t& stm) override;
		/* commands */
		virtual v1bit_t remake();
		virtual v1nil_t clear(ptr_tc data) override;
		virtual v1nil_t on_draw() override;
		/* commands */
	private:
#if (NC_GAPI & NC_GAPI_D3D)
		ID3D11Texture1D* m_native;
#endif
	};
}
#endif	// NC_GAPI
#endif	// NC_TEXTURE_3D_H