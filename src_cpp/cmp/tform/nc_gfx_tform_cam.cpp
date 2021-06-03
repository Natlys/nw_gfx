#include "nc_gfx_pch.hpp"
#include "nc_gfx_tform_cam.hxx"
#if (defined NC_GAPI)
#	include "../../core/nc_nc_gfx_eng.hxx"
#	include "num/nc_num_imag.hxx"
namespace NC
{
	gfx_tform_cam::gfx_tform_cam() :
		gfx_tform(),
		m_fov(1.0f),
		m_ratio(16.0f / 9.0f), m_near(0.01f), m_far(100.0f),
		m_right{ 1.0f, 0.0f, 0.0f }, m_upper{ 0.0f, 1.0f, 0.0f }, m_front{ 0.0f, 0.0f, 1.0f },
		m_mode(NC_CAMERA)
	{
		set_mode(NC_CAMERA_2D);
		set_layt(layt_tc("tform_cam", layt_t::elem_list_tc
			{
				mem_layt_t("modl", type_info_t::get_type<m4x4f>()),
				mem_layt_t("view", type_info_t::get_type<m4x4f>()),
				mem_layt_t("proj", type_info_t::get_type<m4x4f>())
			}
		)).set_count(1u);
	}
	gfx_tform_cam::gfx_tform_cam(cam_tc& copy) : gfx_tform_cam() { operator=(copy); }
	gfx_tform_cam::gfx_tform_cam(cam_t&& copy) : gfx_tform_cam() { operator=(copy); }
	gfx_tform_cam::~gfx_tform_cam() { }
	/* setters */
	// // --protection
	gfx_tform_cam::cam_t& gfx_tform_cam::set_fov(v1f_tc field_of_view) { m_fov = field_of_view; return *this; }
	gfx_tform_cam::cam_t& gfx_tform_cam::set_ratio(v1f_tc aspect_ratio) { m_ratio = aspect_ratio; return *this; }
	gfx_tform_cam::cam_t& gfx_tform_cam::set_ratio(v1f_tc size_x, v1f_tc size_y) { m_ratio = size_x / size_y; return *this; }
	gfx_tform_cam::cam_t& gfx_tform_cam::set_clips(v1f_tc near_clip, v1f_tc far_clip) { m_near = near_clip; m_far = far_clip; return *this; }
	gfx_tform_cam::cam_t& gfx_tform_cam::set_clips(cv2f& near_and_far) { m_near = near_and_far[0]; m_far = near_and_far[1]; return *this; }
	// // --transform
	gfx_tform_cam::cam_t& gfx_tform_cam::set_view(cm4x4f& view) { get_elem("view").set<m4x4f>(view); return *this; }
	gfx_tform_cam::cam_t& gfx_tform_cam::set_proj(cm4x4f& proj) { get_elem("proj").set<m4x4f>(proj); return *this; }
	// // --configuration
	gfx_tform_cam::cam_t& gfx_tform_cam::set_mode(mode_tc mode) {
		m_mode = mode;
		switch (mode) {
		case NC_CAMERA_2D: {
			set_clips(-1000.0f, +1000.0f).
				set_fov(5.0f).
				set_crd(v3f_t{ 0.0f, 0.0f, 0.0f }).set_rtn(v3f_t{ 0.0f, 0.0f, 0.0f });
			break;
		}
		case NC_CAMERA_3D: {
			set_clips(0.1f, 100.0f).
				set_fov(45.0f).
				set_crd(v3f_t{ 0.0f, 0.0f, -3.0f }).set_rtn(v3f_t{ 0.0f, 0.0f, 0.0f });
			break;
		}
		}
		return *this;
	}
	/* commands */
	v1nil_t gfx_tform_cam::update(keybod_tc* keyboard, cursor_tc* cursor, timer_tc* timer)
	{
		if (timer == NC_NULL) { return; }
		if (keyboard != NC_NULL) {
			v1f_t delta_coord = timer->get_delta(m_fov);
			// movement
			switch (get_mode()) {
			case NC_CAMERA_2D:
				delta_coord *= (2.0f);
				if (keyboard->is_held(NC_KEYCODE_W)) { m_crd[1] += delta_coord; }
				if (keyboard->is_held(NC_KEYCODE_S)) { m_crd[1] -= delta_coord; }
				if (keyboard->is_held(NC_KEYCODE_D)) { m_crd[0] += delta_coord; }
				if (keyboard->is_held(NC_KEYCODE_A)) { m_crd[0] -= delta_coord; }
				break;
			case NC_CAMERA_3D:
				delta_coord *= (2.5f / m_fov);
				if (keyboard->is_held(NC_KEYCODE_W)) { m_crd += v3f_t::make_norm(v3f_t{ m_front[0], 0.0f, m_front[2] }) * delta_coord; }
				if (keyboard->is_held(NC_KEYCODE_S)) { m_crd -= v3f_t::make_norm(v3f_t{ m_front[0], 0.0f, m_front[2] }) * delta_coord; }
				if (keyboard->is_held(NC_KEYCODE_D)) { m_crd += m_right * delta_coord; }
				if (keyboard->is_held(NC_KEYCODE_A)) { m_crd -= m_right * delta_coord; }
				if (keyboard->is_held(NC_KEYCODE_SPACE)) { m_crd[1] += delta_coord; }
				if (keyboard->is_held(NC_KEYCODE_SHIFT)) { m_crd[1] -= delta_coord; }
				break;
			}
			// configuration
			if (keyboard->is_held(NC_KEYCODE_C)) {
				if (keyboard->is_press(NC_KEYCODE_1)) { set_mode(NC_CAMERA); }
				if (keyboard->is_press(NC_KEYCODE_2)) { set_mode(NC_CAMERA_2D); }
				if (keyboard->is_press(NC_KEYCODE_3)) { set_mode(NC_CAMERA_3D); }
			}
		}
		if (cursor != NC_NULL) {
			// rotation
			v1f_t delta_rotat = timer->get_delta(m_fov);
			switch (get_mode()) {
			case NC_CAMERA_2D:
				delta_rotat *= 75.0f / m_fov;
				if (cursor->is_held(NC_CURCODE_1)) { m_rtn[2] += cursor->get_move_delta_x(delta_rotat); }
				if (m_rtn[2] > +180.0f) { m_rtn[2] = -180.0f; break; }
				if (m_rtn[2] < -180.0f) { m_rtn[2] = +180.0f; break; }
				break;
			case NC_CAMERA_3D:
				delta_rotat *= 1.0f;
				// pitching
				m_rtn[0] -= cursor->get_move_delta_y(delta_rotat);
				if (m_rtn[0] > +85.0f) { m_rtn[0] = +85.0f; break; }
				if (m_rtn[0] < -85.0f) { m_rtn[0] = -85.0f; break; }
				// yawing
				m_rtn[1] += cursor->get_move_delta_x(delta_rotat);
				if (m_rtn[1] > +180.0f) { m_rtn[1] = -180.0f; break; }
				if (m_rtn[1] < -180.0f) { m_rtn[1] = +180.0f; break; }
				// rolling
				if (keyboard->is_held(NC_KEYCODE_E)) { m_rtn[2] += delta_rotat; }
				if (keyboard->is_held(NC_KEYCODE_Q)) { m_rtn[2] -= delta_rotat; }
				if (m_rtn[2] > +180.0f) { m_rtn[2] = -180.0f; break; }
				if (m_rtn[2] < -180.0f) { m_rtn[2] = +180.0f; break; }
				break;
			}
			// zooming
			v1f_t delta_zoom = -timer->get_delta(cursor->get_scroll_delta_y() * m_fov);
			switch (get_mode()) {
			case NC_CAMERA_2D:
				delta_zoom *= 50.0f;
				m_fov = NC_NUM_CLAMP(0.01f, 1000.0f, m_fov + delta_zoom);
				break;
			case NC_CAMERA_3D:
				delta_zoom *= 20.0f;
				m_fov = NC_NUM_CLAMP(1.00f, 179.0f, m_fov + delta_zoom);
				break;
			}
			// panning
			if (cursor->is_held(NC_CURCODE_2)) {
				v1f_t delta_coord = -timer->get_delta(m_fov);
				m_crd[0] -= cursor->get_move_delta_x(delta_coord);
				m_crd[1] += cursor->get_move_delta_y(delta_coord);
			}
		}
	}
	v1bit_t gfx_tform_cam::remake()
	{
		NC_CHECK(gfx_tform::remake(), "remake error!", return NC_FALSE);
		NC_CHECK(has_elem("view"), "no view!", return NC_FALSE);
		NC_CHECK(has_elem("proj"), "no proj!", return NC_FALSE);

		return NC_TRUTH;
	}
	v1nil_t gfx_tform_cam::on_draw()
	{
		gfx_tform::on_draw();
		m_ratio = NC_NUM_MAX(m_ratio, 0.01f);
		switch (m_mode) {
		case NC_CAMERA_2D: {
			m2x3f bounds(NC_NULL);
			bounds[0] = v2f_t{ -m_ratio, +m_ratio };
			bounds[1] = v2f_t{ -1.0f, +1.0f };
			bounds[2] = v2f_t{ m_near, m_far };
			set_view( m4x4f::make_coord(-m_crd) * m4x4f::make_rotat_xyz(-m_rtn) );
			set_proj( m4x4f::make_ortho(bounds, m_fov) );
			break;
		}
		case NC_CAMERA_3D: {
			m_front = v3f_t{ 0.0f, 0.0f, 1.0f };
#			if (NC_FALSE)
			m_front[0] = NC_NUM_SIN(-m_rtn[1]) * NC_NUM_COS(m_rtn[0]);
			m_front[1] = NC_NUM_SIN(m_rtn[0]);
			m_front[2] = NC_NUM_COS(-m_rtn[1]) * NC_NUM_COS(m_rtn[0]);
#			elif (NC_FALSE)
			m_front[0] = NC_NUM_COS(m_rtn[2]) * NC_NUM_COS(m_rtn[1]) * NC_NUM_COS(m_rtn[0]);
			m_front[1] = NC_NUM_SIN(m_rtn[2]) * NC_NUM_COS(m_rtn[1]);
			m_front[2] = NC_NUM_SIN(m_rtn[1]) * NC_NUM_COS(m_rtn[0]);
#			elif (NC_TRUTH)
			m_front = m3x3f::make_rotat_xyz(-m_rtn) * m_front;
#			elif (NC_TRUTH)
			m_front = inum3d_t::make_mat({ NC_NUM_COS(-m_rtn[0] / 2.0f), v3f_t{ NC_NUM_SIN(-m_rtn[0] / 2.0f), NC_NUM_SIN(0.0f), NC_NUM_SIN(0.0f) } }) * m_front;
			m_front = inum3d_t::make_mat({ NC_NUM_COS(-m_rtn[1]), v3f_t{ NC_NUM_SIN(0.0f), NC_NUM_SIN(-m_rtn[1]), NC_NUM_SIN(0.0f) } }) * m_front;
#			elif (NC_TRUTH)
			m_front = inum3d_t::make_rotat(m_rtn[0], v3f_t{ 1.0f, 0.0f, 0.0f }, m_front).m_imag;
			m_front = inum3d_t::make_rotat(m_rtn[1], v3f_t{ 0.0f, 1.0f, 0.0f }, m_front).m_imag;
			m_front = inum3d_t::make_rotat(m_rtn[2], v3f_t{ 0.0f, 0.0f, 1.0f }, m_front).m_imag;
#			endif
			m_front = v3f_t::make_norm(m_front);
			m_right = v3f_t::make_norm(v3f_t::make_crs(m_front, v3f_t{ 0.0f, 1.0f, 0.0f }));
			m_upper = v3f_t::make_norm(v3f_t::make_crs(m_right, m_front));
			m2x3f bounds(NC_NULL);
			bounds[0] = v2f_t{ m_ratio * -1.0f, m_ratio * +1.0f };
			bounds[1] = v2f_t{ -1.0f, +1.0f };
			bounds[2] = v2f_t{ m_near, m_far };
			set_view( m4x4f::make_lookat(m_crd, m_crd + m_front, v3f_t{ 0.0f, 1.0f, 0.0f }) );
			set_proj( m4x4f::make_persp(bounds, m_fov) );
			break;
		}
		}
	}
	// --==</core_methods>==--
}
#endif	// NC_GAPI