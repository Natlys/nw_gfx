#ifndef NWG_TEXTURE_H
#define NWG_TEXTURE_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <core/nwg_cmp.h>
#include <core/nwg_tools.h>
namespace NWG
{
	struct NWG_API texture_info : public image_info
	{
	public:
		gfx_api_types gapi_type = GAPI_DEFAULT;
		dstring name = "default";
		ui8 nof_samples = 1;
		texture_types txr_type = TXT_2D;
		texture_formats txr_format = TXF_RGBA;
		texture_wraps wrap_s = TXW_BORDER;
		texture_wraps wrap_t = TXW_BORDER;
		texture_wraps wrap_r = TXW_BORDER;
		texture_filters filter = TXFL_NEAREST;
		v4f32 border_color = { 1.0f, 1.0f, 1.0f, 1.0f };
	public:
		// --operators
		texture_info& operator=(const image_bmp_info& info);
		texture_info& operator=(const image_png_info& info);
		texture_info& operator=(const image_info& info);
		virtual out_stream& operator<<(out_stream& stm) const override;
		virtual in_stream& operator>>(in_stream& stm) override;
	};
}
namespace NWG
{
	/// a_texture class
	/// description:
	class NWG_API a_texture : public t_gfx_cmp<a_texture>, public a_data_res
	{
	public:
		a_texture(gfx_engine& graphics, cstring name, texture_types txr_types);
		virtual ~a_texture();
		// --getters
		inline ui8 get_txr_slot() const				{ return m_slot; }
		inline texture_types get_txr_type() const	{ return m_info.txr_type; }
		inline const texture_info& get_info() const	{ return m_info; }
#if (NWG_GAPI & NWG_GAPI_OGL)
		inline GLuint get_ogl_id() const { return m_ogl_id; }
#endif
		// --setters
		void set_txr_slot(ui8 texture_slot);
		// --core_methods
		virtual void on_draw() = 0;
		virtual bool remake(const texture_info& info) = 0;
		virtual void clear(ptr value) = 0;
		// --data_methods
		virtual bit save_file(cstring file_path) = 0;
		virtual bit load_file(cstring file_path) = 0;
	protected:
		texture_info m_info;
		ui8 m_slot;
#if (NWG_GAPI & NWG_GAPI_OGL)
		GLuint m_ogl_id;
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
		ID3D11ShaderResourceView* m_res;
		ID3D11SamplerState* m_sampler;
#endif
	};
}
namespace NWG
{
	class NWG_API texture2d : public a_texture
	{
	public:
		texture2d(gfx_engine& graphics, cstring name);
		~texture2d();
		// --core_methods
		virtual void on_draw() override;
		virtual bool remake(const texture_info& info) override;
		virtual void clear(ptr value) override;
		// --data_methods
		virtual bit save_file(cstring file_path) override;
		virtual bit load_file(cstring file_path) override;
	private:
#if (NWG_GAPI & NWG_GAPI_DX)
		ID3D11Texture2D* m_native;
#endif
	};
}
#endif	// NWG_GAPI
#endif // GFX_TEXTURE_H