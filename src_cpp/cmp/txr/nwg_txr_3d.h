#ifndef NWG_TEXTURE_3D_H
#define NWG_TEXTURE_3D_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include "nwg_txr.h"
namespace NW
{
	/// txr_cube class
	/// description:
	class NW_API txr_cube : public a_txr
	{
	public:
		txr_cube(gfx_engine& graphics);
		~txr_cube();
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const override;
		virtual stm_in& operator>>(stm_in& stm) override;
		// --core_methods
		virtual bit remake(const img_cmp& img) override;
		virtual void clear(ptr value) override;
		virtual void on_draw() override;
	private:
#if (NW_GAPI & NW_GAPI_DX)
		ID3D11CubeTexture* m_native;
#endif
	};
}
#endif	// NW_GAPI
#endif	// NWG_TEXTURE_3D_H