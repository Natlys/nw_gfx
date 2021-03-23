#include <nwg_pch.hpp>
#include "nwg_shd.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#include <lib/nwg_load_shd.h>
#include <lib/nwg_load_mtl.h>
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	a_shd::a_shd(gfx_engine& graphics) :
		t_cmp(), a_gfx_cmp(graphics), a_data_cmp(),
		m_handle(0), m_src_code("default"), m_rscs(rscs())
	{
	}
	a_shd::~a_shd() { if (m_handle != 0) { glDeleteShader(m_handle); m_handle = 0; } }
	// --setters
	void a_shd::add_rsc(rsc& ref) {
		m_rscs.push_back(ref);
	}
	void a_shd::rmv_rsc(ui8 idx) {
		m_rscs.erase(m_rscs.begin() + idx % m_rscs.size());
	}
	/// shader debugging
	bit gfx_get_err_log(shd_types shd_type, si32 idx)
	{
		if (idx == 0) { return false; }
		si32 success_code = 0;
		si32 log_size = 0;
		dstr log_string;
		cstr type_string = convert_enum<shd_types, cstr>(shd_type);
		if (shd_type != SHD_PROG) {
			glGetShaderiv(idx, GL_COMPILE_STATUS, &success_code);
			if (success_code == 0) {
				glGetShaderiv(idx, GL_INFO_LOG_LENGTH, &log_size);
				log_string.resize(log_size);
				glGetShaderInfoLog(idx, log_size, NULL, &log_string[0]);
				throw a_error(&log_string[0], ERC_COMPILLATION, __FILE__, __LINE__);
				return false;
			}
		}
		else {
			glGetProgramiv(idx, GL_LINK_STATUS, &success_code);
			if (success_code == 0) {
				glGetProgramiv(idx, GL_INFO_LOG_LENGTH, &log_size);
				log_string.resize(log_size);
				glGetProgramInfoLog(idx, log_size, NULL, &log_string[0]);
				throw a_error(&log_string[0], ERC_LINKAGE, __FILE__, __LINE__);
				return false;
			}
		}
		return success_code == 1;
	}
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	a_shd::a_shd(gfx_engine& graphics) :
		t_cmp(), a_gfx_cmp(graphics), a_data_cmp(),
		m_handle(nullptr), m_src_code("default"), m_rscs(rscs())
	{
	}
	a_shd::~a_shd() { if (m_handle != nullptr) { m_handle->Release(); m_handle = nullptr; } }
	// --setters
	void a_shd::add_rsc(rsc& ref) {
		m_rscs.push_back(ref);
	}
	void a_shd::rmv_rsc(ui8 idx) {
		m_rscs.erase(m_rscs.begin() + idx % m_rscs.size());
	}
}
#endif
#endif	// NW_GAPI