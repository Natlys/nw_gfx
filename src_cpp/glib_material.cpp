#include <glib_pch.hpp>
#include "glib_material.h"

#include <core/glib_engine.h>

#include <glib_buffer.h>
#include <glib_texture.h>
#include <glib_shader.h>

namespace GLIB
{
	GMaterial::GMaterial(const char* strName) :
		AGRes(strName) { GEngine::Get().AddGRes<GMaterial>(this); }
	GMaterial::GMaterial(GMaterial& rCpy) :
		GMaterial(&rCpy.m_strName[0]) { }
	GMaterial::~GMaterial() { GEngine::Get().RmvGRes<GMaterial>(GetId()); }

	// --setters
	void GMaterial::SetShader(AShader* pShader) {
		m_pShader = pShader;
		m_Textures.clear();
		m_Colors.clear();

		if (pShader != nullptr) {
			for (auto& itGlob : pShader->GetShdLayout().GetGlobals()) {
				switch (itGlob.sdType) {
				case SDT_FLOAT32: if (itGlob.unCount == 4) { m_Colors[itGlob.strName] = V4f{ 1.0f, 1.0f, 1.0f, 1.0f }; } break;
				case SDT_SAMPLER: m_Textures[itGlob.strName] = GEngine::Get().GetGResource<ATexture>("tex_white"); break;
				}
			}
		}
		if (m_Colors.empty()) { m_Colors[""] = V4f{ 1.0f, 1.0f, 1.0f, 1.0f }; }
		if (m_Textures.empty()) { m_Textures[""] = nullptr; }
	}
	void GMaterial::SetTexture(ATexture* pTex, const char* strType) {
		if (pTex == nullptr) { return; }
		if (strcmp(strType, "") == 0) { m_Textures.begin()->second = pTex; }
		if (m_Textures.find(strType) != m_Textures.end()) { m_Textures[strType] = pTex; }
		else { m_pShader->SetInt(strType, pTex->GetTexSlot()); }
	}
	void GMaterial::SetColor(const V4f& rgbaClr, const char* strType) {
		if (strcmp(strType, "") == 0) { m_Colors.begin()->second = rgbaClr; }
		if (m_Colors.find(strType) == m_Colors.end()) {	m_Colors[strType] = rgbaClr; }
		else { m_pShader->SetV4f(strType, rgbaClr); }
	}

	// --core_methods
	void GMaterial::Enable()
	{
		m_pShader->Enable();
		for (auto itClr : m_Colors) { m_pShader->SetV4f(&itClr.first[0], itClr.second); }
		auto itTex = m_Textures.begin();
		for (UInt8 txi = 0; txi < m_Textures.size(); txi++) {
			itTex->second->Bind(txi);
			m_pShader->SetInt(&itTex->first[0], itTex->second->GetTexSlot());
			itTex++;
		}
	}
	void GMaterial::Disable()
	{
		m_pShader->Disable();
	}
	// --data_methods
	bool GMaterial::SaveF(const char* strFPath) { return true; }
	bool GMaterial::LoadF(const char* strFPath) { return true; }
}