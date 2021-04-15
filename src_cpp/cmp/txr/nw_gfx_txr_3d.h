#ifndef NW_GFX_TEXTURE_3D_H
#define NW_GFX_TEXTURE_3D_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#include "nw_gfx_txr.h"
namespace NW
{
	/// gfx_txr_cube class
	/// description:
	class NW_API gfx_txr_cube : public a_gfx_txr
	{
	public:
		gfx_txr_cube(gfx_engine& graphics);
		~gfx_txr_cube();
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const override;
		virtual stm_in& operator>>(stm_in& stm) override;
		// --core_methods
		virtual v1bit remake(img_tc& img) override;
		virtual v1nil clear(ptr_tc buffer) override;
		virtual v1nil on_draw() override;
	private:
#if (NW_GAPI & NW_GAPI_D3D)
		ID3D11Texture3D * m_native;
#endif
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_TEXTURE_3D_H
