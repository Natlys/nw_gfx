#include "nw_gfx_pch.hpp"
#include "nw_gfx_cam.h"
#if (defined NW_GAPI)
namespace NW
{
	gfx_cam::gfx_cam() :
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
	void gfx_cam::set_fov(v1f field_of_view) {
		m_fov = field_of_view;
	}
	void gfx_cam::set_ratio(v1f aspect_ratio) {
		m_ratio = aspect_ratio;
	}
	void gfx_cam::set_ratio(v1f size_x, v1f size_y) {
		m_ratio = size_x / size_y;
	}
	void gfx_cam::set_clips(cv1f near_clip, cv1f far_clip) {
		m_near = near_clip;
		m_far = far_clip;
	}
	void gfx_cam::set_clips(const v2f& near_and_far) {
		m_near = near_and_far[0];
		m_far = near_and_far[1];
	}
	void gfx_cam::set_crd(const v3f& coord) {
		m_crd = coord;
	}
	void gfx_cam::set_rtn(const v3f& rotation) {
		m_rtn = rotation;
	}
	void gfx_cam::set_mode(mode mode) {
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
	void gfx_cam::update()
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
#endif	// NW_GAPI