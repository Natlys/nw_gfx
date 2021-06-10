#ifndef NC_GFX_LIB_INFO_H
#define NC_GFX_LIB_INFO_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "nc_gfx_lib_core.hxx"
#	if (!defined NC_GFX_FOREACH_VTYPE)
#		define NC_GFX_FOREACH_VTYPE(ITERATOR)  \
\
			ITERATE(v1bit_t, NC_GFX_V1BIT, 1u,      1u * 1u) \
			ITERATE(v2bit, NC_GFX_V1BIT, 2u,      1u * 2u) \
			ITERATE(v3bit, NC_GFX_V1BIT, 3u,      1u * 3u) \
			ITERATE(v4bit, NC_GFX_V1BIT, 4u,      1u * 4u) \
			ITERATE(m2x2bit, NC_GFX_V1BIT, 2u * 2u, 1u * 2u * 2u) \
			ITERATE(m3x3bit, NC_GFX_V1BIT, 3u * 3u, 1u * 3u * 3u) \
			ITERATE(m4x4bit, NC_GFX_V1BIT, 4u * 4u, 1u * 4u * 4u) \
\
			ITERATE(v1s08_t, NC_GFX_V1S08, 1u,      1u * 1u) \
			ITERATE(v2s08, NC_GFX_V1S08, 2u,      1u * 2u) \
			ITERATE(v3s08, NC_GFX_V1S08, 3u,      1u * 3u) \
			ITERATE(v4s08, NC_GFX_V1S08, 4u,      1u * 4u) \
			ITERATE(m2x2s08, NC_GFX_V1S08, 2u * 2u, 1u * 2u * 2u) \
			ITERATE(m3x3s08, NC_GFX_V1S08, 3u * 3u, 1u * 3u * 3u) \
			ITERATE(m4x4s08, NC_GFX_V1S08, 4u * 4u, 1u * 4u * 4u) \
\
			ITERATE(v1s16, NC_GFX_V1S16, 1u,      2u * 1u) \
			ITERATE(v2s16, NC_GFX_V1S16, 2u,      2u * 2u) \
			ITERATE(v3s16, NC_GFX_V1S16, 3u,      2u * 3u) \
			ITERATE(v4s16, NC_GFX_V1S16, 4u,      2u * 4u) \
			ITERATE(m2x2s16, NC_GFX_V1S16, 2u * 2u, 2u * 2u * 2u) \
			ITERATE(m3x3s16, NC_GFX_V1S16, 3u * 3u, 2u * 3u * 3u) \
			ITERATE(m4x4s16, NC_GFX_V1S16, 4u * 4u, 2u * 4u * 4u) \
\
			ITERATE(v1s32, NC_GFX_V1S32, 1u,      4u * 1u) \
			ITERATE(v2s32, NC_GFX_V1S32, 2u,      4u * 2u) \
			ITERATE(v3s32, NC_GFX_V1S32, 3u,      4u * 3u) \
			ITERATE(v4s32, NC_GFX_V1S32, 4u,      4u * 4u) \
			ITERATE(m2x2s32, NC_GFX_V1S32, 2u * 2u, 4u * 2u * 2u) \
			ITERATE(m3x3s32, NC_GFX_V1S32, 3u * 3u, 4u * 3u * 3u) \
			ITERATE(m4x4s32, NC_GFX_V1S32, 4u * 4u, 4u * 4u * 4u) \
\
			ITERATE(v1s64_t, NC_GFX_V1S64, 1u,      8u * 1u) \
			ITERATE(v2s64, NC_GFX_V1S64, 2u,      8u * 2u) \
			ITERATE(v3s64, NC_GFX_V1S64, 3u,      8u * 3u) \
			ITERATE(v4s64, NC_GFX_V1S64, 4u,      8u * 4u) \
			ITERATE(m2x2s64, NC_GFX_V1S64, 2u * 2u, 8u * 2u * 2u) \
			ITERATE(m3x3s64, NC_GFX_V1S64, 3u * 3u, 8u * 3u * 3u) \
			ITERATE(m4x4s64, NC_GFX_V1S64, 4u * 4u, 8u * 4u * 4u) \
\
			ITERATE(v1u08_t, NC_GFX_V1U08, 1u,      1u * 1u) \
			ITERATE(v2u08, NC_GFX_V1U08, 2u,      1u * 2u) \
			ITERATE(v3u08, NC_GFX_V1U08, 3u,      1u * 3u) \
			ITERATE(v4u08, NC_GFX_V1U08, 4u,      1u * 4u) \
			ITERATE(m2x2u08, NC_GFX_V1U08, 2u * 2u, 1u * 2u * 2u) \
			ITERATE(m3x3u08, NC_GFX_V1U08, 3u * 3u, 1u * 3u * 3u) \
			ITERATE(m4x4u08, NC_GFX_V1U08, 4u * 4u, 1u * 4u * 4u) \
