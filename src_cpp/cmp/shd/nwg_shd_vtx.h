#ifndef NWG_VERTEX_SHADER_H
#define NWG_VERTEX_SHADER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include "nwg_shd.h"
namespace NW
{
	class NW_API shd_vtx : public a_shd
	{
	public:
		shd_vtx(gfx_engine& graphics);
		virtual ~shd_vtx();
		// --getters
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const override;
		virtual stm_in& operator>>(stm_in& stm) override;
		// --core_methods
		virtual bit remake(cstr source_code) override;
		virtual void on_draw() override;
	private:
		bit code_proc();
#if (NW_GAPI & NW_GAPI_DX)
		ID3D11VertexShader* m_native;
#endif
	};
}
#endif	// NW_GAPI
#endif // NWG_VERTEX_SHADER_H