#ifndef NW_GFX_GEOMETRY_SHADER_H
#define NW_GFX_GEOMETRY_SHADER_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#include "nw_gfx_shd.h"
namespace NW
{
	class NW_API gfx_shd_gmt : public a_gfx_shd
	{
	public:
		gfx_shd_gmt();
		gfx_shd_gmt(source_tc& source_code);
		~gfx_shd_gmt();
		// --getters
		// --setters
		// --operators
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// --core_methods
		virtual v1bit remake() override;
		virtual v1nil on_draw() override;
	private:
#if(NW_GAPI & NW_GAPI_D3D)
		ID3D11GeometryShader* m_native;
#endif
	};
}
#endif	// NW_GAPI
#endif // NW_GFX_GEOMETRY_SHADER_H
