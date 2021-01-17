#include <glib_pch.hpp>
#include "glib_shader.h"

#if (defined GLIB_GAPI)
#include <core/glib_engine.h>
#include <core/glib_api.h>
#include <glib_buffer.h>

namespace GLIB
{
	ASubShader::ASubShader(const char* strName, ShaderTypes sdType) :
		AGRes(strName),
		m_shdType(sdType), m_unRId(0), m_strCode("") { GEngine::Get().AddGRes<ASubShader>(this); }
	ASubShader::~ASubShader() { GEngine::Get().RmvGRes<ASubShader>(GetId()); }

	// --==<data_methods>==--
	bool ASubShader::SaveF(const char* strFPath) { return true; }
	bool ASubShader::LoadF(const char* strFPath) { return true; }
	// --==</data_methods>==--

	ASubShader* ASubShader::Create(const char* strName, ShaderTypes sdType)
	{
		ASubShader* pSubShader = nullptr;
		switch (GEngine::Get().GetGApi()->GetType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GAPI_OPENGL: pSubShader = new SubShaderOgl(strName, sdType); break;
	#endif // GLIB_GAPI
		default: GLIB_ERR("Graphics Api is not defined"); break;
		}
		return pSubShader;
	}
}
namespace GLIB
{
	AShader::AShader(const char* strName) :
		AGRes(strName), m_unRId(0), m_strCode("") { GEngine::Get().AddGRes<AShader>(this); }
	AShader::~AShader() { GEngine::Get().RmvGRes<AShader>(GetId()); }

	// --==<data_methods>==--
	bool AShader::SaveF(const char* strFPath)
	{
		String strFile = m_strCode;
		if (!GEngine::Get().SaveFShaderCode(strFPath, this)) { return false; }
		return true;
	}
	bool AShader::LoadF(const char* strFPath)
	{
		bool bSuccess = false;
		if (GEngine::Get().LoadFShaderCode(strFPath, this)) {
			if (!Compile()) {
				String strFile = m_strCode;
				bSuccess = false;
			}
			else { bSuccess = true; }
		}
		return bSuccess;
	}
	// --==</data_methods>==--

	AShader* AShader::Create(const char* strName)
	{
		AShader* pShader = nullptr;
		switch (GEngine::Get().GetGApi()->GetType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GAPI_OPENGL: pShader = new ShaderOgl(strName); break;
	#endif // GLIB_GAPI
		default: GLIB_ERR("Graphics Api is not defined"); break;
		}
		return pShader;
	}
}
#endif	// GLIB_GAPI
#if (GLIB_GAPI & GLIB_GAPI_OGL)
#include <glad/glad.h>
// SubShaderOgl
namespace GLIB
{
	// Constructor&Destructor
	SubShaderOgl::SubShaderOgl(const char* strName, ShaderTypes sdType) :
		ASubShader(strName, sdType),
		m_pOverShader(nullptr) { Reset(); }
	SubShaderOgl::~SubShaderOgl(){ Reset(); }

	// getters
	const AShader* SubShaderOgl::GetOverShader() const { return dynamic_cast<const AShader*>(m_pOverShader); }
	// core_methods
	void SubShaderOgl::Attach(AShader* pOverShader) {
		Detach();
		m_pOverShader = dynamic_cast<ShaderOgl*>(pOverShader);
		if (m_pOverShader == nullptr) return;
		glAttachShader(m_pOverShader->GetRenderId(), m_unRId);
	}
	void SubShaderOgl::Detach() { if (m_pOverShader) { glDetachShader(m_pOverShader->GetRenderId(), m_unRId); } }

	bool SubShaderOgl::Compile()
	{
		if (!CodeProc()) { return false; }
		const char* strSource = &m_strCode[0];
		glShaderSource(m_unRId, 1, &strSource, nullptr);
		glCompileShader(m_unRId);
		if (OGL_ErrLog_Shader(m_shdType, m_unRId) != 0) { return false; }
		return true;
	}
	void SubShaderOgl::Reset() {
		Detach();
		if (m_unRId != 0) { glDeleteShader(m_unRId); m_unRId = 0; }
		m_unRId = glCreateShader(m_shdType);
		m_strCode = "";
	}

