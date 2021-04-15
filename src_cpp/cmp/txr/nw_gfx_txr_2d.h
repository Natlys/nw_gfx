#ifndef NW_GFX_TEXTURE_2D_H
#define NW_GFX_TEXTURE_2D_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_txr.h"
namespace NW
{
	/// gfx_txr_2d class
	/// description:
	class NW_API gfx_txr_2d : public a_gfx_txr
	{
	public:
		gfx_txr_2d(gfx_engine& graphics);
		virtual ~gfx_txr_2d();
		// --setters
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const override;
		virtual stm_in& operator>>(stm_in& stm) override;
		// --core_methods
		virtual v1bit remake(img_tc& img) override;
		virtual v1nil clear(ptr_tc buffer) override;
		virtual v1nil on_draw() override;
	private:
#if (NW_GAPI & NW_GAPI_D3D)
		ID3D11Texture2D* m_native;
#endif
	};
	// gfx_txr_2d_multisample class
	class NW_API gfx_txr_2d_mulsmp : public gfx_txr_2d
	{
	public:
		gfx_txr_2d_mulsmp(gfx_engine& graphics);
		~gfx_txr_2d_mulsmp();
		// --getters
		inline v1u get_samples() const { return m_samples; }
		// --setters
		void set_samples(v1u samples);
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const override;
		virtual stm_in& operator>>(stm_in& stm) override;
		// --core_methods
		virtual v1bit remake(img_tc& img) override;
		virtual v1nil on_draw() override;
	private:
		v1u m_samples;
#if (NW_GAPI & NW_GAPI_D3D)
		ID3D11Texture2D* m_native;
#endif
	};
}
#endif	// NW_GAPI
#endif // NW_GFX_TEXTURE_2D_H
