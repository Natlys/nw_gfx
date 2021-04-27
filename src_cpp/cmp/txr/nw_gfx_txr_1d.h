#ifndef NW_TEXTURE_1D_H
#define NW_TEXTURE_1D_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_txr.h"
namespace NW
{
	/// texture_1d class
	/// description:
	class NW_API gfx_txr_1d : public gfx_txr
	{
	public:
		gfx_txr_1d();
		virtual ~gfx_txr_1d();
		// --getters
		// --setters
		// --predicates
		// --operators
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// --core_methods
		virtual v1bit remake();
		virtual v1nil clear(ptr_tc data) override;
		virtual v1nil on_draw() override;
		// --core_methods
	private:
#if (NW_GAPI & NW_GAPI_D3D)
		ID3D11Texture1D* m_native;
#endif
	};
}
#endif	// NW_GAPI
#endif	// NW_TEXTURE_3D_H