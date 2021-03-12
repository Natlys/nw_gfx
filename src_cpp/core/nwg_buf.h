#ifndef NW_BUFFER_H
#define NW_BUFFER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_rsc.h>
#include <lib/nwg_switch.h>
namespace NW
{
	class NW_API a_gfx_buf
	{
	public:
		a_gfx_buf();
		virtual ~a_gfx_buf();
		// --getters
		inline size get_data_size() const	{ return m_data_size; }
#if (NW_GAPI & NW_GAPI_OGL)
		inline GLuint get_ogl_id() const	{ return m_ogl_id; }
#endif
#if (NW_GAPI & NW_GAPI_DX)
		inline ID3D11Buffer* get_dx_buf()	{ return m_dx_buf; }
#endif
		// --setters
		virtual void set_data(size data_size, const ptr data_ptr, size offset_size = 0) = 0;
		// --core_methods
		virtual void on_draw() = 0;
	protected:
		size m_data_size = 0;
#if (NW_GAPI & NW_GAPI_OGL)
		GLuint m_ogl_id;
#endif
#if (NW_GAPI & NW_GAPI_DX)
		ID3D11Buffer* m_dx_buf;
#endif
	};
}
#endif	// NW_GAPI
#endif	// NW_BUFFER_H