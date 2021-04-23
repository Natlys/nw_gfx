#include "nw_gfx_pch.hpp"
#include "nw_gfx_cam.h"
#if (defined NW_GAPI)
namespace NW
{
	gfx_cam::gfx_cam() :
		t_cmp(), a_gfx_cmp(),
		m_fov(1.0f), m_ratio(16.0f / 9.0f),
		m_near(0.01f), m_far(100.0f),
		m_crd{ 0.0f, 0.0f, 1.0f }, m_rtn{ 0.0f, 0.0f, 0.0f },
		m_right{ 1.0f, 0.0f, 0.0f }, m_upper{ 0.0f, 1.0f, 0.0f }, m_front{ 0.0f, 0.0f, 1.0f },
		m_mode(NW_CAMERA_2D),
		m_tform(m4f::make_ident()), m_proj(m4f::make_ident()), m_view(m4f::make_ident())
	{
		set_mode(NW_CAMERA_2D);
	}
	// --getters
	v1nil gfx_cam::set_fov(cv1f field_of_view) {
		m_fov = field_of_view;
	}
	v1nil gfx_cam::set_ratio(cv1f aspect_ratio) {
		m_ratio = aspect_ratio;
	}
	v1nil gfx_cam::set_ratio(cv1f size_x, cv1f size_y) {
		m_ratio = size_x / size_y;
	}
	v1nil gfx_cam::set_clips(cv1f near_clip, cv1f far_clip) {
		m_near = near_clip;
		m_far = far_clip;
	}
	v1nil gfx_cam::set_clips(cv2f& near_and_far) {
		m_near = near_and_far[0];
		m_far = near_and_far[1];
	}
	v1nil gfx_cam::set_crd(cv3f& coord) {
		m_crd = coord;
	}
	v1nil gfx_cam::set_rtn(cv3f& rotation) {
		m_rtn = rotation;
	}
	v1nil gfx_cam::set_mode(mode_tc mode) {
		m_mode = mode;
		switch (mode) {
		case NW_CAMERA_2D: {
			m_near = -1000.0f;
			m_far = +1000.0f;
			m_fov = 1.0f;
			break;
		}
		case NW_CAMERA_3D: {
			m_near = 0.01f;
			m_far = 100.0f;
			m_fov = 45.0f;
			break;
		}
		}
	}
	// --==<core_methods>==--
	v1nil gfx_cam::on_draw()
	{
		m_ratio = NW_MATH_MAX(m_ratio, 0.01f);

		switch (m_mode) {
		case NW_CAMERA_2D: {
			m_proj = make_ortho(m_near, m_far, m_ratio, m_fov);
			m_tform = m4f::make_coord(m_crd) * m4f::make_rotat_z(m_rtn[2]);
			m_view = m_tform;
			break;
		}
		case NW_CAMERA_3D: {
			m_front = v3f::make_norm(v3f{
				NW_MATH_SIN(m_rtn[1]) * NW_MATH_COS(m_rtn[0]),
				NW_MATH_SIN(m_rtn[0]),
				NW_MATH_COS(m_rtn[1]) * NW_MATH_COS(m_rtn[0])
				});
			m_right = v3f::make_norm(v3f::make_cross(m_front, { 0.0f, 1.0f, 0.0f }));
			m_upper = v3f::make_norm(v3f::make_cross(m_right, m_front));

			m_proj = make_persp(m_near, m_far, m_ratio, m_fov);
			m_tform = m4f::make_coord(m_crd) * m4f::make_rotat_xyz(m_rtn);
#		if (NW_FALSE)
			m_view[0] = v4f{ m_right[0], m_right[1], m_right[2], -v3f::get_dot(m_right, m_crd) };
			m_view[1] = v4f{ m_upper[0], m_upper[1], m_upper[2], -v3f::get_dot(m_upper, m_crd) };
			m_view[2] = v4f{ m_front[0], m_front[1], m_front[2], -v3f::get_dot(m_front, m_crd) };
			m_view[3] = v4f{ 0.0f, 0.0f, 0.0f, 1.0f };
#		elif (NW_FALSE)
			m_view[0] = v4f{ m_right[0], m_right[1], m_right[2], 0.0f };
			m_view[1] = v4f{ m_upper[0], m_upper[1], m_upper[2], 0.0f };
			m_view[2] = v4f{ m_front[0], m_front[1], m_front[2], 0.0f };
			m_view[3] = v4f{ -v3f::get_dot(m_right, m_crd) , -v3f::get_dot(m_upper, m_crd) , -v3f::get_dot(m_front, m_crd), 1.0f };
#		elif (NW_FALSE)
			m_view[0] = v4f{ m_right[0], m_right[1], m_right[2], 0.0f };
			m_view[1] = v4f{ m_upper[0], m_upper[1], m_upper[2], 0.0f };
			m_view[2] = v4f{ m_front[0], m_front[1], m_front[2], 0.0f };
			m_view[3] = v4f{ 0.0f, 0.0f, 0.0f, 1.0f };
			m_view *= m4f::make_coord(-m_crd);
#		else
			m_view = m_tform;
			m_view = make_lookat(-m_crd, -m_crd + m_front, v3f{ 0.0f, 1.0f, 0.0f });
#endif
			break;
		}
		}
	}
	// --==</core_methods>==--
}
namespace NW
{
	gfx_cam_lad::gfx_cam_lad() :
		gfx_cam(),
		m_rtn_speed(-180.0f),
		m_rtn_limit{ 89.0f, 180.0f, 180.0f },
		m_zoom_speed(-100.0f), m_move_speed(-4.0f)
	{
	}
	// --==<core_methods>==--
	v1nil gfx_cam_lad::on_draw(keybod_tc* keybod, cursor_tc* cursor, timer_tc* timer)
	{
		on_draw();
		if (timer == NW_NULL) { return; }
		if (keybod != NW_NULL) {
			v1f move_delta = timer->get_delta(m_move_speed);
			// movement
			switch (m_mode) {
			case NW_CAMERA_2D:
				if (keybod->is_held(NW_KEYCODE_W)) { m_crd[1] += move_delta; }
				if (keybod->is_held(NW_KEYCODE_S)) { m_crd[1] -= move_delta; }
				if (keybod->is_held(NW_KEYCODE_D)) { m_crd[0] += move_delta; }
				if (keybod->is_held(NW_KEYCODE_A)) { m_crd[0] -= move_delta; }
				break;
			case NW_CAMERA_3D:
				if (keybod->is_held(NW_KEYCODE_W)) { m_crd += v3f::make_norm(v3f{ m_front[0], 0.0f, m_front[2] }) * move_delta; }
				if (keybod->is_held(NW_KEYCODE_S)) { m_crd -= v3f::make_norm(v3f{ m_front[0], 0.0f, m_front[2] }) * move_delta; }
				if (keybod->is_held(NW_KEYCODE_D)) { m_crd += m_right * move_delta; }
				if (keybod->is_held(NW_KEYCODE_A)) { m_crd -= m_right * move_delta; }
				if (keybod->is_held(NW_KEYCODE_SPACE)) { m_crd[1] += move_delta; }
				if (keybod->is_held(NW_KEYCODE_SHIFT)) { m_crd[1] -= move_delta; }
				break;
			}
			// configuration
			if (keybod->is_held(NW_KEYCODE_C)) {
				if (keybod->is_press(NW_KEYCODE_1)) {
					set_mode(NW_CAMERA_2D);
					m_crd = v3f{ 0.0f, 0.0f, 0.0f };
					m_rtn = v3f{ 0.0f, 0.0f, 0.0f };
				}
				if (keybod->is_press(NW_KEYCODE_2)) { set_mode(NW_CAMERA_2D); }
				if (keybod->is_press(NW_KEYCODE_3)) { set_mode(NW_CAMERA_3D); }
			}
		}
		if (cursor != NW_NULL) {
			// rotation
			v1f rtn_delta = timer->get_delta(m_rtn_speed);
			switch (m_mode) {
			case NW_CAMERA_2D:
				if (m_rtn[2] < -m_rtn_limit[2]) { m_rtn[2] = +m_rtn_limit[2]; }
				else if (m_rtn[2] > +m_rtn_limit[2]) { m_rtn[2] = -m_rtn_limit[2]; }
				break;
			case NW_CAMERA_3D:
				if (m_rtn[1] > +m_rtn_limit[1]) { m_rtn[1] = -m_rtn_limit[1]; }
				else if (m_rtn[1] < -m_rtn_limit[1]) { m_rtn[1] = +m_rtn_limit[1]; }
				m_rtn[1] += cursor->get_move_delta_x() * rtn_delta;
				if (m_rtn[0] > +m_rtn_limit[0]) { m_rtn[0] = +m_rtn_limit[0]; }
				else if (m_rtn[0] < -m_rtn_limit[0]) { m_rtn[0] = -m_rtn_limit[0]; }
				m_rtn[0] += cursor->get_move_delta_y() * rtn_delta;
				break;
			}
			// zooming
			v1f zoom_delta = timer->get_delta(m_zoom_speed) * cursor->get_scroll_delta_y();
			switch (m_mode) {
			case NW_CAMERA_2D:
				m_fov = NW_MATH_CLAMP(0.0f, 1000.0f, m_fov + (m_fov * zoom_delta));
				break;
			case NW_CAMERA_3D:
				m_fov = NW_MATH_CLAMP(12.5f, 170.0f, m_fov + (m_fov * zoom_delta));
				break;
			}
			// panning
			if (cursor->is_held(NW_CURCODE_MIDL)) {
				v1f move_delta = timer->get_delta(m_move_speed);
				m_crd[0] -= cursor->get_move_delta_x() * move_delta * m_fov;
				m_crd[1] += cursor->get_move_delta_y() * move_delta * m_fov;
			}
		}
	}
	v1nil gfx_cam_lad::on_draw()
	{
		gfx_cam::on_draw();
	}
	// --==</core_methods>==--
}
#endif	// NW_GAPI