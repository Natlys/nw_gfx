#include "nw_gfx_pch.hpp"
#include "nw_gfx_cam_lad.h"
namespace NW
{
	gfx_cam_lad::gfx_cam_lad() :
		gfx_cam(),
		zoom_speed(-100.0f), move_speed(-4.0f), rtn_speed(-180.0f),
		rtn_limit{ 89.0f, 180.0f, 180.0f }
	{
	}
	// --==<core_methods>==--
	void gfx_cam_lad::update(const keyboard_state* keyboard, const mouse_state* mouse, const time_state* timer)
	{
		gfx_cam::update();
		if (timer == NW_NULL) { return; }
		if (keyboard != NW_NULL) {
			v1f move_delta = timer->get_delta(move_speed);
			// movement
			switch (m_mode) {
			case NW_CAMERA_2D:
				if (keyboard->is_held(KBC_W)) { m_crd[1] += move_delta; }
				if (keyboard->is_held(KBC_S)) { m_crd[1] -= move_delta; }
				if (keyboard->is_held(KBC_D)) { m_crd[0] += move_delta; }
				if (keyboard->is_held(KBC_A)) { m_crd[0] -= move_delta; }
				break;
			case NW_CAMERA_3D:
				if (keyboard->is_held(KBC_W)) { m_crd += (v3f{ m_front[0], 0.0f, m_front[2] }) * move_delta; }
				if (keyboard->is_held(KBC_S)) { m_crd -= (v3f{ m_front[0], 0.0f, m_front[2] }) * move_delta; }
				if (keyboard->is_held(KBC_D)) { m_crd += m_right * move_delta; }
				if (keyboard->is_held(KBC_A)) { m_crd -= m_right * move_delta; }
				if (keyboard->is_held(KBC_SPACE)) { m_crd[1] += move_delta; }
				if (keyboard->is_held(KBC_LSHIFT)) { m_crd[1] -= move_delta; }
				break;
			}
			// configuration
			if (keyboard->is_held(KBC_C)) {
				if (keyboard->is_pressed(KBC_1)) {
					set_mode(NW_CAMERA_2D);
					m_crd = v3f{ 0.0f, 0.0f, 0.0f };
					m_rtn = v3f{ 0.0f, 0.0f, 0.0f };
				}
				if (keyboard->is_pressed(KBC_2)) { set_mode(NW_CAMERA_2D); }
				if (keyboard->is_pressed(KBC_3)) { set_mode(NW_CAMERA_3D); }
			}
		}
		if (mouse != NW_NULL) {
			// rotation
			v1f rtn_delta = timer->get_delta(rtn_speed);
			switch (m_mode) {
			case NW_CAMERA_2D:
				if (m_rtn[2] < -rtn_limit[2]) { m_rtn[2] = +rtn_limit[2]; }
				else if (m_rtn[2] > +rtn_limit[2]) { m_rtn[2] = -rtn_limit[2]; }
				break;
			case NW_CAMERA_3D:
				if (m_rtn[1] > +rtn_limit[1]) { m_rtn[1] = -rtn_limit[1]; }
				else if (m_rtn[1] < -rtn_limit[1]) { m_rtn[1] = +rtn_limit[1]; }
				m_rtn[1] += mouse->get_move_delta_x() * rtn_delta;
				if (m_rtn[0] > +rtn_limit[0]) { m_rtn[0] = +rtn_limit[0]; }
				else if (m_rtn[0] < -rtn_limit[0]) { m_rtn[0] = -rtn_limit[0]; }
				m_rtn[0] += mouse->get_move_delta_y() * rtn_delta;
				break;
			}
			// zooming
			v1f zoom_delta = timer->get_delta(zoom_speed) * mouse->get_scroll_delta_y();
			switch (m_mode) {
			case NW_CAMERA_2D:
				m_fov = NW_MATH_CLAMP(0.0f, 1000.0f, m_fov + (m_fov * zoom_delta));
				break;
			case NW_CAMERA_3D:
				m_fov = NW_MATH_CLAMP(12.5f, 170.0f, m_fov + (m_fov * zoom_delta));
				break;
			}
			// panning
			if (mouse->is_held(MSC_2)) {
				v1f move_delta = timer->get_delta(move_speed);
				m_crd[0] -= mouse->get_move_delta_x() * move_delta * m_fov;
				m_crd[1] += mouse->get_move_delta_y() * move_delta * m_fov;
			}
		}
	}
	// --==</core_methods>==--
}