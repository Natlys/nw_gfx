#ifndef NW_GFX_SAMPLER_H
#define NW_GFX_SAMPLER_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "../nw_gfx_cmp.h"
namespace NW
{
	/// graphics_sampler class
	class NW_API gfx_smp : public t_cmp<gfx_smp>, public a_gfx_cmp
	{
	public:
		using smp_t = gfx_smp;
		using smp_tc = const smp_t;
#	if (NW_GAPI & NW_GAPI_OGL)
		using handle_t = GLuint;
		using filter_t = GLenum;
		using border_t = GLenum;
#	endif
#	if (NW_GAPI & NW_GAPI_D3D)
		using handle_t = ID3D11SamplerState*;
		using filter_t = D3D11_FILTER;
		using border_t = D3D11_TEXTURE_ADDRESS_MODE;
#	endif
		using handle_tc = const handle_t;
		using filter_tc = const filter_t;
		using border_tc = const border_t;
	public:
		gfx_smp();
		gfx_smp(filter_t filter);
		gfx_smp(filter_t filter, border_t border);
		gfx_smp(filter_t filter, border_t border, cv4f& color);
		gfx_smp(smp_tc& copy);
		gfx_smp(smp_t&& copy);
		virtual ~gfx_smp();
		// --getters
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		inline cv1u get_slot() const        { return m_slot; }
		inline filter_tc get_filter() const { return m_filter; }
		inline border_tc get_border() const { return m_border; }
		inline cv4f& get_color() const      { return m_color; }
		// --setters
		smp_t& set_slot(cv1u slot);
		smp_t& set_filter(filter_tc filter);
		smp_t& set_border(border_tc border);
		smp_t& set_color(cv4f& color);
		// --operators
		inline smp_t& operator=(smp_tc& copy) { NW_CHECK(remake(copy.get_filter(), copy.get_border(), copy.get_color()), "remake error!", return *this); return *this; }
		inline smp_t& operator=(smp_t&& copy) { NW_CHECK(remake(copy.get_filter(), copy.get_border(), copy.get_color()), "remake error!", return *this); return *this; }
		// --core_methods
		v1bit remake();
		inline v1bit remake(filter_t filter) { set_filter(filter); return remake(); }
		inline v1bit remake(filter_t filter, border_t border) { set_border(border); return remake(filter); }
		inline v1bit remake(border_t border, cv4f& color)     { set_color(color); return remake(get_filter(), border); }
		inline v1bit remake(filter_t filter, border_t border, cv4f& color) { set_color(color); return remake(filter, border); }
		virtual v1nil on_draw() override;
	private:
		handle_t m_handle;
		v1u m_slot;
		filter_t m_filter;
		border_t m_border;
		v4f m_color;
	};
}
#endif	// NW_GFX_GAPI
#endif	// NW_GFX_SAMPLER_H
