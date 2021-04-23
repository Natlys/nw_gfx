#ifndef NW_GFX_TEXTURE_3D_H
#define NW_GFX_TEXTURE_3D_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_txr_2d.h"
namespace NW
{
	/// graphics_texture_3d class
	/// description:
	class NW_API gfx_txr_3d : public a_gfx_txr
	{
	public:
		gfx_txr_3d();
		virtual ~gfx_txr_3d();
		// --getters
		// --setters
		// --predicates
		// --operators
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// --core_methods
		virtual v1bit remake() override;
		virtual v1nil clear(ptr_tc data) override;
		virtual v1nil on_draw() override;
	protected:
#	if (NW_GAPI & NW_GAPI_D3D)
		ID3D11Texture3D* m_native;
#	endif
	};
}
namespace NW
{
	/// gfx_txr_cube class
	/// description:
	class NW_API gfx_txr_cube : public a_gfx_txr
	{
	public:
		gfx_txr_cube();
		virtual ~gfx_txr_cube();
		// --getters
		// --setters
		// --predicates
		// --operators
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// --core_methods
		virtual v1bit remake() override;
		virtual v1nil clear(ptr_tc data) override;
		virtual v1nil on_draw() override;
	protected:
#	if (NW_GAPI & NW_GAPI_D3D)
		ID3D11Texture3D * m_native;
#	endif
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_TEXTURE_3D_H
