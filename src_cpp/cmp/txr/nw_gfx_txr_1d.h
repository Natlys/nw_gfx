#ifndef NW_TEXTURE_1D_H
#define NW_TEXTURE_1D_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_txr.h"
namespace NW
{
	/// texture_1d class
	/// description:
	class NW_API gfx_txr_1d : public a_gfx_txr
	{
	public:
		gfx_txr_1d(gfx_engine& graphics);
		~gfx_txr_1d();
		// --getters
		// --setters
		// --core_methods
		virtual v1bit remake(const gfx_img& img);
		virtual v1nil clear(ptr_tc buffer) override;
		virtual v1nil on_draw() override;
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const override;
		virtual stm_in& operator>>(stm_in& stm) override;
	private:
#if (NW_GAPI & NW_GAPI_D3D)
		ID3D11Texture1D* m_native;
#endif
	};
}
#endif	// NW_GAPI
#endif	// NW_TEXTURE_3D_H