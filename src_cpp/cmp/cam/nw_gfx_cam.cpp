#include "nw_gfx_pch.hpp"
#include "nw_gfx_cam.h"
#if (defined NW_GAPI)
#	include "../../core/nw_gfx_engine.h"
namespace NW
{
	gfx_cam::gfx_cam() :
		m_buf(cmp_sys::get().get_ref<gfx_buf_shd>(0u)),
		m_fov(1.0f), m_ratio(16.0f / 9.0f),
		m_near(0.01f), m_far(100.0f),
		m_crd{ 0.0f, 0.0f, 1.0f }, m_rtn{ 0.0f, 0.0f, 0.0f },
		m_right{ 1.0f, 0.0f, 0.0f }, m_upper{ 0.0f, 1.0f, 0.0f }, m_front{ 0.0f, 0.0f, 1.0f },
		m_mode(NW_CAMERA_2D)
	{
		set_mode(NW_CAMERA_2D);
	}
	gfx_cam::~gfx_cam() { }
	// --getters
	gfx_cam::cam_t& gfx_cam::set_buf(buf_tc& buf) { m_buf = buf; return *this; }
	gfx_cam::cam_t& gfx_cam::set_fov(cv1f field_of_view) { m_fov = field_of_view; return *this; }
	gfx_cam::cam_t& gfx_cam::set_ratio(cv1f aspect_ratio) { m_ratio = aspect_ratio; return *this; }
	gfx_cam::cam_t& gfx_cam::set_ratio(cv1f size_x, cv1f size_y) { m_ratio = size_x / size_y; return *this; }
	gfx_cam::cam_t& gfx_cam::set_clips(cv1f near_clip, cv1f far_clip) { m_near = near_clip; m_far = far_clip; return *this; }
	gfx_cam::cam_t& gfx_cam::set_clips(cv2f& near_and_far) { m_near = near_and_far[0]; m_far = near_and_far[1]; return *this; }
	gfx_cam::cam_t& gfx_cam::set_crd(cv3f& coord) { m_crd = coord; return *this; }
	gfx_cam::cam_t& gfx_cam::set_rtn(cv3f& rotat) { m_rtn = rotat; return *this; }
	gfx_cam::cam_t& gfx_cam::set_proj(cm4f& proj) { (*m_buf)["cam_proj"] = proj; return *this; }
	gfx_cam::cam_t& gfx_cam::set_view(cm4f& view) { (*m_buf)["cam_view"] = view; return *this; }
	gfx_cam::cam_t& gfx_cam::set_modl(cm4f& modl) { (*m_buf)["cam_modl"] = modl; return *this; }
	gfx_cam::cam_t&  gfx_cam::set_mode(mode_tc mode) {
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
		return *this;
	}
	// --==<core_methods>==--
	v1nil gfx_cam::on_draw()
	{
		m_ratio = NW_MATH_MAX(m_ratio, 0.01f);
		switch (m_mode) {
		case NW_CAMERA_2D: {
			set_proj(make_ortho(m_near, m_far, m_ratio, m_fov));
			set_modl(m4f::make_coord(m_crd) * m4f::make_rotat_z(m_rtn[2]));
			set_view(get_modl());
			break;
		}
		case NW_CAMERA_3D: {
			m_front = v3f{
				NW_MATH_SIN(m_rtn[1]) * NW_MATH_COS(m_rtn[0]),
				NW_MATH_SIN(m_rtn[0]),
				NW_MATH_COS(m_rtn[1]) * NW_MATH_COS(m_rtn[0])
				}.get_nrm();
			m_right = m_front.get_crs({ 0.0f, 1.0f, 0.0f }).get_nrm();
			m_upper = m_right.get_crs(m_front).get_nrm();
			set_proj(make_persp(m_near, m_far, m_ratio, m_fov));
			set_modl(m4f::make_coord(m_crd) * m4f::make_rotat_xyz(m_rtn));
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
#		elif (NW_FALSE)
			m_view = m_tform;
#		else
			set_view(make_lookat(-m_crd, -m_crd + m_front, v3f{ 0.0f, 1.0f, 0.0f }));
#endif
			break;
		}
		}
		m_buf->on_draw();
		m_buf.get_val<mem_buf>().set_data();
	}
	// --==</core_methods>==--
}
namespace NW
{
	gfx_cam_lad::gfx_cam_lad() :
		gfx_cam(),
		m_rtn_limit{ 85.0f, 180.0f, 180.0f },
		m_crd_limit{ 1000.0f, 1000.0f, 1000.0f },
		m_rtn_speed(-60.0f),
		m_crd_speed(-5.0f),
		m_scl_speed(-50.0f)
	{
	}
	gfx_cam_lad::~gfx_cam_lad() { }
	// --setters
	gfx_cam_lad::lad_t& gfx_cam_lad::set_crd_limit(cv3f& coord_limit) { m_crd_limit = coord_limit; return *this; }
	gfx_cam_lad::lad_t& gfx_cam_lad::set_rtn_limit(cv3f& rotat_limit) { m_rtn_limit = rotat_limit; return *this; }
	gfx_cam_lad::lad_t& gfx_cam_lad::set_crd_speed(cv1f coord_speed) { m_crd_speed = coord_speed; return *this;}
	gfx_cam_lad::lad_t& gfx_cam_lad::set_rtn_speed(cv1f rotat_speed) { m_rtn_speed = rotat_speed; return *this;}
	gfx_cam_lad::lad_t& gfx_cam_lad::set_scl_speed(cv1f scale_speed) { m_scl_speed = scale_speed; return *this; }
	// --==<core_methods>==--
	v1nil gfx_cam_lad::on_draw()
	{
		gfx_cam::on_draw();
	}
	v1nil gfx_cam_lad::on_draw(keybod_tc* keyboard, cursor_tc* cursor, timer_tc* timer)
	{
		gfx_cam_lad::on_draw();
		if (timer == NW_NULL) { return; }
		if (keyboard != NW_NULL) {
			v1f delta_crd = timer->get_delta(get_crd_speed());
			// movement
			switch (get_mode()) {
			case NW_CAMERA_2D:
				if (keyboard->is_held(NW_KEYCODE_W)) { m_crd[1] += delta_crd; }
				if (keyboard->is_held(NW_KEYCODE_S)) { m_crd[1] -= delta_crd; }
				if (keyboard->is_held(NW_KEYCODE_D)) { m_crd[0] += delta_crd; }
				if (keyboard->is_held(NW_KEYCODE_A)) { m_crd[0] -= delta_crd; }
				break;
			case NW_CAMERA_3D:
				if (keyboard->is_held(NW_KEYCODE_W)) { m_crd += (v3f{ m_front[0], 0.0f, m_front[2] }).get_nrm() * delta_crd; }
				if (keyboard->is_held(NW_KEYCODE_S)) { m_crd -= (v3f{ m_front[0], 0.0f, m_front[2] }).get_nrm() * delta_crd; }
				if (keyboard->is_held(NW_KEYCODE_D)) { m_crd += m_right * delta_crd; }
				if (keyboard->is_held(NW_KEYCODE_A)) { m_crd -= m_right * delta_crd; }
				if (keyboard->is_held(NW_KEYCODE_SPACE)) { m_crd[1] += delta_crd; }
				if (keyboard->is_held(NW_KEYCODE_SHIFT)) { m_crd[1] -= delta_crd; }
				break;
			}
			// configuration
			if (keyboard->is_held(NW_KEYCODE_C)) {
				if (keyboard->is_press(NW_KEYCODE_1)) {
					set_mode(NW_CAMERA_2D);
					m_crd = v3f{ 0.0f, 0.0f, 0.0f };
					m_rtn = v3f{ 0.0f, 0.0f, 0.0f };
				}
				if (keyboard->is_press(NW_KEYCODE_2)) { set_mode(NW_CAMERA_2D); }
				if (keyboard->is_press(NW_KEYCODE_3)) { set_mode(NW_CAMERA_3D); }
			}
		}
		if (cursor != NW_NULL) {
			// rotation
			v1f delta_rotat = timer->get_delta(get_rtn_speed());
			switch (get_mode()) {
			case NW_CAMERA_2D:
				if (m_rtn[2] < -m_rtn_limit[2]) { m_rtn[2] = +m_rtn_limit[2]; }
				else if (m_rtn[2] > +m_rtn_limit[2]) { m_rtn[2] = -m_rtn_limit[2]; }
				break;
			case NW_CAMERA_3D:
				m_rtn[0] += cursor->get_move_delta_y(delta_rotat);
				if (m_rtn[0] > +m_rtn_limit[0]) { m_rtn[0] = +m_rtn_limit[0]; }
				else if (m_rtn[0] < -m_rtn_limit[0]) { m_rtn[0] = -m_rtn_limit[0]; }
				m_rtn[1] += cursor->get_move_delta_x(delta_rotat);
				if (m_rtn[1] > +m_rtn_limit[1]) { m_rtn[1] = -m_rtn_limit[1]; }
				else if (m_rtn[1] < -m_rtn_limit[1]) { m_rtn[1] = +m_rtn_limit[1]; }
				break;
			}
			// scaling
			v1f delta_scale = timer->get_delta(get_scl_speed()) * cursor->get_scroll_delta_y();
			switch (m_mode) {
			case NW_CAMERA_2D:
				m_fov = NW_MATH_CLAMP(0.0f, 1000.0f, m_fov + (m_fov * delta_scale));
				break;
			case NW_CAMERA_3D:
				m_fov = NW_MATH_CLAMP(12.5f, 170.0f, m_fov + (m_fov * delta_scale));
				break;
			}
			// panning
			if (cursor->is_held(NW_CURCODE_2)) {
				v1f delta_coord = timer->get_delta(get_crd_speed() * 0.1f);
				m_crd[0] -= cursor->get_move_delta_x() * delta_coord * m_fov;
				m_crd[1] += cursor->get_move_delta_y() * delta_coord * m_fov;
			}
		}
	}
	// --==</core_methods>==--
}
#endif	// NW_GAPI