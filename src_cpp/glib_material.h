#ifndef GLIB_GMATERIAL_H
#define GLIB_GMATERIAL_H

#include <glib_tools.h>
#include <glib_core.hpp>

namespace GLIB
{
	/// GraphicsMaterial Class
	class GLIB_API GMaterial : public ADataRes
	{
	public:
		using Textures = HashMap<String, ATexture*>;
		using Colors = HashMap<String, V4f>;
	public:
		GMaterial(const char* strName);
		virtual ~GMaterial();

		// --getters
		inline AShader* GetShader() { return m_pShader; }
		inline UInt8 GetTexCount() { return m_Textures.size(); }
		inline Textures& GetTextures() { return m_Textures; }
		inline Colors& GetColors() { return m_Colors; }
		inline ATexture* GetTexture(const char* strType = "") {
			if (strcmp(strType, "") == 0) { return m_Textures.begin()->second; }
			auto itTex = m_Textures.find(&strType[0]);
			return itTex == m_Textures.end() ? nullptr : itTex->second;
		}
		inline V4f* GetColor(const char* strType = "") {
			if (strcmp(strType, "") == 0) { return &m_Colors.begin()->second; }
			auto itClr = m_Colors.find(&strType[0]);
			return itClr == m_Colors.end() ? nullptr : &itClr->second;
		}
		// --setters
		void SetShader(AShader* pShader);
		void SetTexture(ATexture* pTex, const char* strType = "");
		void SetColor(const V4f& rgbaClr, const char* strType = "");
		// --core_methods
		void Enable();
		void Disable();
		// --data_methods
		virtual bool SaveF(const char* strFPath) override;
		virtual bool LoadF(const char* strFPath) override;
	private:
		String m_strName;
		AShader* m_pShader;
		Textures m_Textures;
		Colors m_Colors;
	};
}

#endif // GLIB_AGMATERIAL_H