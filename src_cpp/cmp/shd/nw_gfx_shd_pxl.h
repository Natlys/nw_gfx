#ifndef NW_GFX_PIXEL_SHADER_H
#define NW_GFX_PIXEL_SHADER_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_shd.h"
namespace NW
{
	class NW_API gfx_shd_pxl : public gfx_shd
	{
	public:
		using pshd_t = gfx_shd_pxl;
		using pshd_tc = const pshd_t;
	public:
		gfx_shd_pxl();
		gfx_shd_pxl(source_tc& source);
		gfx_shd_pxl(pshd_tc& copy);
		gfx_shd_pxl(pshd_t&& copy);
		~gfx_shd_pxl();
		// --getters
		// --setters
		// --operators
		inline pshd_t& operator=(pshd_tc& copy) { gfx_shd::operator=(copy); return *this; }
		inline pshd_t& operator=(pshd_t&& copy) { gfx_shd::operator=(copy); return *this; }
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// --core_methods
		virtual v1bit remake() override;
		virtual v1nil on_bind(binder_t& ref) override;
		virtual v1nil on_draw() override;
	private:
#	if (NW_GAPI & NW_GAPI_D3D)
		ID3D11PixelShader* m_native;
#	endif
	};
}
#endif	// NW_GAPI
#endif // NW_GFX_PIXEL_SHADER_H