	// --implementation_methods
	bool SubShaderOgl::CodeProc() {
		StrStream strCodeStream(m_strCode);
		String strToken("", 256);
		String strLine("", 256);
		String strName("", 128);
		Int32 nCurr = 0;

		while (!strCodeStream.eof()) {		// parse the entire shader code
			strCodeStream >> strToken;
			if (strToken == "#version") {	// #version %num[ %core]
				strCodeStream >> strToken;
				m_strName += "_ver" + strToken;
				strCodeStream >> strToken;
				if (strToken == "core") m_strName += strToken;
			}
			else if (strToken.find("layout") != -1) {		// layout(location=%x/%std140)in /uniform{
				if ((nCurr = strToken.find(')')) != -1) {}
				else { std::getline(strCodeStream, strToken, ')'); }
				strCodeStream >> strToken;
				if (strToken == "in") {		// layout(location=%loc)in %type %name;
					strCodeStream >> strToken;
				/// --<macro_helper>--
#define MAKE_BUF_ELEM(expr, type, count, command)				\
	if (expr) { if (nCurr < 0) { nCurr = 0; }					\
		UInt32 unCount = 1;										\
		strCodeStream >> strName;								\
		if ((nCurr = strName.find("[", nCurr)) != -1) {			\
			unCount *= atoi(&strName[nCurr + 1]);				\
			strName = strName.substr(0, nCurr);	}				\
		BufferElement BufElem(&strName[0], type, count, false);	\
		while(unCount-- > 0) { command(BufElem); } }
				/// --<macro_helper>--
					MAKE_BUF_ELEM(strToken == "bool", SDT_BOOL, 1,			m_pOverShader->m_vtxLayout.AddElement)
					MAKE_BUF_ELEM(strToken == "short", SDT_INT16, 1,		m_pOverShader->m_vtxLayout.AddElement)
					MAKE_BUF_ELEM(strToken == "int", SDT_INT32, 1,			m_pOverShader->m_vtxLayout.AddElement)
					MAKE_BUF_ELEM(strToken == "float", SDT_FLOAT32, 1,		m_pOverShader->m_vtxLayout.AddElement)
					MAKE_BUF_ELEM(strToken == "vec2", SDT_FLOAT32, 2,		m_pOverShader->m_vtxLayout.AddElement)
					MAKE_BUF_ELEM(strToken == "vec3", SDT_FLOAT32, 3,		m_pOverShader->m_vtxLayout.AddElement)
					MAKE_BUF_ELEM(strToken == "vec4", SDT_FLOAT32, 4,		m_pOverShader->m_vtxLayout.AddElement)
					if ((nCurr = strToken.find("mat")) != -1) {
						strCodeStream >> strName;
						if (sscanf(&strToken[0], "mat%d", &nCurr) > 0) {
							for (UInt8 ei = 0; ei < nCurr; ei++) {
								m_pOverShader->m_vtxLayout.AddElement(BufferElement{ &strName[0], SDT_FLOAT32, static_cast<UInt32>(nCurr), false });
							}
						}
					}
				}
				else if (strToken == "uniform") {	// uniform %name {%elements};
					strCodeStream >> strName;
					if ((nCurr = strName.find("{")) != -1) { strName = strName.substr(0, nCurr); }
					ShaderBlock shdBlock(&strName[0], m_pOverShader->m_shdLayout.GetBlocks().size());
					while (!strCodeStream.eof()) {
						strCodeStream >> strToken;
						if (strToken.find('{') != -1) { continue; }
						if (strToken.find('}') != -1) { break; }
						MAKE_BUF_ELEM(strToken == "bool", SDT_BOOL, 1, shdBlock.BufElems.push_back)
						MAKE_BUF_ELEM(strToken == "short", SDT_INT16, 1, shdBlock.BufElems.push_back)
						MAKE_BUF_ELEM(strToken == "int", SDT_INT32, 1, shdBlock.BufElems.push_back)
						MAKE_BUF_ELEM(strToken == "float", SDT_FLOAT32, 1, shdBlock.BufElems.push_back)
						MAKE_BUF_ELEM(strToken == "vec2", SDT_FLOAT32, 2, shdBlock.BufElems.push_back)
						MAKE_BUF_ELEM(strToken == "vec3", SDT_FLOAT32, 4, shdBlock.BufElems.push_back)
						MAKE_BUF_ELEM(strToken == "vec4", SDT_FLOAT32, 4, shdBlock.BufElems.push_back)
						MAKE_BUF_ELEM(strToken == "mat2", SDT_FLOAT32, 2 * 2, shdBlock.BufElems.push_back)
						MAKE_BUF_ELEM(strToken == "mat3", SDT_FLOAT32, 3 * 4, shdBlock.BufElems.push_back)
						MAKE_BUF_ELEM(strToken == "mat4", SDT_FLOAT32, 4 * 4, shdBlock.BufElems.push_back)
					}
					m_pOverShader->m_shdLayout.AddBlock(shdBlock);
					m_pOverShader->m_Blocks[&shdBlock.strName[0]] = shdBlock.unBindPoint;
				}
			}
			else if (strToken == "uniform") {	// uniform {type} {name};
				std::getline(strCodeStream, strToken, ';');
				auto fnMakeElems = [&](const char* strComp, ShaderDataTypes sdType, UInt8 unCount = 1)->bool {
					if ((nCurr = strToken.find(strComp)) != -1) {
						Int32 nCount = 1;
						Int32 nBeg = (nCurr += strlen(strComp) + 1);
						strName = strToken.substr(nBeg, strToken.size());
						if ((nCurr = strName.find("[")) != -1) {
							if (sscanf(&strName[nCurr], "[%d]", &nCount) <= 0) { return false; }
							strName = strName.substr(0, nCurr);
						}
						if ((nCurr = strName.find(" ")) != -1) { strName = strName.substr(0, nCurr - 1); }
						if (nCount > 1) {
							for (Int32 bi = 0; bi < nCount; bi++) {
								Char strCompleteName[128];
								sprintf(&strCompleteName[0], "%s[%d]", &strName[0], bi);
								m_pOverShader->m_shdLayout.AddGlobalElem(BufferElement(&strCompleteName[0], sdType, unCount, false));
							}
						}
						else {
							m_pOverShader->m_shdLayout.AddGlobalElem(BufferElement(&strName[0], sdType, unCount, false));
						}
						return true;
					}
					return true;
				};
				fnMakeElems("sampler1D", SDT_SAMPLER); fnMakeElems("sampler2D", SDT_SAMPLER); fnMakeElems("sampler3D", SDT_SAMPLER);
				fnMakeElems("bool", SDT_BOOL); fnMakeElems("char", SDT_INT8); fnMakeElems("short", SDT_INT16); fnMakeElems("int", SDT_INT32);
				fnMakeElems("float", SDT_FLOAT32); fnMakeElems("vec2", SDT_FLOAT32, 2);
				fnMakeElems("vec3", SDT_FLOAT32, 3); fnMakeElems("vec4", SDT_FLOAT32, 4);
				fnMakeElems("mat2", SDT_FLOAT32, 2 * 2); fnMakeElems("mat3", SDT_FLOAT32, 3 * 3); fnMakeElems("mat4", SDT_FLOAT32, 4 * 4);
				//m_pOverShader->m_Globals[strName] = m_pOverShader->m_Globals.size();
			}
		}
		return true;
	}
}
// ShaderOgl
namespace GLIB
{
	ShaderOgl::ShaderOgl(const char* strName) :
		AShader(strName) { }
	ShaderOgl::~ShaderOgl() { }

