#include <nwg_pch.hpp>
#include "nwg_switch.h"
#ifdef NWG_GAPI
namespace NWG
{
	template<> cstring convert_enum<data_types, cstring>(data_types data_type) {
		switch (data_type) {
		case DT_BOOL: return "DT_BOOL";
		case DT_SINT8: return "DT_SINT8";
		case DT_VEC2_SINT8: return "DT_VEC2_UINT8";
		case DT_VEC3_SINT8: return "DT_VEC3_SINT8";
		case DT_VEC4_SINT8:	return "DT_VEC4_SINT8";

		case DT_UINT8: return "DT_UINT8";
		case DT_VEC2_UINT8: return "DT_VEC2_UINT8";
		case DT_VEC3_UINT8: return "DT_VEC3_UINT8";
		case DT_VEC4_UINT8: return "DT_VEC4_UINT8";

		case DT_SINT16: return "DT_SINT16";
		case DT_VEC2_SINT16: return "DT_VEC2_SINT16";
		case DT_VEC3_SINT16: return "DT_VEC3_SINT16";
		case DT_VEC4_SINT16: return "DT_VEC4_SINT16";

		case DT_UINT16: return "DT_UINT16";
		case DT_VEC2_UINT16: return "DT_VEC2_UINT16";
		case DT_VEC3_UINT16: return "DT_VEC3_UINT16";
		case DT_VEC4_UINT16: return "DT_VEC4_UINT16";

		case DT_SINT32: return "DT_SINT32";
		case DT_VEC2_SINT32: return "DT_VEC2_SINT32";
		case DT_VEC3_SINT32: return "DT_VEC3_SINT32";
		case DT_VEC4_SINT32: return "DT_VEC4_SINT32";

		case DT_UINT32: return "DT_UINT32";
		case DT_VEC2_UINT32: return "DT_VEC2_UINT32";
		case DT_VEC3_UINT32: return "DT_VEC3_UINT32";
		case DT_VEC4_UINT32: return "DT_VEC4_UINT32";

		case DT_FLOAT32: return "DT_FLOAT32";
		case DT_VEC2_FLOAT32: return "DT_VEC2_FLOAT32";
		case DT_VEC3_FLOAT32: return "DT_VEC3_FLOAT32";
		case DT_VEC4_FLOAT32: return "DT_VEC4_FLOAT32";

		case DT_USER_DATA: return "DT_USER_DATA";

		default: throw error("unsupported format", ERC_NO_SUPPORT); break;
		}
		return "DT_DEFAULT";
	}
	template<> cstring convert_enum<pixel_formats, cstring>(pixel_formats pxl_format) {
		switch (pxl_format) {
		case PXF_R8_SINT8: return "PXF_R8_SINT8"; break;

		case PXF_R32_SINT32: return "PXF_R32_SINT32"; break;
		case PXF_R16G16_SINT32: return "PXF_R16G16_SINT32"; break;
		case PXF_R8G8B8_SINT32: return "PXF_R8G8B8_SINT32"; break;
		case PXF_R8G8B8A8_SINT32: return "PXF_R8G8B8A8_SINT32"; break;

		case PXF_R32_UINT32: return "PXF_R32_UINT32"; break;
		case PXF_R16G16_UINT32: return "PXF_R16G16_UINT32"; break;
		case PXF_R8G8B8_UINT32: return "PXF_R8G8B8_UINT32"; break;
		case PXF_R8G8B8A8_UINT32: return "PXF_R8G8B8A8_UINT32"; break;

		case PXF_D24S8_UINT32: return "PXF_D24S8_UINT32"; break;
		default: throw error("unsupported pixel format", ERC_NO_SUPPORT); break;
		}
		return "PXF_DEFAULT";
	}
	template<> cstring convert_enum<shader_types, cstring>(shader_types shdType) {
		switch (shdType) {
		case SHD_PROG: return "SHD_PROG"; break;
		case SHD_VERTEX: return "SHD_VERTEX"; break;
		case SHD_PIXEL: return "SHD_PIXEL"; break;
		case SHD_GEOMETRY: return "SHD_GEOMETRY"; break;
		default: throw error("unsupported pixel format", ERC_NO_SUPPORT); break;
		}
		return "SHD_DEFAULT";
	}
}
namespace NWG
{
	template<>data_types convert_enum<si8, data_types>() { return DT_SINT8; }
	template<>data_types convert_enum<v2si8, data_types>() { return DT_VEC2_SINT8; }
	template<>data_types convert_enum<v3si8, data_types>() { return DT_VEC3_SINT8; }
	template<>data_types convert_enum<v4si8, data_types>() { return DT_VEC4_SINT8; }

