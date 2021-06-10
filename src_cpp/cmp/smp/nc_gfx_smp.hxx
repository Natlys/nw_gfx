#ifndef NC_GFX_SAMPLER_H
#define NC_GFX_SAMPLER_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "../nc_gfx_cmp.hxx"
namespace NC
{
	/// graphics_sampler_type
	class gfx_smp_t : public nc_cmp_tt<gfx_smp_t>, public gfx_cmp_t
	{
	public:
		using smp_t = gfx_smp_t;
		using smp_tc = const smp_t;
#	if (NC_GAPI & NC_GAPI_OGL)
		using handle_t = GLuint;
		using filter_t = GLenum;
		using border_t = GLenum;
#	endif
#	if (NC_GAPI & NC_GAPI_D3D)
		using handle_t = ID3D11SamplerState*;
		using filter_t = D3D11_FILTER;
		using border_t = D3D11_TEXTURE_ADDRESS_MODE;
#	endif
		using handle_tc = const handle_t;
		using filter_tc = const filter_t;
		using border_tc = const border_t;
	public:
		gfx_smp_t();
		gfx_smp_t(filter_t filter);
		gfx_smp_t(filter_t filter, border_t border);
		gfx_smp_t(filter_t filter, border_t border, v4f_tc& color);
		gfx_smp_t(smp_tc& copy);
		gfx_smp_t(smp_t&& copy);
		virtual ~gfx_smp_t();
		/* getters */
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		inline v1u_tc get_slot() const        { return m_slot; }
		inline filter_tc get_filter() const { return m_filter; }
		inline border_tc get_border() const { return m_border; }
		inline v4f_tc& get_color() const      { return m_color; }
		/* setters */
		smp_t& set_slot(v1u_tc slot);
		smp_t& set_filter(filter_tc filter);
		smp_t& set_border(border_tc border);
		smp_t& set_color(v4f_tc& color);
		/* operators */
		inline smp_t& operator=(smp_tc& copy) { NC_CHECK(remake(copy.get_filter(), copy.get_border(), copy.get_color()), "remake error!", return *this); return *this; }
		inline smp_t& operator=(smp_t&& copy) { NC_CHECK(remake(copy.get_filter(), copy.get_border(), copy.get_color()), "remake error!", return *this); return *this; }
		/* command */
		v1bit_t remake();
		inline v1bit_t remake(filter_t filter) { set_filter(filter); return remake(); }
		inline v1bit_t remake(filter_t filter, border_t border) { set_border(border); return remake(filter); }
		inline v1bit_t remake(border_t border, v4f_tc& color)     { set_color(color); return remake(get_filter(), border); }
		inline v1bit_t remake(filter_t filter, border_t border, v4f_tc& color) { set_color(color); return remake(filter, border); }
		virtual v1nil_t on_draw() override;
	private:
		handle_t m_handle;
		v1u_t m_slot;
		filter_t m_filter;
		border_t m_border;
		v4f_t m_color;
	};
}
#endif	// NC_GFX_GAPI
#endif	// NC_GFX_SAMPLER_H
