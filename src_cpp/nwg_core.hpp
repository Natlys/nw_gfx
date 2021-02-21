#ifndef NWG_CORE_HPP
#define NWG_CORE_HPP

// --==<configuration>==--
#if defined NWG_BUILD_LIB
		#define NWG_API
#else
	#if defined NWG_BUILD_DLL
		#define NWG_API __declspec(dllexport)
	#else
		#define NWG_API __declspec(dllimport)
	#endif
#endif

#define NWG_GAPI_OGL	1 << 1
#define NWG_GAPI_DX		1 << 2
#define NWG_GAPI		NWG_GAPI_DX
// --==</configurations>==--

#include <nwg_pch.hpp>

namespace NWG
{
	enum GfxApiTypes : UInt32 {
		GAPI_DEFAULT = NWG_GAPI,
		GAPI_OPENGL = NWG_GAPI_OGL,
		GAPI_DIRECTX = NWG_GAPI_DX,
	};
	enum GfxBufferTypes : UInt32 {
		GBT_DEFAULT = 0,
		GBT_VERTEX = 1, GBT_INDEX = 2, GBT_SHADER = 3,
	};
	enum FrameBufTypes : UInt32 {
		FBT_DEFAULT = 0,
		FBT_IN = 1, FBT_OUT = 2, FBT_IN_OUT = 3,
	};
	enum ShaderTypes : UInt32 {
		ST_DEFAULT = 0,
		ST_VERTEX = 1, ST_PIXEL = 2, ST_GEOMETRY = 3,
		ST_SHADER = 4,
	};
	enum FrameBufAttachments : UInt32 {
		FB_DEFAULT = 0,
		FB_COLOR = 1, FB_DEPTH = 2, FB_STENCIL = 3,
		FB_DEPTH_STENCIL,
	};
}
namespace NWG
{
	enum GfxPrimitives : UInt32 {
		GPT_DEFAULT = 0,
		GPT_POINTS = 1,
		GPT_LINES, GPT_LINE_LOOP, GPT_LINE_STRIP,
		GPT_TRIANGLES, GPT_TRIANGLE_STRIP, GPT_TRIANGLE_FAN,
	};
	enum DrawModes : UInt32 {
		DM_DEFAULT = 0,
		DM_LINE = 1, DM_FILL = 2
	};
	enum GfxVariables : UInt32 {
		GV_DEFAULT = 0,
		GV_LINE_WIDTH = 1, GV_POINT_SIZE = 2,
	};
	enum ProcessingModes : UInt32 {
		PM_DEFAULT = 0,
		PM_DEPTH_TEST = 1, PM_STENCIL_TEST = 2,
		PM_BLEND, PM_MULTISAMPLE,
		PM_CULL_FACE,
	};
	enum BlendConfigs : UInt32 {
		BC_SRC_DEFAULT = 0, BC_DEST_DEFAULT = 0,
		BC_SRC_ALPHA, BC_SRC_COLOR,
		BC_ONE_MINUS_SRC_ALPHA,
		BC_ONE_MINUS_SRC_COLOR,
		BC_DST_ALPHA, BC_DST_COLOR,
		BC_ONE_MUNUS_DST_ALPHA,
		BC_ONE_MINUS_DST_COLOR,
	};
	enum CullFaceConfigs : UInt32 {
		CFC_DEFAULT = 0
	};
	enum DepthConfigs : UInt32 {
		DTC_DEFAULT = 0,
		DTC_EQUAL = 1, DTC_LESS = 2, DTC_LEQUAL = 3,
		DTC_GREATER, DTC_GEQUAL,
		DTC_NEVER, DTC_ALWAYS,
	};
	enum StencilConfigs : UInt32 {
		STC_DEFAULT = 0,
		STC_INCR = 0, STC_DECR = 1,
		STC_KEEP, STC_ZERO, STC_REPLACE, STC_INVERT,
	};
	enum GfxCameraTypes : UInt32 {
		GCT_DEFAULT = 0,
		GCT_ORTHO = 1, GCT_PERSPECT = 2,
	};
	enum GfxCameraModes : UInt32 {
		GCM_DEFAULT = 0,
		GCM_2D = 2, GCM_3D = 3,
	};
}

namespace NWG
{
	class NWG_API GfxEngine;
	class NWG_API FrameBuf;

	class NWG_API ADrawable;
	class NWG_API VertexedDrawable;
	class NWG_API IndexedDrawable;
	class NWG_API GfxMesh;

	class NWG_API VertexBuf;
	class NWG_API IndexBuf;
	class NWG_API ShaderBuf;

	class NWG_API ShaderProgram;
	class NWG_API Shader;
	class NWG_API VertexShader;
	class NWG_API PixelShader;
	class NWG_API GeometryShader;

	class NWG_API Texture;
	class NWG_API GfxMaterial;
}
namespace NWG
{
	struct NWG_API GfxCamera;
}
#endif	// NWG_CORE_HPP