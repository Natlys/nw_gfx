#ifndef NW_GFX_BUFFER_H
#define NW_GFX_BUFFER_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "../nw_gfx_cmp.h"
#	include "mem/nw_mem_buf.h"
namespace NW
{
	class NW_API a_gfx_buf : public t_cmp<a_gfx_buf>, public a_gfx_cmp, public mem_buf
	{
	public:
#if (NW_GAPI & NW_GAPI_OGL)
		using handle_t = GLuint;
#endif
#if (NW_GAPI & NW_GAPI_D3D)
		using handle_t = ID3D11Buffer*;
#endif
		using handle_tc = const handle_t;
	public:
		a_gfx_buf(gfx_engine& graphics);
		a_gfx_buf(gfx_engine& graphics, cv1u stride, cv1u count = 1u, ptr_tc data = NW_NULL);
		virtual ~a_gfx_buf();
		// --getters
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		// --setters
		template<typename tname>
		v1nil set_data(cv1u count, const tname* buffer, cv1u offset = NW_NULL) { set_data(count, buffer, offset); }
		template<typename tname>
		v1nil set_data(cv1u count, const tname& buffer, cv1u offset = NW_NULL) { set_data(count, &buffer, offset); }
		template<typename tname>
		v1nil set_data(const darray<tname>& buffer, cv1u offset = NW_NULL) { set_data(buffer.size(), &buffer[0], offset); }
		virtual v1nil set_data(cv1u count = 1u, ptr_tc data = NW_NULL, cv1u offset = NW_NULL) override;
		// --core_methods
		template<typename tname>
		v1bit remake(const darray<tname>& buffer)     { return remake(sizeof(tname), buffer.size(), &buffer[0]); }
		template<typename tname>
		v1bit remake(cv1u count, const tname* buffer) { return remake(sizeof(tname), count, &buffer[0]); }
		template<typename tname>
		v1bit remake(cv1u count, const tname& buffer) { return remake(sizeof(tname), count, &buffer); }
		virtual v1bit remake(cv1u stride, cv1u count = 1u, ptr_tc data = NW_NULL) override;
		virtual v1nil on_draw() = 0;
	protected:
		handle_t m_handle;
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_BUFFER_H
