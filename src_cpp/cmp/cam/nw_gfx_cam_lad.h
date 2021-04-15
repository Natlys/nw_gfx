#ifndef NW_GFX_CAMERA_LAD_H
#define NW_GFX_CAMERA_LAD_H
#include "nw_gfx_core.hpp"
#include "nw_gfx_cam.h"
namespace NW
{
	/// graphics_gfx_cam_lad class
	class NW_API gfx_cam_lad : public gfx_cam
	{
	public:
		v1f rtn_speed;
		v1f move_speed;
		v1f zoom_speed;
		v3f rtn_limit;
	public:
		gfx_cam_lad();
		// --core_methods
		void update(const keyboard_state* keyboard, const mouse_state* mouse, const time_state* timer);
	};
}

#endif	// NW_CAMERA_LAD_H