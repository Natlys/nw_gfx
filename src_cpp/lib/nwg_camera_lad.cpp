#include <nwg_pch.hpp>
#include "nwg_camera_lad.h"
namespace NW
{
	gfx_camera_lad::gfx_camera_lad() :
		gfx_camera(),
		zoom_speed(-100.0f),
		move_speed(-4.0f),
		rotation_speed(-180.0f)
	{
		m_mode = GCM_2D;
		m_type = GCT_ORTHO;
		near_clip = -100.0f;
		far_clip = +100.0f;
		view_scale = 1.0f;
		view_field = 1.0f;
	}
	// --==<core_methods>==--
	void gfx_camera_lad::update(const keyboard_state& keyboard, const mouse_state& mouse, const time_state& timer)
	{
		gfx_camera::update();
		if (mouse.is_cursor_enabled()) { return; }
		// movement
		f32 move_delta = move_speed * timer.get_delta();
		if (m_mode == GCM_2D) {
			if (keyboard.is_held(KBC_W)) { coord.y += move_delta; }
			if (keyboard.is_held(KBC_S)) { coord.y -= move_delta; }
			if (keyboard.is_held(KBC_D)) { coord.x += move_delta; }
			if (keyboard.is_held(KBC_A)) { coord.x -= move_delta; }
		}
		else if (m_mode == GCM_3D) {
			if (keyboard.is_held(KBC_W)) { coord += glm::normalize(v3f{ front_dir.x, 0.0f, front_dir.z }) * move_delta; }
			if (keyboard.is_held(KBC_S)) { coord -= glm::normalize(v3f{ front_dir.x, 0.0f, front_dir.z }) * move_delta; }
			if (keyboard.is_held(KBC_D)) { coord += right_dir * move_delta; }
			if (keyboard.is_held(KBC_A)) { coord -= right_dir * move_delta; }
			if (keyboard.is_held(KBC_SPACE)) { coord.y -= move_delta; }
			if (keyboard.is_held(KBC_LSHIFT)) { coord.y += move_delta; }
		}
		// rotation
		f32 rtn_delta = rotation_speed * timer.get_delta();
		if (m_mode == GCM_2D) {
			if (rotation.z < -max_roll) { rotation.z = +max_roll; }
			else if (rotation.z > +max_roll) { rotation.z = -max_roll; }
		}
		else if (m_mode == GCM_3D) {
			if (rotation.y > +max_yaw) { rotation.y = -max_yaw; }
			else if (rotation.y < -max_yaw) { rotation.y = +max_yaw; }
			rotation.y += static_cast<f32>(mouse.get_move_delta_x()) * rtn_delta;

			if (rotation.x > +max_pitch) { rotation.x = +max_pitch; }
			else if (rotation.x < -max_pitch) { rotation.x = -max_pitch; }
			rotation.x += static_cast<f32>(mouse.get_move_delta_y()) * rtn_delta;
		}
		// zooming
		f32 zoom_delta = zoom_speed * mouse.get_scroll_delta_y() * timer.get_delta();
		if (m_type == GCT_ORTHO) {
			view_scale += zoom_delta * view_scale;
			if (view_scale <= 0.01f) { view_scale = 0.01f; }
			else if (view_scale >= 1000.0f) { view_scale = 1000.0f; }
		}
		else if (m_type == GCT_PERSPECT) {
			view_field += zoom_delta * view_field;
			if (view_field <= 12.5f) { view_field = 12.51f; }
			else if (view_field >= 170.0f) { view_field = 169.99f; }
		}
		// configuration
		if (keyboard.is_held(KBC_C)) {
			if (keyboard.is_pressed(KBC_1)) {
				set_mode(GCM_2D);
				set_type(GCT_ORTHO);
				coord = { 0.0f, 0.0f, 0.0f };
				rotation = { 0.0f, 0.0f, 0.0f };
			}
			if (keyboard.is_pressed(KBC_2)) { set_mode(GCM_2D); }
			if (keyboard.is_pressed(KBC_3)) { set_mode(GCM_3D); }
			if (keyboard.is_pressed(KBC_O)) { set_type(GCT_ORTHO); }
			if (keyboard.is_pressed(KBC_P)) { set_type(GCT_PERSPECT); }
		}
	}
	// --==</core_methods>==--
}