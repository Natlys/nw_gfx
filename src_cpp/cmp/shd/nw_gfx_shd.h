#ifndef NW_GFX_SHADER_H
#define NW_GFX_SHADER_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "../nw_gfx_cmp.h"
namespace NW
{
	class NW_API gfx_shd : public t_cmp<gfx_shd>, public a_gfx_cmp, public a_iop_cmp
	{
	public:
		using shd_t = gfx_shd;
		using shd_tc = const shd_t;
		using source_t = dstr_t;
		using source_tc = const source_t;
		using binder_t = gfx_bind;
		using binder_tc = const binder_t;
#	if (NW_GAPI & NW_GAPI_OGL)
		using handle_t = GLuint;
#	endif
#	if (NW_GAPI & NW_GAPI_D3D)
		using handle_t = ID3DBlob*;
#	endif
		using handle_tc = const handle_t;
	public:
		gfx_shd();
		gfx_shd(source_tc& source);
		gfx_shd(shd_tc& copy);
		gfx_shd(shd_t&& copy);
		virtual ~gfx_shd();
		// --getters
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		inline source_t& get_source()        { return m_source; }
		inline source_tc& get_source() const { return m_source; }
		// --setters
		shd_t& set_source(source_tc& source);
		// --predicates
		// --operators
		inline shd_t& operator=(shd_tc& copy) { NW_CHECK(remake(copy.get_source()), "remake error!", return *this); return *this; }
		inline shd_t& operator=(shd_t&& copy) { NW_CHECK(remake(copy.get_source()), "remake error!", return *this); return *this; }
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// --core_methods
		virtual v1bit remake();
		inline v1bit remake(source_tc& source) { set_source(source); return remake(); }
		virtual v1nil on_bind(binder_t& binder);
		virtual v1nil on_draw() override;
	protected:
		handle_t m_handle;
		source_t m_source;
	};
}
#endif	// NW_GAPI
#endif // NW_GFX_SHADER_H
