#ifndef NWG_TEXTURE_SAMPLER_H
#define NWG_TEXTURE_SAMPLER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_cmp.h>
#include <lib/nwg_switch.h>
namespace NW
{
	/// txr_smp class
	class NW_API txr_smp : public t_cmp<txr_smp>, public a_gfx_cmp
	{
	public:
		using wrap = txr_wraps;
		using fltr = txr_filters;
#if (NW_GAPI & NW_GAPI_OGL)
		using handle = GLuint;
#endif
#if (NW_GAPI & NW_GAPI_DX)
		using handle = ID3D11SamplerState*;
#endif
	public:
		txr_smp(gfx_engine& graphics);
		~txr_smp();
		// --getters
		inline handle get_handle()	{ return m_handle; }
		inline ui8 get_slot() const	{ return m_slot; }
		// --setters
		void set_slot(ui8 txr_slot);
		// --core_methods
		bit remake(fltr filter = TXFL_DEFAULT, wrap wrap_s = TXW_DEFAULT, wrap wrap_t = TXW_DEFAULT, wrap wrap_r = TXW_DEFAULT);
		bit remake(v4f border_color, fltr filter = TXFL_DEFAULT, wrap wrap_s = TXW_DEFAULT, wrap wrap_t = TXW_DEFAULT, wrap wrap_r = TXW_DEFAULT);
		virtual void on_draw() override;
	private:
		handle m_handle;
		ui8 m_slot;
		wrap m_wrap_s;
		wrap m_wrap_t;
		wrap m_wrap_r;
		fltr m_filter;
		v4f m_border_color;
	};
}
#endif	// NWG_GAPI
#endif	// NWG_TEXTURE_SAMPLER_H