	template<>data_types convert_enum<ui8, data_types>() { return DT_SINT8; }
	template<>data_types convert_enum<v2ui8, data_types>() { return DT_VEC2_UINT8; }
	template<>data_types convert_enum<v3ui8, data_types>() { return DT_VEC3_UINT8; }
	template<>data_types convert_enum<v4ui8, data_types>() { return DT_VEC4_UINT8; }

	template<>data_types convert_enum<si16, data_types>() { return DT_SINT16; }
	template<>data_types convert_enum<v2si16, data_types>() { return DT_VEC2_SINT16; }
	template<>data_types convert_enum<v3si16, data_types>() { return DT_VEC3_SINT16; }
	template<>data_types convert_enum<v4si16, data_types>() { return DT_VEC4_SINT16; }

	template<>data_types convert_enum<ui16, data_types>() { return DT_UINT16; }
	template<>data_types convert_enum<v2ui16, data_types>() { return DT_VEC2_UINT16; }
	template<>data_types convert_enum<v3ui16, data_types>() { return DT_VEC3_UINT16; }
	template<>data_types convert_enum<v4ui16, data_types>() { return DT_VEC4_UINT16; }

	template<>data_types convert_enum<si32, data_types>() { return DT_SINT32; }
	template<>data_types convert_enum<v2si32, data_types>() { return DT_VEC2_SINT32; }
	template<>data_types convert_enum<v3si32, data_types>() { return DT_VEC3_SINT32; }
	template<>data_types convert_enum<v4si32, data_types>() { return DT_VEC4_SINT32; }

	template<>data_types convert_enum<ui32, data_types>() { return DT_UINT32; }
	template<>data_types convert_enum<v2ui32, data_types>() { return DT_VEC2_UINT32; }
	template<>data_types convert_enum<v3ui32, data_types>() { return DT_VEC3_UINT32; }
	template<>data_types convert_enum<v4ui32, data_types>() { return DT_VEC4_UINT32; }