\
			ITERATE(v1s16_t, NC_GFX_V1U16, 1u,      2u * 1u) \
			ITERATE(v2u16, NC_GFX_V1U16, 2u,      2u * 2u) \
			ITERATE(v3u16, NC_GFX_V1U16, 3u,      2u * 3u) \
			ITERATE(v4u16, NC_GFX_V1U16, 4u,      2u * 4u) \
			ITERATE(m2x2u16, NC_GFX_V1U16, 2u * 2u, 2u * 2u * 2u) \
			ITERATE(m3x3u16, NC_GFX_V1U16, 3u * 3u, 2u * 3u * 3u) \
			ITERATE(m4x4u16, NC_GFX_V1U16, 4u * 4u, 2u * 4u * 4u) \
\
			ITERATE(v1u32, NC_GFX_V1U32, 1u,      4u * 1u) \
			ITERATE(v2u32, NC_GFX_V1U32, 2u,      4u * 2u) \
			ITERATE(v3u32, NC_GFX_V1U32, 3u,      4u * 3u) \
			ITERATE(v4u32, NC_GFX_V1U32, 4u,      4u * 4u) \
			ITERATE(m2x2u32, NC_GFX_V1U32, 2u * 2u, 4u * 2u * 2u) \
			ITERATE(m3x3u32, NC_GFX_V1U32, 3u * 3u, 4u * 3u * 3u) \
			ITERATE(m4x4u32, NC_GFX_V1U32, 4u * 4u, 4u * 4u * 4u) \
\
			ITERATE(v1u64_t, NC_GFX_V1U64, 1u,      8u * 1u) \
			ITERATE(v2u64, NC_GFX_V1U64, 2u,      8u * 2u) \
			ITERATE(v3u64, NC_GFX_V1U64, 3u,      8u * 3u) \
			ITERATE(v4u64, NC_GFX_V1U64, 4u,      8u * 4u) \
			ITERATE(m2x2u64, NC_GFX_V1U64, 2u * 2u, 8u * 2u * 2u) \
			ITERATE(m3x3u64, NC_GFX_V1U64, 3u * 3u, 8u * 3u * 3u) \
			ITERATE(m4x4u64, NC_GFX_V1U64, 4u * 4u, 8u * 4u * 4u) \
\
			ITERATE(v1f32, NC_GFX_V1F32, 1u,      4u * 1u) \
			ITERATE(v2f32, NC_GFX_V1F32, 2u,      4u * 2u) \
			ITERATE(v3f32, NC_GFX_V1F32, 3u,      4u * 3u) \
			ITERATE(v4f32, NC_GFX_V1F32, 4u,      4u * 4u) \
			ITERATE(m2x2f32, NC_GFX_V1F32, 2u * 2u, 4u * 2u) \
			ITERATE(m3x3f32, NC_GFX_V1F32, 3u * 3u, 4u * 3u) \
			ITERATE(m4x4f32, NC_GFX_V1F32, 4u * 4u, 4u * 4u) \
\
			ITERATE(v1f64, NC_GFX_V1F64, 1u,      8u * 1u) \
			ITERATE(v2f64, NC_GFX_V1F64, 1u,      8u * 2u) \
			ITERATE(v3f64, NC_GFX_V1F64, 1u,      8u * 3u) \
			ITERATE(v4f64, NC_GFX_V1F64, 1u,      8u * 4u) \
			ITERATE(m2x2f64, NC_GFX_V1F64, 2u * 2u, 8u * 2u * 2u) \
			ITERATE(m3x3f64, NC_GFX_V1F64, 3u * 3u, 8u * 3u * 3u) \
			ITERATE(m4x4f64, NC_GFX_V1F64, 4u * 4u, 8u * 4u * 4u) \
// that's it
#	else
#		error "NC_GFX_FOREACH_VTYPE must not be defined here!"
#	endif	// NC_GFX_FOREACH_VTYPE
#	if (!defined NC_GFX_FOREACH_FORMAT)
#		define NC_GFX_FOREACH_FORMAT(ITERATOR)  \
\
			ITERATE(v1s08_t, NC_GFX_FORMAT_R8_S8, NC_GFX_FORMAT_RED) \
			ITERATE(v1u08_t, NC_GFX_FORMAT_R8_U8, NC_GFX_FORMAT_RED) \
			ITERATE(v1s16, NC_GFX_FORMAT_R16_S16, NC_GFX_FORMAT_RED) \
			ITERATE(v1s16_t, NC_GFX_FORMAT_R32_U32, NC_GFX_FORMAT_RED) \
			ITERATE(v1s32, NC_GFX_FORMAT_R32_S32, NC_GFX_FORMAT_RED) \
			ITERATE(v1u32, NC_GFX_FORMAT_R32_U32, NC_GFX_FORMAT_RED) \
