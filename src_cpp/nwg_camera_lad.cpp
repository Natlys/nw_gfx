#include <nwg_pch.hpp>
#include "nwg_camera_lad.h"

namespace NWG
{
	GfxCameraLad::GfxCameraLad() :
		nZoomSpeed(1000.0f),
		nMoveSpeed(2.0f),
		nRtnSpeed(200.0f),
		whBounds{ 800.0f, 600.0f },
		m_kbd(nullptr), m_crs(nullptr) { }
	GfxCameraLad::~GfxCameraLad() = default;

	// --==<core_methods>==--
	void GfxCameraLad::UpdateCamera(GfxCamera& rCamera)
	{
		rCamera.nAspectRatio = whBounds.x / whBounds.y;
		if (!(m_crs->GetMode() & CRS_CAPTURED)) { return; }
		float MoveSpeed = this->nMoveSpeed * TimeSys::GetDeltaS();
		if (rCamera.GetMode() == GCM_2D)
		{
			if (m_kbd->GetHeld(KC_W)) { rCamera.xyzCrd.y += MoveSpeed; }
			if (m_kbd->GetHeld(KC_S)) { rCamera.xyzCrd.y -= MoveSpeed; }
			if (m_kbd->GetHeld(KC_D)) { rCamera.xyzCrd.x += MoveSpeed; }
			if (m_kbd->GetHeld(KC_A)) { rCamera.xyzCrd.x -= MoveSpeed; }
		}
		else if (rCamera.GetMode() == GCM_3D) {
			MoveSpeed = -MoveSpeed;
			if (m_kbd->GetHeld(KC_W)) {	// Move Forward
				rCamera.xyzCrd.x += rCamera.dirFront.x * MoveSpeed;
				//rCamera.yCrd += rCamera.dirFront.y * MoveSpeed;
				rCamera.xyzCrd.z += rCamera.dirFront.z * MoveSpeed;
			}
			if (m_kbd->GetHeld(KC_S)) {	// Move Back
				rCamera.xyzCrd.x -= rCamera.dirFront.x * MoveSpeed;
				//rCamera.yCrd -= rCamera.dirFront.y * MoveSpeed;
				rCamera.xyzCrd.z -= rCamera.dirFront.z * MoveSpeed; } if (m_kbd->GetHeld(KC_D)) { rCamera.xyzCrd += rCamera.dirRight * MoveSpeed; }
			if (m_kbd->GetHeld(KC_A)) { rCamera.xyzCrd -= rCamera.dirRight * MoveSpeed; }
			if (m_kbd->GetHeld(KC_SPACE)) { rCamera.xyzCrd -= MoveSpeed; }
			if (m_kbd->GetHeld(KC_LSHIFT)) { rCamera.xyzCrd += MoveSpeed; }
		}
	}
	// --==</core_methods>==--

	// --==<--on_event_methods>==--
	void GfxCameraLad::OnEvent(CursorEvent& rcEvt, GfxCamera& rCamera)
	{
		if (!(m_crs->GetMode() & CRS_CAPTURED)) { return; }
		switch (rcEvt.evType) {
		case EVT_CURSOR_MOVE:
			if (rCamera.GetMode() == GCM_2D) {
				if (m_crs->GetHeld(CRS_RIGHT)) {
					rCamera.xyzCrd.x += -m_crs->GetMoveDeltaX() * TimeSys::GetDeltaS() * nMoveSpeed;
					rCamera.xyzCrd.y += m_crs->GetMoveDeltaY() * TimeSys::GetDeltaS() * nMoveSpeed;
				}
				float nRoll_deg = rCamera.xyzRtn.z + m_crs->GetMoveDeltaX() * nRtnSpeed * TimeSys::GetDeltaS();
				if (nRoll_deg < -nMaxRoll) { rCamera.xyzRtn.z = nMaxRoll; }
				else if (nRoll_deg > nMaxRoll) { rCamera.xyzRtn.z = -nMaxRoll; }
				else { rCamera.xyzRtn.z = nRoll_deg; }
			}
			else if (rCamera.GetMode() == GCM_3D) {
				float nYaw_deg = rCamera.xyzRtn.y - m_crs->GetMoveDeltaX() * nRtnSpeed * TimeSys::GetDeltaS();
				float nPitch_deg = rCamera.xyzRtn.x - static_cast<Float32>(m_crs->GetMoveDeltaY()) * nRtnSpeed * TimeSys::GetDeltaS();

				if (nYaw_deg < -nMaxYaw) { rCamera.xyzRtn.y = nMaxYaw; }
				else if (nYaw_deg > nMaxYaw) { rCamera.xyzRtn.y = -nMaxYaw; }
				else { rCamera.xyzRtn.y = nYaw_deg; }

				if (nPitch_deg > nMaxPitch) { rCamera.xyzRtn.x = nMaxPitch; }
				else if (nPitch_deg < -nMaxPitch) { rCamera.xyzRtn.x = -nMaxPitch; }
				else { rCamera.xyzRtn.x = nPitch_deg; }
			}
			break;
		case EVT_CURSOR_SCROLL:
			if (!(m_crs->GetMode() & CRS_CAPTURED)) return;
			float nZoom = -rcEvt.nY * nZoomSpeed * TimeSys::GetDeltaS();
			if (rCamera.GetType() == GCT_ORTHO) {
				float nScale = rCamera.nViewScale + nZoom * rCamera.nViewScale / 40.0f + 0.01f;
				if (nScale > 0.0f) rCamera.nViewScale = nScale;
			}
			else if (rCamera.GetType() == GCT_PERSPECT) {
				float nViewField = rCamera.nViewField + nZoom;
				if (nViewField >= 0.01f && nViewField <= 180.0f) rCamera.nViewField = nViewField;
			}
			break;
		}
	}
	void GfxCameraLad::OnEvent(KeyboardEvent& rkEvt, GfxCamera& rCamera)
	{
		if (!(m_crs->GetMode() & CRS_CAPTURED)) { return; }
		switch (rkEvt.evType) {
		case EVT_KEYBOARD_RELEASE:
			switch (rkEvt.keyCode) {
			case KC_0: rCamera = GfxCamera(); break;
			case KC_2: rCamera.SetMode(GCM_2D); rCamera.SetType(GCT_ORTHO); break;
			case KC_3: rCamera.SetMode(GCM_3D); rCamera.SetType(GCT_PERSPECT); break;
			default: break;
			}
			break;
		}
	}
	void GfxCameraLad::OnEvent(WindowEvent& rwEvt, GfxCamera& rCamera)
	{
		switch (rwEvt.evType) {
		case EVT_WINDOW_RESIZE:
			whBounds = V2f{ rwEvt.nX, rwEvt.nY };
			break;
		}
	}
	// --==</--on_event_methods>==--
}