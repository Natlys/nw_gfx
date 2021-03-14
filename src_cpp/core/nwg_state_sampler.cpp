#include <nwg_pch.hpp>
#include "nwg_state_sampler.h"
#if (defined NW_GAPI)
#if (NW_GAPI & NW_GAPI_OGL)
#include <lib/nwg_load_smp.h>
#include <lib/nwg_load_txr.h>
namespace NW
{
	state_sampler::state_sampler(gfx_engine& graphics) :
		t_gfx_rsc(graphics),
		m_slot(0),
		m_filter(TXFL_NEAREST),
		m_wrap_s(TXW_REPEAT), m_wrap_t(TXW_REPEAT), m_wrap_r(TXW_REPEAT),
		m_border_color(v4f{ 0.5f, 0.5f, 0.5f, 1.0f })
	{
		glGenSamplers(1, &m_ogl_id);
		glSamplerParameteri(m_ogl_id, GL_TEXTURE_MIN_FILTER, convert_enum<texture_filters, GLenum>(m_filter));
		glSamplerParameteri(m_ogl_id, GL_TEXTURE_MAG_FILTER, convert_enum<texture_filters, GLenum>(m_filter));
		glSamplerParameteri(m_ogl_id, GL_TEXTURE_WRAP_S, convert_enum<texture_wraps, GLenum>(m_wrap_s));
		glSamplerParameteri(m_ogl_id, GL_TEXTURE_WRAP_T, convert_enum<texture_wraps, GLenum>(m_wrap_t));
		glSamplerParameteri(m_ogl_id, GL_TEXTURE_WRAP_R, convert_enum<texture_wraps, GLenum>(m_wrap_r));
		glSamplerParameterfv(m_ogl_id, GL_TEXTURE_BORDER_COLOR, &m_border_color[0]);
	}
	state_sampler::~state_sampler() { if (m_ogl_id != 0) { glDeleteSamplers(1, &m_ogl_id); m_ogl_id = 0; } }
	// --setters
	void state_sampler::set_txr_slot(ui8 texture_slot) { m_slot = texture_slot; }
	void state_sampler::set_wrap(texture_wraps wrap_s, texture_wraps wrap_t, texture_wraps wrap_r) {
		m_wrap_s = wrap_s;
		m_wrap_t = wrap_t;
		m_wrap_r = wrap_r;
		glSamplerParameteri(m_ogl_id, GL_TEXTURE_WRAP_S, convert_enum<texture_wraps, GLenum>(m_wrap_s));
		glSamplerParameteri(m_ogl_id, GL_TEXTURE_WRAP_T, convert_enum<texture_wraps, GLenum>(m_wrap_t));
		glSamplerParameteri(m_ogl_id, GL_TEXTURE_WRAP_R, convert_enum<texture_wraps, GLenum>(m_wrap_r));
	}
	void state_sampler::set_filter(texture_filters filter_mode) {
		m_filter = filter_mode;
		glSamplerParameteri(m_ogl_id, GL_TEXTURE_MIN_FILTER, convert_enum<texture_filters, GLenum>(m_filter));
		glSamplerParameteri(m_ogl_id, GL_TEXTURE_MAG_FILTER, convert_enum<texture_filters, GLenum>(m_filter));
	}
	void state_sampler::set_border_color(f32 red, f32 green, f32 blue, f32 alpha) {
		glSamplerParameterfv(m_ogl_id, GL_TEXTURE_BORDER_COLOR, &m_border_color[0]);
	}
	// --==<core_methods>==--
	void state_sampler::on_draw()
	{
		glBindSampler(m_slot, m_ogl_id);
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
#endif
#endif	// NW_GAPI