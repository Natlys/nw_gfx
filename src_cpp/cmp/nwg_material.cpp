#include <nwg_pch.hpp>
#include "nwg_material.h"
#if (defined NWG_GAPI)
#include <core/nwg_engine.h>
namespace NWG
{
	out_stream& gfx_material_info::operator<<(out_stream& stm) const {
		return stm <<
			"--==<shader_program_info>==--" << std::endl <<
			"gapi:" << gapi_type <<		";" << std::endl <<
			"name:" << name <<		";" << std::endl <<
			"src_vtx:" << source_vtx <<	";" << std::endl <<
			"src_pxl:" << source_pxl <<	";" << std::endl <<
			"src_gmt:" << source_gmt <<	";" << std::endl <<
			"--==</shader_program_info>==--" << std::endl;
	}
	in_stream& gfx_material_info::operator>>(in_stream& stm) {
		char8 str_buf[256];
		si32 unGfxApi = 0;
		
		stm.getline(str_buf, 256, ':');
		if (!(stm >> unGfxApi)) { throw error("invalid format"); }
		stm.get();
		
		stm.getline(str_buf, 256, ':');
		std::getline(stm, name, ';');
		stm.get();
		stm.getline(str_buf, 256, ':');
		std::getline(stm, source_vtx, ';');
		stm.get();
		stm.getline(str_buf, 256, ':');
		std::getline(stm, source_pxl, ';');
		stm.get();
		stm.getline(str_buf, 256, ':');
		std::getline(stm, source_gmt, ';');
		stm.get();
		
		gapi_type = static_cast<gfx_api_types>(unGfxApi);

		return stm;
	}
}
#if (NWG_GAPI & NWG_GAPI_OGL)
#include <lib/nwg_ogl_v2.h>
#include <lib/nwg_ogl_v3.h>
#include <lib/nwg_ogl_arb.h>
namespace NWG {
	gfx_material::gfx_material(gfx_engine& graphics, cstring name) :
		t_gfx_cmp(graphics), a_data_res(name),
		m_ogl_id(0) { }
	gfx_material::~gfx_material() { if (m_ogl_id != 0) { glDeleteProgram(m_ogl_id); m_ogl_id = 0; } }
	// --setters
	template<> void gfx_material::set_value<si32>(si32 idx, const si32& data, ui32 count) { glUniform1i(idx, data); }
	template<> void gfx_material::set_value<ui32>(si32 idx, const ui32& data, ui32 count) { glUniform1ui(idx, data); }
	template<> void gfx_material::set_value<m4f32>(si32 idx, const m4f32& data, ui32 count) { glUniform4fv(idx, 1, &data[0][0]); }
	// --==<core_methods>==--
	void gfx_material::on_draw() {
		glUseProgram(m_ogl_id);
		for (auto& ishd : m_shds) { ishd->on_draw(); }
	}
	bool gfx_material::remake(const gfx_material_info& info)
	{
		if (m_ogl_id != 0) { glDeleteShader(m_ogl_id); m_ogl_id = 0; }
		m_ogl_id = glCreateProgram();
		m_shds.clear();

		if (info.gapi_type != GAPI_OPENGL) { throw error("wrong shader info!"); }
		set_name(&info.name[0]);

		shader_info shd_info;
		shd_info.gapi_type = GAPI_OPENGL;
		if (info.source_vtx != "default") {
			m_shds.push_back(mem_ref<shader>());
			m_gfx->new_cmp<vtx_shader>("shd_vtx");
			m_shds.back().set_ref(m_gfx->get_cmp<shader>(1));
			if (!data_sys::load_file(&info.source_vtx[0], shd_info)) { return false; }
			if (!m_shds.back()->remake(shd_info)) { throw error("shader was not loaded"); }
			glAttachShader(m_ogl_id, m_shds.back()->get_ogl_id());
		}
		if (info.source_vtx != "default") {
			m_shds.push_back(mem_ref<shader>());
			m_gfx->new_cmp<pxl_shader>("shd_pxl");
			m_shds.back().set_ref(m_gfx->get_cmp<shader>(2));
			if (!data_sys::load_file(&info.source_pxl[0], shd_info)) { return false; }
			if (!m_shds.back()->remake(shd_info)) { throw error("shader was not loaded"); }
			glAttachShader(m_ogl_id, m_shds.back()->get_ogl_id());
		}
		if (info.source_gmt != "default" && false) {
			m_shds.push_back(mem_ref<shader>());
			m_gfx->new_cmp<gmt_shader>("shd_gmt");
			m_shds.back().set_ref(m_gfx->get_cmp<shader>(3));
			if (!data_sys::load_file(&info.source_gmt[0], shd_info)) { return false; }
			if (!m_shds.back()->remake(shd_info)) { throw error("shader was not loaded"); }
			glAttachShader(m_ogl_id, m_shds.back()->get_ogl_id());
		}

		glLinkProgram(m_ogl_id);
		return (ogl_get_err_log(SHD_PROG, m_ogl_id));
	}
	// --==</core_methods>==--
	// --==<data_methods>==--
	bit gfx_material::save_file(cstring file_path)
	{
		gfx_material_info mtl_info;
		mtl_info.gapi_type = GAPI_OPENGL;
		mtl_info.name = m_name;
		if (auto& shd = get_shader(SHD_VERTEX)) { mtl_info.source_vtx = shd->get_source_code(); }
		if (auto& shd = get_shader(SHD_PIXEL)) { mtl_info.source_pxl = shd->get_source_code(); }
		if (auto& shd = get_shader(SHD_GEOMETRY)) { mtl_info.source_gmt = shd->get_source_code(); }

		str_stream stm_file;
		stm_file << mtl_info;

		return data_sys::save_file(file_path, stm_file.str());
	}
	bit gfx_material::load_file(cstring file_path)
	{
		if (!data_sys::load_file(file_path, m_info)) { throw(error("failed to load a shader")); }
		return remake(m_info);
	}
	// --==</data_methods>==--
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
#include <lib/nwg_dx_loader.h>
namespace NWG {
	gfx_material::gfx_material(gfx_engine& graphics, const char* name) :
		t_ent(), a_gfx_cmp(graphics), a_data_res(name),
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

		str_stream stm_file;
		stm_file << spInfo;
		
		return data_sys::SaveFString(file_path, &stm_file.str()[0], stm_file.str().size());
	}
	bool gfx_material::LoadF(const char* file_path)
	{
		String strFile = "";
		if (!data_sys::LoadFString(file_path, strFile)) { throw(error("failed to load a shader")); }
		str_stream stm_file(strFile);
		
		gfx_material_info spInfo{ 0 };
		stm_file >> spInfo;

		return Remake(spInfo);
	}
	// --==</data_methods>==--
}
#endif
#endif	// NWG_GAPI