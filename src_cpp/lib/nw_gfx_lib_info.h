#ifndef NW_GFX_LIB_INFO_H
#define NW_GFX_LIB_INFO_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_lib_core.h"
#	if (!defined NW_GFX_FOREACH_VTYPE)
#		define NW_GFX_FOREACH_VTYPE(ITERATOR)  \
\
			ITERATOR(v1bit, NW_GFX_V1BIT, 1u,      1u * 1u) \
			ITERATOR(v2bit, NW_GFX_V1BIT, 2u,      1u * 2u) \
			ITERATOR(v3bit, NW_GFX_V1BIT, 3u,      1u * 3u) \
			ITERATOR(v4bit, NW_GFX_V1BIT, 4u,      1u * 4u) \
			ITERATOR(m2bit, NW_GFX_V1BIT, 2u * 2u, 1u * 2u * 2u) \
			ITERATOR(m3bit, NW_GFX_V1BIT, 3u * 3u, 1u * 3u * 3u) \
			ITERATOR(m4bit, NW_GFX_V1BIT, 4u * 4u, 1u * 4u * 4u) \
\
			ITERATOR(v1s08, NW_GFX_V1S08, 1u,      1u * 1u) \
			ITERATOR(v2s08, NW_GFX_V1S08, 2u,      1u * 2u) \
			ITERATOR(v3s08, NW_GFX_V1S08, 3u,      1u * 3u) \
			ITERATOR(v4s08, NW_GFX_V1S08, 4u,      1u * 4u) \
			ITERATOR(m2s08, NW_GFX_V1S08, 2u * 2u, 1u * 2u * 2u) \
			ITERATOR(m3s08, NW_GFX_V1S08, 3u * 3u, 1u * 3u * 3u) \
			ITERATOR(m4s08, NW_GFX_V1S08, 4u * 4u, 1u * 4u * 4u) \
\
			ITERATOR(v1s16, NW_GFX_V1S16, 1u,      2u * 1u) \
			ITERATOR(v2s16, NW_GFX_V1S16, 2u,      2u * 2u) \
			ITERATOR(v3s16, NW_GFX_V1S16, 3u,      2u * 3u) \
			ITERATOR(v4s16, NW_GFX_V1S16, 4u,      2u * 4u) \
			ITERATOR(m2s16, NW_GFX_V1S16, 2u * 2u, 2u * 2u * 2u) \
			ITERATOR(m3s16, NW_GFX_V1S16, 3u * 3u, 2u * 3u * 3u) \
			ITERATOR(m4s16, NW_GFX_V1S16, 4u * 4u, 2u * 4u * 4u) \
\
			ITERATOR(v1s32, NW_GFX_V1S32, 1u,      4u * 1u) \
			ITERATOR(v2s32, NW_GFX_V1S32, 2u,      4u * 2u) \
			ITERATOR(v3s32, NW_GFX_V1S32, 3u,      4u * 3u) \
			ITERATOR(v4s32, NW_GFX_V1S32, 4u,      4u * 4u) \
			ITERATOR(m2s32, NW_GFX_V1S32, 2u * 2u, 4u * 2u * 2u) \
			ITERATOR(m3s32, NW_GFX_V1S32, 3u * 3u, 4u * 3u * 3u) \
			ITERATOR(m4s32, NW_GFX_V1S32, 4u * 4u, 4u * 4u * 4u) \
\
			ITERATOR(v1s64, NW_GFX_V1S64, 1u,      8u * 1u) \
			ITERATOR(v2s64, NW_GFX_V1S64, 2u,      8u * 2u) \
			ITERATOR(v3s64, NW_GFX_V1S64, 3u,      8u * 3u) \
			ITERATOR(v4s64, NW_GFX_V1S64, 4u,      8u * 4u) \
			ITERATOR(m2s64, NW_GFX_V1S64, 2u * 2u, 8u * 2u * 2u) \
			ITERATOR(m3s64, NW_GFX_V1S64, 3u * 3u, 8u * 3u * 3u) \
			ITERATOR(m4s64, NW_GFX_V1S64, 4u * 4u, 8u * 4u * 4u) \
\
			ITERATOR(v1u08, NW_GFX_V1U08, 1u,      1u * 1u) \
			ITERATOR(v2u08, NW_GFX_V1U08, 2u,      1u * 2u) \
			ITERATOR(v3u08, NW_GFX_V1U08, 3u,      1u * 3u) \
			ITERATOR(v4u08, NW_GFX_V1U08, 4u,      1u * 4u) \
			ITERATOR(m2u08, NW_GFX_V1U08, 2u * 2u, 1u * 2u * 2u) \
			ITERATOR(m3u08, NW_GFX_V1U08, 3u * 3u, 1u * 3u * 3u) \
			ITERATOR(m4u08, NW_GFX_V1U08, 4u * 4u, 1u * 4u * 4u) \
