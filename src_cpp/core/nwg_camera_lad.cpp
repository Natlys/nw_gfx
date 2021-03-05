#include <nwg_pch.hpp>
#include "nwg_camera_lad.h"
namespace NWG
{
	gfx_camera_lad::gfx_camera_lad() :
		gfx_camera(),
		zoom_speed(1000.0f),
		move_speed(2.0f),
		rotation_speed(200.0f),
		m_kbd(keyboard_state()), m_crs(cursor_state()), m_timer(timer()) { }
	// --==<core_methods>==--
	void gfx_camera_lad::update()
	{
		m_timer.update();
		gfx_camera::update();
	}
	void gfx_camera_lad::on_event(cursor_event& crs_evt)
	{
		if (!(m_crs.get_mode() & CRS_CAPTURED)) { return; }
		m_crs.on_event(crs_evt);
		switch (crs_evt.type) {
		case EVT_CURSOR_MOVE:
			if (m_mode == GCM_2D) {
				if (m_crs.get_held(CRS_RIGHT)) {
					coord.x += -m_crs.get_move_delta_x() * move_speed * m_timer.get_delta();
					coord.y += m_crs.get_move_delta_y() * move_speed * m_timer.get_delta();
				}
				f32 roll_deg = rotation.z + m_crs.get_move_delta_x() * move_speed * m_timer.get_delta();
				if (roll_deg < -max_roll) { rotation.z = max_roll; }
				else if (roll_deg > max_roll) { rotation.z = -max_roll; }
				else { rotation.z = roll_deg; }
			}
			else if (m_mode == GCM_3D) {
				f32 yaw_deg = rotation.y - m_crs.get_move_delta_x() * rotation_speed * m_timer.get_delta();
				f32 pitch_deg = rotation.x - static_cast<f32>(m_crs.get_move_delta_y()) * rotation_speed * m_timer.get_delta();

				if (yaw_deg < -max_yaw) { rotation.y = max_yaw; }
				else if (yaw_deg > max_yaw) { rotation.y = -max_yaw; }
				else { rotation.y = yaw_deg; }

				if (pitch_deg > max_pitch) { rotation.x = max_pitch; }
				else if (pitch_deg < -max_pitch) { rotation.x = -max_pitch; }
				else { rotation.x = pitch_deg; }
			}
			break;
		case EVT_CURSOR_SCROLL:
			f32 zoom_val = -crs_evt.val_y * zoom_speed * m_timer.get_delta();
			if (m_type == GCT_ORTHO) {
				f32 scale = view_scale + zoom_val * view_scale / 40.0f + 0.01f;
				if (scale > 0.0f) { view_scale = scale; }
			}
			else if (m_type == GCT_PERSPECT) {
				f32 fov = view_field + zoom_val;
				if (fov >= 0.01f && fov <= 180.0f) { view_field = fov; }
			}
			break;
		}
	}
	void gfx_camera_lad::on_event(keyboard_event& kbd_evt)
	{
		if (!(m_crs.get_mode() & CRS_CAPTURED)) { return; }
		m_kbd.on_event(kbd_evt);
		f32 speed = move_speed * m_timer.get_delta();
		if (m_mode == GCM_2D) {
			if (m_kbd.get_held(KC_W)) { coord.y += speed; }
			if (m_kbd.get_held(KC_S)) { coord.y -= speed; }
			if (m_kbd.get_held(KC_D)) { coord.x += speed; }
			if (m_kbd.get_held(KC_A)) { coord.x -= speed; }
		}
		else if (m_mode == GCM_3D) {
			speed = -speed;
			if (m_kbd.get_held(KC_W)) {
				coord.x += front_dir.x * speed;
				coord.y += front_dir.y * speed;
				coord.z += front_dir.z * speed;
			}
			if (m_kbd.get_held(KC_S)) {
				coord.x -= front_dir.x * speed;
				coord.z -= front_dir.z * speed;
			}
			if (m_kbd.get_held(KC_D)) { coord += right_dir * speed; }
			if (m_kbd.get_held(KC_A)) { coord -= right_dir * speed; }
			if (m_kbd.get_held(KC_SPACE)) { coord -= speed; }
			if (m_kbd.get_held(KC_LSHIFT)) { coord += speed; }
		}
	}
	void gfx_camera_lad::on_event(window_event& wnd_evt)
	{
		switch (wnd_evt.type) {
		case EVT_WINDOW_RESIZE:
			aspect_ratio = wnd_evt.val_x / wnd_evt.val_y;
			break;
		}
	}
	// --==</core_methods>==--
}