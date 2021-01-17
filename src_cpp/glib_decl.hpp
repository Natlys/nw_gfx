#ifndef GLIB_DECL_HPP
#define GLIB_DECL_HPP

#include <glib_core.hpp>

namespace GLIB
{
	class GLIB_API AGApi;
	class GLIB_API GEngine;
	struct GLIB_API GLayer;

	class GLIB_API AShader;
	class GLIB_API GMaterial;

	class GLIB_API ATexture;
	class GLIB_API ATexture1d;
	class GLIB_API ATexture2d;
	class GLIB_API ATexture3d;

	class GLIB_API AWindow;
	class GLIB_API AGContext;
	class GLIB_API AFrameBuf;

	class GLIB_API VertexBufLayout;
	class GLIB_API ShaderBufLayout;

	class GLIB_API AVertexBuf;
	class GLIB_API AIndexBuf;
	class GLIB_API AShaderBuf;

	class GLIB_API GCameraLad;
}
namespace GLIB
{
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

	struct GLIB_API RenderAttribs;
	struct GLIB_API RenderLayer;

	struct GLIB_API AEvent;
	struct GLIB_API MouseEvent;
	struct GLIB_API KeyboardEvent;
	struct GLIB_API WindowEvent;
}
namespace GLIB
{
	/// window_api_types
	enum WApiTypes : UInt32 {
		WAPI_NONE = 0,
		WAPI_GLFW = GLIB_WINDOW_GLFW
	};
	/// graphics_api_types
	/// Interface:
	/// -> Give it to the GraphicsApi create function
	/// -> Check the types for the abstracted usage
	enum GApiTypes : UInt32
	{
		GAPI_NONE = 0,
		GAPI_OPENGL = GLIB_GAPI_OGL
	};
	enum GraphicsBufTypes : UInt32 {
		GBT_VERTEX = GLIB_GBUFFER_VERTEX,
		GBT_INDEX = GLIB_GBUFFER_INDEX,
		GBT_SHADER = GLIB_GBUFFER_SHADER
	};
	/// Data that can be loaded in a shader
	enum ShaderDataTypes : UInt32
	{
		SDT_NONE = GLIB_ERR_NO_DATA,
		SDT_BOOL = GLIB_BOOL, SDT_INT8 = GLIB_INT8, SDT_UINT8 = GLIB_UINT8,
		SDT_INT16 = GLIB_INT16, SDT_UINT16 = GLIB_UINT16,
		SDT_INT32 = GLIB_INT32, SDT_UINT32 = GLIB_UINT32,
		SDT_FLOAT32 = GLIB_FLOAT32, SDT_FLOAT64 = GLIB_FLOAT64,

		//SDT_FLOAT32_VEC2 = GLIB_FLOAT32_VEC2, SDT_FLOAT32_VEC3 = GLIB_FLOAT32_VEC3, SDT_FLOAT32_VEC4 = GLIB_FLOAT32_VEC4,
		//SDT_FLOAT32_MAT2 = GLIB_FLOAT32_MAT2, SDT_FLOAT32_MAT3 = GLIB_FLOAT32_MAT3, SDT_FLOAT32_MAT4 = GLIB_FLOAT32_MAT4

