#include <nwg_pch.hpp>
#include "nwg_buf.h"
#if (defined NW_GAPI)
#if (NW_GAPI & NW_GAPI_OGL)
#include <lib/nwg_load_buf.h>
namespace NW
{
	a_gfx_buf::a_gfx_buf() :
		m_data_size(0),
		m_ogl_id(0)
	{
	}
	a_gfx_buf::~a_gfx_buf() { if (m_ogl_id != 0) { glDeleteBuffers(1, &m_ogl_id); m_ogl_id = 0; } }
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
#include <lib/nwg_dx_loader.h>
namespace NW
{
	a_gfx_buf::a_gfx_buf(gfx_engine& graphics) :
		a_gfx_rsc(graphics),
		m_info(gfx_buf_info()),
		m_native(nullptr)
	{
	}
	a_gfx_buf::~a_gfx_buf() { if (m_native != nullptr) { m_native->Release(); m_native = nullptr; } }
}
#endif
#endif	// NW_API