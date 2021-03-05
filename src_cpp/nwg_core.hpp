#ifndef NWG_CORE_HPP
#define NWG_CORE_HPP

// --==<configuration>==--
#if defined NWG_BUILD_LIB
#	define NWG_API
#else
#	if defined NWG_BUILD_DLL
#		define NWG_API __declspec(dllexport)
#	else
#		define NWG_API __declspec(dllimport)
#	endif
#endif

#define NWG_GAPI_OGL	1 << 1
#define NWG_GAPI_DX		1 << 2
#define NWG_GAPI		NWG_GAPI_OGL

#if (NWG_GAPI & NWG_GAPI_OGL)
using gfx_device = HDC;
using gfx_window = HWND;
using gfx_context = HGLRC;
using gfx_lib = HMODULE;
using GLuint = unsigned int;
#endif	// NWG_GAPI
#if (NWG_GAPI & NWG_GAPI_DX)
using gfx_device = ID3D11Device*;
using gfx_context = ID3D11DeviceContext*;
using gfx_lib = HMODULE;
#endif	// NWG_GAPI
// --==</configurations>==--
#include <nwg_pch.hpp>
namespace NWG
{
	class NWG_API gfx_engine;
	class NWG_API gfx_camera_lad;

	class NWG_API a_gfx_cmp;
	class NWG_API a_drawable;
	class NWG_API drawable_vtx;
	class NWG_API drawable_idx;

	class NWG_API framebuf;
	class NWG_API vtx_buf;
	class NWG_API idx_buf;
	class NWG_API shd_buf;
	class NWG_API a_texture;

	class NWG_API gfx_material;
	class NWG_API shader;
	class NWG_API vtx_shader;
	class NWG_API pxl_shader;
	class NWG_API gmt_shader;

	struct NWG_API gfx_camera;
}
#endif	// NWG_CORE_HPP