#include <nwg_pch.hpp>
#include "nwg_camera_lad.h"
namespace NWG
{
	gfx_camera_lad::gfx_camera_lad() :
		gfx_camera(),
		zoom_speed(1000.0f),
		move_speed(2.0f),
		rotation_speed(200.0f)
	{
		m_mode = GCM_2D;
		m_type = GCT_ORTHO;
		near_clip = -1000.0f;
		far_clip = +1000.0f;
		view_scale = 1.0f;
		view_field = 1.0f;
	}
	// --==<core_methods>==--
	void gfx_camera_lad::update(const keyboard_state& keyboard, const cursor_state& cursor, const time_state& timer)
	{
		gfx_camera::update();
		if (!(cursor.get_mode() & CRS_CAPTURED)) { return; }
		// movement
		f32 move_delta = move_speed * timer.get_delta();
		if (m_mode == GCM_2D) {
			if (keyboard.get_held(KC_W)) { coord.y += move_delta; }
			if (keyboard.get_held(KC_S)) { coord.y -= move_delta; }
			if (keyboard.get_held(KC_D)) { coord.x += move_delta; }
			if (keyboard.get_held(KC_A)) { coord.x -= move_delta; }
		}
		else if (m_mode == GCM_3D) {
			move_delta = -move_delta;
			if (keyboard.get_held(KC_W)) {
				coord += front_dir * move_delta;
			}
			if (keyboard.get_held(KC_S)) {
				coord -= front_dir * move_delta;
			}
			if (keyboard.get_held(KC_D)) { coord += right_dir * move_delta; }
			if (keyboard.get_held(KC_A)) { coord -= right_dir * move_delta; }
			if (keyboard.get_held(KC_SPACE)) { coord.y -= move_delta; }
			if (keyboard.get_held(KC_LSHIFT)) { coord.y += move_delta; }
		}
		// rotation
		f32 rtn_delta = rotation_speed * timer.get_delta();
		if (m_mode == GCM_2D) {
			f32 roll_deg = rotation.z;
			if (roll_deg < -max_roll) { rotation.z = max_roll; }
			else if (roll_deg > max_roll) { rotation.z = -max_roll; }
			else { rotation.z = roll_deg; }
		}
		else if (m_mode == GCM_3D) {
			f32 yaw_deg = rotation.y - static_cast<f32>(cursor.get_move_delta_x()) * rtn_delta;
			if (yaw_deg > max_yaw) { rotation.y = -max_yaw; }
			else if (yaw_deg < -max_yaw) { rotation.y = max_yaw; }
			else { rotation.y = yaw_deg; }

			f32 pitch_deg = rotation.x - static_cast<f32>(cursor.get_move_delta_y()) * rtn_delta;
			if (pitch_deg > max_pitch) { rotation.x = max_pitch; }
			else if (pitch_deg < -max_pitch) { rotation.x = -max_pitch; }
			else { rotation.x = pitch_deg; }
		}
		// zooming
		f32 zoom_delta = zoom_speed * cursor.get_scroll_delta_y();
		if (m_type == GCT_ORTHO) {
			f32 scale = view_scale + zoom_delta;
			if (scale > 0.0f) { view_scale = scale; }
		}
		else if (m_type == GCT_PERSPECT) {
			f32 fov = view_field + zoom_delta;
			if (fov >= 0.01f && fov <= 180.0f) { view_field = fov; }
		}
		// configuration
		if (keyboard.get_held(KC_C)) {
			if (keyboard.get_held(KC_1)) {
				set_mode(GCM_2D);
				set_type(GCT_ORTHO);
				coord = { 0.0f, 0.0f, 0.0f };
				rotation = { 0.0f, 0.0f, 0.0f };
			}
			if (keyboard.get_held(KC_2)) {
				set_mode(GCM_2D);
			}
			else if (keyboard.get_held(KC_3)) {
				set_mode(GCM_3D);
			}
			if (keyboard.get_held(KC_O)) {
				set_type(GCT_ORTHO);
			}
			else if (keyboard.get_held(KC_P)) {
				set_type(GCT_PERSPECT);
			}
		}
	}
	// --==</core_methods>==--
}