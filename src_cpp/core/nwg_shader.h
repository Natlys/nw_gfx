#ifndef NWG_SHADER_H
#define NWG_SHADER_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <core/nwg_res.h>
#include <core/nwg_layout.h>
#include <core/nwg_shd_buf.h>
#include <core/nwg_texture.h>
namespace NWG
{
	struct NWG_API shader_info : public a_info
	{
	public:
		gfx_api_types gapi_type = GAPI_DEFAULT;
		shader_types shd_type = SHD_DEFAULT;
		dstring name = "default";
		dstring source_code = "default";
	public:
		shader_info(gfx_api_types gfx_api_type = GAPI_DEFAULT, shader_types shader_type = SHD_DEFAULT,
			cstring name = "default", cstring source_code = "default");
		// --operators
		virtual out_stream& operator<<(out_stream& stm) const override;
		virtual in_stream& operator>>(in_stream& stm) override;
	};
}
namespace NWG
{
	class NWG_API shader : public a_data_res
	{
		using textures = darray<mem_ref<a_texture>>;
		using buffers = darray<mem_ref<shd_buf>>;
	public:
		shader(cstring name, shader_types shd_type);
		virtual ~shader();
		// --getters
		inline const shader_info& get_info() const		{ return m_info; }
		inline shader_types get_shd_type() const		{ return m_info.shd_type; }
		inline cstring get_source_code() const			{ return &m_info.source_code[0]; }
		inline mem_ref<a_texture>& get_texture(ui8 idx) { return m_txrs[idx % m_txrs.size()]; }
		inline mem_ref<shd_buf>& get_buffer(ui8 idx)	{ return m_bufs[idx % m_bufs.size()]; }
#if (NWG_GAPI & NWG_GAPI_OGL)
		inline GLuint get_ogl_id() const				{ return m_ogl_id; }
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
		inline ID3DBlob* get_dx_blob()					{ return m_dx_blob; }
#endif
		// --setters
		void set_source_code(cstring source_code);
		// --core_methods
		virtual void on_draw() = 0;
		virtual bit compile() = 0;
		virtual bit remake(const shader_info& info);
		// --data_methods
		virtual bit save_file(cstring file_path) override;
		virtual bit load_file(cstring file_path) override;
	protected:
		shader_info m_info;
		textures m_txrs;
		buffers m_bufs;
#if (NWG_GAPI & NWG_GAPI_OGL)
		GLuint m_ogl_id;
#endif
#if(NWG_GAPI & NWG_GAPI_DX)
		ID3DBlob* m_dx_blob;
#endif
	};
}
namespace NWG
{
	class NWG_API vtx_shader : public shader, public t_gfx_res<vtx_shader>
	{
	public:
		vtx_shader(gfx_engine& graphics, cstring name);
		virtual ~vtx_shader();
		// --core_methods
		virtual void on_draw() override;
		virtual bit compile() override;
#if(NWG_GAPI & NWG_GAPI_DX)
		ID3D11VertexShader* inline get_dx_shader()	{ return m_dx_shader; }
#endif
	private:
		bit code_proc();
	private:
		input_layout m_layout;
#if(NWG_GAPI & NWG_GAPI_DX)
		ID3D11VertexShader* m_dx_shader;
#endif
	};
}
namespace NWG
{
	class NWG_API pxl_shader : public shader, public t_gfx_res<pxl_shader>
	{
	public:
		pxl_shader(gfx_engine& graphics, cstring name);
		virtual ~pxl_shader();
		// --core_methods
		virtual void on_draw() override;
		virtual bit compile() override;
#if(NWG_GAPI & NWG_GAPI_DX)
		ID3D11PixelShader* inline get_dx_shader()	{ return m_dx_shader; }
#endif
	private:
		bit code_proc();
	private:
#if(NWG_GAPI & NWG_GAPI_DX)
		ID3D11PixelShader* m_dx_shader;
#endif
	};
}
namespace NWG
{
	class NWG_API gmt_shader : public shader, public t_gfx_res<gmt_shader>
	{
	public:
		gmt_shader(gfx_engine& graphics, cstring name);
		virtual ~gmt_shader();
		// --core_methods
		virtual void on_draw() override;
		virtual bit compile() override;
#if(NWG_GAPI & NWG_GAPI_DX)
		ID3D11GeometryShader* inline get_dx_shader()	{ return m_dx_shader; }
#endif
	private:
		bit code_proc();
	private:
#if(NWG_GAPI & NWG_GAPI_DX)
		ID3D11GeometryShader* m_dx_shader;
#endif
	};
}
#endif	// NWG_GAPI
#endif // NWG_SHADER_H