	// --==<core_methods>==--
	void ShaderOgl::Enable() {
		glUseProgram(m_unRId);
		for (UInt8 bi = 0; bi < m_shdLayout.GetBlocks().size(); bi++) {
			glUniformBlockBinding(m_unRId, bi, m_shdLayout.GetBlock(bi).unBindPoint);
		}
	}
	void ShaderOgl::Disable() { glUseProgram(0); }

	bool ShaderOgl::Compile()
	{
		Reset();
		if (!CodeProc()) { return false; }
		for (auto& rSub : m_SubShaders) {
			rSub.Attach(this);
			if (!rSub.Compile()) { return false; }
		}
		glLinkProgram(m_unRId);
		if (OGL_ErrLog_Shader(ST_SHADER, m_unRId) != 0) return false;
		
		return true;
	}
	void ShaderOgl::Reset()
	{
		if (m_unRId != 0) { glDeleteProgram(m_unRId); m_unRId = 0; }
		m_unRId = glCreateProgram();
		m_SubShaders.clear();
		m_Globals.clear();
		m_vtxLayout.Reset();
		m_shdLayout.Reset();
	}
	// --==</core_methods>==--

	// --==<setters>==--
	void ShaderOgl::SetBool(const char* name, bool value) const { glUniform1i(GetUniformLoc(name), value); }
	void ShaderOgl::SetInt(const char* name, int value) const { glUniform1i(GetUniformLoc(name), value); }
	void ShaderOgl::SetIntArray(const char* name, Int32* pIntArr, UInt32 unCount) const { glUniform1iv(GetUniformLoc(name), unCount, pIntArr); }
	void ShaderOgl::SetUIntArray(const char* name, UInt32* pUIntArr, UInt32 unCount) const { glUniform1uiv(GetUniformLoc(name), unCount, pUIntArr); }
	void ShaderOgl::SetFloat(const char* name, float value) const { glUniform1f(GetUniformLoc(name), value); }
	void ShaderOgl::SetFloatArray(const char* name, float* pFloatArr, UInt32 unCount) const { glUniform1fv(GetUniformLoc(name), unCount, pFloatArr); }
	void ShaderOgl::SetV2f(const char* name, const V2f& value) const { glUniform2fv(GetUniformLoc(name), 1, &(value[0])); }
	void ShaderOgl::SetV3f(const char* name, const V3f& value) const { glUniform3fv(GetUniformLoc(name), 1, &(value[0])); }
	void ShaderOgl::SetV4f(const char* name, const V4f& value) const { glUniform4fv(GetUniformLoc(name), 1, &(value[0])); }
	void ShaderOgl::SetM4f(const char* name, const Mat4f& value) const { glUniformMatrix4fv(GetUniformLoc(name), 1, GL_FALSE, &value[0][0]); }
	// --==</setters>==--

