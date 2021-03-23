#ifndef NWG_BUFFER_H
#define NWG_BUFFER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_cmp.h>
#include <lib/nwg_switch.h>
namespace NW
{
	class NW_API a_gfx_buf : public a_gfx_cmp
	{
#if (NW_GAPI & NW_GAPI_DX)
		using handle = ID3D11Buffer*;
#endif
#if (NW_GAPI & NW_GAPI_OGL)
		using handle = GLuint;
#endif
	public:
		a_gfx_buf(gfx_engine& graphics);
		virtual ~a_gfx_buf();
		// --getters
		inline size get_data_size() const	{ return m_data_size; }
		inline handle get_handle()	const	{ return m_handle; }
		// --setters
		virtual void set_data(size data_size, const ptr data_ptr, size offset_size = 0) = 0;
		// --core_methods
		virtual void on_draw() = 0;
	protected:
		handle m_handle;
		size m_data_size;
	};
}
#endif	// NW_GAPI
#endif	// NWG_BUFFER_H