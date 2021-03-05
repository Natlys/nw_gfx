#include <nwg_pch.hpp>
#include "nwg_camera.h"
#include <math/math_transform.h>
namespace NWG
{
	gfx_camera::gfx_camera() :
		coord{ 0.0f, 0.0f, 1.0f }, rotation{ 0.0f, 0.0f, 0.0f },
		right_dir{ 1.0f, 0.0f, 0.0f }, upper_dir{ 0.0f, 1.0f, 0.0f }, front_dir{0.0f, 0.0f, 1.0f},
		world_up_dir{0.0f, 1.0f, 0.0f},
		view_scale(1.0f), view_field(45.0f),
		near_clip(0.1f), far_clip(100.0f),
		aspect_ratio(1.3f),
		m_mode(GCM_2D), m_type(GCT_ORTHO),
		m_proj(m4f32(1.0f)), m_view(m4f32(1.0f)) {}
	// --getters
	void gfx_camera::set_mode(gfx_cameraModes camera_mode) {
		m_mode = camera_mode;
		if (camera_mode == GCM_2D) {
		}
		else if (camera_mode == GCM_3D) {
		}
	}
	// --setters
	void gfx_camera::set_type(gfx_cameraTypes camera_type) {
		m_type = camera_type;
		if (camera_type == GCT_ORTHO) {
			near_clip = -100.0f;
			far_clip = 100.0f;
		}
		else if (camera_type == GCT_PERSPECT) {
			near_clip = 0.01f;
			far_clip = 100.0f;
		}
	}
	// --core_methods
	void gfx_camera::update()
	{
		if (m_type == GCT_ORTHO) {
			m_proj = mat_ortho(-view_scale * aspect_ratio,
				view_scale * aspect_ratio, -view_scale, view_scale, near_clip, far_clip);
		}
		else if (m_type == GCT_PERSPECT) {
			m_proj = mat_perspect(deg_to_rad(view_field),
				aspect_ratio, near_clip, far_clip);
		}

		v3f32 next_front_dir = v3f32(0.0f, 0.0f, 0.0f);
		f32 pitch_rad = deg_to_rad(rotation.x);
		f32 yaw_rad = deg_to_rad(rotation.y);
		f32 roll_rad = deg_to_rad(rotation.z);

		if (m_type == GCT_PERSPECT)
		{
			next_front_dir.x = sinf(yaw_rad) * cosf(pitch_rad);
			next_front_dir.y = sinf(pitch_rad);
			next_front_dir.z = cosf(yaw_rad) * cosf(pitch_rad);
		}
		else if (m_type == GCT_ORTHO) {
			next_front_dir.x = cosf(roll_rad);
			next_front_dir.y = sinf(roll_rad);
		}

		front_dir = glm::normalize(next_front_dir);
		right_dir = glm::normalize(glm::cross(front_dir, world_up_dir));
		upper_dir = glm::normalize(glm::cross(right_dir, front_dir));

		m4f32 transformation =
			mat_translate(m4f32(1.0f), coord) *
			mat_rotate(m4f32(1.0f), pitch_rad, v3f32(1.0f, 0.0f, 0.0f)) *
			mat_rotate(m4f32(1.0f), yaw_rad, v3f32(0.0f, 1.0f, 0.0f)) *
			mat_rotate(m4f32(1.0f), roll_rad, v3f32(0.0f, 0.0f, 1.0f));
		m_view = mat_inverse(transformation);
	}
}