#include <glib_pch.hpp>
#include "core/glib_engine.h"

#include <core/glib_api.h>

#include <core/glib_window.h>
#include <glib_framebuf.h>

#include <glib_camera.h>
#include <glib_shader.h>
#include <glib_material.h>
#include <glib_texture.h>

#include <glib_event.h>

#include <stb_image.h>

namespace GLIB
{
	GEngine::GEngine() :
		m_bIsRunning(false),
		m_pGApi(nullptr), m_pWindow(nullptr),
		m_DInfo(GEngineInfo()) { }
	GEngine::~GEngine() {}

	// --setters
	GLayer* GEngine::AddLayer(const char* strName) {
		if (GetLayer(strName) != nullptr) { return nullptr; }
		m_GLayers.push_back(GLayer(strName));
		return &m_GLayers.back();
	}
	void GEngine::RmvLayer(const char* strName) {
		Layers::iterator& itDest = std::find_if(m_GLayers.begin(), m_GLayers.end(),
			[=](GLayer& rObj)->bool {return rObj.strName == strName; });
		if (itDest != m_GLayers.end()) { return; }
		m_GLayers.erase(itDest);
	}
	// --==<core_methods>==--
	bool GEngine::Init(WApiTypes WindowApiType, GApiTypes GraphicsApiType)
	{
		m_bIsRunning = true;

		WindowInfo WindowInfo{ "graphics_engine", 1200, 1200 / 4 * 3, true, nullptr };
		m_pWindow = AWindow::Create(WindowInfo, WindowApiType);
		if (!m_pWindow->Init()) { m_pWindow->OnQuit(); return false; }
		m_pWindow->SetEventCallback([this](AEvent& rEvt)->void {
			if (rEvt.EvtType == ET_MOUSE_PRESS) {
				MouseEvent* pmEvt = static_cast<MouseEvent*>(&rEvt);
				switch (pmEvt->nButton) {
				default: break;
				}
			}
			else if (rEvt.EvtType == ET_MOUSE_RELEASE) {
				MouseEvent* pmEvt = static_cast<MouseEvent*>(&rEvt);
				switch (pmEvt->nButton) {
				default: break;
				}
			}
			else if (rEvt.EvtType == ET_KEY_PRESS) {
				KeyboardEvent* pkEvt = static_cast<KeyboardEvent*>(&rEvt);
				switch (pkEvt->unKeyCode) {
				case GLIB_KEY_ESCAPE_27: Quit(); break;
				default: break;
				}
			}
			else if (rEvt.EvtType == ET_KEY_RELEASE) {
				KeyboardEvent* pkEvt = static_cast<KeyboardEvent*>(&rEvt);
				switch (pkEvt->unKeyCode) {
				default: break;
				}
			}
			else if (rEvt.EvtType == ET_WINDOW_CLOSE) { Quit(); }
			else if (rEvt.EvtType == ET_WINDOW_RESIZE) {
				WindowEvent* pwEvt = static_cast<WindowEvent*>(&rEvt);
			}
			else if (rEvt.EvtType == ET_WINDOW_FOCUS) {
				WindowEvent* pwEvt = static_cast<WindowEvent*>(&rEvt);
				if (pwEvt->bIsFocused) { m_pWindow->SetOpacity(1.0f); }
				else { m_pWindow->SetOpacity(0.95f); }
			}
			});

		m_pGApi = AGApi::Create(GraphicsApiType);
		m_pGApi->SetClearColor(0.1f, 0.2f, 0.3f);

		if (true) {
			AShader::Create("shd_3d_batch")->LoadF("D:/dev/native_world/nw_glib/src_glsl/shd_3d_batch.glsl");
		}
		if (true) {
			ATexture2d::Create("tex_white")->LoadF("");
			ImageInfo imgInfo;
			TextureInfo texInfo;
			if (LoadFImage("D:/dev/native_world/nw_glib/data/ico/nw_bat.png", &imgInfo)) {
				m_pWindow->SetIcon(imgInfo.ClrData, imgInfo.nWidth, imgInfo.nHeight);
				
				ATexture2d::Create("tex_2d_bat");
				texInfo.FilterMag = texInfo.FilterMag = TC_FILTER_NEAREST;
				texInfo.InterFormat= texInfo.Format = TC_FORMAT_RGBA;
				texInfo.WrapTypeS = texInfo.WrapTypeT = TC_WRAP_REPEAT;
				GetGResource<ATexture>("tex_2d_bat")->SetInfo(imgInfo);
				GetGResource<ATexture>("tex_2d_bat")->SetInfo(texInfo);
				GetGResource<ATexture>("tex_2d_bat")->Remake();
				
				delete[] imgInfo.ClrData;
			}
		}
		if (true) {
			new GMaterial("gmt_3d_batch");
			GetGResource<GMaterial>("gmt_3d_batch")->SetShader(GetGResource<AShader>("shd_3d_batch"));
			GetGResource<GMaterial>("gmt_3d_batch")->SetTexture(GetGResource<ATexture>("tex_2d_bat"));
		}
		AddLayer("gel_3d_batch");
		m_GLayer = m_GLayers.begin();
		m_GLayer->SetShader(GetGResource<AShader>("shd_3d_batch"));

		if (!m_bIsRunning) { Quit(); }
		return true;
	}
	void GEngine::Quit()
	{
		if (!m_bIsRunning) { return; }
		m_bIsRunning = false;

		if (true) {
			delete GetGResource<GMaterial>("gmt_3d_batch");
		}
		if (true) {
			delete GetGResource<ATexture>("tex_white");
			delete GetGResource<ATexture>("tex_2d_batch");
		}
		if (true) {
			delete GetGResource<AShader>("shd_3d_batch");
		}
		
		m_GLayers.clear();
		delete m_pGApi;
		m_pWindow->OnQuit();
		delete m_pWindow;
	}
	void GEngine::Run() {
		m_thrRun = std::thread([this]()->void { while (m_bIsRunning) { Update(); } });
	}
	inline void GEngine::Update()
	{
		m_pWindow->Update();

		m_DInfo.Reset();

		std::sort(m_GLayers.begin(), m_GLayers.end());
		for (m_GLayer = m_GLayers.begin(); m_GLayer != m_GLayers.end(); m_GLayer++) {
			m_GLayer->OnDraw(m_pGApi);
			m_DInfo.szShd = m_DInfo.szShd + m_GLayer->szShdData;
			m_DInfo.szVtx = m_DInfo.szVtx + m_GLayer->szVtxData;
			m_DInfo.szIdx = m_DInfo.szIdx + m_GLayer->szIdxData;
			if (m_DInfo.unTex < m_GLayer->unTexCount) { m_DInfo.unTex = m_GLayer->unTexCount; }
			m_DInfo.unDrawCalls += m_GLayer->unDrawCalls;
		}
		m_GLayer = m_GLayers.begin();
	}
	// --==</core_methods>==--

