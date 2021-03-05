#ifndef NWG_SWITCH_H
#define NWG_SWITCH_H
#include <nwg_core.hpp>
#ifdef NWG_GAPI
namespace NWG
{
	enum gfx_api_types : si32 {
		GAPI_DEFAULT = NWG_GAPI,
		GAPI_OPENGL = NWG_GAPI_OGL,
		GAPI_DIRECTX = NWG_GAPI_DX,
	};
	enum shader_types : si32 {
		SHD_DEFAULT = 0,
		SHD_VERTEX = 1, SHD_PIXEL = 2, SHD_GEOMETRY = 3,
		SHD_PROG = 4,
	};
	enum gfx_buf_types : si32 {
		GBT_DEFAULT = 0,
		GBT_VERTEX = 1, GBT_INDEX = 2, GBT_SHADER = 3,
	};
	enum frame_buf_types : si32 {
		FBT_DEFAULT = 0,
		FBT_IN = 1, FBT_OUT = 2, FBT_IN_OUT = 3,
	};
	enum frame_buf_attachments : si32 {
		FB_DEFAULT = 0,
		FB_COLOR = 1, FB_DEPTH = 2, FB_STENCIL = 3,
		FB_DEPTH_STENCIL,
	};
}
namespace NWG
{
	enum gfx_primitives : si32 {
		GPT_DEFAULT = 0,
		GPT_POINTS = 1,
		GPT_LINES, GPT_LINE_LOOP, GPT_LINE_STRIP,
		GPT_TRIANGLES, GPT_TRIANGLE_STRIP, GPT_TRIANGLE_FAN,
	};
	enum draw_modes : si32 {
		DM_DEFAULT = 0,
		DM_LINE = 1, DM_FILL = 2
	};
	enum proc_modes : si32 {
		PM_DEFAULT = 0,
		PM_DEPTH_TEST = 1, PM_STENCIL_TEST = 2,
		PM_BLEND, PM_MULTISAMPLE,
		PM_CULL_FACE,
	};
	enum blend_configs : si32 {
		BC_SRC_DEFAULT = 0, BC_DEST_DEFAULT = 0,
		BC_SRC_ALPHA, BC_SRC_COLOR,
		BC_ONE_MINUS_SRC_ALPHA,
		BC_ONE_MINUS_SRC_COLOR,
		BC_DST_ALPHA, BC_DST_COLOR,
		BC_ONE_MUNUS_DST_ALPHA,
		BC_ONE_MINUS_DST_COLOR,
	};
	enum cull_face_configs : si32 {
		CFC_DEFAULT = 0
	};
	enum depth_configs : si32 {
		DTC_DEFAULT = 0,
		DTC_EQUAL = 1, DTC_LESS = 2, DTC_LEQUAL = 3,
		DTC_GREATER, DTC_GEQUAL,
		DTC_NEVER, DTC_ALWAYS,
	};
	enum stencil_configs : si32 {
		STC_DEFAULT = 0,
		STC_INCR = 0, STC_DECR = 1,
		STC_KEEP, STC_ZERO, STC_REPLACE, STC_INVERT,
	};
}
namespace NWG
{
	enum texture_types : ui32 {
		TXT_DEFAULT = 0,
		TXT_1D = 1, TXT_2D = 2, TXT_3D = 3,
		TXT_2D_MULTISAMPLE, TXT_3D_MULTISAMPLE
	};
	enum texture_wraps : ui32 {
		TXW_DEFAULT = 0,
		TXW_REPEAT = 1, TXW_CLAMP = 2, TXW_BORDER = 3,
	};
	enum texture_filters : ui32 {
		TXFL_DEFAULT = 0,
		TXFL_LINEAR, TXFL_NEAREST,
	};
	enum texture_formats : ui32 {
		TXF_DEFAULT = 0u,
		TXF_RGB = 1, TXF_RGBA = 2,
		TXF_GRAY, TXF_IDX,
		TXF_DEPTH, TXF_STENCIL,
		TXF_DEPTH_STENCIL,
	};
}
namespace NWG
{
	template<typename in_type, typename out_type>
	NWG_API out_type convert_enum();
	template<typename in_type, typename out_type>
	NWG_API out_type convert_enum(in_type input);
	
	NWG_API si32 dt_get_count(data_types data_type);
	NWG_API size dt_get_size(data_types data_type, si32 count = 1);
	NWG_API size dt_get_aligned_size(data_types data_type, si32 count = 1);
}
#endif	// NWG_GAPI
#endif	// NWG_SWITCH_H