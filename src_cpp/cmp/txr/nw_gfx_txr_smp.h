#ifndef NW_GFX_TEXTURE_SAMPLER_H
#define NW_GFX_TEXTURE_SAMPLER_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#include "cmp/nw_gfx_cmp.h"
namespace NW
{
	/// gfx_txr_smp class
	class NW_API gfx_txr_smp : public t_cmp<gfx_txr_smp>, public a_gfx_cmp
	{
	public:
#if (NW_GAPI & NW_GAPI_OGL)
		using handle = GLuint;
		using wrap = GLenum;
		using filter = GLenum;
#endif
#if (NW_GAPI & NW_GAPI_D3D)
		using handle = ID3D11SamplerState*;
		using wrap = D3D11_TEXTURE_ADDRESS_MODE;
		using filter = D3D11_FILTER;
#endif
	public:
		gfx_txr_smp(
			gfx_engine& graphics,
			filter filter_mode = NW_NULL,
			wrap wrap_mode = NW_NULL,
			v4f border_color = v4f()
		);
		~gfx_txr_smp();
		// --getters
		inline handle get_handle()       { return m_handle; }
		inline v1u get_slot() const      { return m_slot; }
		inline wrap get_wrap() const     { return m_wrap; }
		inline filter get_filter() const { return m_filter; }
		// --setters
		void set_slot(v1u slot);
		// --core_methods
		v1b remake(
			filter filter_mode = NW_NULL,
			wrap wrap_mode = NW_NULL,
			v4f border_color = v4f()
		);
		virtual v1nil on_draw() override;
	private:
		handle m_handle;
		v1u m_slot;
		wrap m_wrap;
		filter m_filter;
		v4f m_border_color;
	};
}
#endif	// NW_GFX_GAPI
#endif	// NW_GFX_TEXTURE_SAMPLER_H
