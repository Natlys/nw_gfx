#ifndef NW_SAMPLER_H
#define NW_SAMPLER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_state.h>
namespace NW
{
	/// sampler_state class
	class NW_API sampler : public t_gfx_res<sampler>
	{
	public:
		sampler(gfx_engine& graphics);
		~sampler();
		// --getters
		inline ui8 get_txr_slot() const				{ return m_slot; }
#if (NW_GAPI & NW_GAPI_OGL)
		inline GLuint get_ogl_id() const			{ return m_ogl_id; }
#endif
#if (NW_GAPI & NW_GAPI_DX)
		inline ID3D11SamplerState* get_dx_sampler() { return m_dx_sampler; }
#endif
		// --setters
		void set_txr_slot(ui8 texture_slot);
		void set_wrap(texture_wraps wrap_s, texture_wraps wrap_t = TXW_REPEAT, texture_wraps wrap_r = TXW_REPEAT);
		void set_filter(texture_filters filter_mode);
		void set_border_color(f32 red, f32 green, f32 blue, f32 alpha = 1.0f);
		// --core_methods
		virtual void on_draw() override;
	private:
		ui8 m_slot;
		texture_wraps m_wrap_s;
		texture_wraps m_wrap_t;
		texture_wraps m_wrap_r;
		texture_filters m_filter;
		v4f m_border_color;
#if (NW_GAPI & NW_GAPI_OGL)
		GLuint m_ogl_id;
#endif
#if (NW_GAPI & NW_GAPI_DX)
		ID3D11SamplerState* m_dx_sampler;
#endif
	};
}
#endif	// NW_GAPI
#endif	// NW_SAMPLER_H