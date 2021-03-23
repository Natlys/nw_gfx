#ifndef NW_TEXTURE_1D_H
#define NW_TEXTURE_1D_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include "nwg_txr.h"
namespace NW
{
	/// texture_1d class
	/// description:
	class NW_API txr_1d : public a_txr
	{
	public:
		txr_1d(gfx_engine& graphics);
		~txr_1d();
		// --getters
		// --setters
		// --core_methods
		virtual bit remake(const img_cmp& img);
		virtual void clear(ptr value) override;
		virtual void on_draw() override;
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const override;
		virtual stm_in& operator>>(stm_in& stm) override;
	private:
#if (NW_GAPI & NW_GAPI_DX)
		ID3D11Texture1D* m_native;
#endif
	};
}
#endif	// NW_GAPI
#endif	// NW_TEXTURE_3D_H