#include <nwg_pch.hpp>
#include "nwg_shd_gmt.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#include <lib/nwg_load_shd.h>
#include <lib/nwg_load_mtl.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	shd_gmt::shd_gmt(gfx_engine& graphics) :
		a_shd(graphics)
	{
	}
	shd_gmt::~shd_gmt() { }
	// --setters
	// --operators
	stm_out& shd_gmt::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& shd_gmt::operator>>(stm_in& stm) {
		return stm;
	}
	// --==<core_methods>==--
	bit shd_gmt::remake(cstr source_code)
	{
		m_src_code = source_code;
		if (m_handle != 0) { glDeleteShader(m_handle); m_handle = 0; }
		if (!code_proc()) { return false; }
		m_handle = glCreateShader(GL_GEOMETRY_SHADER);

		cstr shd_source = &m_src_code[0];
		glShaderSource(m_handle, 1, &shd_source, nullptr);
		glCompileShader(m_handle);

		if (!gfx_get_err_log(SHD_GEOMETRY, m_handle)) { return false; }

		return true;
	}
	void shd_gmt::on_draw() {
		for (ui8 bi = 0; bi < m_rscs.size(); bi++) {
			m_rscs[bi]->on_draw();
			glUniformBlockBinding(m_handle, bi, bi);
		}
	}
	// --==</core_methods>==--
	// --==<implemetation_methods>==--
	bit shd_gmt::code_proc() {
		if (m_src_code.empty() || m_src_code == "default") { return false; }
		return true;
	}
	// --==</implemetation_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	shd_gmt::shd_gmt(gfx_engine& graphics) :
		a_shd(graphics),
		m_native(nullptr)
	{
	}
	shd_gmt::~shd_gmt() { if (m_native != nullptr) { m_native->Release(); m_native = nullptr; } }
	// --setters
	// --operators
	stm_out& shd_gmt::operator<<(stm_out& stm) const {
		return stm;
	}
	stm_in& shd_gmt::operator>>(stm_in& stm) {
		return stm;
	}
	// --==<core_methods>==--
	bit shd_gmt::remake(cstr source_code)
	{
		m_src_code = source_code;
		return false;
	}
	void shd_gmt::on_draw()
	{
		for (auto& irsc : m_rscs) {
			irsc->on_draw();
		}
	}
	// --==</core_methods>==--
	// --==<implementation_methods>==--
	bit shd_gmt::code_proc() {
		return true;
	}
	// --==</implementation_methods>==--
}
#endif
#endif	// NW_GAPI