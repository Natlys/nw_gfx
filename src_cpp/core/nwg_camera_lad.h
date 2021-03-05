#ifndef NWG_CAMERA_LAD_H
#define NWG_CAMERA_LAD_H
#include <nwg_core.hpp>
#include "nwg_camera.h"
namespace NWG
{
	/// graphics_camera_lad class
	class NWL_API gfx_camera_lad : public gfx_camera
	{
	public: // Configurable Attributes
		f32 rotation_speed = 0.0, move_speed = 0.0, zoom_speed = 0.0;
		f32 max_yaw = 360.0f;
		f32 max_pitch = 90.0f;
		f32 max_roll = 0.0f;
	public:
		gfx_camera_lad();
		// --core_methods
		void update();
		void on_event(cursor_event& crs_evt);
		void on_event(keyboard_event& kbd_evt);
		void on_event(window_event& wnd_evt);
	private:
		keyboard_state m_kbd;
		cursor_state m_crs;
		timer m_timer;
	};
}

#endif	// NWL_GFX_CAMERA_LAD_H