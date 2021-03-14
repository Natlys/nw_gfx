#ifndef NW_VERTEX_SHADER_H
#define NW_VERTEX_SHADER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_shader.h>
namespace NW
{
	class NW_API shader_vtx : public a_shader, public t_gfx_rsc<shader_vtx>
	{
	public:
		shader_vtx(gfx_engine& graphics, cstring name);
		virtual ~shader_vtx();
		// --getters
		// --setters
		// --operators
		virtual out_stream& operator<<(out_stream& stm) const override;
		virtual in_stream& operator>>(in_stream& stm) override;
		// --core_methods
		virtual bit remake(cstring source_code) override;
		virtual void bind_txr(txr& ref) override;
		virtual void on_draw() override;
#if(NW_GAPI & NW_GAPI_DX)
		ID3D11VertexShader* inline get_dx_shader()	{ return m_dx_shader; }
#endif
	private:
		bit code_proc();
	private:
#if(NW_GAPI & NW_GAPI_DX)
		ID3D11VertexShader* m_dx_shader;
#endif
	};
}
#endif	// NW_GAPI
#endif // NW_VERTEX_SHADER_H