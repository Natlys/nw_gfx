#include "nw_gfx_pch.hpp"
#include "nw_gfx_context.h"
#if (defined NW_GAPI)
#	if (NW_GAPI & NW_GAPI_OGL)
#	include "../lib/nw_gfx_lib_txr.h"
#	include "../lib/nw_gfx_lib_shd.h"
#	include "../lib/nw_gfx_lib_layt.h"
#	include "../lib/nw_gfx_lib_core.h"
namespace NW
{
	gfx_context::gfx_context() :
		a_mem_cmp(),
		m_handle(NW_NULL),
		m_device(NW_NULL),
		m_window(NW_NULL),
		m_loader(loader_t()),
		m_drawer(NW_DEFAULT_STR),
		m_vendor(NW_DEFAULT_STR),
		m_shd_lang(NW_DEFAULT_STR),
		m_max_slot_atb(NW_DEFAULT_VAL),
		m_max_slot_txr(NW_DEFAULT_VAL),
		m_pxl_gran(NW_DEFAULT_VAL),
		m_pxl_range(NW_DEFAULT_VAL)
	{
	}
	gfx_context::gfx_context(window_t window) :
		gfx_context()
	{
		NW_CHECK(remake(window), "failed remake!", return);
	}
	gfx_context::~gfx_context()
	{
		if (has_handle()) {}
	}
	// --setters
	v1nil gfx_context::set_window(window_t& window) {
		m_window = window;
	}
	// --==<core_methods>==--
	v1bit gfx_context::remake()
	{
		NW_CHECK(has_window(), "no window!", return NW_FALSE);
		
		// only one context can be used in a single thread at one time;
		if constexpr (NW_TRUE) {
			if (has_handle() && has_device()) {
				// NW_CHECK(m_wndh, "no window!", return NW_FALSE);
				// break the connection between our thread and the rendering context;
				wglMakeContextCurrent(NW_NULL, NW_NULL);
				// release the associated dc and delete the rendering context;
				::ReleaseDC(m_window, m_device);
				// before delete - we need to release that;
				// DeleteDC(m_ctxh);	// delete only created device context;
				// before this call device context must be released or deleted;
				wglDeleteContext(m_handle);
				m_handle = NW_NULL;
				m_device = NW_NULL;
			}
			// get device context of the window;
			m_device = ::GetWindowDC(m_window);
			// setup device pixel format and only then make render context;
			PIXELFORMATDESCRIPTOR pxf_desc{ 0 };
			pxf_desc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
			pxf_desc.nVersion = 1;
			pxf_desc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL;
			pxf_desc.iPixelType = PFD_TYPE_RGBA;
			pxf_desc.iLayerType = PFD_MAIN_PLANE;
			pxf_desc.cColorBits = 24;
			pxf_desc.cRedBits = 0; pxf_desc.cGreenBits = 0; pxf_desc.cBlueBits = 0; pxf_desc.cAlphaBits = 0;
			pxf_desc.cRedShift = 0; pxf_desc.cGreenShift = 0; pxf_desc.cBlueShift = 0; pxf_desc.cAlphaShift = 0;
			pxf_desc.cAccumBits = 0;
			pxf_desc.cAccumRedBits = 0; pxf_desc.cAccumGreenBits = 0; pxf_desc.cAccumBlueBits = 0; pxf_desc.cAccumAlphaBits = 0;
			pxf_desc.cAuxBuffers = 0;
			pxf_desc.cDepthBits = 24;
			pxf_desc.cStencilBits = 8;
			pxf_desc.bReserved = 0;
			pxf_desc.dwVisibleMask = 0; pxf_desc.dwLayerMask = 0; pxf_desc.dwDamageMask = 0;
			// get the best availabple pixel format for device context;
			v1s pxl_format = ::ChoosePixelFormat(m_device, &pxf_desc);
			NW_CHECK(pxl_format != NW_NULL, "no pixel format!", return NW_FALSE);
			// pixel format can be set to some window only once
			NW_CHECK(::SetPixelFormat(m_device, pxl_format, &pxf_desc), "pixel format is not set!", return NW_FALSE);
			::DescribePixelFormat(m_device, pxl_format, pxf_desc.nSize, &pxf_desc);
		}
		// create opengl context and associate that with the device context;
		// it will be attached to the current thread and device context;
		// this is only one current context we can use;
		if constexpr (NW_TRUE) {
			m_handle = wglCreateContext(m_device);
			wglMakeContextCurrent(m_device, m_handle);
			NW_CHECK(m_loader.load(), "failed load!", return NW_FALSE);
		}
		if constexpr (NW_TRUE) { // information
			m_drawer = reinterpret_cast<cstr_t>(glGetString(GL_RENDERER));
			m_vendor = reinterpret_cast<cstr_t>(glGetString(GL_VENDOR));
			m_shd_lang = reinterpret_cast<cstr_t>(glGetString(GL_SHADING_LANGUAGE_VERSION));
			glGetIntegerv(GL_POINT_SIZE_RANGE, &m_pxl_range);
			glGetIntegerv(GL_POINT_SIZE_GRANULARITY, &m_pxl_gran);
			glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &m_max_slot_txr);
			glGetIntegerv(GL_MAX_VERTEX_ATTRIB_BINDINGS, &m_max_slot_atb);
		}

		return NW_TRUE;
	}
	v1nil gfx_context::update()
	{
		::SwapBuffers(m_device);
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
#	include "dxgi.h"
#	include "d3dcompiler.h"
namespace NW
{
	//
}
#	endif	// GAPI_D3D
#endif	// NW_GAPI