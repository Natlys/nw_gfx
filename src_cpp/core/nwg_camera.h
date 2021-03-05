#ifndef NWG_CAMERA_H
#define NWG_CAMERA_H
#include <nwg_core.hpp>
namespace NWG
{
	enum gfx_cameraTypes : si32 {
		GCT_DEFAULT = 0,
		GCT_ORTHO = 1, GCT_PERSPECT = 2,
	};
	enum gfx_cameraModes : si32 {
		GCM_DEFAULT = 0,
		GCM_2D = 2, GCM_3D = 3,
	};
}
namespace NWG
{
	/// graphics_camera struct
	/// description:
	/// --makes all relevant rotation and movement calculations
	/// --makes projection and view-lookAt matricies
	/// interface:
	/// ->config Frustrum, tarGet, 
	/// ->set coordinates and rotation
	/// ->get transform matricies: proj and view
	struct NWG_API gfx_camera
	{
	public:
		v3f32
			coord = { 0.0f, 0.0f, 0.0f },
			rotation = { 0.0f, 90.0f, 0.0f };
		v3f32
			right_dir = { 1.0f, 0.0f, 0.0f },
			upper_dir = { 0.0f, 1.0f, 0.0f },
			front_dir = { 0.0f, 0.0f, 1.0f },
			world_up_dir = { 0.0f, 1.0f, 0.0f };
		f32 view_field = 45.0f, view_scale = 1.0f;
		f32 aspect_ratio = 16.0f / 9.0f;
		f32 near_clip = 0.1f, far_clip = 100.0f;
	public:
		gfx_camera();
		// --getters
		const m4f32& get_proj_mat()const		{ return m_proj; }
		const m4f32& get_view_mat() const		{ return m_view; }
		inline const gfx_cameraTypes& get_type() const	{ return m_type; }
		inline const gfx_cameraModes& get_mode() const	{ return m_mode; }
		// --setters
		void set_type(gfx_cameraTypes camera_type);
		void set_mode(gfx_cameraModes camera_mode);
		// --core_methods
		void update();
	protected:
		m4f32 m_view, m_proj;
		gfx_cameraTypes m_type;
		gfx_cameraModes m_mode;
	};
}
#endif // NWG_CAMERA_H