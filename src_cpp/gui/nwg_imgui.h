#ifndef NW_IMGUI_H
#define NW_IMGUI_H
#include <nwg_core.hpp>
#if (defined NW_GAPI && defined NW_OS)
struct imgui_draw_data;
struct imgui_io;
struct imgui_style;
namespace NW
{
	// data
	extern NW_API imgui_io* s_imgui_io;
	extern NW_API imgui_style* s_imgui_style;
	// --setters
	extern NW_API void imgui_set_mouse_enabled(bit is_enabled);
	// --core_functions
	extern NW_API bit imgui_init(window_handle* wnd, device_handle* device, context_handle* context);
	extern NW_API void imgui_quit();
	extern NW_API void imgui_begin_frame();
	extern NW_API void imgui_end_frame();
#if (NW_OS & NW_OS_WIN)
	extern NW_API LRESULT __stdcall imgui_event_proc(window_handle wnd, UINT msg, WPARAM wparam, LPARAM lparam);
#endif
}
#endif	// NW_GAPI && NW_OS
#endif	// NW_GUI_OGL_H