	// --==<data_methods>==--
	bool GEngine::SaveFImage(const char* strFPath, ImageInfo* pImg) {
		return true;
	}
	bool GEngine::LoadFImage(const char* strFPath, ImageInfo* pImg) {
		UByte* pDataTemp = stbi_load(strFPath, &pImg->nWidth, &pImg->nHeight, &pImg->nChannels, 4);
		if (pDataTemp == nullptr) { return false; }
		pImg->ClrData = pDataTemp;
		return true;
	}
	bool GEngine::SaveFShaderCode(const char* strFPath, AShader* pShader)
	{
		return true;
	}
	bool GEngine::LoadFShaderCode(const char* strFPath, AShader* pShader)
	{
		std::stringstream strStream;
		std::fstream fStream;
		fStream.exceptions(std::ios_base::badbit | std::ios_base::failbit);
		try {
			fStream.open(strFPath);
			strStream << fStream.rdbuf();
			pShader->SetCode(&strStream.str()[0]);
			fStream.close();
		}
		catch (std::exception Ex){
			GLIB_ERR(Ex.what());
			return false;
		}
		return true;
	}
	// --==</data_methods>==--
}

/// OnDraw (AShape)
	/// Description:
	/// -- Shapes have a vertex data, indices and bound AGMaterial
	/// -- GEngine collects all the Vertex and Index data into some arrays from given object
	/// -- AGMaterial of the object provides GEngine's AGMaterial with textures
	/// -- Every new texture from new AGMaterial will be bound to the current GMtl
	/// -- In the EndDraw it will bind all owned textures and will set their samplerIDs to the own shader
	/// -- There is also default white texture which will be used if we don not have other textures