\
			ITERATE(v2s08, NC_GFX_FORMAT_R8G8_S16, NC_GFX_FORMAT_RG) \
			ITERATE(v2u08, NC_GFX_FORMAT_R8G8_U16, NC_GFX_FORMAT_RG) \
			ITERATE(v2s16, NC_GFX_FORMAT_R16G16_S32, NC_GFX_FORMAT_RG) \
			ITERATE(v2u16, NC_GFX_FORMAT_R16G16_U32, NC_GFX_FORMAT_RG) \
\
			ITERATE(v3s08, NC_GFX_FORMAT_R8G8B8_S32, NC_GFX_FORMAT_RGB) \
			ITERATE(v3u08, NC_GFX_FORMAT_R8G8B8_U32, NC_GFX_FORMAT_RGB) \
\
			ITERATE(v4s08, NC_GFX_FORMAT_R8G8B8A8_S32, NC_GFX_FORMAT_RGBA) \
			ITERATE(v4u08, NC_GFX_FORMAT_R8G8B8A8_U32, NC_GFX_FORMAT_RGBA) \
\
			ITERATE(v1bit_t, NC_GFX_FORMAT_S8_S8, NC_GFX_FORMAT_STEN) \
			ITERATE(v3bit, NC_GFX_FORMAT_D32_S32, NC_GFX_FORMAT_DEPT) \
			ITERATE(v4bit, NC_GFX_FORMAT_D24S8_S32, NC_GFX_FORMAT_DPST) \
\
// that's it
#	else
#		error "NC_GFX_FOREACH_FORMAT must not be defined here!"
#	endif	// NC_GFX_FOREACH_FORMAT
#endif	// NC_GAPI
namespace NC
{
	/// graphics_information_type
	class gfx_info_t
	{
	public:
		using info_t = gfx_info_t;
		using info_tc = const info_t;
		using type_t = v1u_t;
		using type_tc = const type_t;
#	if (NC_GAPI & NC_GAPI_OGL)
		using enum_t = GLenum;
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
		using enum_t = DXGI_FORMAT;
#	endif	// GAPI_D3D
		using enum_tc = const enum_t;
	public:
		enum_tc tenum;
		size_tc count;
		size_tc space;
	public:
		/* command */
#		define NC_GFX_ITERATOR_VTYPE(tname, tenum, vcount, vspace) type == type_info_t::get_type<tname>() ? tenum :
		static inline enum_tc get_type(type_tc type) { return NC_GFX_FOREACH_VTYPE(NC_GFX_ITERATOR_VTYPE) NC_NULL; }
#		undef NC_GFX_ITERATOR_VTYPE
#		define NC_GFX_ITERATOR_VTYPE(tname, tenum, vcount, vspace) type == type_info_t::get_type<tname>() ? vcount :
		static inline size_tc get_count(type_tc type) { return NC_GFX_FOREACH_VTYPE(NC_GFX_ITERATOR_VTYPE) NC_NULL; }
#		undef NC_GFX_ITERATOR_VTYPE
#		define NC_GFX_ITERATOR_VTYPE(tname, tenum, vcount, vspace) type == type_info_t::get_type<tname>() ? vspace :
		static inline size_tc get_space(type_tc type) { return NC_GFX_FOREACH_VTYPE(NC_GFX_ITERATOR_VTYPE) NC_NULL; }
#		undef NC_GFX_ITERATOR_VTYPE
#		define NC_GFX_ITERATOR_FORMAT(tname, pxl_fmt, img_fmt) type == type_info_t::get_type<tname>() ? pxl_fmt :
		static inline enum_tc get_pxl_fmt(type_tc type) { return NC_GFX_FOREACH_FORMAT(NC_GFX_ITERATOR_FORMAT) NC_NULL; }
#		undef NC_GFX_ITERATOR_FORMAT
#		define NC_GFX_ITERATOR_FORMAT(tname, pxl_fmt, img_fmt) type == type_info_t::get_type<tname>() ? img_fmt :
		static inline enum_tc get_img_fmt(type_tc type) { return NC_GFX_FOREACH_FORMAT(NC_GFX_ITERATOR_FORMAT) NC_NULL; }
#		undef NC_GFX_ITERATOR_FORMAT
	};
}
#endif	// NC_GFX_LIB_INFO_H