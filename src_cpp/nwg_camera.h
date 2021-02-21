#ifndef NWG_GCAMERA_H
#define NWG_GCAMERA_H

#include <nwg_core.hpp>

namespace NWG
{
	/// GraphicsCamera struct
	/// Description:
	/// -- Makes all relevant rotation and movement calculations
	/// -- Makes projection and view-lookAt matricies
	/// Interface:
	/// -> Config Frustrum, tarGet, 
	/// -> Set coordinates and rotation
	/// -> Get transform matricies: proj and view
	struct NWG_API GfxCamera
	{
	public:
		V3f xyzCrd = { 0.0f, 0.0f, 0.0f };
		V3f xyzRtn = { 0.0f, 90.0f, 0.0f };

		V3f dirRight = { 1.0f, 0.0f, 0.0f },
			dirUp = { 0.0f, 1.0f, 0.0f },
			dirFront = { 0.0f, 0.0f, 1.0f },
			dirWorldUp = { 0.0f, 1.0f, 0.0f };

		Float32 nViewField = 45.0f, nViewScale = 1.0f;
		Float32 nAspectRatio = 16.0f / 9.0f;
		Float32 nNearClip = 0.1f, nFarClip = 100.0f;
	public:
		GfxCamera();
		// --getters
		const Mat4f& GetViewMatrix();
		const Mat4f& GetProjMatrix();
		inline const GfxCameraTypes& GetType() const { return m_gcType; }
		inline const GfxCameraModes& GetMode() const { return m_gcMode; }
		// --setters
		void SetType(GfxCameraTypes gcType);
		void SetMode(GfxCameraModes gcMode);
	private:
		Mat4f m_m4View, m_m4Proj;

		GfxCameraTypes m_gcType;
		GfxCameraModes m_gcMode;
	};
}
#endif // NWG_GCAMERA_H