\
			ITERATOR(v1u16, NW_GFX_V1U16, 1u,      2u * 1u) \
			ITERATOR(v2u16, NW_GFX_V1U16, 2u,      2u * 2u) \
			ITERATOR(v3u16, NW_GFX_V1U16, 3u,      2u * 3u) \
			ITERATOR(v4u16, NW_GFX_V1U16, 4u,      2u * 4u) \
			ITERATOR(m2u16, NW_GFX_V1U16, 2u * 2u, 2u * 2u * 2u) \
			ITERATOR(m3u16, NW_GFX_V1U16, 3u * 3u, 2u * 3u * 3u) \
			ITERATOR(m4u16, NW_GFX_V1U16, 4u * 4u, 2u * 4u * 4u) \
\
			ITERATOR(v1u32, NW_GFX_V1U32, 1u,      4u * 1u) \
			ITERATOR(v2u32, NW_GFX_V1U32, 2u,      4u * 2u) \
			ITERATOR(v3u32, NW_GFX_V1U32, 3u,      4u * 3u) \
			ITERATOR(v4u32, NW_GFX_V1U32, 4u,      4u * 4u) \
			ITERATOR(m2u32, NW_GFX_V1U32, 2u * 2u, 4u * 2u * 2u) \
			ITERATOR(m3u32, NW_GFX_V1U32, 3u * 3u, 4u * 3u * 3u) \
			ITERATOR(m4u32, NW_GFX_V1U32, 4u * 4u, 4u * 4u * 4u) \
\
			ITERATOR(v1u64, NW_GFX_V1U64, 1u,      8u * 1u) \
			ITERATOR(v2u64, NW_GFX_V1U64, 2u,      8u * 2u) \
			ITERATOR(v3u64, NW_GFX_V1U64, 3u,      8u * 3u) \
			ITERATOR(v4u64, NW_GFX_V1U64, 4u,      8u * 4u) \
			ITERATOR(m2u64, NW_GFX_V1U64, 2u * 2u, 8u * 2u * 2u) \
			ITERATOR(m3u64, NW_GFX_V1U64, 3u * 3u, 8u * 3u * 3u) \
			ITERATOR(m4u64, NW_GFX_V1U64, 4u * 4u, 8u * 4u * 4u) \
\
			ITERATOR(v1f32, NW_GFX_V1F32, 1u,      4u * 1u) \
			ITERATOR(v2f32, NW_GFX_V1F32, 2u,      4u * 2u) \
			ITERATOR(v3f32, NW_GFX_V1F32, 3u,      4u * 3u) \
			ITERATOR(v4f32, NW_GFX_V1F32, 4u,      4u * 4u) \
			ITERATOR(m2f32, NW_GFX_V1F32, 2u * 2u, 4u * 2u) \
			ITERATOR(m3f32, NW_GFX_V1F32, 3u * 3u, 4u * 3u) \
			ITERATOR(m4f32, NW_GFX_V1F32, 4u * 4u, 4u * 4u) \
\
			ITERATOR(v1f64, NW_GFX_V1F64, 1u,      8u * 1u) \
			ITERATOR(v2f64, NW_GFX_V1F64, 1u,      8u * 2u) \
			ITERATOR(v3f64, NW_GFX_V1F64, 1u,      8u * 3u) \
			ITERATOR(v4f64, NW_GFX_V1F64, 1u,      8u * 4u) \
			ITERATOR(m2f64, NW_GFX_V1F64, 2u * 2u, 8u * 2u * 2u) \
			ITERATOR(m3f64, NW_GFX_V1F64, 3u * 3u, 8u * 3u * 3u) \
			ITERATOR(m4f64, NW_GFX_V1F64, 4u * 4u, 8u * 4u * 4u) \
// that's it
#	else
#		error "NW_GFX_FOREACH_VTYPE must not be defined here!"
#	endif	// NW_GFX_FOREACH_VTYPE
namespace NW
{
	/// type_information static class
	class NW_API gfx_type_info : public type_info
	{
	public:
		using info_t = gfx_type_info;
		using info_tc = const info_t;
#	if (NW_GAPI & NW_GAPI_OGL)
		using enum_t = GLenum;
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
		using enum_t = DXGI_FORMAT;
#	endif	// GAPI_D3D
		using enum_tc = const enum_t;
	public:
		enum_tc tenum;
		size_tc count;
		size_tc space;
	public:
		// --core_methods
#		define NW_GFX_ITERATOR_VTYPE(tname, tenum, vcount, vspace) type == type_info::get_type<tname>() ? tenum :
		static inline enum_tc get_enum(type_tc type) { return NW_GFX_FOREACH_VTYPE(NW_GFX_ITERATOR_VTYPE) NW_NULL; }
#		undef NW_ITERATOR_VTYPE
#		define NW_GFX_ITERATOR_VTYPE(tname, tenum, vcount, vspace) type == type_info::get_type<tname>() ? vcount :
		static inline enum_tc get_count(type_tc type) { return NW_GFX_FOREACH_VTYPE(NW_GFX_ITERATOR_VTYPE) NW_NULL; }
#		undef NW_ITERATOR_VTYPE
#		define NW_GFX_ITERATOR_VTYPE(tname, tenum, vcount, vspace) type == type_info::get_type<tname>() ? vspace :
		static inline enum_tc get_space(type_tc type) { return NW_GFX_FOREACH_VTYPE(NW_GFX_ITERATOR_VTYPE) NW_NULL; }
#		undef NW_ITERATOR_VTYPE
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_LIB_INFO_H