#ifndef NWG_GCAMERA_H
#define NWG_GCAMERA_H

#include <nwg_core.hpp>

namespace NWG
{
	enum GfxCameraTypes {
		GCT_ORTHO = 0,
		GCT_PERSPECT = 1
	};
	enum GfxCameraModes {
		GCM_2D = 2,
		GCM_3D = 3
	};
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
		union {
			struct {
				float x, y, z;
			} xyzCrd;
			struct {
				float xCrd, yCrd, zCrd;
			};
		};
		union {
			struct {
				float x, y, z;
			}xyzRtn;
			struct {
				float xRtn, yRtn, zRtn;
			};
			struct {
				float nPitch, nYaw, nRoll;
			};
		};

		float nViewField = 45.0f, nViewScale = 1.0f;
		float nAspectRatio = 16.0f / 9.0f;
		float nNearClip = 0.1f, nFarClip = 100.0f;

		V3f dirRight = V3f{ 1.0f, 0.0f, 0.0f },
			dirUp = V3f{ 0.0f, 1.0f, 0.0f },
			dirFront = V3f{ 0.0f, 0.0f, 1.0f },
			dirWorldUp = V3f{ 0.0f, 1.0f, 0.0f };
	public:
		GfxCamera();
		~GfxCamera() = default;

		// --getters
		const Mat4f& GetViewMatrix();
		const Mat4f& GetProjMatrix();
		inline const GfxCameraTypes& GetType() const { return m_gcType; }
		inline const GfxCameraModes& GetMode() const { return m_gcMode; }
		// --setters
		inline void SetType(GfxCameraTypes gcType) {
			m_gcType = gcType;
			if (m_gcType == GCT_ORTHO) {
				nNearClip = -100.0f;
				nFarClip = 100.0f;
			}
			else if (m_gcType == GCT_PERSPECT) {
				nNearClip = 0.01f;
				nFarClip = 1000.0f;
			}
		}
		inline void SetMode(GfxCameraModes gcMode) {
			m_gcMode = gcMode;
			if (m_gcMode == GCM_2D) {
				zCrd = 1.0f;
			} else if (m_gcMode == GCM_2D) {
				zCrd = 1.0f;
			}
		}
	private:
		Mat4f m_m4View, m_m4Proj;

		GfxCameraTypes m_gcType;
		GfxCameraModes m_gcMode;
	};
}
#endif // NWG_GCAMERA_H