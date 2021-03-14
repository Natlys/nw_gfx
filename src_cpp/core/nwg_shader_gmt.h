#ifndef NW_GEOMETRY_SHADER_H
#define NW_GEOMETRY_SHADER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_shader.h>
namespace NW
{
	class NW_API shader_gmt : public a_shader, public t_gfx_rsc<shader_gmt>
	{
	public:
		shader_gmt(gfx_engine& graphics, cstring name);
		~shader_gmt();
		// --getters
		// --setters
		virtual out_stream& operator<<(out_stream& stm) const override;
		virtual in_stream& operator>>(in_stream& stm) override;
		// --core_methods
		virtual bit remake(cstring source_code) override;
		virtual void bind_txr(txr& ref) override;
		virtual void on_draw() override;
	private:
		bit code_proc();
#if(NW_GAPI & NW_GAPI_DX)
		ID3D11GeometryShader* inline get_dx_shader()	{ return m_dx_shader; }
#endif
	private:
#if(NW_GAPI & NW_GAPI_DX)
		ID3D11GeometryShader* m_dx_shader;
#endif
	};
}
#endif	// NW_GAPI
#endif // NW_GEOMETRY_SHADER_H