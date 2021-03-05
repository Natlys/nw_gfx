#include <nwg_pch.hpp>
#include "nwg_tools.h"
#pragma warning (disable: 4312)
#if (defined NWG_GAPI)
namespace NWG
{
	gfx_context_info::gfx_context_info(cstring str_renderer, cstring str_version,
		cstring str_vendor, cstring str_shader_lang) :
		renderer("default"), version("default"), vendor("default"), shader_language("default")
	{
		strcpy_s(&renderer[0], 256, &str_renderer[0]);
		strcpy_s(&version[0], 256, &str_version[0]);
		strcpy_s(&vendor[0], 256, &str_vendor[0]);
		strcpy_s(&shader_language[0], 256, &shader_language[0]);
	}
	// --operators
	out_stream& gfx_context_info::operator<<(out_stream& stm) const {
		return stm <<
			"--==<graphics_context_info>==--" << std::endl <<
			"graphics context: " << &version[0] << std::endl <<
			"renderer: " << &renderer[0] << std::endl <<
			"vendor: " << &vendor[0] << std::endl <<
			"shading language: " << &shader_language[0] << std::endl <<
			"--==</graphics_info>==--" << std::endl;
	}
	in_stream& gfx_context_info::operator>>(in_stream& stm) {
		return stm >>
			version >> renderer >> version >> vendor >> shader_language;
	}
}
#if (NWG_GAPI & NWG_GAPI_OGL)
#include <lib/nwg_ogl_v1.h>
#include <lib/nwg_ogl_v2.h>
#include <lib/nwg_ogl_v3.h>
#include <lib/nwg_ogl_arb.h>
// --functions
namespace NWG
{
	// glGetError gets last message and clears errorLog
	void ogl_clear_err() { while (glGetError() != GL_NO_ERROR); }
	bool ogl_get_err_log(cstring strLoc, cstring strFile, int nLine)
	{
		si32 err_code = 0u;
		while ((err_code = glGetError()) != GL_NO_ERROR) {
			dstring err_comment;
			switch (err_code) {
			case GL_INVALID_ENUM: err_comment = "INVALID_ENUM"; break;
			case GL_INVALID_VALUE: err_comment = "INVALID_VALUE"; break;
			case GL_INVALID_OPERATION: err_comment = "INVALID_OPERATION"; break;
			case GL_STACK_OVERFLOW: err_comment = "STACK_OVERFLOW"; break;
			case GL_STACK_UNDERFLOW: err_comment = "STACK_UNDERFLOW"; break;
			case GL_OUT_OF_MEMORY: err_comment = "OUT_OF_MEMORY"; break;
			}
			throw (error(&err_comment[0], err_code, strLoc, nLine));
			return false;
		}
		return true;
	}
	int ogl_get_err_log(shader_types shd_type, si32 idx)
	{
		if (idx == 0) { return ERC_UNKNOWN_ID; }
		si32 success_code = 0;
		si32 log_size = 0;
		dstring log_string;
		cstring type_string = convert_enum<shader_types, cstring>(shd_type);
		if (shd_type != SHD_PROG) {
			glGetShaderiv(idx, GL_COMPILE_STATUS, &success_code);
			if (success_code == false) {
				glGetShaderiv(idx, GL_INFO_LOG_LENGTH, &log_size);
				log_string.resize(log_size);
				glGetshader_infoLog(idx, log_size, NULL, &log_string[0]);
				throw error(&log_string[0], ERC_COMPILLATION, __FILE__, __LINE__);
				return ERC_COMPILLATION;
			}
		}
		else {
			glGetProgramiv(idx, GL_LINK_STATUS, &success_code);
			if (success_code == false) {
				glGetProgramiv(idx, GL_INFO_LOG_LENGTH, &log_size);
				log_string.resize(log_size);
				glGetProgramInfoLog(idx, log_size, NULL, &log_string[0]);
				throw error(&log_string[0], ERC_LINKAGE, __FILE__, __LINE__);
				return ERC_LINKAGE;
			}
		}
		return success_code;
	}
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
#include <lib/nwg_dx_loader.h>
template<> data_types convert_enum<cstring, data_types>(cstring type_string) {
	if (str_is_equal(type_string, "int")) { return DT_SINT32; }
	if (str_is_equal(type_string, "int2")) { return DT_VEC2_SINT32; }
	if (str_is_equal(type_string, "int3")) { return DT_VEC3_SINT32; }
	if (str_is_equal(type_string, "int4")) { return DT_VEC4_SINT32; }
	if (str_is_equal(type_string, "float")) { return DT_FLOAT32; }
	if (str_is_equal(type_string, "float2")) { return DT_VEC2_FLOAT32; }
	if (str_is_equal(type_string, "float3")) { return DT_VEC3_FLOAT32; }
	if (str_is_equal(type_string, "float4")) { return DT_VEC4_FLOAT32; }
	return DT_DEFAULT;
	}
template<> DXGI_FORMAT convert_enum<data_types, DXGI_FORMAT>(data_types dType) {
	switch (dType) {
	case DT_BOOL: return DXGI_FORMAT_R8_UINT;
	case DT_SINT8: return DXGI_FORMAT_R8_SINT;
	case DT_VEC2_SINT8: return DXGI_FORMAT_R8_SINT;
	case DT_VEC3_SINT8: case DT_VEC4_SINT8: return DXGI_FORMAT_R8G8B8A8_SINT;

	case DT_UINT8: return DXGI_FORMAT_R8_UINT;
	case DT_VEC2_UINT8: return DXGI_FORMAT_R8_UINT;
	case DT_VEC3_UINT8: return DXGI_FORMAT_R8G8B8A8_UINT;
	case DT_VEC4_UINT8: return DXGI_FORMAT_R8G8B8A8_UINT;

	case DT_SINT16: return DXGI_FORMAT_R16_SINT;
	case DT_VEC2_SINT16: return DXGI_FORMAT_R16_SINT;
	case DT_VEC3_SINT16: return DXGI_FORMAT_R16G16B16A16_SINT;
	case DT_VEC4_SINT16: return DXGI_FORMAT_R16G16B16A16_SINT;

	case DT_UINT16: return DXGI_FORMAT_R16_UINT;
	case DT_VEC2_UINT16: return DXGI_FORMAT_R16_UINT;
	case DT_VEC3_UINT16: return DXGI_FORMAT_R16G16B16A16_UINT;
	case DT_VEC4_UINT16: return DXGI_FORMAT_R16G16B16A16_UINT;

	case DT_SINT32: return DXGI_FORMAT_R32_SINT;
	case DT_VEC2_SINT32: return DXGI_FORMAT_R32_SINT;
	case DT_VEC3_SINT32: return DXGI_FORMAT_R32G32B32_SINT;
	case DT_VEC4_SINT32: return DXGI_FORMAT_R32G32B32A32_SINT;

	case DT_UINT32: return DXGI_FORMAT_R32_UINT;
	case DT_VEC2_UINT32: return DXGI_FORMAT_R32_UINT;
	case DT_VEC3_UINT32: return DXGI_FORMAT_R32G32B32_UINT;
	case DT_VEC4_UINT32: return DXGI_FORMAT_R32G32B32A32_UINT;

	case DT_FLOAT32: return DXGI_FORMAT_R32_FLOAT;
	case DT_VEC2_FLOAT32: return DXGI_FORMAT_R32G32_FLOAT;
	case DT_VEC3_FLOAT32: return DXGI_FORMAT_R32G32B32_FLOAT;
	case DT_VEC4_FLOAT32: return DXGI_FORMAT_R32G32B32A32_FLOAT;

	default: throw error("unsupported format", ERC_NO_SUPPORT); break;
	}
	return DXGI_FORMAT_R32_FLOAT;
}
template<> D3D11_PRIMITIVE_TOPOLOGY convert_enum<gfx_primitives, D3D11_PRIMITIVE_TOPOLOGY>(gfx_primitives gpType) {
	switch (gpType) {
	case GPT_POINTS: return D3D11_PRIMITIVE_TOPOLOGY_POINTLIST; break;
	case GPT_TRIANGLES: return D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST; break;
	case GPT_TRIANGLE_STRIP: return D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP; break;
	case GPT_TRIANGLE_FAN: return D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ; break;
	case GPT_LINES: return D3D11_PRIMITIVE_TOPOLOGY_LINELIST; break;
	case GPT_LINE_LOOP: return D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ; break;
	case GPT_LINE_STRIP: return D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP; break;
	default: throw error("unavailable primitive topology", ERC_INVALID_ENUM); break;
	}
	return D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
}
template<> si32 convert_enum<texture_types, si32>(texture_types txr_type) {
	switch (txr_type) {
	case TXT_1D: return 0; break;
	case TXT_2D: return 0; break;
	case TXT_3D: return 0; break;
	default: throw error("unsupported texture type", ERC_NO_SUPPORT); break;
	}
	return 0;
}
template<> DXGI_FORMAT convert_enum <pixel_formats, DXGI_FORMAT>(pixel_formats pxl_format) {
	switch (pxl_format) {
	case PXF_R32_SINT32: return DXGI_FORMAT_R32_SINT; break;
	case PXF_R8G8B8_SINT32: return DXGI_FORMAT_R8G8B8A8_SNORM; break;
	case PXF_R8G8B8_UINT32: return DXGI_FORMAT_B8G8R8A8_UNORM; break;
	case PXF_R8G8B8A8_SINT32: return DXGI_FORMAT_R8G8B8A8_SNORM; break;
	case PXF_R8G8B8A8_UINT32: return DXGI_FORMAT_B8G8R8A8_UNORM; break;
	default: throw error("unsupported pixel format", ERC_NO_SUPPORT); break;
	}
	return DXGI_FORMAT_R8G8B8A8_UNORM;
}
template<> D3D11_FILTER convert_enum <texture_filters, D3D11_FILTER>(texture_filters txr_filter) {
	switch (txr_filter) {
	case TXF_LINEAR: return D3D11_FILTER_MIN_MAG_MIP_LINEAR; break;
	case TXF_NEAREST: return D3D11_FILTER_MIN_MAG_MIP_POINT; break;
	default: throw error("unsupported pixel filter", ERC_NO_SUPPORT); break;
	}
	return D3D11_FILTER_MIN_MAG_MIP_POINT;
}
template<> D3D11_TEXTURE_ADDRESS_MODE convert_enum<texture_wraps, D3D11_TEXTURE_ADDRESS_MODE>(texture_wraps txr_wrap) {
	switch (txr_wrap) {
	case TXW_REPEAT: return D3D11_TEXTURE_ADDRESS_WRAP; break;
	case TXW_CLAMP: return D3D11_TEXTURE_ADDRESS_CLAMP; break;
	case TXW_BORDER: return D3D11_TEXTURE_ADDRESS_CLAMP; break;
	default: throw error("unsupported pixel filter", ERC_NO_SUPPORT); break;
	}
	return D3D11_TEXTURE_ADDRESS_WRAP;
}
namespace NWG
{
	void DxClearErr() {
		//
	}
	bool DxErrLog(cstring stinfo, cstring strFile, int nLine) {
		return false;
	}
}
#endif
#endif	// NWG_GAPI