	template<>data_types convert_enum<f32, data_types>() { return DT_FLOAT32; }
	template<>data_types convert_enum<v2f32, data_types>() { return DT_VEC2_FLOAT32; }
	template<>data_types convert_enum<v3f32, data_types>() { return DT_VEC3_FLOAT32; }
	template<>data_types convert_enum<v4f32, data_types>() { return DT_VEC4_FLOAT32; }
	template<>data_types convert_enum<m2f32, data_types>() { return DT_MAT2_FLOAT32; }
	template<>data_types convert_enum<m3f32, data_types>() { return DT_MAT3_FLOAT32; }
	template<>data_types convert_enum<m4f32, data_types>() { return DT_MAT4_FLOAT32; }
}
#if (NWG_GAPI & NWG_GAPI_OGL)
#include <lib/nwg_load_base.h>
#include <lib/nwg_load_txr.h>
#include <lib/nwg_load_buf.h>
#include <lib/nwg_load_fbuf.h>
#include <lib/nwg_load_shd.h>
#include <gl/GL.h>
namespace NWG
{
	template<> data_types convert_enum<const GLchar*, data_types>(const GLchar* type_string) {
		if (str_is_equal(type_string, "bool")) { return DT_BOOL; }

		if (str_is_equal(type_string, "int")) { return DT_SINT32; }
		else if (str_is_equal(type_string, "ivec2")) { return DT_VEC2_SINT32; }
		else if (str_is_equal(type_string, "ivec3")) { return DT_VEC3_SINT32; }
		else if (str_is_equal(type_string, "ivec4")) { return DT_VEC4_SINT32; }

		if (str_is_equal(type_string, "uint")) { return DT_UINT32; }
		else if (str_is_equal(type_string, "uvec2")) { return DT_VEC2_UINT32; }
		else if (str_is_equal(type_string, "uvec3")) { return DT_VEC3_UINT32; }
		else if (str_is_equal(type_string, "uvec4")) { return DT_VEC4_UINT32; }

		if (str_is_equal(type_string, "float")) { return DT_FLOAT32; }
		else if (str_is_equal(type_string, "vec2")) { return DT_VEC2_FLOAT32; }
		else if (str_is_equal(type_string, "vec3")) { return DT_VEC3_FLOAT32; }
		else if (str_is_equal(type_string, "vec4")) { return DT_VEC4_FLOAT32; }
		else if (str_is_equal(type_string, "mat2")) { return DT_MAT2_FLOAT32; }
		else if (str_is_equal(type_string, "mat3")) { return DT_MAT3_FLOAT32; }
		else if (str_is_equal(type_string, "mat4")) { return DT_MAT4_FLOAT32; }

		if (str_is_equal(type_string, "double")) { return DT_FLOAT64; }
		else if (str_is_equal(type_string, "dvec2")) { return DT_VEC2_FLOAT64; }
		else if (str_is_equal(type_string, "dvec3")) { return DT_VEC3_FLOAT64; }
		else if (str_is_equal(type_string, "dvec4")) { return DT_VEC4_FLOAT64; }

		if (str_is_equal(type_string, "sampler1D")) { return DT_USER_DATA; }
		if (str_is_equal(type_string, "sampler2D")) { return DT_USER_DATA; }
		if (str_is_equal(type_string, "sampler3D")) { return DT_USER_DATA; }

		return DT_DEFAULT;
	}
	template<> GLenum convert_enum<data_types, GLenum>(data_types data_type) {
		switch (data_type) {
		case DT_BOOL: return GL_BOOL;
		case DT_SINT8: return GL_BYTE;
		case DT_VEC2_SINT8: return GL_BYTE;
		case DT_VEC3_SINT8: case DT_VEC4_SINT8: return GL_BYTE;

		case DT_UINT8: return GL_UNSIGNED_BYTE;
		case DT_VEC2_UINT8: return GL_UNSIGNED_BYTE;
		case DT_VEC3_UINT8: return GL_UNSIGNED_BYTE;
		case DT_VEC4_UINT8: return GL_UNSIGNED_BYTE;

		case DT_SINT16: return GL_SHORT;
		case DT_VEC2_SINT16: return GL_SHORT;
		case DT_VEC3_SINT16: return GL_SHORT;
		case DT_VEC4_SINT16: return GL_SHORT;

		case DT_UINT16: return GL_UNSIGNED_SHORT;
		case DT_VEC2_UINT16: return GL_UNSIGNED_SHORT;
		case DT_VEC3_UINT16: return GL_UNSIGNED_SHORT;
		case DT_VEC4_UINT16: return GL_UNSIGNED_SHORT;

		case DT_SINT32: return GL_INT;
		case DT_VEC2_SINT32: return GL_INT;
		case DT_VEC3_SINT32: return GL_INT;
		case DT_VEC4_SINT32: return GL_INT;

		case DT_UINT32: return GL_UNSIGNED_INT;
		case DT_VEC2_UINT32: return GL_UNSIGNED_INT;
		case DT_VEC3_UINT32: return GL_UNSIGNED_INT;
		case DT_VEC4_UINT32: return GL_UNSIGNED_INT;

		case DT_FLOAT32: return GL_FLOAT;
		case DT_VEC2_FLOAT32: return GL_FLOAT;
		case DT_VEC3_FLOAT32: return GL_FLOAT;
		case DT_VEC4_FLOAT32: return GL_FLOAT;

		default: throw error("unsupported format", ERC_NO_SUPPORT); break;
		}
		return DT_DEFAULT;
	}
	template<> GLenum convert_enum<gfx_primitives, GLenum>(gfx_primitives prim_type) {
		switch (prim_type) {
		case GPT_POINTS: return GL_POINTS; break;
		case GPT_TRIANGLES: return GL_TRIANGLES; break;
		case GPT_TRIANGLE_STRIP: return GL_TRIANGLE_STRIP; break;
		case GPT_TRIANGLE_FAN: return GL_TRIANGLE_FAN; break;
		case GPT_LINES: return GL_LINES; break;
		case GPT_LINE_LOOP: return GL_LINE_LOOP; break;
		case GPT_LINE_STRIP: return GL_LINE_STRIP; break;
		default: throw error("unavailable primitive topology", ERC_INVALID_ENUM); break;
		}
		return GL_TRIANGLES;
	}
	template<> GLenum convert_enum<texture_types, GLenum>(texture_types txr_type) {
		switch (txr_type) {
		case TXT_1D: return GL_TEXTURE_1D; break;
		case TXT_2D: return GL_TEXTURE_2D; break;
		case TXT_3D: return GL_TEXTURE_3D; break;
		case TXT_2D_MULTISAMPLE: return GL_TEXTURE_2D_MULTISAMPLE; break;
		case TXT_3D_MULTISAMPLE: return GL_TEXTURE_2D_MULTISAMPLE_ARRAY; break;
		default: throw error("unsupported texture type", ERC_NO_SUPPORT); break;
		}
		return GL_TEXTURE_2D;
	}
	template<> GLenum convert_enum<pixel_formats, GLenum>(pixel_formats pxl_format) {
		switch (pxl_format) {
		case PXF_R8_SINT8: return GL_BYTE; break;

		case PXF_R32_SINT32: return GL_R32I; break;
		case PXF_R16G16_SINT32: return GL_RG32I; break;
		case PXF_R8G8B8_SINT32: return GL_RGB32I; break;
		case PXF_R8G8B8A8_SINT32: return GL_RGBA32I; break;

		case PXF_R32_UINT32: return GL_R32UI; break;
		case PXF_R16G16_UINT32: return GL_RG32UI; break;
		case PXF_R8G8B8A8_UINT32: return GL_RGBA32UI; break;

		case PXF_D24S8_UINT32: return GL_DEPTH24_STENCIL8; break;
		default: throw error("unsupported pixel format", ERC_NO_SUPPORT); break;
		}
		return GL_RGB;
	}
	template<> GLenum convert_enum<shader_types, GLenum>(shader_types shd_type) {
		switch (shd_type) {
		case SHD_VERTEX: return GL_VERTEX_SHADER; break;
		case SHD_PIXEL: return GL_FRAGMENT_SHADER; break;
		case SHD_GEOMETRY: return GL_GEOMETRY_SHADER; break;
		case SHD_PROG: return GL_SHADER; break;
		default: throw error("unsupported pixel format", ERC_NO_SUPPORT); break;
		}
		return GL_SHADER;
	}
	template<> GLenum convert_enum<proc_modes, GLenum>(proc_modes proc_mode) {
		switch (proc_mode) {
		case PM_BLEND: return GL_BLEND; break;
		case PM_MULTISAMPLE: return GL_MULTISAMPLE; break;
		case PM_DEPTH_TEST: return GL_DEPTH_TEST; break;
		case PM_STENCIL_TEST: return GL_STENCIL_TEST; break;
		default: throw error("undefined processing mode", ERC_INVALID_ENUM); break;
		}
		return PM_DEFAULT;
	}
	template<> GLenum convert_enum<draw_modes, GLenum>(draw_modes draw_mode) {
		switch (draw_mode) {
		case DM_LINE: return GL_LINE; break;
		case DM_FILL: return GL_FILL; break;
		default: throw error("undefined draw mode", ERC_INVALID_ENUM); break;
		}
		return DM_DEFAULT;
	}
	template<> GLenum convert_enum<faces, GLenum>(faces face_plane) {
		switch (face_plane) {
		case FACE_FRONT: return GL_FRONT; break;
		case FACE_BACK: return GL_BACK; break;
		case FACE_FRONT_AND_BACK: return GL_FRONT_AND_BACK; break;
		default: throw error("undefined face plane", ERC_INVALID_ENUM); break;
		}
		return FACE_DEFAULT;
	}
	template<> GLenum convert_enum<blend_configs, GLenum>(blend_configs cfg) {
		switch (cfg) {
		case BC_SRC_ALPHA: return GL_SRC_ALPHA; break;
		case BC_ONE_MINUS_SRC_ALPHA: return GL_ONE_MINUS_SRC_ALPHA; break;
		default: throw error("invalid blending config", ERC_INVALID_ENUM); break;
		}
		return BC_SRC_DEFAULT;
	}
	template<> GLenum convert_enum<depth_configs, GLenum>(depth_configs cfg) {
		switch (cfg) {
		case DTC_LESS: return GL_LESS; break;
		case DTC_GREATER: return GL_GREATER; break;
		default: throw error("invalid depth config", ERC_INVALID_ENUM); break;
		}
		return DTC_DEFAULT;
	}
	template<> GLenum convert_enum<stencil_configs, GLenum>(stencil_configs cfg) {
		switch (cfg) {
		case STC_KEEP: return GL_KEEP; break;
		case STC_REPLACE: return GL_REPLACE; break;
		default: throw error("invalid depth config", ERC_INVALID_ENUM); break;
		}
		return STC_DEFAULT;
	}
	template<> GLenum convert_enum<texture_formats, GLenum>(texture_formats txr_format) {
		switch (txr_format) {
		case TXF_RGB: return GL_RGB; break;
		case TXF_RGBA: return GL_RGBA; break;
		case TXF_GRAY: return GL_RED; break;
		case TXF_IDX: return GL_RGBA; break;
		case TXF_DEPTH: return GL_DEPTH_ATTACHMENT; break;
		case TXF_STENCIL: return GL_STENCIL_ATTACHMENT; break;
		case TXF_DEPTH_STENCIL: return GL_DEPTH_STENCIL_ATTACHMENT; break;
		default: throw error("invalid texture filter", ERC_INVALID_ENUM); break;
		}
		return TXF_DEFAULT;
	}
	template<> GLenum convert_enum<texture_filters, GLenum>(texture_filters txr_filter) {
		switch (txr_filter) {
		case TXFL_LINEAR: return GL_LINEAR; break;
		case TXFL_NEAREST: return GL_NEAREST; break;
		default: throw error("invalid texture filter", ERC_INVALID_ENUM); break;
		}
		return TXF_DEFAULT;
	}
	template<> GLenum convert_enum<texture_wraps, GLenum>(texture_wraps txr_wrap) {
		switch (txr_wrap) {
		case TXW_REPEAT: return GL_REPEAT; break;
		case TXW_CLAMP: return GL_CLAMP_TO_BORDER; break;
		case TXW_BORDER: return GL_CLAMP_TO_BORDER; break;
		default: throw error("invalid texture wrap", ERC_INVALID_ENUM); break;
		}
		return TXW_DEFAULT;
	}
}
namespace NWG
{
	si32 dt_get_count(data_types data_type) {
		switch (data_type) {
		case DT_BOOL: return 1;
		case DT_VEC2_BOOL: return 2;
		case DT_VEC3_BOOL: return 3;
		case DT_VEC4_BOOL: return 4;

		case DT_SINT8: return 1;
		case DT_VEC2_SINT8: return 2;
		case DT_VEC3_SINT8: return 3;
		case DT_VEC4_SINT8: return 4;

		case DT_UINT8: return 1;
		case DT_VEC2_UINT8: return 2;
		case DT_VEC3_UINT8: return 3;
		case DT_VEC4_UINT8: return 4;

		case DT_SINT16: return 1;
		case DT_VEC2_SINT16: return 2;
		case DT_VEC3_SINT16: return 3;
		case DT_VEC4_SINT16: return 4;

		case DT_UINT16: return 1;
		case DT_VEC2_UINT16: return 2;
		case DT_VEC3_UINT16: return 3;
		case DT_VEC4_UINT16: return 4;

		case DT_SINT32: return 1;
		case DT_VEC2_SINT32: return 2;
		case DT_VEC3_SINT32: return 3;
		case DT_VEC4_SINT32: return 4;

		case DT_UINT32: return 1;
		case DT_VEC2_UINT32: return 2;
		case DT_VEC3_UINT32: return 3;
		case DT_VEC4_UINT32: return 4;

		case DT_FLOAT32: return 1;
		case DT_VEC2_FLOAT32: return 2;
		case DT_VEC3_FLOAT32: return 3;
		case DT_VEC4_FLOAT32: return 4;
		default: throw(error("invalid data type")); break;
		}
		return 0;
	}
	size dt_get_size(data_types data_type, si32 count) {
		switch (data_type) {
		case DT_BOOL:
		case DT_SINT8: case DT_UINT8:
			return 1;
		case DT_VEC2_SINT8: case DT_VEC2_UINT8:
		case DT_SINT16: case DT_UINT16:
			return 2;
		case DT_FLOAT32:
		case DT_SINT32: case DT_UINT32:
		case DT_VEC2_SINT16: case DT_VEC2_UINT16:
			return 4;

		case DT_VEC2_FLOAT32:
		case DT_VEC2_SINT32: case DT_VEC2_UINT32:
		case DT_VEC4_SINT16: case DT_VEC4_UINT16:
			return 4 * 2;
		case DT_VEC3_FLOAT32:
		case DT_VEC3_SINT32: case DT_VEC3_UINT32:
			return 4 * 3;
		case DT_VEC4_FLOAT32:
		case DT_VEC4_SINT32: case DT_VEC4_UINT32:
			return 4 * 4;

		case DT_USER_DATA: return 4;
		default: throw error("invalid data type", ERC_INVALID_ENUM); break;
		}
		return 0;
	}
	size dt_get_aligned_size(data_types data_type, si32 count) {
		size aligned_size = 0;
		switch (data_type) {
		case DT_BOOL: aligned_size = 4; break;

		case DT_SINT8: aligned_size = 4; break;

		case DT_UINT8: aligned_size = 4; break;

		case DT_SINT16: aligned_size = 4; break;

		case DT_UINT16: aligned_size = 4; break;

		case DT_SINT32: aligned_size = 4; break;

		case DT_UINT32: aligned_size = 4; break;

		case DT_FLOAT32: aligned_size = 4; break;
		case DT_VEC2_FLOAT32: aligned_size = 8; break;
		case DT_VEC3_FLOAT32: aligned_size = 16; break;
		case DT_VEC4_FLOAT32: aligned_size = 16; break;
		case DT_MAT2_FLOAT32: aligned_size = 32; break;
		case DT_MAT3_FLOAT32: aligned_size = 64; break;
		case DT_MAT4_FLOAT32: aligned_size = 64; break;

		case DT_USER_DATA: aligned_size = 4; break;

		default: throw error("invalid data type", ERC_INVALID_ENUM); aligned_size = 0; break;
		}
		return count * ((aligned_size + (aligned_size - 1)) & ~(aligned_size - 1));
	}
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
#include <lib/nwg_dx_loader.h>
namespace NWG
{
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
}
#endif
#endif	// NWG_GAPI