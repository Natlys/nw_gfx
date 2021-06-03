#ifndef NC_GFX_TEXTURE_2D_H
#define NC_GFX_TEXTURE_2D_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "nc_gfx_txr.hxx"
namespace NC
{
	/// gfx_texture2d_type
	/// description:
	class gfx_txr2d_t : public gfx_txr_t
	{
	public:
		/* ctor_dtor */
		gfx_txr2d_t();
		virtual ~gfx_txr2d_t();
		/* getters */
		/* setters */
		/* vetters */
		/* operators */
		virtual nc_ostream_t& operator<<(nc_ostream_t& stm) const override;
		virtual nc_istream_t& operator>>(nc_istream_t& stm) override;
		/* commands */
		virtual v1bit_t remake() override;
		virtual v1nil_t clear(ptr_tc data) override;
		virtual v1nil_t on_draw() override;
	public:
#	if (NC_GAPI & NC_GAPI_D3D)
		ID3D11Texture2D* m_native;
#	endif
	};
	// gfx_txr_2d_multisample_type
	class gfx_txr2d_mulsmp_t : public gfx_txr2d_t
	{
	public:
		/* ctor_dtor */
		gfx_txr2d_mulsmp_t();
		virtual ~gfx_txr2d_mulsmp_t();
		/* getters */
		inline v1u_t get_samples() const { return m_samples; }
		/* setters */
		v1nil_t set_samples(v1u_t samples);
		/* operators */
		virtual nc_ostream_t& operator<<(nc_ostream_t& stm) const override;
		virtual nc_istream_t& operator>>(nc_istream_t& stm) override;
		/* commands */
		virtual v1bit_t remake();
		virtual v1nil_t on_draw() override;
	private:
		v1u_t m_samples;
#	if (NC_GAPI & NC_GAPI_D3D)
		ID3D11Texture2D* m_native;
#	endif
	};
}
#endif	// NC_GAPI
#endif // NC_GFX_TEXTURE_2D_H
