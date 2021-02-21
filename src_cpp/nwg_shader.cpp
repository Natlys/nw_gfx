#include <nwg_pch.hpp>
#include "nwg_shader.h"
#if (defined NWG_GAPI)
#include <nwg_engine.h>
#include <nwg_shd_buf.h>
#include <nwg_loader.h>
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	Shader::Shader(GfxEngine& rGfx, const char* strName) :
		TEntity(), AGfxRes(rGfx), ACodeRes(strName)
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
	void Shader::Bind() {
		glUseProgram(m_unRId);
		for (UInt8 bi = 0; bi < m_shdLayout.GetBlocks().size(); bi++) {
			glUniformBlockBinding(m_unRId, bi, m_shdLayout.GetBlock(bi).unBindPoint);
		}
	}
	bool Shader::Compile()
	{
		Remake();
		StrStream strStream(m_strCode), strCodeStream;
		String strToken = "", strLine = "";
		if (m_unRId != 0) { Remake(); }

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

			if (strToken == "vertex") { shdType = ST_VERTEX; }
			else if (strToken == "geometry") { shdType = ST_GEOMETRY; }
			else if (strToken == "pixel") { shdType = ST_PIXEL; }
			else { continue; }
			{
				Int32 nCurr = 0;

				while (!strCodeStream.eof()) {		// parse the entire shader code
					strCodeStream >> strToken;
					if (strToken == "#version") {	// #version %num[ %core]
						strCodeStream >> strToken;
						sprintf(&m_strName[0], "%s_ver_%s", &m_strName[0], &strToken[0]);
						strCodeStream >> strToken;
						if (strToken == "core") { sprintf(&m_strName[0], "%s_%s", &m_strName[0], &strToken[0]); }
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
		BufElem BufElem(&strName[0], type, count, false);	\
		while(unCount-- > 0) { command(BufElem); } }
				/// --<macro_helper>--
							MAKE_BUF_ELEM(strToken == "bool", DT_BOOL, 1, m_vtxLayout.AddElement)
								MAKE_BUF_ELEM(strToken == "short", DT_INT16, 1, m_vtxLayout.AddElement)
								MAKE_BUF_ELEM(strToken == "int", DT_INT32, 1, m_vtxLayout.AddElement)
								MAKE_BUF_ELEM(strToken == "float", DT_FLOAT32, 1, m_vtxLayout.AddElement)
								MAKE_BUF_ELEM(strToken == "vec2", DT_FLOAT32, 2, m_vtxLayout.AddElement)
								MAKE_BUF_ELEM(strToken == "vec3", DT_FLOAT32, 3, m_vtxLayout.AddElement)
								MAKE_BUF_ELEM(strToken == "vec4", DT_FLOAT32, 4, m_vtxLayout.AddElement)
								if ((nCurr = strToken.find("mat")) != -1) {
									strCodeStream >> strName;
									if (sscanf(&strToken[0], "mat%d", &nCurr) > 0) {
										for (UInt8 ei = 0; ei < nCurr; ei++) {
											m_vtxLayout.AddElement(BufElem{ &strName[0], DT_FLOAT32, static_cast<UInt32>(nCurr), false });
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
								MAKE_BUF_ELEM(strToken == "bool", DT_BOOL, 1, shdBlock.BufElems.push_back)
									MAKE_BUF_ELEM(strToken == "short", DT_INT16, 1, shdBlock.BufElems.push_back)
									MAKE_BUF_ELEM(strToken == "int", DT_INT32, 1, shdBlock.BufElems.push_back)
									MAKE_BUF_ELEM(strToken == "float", DT_FLOAT32, 1, shdBlock.BufElems.push_back)
									MAKE_BUF_ELEM(strToken == "vec2", DT_FLOAT32, 2, shdBlock.BufElems.push_back)
									MAKE_BUF_ELEM(strToken == "vec3", DT_FLOAT32, 4, shdBlock.BufElems.push_back)
									MAKE_BUF_ELEM(strToken == "vec4", DT_FLOAT32, 4, shdBlock.BufElems.push_back)
									MAKE_BUF_ELEM(strToken == "mat2", DT_FLOAT32, 2 * 2, shdBlock.BufElems.push_back)
									MAKE_BUF_ELEM(strToken == "mat3", DT_FLOAT32, 3 * 4, shdBlock.BufElems.push_back)
									MAKE_BUF_ELEM(strToken == "mat4", DT_FLOAT32, 4 * 4, shdBlock.BufElems.push_back)
							}
							m_shdLayout.AddBlock(shdBlock);
							m_Blocks[&shdBlock.strName[0]] = shdBlock.unBindPoint;
						}
					}
					else if (strToken == "uniform") {	// uniform {type} {name};
						std::getline(strCodeStream, strToken, ';');
						auto fnMakeElems = [&](const char* strComp, DataTypes sdType, UInt8 unCount = 1)->bool {
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
										m_shdLayout.GetBlock(0).AddElem(BufElem(&strCompleteName[0], sdType, unCount, false));
									}
								}
								else {
									m_shdLayout.GetBlock(0).AddElem(BufElem(&strName[0], sdType, unCount, false));
								}
								return true;
							}
							return true;
						};
						fnMakeElems("sampler1D", DT_SAMPLER); fnMakeElems("sampler2D", DT_SAMPLER); fnMakeElems("sampler3D", DT_SAMPLER);
						fnMakeElems("bool", DT_BOOL); fnMakeElems("char", DT_INT8); fnMakeElems("short", DT_INT16); fnMakeElems("int", DT_INT32);
						fnMakeElems("float", DT_FLOAT32); fnMakeElems("vec2", DT_FLOAT32, 2);
						fnMakeElems("vec3", DT_FLOAT32, 3); fnMakeElems("vec4", DT_FLOAT32, 4);
						fnMakeElems("mat2", DT_FLOAT32, 2 * 2); fnMakeElems("mat3", DT_FLOAT32, 3 * 3); fnMakeElems("mat4", DT_FLOAT32, 4 * 4);
					}
				}
			}
		}
		if (m_unRId != 0) { glDeleteShader(m_unRId); m_unRId = 0; }
		m_unRId = glCreateShader(m_shdType);

		const char* strSource = &m_strCode[0];
		glShaderSource(m_unRId, 1, &strSource, nullptr);
		glCompileShader(m_unRId);
		glLinkProgram(m_unRId);
		if (OglErrLogShader(ST_SHADER, m_unRId) != 0) { throw Exception("Failed to load a shader", NWL_ERR_SHADER_COMPILE); return false; }
		
		return true;
	}
	void Shader::Remake()
	{
		if (m_unRId != 0) { glDeleteProgram(m_unRId); m_unRId = 0; }
		m_unRId = glCreateProgram();
		m_SubShaders.clear();
		m_Uniforms.clear();
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
		IOFStream fStream(strFPath);

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


	// --==<implementation_methods>==-
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
namespace NWG
{
	Shader::Shader(GfxEngine& rGfx, ShaderTypes sdType) :
		TEntity(), AGfxRes(rGfx), ACodeRes(),
		m_sdType(sdType),
		m_pBlob(nullptr) {}
	Shader::~Shader() { if (m_pBlob != nullptr) { m_pBlob->Release(); m_pBlob = nullptr; } }
	// --setters
	void Shader::SetProgram(ShaderProgram* psProg) { m_psProg = psProg; }
	// --data_methods
	bool Shader::SaveF(const char* strFPath)
	{
		return true;
	}
	bool Shader::LoadF(const char* strFPath)
	{
		SetCode(strFPath);
		if (!Compile()) { return false; }
		
		return true;
	}
}
namespace NWG
{
	VertexShader::VertexShader(GfxEngine& rGfx) : Shader(rGfx, ST_VERTEX),
		m_pNative(nullptr),
		m_inLayout(InputLayout(rGfx)) { }
	VertexShader::~VertexShader() { if (m_pNative != nullptr) { m_pNative->Release(); m_pNative = nullptr; } }
	// --core_methods
	void VertexShader::Bind()
	{
		m_pGfx->GetContext()->VSSetShader(m_pNative, NULL, NULL);
		m_inLayout.Bind();
	}
	bool VertexShader::Compile()
	{
		if (m_pNative != nullptr) { m_pNative->Release(); m_pNative = nullptr; }
		
		WChar wstrFPath[256]{ 0 };
		mbstowcs(&wstrFPath[0], &m_strCode[0], 256);
		
		D3DReadFileToBlob(&wstrFPath[0], &m_pBlob);
		if (m_pBlob == nullptr) { return false; }
		m_pGfx->GetDevice()->CreateVertexShader(m_pBlob->GetBufferPointer(), m_pBlob->GetBufferSize(), NULL, &m_pNative);
		
		m_pGfx->GetContext()->VSSetShader(m_pNative, NULL, NULL);
		m_vtxLayout.AddElement(BufElem("vtx_crd", DtGet<V3f>(), 1, false));
		m_vtxLayout.AddElement(BufElem("tex_crd", DtGet<V2f>(), 1, false));
		m_vtxLayout.AddElement(BufElem("nrm_crd", DtGet<V3f>(), 1, false));
		m_inLayout.SetShader(this);
		m_inLayout.Remake();
		
		return true;
	}
}
namespace NWG
{
	PixelShader::PixelShader(GfxEngine& rGfx) : Shader(rGfx, ST_PIXEL), m_pNative(nullptr) { }
	PixelShader::~PixelShader() { if (m_pNative != nullptr) { m_pNative->Release(); m_pNative = nullptr; } }
	// --core_methods
	void PixelShader::Bind() { m_pGfx->GetContext()->PSSetShader(m_pNative, NULL, NULL); }
	bool PixelShader::Compile()
	{
		if (m_pNative != nullptr) { m_pNative->Release(); m_pNative = nullptr; }
		
		WChar wstrFPath[256]{ 0 };
		mbstowcs(&wstrFPath[0], &m_strCode[0], 256);
		
		D3DReadFileToBlob(&wstrFPath[0], &m_pBlob);
		if (m_pBlob == nullptr) { return false; }
		m_pGfx->GetContext()->PSSetShader(m_pNative, NULL, NULL);
		m_pGfx->GetDevice()->CreatePixelShader(m_pBlob->GetBufferPointer(), m_pBlob->GetBufferSize(), NULL, &m_pNative);
		
		return true;
	}
}
namespace NWG
{
	ShaderProgram::ShaderProgram(GfxEngine& rGfx, const char* strName) :
		TEntity(), AGfxRes(rGfx), ADataRes(strName),
		m_shdLayout(ShaderLayout()) {  }
	ShaderProgram::~ShaderProgram() { Remake(); }
	// --==<core_methods>==--
	void ShaderProgram::Bind() {
		for (auto& itShader : m_Shaders) {
			itShader->Bind();
		}
	}
	void ShaderProgram::Remake()
	{
		m_shdLayout.Remake();
		m_Shaders.clear();
	}
	// --==</core_methods>==--
	// --==<data_methods>==--
	bool ShaderProgram::SaveF(const char* strFPath) { return true; }
	bool ShaderProgram::LoadF(const char* strFPath)
	{
		Remake();

		String strFile = "";
		if (!DataSys::LoadFString(strFPath, strFile)) { throw(Exception("failed to load a shader")); }
		Int32 nCurr = 0;
		Int32 nLineEnd = 0;
		StrStream stmFile(strFile);
		
		while (std::getline(stmFile, strFile, ':')) {
			if (strFile == "gapi") {
				std::getline(stmFile, strFile, ';');
				if (strFile == "directx") { }
				else { return false; }
			}
			else if (strFile == "name") {
				std::getline(stmFile, strFile, ';');
				SetName(&strFile[0]);
			}
			else if (strFile == "vertex_src") {
				std::getline(stmFile, strFile, ';');
			}
			else if (strFile == "vertex_bin") {
				std::getline(stmFile, strFile, ';');
				if (!AddShader(ST_VERTEX, &strFile[0])) { throw Exception("failed to load subshader"); }
			}
			else if (strFile == "pixel_src") {
				std::getline(stmFile, strFile, ';');
			}
			else if (strFile == "pixel_bin") {
				std::getline(stmFile, strFile, ';');
				if (!AddShader(ST_PIXEL, &strFile[0])) { throw Exception("failed to load the subshader"); }
			}
			else { }
			stmFile.get();	// get rid of '\n' and ' ' characters
		}

		return true;
	}
	// --==</data_methods>==--

	// --==<implementation_methods>==--
	inline bool ShaderProgram::AddShader(ShaderTypes shdType, const char* strCode)
	{
		WChar wstrFPath[256]{ 0 };
		mbstowcs(&wstrFPath[0], &strCode[0], 256);
		switch (shdType) {
		case ST_VERTEX: {
			m_Shaders.push_back(RefKeeper<Shader>());
			m_pGfx->CreateRes<Shader, VertexShader>(m_Shaders.back());
			return m_Shaders.back()->LoadF(strCode);
			break;
		}
		case ST_PIXEL: {
			m_Shaders.push_back(RefKeeper<Shader>());
			m_pGfx->CreateRes<Shader, PixelShader>(m_Shaders.back());
			return m_Shaders.back()->LoadF(strCode);
			break;
		}
		default: { throw Exception("inaccessible shader type"); } return false; break;
		}
		return true;
	}
	// --==</implementation_methods>==--
}
#endif
#endif	// NWG_GAPI