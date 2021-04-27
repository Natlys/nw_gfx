#ifndef NW_GFX_VERTEX_SHADER_H
#define NW_GFX_VERTEX_SHADER_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_shd.h"
namespace NW
{
	class NW_API gfx_shd_vtx : public gfx_shd
	{
	public:
		using vshd_t = gfx_shd_vtx;
		using vshd_tc = const vshd_t;
	public:
		gfx_shd_vtx();
		gfx_shd_vtx(source_tc& source);
		gfx_shd_vtx(vshd_tc& copy);
		gfx_shd_vtx(vshd_t&& copy);
		virtual ~gfx_shd_vtx();
		// --getters
		// --setters
		// --operators
		inline vshd_t& operator=(vshd_tc& copy) { gfx_shd::operator=(copy); return *this; }
		inline vshd_t& operator=(vshd_t&& copy) { gfx_shd::operator=(copy); return *this; }
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// --core_methods
		virtual v1bit remake() override;
		virtual v1nil on_bind(binder_t& ref) override;
		virtual v1nil on_draw() override;
	private:
#	if (NW_GAPI & NW_GAPI_D3D)
		ID3D11VertexShader* m_native;
#	endif
	};
}
#endif	// NW_GAPI
#endif // NW_GFX_VERTEX_SHADER_H
