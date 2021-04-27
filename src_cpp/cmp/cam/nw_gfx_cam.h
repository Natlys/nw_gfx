#ifndef NW_GFX_LIB_CAMERA_H
#define NW_GFX_LIB_CAMERA_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "../buf/nw_gfx_buf_shd.h"
#	include "../nw_gfx_cmp.h"
#	include "mat/nw_mat_rect.h"
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
		using cam_t = gfx_cam;
		using cam_tc = const cam_t;
		using buf_t = mem_ref<gfx_buf_shd>;
		using buf_tc = const buf_t;
		using mode_t = v1u;
		using mode_tc = const mode_t;
	public:
		gfx_cam();
		virtual ~gfx_cam();
		// --getters
		inline buf_t& get_buf() { return m_buf; }
		inline buf_tc& get_buf() const { return m_buf; }
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
		inline cm4f& get_proj() const { return (*m_buf)["cam_proj"]; }
		inline cm4f& get_view() const { return (*m_buf)["cam_view"]; }
		inline cm4f& get_modl() const { return (*m_buf)["cam_modl"]; }
		inline mode_tc& get_mode() const { return m_mode; }
		// --setters
		cam_t& set_buf(buf_tc& buf);
		cam_t& set_fov(cv1f field_of_view);
		cam_t& set_ratio(cv1f size_x, cv1f size_y);
		cam_t& set_ratio(cv1f aspect_ratio);
		cam_t& set_clips(cv1f near_clip, cv1f far_clip);
		cam_t& set_clips(cv2f& near_and_far);
		cam_t& set_crd(cv3f& coord);
		cam_t& set_rtn(cv3f& rotat);
		cam_t& set_proj(cm4f& proj);
		cam_t& set_view(cm4f& view);
		cam_t& set_modl(cm4f& modl);
		cam_t& set_mode(mode_tc mode);
		// --predicates
		inline v1bit has_crd_x(cv1f coord) const { return m_crd[0] == coord; }
		inline v1bit has_crd_y(cv1f coord) const { return m_crd[1] == coord; }
		inline v1bit has_crd_z(cv1f coord) const { return m_crd[2] == coord; }
		inline v1bit has_crd_xyz(cv3f& coord) const {
			return m_crd[0] == coord[0] && m_crd[1] == coord[1] && m_crd[2] == coord[2];
		}
		inline v1bit has_crd_aabb(cv3f& coord_min, cv3f& coord_max) const {
			if (m_crd[0] >= coord_min[0] && m_crd[0] <= coord_max[0]) { return NW_TRUE; }
			if (m_crd[1] >= coord_min[1] && m_crd[1] <= coord_max[1]) { return NW_TRUE; }
			if (m_crd[2] >= coord_min[2] && m_crd[2] <= coord_max[2]) { return NW_TRUE; }
			return NW_FALSE;
		}
		// --core_methods
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
		static inline cm4f make_lookat(cv3f& view_crd, cv3f& dest_crd, cv3f& upper_dir) {
			v3f axis_z = (dest_crd - view_crd).get_nrm();
			v3f axis_x = axis_z.get_crs(upper_dir).get_nrm();
			v3f axis_y = axis_x.get_crs(axis_z).get_nrm();

			axis_z = -axis_z;
			m4f result;
#		if (NW_FALSE)
			result[0] = v4f{ axis_x[0], axis_x[1], axis_x[2], -v3f::get_dot(axis_x, view_crd) };
			result[1] = v4f{ axis_y[0], axis_y[1], axis_y[2], -v3f::get_dot(axis_y, view_crd) };
			result[2] = v4f{ axis_z[0], axis_z[1], axis_z[2], -v3f::get_dot(axis_z, view_crd) };
			result[3] = v4f{ 0.0f, 0.0f, 0.0f, 1.0f };
#		else
			cv3f origin = { -view_crd.get_dot(axis_x), -view_crd.get_dot(axis_y), -view_crd.get_dot(axis_z) };
			result[0] = v4f{ axis_x[0], axis_y[0], axis_z[0], 0.0f };
			result[1] = v4f{ axis_x[1], axis_y[1], axis_z[1], 0.0f };
			result[2] = v4f{ axis_x[2], axis_y[2], axis_z[2], 0.0f };
			result[3] = v4f{ origin[0], origin[1], origin[2],  1.0f };
#		endif
			
			return result;
		}
		virtual v1nil on_draw() override;
	protected:
		buf_t m_buf;
		v1f m_fov;
		v1f m_ratio;
		v1f m_near, m_far;
		v3f m_crd, m_rtn;
		v3f m_right, m_upper, m_front;
		mode_t m_mode;
	};
}
namespace NW
{
	/// graphics_camera_lad class
	class NW_API gfx_cam_lad : public gfx_cam
	{
	public:
		using lad_t = gfx_cam_lad;
		using lad_tc = const lad_t;
		using keybod_t = iop_keybod_t;
		using keybod_tc = const keybod_t;
		using cursor_t = iop_cursor_t;
		using cursor_tc = const cursor_t;
		using timer_t = time_state;
		using timer_tc = const timer_t;
	public:
		gfx_cam_lad();
		virtual ~gfx_cam_lad();
		// --getters
		inline cv3f get_crd_limit() const { return m_crd_limit; }
		inline cv3f get_rtn_limit() const { return m_rtn_limit; }
		inline cv1f get_crd_speed() const { return m_crd_speed; }
		inline cv1f get_rtn_speed() const { return m_rtn_speed; }
		inline cv1f get_scl_speed() const { return m_rtn_speed; }
		// --setters
		lad_t& set_rtn_limit(cv3f& rotat_limit);
		lad_t& set_crd_limit(cv3f& coord_limit);
		lad_t& set_rtn_speed(cv1f rotat_speed);
		lad_t& set_crd_speed(cv1f coord_speed);
		lad_t& set_scl_speed(cv1f scale_speed);
		// --predicates
		// --core_methods
		v1nil on_draw(keybod_tc* keyboard, cursor_tc* cursor, timer_tc* timer);
		virtual v1nil on_draw() override;
	private:
		v3f m_crd_limit;
		v3f m_rtn_limit;
		v1f m_crd_speed;
		v1f m_rtn_speed;
		v1f m_scl_speed;
	};
}
#endif	// NW_GAPI
#endif // NW_GFX_LIB_CAMERA_H