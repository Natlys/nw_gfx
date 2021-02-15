#include <nwg_pch.hpp>
#include "nwg_shader.h"
#if (defined NWG_GAPI)
#include <nwg_engine.h>
#include <nwg_buffer.h>
#include <nwg_loader.h>
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	SubShader::SubShader(const char* strName, ShaderTypes sdType) :
		GfxEntity(), ACodeRes(strName),
		m_shdType(sdType), m_pOverShader(nullptr)
	{
		Remake();
	}
	SubShader::~SubShader() { Remake(); }
	// --==<core_methods>==--
	void SubShader::Attach(Shader* pOverShader) {
		Detach();
		m_pOverShader = static_cast<Shader*>(pOverShader);
		if (m_pOverShader == nullptr) return;
		glAttachShader(m_pOverShader->m_unRId, m_unRId);
	}
	void SubShader::Detach() {
		if (m_pOverShader == nullptr) { return; }
		glDetachShader(m_pOverShader->m_unRId, m_unRId);
	}

	bool SubShader::Compile()
	{
		if (!CodeProc()) { return false; }
		const char* strSource = &m_strCode[0];
		glShaderSource(m_unRId, 1, &strSource, nullptr);
		glCompileShader(m_unRId);
		return true;
	}
	void SubShader::Remake() {
		Detach();
		if (m_unRId != 0) { glDeleteShader(m_unRId); m_unRId = 0; }
		m_unRId = glCreateShader(m_shdType);
		m_strCode = "";
	}
	// --==</core_methods>==--
		// --==<data_methods>==--
	bool SubShader::SaveF(const char* strFPath) { return true; }
	bool SubShader::LoadF(const char* strFPath) { return true; }
	// --==</data_methods>==--
	// --==<implementation_methods>==--
	bool SubShader::CodeProc() {
		StrStream strCodeStream(m_strCode);
		String strToken("", 256);
		String strLine("", 256);
		String strName("", 128);
		Int32 nCurr = 0;

		while (!strCodeStream.eof()) {		// parse the entire shader code
			strCodeStream >> strToken;
			if (strToken == "#version") {	// #version %num[ %core]
				strCodeStream >> strToken;
				sprintf(&m_strName[0], "%s_ver_%s", &m_strName[0], &strToken[0]);
				strCodeStream >> strToken;
				if (strToken == "core") { sprintf(&m_strName[0], "%s_", &m_strName[0], strToken[0]); }
			}
			else if (strToken.find("layout") != -1) {		// layout(location=%x/%std140)in/uniform{
				if ((nCurr = strToken.find(')')) != -1) {
					strToken = strToken.substr(nCurr + 1, strToken.size() - nCurr);
					if (strToken == "") { strCodeStream >> strToken; }
				}
				else { std::getline(strCodeStream, strToken, ')'); strCodeStream >> strToken; }
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
					MAKE_BUF_ELEM(strToken == "bool", SDT_BOOL, 1, m_pOverShader->m_vtxLayout.AddElement)
						MAKE_BUF_ELEM(strToken == "short", SDT_INT16, 1, m_pOverShader->m_vtxLayout.AddElement)
						MAKE_BUF_ELEM(strToken == "int", SDT_INT32, 1, m_pOverShader->m_vtxLayout.AddElement)
						MAKE_BUF_ELEM(strToken == "float", SDT_FLOAT32, 1, m_pOverShader->m_vtxLayout.AddElement)
						MAKE_BUF_ELEM(strToken == "vec2", SDT_FLOAT32, 2, m_pOverShader->m_vtxLayout.AddElement)
						MAKE_BUF_ELEM(strToken == "vec3", SDT_FLOAT32, 3, m_pOverShader->m_vtxLayout.AddElement)
						MAKE_BUF_ELEM(strToken == "vec4", SDT_FLOAT32, 4, m_pOverShader->m_vtxLayout.AddElement)
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
	// --==</implementation_methods>==--
}
namespace NWG
{
	Shader::Shader(const char* strName) :
		ACodeRes(strName), GfxEntity()
	{
		Remake();
	}
	Shader::~Shader() { Remake(); }
	// --setters
	void Shader::SetBool(const char* name, bool value) const { glUniform1i(GetUniformLoc(name), value); }
	void Shader::SetInt(const char* name, int value) const { glUniform1i(GetUniformLoc(name), value); }
	void Shader::SetIntArray(const char* name, Int32* pIntArr, UInt32 unCount) const { glUniform1iv(GetUniformLoc(name), unCount, pIntArr); }
	void Shader::SetUIntArray(const char* name, UInt32* pUIntArr, UInt32 unCount) const { glUniform1uiv(GetUniformLoc(name), unCount, pUIntArr); }
	void Shader::SetFloat(const char* name, float value) const { glUniform1f(GetUniformLoc(name), value); }
	void Shader::SetFloatArray(const char* name, float* pFloatArr, UInt32 unCount) const { glUniform1fv(GetUniformLoc(name), unCount, pFloatArr); }
	void Shader::SetV2f(const char* name, const V2f& value) const { glUniform2fv(GetUniformLoc(name), 1, &(value[0])); }
	void Shader::SetV3f(const char* name, const V3f& value) const { glUniform3fv(GetUniformLoc(name), 1, &(value[0])); }
	void Shader::SetV4f(const char* name, const V4f& value) const { glUniform4fv(GetUniformLoc(name), 1, &(value[0])); }
	void Shader::SetM4f(const char* name, const Mat4f& value) const { glUniformMatrix4fv(GetUniformLoc(name), 1, GL_FALSE, &value[0][0]); }
	// --==<core_methods>==--
	void Shader::Bind() const {
		glUseProgram(m_unRId);
		for (UInt8 bi = 0; bi < m_shdLayout.GetBlocks().size(); bi++) {
			glUniformBlockBinding(m_unRId, bi, m_shdLayout.GetBlock(bi).unBindPoint);
		}
	}
	bool Shader::Compile()
	{
		Remake();
		if (!CodeProc()) { return false; }
		for (auto& rSub : m_SubShaders) {
			rSub->Attach(this);
			if (!rSub->Compile()) { return false; }
		}
		glLinkProgram(m_unRId);
		if (OglErrLogShader(ST_SHADER, m_unRId) != 0) return false;
		
		return true;
	}
	void Shader::Remake()
	{
		if (m_unRId != 0) { glDeleteProgram(m_unRId); m_unRId = 0; }
		m_unRId = glCreateProgram();
		m_SubShaders.clear();
		m_Globals.clear();
		m_vtxLayout.Reset();
		m_shdLayout.Reset();
	}
	// --==</core_methods>==--
		// --==<data_methods>==--
	bool Shader::SaveF(const char* strFPath)
	{
		String strFile = m_strCode;
		return true;
	}
	bool Shader::LoadF(const char* strFPath)
	{
		bool bSuccess = false;
		std::fstream fStream(strFPath);

		if (!fStream.is_open()) { return false; }
		fStream.seekg(0, std::ios::end);
		m_strCode.resize(fStream.tellg());
		fStream.seekg(0);
		fStream.read(&m_strCode[0], m_strCode.size());
		fStream.close();

		if (!Compile()) {
			String strFile = m_strCode;
			bSuccess = false;
		}
		else { bSuccess = true; }

		return bSuccess;
	}
	// --==</data_methods>==--
	// --==<implementation_methods>==--
	inline bool Shader::CodeProc()
	{
		StrStream strStream(m_strCode), strCodeStream;
		String strToken = "", strLine = "";
		if (m_SubShaders.size() > 0) { Remake(); }

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

			String strName = m_strName;
			strName += "_";
			ShaderTypes shdType = ST_DEFAULT;
			if (strToken == "vertex") { shdType = ST_VERTEX; }
			else if (strToken == "geometry") { shdType = ST_GEOMETRY; }
			else if (strToken == "pixel") { shdType = ST_PIXEL; }
			else { continue; }
			strName += strToken;

			m_SubShaders.push_back(RefKeeper<SubShader>());
			auto& rSub = m_SubShaders.back();
			rSub.SetRef<ADataRes>(*DataSys::GetDR(DataSys::NewDR<SubShader>(&(strName)[0], shdType)));
			rSub->SetCode(&strCodeStream.str()[0]);
			strCodeStream = std::stringstream();
		}

		return true;
	}

	inline Int32 Shader::GetUniformLoc(const char* strName) const {
		for (auto& itPar : m_Globals) { if (strcmp(itPar.first.c_str(), strName) == 0) { return itPar.second; } }
		Int32 nLoc = glGetUniformLocation(m_unRId, strName);
		m_Globals[strName] = nLoc;
		return nLoc;
	}
	inline Int32 Shader::GetBlockIdx(const char* strName) const {
		for (auto& itBlk : m_Blocks) { if (strcmp(itBlk.first.c_str(), strName) == 0) { return itBlk.second; } }
		Int32 nIdx = glGetUniformBlockIndex(m_unRId, &strName[0]);
		m_Blocks[strName] = nIdx;
		return nIdx;

	}
	// --==</implementation_methods>==--
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
#endif
#endif	// NWG_GAPI