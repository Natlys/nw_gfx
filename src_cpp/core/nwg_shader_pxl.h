#ifndef NW_PIXEL_SHADER_H
#define NW_PIXEL_SHADER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_shader.h>
namespace NW
{
	class NW_API shader_pxl : public a_shader, public t_gfx_res<shader_pxl>
	{
	public:
		shader_pxl(gfx_engine& graphics, cstring name);
		~shader_pxl();
		// --setters
		// --operators
		virtual out_stream& operator<<(out_stream& stm) const override;
		virtual in_stream& operator>>(in_stream& stm) override;
		// --core_methods
		virtual bit remake(cstring source_code) override;
		virtual void bind_texture(texture& ref) override;
		virtual void on_draw() override;
#if(NW_GAPI & NW_GAPI_DX)
		ID3D11PixelShader* inline get_dx_shader()	{ return m_dx_shader; }
#endif
	private:
		bit code_proc();
	private:
#if(NW_GAPI & NW_GAPI_DX)
		ID3D11PixelShader* m_dx_shader;
#endif
	};
}
#endif	// NW_GAPI
#endif // NW_PIXEL_SHADER_H