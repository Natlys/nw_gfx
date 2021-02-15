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
			if (m_kbd->GetHeld(KC_W)) {
				rCamera.yCrd += MoveSpeed;
			}
			if (m_kbd->GetHeld(KC_S)) {
				rCamera.yCrd -= MoveSpeed;
			}
			if (m_kbd->GetHeld(KC_D)) {
				rCamera.xCrd += MoveSpeed;
			}
			if (m_kbd->GetHeld(KC_A))
				rCamera.xCrd -= MoveSpeed;
		}
		else if (rCamera.GetMode() == GCM_3D) {
			MoveSpeed = -MoveSpeed;
			if (m_kbd->GetHeld(KC_W)) {	// Move Forward
				rCamera.xCrd += rCamera.dirFront.x * MoveSpeed;
				//rCamera.yCrd += rCamera.dirFront.y * MoveSpeed;
				rCamera.zCrd += rCamera.dirFront.z * MoveSpeed;
			} if (m_kbd->GetHeld(KC_S)) {	// Move Back
				rCamera.xCrd -= rCamera.dirFront.x * MoveSpeed;
				//rCamera.yCrd -= rCamera.dirFront.y * MoveSpeed;
				rCamera.zCrd -= rCamera.dirFront.z * MoveSpeed;
			} if (m_kbd->GetHeld(KC_D)) {	// Move Right
				rCamera.xCrd += rCamera.dirRight.x * MoveSpeed;
				rCamera.yCrd += rCamera.dirRight.y * MoveSpeed;
				rCamera.zCrd += rCamera.dirRight.z * MoveSpeed;
			} if (m_kbd->GetHeld(KC_A)) {	// Move Left
				rCamera.xCrd -= rCamera.dirRight.x * MoveSpeed;
				rCamera.yCrd -= rCamera.dirRight.y * MoveSpeed;
				rCamera.zCrd -= rCamera.dirRight.z * MoveSpeed;
			} if (m_kbd->GetHeld(KC_SPACE)) {		// Move Up
				rCamera.yCrd -= MoveSpeed;
			} if (m_kbd->GetHeld(KC_LSHIFT)) {	// Move Down
				rCamera.yCrd += MoveSpeed;
			}
		}
	}
	// --==</core_methods>==--

	// --==<--on_event_methods>==--
	void GfxCameraLad::OnEvent(CursorEvent& rcEvt, GfxCamera& rCamera)
	{
		if (!(m_crs->GetMode() & CRS_CAPTURED)) { return; }
		switch (rcEvt.evType) {
		case ET_CURSOR_MOVE:
			if (rCamera.GetMode() == GCM_2D) {
				if (m_crs->GetHeld(CRS_RIGHT)) {
					rCamera.xyzCrd.x += -m_crs->GetMoveDeltaX() * TimeSys::GetDeltaS() * nMoveSpeed;
					rCamera.xyzCrd.y += m_crs->GetMoveDeltaY() * TimeSys::GetDeltaS() * nMoveSpeed;
				}
				float nRoll_deg = rCamera.nRoll + m_crs->GetMoveDeltaX() * nRtnSpeed * TimeSys::GetDeltaS();
				if (nRoll_deg < -nMaxRoll) { rCamera.nRoll = nMaxRoll; }
				else if (nRoll_deg > nMaxRoll) { rCamera.nRoll = -nMaxRoll; }
				else { rCamera.nRoll = nRoll_deg; }
			}
			else if (rCamera.GetMode() == GCM_3D) {
				float nYaw_deg = rCamera.nYaw - m_crs->GetMoveDeltaX() * nRtnSpeed * TimeSys::GetDeltaS();
				float nPitch_deg = rCamera.nPitch - m_crs->GetMoveDeltaY() * nRtnSpeed * TimeSys::GetDeltaS();

				if (nYaw_deg < -nMaxYaw) { rCamera.nYaw = nMaxYaw; }
				else if (nYaw_deg > nMaxYaw) { rCamera.nYaw = -nMaxYaw; }
				else { rCamera.nYaw = nYaw_deg; }

				if (nPitch_deg > nMaxPitch) { rCamera.nPitch = nMaxPitch; }
				else if (nPitch_deg < -nMaxPitch) { rCamera.nPitch = -nMaxPitch; }
				else { rCamera.nPitch = nPitch_deg; }
			}
			break;
		case ET_CURSOR_SCROLL:
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
		if (m_kbd->GetHeld(KC_LCTRL)) {
			if (m_kbd->GetHeld(KC_C)) {
				if (m_kbd->GetHeld(KC_0)) { rCamera = GfxCamera(); }
				else if (m_kbd->GetHeld(KC_2)) { rCamera.SetMode(GCM_2D); rCamera.SetType(GCT_ORTHO); }
				else if (m_kbd->GetHeld(KC_3)) { rCamera.SetMode(GCM_3D); rCamera.SetType(GCT_PERSPECT); }
			}
		}
		switch (rkEvt.evType) {
		case ET_KEYBOARD_RELEASE:
			switch (rkEvt.keyCode) {
			case KC_0:
				break;
			default: break;
			}
			break;
		}
	}
	void GfxCameraLad::OnEvent(WindowEvent& rwEvt, GfxCamera& rCamera)
	{
		switch (rwEvt.evType) {
		case ET_WINDOW_RESIZE:
			whBounds = V2f{ rwEvt.nX, rwEvt.nY };
			break;
		}
	}
	// --==</--on_event_methods>==--
}