#ifndef NWG_PIXEL_SHADER_H
#define NWG_PIXEL_SHADER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include "nwg_shd.h"
namespace NW
{
	class NW_API shd_pxl : public a_shd
	{
	public:
		shd_pxl(gfx_engine& graphics);
		~shd_pxl();
		// --getters
		// --setters
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const override;
		virtual stm_in& operator>>(stm_in& stm) override;
		// --core_methods
		virtual bit remake(cstr source_code) override;
		virtual void on_draw() override;
	private:
		bit code_proc();
	private:
#if (NW_GAPI & NW_GAPI_DX)
		ID3D11PixelShader* m_native;
#endif
	};
}
#endif	// NW_GAPI
#endif // NWG_PIXEL_SHADER_H