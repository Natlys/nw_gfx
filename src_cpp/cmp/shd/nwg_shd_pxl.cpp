#include <nwg_pch.hpp>
#include "nwg_shd_pxl.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#include <lib/nwg_load_shd.h>
#include <lib/nwg_load_mtl.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	shd_pxl::shd_pxl(gfx_engine& graphics) :
		a_shd(graphics)
	{
	}
	shd_pxl::~shd_pxl() { }
	// --operators
	stm_out& shd_pxl::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& shd_pxl::operator>>(stm_in& stm) {
		return stm;
	}
	// --==<core_methods>==--
	bit shd_pxl::remake(cstr source_code)
	{
		m_src_code = source_code;
		if (m_handle != 0) { glDeleteShader(m_handle); m_handle = 0; }
		if (!code_proc()) { return false; }
		m_handle = glCreateShader(GL_FRAGMENT_SHADER);
		
		cstr shd_source = &m_src_code[0];
		glShaderSource(m_handle, 1, &shd_source, nullptr);
		glCompileShader(m_handle);

		if (!gfx_get_err_log(SHD_PIXEL, m_handle)) { return false; }

		return true;
	}
	void shd_pxl::on_draw()
	{
		for (ui8 bi = 0; bi < m_rscs.size(); bi++) {
			m_rscs[bi]->on_draw();
			glUniformBlockBinding(m_handle, bi, bi);
		}
	}
	// --==</core_methods>==--
	// --==<implementation_methods>==--
	bit shd_pxl::code_proc() {
		if (m_src_code.empty() || m_src_code == "default") { return false; }
		stm_io_str stm_code(m_src_code);
		dstr str_buf = "";
		dstr name = "";
		si32 count = 1;
		si32 ncurr = 0;

#if false
		while (std::getline(stm_code, str_buf, ' ')) {
			if ((ncurr = str_buf.find("layout")) != -1) {
				stm_code.seekg(stm_code.gcount(), stm_code.cur);
				std::getline(stm_code, str_buf, ')');
				if ((ncurr = str_buf.find("location")) != -1) {		// single attribute
					shd_elem elem;
					if ((ncurr = str_buf.find("=")) != -1) {
						stm_code.seekg((strlen(&str_buf[0] - ncurr)), stm_code.cur);
						stm_code >> elem.idx;
						stm_code.get();	// get rid of ')'
					}
					stm_code >> str_buf;
					if (str_buf == "in") { throw error("pixel shader must not have input layouts"); return false; }
					else if (str_buf == "uniform") {
					}
				}
				else if ((ncurr = str_buf.find("std140")) != -1) {	// uniform block
					// read the semantic
					stm_code >> str_buf;
					if (str_buf == "uniform") {
						buffer sbuf;
						m_gfx->new_rsc<buf_shd>(sbuf);
						// read the name
						stm_code >> str_buf;
						std::getline(stm_code, str_buf, '{');
						std::getline(stm_code, str_buf, '}');
						io_stream_str stm_buf(str_buf);
						while (std::getline(stm_buf, str_buf, ' ')) {	// read the type
							std::getline(stm_buf, name, ';');			// read the name
							sbuf->add_elem(shd_elem(&name[0], convert_enum<cstr, data_types>(&str_buf[0]), count));
						}
						if (!sbuf->remake()) { return false; }
						m_bufs.push_back(sbuf);
					}
					else { throw error("unknow syntax"); return false; }
				}
				else { throw error("unknown syntax"); return false; }
#if false
				// go back to the beginning
				stm_code.seekg(-static_cast<si32>(strlen(&str_buf[0])), std::ios_base::cur);
				std::getline(stm_code, str_buf, ';');
				if ((ncurr = str_buf.find("in ")) != -1) {
					stm_code.seekg(-static_cast<si32>(str_buf.length()) + ncurr, std::ios_base::cur);
					stm_code >> str_buf;	// read the token "in "

					stm_code >> str_buf;	// read the type
					std::getline(stm_code, name, ';');
					m_layout.add_elem(shd_elem(&name[0], convert_enum<cstr, data_types>(&str_buf[0]), count));
				}
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
					io_stream_str stm_block(str_buf);
					while (stm_block >> str_buf) {			// read element type
						std::getline(stm_block, name, ';');	// read element name
						buf.get_elems().push_back(shd_elem(&name[0], convert_enum<cstr, data_types>(&str_buf[0]), count));
					}
					buf.remake(buf.get_elems());
				}
#endif
			}
			else if ((ncurr = str_buf.find("uniform")) != -1) { throw error("uniform layout is not specified"); return false; }
		}
#endif

		return true;
	}
	// --==</implementation_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	shd_pxl::shd_pxl(gfx_engine& graphics) :
		a_shd(graphics),
		m_native(nullptr)
	{
	}
	shd_pxl::~shd_pxl() { if (m_native != nullptr) { m_native->Release(); m_native = nullptr; } }
	// --setters
	// --operators
	stm_out& shd_pxl::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& shd_pxl::operator>>(stm_in& stm) {
		return stm;
	}
	// --==<core_methods>==--
	bit shd_pxl::remake(cstr source_code)
	{
		m_src_code = source_code;
		if (m_handle != nullptr) { m_handle->Release(); m_handle = nullptr; }
		if (m_native != nullptr) { m_native->Release(); m_native = nullptr; }
		if (m_src_code == "default") { return false; }

		HRESULT h_result = 0;
		if ((h_result = D3DCompile(
			&m_src_code[0],		// source code
			m_src_code.size(),	// source code length
			NULL,				// source name
			NULL,				// defines
			NULL,				// includes
			"main",				// entry point name
			"ps_4_0",			// target
			0u,					// flags1
			0u,					// flags2
			&m_handle,			// where to store the code
			NULL				// blob for error messages
		)) != S_OK) { return false; }
		if (m_handle == nullptr) { return false; }

		m_gfx->get_dvch()->CreatePixelShader(m_handle->GetBufferPointer(), m_handle->GetBufferSize(), NULL, &m_native);
		if (m_native == nullptr) { return false; }
		m_gfx->get_ctxh()->PSSetShader(m_native, NULL, NULL);
		
		return true;
	}
	void shd_pxl::on_draw()
	{
		m_gfx->get_ctxh()->PSSetShader(m_native, NULL, NULL);
		for (auto& irsc : m_rscs) {
			irsc->on_draw();
		}
	}
	// --==</core_methods>==--
}
#endif
#endif	// NW_GAPI