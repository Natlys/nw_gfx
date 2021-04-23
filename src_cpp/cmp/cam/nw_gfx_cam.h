#ifndef NW_GFX_LIB_CAMERA_H
#define NW_GFX_LIB_CAMERA_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "../nw_gfx_cmp.h"
#	define NW_CAMERA_2D   1 << 1
#	define NW_CAMERA_3D   1 << 2
#	define NW_CAMERA      NW_CAMERA_2D
namespace NW
{
	/// graphics_camera class
	/// description:
	/// --makes all relevant rotation and movement calculations
	/// --makes projection and view-lookAt matricies
	/// interface:
	/// ->config Frustrum, tarGet, 
	/// ->set coordinates and rotation
	/// ->get transform matricies: proj and view
	class NW_API gfx_cam : public t_cmp<gfx_cam>, public a_gfx_cmp
	{
	public:
		using mode_t = venum;
		using mode_tc = const mode_t;
	public:
		gfx_cam();
		// --getters
		inline v1f get_fov() const   { return m_fov; }
		inline v1f get_ratio() const { return m_ratio; }
		inline v1f get_near() const  { return m_near; }
		inline v1f get_far() const   { return m_far; }
		inline v3f get_crd() const   { return m_crd; }
		inline v3f get_rtn() const   { return m_rtn; }
		inline v3f get_right_dir(v1f scalar = 1.0f) const { return v3f{ -m_right[0], +m_right[1], -m_right[2] } * scalar; }
		inline v3f get_upper_dir(v1f scalar = 1.0f) const { return v3f{ -m_upper[0], +m_upper[1], -m_upper[2] } * scalar; }
		inline v3f get_front_dir(v1f scalar = 1.0f) const { return v3f{ -m_front[0], +m_front[1], -m_front[2] } * scalar; }
		inline v3f get_right_crd(v1f scalar = 1.0f) const { return m_right * -scalar + m_crd; }
		inline v3f get_upper_crd(v1f scalar = 1.0f) const { return m_upper * -scalar + m_crd; }
		inline v3f get_front_crd(v1f scalar = 1.0f) const { return get_front_dir(scalar) + m_crd; }
		inline const m4f& get_proj() const  { return m_proj; }
		inline const m4f& get_view() const  { return m_view; }
		inline const m4f& get_tform() const { return m_tform; }
		inline mode_tc& get_mode() const { return m_mode; }
		static inline cm4f make_ortho(cv1f znear, cv1f zfar, cv1f ratio, cv1f fov) {
			v1f lft = -fov * ratio / 2.0f;
			v1f rht = +fov * ratio / 2.0f;
			v1f bot = -fov / 2.0f;
			v1f top = +fov / 2.0f;
			m4f result(0.0f);
			result[0][0] = +2.0f / (rht - lft);
			result[0][3] = (rht + lft) / (lft - rht);
			result[1][1] = +2.0f / (top - bot);
			result[1][3] = (top + bot) / (bot - top);
			result[2][2] = -2.0f / (zfar - znear);
			result[2][3] = -(zfar + znear) / (zfar - znear);
			result[3][3] = 1.0f;
			return result;
		}
		static inline cm4f make_persp(cv1f znear, cv1f zfar, cv1f ratio, cv1f fov) {
			m4f result(0.0f);
			v1f fov_tan = NW_MATH_TANG(fov / 2.0f);
			result[0][0] = 1.0f / (fov_tan * ratio);
			result[1][1] = 1.0f / (fov_tan);
			result[2][2] = -(zfar + znear) / (zfar - znear);
			result[2][3] = -1.0f;
			result[3][2] = -(2.0f * zfar * znear) / (zfar - znear);
			return result;
		}
		static inline cm4f make_lookat(cv3f& view_crd, cv3f& dest_crd, cv3f upper_dir) {
			v3f axis_z = v3f::make_norm(dest_crd - view_crd);
			v3f axis_x = v3f::make_norm(v3f::make_cross(axis_z, upper_dir));
			v3f axis_y = v3f::make_norm(v3f::make_cross(axis_x, axis_z));

			axis_z = -axis_z;
			m4f result;
#		if (NW_FALSE)
			result[0] = v4f{ axis_x[0], axis_x[1], axis_x[2], -v3f::get_dot(axis_x, view_crd) };
			result[1] = v4f{ axis_y[0], axis_y[1], axis_y[2], -v3f::get_dot(axis_y, view_crd) };
			result[2] = v4f{ axis_z[0], axis_z[1], axis_z[2], -v3f::get_dot(axis_z, view_crd) };
			result[3] = v4f{ 0.0f, 0.0f, 0.0f, 1.0f };
#		else
			cv3f origin = { -v3f::get_dot(axis_x, view_crd), -v3f::get_dot(axis_y, view_crd), -v3f::get_dot(axis_z, view_crd) };
			result[0] = v4f{ axis_x[0], axis_y[0], axis_z[0], 0.0f };
			result[1] = v4f{ axis_x[1], axis_y[1], axis_z[1], 0.0f };
			result[2] = v4f{ axis_x[2], axis_y[2], axis_z[2], 0.0f };
			result[3] = v4f{ origin[0], origin[1], origin[2],  1.0f };
#		endif
			
			return result;
		}
		// --setters
		v1nil set_fov(cv1f field_of_view);
		v1nil set_ratio(cv1f size_x, cv1f size_y);
		v1nil set_ratio(cv1f aspect_ratio);
		v1nil set_clips(cv1f near_clip, cv1f far_clip);
		v1nil set_clips(cv2f& near_and_far);
		v1nil set_crd(cv3f& coord);
		v1nil set_rtn(cv3f& rotation);
		v1nil set_mode(mode_tc mode);
		// --core_methods
		virtual v1nil on_draw() override;
	protected:
		v1f m_fov;
		v1f m_ratio;
		v1f m_near, m_far;
		v3f m_crd, m_rtn;
		v3f m_right, m_upper, m_front;
		m4f m_tform, m_view, m_proj;
		mode_t m_mode;
	};
}
namespace NW
{
	/// graphics_camera_lad class
	class NW_API gfx_cam_lad : public gfx_cam
	{
	public:
		using keybod_t = iop_keybod_t;
		using keybod_tc = const keybod_t;
		using cursor_t = iop_cursor_t;
		using cursor_tc = const cursor_t;
		using timer_t = time_state;
		using timer_tc = const timer_t;
	public:
		v3f m_rtn_limit;
		v1f m_rtn_speed;
		v1f m_move_speed;
		v1f m_zoom_speed;
	public:
		gfx_cam_lad();
		// --core_methods
		v1nil on_draw(keybod_tc* keyboard, cursor_tc* cursor, timer_tc* timer);
		virtual v1nil on_draw() override;
	};
}
#endif	// NW_GAPI
#endif // NW_GFX_LIB_CAMERA_H