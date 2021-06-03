#ifndef NC_GFX_TRANSFORM_CAMERA_H
#define NC_GFX_TRANSFORM_CAMERA_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "nc_gfx_tform.hxx"
#	define NC_CAMERA_2D   1 << 1
#	define NC_CAMERA_3D   1 << 2
#	define NC_CAMERA      NC_CAMERA_2D
namespace NC
{
	/// graphics_transform_camera class
	/// description:
	/// --makes all relevant rotation and movement calculations
	/// --makes projection and view-lookAt matricies
	/// interaction:
	/// ->config Frustrum, tarGet, 
	/// ->set coordinates and rotation
	/// ->get transform matricies: proj and view
	class gfx_tform_cam : public gfx_tform
	{
	public:
		using cam_t = gfx_tform_cam;
		using cam_tc = const cam_t;
		using nc_keybod_t = nc_keybod_t;
		using keybod_tc = const nc_keybod_t;
		using cursor_t = nc_cursor_t;
		using cursor_tc = const cursor_t;
		using timer_tc = const timer_t;
		using mode_t = v1u_t;
		using mode_tc = const mode_t;
	public:
		/* ctor_dtor */
		gfx_tform_cam();
		gfx_tform_cam(cam_tc& copy);
		gfx_tform_cam(cam_t&& copy);
		virtual ~gfx_tform_cam();
		/* getters */
		// // --projection
		inline v1f_tc get_fov() const { return m_fov; }
		inline v1f_tc get_ratio() const { return m_ratio; }
		inline v1f_tc get_near() const  { return m_near; }
		inline v1f_tc get_far() const   { return m_far; }
		// // --orientation
		inline v3f_t get_right_dir(v1f_t scalar = 1.0f) const { return v3f_t{ -m_right[0], +m_right[1], -m_right[2] } * scalar; }
		inline v3f_t get_upper_dir(v1f_t scalar = 1.0f) const { return v3f_t{ -m_upper[0], +m_upper[1], -m_upper[2] } * scalar; }
		inline v3f_t get_front_dir(v1f_t scalar = 1.0f) const { return v3f_t{ -m_front[0], +m_front[1], -m_front[2] } * scalar; }
		inline v3f_t get_right_crd(v1f_t scalar = 1.0f) const { return m_right * -scalar + m_crd; }
		inline v3f_t get_upper_crd(v1f_t scalar = 1.0f) const { return m_upper * -scalar + m_crd; }
		inline v3f_t get_front_crd(v1f_t scalar = 1.0f) const { return get_front_dir(scalar) + m_crd; }
		// // --transform
		inline cm4x4f& get_view() const { return get_elem("view").get<m4x4f>(); }
		inline cm4x4f& get_proj() const { return get_elem("proj").get<m4x4f>(); }
		// // --configuration
		inline mode_tc& get_mode() const { return m_mode; }
		/* setters */
		// // --projection
		cam_t& set_fov(v1f_tc field_of_view);
		cam_t& set_ratio(v1f_tc size_x, v1f_tc size_y);
		cam_t& set_ratio(v1f_tc aspect_ratio);
		cam_t& set_clips(v1f_tc near_clip, v1f_tc far_clip);
		cam_t& set_clips(cv2f& near_and_far);
		// // --transform
		cam_t& set_view(cm4x4f& view);
		cam_t& set_proj(cm4x4f& proj);
		// // --configuration
		cam_t& set_mode(mode_tc mode);
		/* vetters */
		/* operators */
		inline cam_t& operator=(cam_tc& copy) { NC_CHECK(remake(), "remake error!", return *this); return *this; }
		inline cam_t& operator=(cam_t&& copy) { NC_CHECK(remake(), "remake error!", return *this); return *this; }
		/* commands */
		v1nil_t update(keybod_tc* keyboard, cursor_tc* cursor, timer_tc* timer);
		virtual v1bit_t remake() override;
		virtual v1nil_t on_draw() override;
	protected:
		// --projection
		v1f_t m_fov;
		v1f_t m_ratio;
		v1f_t m_near, m_far;
		// --orientation
		v3f_t m_right;
		v3f_t m_upper;
		v3f_t m_front;
		// --configuration
		mode_t m_mode;
	};
}
#endif	// NC_GAPI
#endif // NC_GFX_TRANSFORM_CAMERA_H