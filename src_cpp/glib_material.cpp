#include <glib_pch.hpp>
#include "glib_material.h"

#include <glib_engine.h>
#include <glib_buffer.h>
#include <glib_texture.h>
#include <glib_shader.h>

namespace GLIB
{
	GMaterial::GMaterial(const char* strName) :
		TDataRes(strName) { }
	GMaterial::~GMaterial() { }

	// --setters
	void GMaterial::SetShader(Shader* pShader) {
		m_pShader = pShader;
		m_Textures.clear();
		m_Colors.clear();

		if (pShader != nullptr) {
			for (auto& itGlob : pShader->GetShdLayout().GetGlobals()) {
				switch (itGlob.sdType) {
				case SDT_FLOAT32: if (itGlob.unCount == 4) { m_Colors[itGlob.strName] = V4f{ 1.0f, 1.0f, 1.0f, 1.0f }; } break;
				case SDT_SAMPLER: m_Textures[itGlob.strName] = TDataRes<Texture>::GetDataRes("tex_white_solid"); break;
				}
			}
		}
		if (m_Colors.empty()) { m_Colors[""] = V4f{ 1.0f, 1.0f, 1.0f, 1.0f }; }
		if (m_Textures.empty()) { m_Textures[""] = nullptr; }
	}
	void GMaterial::SetTexture(Texture* pTex, const char* strType) {
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
		auto itTex = m_Textures.begin();
		for (UInt8 txi = 0; txi < m_Textures.size(); txi++) {
			itTex->second->Unbind();
			itTex++;
		}
		m_pShader->Disable();
	}

	GMaterial* GMaterial::Create(const char* strName) { return NewT<GMaterial>(GraphEngine::Get().GetMemory(), strName); }
	void GMaterial::Create(const char* strName, RefKeeper<GMaterial>& rgMtl) { rgMtl.MakeRef<GMaterial>(GraphEngine::Get().GetMemory(), strName); }
	// --data_methods
	bool GMaterial::SaveF(const char* strFPath) { return true; }
	bool GMaterial::LoadF(const char* strFPath) { return true; }
}