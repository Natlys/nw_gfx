#ifndef NW_CAMERA_LAD_H
#define NW_CAMERA_LAD_H
#include <nwg_core.hpp>
#include "nwg_camera.h"
namespace NW
{
	/// graphics_camera_lad class
	class NW_API gfx_camera_lad : public gfx_camera
	{
	public: // configurable Attributes
		f32 rotation_speed = 0.0, move_speed = 0.0, zoom_speed = 0.0;
		f32 max_yaw = 360.0f;
		f32 max_pitch = 90.0f;
		f32 max_roll = 0.0f;
	public:
		gfx_camera_lad();
		// --core_methods
		void update(const keyboard_state& keyboard, const cursor_state& cursor, const time_state& timer);
	};
}

#endif	// NW_CAMERA_LAD_H