#include <nwg_pch.hpp>
#include "nwg_material.h"
#if (defined NWG_GAPI)
#include <nwg_texture.h>
#include <nwg_shader.h>
namespace NWG
{
	GfxMaterial::GfxMaterial(GfxEngine& rGfx, const char* strName) :
		TEntity(), AGfxRes(rGfx), ADataRes(strName) { m_Textures["tex_default"] = RefKeeper<Texture>(); }
	GfxMaterial::GfxMaterial(GfxEngine& rGfx, const char* strName, RefKeeper<ShaderProgram>& rshdProg) :
		TEntity(), AGfxRes(rGfx), ADataRes(strName) { SetShaderProg(rshdProg); }
	GfxMaterial::~GfxMaterial() { }

	// --setters
	void GfxMaterial::SetShaderProg(RefKeeper<ShaderProgram>& rshdProg) {
		m_pshdProg = rshdProg;
		m_Textures.clear();
		m_Colors.clear();

		if (rshdProg.IsValid()) {
			for (auto& itGlob : rshdProg->GetShdLayout().GetBlock().Elems) {
				switch (itGlob.sdType) {
				case DT_FLOAT32: if (itGlob.unCount == 4) { m_Colors[itGlob.strName] = V4f{ 1.0f, 1.0f, 1.0f, 1.0f }; } break;
				case DT_BOOL: m_Textures[itGlob.strName].SetRef<Texture>(EntSys::GetEnts<Texture>()[0]); break;
				}
			}
		}
		if (m_Textures.empty()) { m_Textures["tex_default"] = RefKeeper<Texture>(); }
	}
	void GfxMaterial::SetTexture(RefKeeper<Texture>& rTex, const char* strType) {
		if (!rTex.IsValid()) { return; }
		if (strcmp(strType, "") == 0) { m_Textures.begin()->second.SetRef(rTex); }
		if (m_Textures.find(strType) != m_Textures.end()) { m_Textures[strType].SetRef(rTex); }
		else { }
	}
	void GfxMaterial::SetColor(const V4f& rgbaClr, const char* strType) {
		if (strcmp(strType, "") == 0) { m_Colors.begin()->second = rgbaClr; }
		if (m_Colors.find(strType) == m_Colors.end()) {	m_Colors[strType] = rgbaClr; }
		else { }
	}

	// --core_methods
	void GfxMaterial::Bind()
	{
		m_pshdProg->Bind();
		for (auto itClr : m_Colors) { }
		auto& itTex = m_Textures.begin();
		for (UInt8 txi = 0; txi < m_Textures.size(); txi++) {
			itTex->second->SetSlot(txi);
			itTex->second->Bind();
			itTex++;
		}
	}

	// --data_methods
	bool GfxMaterial::SaveF(const char* strFPath) { return true; }
	bool GfxMaterial::LoadF(const char* strFPath) { return true; }
}
#endif	// NWG_GAPI