		SDT_SAMPLER = GLIB_SAMPLER_1D
	};
	/// Accessible (maintained) shader types
	enum ShaderTypes : UInt32
	{
		ST_SHADER = GLIB_SHADER,
		ST_VERTEX = GLIB_SHADER_VERTEX,
		ST_GEOMETRY = GLIB_SHADER_GEOMETRY,
		ST_PIXEL = GLIB_SHADER_PIXEL
	};
	enum FrameBufs : UInt32
	{
		FB_COLOR = GLIB_BUFFER_COLOR_BIT,
		FB_DEPTH = GLIB_BUFFER_DEPTH_BIT,
		FB_STENCIL = GLIB_BUFFER_STENCIL_BIT
	};
	enum GPrimitiveTypes : UInt32
	{
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
	enum DrawModes : UInt32
	{
		DM_LINE = GLIB_LINE,
		DM_FILL = GLIB_FILL
	};
	enum FacePlanes : UInt32
	{
		FP_FRONT_AND_BACK = GLIB_FRONT_AND_BACK,
		FP_FRONT = GLIB_FRONT,
		FP_BACK = GLIB_BACK,
		FP_RIGTH = GLIB_RIGHT,
		FP_LEFT = GLIB_LEFT,
	};
	enum ProcModes : UInt32
	{
		PM_BLEND = GLIB_BLEND,
		PM_DEPTH_TEST = GLIB_DEPTH_TEST,
		PM_STENCIL_TEST = GLIB_STENCIL_TEST
	};
	enum BlendConfigs : UInt32
	{
		BC_SRC_ALPHA = GLIB_SRC_ALPHA,
		BC_SRC_COLOR = GLIB_SRC_COLOR,
		BC_ONE_MINUS_SRC_ALPHA = GLIB_ONE_MINUS_SRC_ALPHA,
		BC_ONE_MINUS_SRC_COLOR = GLIB_ONE_MINUS_SRC_COLOR,
		BC_DST_ALPHA = GLIB_DST_ALPHA,
		BC_DST_COLOR = GLIB_DST_COLOR,
		BC_ONE_MUNUS_DST_ALPHA = GLIB_ONE_MINUS_DST_ALPHA,
		BC_ONE_MINUS_DST_COLOR = GLIB_ONE_MINUS_DST_COLOR,
	};
	enum DepthConfigs : UInt32
	{
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
		TT_1D = GLIB_TEXTURE_1D, TT_2D = GLIB_TEXTURE_2D, TT_3D = GLIB_TEXTURE_3D,
	};
	enum TextureConfigs : UInt32 {
		TC_WRAP_REPEAT = GLIB_TEXTURE_WRAP_REPEAT, TC_WRAP_CLAMP = GLIB_TEXTURE_WRAP_CLAMP,
		TC_FILTER_LINEAR = GLIB_TEXTURE_FILTER_LINEAR, TC_FILTER_NEAREST = GLIB_TEXTURE_FILTER_NEAREST,
		TC_FORMAT_RED = GLIB_RED, TC_FORMAT_GREEN = GLIB_GREEN, TC_FORMAT_BLUE = GLIB_BLUE,
		TC_FORMAT_RGB = GLIB_RGB, TC_FORMAT_RGBA = GLIB_RGBA, TC_FORMAT_RGBA8 = GLIB_RGBA8,
	};
	enum EventTypes : UInt32 {
		ET_NONE = 0,
		ET_WINDOW_CLOSE, ET_WINDOW_RESIZE, ET_WINDOW_MOVE, ET_WINDOW_FOCUS,
		ET_APP_TICK, ET_APP_UPDATE, ET_APP_RENDER,
		ET_MOUSE_MOVE, ET_MOUSE_SCROLL, ET_MOUSE_PRESS, ET_MOUSE_RELEASE,
		ET_KEY_RELEASE, ET_KEY_PRESS, ET_KEY_TYPE
	};
	enum KeyCodes : Char16 {
		KC_NONE = 0,
		KC_BELL = 7, // "\a" - sound signal
		KC_BACKSPACE = 8, // Step backward - can be used for two symbols in one
		KC_HTAB = 9, KC_ENTER = 10, KC_VTAB = 11, // Hor + Vert tabulation and EndLine
		KC_SHIFT = 16, KC_CTRL = 17, KC_PAUSE = 19, KC_CAPS_LOCK = 20, KC_ESCAPE = 27,
		KC_LEFT = 37, KC_UP = 38, KC_RIGHT = 39, KC_DOWN = 40, KC_INSERT = 45, KC_DEL = 46,
		KC_HOME = 36,
		KC_SPACE = 32, KC_EXCLAIM = 33, KC_HASH = 35,
		KC_K0 = 48, KC_K1 = 49, KC_K2, KC_K3, KC_K4, KC_K5, KC_K6, KC_K7, KC_K8, KC_K9 = 57,
		KC_COLON = 58, KC_SEMICOLON = 59, KC_LESSER = 60, KC_EQUAL = 61, KC_GREATER = 62,
		KC_A = 65, KC_B, KC_C, KC_D, KC_E, KC_F, KC_G, KC_H, KC_I, KC_J, KC_K, KC_L, KC_M, KC_N, KC_O, KC_P = 80,
		KC_Q = 81, KC_R, KC_S, KC_T, KC_U, KC_V, KC_W, KC_X, KC_Y, KC_Z = 90,
		KC_a = 97, KC_b, KC_c, KC_d, KC_e, KC_f, KC_g, KC_h, KC_i, KC_j, KC_k, KC_l, KC_m, KC_n, KC_o, KC_p = 112,
		KC_q = 113, KC_r, KC_s, KC_t, KC_u, KC_v, KC_w, KC_x, KC_y, KC_z = 122,
		KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
		KC_RECT_DITHER = 177, KC_QUAD = 254,
		KC_PGUP, KC_PGDN,
		KC_RETURN, KC_SCROLL,
		KC_NP_MUL, KC_NP_DIV, KC_NP_ADD, KC_NP_SUB, KC_NP_DECIMAL, KC_PERIOD,
		KC_COUNT = 255
	};
	//	--==</structs_enums>==--

#if (GLIB_GAPI & GLIB_GAPI_OGL)
	class GLIB_API WindowOgl;
	class GLIB_API GContextOgl;
	class GLIB_API FrameBufOgl;

	class GLIB_API VertexArrOgl;
	class GLIB_API VertexBufOgl;
	class GLIB_API IndexBufOgl;

	class GLIB_API ShaderOgl;
	class GLIB_API ShaderProg;
	class GLIB_API AGMaterialOgl;
	class GLIB_API Texture2dOgl;
#endif	// GLIB_GAPI
}

#if (GLIB_WINDOW & GLIB_WINDOW_GLFW)
struct GLFWwindow;
struct GLFWimage;
#endif	// GLIB_WINDOW

#define GLIB_MAX_TEXTURES 8
#define GLIB_MIN_TEXTURES 1

#define GLIB_MAX_DRAW_LAYERS 10
#define GLIB_MAX_DRAW_ORDERS 10


#endif	// GLIB_DECL_HPP