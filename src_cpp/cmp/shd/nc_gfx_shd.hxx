#ifndef NC_GFX_SHADER_H
#define NC_GFX_SHADER_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "../nc_gfx_cmp.hxx"
namespace NC
{
	class gfx_shd_t : public nc_cmp_tt<gfx_shd_t>, public gfx_cmp_t, public nc_iop_cmp_t
	{
	public:
		using shd_t = gfx_shd_t;
		using shd_tc = const shd_t;
		using source_t = dstr_t;
		using source_tc = const source_t;
		using binder_t = gfx_bind_t;
		using binder_tc = const binder_t;
#	if (NC_GAPI & NC_GAPI_OGL)
		using handle_t = GLuint;
#	endif
#	if (NC_GAPI & NC_GAPI_D3D)
		using handle_t = ID3DBlob*;
#	endif
		using handle_tc = const handle_t;
	public:
		gfx_shd_t();
		gfx_shd_t(source_tc& source);
		gfx_shd_t(shd_tc& copy);
		gfx_shd_t(shd_t&& copy);
		virtual ~gfx_shd_t();
		/* getters */
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		inline source_t& get_source()        { return m_source; }
		inline source_tc& get_source() const { return m_source; }
		/* setters */
		shd_t& set_source(source_tc& source);
		/* vetters */
		/* operators */
		inline shd_t& operator=(shd_tc& copy) { NC_CHECK(remake(copy.get_source()), "remake error!", return *this); return *this; }
		inline shd_t& operator=(shd_t&& copy) { NC_CHECK(remake(copy.get_source()), "remake error!", return *this); return *this; }
		virtual nc_ostream_t& operator<<(nc_ostream_t& stm) const override;
		virtual nc_istream_t& operator>>(nc_istream_t& stm) override;
		/* command */
		virtual v1bit_t remake();
		inline v1bit_t remake(source_tc& source) { set_source(source); return remake(); }
		virtual v1nil_t on_bind(binder_t& binder);
		virtual v1nil_t on_draw() override;
	protected:
		handle_t m_handle;
		source_t m_source;
	};
}
#endif	// NC_GAPI
#endif // NC_GFX_SHADER_H
