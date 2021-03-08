#ifndef NWG_IMGUI_H
#define NWG_IMGUI_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
struct imgui_draw_data;
struct imgui_io;
struct imgui_style;
namespace NWG
{
	// data
	extern NWG_API imgui_io* s_imgui_io;
	extern NWG_API imgui_style* s_imgui_style;
	// functions
	extern NWG_API bit imgui_init(gfx_window* window, gfx_device* device, gfx_context* context);
	extern NWG_API void imgui_quit();
	extern NWG_API void imgui_begin_frame();
	extern NWG_API void imgui_end_frame();
#if (NWG_OS & NWG_OS_WIN)
	extern NWG_API LRESULT __stdcall imgui_event_proc(gfx_window wnd, UINT msg, WPARAM wparam, LPARAM lparam);
#endif
}
#endif	// NWG_GAPI
#endif	// NWG_GUI_OGL_H