#include <nwg_pch.hpp>
#include "nwg_buf.h"
#if (defined NWG_GAPI)
#if (NWG_GAPI & NWG_GAPI_OGL)
#include <lib/nwg_ogl_v1.h>
namespace NWG
{
	a_gfx_buf::a_gfx_buf(gfx_engine& graphics) :
		t_gfx_cmp(graphics),
		m_data_size(0), m_data_ptr(nullptr),
		m_ogl_id(0) { }
	a_gfx_buf::~a_gfx_buf() { if (m_ogl_id != 0) { glDeleteBuffers(1, &m_ogl_id); m_ogl_id = 0; } }
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
#include <lib/nwg_dx_loader.h>
namespace NWG
{
	a_gfx_buf::a_gfx_buf(gfx_engine& graphics) :
		t_gfx_cmp(graphics),
		m_info(gfx_buf_info()),
		m_native(nullptr) { }
	a_gfx_buf::~a_gfx_buf() { if (m_native != nullptr) { m_native->Release(); m_native = nullptr; } }
}
#endif
#endif	// NWG_API