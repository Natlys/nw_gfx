#include <nwg_pch.hpp>
#include "nwg_shader.h"
#if (defined NWG_GAPI)
#include <core/nwg_engine.h>
#include <cmp/nwg_shd_buf.h>
namespace NWG
{
	shader_info::shader_info(gfx_api_types gfx_api_type, shader_types shader_type,
		cstring shader_name, cstring source_code) :
	gapi_type(gfx_api_type), shd_type(shader_type), name(shader_name), source_code(source_code) { }
	// --operators
	out_stream& shader_info::operator<<(out_stream& stm) const {
		return stm <<
			"--==<shader_info>==--" << std::endl <<
			"gapi:" << gapi_type << ";" << std::endl <<
			"type:" << shd_type << ";" << std::endl <<
			"name:" << name << ";" << std::endl <<
			"src:" << source_code << ";" << std::endl <<
			"--==</shader_info>==--" << std::endl;
	}
	in_stream& shader_info::operator>>(in_stream& stm) {
		char8 str_buf[256];
		si32 unGApi = 0;
		si32 unShdType = 0;
		
		stm.getline(str_buf, 256, ':');
		if (!(stm >> unGApi)) { throw error("invalid format"); }
		stm.get();
		stm.getline(str_buf, 256, ':');
		if (!(stm >> unShdType)) { throw error("invalid format"); }
		stm.get();
		
		stm.getline(str_buf, 256, ':');
		std::getline(stm, name, ';');
		stm.get();
		stm.getline(str_buf, 256, ':');
		std::getline(stm, source_code, ';');
		stm.get();
		
		gapi_type = static_cast<gfx_api_types>(unGApi);
		shd_type = static_cast<shader_types>(unShdType);
		
		return stm;
	}
}
#if (NWG_GAPI & NWG_GAPI_OGL)
#include <lib/nwg_ogl_v2.h>
#include <lib/nwg_ogl_arb.h>
namespace NWG
{
	shader::shader(gfx_engine& graphics, cstring name, shader_types shd_type) :
		t_gfx_cmp(graphics), a_data_res(name),
		m_info{ GAPI_DEFAULT, shd_type, name, "" },
		m_ogl_id(0)
	{
	}
	shader::~shader() { if (m_ogl_id != 0) { glDeleteShader(m_ogl_id); m_ogl_id = 0; } }
	// --setters
	void shader::set_source_code(cstring soruce_code) { m_info.source_code = soruce_code; }
	// --==<core_methods>==--
	bit shader::remake(const shader_info& info) {
		if (info.gapi_type != GAPI_DEFAULT) { return false; }
		if (info.source_code == "default") { return false; }
		if (info.shd_type != get_shd_type()) { return false; }
		set_name(&info.name[0]);
		
		if (!data_sys::load_file(&info.source_code[0], m_info.source_code)) { set_source_code(&info.source_code[0]); }
		return compile();
	}
	// --==</core_methods>==--

