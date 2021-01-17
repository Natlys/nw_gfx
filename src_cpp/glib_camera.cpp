#include <glib_pch.hpp>
#include "glib_camera.h"

namespace GLIB
{
	GCamera::GCamera() :
		xyzCrd{ 0.0f, 0.0f, 1.0f }, xyzRtn{ 0.0f, 0.0f, 0.0f },
		nViewScale(1.0f), nViewField(45.0f), nAspectRatio(1.3f),
		dirRight{ 1.0f, 0.0f, 0.0f }, dirUp{ 0.0f, 1.0f, 0.0f }, dirFront{0.0f, 0.0f, 1.0f},
		dirWorldUp{0.0f, 1.0f, 0.0f},
		m_gcMode(GCM_2D), m_gcType(GCT_ORTHO),
		m_m4Proj(Mat4f{ 1.0f }), m_m4View(Mat4f{ 1.0f }) {}

	// --getters
	const Mat4f& GCamera::GetProjMatrix()
	{
		if (m_gcType == GCT_ORTHO) {
			m_m4Proj = glm::ortho(-nViewScale * nAspectRatio,
				nViewScale * nAspectRatio, -nViewScale, nViewScale,
				-nNearClip, nFarClip);
		} else if (m_gcType == GCT_PERSPECT) {
			m_m4Proj = glm::perspective((nViewField * 3.14f / 180.0f),
				nAspectRatio, nNearClip, nFarClip);
		}
		return m_m4Proj;
	}

	const Mat4f& GCamera::GetViewMatrix()
	{
		V3f xyzNextFront = V3f(0.0f, 0.0f, 0.0f);
		float nPitch_rad = (nPitch) * 3.14f / 180.0f;
		float nYaw_rad = (nYaw) * 3.14f / 180.0f;
		float nRoll_rad = (nRoll) * 3.14f / 180.0f;
		
		if (m_gcType == GCT_PERSPECT)
		{
			xyzNextFront.x = sinf(nYaw_rad) * cosf(nPitch_rad);
			xyzNextFront.y = sinf(nPitch_rad);
			xyzNextFront.z = cosf(nYaw_rad) * cosf(nPitch_rad);
		} else if (m_gcType == GCT_ORTHO) {
			xyzNextFront.x = cosf(nRoll_rad);
			xyzNextFront.y = sinf(nRoll_rad);
		}

		dirFront = glm::normalize(xyzNextFront);
		dirRight = glm::normalize(glm::cross(dirFront, dirWorldUp));
		dirUp = glm::normalize(glm::cross(dirRight, dirFront));

		Mat4f m4Transform = glm::translate(Mat4f(1.0f), V3f{ xCrd, yCrd, zCrd }) *
			glm::rotate(Mat4f(1.0f), nYaw_rad, V3f(0.0f, 1.0f, 0.0f)) *
			glm::rotate(Mat4f(1.0f), nPitch_rad, V3f(1.0f, 0.0f, 0.0f)) *
			glm::rotate(Mat4f(1.0f), nRoll_rad, V3f(0.0f, 0.0f, 1.0f));
		m_m4View = glm::inverse(m4Transform);
		return m_m4View;
	}
}