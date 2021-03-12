#include <nwg_pch.hpp>
#include "nwg_shader_pxl.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#include <core/nwg_buf_shd.h>
#if (NW_GAPI & NW_GAPI_OGL)
#include <lib/nwg_load_shd.h>
#include <lib/nwg_load_mtl.h>
namespace NW
{
	shader_pxl::shader_pxl(gfx_engine& graphics, cstring name) :
		a_shader(name), t_gfx_res(graphics)
	{
	}
	shader_pxl::~shader_pxl() { }
	// --operators
	out_stream& shader_pxl::operator<<(out_stream& stm) const {
		return stm;
	}
	in_stream& shader_pxl::operator>>(in_stream& stm) {
		return stm;
	}
	// --==<core_methods>==--
	bit shader_pxl::remake(cstring source_code)
	{
		set_source_code(source_code);
		m_bufs.clear();
		//m_txrs.clear();
		if (m_ogl_id != 0) { glDeleteShader(m_ogl_id); m_ogl_id = 0; }
		if (!code_proc()) { return false; }
		m_ogl_id = glCreateShader(GL_FRAGMENT_SHADER);
		
		cstring shader_source = &get_source_code()[0];
		glShaderSource(m_ogl_id, 1, &shader_source, nullptr);
		glCompileShader(m_ogl_id);

		if (!ogl_get_err_log(SHD_PIXEL, m_ogl_id)) { return false; }

		return true;
	}
	void shader_pxl::bind_texture(texture& ref) {
		ref->on_draw();
		glUniform1i(ref->get_slot(), ref->get_slot());
	}
	void shader_pxl::on_draw()
	{
		for (ui8 bi = 0; bi < m_bufs.size(); bi++) {
			m_bufs[bi]->on_draw();
			glUniformBlockBinding(m_ogl_id, bi, bi);
		}
		//for (ui8 bi = 0; bi < m_txrs.size(); bi++) {
		//	m_txrs[bi]->set_txr_slot(bi);
		//	m_txrs[bi]->on_draw();
		//	glUniform1i(bi, bi);
		//}
	}
	// --==</core_methods>==--
	// --==<implementation_methods>==--
	bit shader_pxl::code_proc() {
		if (m_source_code.empty() || m_source_code == "default") { return false; }
		io_stream_str stm_code(get_source_code());
		dstring str_buf = "";
		dstring name = "";
		si32 count = 1;
		si32 ncurr = 0;

		while (std::getline(stm_code, str_buf, ' ')) {
			if ((ncurr = str_buf.find("layout")) != -1) {
				// go back to the beginning
				stm_code.seekg(-static_cast<si32>(strlen(&str_buf[0])), std::ios_base::cur);
				std::getline(stm_code, str_buf, ';');
				if ((ncurr = str_buf.find("in ")) != -1) { throw error("pixel shader should not have input layouts"); return false; }
				else if ((ncurr = str_buf.find("uniform ")) != -1) {
					m_bufs.push_back(mem_ref<buf_shd>());
					m_gfx->new_rsc<buf_shd>(m_bufs.back());
					auto& buf = *m_bufs.back();
					buf.set_slot(m_bufs.size() - 1);
					// come back
					stm_code.seekg(-static_cast<si32>(str_buf.length()) + ncurr, std::ios_base::cur);
					stm_code >> str_buf;	// read the token ")uniform{"
					stm_code >> name;	// read the name
					if ((ncurr = name.find("{")) != -1) {
						if (name.length() > ncurr) { stm_code.seekg(-static_cast<si32>(name.length()), std::ios_base::cur); }
						name = name.substr(0, ncurr);
					}
					// come back
					stm_code.seekg(-static_cast<si32>(str_buf.length()) + ncurr, std::ios_base::cur);
					// read the entire uniform block
					std::getline(stm_code, str_buf, '{');
					std::getline(stm_code, str_buf, '}');
					io_stream_str stmBlock(str_buf);
					while (stmBlock >> str_buf) {			// read element type
						std::getline(stmBlock, name, ';');	// read element name
						buf.get_elems().push_back(shd_elem(&name[0], convert_enum<cstring, data_types>(&str_buf[0]), count));
					}
					buf.remake(buf.get_elems());
				}
			}
			else if ((ncurr = str_buf.find("uniform")) != -1) { throw error("uniform layout is not specified"); return false; }
		}

		return true;
	}
	// --==</implementation_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
#include <lib/nwg_dx_loader.h>
namespace NW
{
	Shader::Shader(gfx_engine& graphics, cstring name, shader_types sType) :
		t_ent(), a_gfx_rsc(graphics), ACodeRes(name),
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

namespace NW
{
	shader_vtx::shader_vtx(gfx_engine& graphics, cstring name) :
		Shader(graphics, name, SHD_VERTEX),
		m_inLayout(input_layout(graphics)),
		m_native(nullptr) { }
	shader_vtx::~shader_vtx() { if (m_native != nullptr) { m_native->Release(); m_native = nullptr; } }
	// --core_methods
	void shader_vtx::Bind()
	{
		m_gfx->GetContext()->VSSetShader(m_native, NULL, NULL);
		m_inLayout.Bind();
	}
	bool shader_vtx::Compile()
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

		m_gfx->GetDevice()->Createshader_vtx(m_pBlob->GetBufferPointer(), m_pBlob->GetBufferSize(), NULL, &m_native);
		
		m_gfx->GetContext()->VSSetShader(m_native, NULL, NULL);
		m_vtxLayout.AddElement(BufElem("vtx_crd", DtGet<V3f>(), 1, false));
		m_vtxLayout.AddElement(BufElem("tex_crd", DtGet<V2f>(), 1, false));
		m_vtxLayout.AddElement(BufElem("nrm_crd", DtGet<V3f>(), 1, false));
		m_inLayout.SetShader(this);
		m_inLayout.Remake();
		
		return true;
	}
}
namespace NW
{
	shader_pxl::shader_pxl(gfx_engine& graphics, cstring name) :
		Shader(graphics, name, SHD_PIXEL),
		m_native(nullptr) { }
	shader_pxl::~shader_pxl() { if (m_native != nullptr) { m_native->Release(); m_native = nullptr; } }
	// --core_methods
	void shader_pxl::Bind() { m_gfx->GetContext()->PSSetShader(m_native, NULL, NULL); }
	bool shader_pxl::Compile()
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
		m_gfx->GetDevice()->Createshader_pxl(m_pBlob->GetBufferPointer(), m_pBlob->GetBufferSize(), NULL, &m_native);
		
		return true;
	}
}
namespace NW
{
	shader_gmt::shader_gmt(gfx_engine& graphics, cstring name) :
		Shader(graphics, name, SHD_GEOMETRY) { }
	shader_gmt::~shader_gmt() { }
	// --core_methods
	void shader_gmt::Bind() { for (auto& itBuf : m_Bufs) { itBuf->Bind(); } }
	bool shader_gmt::Compile()
	{
		if (m_native != 0) { glDeleteShader(m_native); m_native = 0; }
		m_native = glCreateShader(GL_FRAGMENT_SHADER);

		if (!CodeProc()) { return false; }
		cstring strSource = &m_strCode[0];
		glShaderSource(m_native, 1, &strSource, nullptr);
		glCompileShader(m_native);
		glAttachShader(m_pProg == nullptr ? 0 : m_pProg->get_ogl_id(), m_native);

		return ogl_get_err_log(m_sType, m_native);
	}
	bool shader_gmt::CodeProc() {
		return true;
	}
}
#endif
#endif	// NW_GAPI