	// --==<core_methods>==--
	inline bool ShaderOgl::CodeProc()
	{
		StrStream strStream(m_strCode), strCodeStream;
		String strToken = "", strLine = "";

		if (m_SubShaders.size() > 0) { Reset(); }
		while (strToken != "#shader_type" && !strStream.eof()) { strStream >> strToken; }
		while (!strStream.eof()) {	// Last token has to be the type: "#shader_type|{type}"
			strStream >> strToken;
			while (!strStream.eof()) {
				strStream >> strLine;						// write a type token from strStream 
				if (strLine == "#shader_type") { break; }	// if it's a new shader - stop
				else {	//	-- write that token in the code and all other line too
					strCodeStream << strLine;
					std::getline(strStream, strLine, '\n');
					strCodeStream << strLine << '\n';
				}
			}

			if (strToken == "vertex") { m_SubShaders.push_back(SubShaderOgl(&(m_strName + "_" + strToken)[0], ST_VERTEX)); }
			else if (strToken == "geometry") { m_SubShaders.push_back(SubShaderOgl(&(m_strName + "_" + strToken)[0], ST_GEOMETRY)); }
			else if (strToken == "pixel" || strToken == "fragment") { m_SubShaders.push_back(SubShaderOgl(&(m_strName + "_" + strToken)[0], ST_PIXEL)); }
			else { continue; }

			auto& rSub = m_SubShaders.back();
			rSub.SetCode(&strCodeStream.str()[0]);
			strCodeStream = std::stringstream();
		}

		return true;
	}

	inline Int32 ShaderOgl::GetUniformLoc(const char* strName) const {
		for (auto& itPar : m_Globals) { if (strcmp(itPar.first.c_str(), strName) == 0) { return itPar.second; } }
		
		Int32 nLoc = glGetUniformLocation(m_unRId, strName);
		m_Globals[strName] = nLoc;
		return nLoc;
	}
	inline Int32 ShaderOgl::GetBlockIdx(const char* strName) const {
		for (auto& itBlk : m_Blocks) { if (strcmp(itBlk.first.c_str(), strName) == 0) { return itBlk.second; } }
		
		Int32 nIdx = glGetUniformBlockIndex(m_unRId, &strName[0]);
		m_Blocks[strName] = nIdx;
		return nIdx;
	}
	// --==</core_methods>==--
}

#endif // GLIB_GAPI