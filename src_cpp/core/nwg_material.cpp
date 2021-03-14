#include <nwg_pch.hpp>
#include "nwg_material.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#if (NW_GAPI & NW_GAPI_OGL)
#include <lib/nwg_load_txr.h>
#include <lib/nwg_load_mtl.h>
namespace NW
{
	gfx_material::gfx_material(gfx_engine& graphics, cstring name) :
		t_gfx_rsc(graphics), a_data_rsc(name),
		m_ogl_id(0) { }
	gfx_material::~gfx_material() { if (m_ogl_id != 0) { glDeleteProgram(m_ogl_id); m_ogl_id = 0; } }
	// --setters
	template<> void gfx_material::set_value<si32>(si32 idx, const si32& data, ui32 count) { glUniform1i(idx, data); }
	template<> void gfx_material::set_value<ui32>(si32 idx, const ui32& data, ui32 count) { glUniform1ui(idx, data); }
	template<> void gfx_material::set_value<m4f>(si32 idx, const m4f& data, ui32 count) { glUniform4fv(idx, 1, &data[0][0]); }
	void gfx_material::add_shader(shader& ref) {
		m_shds.push_back(ref);
	}
	void gfx_material::rmv_shader(ui8 idx) {
		m_shds.erase(m_shds.begin() + idx % m_shds.size());
	}
	void gfx_material::add_texture(texture& ref) {
		m_txrs.push_back(ref);
	}
	void gfx_material::rmv_texture(ui8 idx) {
		m_txrs.erase(m_txrs.begin() + idx % m_txrs.size());
	}
	// --operators
	out_stream& gfx_material::operator<<(out_stream& stm) const {
		return stm;
	}
	in_stream& gfx_material::operator>>(in_stream& stm) {
		return stm;
	}
	// --==<core_methods>==--
	void gfx_material::on_draw() {
		glUseProgram(m_ogl_id);
		for (auto& ishd : m_shds) {
			ishd->on_draw();
			for (auto& itxr : m_txrs) {
				ishd->bind_txr(itxr);
			}
		}
	}
	bool gfx_material::remake()
	{
		if (m_ogl_id != 0) { glDeleteProgram(m_ogl_id); m_ogl_id = 0; }
		m_ogl_id = glCreateProgram();
		if (m_shds.size() == 0) { return false; }

		for (ui8 ish = 0; ish < m_shds.size(); ish++) {
			glAttachShader(m_ogl_id, m_shds[ish]->get_ogl_id());
		}

		glLinkProgram(m_ogl_id);
		if (!ogl_get_err_log(SHD_PROG, m_ogl_id)) { return false; }

		return true;
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
#include <lib/nwg_dx_loader.h>
namespace NW {
	gfx_material::gfx_material(gfx_engine& graphics, const char* name) :
		t_ent(), a_gfx_rsc(graphics), a_data_rsc(name),
		m_shdLayout(ShaderLayout()) {  }
	gfx_material::~gfx_material() { }
	// --==<core_methods>==--
	void gfx_material::Bind() {
		for (auto& itShader : m_Shaders) {
			itShader->Bind();
		}
	}
	bool gfx_material::Remake(const gfx_material_info& info)
	{
		return false;
	}
	// --==</core_methods>==--
	// --==<data_methods>==--
	bool gfx_material::SaveF(const char* file_path)
	{
		gfx_material_info spInfo{ 0 };
		strcpy_s(&spInfo.name[0], 128, &m_name[0]);
		strcpy_s(&spInfo.strGApi[0], 16, "directx");

		io_stream_str stm_file;
		stm_file << spInfo;
		
		return data_sys::SaveFString(file_path, &stm_file.str()[0], stm_file.str().size());
	}
	bool gfx_material::LoadF(const char* file_path)
	{
		String strFile = "";
		if (!data_sys::LoadFString(file_path, strFile)) { throw(error("failed to load a shader")); }
		io_stream_str stm_file(strFile);
		
		gfx_material_info spInfo{ 0 };
		stm_file >> spInfo;

		return Remake(spInfo);
	}
	// --==</data_methods>==--
}
#endif
#endif	// NW_GAPI