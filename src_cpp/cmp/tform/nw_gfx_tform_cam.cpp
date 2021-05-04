#include "nw_gfx_pch.hpp"
#include "nw_gfx_tform_cam.h"
#if (defined NW_GAPI)
#	include "../../core/nw_gfx_engine.h"
#	include "num/nw_num_imag.h"
namespace NW
{
	gfx_tform_cam::gfx_tform_cam() :
		gfx_tform(),
		m_fov(1.0f), m_fov_limit{ 1.0f, 1000.0f }, m_fov_speed(50.0f),
		m_ratio(16.0f / 9.0f), m_near(0.01f), m_far(100.0f),
		m_crd_limit{ 1000.0f, 1000.0f, 1000.0f }, m_crd_speed(5.0f),
		m_rtn_limit{ 85.0f, 180.0f, 180.0f }, m_rtn_speed(60.0f),
		m_right{ 1.0f, 0.0f, 0.0f }, m_upper{ 0.0f, 1.0f, 0.0f }, m_front{ 0.0f, 0.0f, 1.0f },
		m_mode(NW_CAMERA)
	{
		set_mode(NW_CAMERA_2D);
		set_layt(layt_tc("tform_cam", layt_t::elem_list_tc
			{
				mem_layt("modl", type_info::get_type<m4f>()),
				mem_layt("view", type_info::get_type<m4f>()),
				mem_layt("proj", type_info::get_type<m4f>())
			}
		)).set_count(1u);
	}
	gfx_tform_cam::gfx_tform_cam(cam_tc& copy) : gfx_tform_cam() { operator=(copy); }
	gfx_tform_cam::gfx_tform_cam(cam_t&& copy) : gfx_tform_cam() { operator=(copy); }
	gfx_tform_cam::~gfx_tform_cam() { }
	// --setters
	// // --protection
	gfx_tform_cam::cam_t& gfx_tform_cam::set_fov(cv1f field_of_view) { m_fov = field_of_view; return *this; }
	gfx_tform_cam::cam_t& gfx_tform_cam::set_fov_limit(cv2f& field_of_view_limit) { m_fov_limit = field_of_view_limit; return *this; }
	gfx_tform_cam::cam_t& gfx_tform_cam::set_fov_speed(cv1f field_of_view_speed) { m_fov_speed = field_of_view_speed; return *this; }
	gfx_tform_cam::cam_t& gfx_tform_cam::set_ratio(cv1f aspect_ratio) { m_ratio = aspect_ratio; return *this; }
	gfx_tform_cam::cam_t& gfx_tform_cam::set_ratio(cv1f size_x, cv1f size_y) { m_ratio = size_x / size_y; return *this; }
	gfx_tform_cam::cam_t& gfx_tform_cam::set_clips(cv1f near_clip, cv1f far_clip) { m_near = near_clip; m_far = far_clip; return *this; }
	gfx_tform_cam::cam_t& gfx_tform_cam::set_clips(cv2f& near_and_far) { m_near = near_and_far[0]; m_far = near_and_far[1]; return *this; }
	// // --coordinate
	gfx_tform_cam::cam_t& gfx_tform_cam::set_crd_limit(cv3f& coord_limit) { m_crd_limit = coord_limit; return *this; }
	gfx_tform_cam::cam_t& gfx_tform_cam::set_crd_speed(cv1f coord_speed) { m_crd_speed = coord_speed; return *this; }
	// // --rotation
	gfx_tform_cam::cam_t& gfx_tform_cam::set_rtn_limit(cv3f& rotat_limit) { m_rtn_limit = rotat_limit; return *this; }
	gfx_tform_cam::cam_t& gfx_tform_cam::set_rtn_speed(cv1f rotat_speed) { m_rtn_speed = rotat_speed; return *this; }
	// // --transform
	gfx_tform_cam::cam_t& gfx_tform_cam::set_view(cm4f& view) { get_elem("view").set<m4f>(view); return *this; }
	gfx_tform_cam::cam_t& gfx_tform_cam::set_proj(cm4f& proj) { get_elem("proj").set<m4f>(proj); return *this; }
	// // --configuration
	gfx_tform_cam::cam_t& gfx_tform_cam::set_mode(mode_tc mode) {
		m_mode = mode;
		switch (mode) {
		case NW_CAMERA_2D: {
			set_clips(-1000.0f, +1000.0f).
				set_fov(5.0f).set_fov_limit({ 0.1f, 1000.0f }).
				set_crd(v3f{ 0.0f, 0.0f, 0.0f }).set_rtn(v3f{ 0.0f, 0.0f, 0.0f });
			break;
		}
		case NW_CAMERA_3D: {
			set_clips(0.01f, 100.0f).
				set_fov(45.0f).set_fov_limit({ 1.0f, 179.0f }).
				set_crd(v3f{ 0.0f, 0.0f, -3.0f }).set_rtn(v3f{ 0.0f, 0.0f, 0.0f });
			break;
		}
		}
		return *this;
	}
	// --==<core_methods>==--
	v1nil gfx_tform_cam::update(keybod_tc* keyboard, cursor_tc* cursor, timer_tc* timer)
	{
		if (timer == NW_NULL) { return; }
		if (keyboard != NW_NULL) {
			v1f delta_coord = timer->get_delta(get_crd_speed());
			// movement
			switch (get_mode()) {
			case NW_CAMERA_2D:
				if (keyboard->is_held(NW_KEYCODE_W)) { m_crd[1] += delta_coord; }
				if (keyboard->is_held(NW_KEYCODE_S)) { m_crd[1] -= delta_coord; }
				if (keyboard->is_held(NW_KEYCODE_D)) { m_crd[0] += delta_coord; }
				if (keyboard->is_held(NW_KEYCODE_A)) { m_crd[0] -= delta_coord; }
				break;
			case NW_CAMERA_3D:
				if (keyboard->is_held(NW_KEYCODE_W)) { m_crd += v3f::make_norm(v3f{ m_front[0], 0.0f, m_front[2] }) * delta_coord; }
				if (keyboard->is_held(NW_KEYCODE_S)) { m_crd -= v3f::make_norm(v3f{ m_front[0], 0.0f, m_front[2] }) * delta_coord; }
				if (keyboard->is_held(NW_KEYCODE_D)) { m_crd += m_right * delta_coord; }
				if (keyboard->is_held(NW_KEYCODE_A)) { m_crd -= m_right * delta_coord; }
				if (keyboard->is_held(NW_KEYCODE_SPACE)) { m_crd[1] += delta_coord; }
				if (keyboard->is_held(NW_KEYCODE_SHIFT)) { m_crd[1] -= delta_coord; }
				break;
			}
			// configuration
			if (keyboard->is_held(NW_KEYCODE_C)) {
				if (keyboard->is_press(NW_KEYCODE_1)) { set_mode(NW_CAMERA); }
				if (keyboard->is_press(NW_KEYCODE_2)) { set_mode(NW_CAMERA_2D); }
				if (keyboard->is_press(NW_KEYCODE_3)) { set_mode(NW_CAMERA_3D); }
			}
		}
		if (cursor != NW_NULL) {
			// rotation
			v1f delta_rotat = timer->get_delta(get_rtn_speed());
			switch (get_mode()) {
			case NW_CAMERA_2D:
				if (cursor->is_held(NW_CURCODE_1)) { m_rtn[2] += cursor->get_move_delta_x(delta_rotat); }
				if (m_rtn[2] > +m_rtn_limit[2]) { m_rtn[2] = -m_rtn_limit[2]; break; }
				if (m_rtn[2] < -m_rtn_limit[2]) { m_rtn[2] = +m_rtn_limit[2]; break; }
				break;
			case NW_CAMERA_3D:
				// pitching
				m_rtn[0] -= cursor->get_move_delta_y(delta_rotat);
				if (m_rtn[0] > +m_rtn_limit[0]) { m_rtn[0] = +m_rtn_limit[0]; break; }
				if (m_rtn[0] < -m_rtn_limit[0]) { m_rtn[0] = -m_rtn_limit[0]; break; }
				// yawing
				m_rtn[1] += cursor->get_move_delta_x(delta_rotat);
				if (m_rtn[1] > +m_rtn_limit[1]) { m_rtn[1] = -m_rtn_limit[1]; break; }
				if (m_rtn[1] < -m_rtn_limit[1]) { m_rtn[1] = +m_rtn_limit[1]; break; }
				// rolling
				if (keyboard->is_held(NW_KEYCODE_E)) { m_rtn[2] += 1.0f; }
				if (keyboard->is_held(NW_KEYCODE_Q)) { m_rtn[2] -= 1.0f; }
				if (m_rtn[2] > +m_rtn_limit[2]) { m_rtn[2] = -m_rtn_limit[2]; break; }
				if (m_rtn[2] < -m_rtn_limit[2]) { m_rtn[2] = +m_rtn_limit[2]; break; }
				break;
			}
			// zooming
			v1f delta_zoom = -timer->get_delta(get_fov_speed()) * cursor->get_scroll_delta_y();
			m_fov = NW_NUM_CLAMP(m_fov_limit[0], m_fov_limit[1], m_fov + (m_fov * delta_zoom));
			// panning
			if (cursor->is_held(NW_CURCODE_2)) {
				v1f delta_coord = -timer->get_delta(get_crd_speed() * 0.1f);
				m_crd[0] -= cursor->get_move_delta_x() * delta_coord * m_fov;
				m_crd[1] += cursor->get_move_delta_y() * delta_coord * m_fov;
			}
		}
	}
	v1bit gfx_tform_cam::remake()
	{
		NW_CHECK(gfx_tform::remake(), "remake error!", return NW_FALSE);
		NW_CHECK(has_elem("view"), "no view!", return NW_FALSE);
		NW_CHECK(has_elem("proj"), "no proj!", return NW_FALSE);

		return NW_TRUE;
	}
	v1nil gfx_tform_cam::on_draw()
	{
		gfx_tform::on_draw();
		m_ratio = NW_NUM_MAX(m_ratio, 0.01f);
		switch (m_mode) {
		case NW_CAMERA_2D: {
			set_proj(make_ortho(m_near, m_far, m_ratio, m_fov));
			set_modl(m4f::make_coord(m_crd) * m4f::make_rotat_xyz(m_rtn));
			set_view(m4f::make_coord(-m_crd) * m4f::make_rotat_xyz(-m_rtn));
			break;
		}
		case NW_CAMERA_3D: {
			m_front = v3f{ 0.0f, 0.0f, 1.0f };
#			if (NW_TRUE)
			m_front[0] = NW_NUM_SIN(-m_rtn[1]) * NW_NUM_COS(m_rtn[0]);
			m_front[1] = NW_NUM_SIN(m_rtn[0]);
			m_front[2] = NW_NUM_COS(-m_rtn[1]) * NW_NUM_COS(m_rtn[0]);
#			elif (NW_FALSE)
			m_front[0] = NW_NUM_COS(m_rtn[2]) * NW_NUM_COS(m_rtn[1]) * NW_NUM_COS(m_rtn[0]);
			m_front[1] = NW_NUM_SIN(m_rtn[2]) * NW_NUM_COS(m_rtn[1]);
			m_front[2] = NW_NUM_SIN(m_rtn[1]) * NW_NUM_COS(m_rtn[0]);
#			elif (NW_TRUE)
			m_front = m3f::make_rotat_xyz(-m_rtn) * m_front;
#			elif (NW_TRUE)
			m_front = inum3d_t::make_rotat(m_rtn[0], v3f{ 1.0f, 0.0f, 0.0f }, m_front).m_imag;
			m_front = inum3d_t::make_rotat(m_rtn[1], v3f{ 0.0f, 1.0f, 0.0f }, m_front).m_imag;
			m_front = inum3d_t::make_rotat(m_rtn[2], v3f{ 0.0f, 0.0f, 1.0f }, m_front).m_imag;
#			endif
			m_front = v3f::make_norm(m_front);
			m_right = v3f::make_norm(v3f::make_crs(m_front, v3f{ 0.0f, 1.0f, 0.0f }));
			m_upper = v3f::make_norm(v3f::make_crs(m_right, m_front));
			set_proj(make_persp(m_near, m_far, m_ratio, m_fov));
			set_modl(m4f::make_coord(m_crd) * m4f::make_rotat_xyz(m_rtn));
			set_view(make_lookat(m_crd, m_crd + m_front, v3f{ 0.0f, 1.0f, 0.0f }));
			break;
		}
		}
	}
	// --==</core_methods>==--
}
#endif	// NW_GAPI