	// --==<data_methods>==--
	bit shader::save_file(cstring file_path)
	{
		str_stream stm_file;
		stm_file << m_info;

		return data_sys::save_file(file_path, stm_file.str());
	}
	bit shader::load_file(cstring file_path)
	{
		str_stream stm_file;
		if (!data_sys::load_file(file_path, stm_file.str())) { return false; }
		
		shader_info shdInfo;
		stm_file >> shdInfo;

		return remake(shdInfo);
	}
	// --==</data_methods>==--
}
namespace NWG
{
	vtx_shader::vtx_shader(gfx_engine& graphics, cstring name) :
		shader(graphics, name, SHD_VERTEX),
		m_layout(graphics) { }
	vtx_shader::~vtx_shader() { }
	// --core_methods
	void vtx_shader::on_draw() {
		for (ui8 bi = 0; bi < m_bufs.size(); bi++) {
			m_bufs[bi]->on_draw();
			glUniformBlockBinding(m_ogl_id, bi, bi);
		}
		for (ui8 bi = 0; bi < m_txrs.size(); bi++) {
			m_txrs[bi]->set_txr_slot(bi);
			m_txrs[bi]->on_draw();
			glUniform1i(bi, bi);
		}
		m_layout.on_draw();
	}
	bit vtx_shader::compile()
	{
		if (m_ogl_id != 0) { glDeleteShader(m_ogl_id); m_ogl_id = 0; }
		m_ogl_id = glCreateShader(GL_VERTEX_SHADER);
		m_txrs.clear();
		m_bufs.clear();
		m_layout.get_elems().clear();

		if (!code_proc()) { return false; }
		cstring shader_source = &get_source_code()[0];
		glShaderSource(m_ogl_id, 1, &shader_source, nullptr);
		glCompileShader(m_ogl_id);

		return ogl_get_err_log(get_shd_type(), m_ogl_id);
	}
	bit vtx_shader::code_proc() {
		if (m_info.source_code.empty() || m_info.source_code == "default") { return false; }
		str_stream stm_code(get_source_code());
		dstring str_buf = "";
		dstring name = "";
		si32 count = 1;
		si32 ncurr = 0;
		
		while (std::getline(stm_code, str_buf, ' ')) {
			if ((ncurr = str_buf.find("layout")) != -1) {
				// go back to the beginning
				stm_code.seekg(-static_cast<si32>(strlen(&str_buf[0])), std::ios_base::cur);
				std::getline(stm_code, str_buf, ';');
				if ((ncurr = str_buf.find("in ")) != -1) {
					stm_code.seekg(-static_cast<si32>(str_buf.length()) + ncurr, std::ios_base::cur);
					stm_code >> str_buf;	// read the token "in "

					stm_code >> str_buf;	// read the type
					std::getline(stm_code, name, ';');
					m_layout.add_elem(shd_elem(&name[0], convert_enum<cstring, data_types>(&str_buf[0]), count));
				}
				else if ((ncurr = str_buf.find("uniform ")) != -1) {
					m_bufs.push_back(mem_ref<shd_buf>());
					m_gfx->new_cmp<shd_buf>();
					m_bufs.back().set_ref(m_gfx->get_cmp<a_gfx_buf>(3));
					auto& buf = *m_bufs.back();

					stm_code.seekg(-static_cast<si32>(str_buf.length()) + ncurr, std::ios_base::cur);
					stm_code >> str_buf;	// read the token ")uniform{"

					stm_code >> name;	// read the name
					if ((ncurr = name.find("{")) != -1) {
						if (name.length() > ncurr) { stm_code.seekg(-static_cast<si32>(name.length()), std::ios_base::cur); }
						name = name.substr(0, ncurr);
					}
					buf.add_block(shd_block(&name[0], buf.get_blocks().size()));
					// come back and read the entire uniform block
					stm_code.seekg(-static_cast<si32>(str_buf.length()) + ncurr, std::ios_base::cur);
					std::getline(stm_code, str_buf, '{');
					std::getline(stm_code, str_buf, '}');
					str_stream stmBlock(str_buf);
					while (stmBlock >> str_buf) {				// read the type
						std::getline(stmBlock, name, ';');	// read the name
						buf.get_blocks().back().elems.push_back(shd_elem(&name[0],
							convert_enum<cstring, data_types>(&str_buf[0]), count));
						
					}
				}
			}
			else if ((ncurr = str_buf.find("uniform")) != -1) {
				throw error("the only supported uniforms are samplers of pixel shader");
			}
		}
		return m_layout.remake(*this);
	}
}
namespace NWG
{
	pxl_shader::pxl_shader(gfx_engine& graphics, cstring name) :
		shader(graphics, name, SHD_PIXEL) { }
	pxl_shader::~pxl_shader() { }
	// --core_methods
	void pxl_shader::on_draw()
	{
		for (ui8 bi = 0; bi < m_bufs.size(); bi++) {
			m_bufs[bi]->on_draw();
			glUniformBlockBinding(m_ogl_id, bi, bi);
		}
		for (ui8 bi = 0; bi < m_txrs.size(); bi++) {
			m_txrs[bi]->set_txr_slot(bi);
			m_txrs[bi]->on_draw();
			glUniform1i(bi, bi);
		}
	}
	bit pxl_shader::compile()
	{
		if (m_ogl_id != 0) { glDeleteShader(m_ogl_id); m_ogl_id = 0; }
		m_ogl_id = glCreateShader(GL_FRAGMENT_SHADER);
		m_txrs.clear();
		m_bufs.clear();

		if (!code_proc()) { return false; }
		cstring shader_source = &get_source_code()[0];
		glShaderSource(m_ogl_id, 1, &shader_source, nullptr);
		glCompileShader(m_ogl_id);

		return ogl_get_err_log(get_shd_type(), m_ogl_id);
	}
	bit pxl_shader::code_proc() {
		if (m_info.source_code.empty() || m_info.source_code == "default") { return false; }
		str_stream stm_code(get_source_code());
		dstring str_buf = "";
		dstring name = "";
		si32 count = 1;
		si32 ncurr = 0;

		while (std::getline(stm_code, str_buf, ' ')) {
			if ((ncurr = str_buf.find("layout")) != -1) {
				// go back to the beginning
				stm_code.seekg(-static_cast<si32>(strlen(&str_buf[0])), std::ios_base::cur);
				std::getline(stm_code, str_buf, ';');
				if ((ncurr = str_buf.find("in ")) != -1) { }
				else if ((ncurr = str_buf.find("uniform ")) != -1) {
					m_bufs.push_back(mem_ref<shd_buf>());
					m_gfx->new_cmp<shd_buf>();
					m_bufs.back().set_ref(m_gfx->get_cmp<a_gfx_buf>(2));
					auto& buf = *m_bufs.back();

					stm_code.seekg(-static_cast<si32>(str_buf.length()) + ncurr, std::ios_base::cur);
					stm_code >> str_buf;	// read the token ")uniform{"

					stm_code >> name;	// read the name
					if ((ncurr = name.find("{")) != -1) {
						if (name.length() > ncurr) { stm_code.seekg(-static_cast<si32>(name.length()), std::ios_base::cur); }
						name = name.substr(0, ncurr);
					}
					buf.add_block(shd_block(&name[0], buf.get_blocks().size()));
					// come back and read the entire uniform block
					stm_code.seekg(-static_cast<si32>(str_buf.length()) + ncurr, std::ios_base::cur);
					std::getline(stm_code, str_buf, '{');
					std::getline(stm_code, str_buf, '}');
					str_stream stmBlock(str_buf);
					while (stmBlock >> str_buf) {				// read the type
						std::getline(stmBlock, name, ';');	// read the name
						buf.get_blocks().back().elems.push_back(shd_elem(&name[0],
							convert_enum<cstring, data_types>(&str_buf[0]), count));

					}
				}
			}
			else if ((ncurr = str_buf.find("uniform")) != -1) {
				stm_code >> str_buf;
				stm_code >> name;
				if (str_buf == "sampler2D") {
					m_txrs.push_back(mem_ref<a_texture>());
				}
				else { throw error("the only supported uniform is a sampler"); }
			}
		}

		return true;
	}
}
namespace NWG
{
	gmt_shader::gmt_shader(gfx_engine& graphics, cstring name) :
		shader(graphics, name, SHD_GEOMETRY) { }
	gmt_shader::~gmt_shader() { }
	// --core_methods
	void gmt_shader::on_draw() {
		for (ui8 bi = 0; bi < m_bufs.size(); bi++) {
			m_bufs[bi]->on_draw();
			glUniformBlockBinding(m_ogl_id, bi, bi);
		}
		for (ui8 bi = 0; bi < m_txrs.size(); bi++) {
			m_txrs[bi]->set_txr_slot(bi);
			m_txrs[bi]->on_draw();
			glUniform1i(bi, bi);
		}
	}
	bit gmt_shader::compile()
	{
		if (m_ogl_id != 0) { glDeleteShader(m_ogl_id); m_ogl_id = 0; }
		m_ogl_id = glCreateShader(GL_FRAGMENT_SHADER);
		m_txrs.clear();
		m_bufs.clear();

		if (!code_proc()) { return false; }
		cstring shader_source = &get_source_code()[0];
		glShaderSource(m_ogl_id, 1, &shader_source, nullptr);
		glCompileShader(m_ogl_id);

		return ogl_get_err_log(get_shd_type(), m_ogl_id);
	}
	bit gmt_shader::code_proc() {
		return true;
	}
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
#include <lib/nwg_dx_loader.h>
namespace NWG
{
	Shader::Shader(gfx_engine& graphics, cstring name, shader_types sType) :
		t_ent(), a_gfx_cmp(graphics), ACodeRes(name),
		m_sType(sType), m_pProg(nullptr), m_shdLayout(ShaderLayout()),
		m_pBlob(nullptr) { }
	Shader::~Shader() { if (m_pBlob != nullptr) { m_pBlob->Release(); m_pBlob = nullptr; } }
	// --setters
	void Shader::SetProg(gfx_material* pProg) { m_pProg = pProg; }
	// --data_methods
	bool Shader::SaveF(cstring file_path)
	{
		return true;
	}
	bool Shader::LoadF(cstring file_path)
	{
		return true;
	}
}

namespace NWG
{
	vtx_shader::vtx_shader(gfx_engine& graphics, cstring name) :
		Shader(graphics, name, SHD_VERTEX),
		m_inLayout(input_layout(graphics)),
		m_native(nullptr) { }
	vtx_shader::~vtx_shader() { if (m_native != nullptr) { m_native->Release(); m_native = nullptr; } }
	// --core_methods
	void vtx_shader::Bind()
	{
		m_gfx->GetContext()->VSSetShader(m_native, NULL, NULL);
		m_inLayout.Bind();
	}
	bool vtx_shader::Compile()
	{
		if (m_native != nullptr) { m_native->Release(); m_native = nullptr; }
		if (m_pBlob != nullptr) { m_pBlob->Release(); m_pBlob = nullptr; }
		
		HRESULT hRes = 0;
		if ((hRes = D3DCompile(
			&m_strCode[0],		// source code
			m_strCode.length(),	// source code length
			NULL,				// source name
			NULL,				// defines
			NULL,				// includes
			"main",				// entry point name
			"vs_4_0",			// target
			0u,					// flags1
			0u,					// flags2
			&m_pBlob,			// where to store the code
			NULL				// blob for error messages
		)) < 0u) { return false; }
		if (m_pBlob == nullptr) { return false; }

		m_gfx->GetDevice()->Createvtx_shader(m_pBlob->GetBufferPointer(), m_pBlob->GetBufferSize(), NULL, &m_native);
		
		m_gfx->GetContext()->VSSetShader(m_native, NULL, NULL);
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
	pxl_shader::pxl_shader(gfx_engine& graphics, cstring name) :
		Shader(graphics, name, SHD_PIXEL),
		m_native(nullptr) { }
	pxl_shader::~pxl_shader() { if (m_native != nullptr) { m_native->Release(); m_native = nullptr; } }
	// --core_methods
	void pxl_shader::Bind() { m_gfx->GetContext()->PSSetShader(m_native, NULL, NULL); }
	bool pxl_shader::Compile()
	{
		if (m_native != nullptr) { m_native->Release(); m_native = nullptr; }
		if (m_pBlob != nullptr) { m_pBlob->Release(); m_pBlob = nullptr; }

		HRESULT hRes = 0;
		if ((hRes = D3DCompile(
			&m_strCode[0],		// source code
			m_strCode.length(),	// source code length
			NULL,				// source name
			NULL,				// defines
			NULL,				// includes
			"main",				// entry point name
			"ps_4_0",			// target
			0u,					// flags1
			0u,					// flags2
			&m_pBlob,			// where to store the code
			NULL				// blob for error messages
		)) < 0u) {
			return false;
		}
		if (m_pBlob == nullptr) { return false; }

		m_gfx->GetContext()->PSSetShader(m_native, NULL, NULL);
		m_gfx->GetDevice()->Createpxl_shader(m_pBlob->GetBufferPointer(), m_pBlob->GetBufferSize(), NULL, &m_native);
		
		return true;
	}
}
namespace NWG
{
	gmt_shader::gmt_shader(gfx_engine& graphics, cstring name) :
		Shader(graphics, name, SHD_GEOMETRY) { }
	gmt_shader::~gmt_shader() { }
	// --core_methods
	void gmt_shader::Bind() { for (auto& itBuf : m_Bufs) { itBuf->Bind(); } }
	bool gmt_shader::Compile()
	{
		if (m_ogl_id != 0) { glDeleteShader(m_ogl_id); m_ogl_id = 0; }
		m_ogl_id = glCreateShader(GL_FRAGMENT_SHADER);

		if (!CodeProc()) { return false; }
		cstring strSource = &m_strCode[0];
		glShaderSource(m_ogl_id, 1, &strSource, nullptr);
		glCompileShader(m_ogl_id);
		glAttachShader(m_pProg == nullptr ? 0 : m_pProg->get_ogl_id(), m_ogl_id);

		return ogl_get_err_log(m_sType, m_ogl_id);
	}
	bool gmt_shader::CodeProc() {
		return true;
	}
}
#endif
#endif	// NWG_GAPI