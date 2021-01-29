#include <glib_pch.hpp>
#include "glib_engine.h"

#include <glib_api.h>

#include <glib_tools.h>
#include <glib_framebuf.h>

#include <glib_camera.h>
#include <glib_shader.h>
#include <glib_material.h>
#include <glib_texture.h>

#include <stb_image.h>

#include <../src_glsl/shd_screen.hpp>

namespace GLIB
{
	GEngine::GEngine() :
		m_Memory(MemArena(nullptr, 0)), m_thrRun(Thread()), m_bIsRunning(false),
		m_pGApi(RefOwner<AGApi>(GetMemory())), m_pGMtlScreen(nullptr),
		m_DInfo(DrawerInfo()) { }
	GEngine::~GEngine() { }

	// --setters
	// --==<core_methods>==--
	bool GEngine::Init(Size szMemory)
	{
		if (m_bIsRunning) { return false; }
		GetMemory() = MemArena(new Byte[szMemory], szMemory);

	#if (defined GLIB_GAPI)
		#if (GLIB_GAPI & GLIB_GAPI_OGL)
		m_gapiType = GAPI_OPENGL;
		#endif
	#endif
		AGApi::Create(m_pGApi);
		if (!m_pGApi->Init()) { Quit(); return false; }

		return (m_bIsRunning = true);
	}
	void GEngine::Quit()
	{
		if (!m_bIsRunning) { return; }
		m_bIsRunning = false;

		m_pGApi->OnQuit();
		m_pGApi.Reset();

		delete[] GetMemory().GetDataBeg();
		GetMemory() = MemArena(nullptr, 0);
	}
	void GEngine::Run(Size szMemory) {
		if (!Init(szMemory)) { return; }
		auto& fnUpdate = [this]()->void {
			while (m_bIsRunning) { Update(); }
			Quit();
		};
		m_thrRun = Thread(fnUpdate);
	}
	void GEngine::Update()
	{
		m_DInfo.Reset();
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
		StrStream strStream;
		IOFStream fStream;
		fStream.exceptions(std::ios_base::badbit | std::ios_base::failbit);
		try {
			fStream.open(strFPath);
			strStream << fStream.rdbuf();
			pShader->SetCode(&strStream.str()[0]);
			fStream.close();
		}
		catch (std::exception Ex){
			NWL_ERR(Ex.what());
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