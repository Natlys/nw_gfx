#ifndef GFX_CAMERA_LAD_H
#define GFX_CAMERA_LAD_H

#include <nwg_core.hpp>
#include <nwg_camera.h>

namespace NWG
{
	/// GraphicsCameraLad Singleton class
	/// Interface:
	/// -> Get static instance -> set current camera -> configure if it's required
	/// -> Update every frame with the set camera -> Dispatch events to GfxCameraLad
	class NWG_API GfxCameraLad
	{
	public: // Configurable Attributes
		float nRtnSpeed, nMoveSpeed, nZoomSpeed;

		Float64 nMaxYaw = 360.0f;
		Float64 nMaxPitch = 90.0f;
		Float64 nMaxRoll = 0.0f;

		V2f whBounds = V2f{ 0.0f, 0.0f };
	private:
		GfxCameraLad();
		GfxCameraLad(const GfxCameraLad& rCpy) = delete;
	public:
		~GfxCameraLad();
		// --getters
		static inline GfxCameraLad& Get() { static GfxCameraLad s_Lad; return s_Lad; }
		inline GfxCamera* GetGfxCamera() { return &m_gCamera; }
		// --setters
		inline void SetKeyboard(Keyboard* pKeyboard) { m_kbd = pKeyboard; }
		inline void SetCursor(Cursor* pCursor) { m_crs = pCursor; }
		// --operators
		void operator=(const GfxCameraLad& rCpy) = delete;
		// --core_methods
		void UpdateCamera(GfxCamera& rCamera);
		inline void UpdateCamera() { UpdateCamera(m_gCamera); }
		void OnEvent(CursorEvent& rcEvt, GfxCamera& rCamera);
		void OnEvent(KeyboardEvent& rkEvt, GfxCamera& rCamera);
		void OnEvent(WindowEvent& rwEvt, GfxCamera& rCamera);
		inline void OnEvent(CursorEvent& rcEvt) { OnEvent(rcEvt, m_gCamera); }
		inline void OnEvent(KeyboardEvent& rkEvt) { OnEvent(rkEvt, m_gCamera); }
		inline void OnEvent(WindowEvent& rwEvt) { OnEvent(rwEvt, m_gCamera); }
	private:
		GfxCamera m_gCamera;
		Keyboard* m_kbd = nullptr;
		Cursor* m_crs = nullptr;
	};
}

#endif	// GFX_CAMERA_LAD_H