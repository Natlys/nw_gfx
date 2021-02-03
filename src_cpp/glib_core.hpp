#ifndef GLIB_CORE_HPP
#define GLIB_CORE_HPP

// --==<linking>==--
#if defined GLIB_LINK_DYNAMIC
#ifdef GLIB_BUILD_DLL
#define GLIB_API __declspec(dllexport)
#elif defined GLIB_BUILD_EXE
#define GLIB_API __declspec(dllimport)
#endif
#else
#define GLIB_API
#endif
// --==</linking>==--

// --==<configurations>==--
// --window_api_choice
#define GLIB_WAPI_GLFW		1 << 1
#define GLIB_WAPI GLIB_WAPI_GLFW
// --graphics_api_choice
#define GLIB_GAPI_OGL		1 << 1
#define GLIB_GAPI			GLIB_GAPI_OGL
// --==</configurations>==--

// --debug_macro
#if (defined GLIB_DEBUG)
#if (GLIB_GAPI & GLIB_GAPI_OGL)
// --opengl_debug
namespace GLIB
{
	extern inline void OglClearErr();
	extern inline bool OglErrLog(const char* funcName, const char* file, int line);
}
#define OGL_CALL(function) OglClearErr();\
		function;\
		NWL_ASSERT(OglErrLog(#function, NWL_FNAME_APATH((std::string)__FILE__), __LINE__), "GL_ERROR: ")
#endif // GLIB_GAPI
#else
#define OGL_CALL(function);
#endif // GLIB_DEBUG
// --==</support_macroses>==--

// --==<pragmas>==--
#pragma warning(disable : 4005)
#pragma warning(disable : 4081)
#pragma warning(disable : 4099)
#pragma warning(disable : 4102)
#pragma warning(disable : 4244)
#pragma warning(disable : 4267)
#pragma warning(disable : 4552)
#pragma warning(disable : 4996)
// --==</pragmas>==--

#endif	// GLIB_CORE_HPP

#include <glib_pch.hpp>

#ifndef GLIB_DECL_HPP
#define GLIB_DECL_HPP
#if (GLIB_GAPI & GLIB_GAPI_OGL)
// --==<data_types_ogl>==--
#define GL_BOOL								0x8B56
#define GL_BYTE								0x1400
#define GL_UNSIGNED_BYTE					0x1401
#define GL_SHORT							0x1402
#define GL_UNSIGNED_SHORT					0x1403
#define GL_INT								0x1404
#define GL_UNSIGNED_INT						0x1405
#define GL_FLOAT							0x1406
#define GL_DOUBLE							0x140A
#define GL_SAMPLER_1D						0x8B5D
#define GL_UNSIGNED_INT_24_8				0x84FA
// --==</data_types_ogl>==--

// --==<data_types_glib>==--
#define GLIB_ZERO 0
#define GLIB_ONE 1
#define GLIB_BOOL			GL_BOOL
#define GLIB_INT16			GL_SHORT
#define GLIB_UINT16			GL_UNSIGNED_SHORT
#define GLIB_INT8			GL_BYTE
#define GLIB_UINT8			GL_UNSIGNED_BYTE
#define GLIB_INT32			GL_INT
#define GLIB_UINT32			GL_UNSIGNED_INT
#define GLIB_FLOAT32		GL_FLOAT
#define GLIB_FLOAT64		GL_DOUBLE
#define GLIB_FLOAT32_VEC2	(GLIB_FLOAT32 + 0x0020)
#define GLIB_FLOAT32_VEC3	(GLIB_FLOAT32 + 0x0030)
#define GLIB_FLOAT32_VEC4	(GLIB_FLOAT32 + 0x0040)
#define GLIB_FLOAT32_MAT2	(GLIB_FLOAT32 + 0x0100)
#define GLIB_FLOAT32_MAT3	(GLIB_FLOAT32 + 0x0200)
#define GLIB_FLOAT32_MAT4	(GLIB_FLOAT32 + 0x0300)
#define GLIB_SAMPLER_1D		GL_SAMPLER_1D
#define GLIB_UINT24_8		GL_UNSIGNED_INT_24_8
// --==</data_types_glib>==--

// --==<draw_modes_ogl>==--
#define GL_POINT 0x1B00
#define GL_LINE 0x1B01
#define GL_FILL 0x1B02
// --primitives
#define GL_POINTS 0x0000
#define GL_LINES 0x0001
#define GL_LINE_STRIP 0x0003
#define GL_LINE_LOOP 0x0002
#define GL_LINE_BIT 0x00000004
#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006
#define GL_QUADS 0x0007
#define GL_QUAD_STRIP 0x0008
#define GL_POLYGON 0x0009
// --==</draw_modes_ogl>==--

// --==<draw_modes_glib>==--
#define GLIB_POINT 0x1B00
#define GLIB_LINE 0x1B01
#define GLIB_FILL 0x1B02
// --primitives
#define GLIB_POINTS 0x0000
#define GLIB_LINES 0x0001
#define GLIB_LINE_STRIP 0x0003
#define GLIB_LINE_LOOP 0x0002
#define GLIB_LINE_BIT 0x00000004
#define GLIB_TRIANGLES 0x0004
#define GLIB_TRIANGLE_STRIP 0x0005
#define GLIB_TRIANGLE_FAN 0x0006
#define GLIB_QUADS 0x0007
#define GLIB_QUAD_STRIP 0x0008
#define GLIB_POLYGON 0x0009
// --==</draw_modes_GLIB>==--

// --==<planes_ogl>==--
#define GL_FRONT 0x0404
#define GL_BACK 0x0405
#define GL_LEFT 0x0406
#define GL_RIGHT 0x0407
#define GL_FRONT_AND_BACK 0x0408
// --==</planes_ogl>==--
// --==<planes_glib>==--
#define GLIB_FRONT GL_FRONT
#define GLIB_BACK GL_BACK
#define GLIB_LEFT GL_LEFT
#define GLIB_RIGHT GL_RIGHT
#define GLIB_FRONT_AND_BACK GL_FRONT_AND_BACK
// --==</planes_glib>==--

// --==<shaders_ogl>==--
#define GL_SHADER 0x82E1
#define GL_PROGRAM 0x82E2
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_GEOMETRY_SHADER 0x8DD9
#define GL_VERTEX_SHADER 0x8B31
// --==<shaders_ogl>==--

// --==<shaders_glib>==--
#define GLIB_SHADER					GL_PROGRAM
#define GLIB_SHADER_VERTEX			GL_VERTEX_SHADER
#define GLIB_SHADER_GEOMETRY		GL_GEOMETRY_SHADER
#define GLIB_SHADER_PIXEL			GL_FRAGMENT_SHADER
// --==</shaders_glib>==--

// --==<configurations_ogl>==--
#define GL_POINT_SIZE			0x0B11
#define GL_LINE_SMOOTH			0x0B20
#define GL_LINE_WIDTH			0x0B21

#define GL_CULL_FACE			0x0B44
#define GL_CULL_FACE_MODE		0x0B45
#define GL_FRONT_FACE			0x0B46
#define GL_CW					0x0900
#define GL_CCW					0x0901

#define GL_DEPTH_TEST			0x0B71
#define GL_DEPTH_FUNC			0x0B74

#define GL_STENCIL_TEST			0x0B90
#define GL_STENCIL_FUNC			0x0B92

#define GL_BLEND				0x0BE2
#define GL_BLEND_DST			0x0BE0
#define GL_BLEND_SRC			0x0BE1
#define GL_SRC_COLOR			0x0300
#define GL_ONE_MINUS_SRC_COLOR	0x0301
#define GL_SRC_ALPHA			0x0302
#define GL_ONE_MINUS_SRC_ALPHA	0x0303
#define GL_DST_ALPHA			0x0304
#define GL_ONE_MINUS_DST_ALPHA	0x0305
#define GL_DST_COLOR			0x0306
#define GL_ONE_MINUS_DST_COLOR	0x0307
#define GL_SRC_ALPHA_SATURATE	0x0308

#define GL_MULTISAMPLE			0x809D

#define GL_KEEP					0x1E00
#define GL_REPLACE				0x1E01
#define GL_INCR					0x1E02
#define GL_DECR					0x1E03
// --==</configurations_ogl>==--

// --==<configurations_glib>==--
#define GLIB_POINT_SIZE				GL_POINT_SIZE
#define GLIB_LINE_SMOOTH			GL_LINE_SMOOTH
#define GLIB_LINE_WIDTH				GL_LINE_WIDTH

#define GLIB_CULL_FACE				GL_CULL_FACE
#define GLIB_CULL_FACE_MODE			GL_CULL_FACE_MODE
#define GLIB_FRONT_FACE				GL_FRONT_FACE
#define GLIB_CW						GL_CW
#define GLIB_CCW					GL_CCW

#define GLIB_DEPTH_TEST				GL_DEPTH_TEST
#define GLIB_DEPTH_FUNC				GL_DEPTH_FUNC

#define GLIB_STENCIL_TEST			GL_STENCIL_TEST
#define GLIB_STENCIL_FUNC			GL_STENCIL_FUNC

#define GLIB_BLEND					GL_BLEND
#define GLIB_BLEND_DST				GL_BLEND_DST
#define GLIB_BLEND_SRC				GL_BLEND_SRC
#define GLIB_SRC_COLOR				GL_SRC_COLOR
#define GLIB_ONE_MINUS_SRC_COLOR	GL_ONE_MINUS_SRC_COLOR
#define GLIB_SRC_ALPHA				GL_SRC_ALPHA
#define GLIB_ONE_MINUS_SRC_ALPHA	GL_ONE_MINUS_SRC_ALPHA
#define GLIB_DST_ALPHA				GL_DST_ALPHA
#define GLIB_ONE_MINUS_DST_ALPHA	GL_ONE_MINUS_DST_ALPHA
#define GLIB_DST_COLOR				GL_DST_COLOR
#define GLIB_ONE_MINUS_DST_COLOR	GL_ONE_MINUS_DST_COLOR
#define GLIB_SRC_ALPHA_SATURATE		GL_SRC_ALPHA_SATURATE

#define GLIB_MULTISAMPLE			GL_MULTISAMPLE

#define GLIB_KEEP					GL_KEEP
#define GLIB_REPLACE				GL_REPLACE
#define GLIB_INCR					GL_INCR
#define GLIB_DECR					GL_DECR
// --==</configurations_glib>==--

// --==<expressions_ogl>==--
// --constants
#define GL_NONE 0
#define GL_FALSE 0
#define GL_TRUE 1
#define GL_ZERO 0
#define GL_ONE 1
// --conditions
#define GL_NEVER 0x0200
#define GL_LESS 0x0201
#define GL_EQUAL 0x0202
#define GL_LEQUAL 0x0203
#define GL_GREATER 0x0204
#define GL_NOTEQUAL 0x0205
#define GL_GEQUAL 0x0206
#define GL_ALWAYS 0x0207
// --logic
#define GL_AND 0x1501
#define GL_AND_REVERSE 0x1502
#define GL_COPY 0x1503
#define GL_AND_INVERTED 0x1504
#define GL_NOOP 0x1505
#define GL_XOR 0x1506
#define GL_OR 0x1507
#define GL_NOR 0x1508
#define GL_EQUIV 0x1509
#define GL_INVERT 0x150A
#define GL_OR_REVERSE 0x150B
#define GL_COPY_INVERTED 0x150C
#define GL_OR_INVERTED 0x150D
#define GL_NAND 0x150E
// --==</expressions_ogl>==--

// --==<expressions_glib>==--
// --constants
#define GLIB_NONE 0
#define GLIB_FALSE 0
#define GLIB_TRUE 1
// --conditions
#define GLIB_NEVER 0x0200
#define GLIB_LESS 0x0201
#define GLIB_EQUAL 0x0202
#define GLIB_LEQUAL 0x0203
#define GLIB_GREATER 0x0204
#define GLIB_NOTEQUAL 0x0205
#define GLIB_GEQUAL 0x0206
#define GLIB_ALWAYS 0x0207
// --logic
#define GLIB_AND 0x1501
#define GLIB_AND_REVERSE 0x1502
#define GLIB_COPY 0x1503
#define GLIB_AND_INVERTED 0x1504
#define GLIB_NOOP 0x1505
#define GLIB_XOR 0x1506
#define GLIB_OR 0x1507
#define GLIB_NOR 0x1508
#define GLIB_EQUIV 0x1509
#define GLIB_INVERT 0x150A
#define GLIB_OR_REVERSE 0x150B
#define GLIB_COPY_INVERTED 0x150C
#define GLIB_OR_INVERTED 0x150D
#define GLIB_NAND 0x150E
// --==</expressions_glib>==--

// --==<pixel_formats_ogl>==--
#define GL_RED 0x1903
#define GL_GREEN 0x1904
#define GL_BLUE 0x1905
#define GL_ALPHA 0x1906
#define GL_RGB 0x1907
#define GL_RGBA 0x1908
#define GL_RED_INTEGER 0x8D94
#define GL_GREEN_INTEGER 0x8D95
#define GL_BLUE_INTEGER 0x8D96
#define GL_RGB_INTEGER 0x8D98
#define GL_RGBA_INTEGER 0x8D99
#define GL_R8UI 0x8232
#define GL_R16I 0x8233
#define GL_R16UI 0x8234
#define GL_R32I 0x8235
#define GL_R32UI 0x8236
#define GL_RG8I 0x8237
#define GL_RGBA8 0x8058
#define GL_DEPTH 0x1801
#define GL_STENCIL 0x1802
#define GL_DEPTH24_STENCIL8 0x88F0
// --==</pixel_formats_ogl>==--

// --==<pixel_formats_glib>==--
#define GLIB_RED				GL_RED
#define GLIB_GREEN				GL_GREEN
#define GLIB_BLUE				GL_BLUE
#define GLIB_ALPHA				GL_ALPHA
#define GLIB_RGB				GL_RGB
#define GLIB_RGBA				GL_RGBA
#define GLIB_RED_INT			GL_RED_INTEGER
#define GLIB_GREEN_INT			GL_GREEN_INTEGER
#define GLIB_BLUE_INT			GL_BLUE_INTEGER
#define GLIB_RGB_INT			GL_RGB_INTEGER
#define GLIB_RGBA_INT			GL_RGBA_INTEGER
#define GLIB_DEPTH				GL_DEPTH
#define GLIB_STENCIL			GL_STENCIL
#define GLIB_RED_INT32			GL_R32I
#define GLIB_RED_UINT32			GL_R32UI
#define GLIB_RGBA8				GL_RGBA8
#define GLIB_DEPTH24			GL_DEPTH
#define GLIB_STENCIL8			GL_STENCIL
#define GLIB_DEPTH24_STENCIL8	GL_DEPTH24_STENCIL8
// --==</pixel_formats_glib>==--

// --==<textures_ogl>==--
#define GL_TEXTURE_1D 0x0DE0
#define GL_TEXTURE_2D 0x0DE1
#define GL_TEXTURE_3D 0x0DE2
#define GL_TEXTURE_2D_MULTISAMPLE 0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE 0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9102
#define GL_DEPTH_STENCIL 0x84F9
#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_NEAREST 0x2600
#define GL_LINEAR 0x2601
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_TEXTURE_WRAP_R 0x8072
#define GL_CLAMP 0x2900
#define GL_REPEAT 0x2901
// --==</textures_ogl>==--

// --==<textures_glib>==--
// --types
#define GLIB_TEXTURE_1D					GL_TEXTURE_1D
#define GLIB_TEXTURE_2D					GL_TEXTURE_2D
#define GLIB_TEXTURE_3D					GL_TEXTURE_3D
#define GLIB_TEXTURE_2D_MULTISAMPLE		GL_TEXTURE_2D_MULTISAMPLE
#define GLIB_TEXTURE_3D_MULTISAMPLE		GL_TEXTURE_2D_MULTISAMPLE_ARRAY
#define GLIB_DEPTH_STENCIL				GL_DEPTH_STENCIL
#define GLIB_DEPTH_STENCIL_ATTACHMENT	GL_DEPTH_STENCIL_ATTACHMENT
// --filters
#define GLIB_TEXTURE_MAG_FILTER			GL_TEXTURE_MAG_FILTER
#define GLIB_TEXTURE_MIN_FILTER			GL_TEXTURE_MIN_FILTER
#define GLIB_TEXTURE_FILTER_NEAREST		GL_NEAREST
#define GLIB_TEXTURE_FILTER_LINEAR		GL_LINEAR
// --wrappers
#define GLIB_TEXTURE_WRAP_S				GL_TEXTURE_WRAP_S
#define GLIB_TEXTURE_WRAP_T				GL_TEXTURE_WRAP_T
#define GLIB_TEXTURE_WRAP_R				GL_TEXTURE_WRAP_R
#define GLIB_TEXTURE_WRAP_CLAMP			GL_CLAMP
#define GLIB_TEXTURE_WRAP_REPEAT		GL_REPEAT
// --==</textures_glib>==--

// --==<gbuffers_ogl>==--
#define GL_ARRAY_BUFFER			0x8892
#define GL_ELEMENT_ARRAY_BUFFER	0x8893
#define GL_UNIFORM_BUFFER		0x8A11
// --==</gbuffers_ogl>==--


// --==<gbuffers_glib>==--
#define GLIB_GBUFFER_VERTEX	GL_ARRAY_BUFFER
#define GLIB_GBUFFER_INDEX	GL_ELEMENT_ARRAY_BUFFER
#define GLIB_GBUFFER_SHADER	GL_UNIFORM_BUFFER
// --==</gbuffers_glib>==--

// --==<framebuffers_ogl>==--
#define GL_DRAW_BUFFER			0x0C01
#define GL_READ_BUFFER			0x0C02
#define GL_FRAMEBUFFER			0x8D40
#define GL_COLOR_BUFFER_BIT		0x00004000
#define GL_DEPTH_BUFFER_BIT		0x00000100
#define GL_ACCUM_BUFFER_BIT		0x00000200
#define GL_STENCIL_BUFFER_BIT	0x00000400
#define GL_DEPTH_ATTACHMENT		0x8D00
#define GL_STENCIL_ATTACHMENT	0x8D20
// --==</buffers_ogl>==--

// --==<framebuffers_glib>==--
#define GLIB_FRAMEBUF_IN		GL_DRAW_BUFFER
#define GLIB_FRAMEBUF_OUT		GL_READ_BUFFER
#define GLIB_FRAMEBUF_IO		GL_FRAMEBUFFER
#define GLIB_BUFFER_COLOR_BIT	GL_COLOR_BUFFER_BIT
#define GLIB_BUFFER_DEPTH_BIT	GL_DEPTH_BUFFER_BIT
#define GLIB_BUFFER_STENCIL_BIT	GL_STENCIL_BUFFER_BIT
// --==</framebuffers_glib>==--

// --==<data_load_types_ogl>==--
#define GL_STATIC_DRAW 0x88E4
#define GL_STREAM_DRAW 0x88E0
#define GL_DYNAMIC_DRAW 0x88E8
// --==</data_load_types_ogl>==--

// --==<data_load_types_glib>==--
#define GLIB_STATIC_DRAW		GL_STATIC_DRAW 
#define GLIB_STREAM_DRAW		GL_STREAM_DRAW 
#define GLIB_DYNAMIC_DRAW		GL_DYNAMIC_DRAW
// --==</data_load_types_glib>==--

// --==<error_codes_ogl>==--
#define GL_NO_ERROR                       0
#define GL_INVALID_ENUM                   0x0500
#define GL_INVALID_VALUE                  0x0501
#define GL_INVALID_OPERATION              0x0502
#define GL_STACK_OVERFLOW                 0x0503
#define GL_STACK_UNDERFLOW                0x0504
#define GL_OUT_OF_MEMORY                  0x0505
// --==</error_codes_ogl>==--

// --==<error_codes_glib>==--
#define GLIB_OK					GL_NO_ERROR         
#define GLIB_INVALID_ENUM		GL_INVALID_ENUM     
#define GLIB_INVALID_VALUE		GL_INVALID_VALUE    
#define GLIB_INVALID_OPERATION	GL_INVALID_OPERATION
#define GLIB_STACK_OVERFLOW		GL_STACK_OVERFLOW   
#define GLIB_STACK_UNDERFLOW	GL_STACK_UNDERFLOW  
#define GLIB_OUT_OF_MEMORY		GL_OUT_OF_MEMORY  
// --==</error_codes_glib>==--

// --==<info_ogl>==--
#define GL_VENDOR				0x1F00
#define GL_RENDERER				0x1F01
#define GL_VERSION				0x1F02
#define GL_EXTENSIONS			0x1F03

#define GL_COMPILE_STATUS		0x8B81
#define GL_LINK_STATUS			0x8B82
#define GL_INFO_LOG_LENGTH		0x8B84
#define GL_ATTACHED_SHADERS		0x8B85
// --==</info_ogl>==--

// --==<info_glib>==--
#define GLIB_COMPILE_STATUS			GL_COMPILE_STATUS
#define GLIB_LINK_STATUS			GL_LINK_STATUS
// --==</info_glib>==--
#endif // GLIB_GAPI

namespace GLIB
{
	class GLIB_API GraphEngine;
	class GLIB_API GLayer;
	class GLIB_API GCameraLad;

	class GLIB_API Shader;
	class GLIB_API GMaterial;

	class GLIB_API Texture;

	class GLIB_API FrameBuf;

	class GLIB_API VertexBufLayout;
	class GLIB_API ShaderBufLayout;

	class GLIB_API VertexBuf;
	class GLIB_API IndexBuf;
	class GLIB_API ShaderBuf;
	class GLIB_API VertexArr;
}
namespace GLIB
{
	struct GLIB_API Drawable;
	
	struct GLIB_API GCamera;

	struct GLIB_API FrameBufInfo;
	struct GLIB_API ImageInfo;
	struct GLIB_API TextureInfo;
	struct GLIB_API RenderInfo;

	struct GLIB_API VertexBatch1d;
	struct GLIB_API VertexBatch2d;
	struct GLIB_API VertexShape3d;

	struct GLIB_API BufferElement;

	struct GLIB_API SubTexture1d;
	struct GLIB_API SubTexture2d;
	struct GLIB_API SubTexture3d;
}
namespace GLIB
{
	/// graphics_api_types
	/// Interface:
	/// -> Give it to the GraphicsApi create function
	/// -> Check the types for the abstracted usage
	enum GApiTypes : UInt32
	{
		GAPI_DEFAULT = GLIB_GAPI_OGL,
		GAPI_OPENGL = GLIB_GAPI_OGL
	};
	enum GBufferTypes : UInt32 {
		GBT_DEFAULT = GLIB_GBUFFER_VERTEX,
		GBT_VERTEX = GLIB_GBUFFER_VERTEX,
		GBT_INDEX = GLIB_GBUFFER_INDEX,
		GBT_SHADER = GLIB_GBUFFER_SHADER
	};
	enum FrameBufTypes : UInt32 {
		FBT_DEFAULT = GLIB_FRAMEBUF_IO,
		FBT_IN = GLIB_FRAMEBUF_IN, FBT_OUT = GLIB_FRAMEBUF_OUT, FBT_IN_OUT = GLIB_FRAMEBUF_IO,
	};
	/// Data that can be loaded in a shader
	enum ShaderDataTypes : UInt32
	{
		SDT_DEFAULT = GLIB_FLOAT32,
		SDT_BOOL = GLIB_BOOL, SDT_INT8 = GLIB_INT8, SDT_UINT8 = GLIB_UINT8,
		SDT_INT16 = GLIB_INT16, SDT_UINT16 = GLIB_UINT16,
		SDT_INT32 = GLIB_INT32, SDT_UINT32 = GLIB_UINT32,
		SDT_FLOAT32 = GLIB_FLOAT32, SDT_FLOAT64 = GLIB_FLOAT64,

		SDT_SAMPLER = GLIB_SAMPLER_1D
	};
	/// Accessible (maintained) shader types
	enum ShaderTypes : UInt32
	{
		ST_DEFAULT = GLIB_SHADER,
		ST_SHADER = GLIB_SHADER,
		ST_VERTEX = GLIB_SHADER_VERTEX,
		ST_GEOMETRY = GLIB_SHADER_GEOMETRY,
		ST_PIXEL = GLIB_SHADER_PIXEL
	};
	enum FrameBufs : UInt32
	{
		FB_DEFAULT = GLIB_BUFFER_COLOR_BIT | GLIB_BUFFER_DEPTH_BIT | GLIB_BUFFER_STENCIL_BIT,
		FB_COLOR = GLIB_BUFFER_COLOR_BIT,
		FB_DEPTH = GLIB_BUFFER_DEPTH_BIT,
		FB_STENCIL = GLIB_BUFFER_STENCIL_BIT
	};
	enum GPrimitiveTypes : UInt32
	{
		PT_DEFAULT = GLIB_TRIANGLES,
		PT_POINTS = GLIB_POINTS,
		PT_LINES = GLIB_LINES,
		PT_LINE_LOOP = GLIB_LINE_LOOP,
		PT_LINE_STRIP = GLIB_LINE_STRIP,
		PT_TRIANGLES = GLIB_TRIANGLES,
		PT_TRIANGLE_FAN = GLIB_TRIANGLE_FAN,
		PT_TRIANGLE_STRIP = GLIB_TRIANGLE_STRIP,
		PT_QUADS = GLIB_QUADS,
		PT_QUADS_STRIP = GLIB_QUAD_STRIP
	};
	enum DrawModes : UInt32 {
		DM_DEFAULT = GLIB_FILL,
		DM_LINE = GLIB_LINE, DM_FILL = GLIB_FILL
	};
	enum FacePlanes : UInt32 {
		FP_DEFAULT = GLIB_FRONT_AND_BACK,
		FP_FRONT_AND_BACK = GLIB_FRONT_AND_BACK,
		FP_BACK = GLIB_BACK, FP_FRONT = GLIB_FRONT,
		FP_LEFT = GLIB_LEFT, FP_RIGTH = GLIB_RIGHT,
	};
	enum ProcessingModes : UInt32 {
		PM_BLEND = GLIB_BLEND,
		PM_MULTISAMPLE = GLIB_MULTISAMPLE,
		PM_CULL_FACE = GLIB_CULL_FACE,
		PM_DEPTH_TEST = GLIB_DEPTH_TEST,
		PM_STENCIL_TEST = GLIB_STENCIL_TEST
	};
	enum BlendConfigs : UInt32 {
		BC_SRC_ALPHA = GLIB_SRC_ALPHA, BC_SRC_COLOR = GLIB_SRC_COLOR,
		BC_ONE_MINUS_SRC_ALPHA = GLIB_ONE_MINUS_SRC_ALPHA,
		BC_ONE_MINUS_SRC_COLOR = GLIB_ONE_MINUS_SRC_COLOR,
		BC_DST_ALPHA = GLIB_DST_ALPHA, BC_DST_COLOR = GLIB_DST_COLOR,
		BC_ONE_MUNUS_DST_ALPHA = GLIB_ONE_MINUS_DST_ALPHA,
		BC_ONE_MINUS_DST_COLOR = GLIB_ONE_MINUS_DST_COLOR,
	};
	enum DepthConfigs : UInt32 {
		DC_EQUAL = GLIB_EQUAL,
		DC_LESS = GLIB_LESS, DC_LEQUAL = GLIB_LEQUAL,
		DC_GREATER = GLIB_GREATER, DC_GEQUAL = GLIB_GEQUAL,
		DC_NEVER = GLIB_NEVER, DC_ALWAYS = GLIB_ALWAYS
	};
	enum StencilConfigs : UInt32 {
		SC_KEEP = GLIB_KEEP, SC_ZERO = GLIB_ZERO, SC_REPLACE = GLIB_REPLACE, SC_INVERT = GLIB_INVERT,
		SC_INCR = GLIB_INCR, SC_DECR = GLIB_DECR
	};
	enum TextureTypes : UInt32 {
		TXT_NONE = 0,
		TXT_1D = GLIB_TEXTURE_1D, TXT_2D = GLIB_TEXTURE_2D, TXT_3D = GLIB_TEXTURE_3D,
		TXT_2D_MULTISAMPLE = GLIB_TEXTURE_2D_MULTISAMPLE, TXT_3D_MULTISAMPLE = GLIB_TEXTURE_3D_MULTISAMPLE
	};
	enum TextureWraps : UInt32 {
		TXW_NONE = 0, TXW_REPEAT = GLIB_TEXTURE_WRAP_REPEAT, TXW_CLAMP = GLIB_TEXTURE_WRAP_CLAMP,
	};
	enum TextureFilters : UInt32 {
		TXF_LINEAR = GLIB_TEXTURE_FILTER_LINEAR, TXF_NEAREST = GLIB_TEXTURE_FILTER_NEAREST,
	};
	enum TextureFormats : UInt32 {
		TXF_NONE = 0,
		TXF_RED = GLIB_RED, TXF_GREEN = GLIB_GREEN, TXF_BLUE = GLIB_BLUE,
		TXF_RGB = GLIB_RGB, TXF_RGBA = GLIB_RGBA,
		TXF_RED_INT = GLIB_RED_INT, TXF_GREEN_INT = GLIB_GREEN_INT, TXF_BLUE_INT = GLIB_BLUE_INT,
		TXF_RGB_INT = GLIB_RGB_INT, TXF_RGBA_INT = GLIB_RGBA_INT,
		TXF_DEPTH = GLIB_DEPTH, TXF_STENCIL = GLIB_STENCIL,
		TXF_DEPTH_STENCIL = GLIB_DEPTH_STENCIL,
	};
	enum TextureInterFormats : UInt32 {
		TXFI_RED_UINT32 = GLIB_RED_UINT32, TXFI_RED_INT32 = GLIB_RED_INT32,
		TXFI_RGB = GLIB_RGB, TXFI_RGBA8 = GLIB_RGBA8,
		TXFI_DEPTH24 = GLIB_DEPTH24, TXFI_STENCIL8 = GLIB_STENCIL8,
		TXFI_DEPTH24_STENCIL8 = GLIB_DEPTH24_STENCIL8,
	};
	enum PixelFormats : UInt32 {
		FBAT_DEFAULT = 0,
		PXF_INT8 = GLIB_INT8, PXF_UINT8 = GLIB_UINT8,
		PXF_INT32 = GLIB_INT32, PXF_UINT32 = GLIB_UINT32,
		PXF_UINT24_8 = GLIB_UINT24_8
	};
	//	--==</structs_enums>==--
}

#define GLIB_MAX_TEXTURES 8
#define GLIB_MIN_TEXTURES 1

#endif	// GLIB_DECL_HPP

/*
* The project created in 16.01.2021
* Graphics library as a tool for game engines and applications
*/