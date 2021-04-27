#ifndef NW_GFX_LIB_CORE_H
#define NW_GFX_LIB_CORE_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	// getters
	typedef v1nil(NW_API_ENTRYP pfn_gfx_get_int_v)(GLenum info, GLint* param);
	typedef const GLubyte* (NW_API_ENTRYP pfn_gfx_get_string)(GLenum info);
	typedef GLenum (NW_API_ENTRYP pfn_gfx_get_error)(void);
	// predicates
	typedef GLboolean (NW_API_ENTRYP pfn_gfx_is_enabled)(GLenum what);
	// drawing
	typedef v1nil(NW_API_ENTRYP pfn_gfx_draw_vtx)(GLenum primitive, GLint first, GLsizei count);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_draw_idx)(GLenum primitive, GLsizei count, GLenum data_type, const GLvoid* index_data);
	// configs
	typedef v1nil(NW_API_ENTRYP pfn_gfx_line_width)(GLfloat size);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_point_size)(GLfloat size);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_viewport)(GLint crd_x, GLint crd_y, GLsizei size_x, GLsizei size_y);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_scissor)(GLint crd_x, GLint crd_y, GLsizei size_x, GLsizei size_y);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_enable)(GLenum mode_to_enable);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_disable)(GLenum mode_to_disable);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_blend_equation)(GLenum blend_mode);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_blend_equation_separate)(GLenum blend_mode_rgb, GLenum blend_mode_alpha);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_blend_function)(GLenum src_factor, GLenum dest_factor);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_blend_function_separate)(GLenum src_factor_rgb, GLenum dest_factor_rgb, GLenum src_factor_alpha, GLenum dest_factor_alpha);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_depth_mask)(GLboolean enable);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_depth_func)(GLenum operation);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_polygon_mode)(GLenum face, GLenum mode);
	// other
	typedef v1nil(NW_API_ENTRYP pfn_gfx_clear_error)(void);
	typedef void (NW_API_ENTRYP pfn_gfx_get_int_v)(GLenum info, GLint* param);
	typedef const GLubyte* (NW_API_ENTRYP pfn_gfx_get_string)(GLenum info);
	typedef GLenum (NW_API_ENTRYP pfn_gfx_get_error)(void);
	// predicates
	typedef GLboolean (NW_API_ENTRYP pfn_gfx_is_enabled)(GLenum what);
	// drawing
	typedef void (NW_API_ENTRYP pfn_gfx_draw_vtx)(GLenum primitive, GLint first, GLsizei count);
	typedef void (NW_API_ENTRYP pfn_gfx_draw_idx)(GLenum primitive, GLsizei count, GLenum data_type, const GLvoid* index_data);
	// configs
	typedef void (NW_API_ENTRYP pfn_gfx_viewport)(GLint crd_x, GLint crd_y, GLsizei size_x, GLsizei size_y);
	typedef void (NW_API_ENTRYP pfn_gfx_scissor)(GLint crd_x, GLint crd_y, GLsizei size_x, GLsizei size_y);
	typedef void (NW_API_ENTRYP pfn_gfx_enable)(GLenum mode_to_enable);
	typedef void (NW_API_ENTRYP pfn_gfx_disable)(GLenum mode_to_disable);
	typedef void (NW_API_ENTRYP pfn_gfx_blend_equation)(GLenum blend_mode);
	typedef void (NW_API_ENTRYP pfn_gfx_blend_equation_separate)(GLenum blend_mode_rgb, GLenum blend_mode_alpha);
	typedef void (NW_API_ENTRYP pfn_gfx_blend_function)(GLenum src_factor, GLenum dest_factor);
	typedef void (NW_API_ENTRYP pfn_gfx_blend_function_separate)(GLenum src_factor_rgb, GLenum dest_factor_rgb, GLenum src_factor_alpha, GLenum dest_factor_alpha);
	typedef void (NW_API_ENTRYP pfn_gfx_depth_mask)(GLboolean enable);
	typedef void (NW_API_ENTRYP pfn_gfx_depth_func)(GLenum operation);
	typedef void (NW_API_ENTRYP pfn_gfx_polygon_mode)(GLenum face, GLenum mode);
	// other
	typedef void (NW_API_ENTRYP pfn_gfx_clear_error)(void);
}
namespace NW
{
	// getters
	extern pfn_gfx_get_int_v ogl_get_int_v;
	extern pfn_gfx_get_string ogl_get_string;
	extern pfn_gfx_get_error ogl_get_error;
	// predicates
	extern pfn_gfx_is_enabled ogl_is_enabled;
	// drawing
	extern pfn_gfx_draw_vtx ogl_draw_vtx;
	extern pfn_gfx_draw_idx ogl_draw_idx;
	// configs
	extern pfn_gfx_line_width ogl_line_width;
	extern pfn_gfx_point_size ogl_point_size;
	extern pfn_gfx_viewport ogl_viewport;
	extern pfn_gfx_scissor ogl_scissor;
	extern pfn_gfx_enable ogl_enable;
	extern pfn_gfx_disable ogl_disable;
	extern pfn_gfx_blend_equation ogl_blend_equation;
	extern pfn_gfx_blend_equation_separate ogl_blend_equation_separate;
	extern pfn_gfx_blend_function ogl_blend_function;
	extern pfn_gfx_blend_function_separate ogl_blend_function_separate;
	extern pfn_gfx_depth_mask ogl_depth_mask;
	extern pfn_gfx_depth_func ogl_depth_func;
	extern pfn_gfx_polygon_mode ogl_polygon_mode;
	// other
	extern pfn_gfx_clear_error ogl_clear_error;
}
// getters
#define glGetIntegerv            ogl_get_int_v
#define glGetString              ogl_get_string
#define glGetError               ogl_get_error
// predicates
#define glIsEnabled              ogl_is_enabled
// drawing
#define glDrawArrays             ogl_draw_vtx
#define glDrawElements           ogl_draw_idx
// configs
#define glLineWidth              ogl_line_width
#define glPointSize              ogl_point_size
#define glViewport               ogl_viewport
#define glScissor                ogl_scissor
#define glEnable                 ogl_enable
#define glDisable                ogl_disable
#define glBlendEquation          ogl_blend_equation
#define glBlendEquationSeparate  ogl_blend_equation_separate
#define glBlendFunc              ogl_blend_function
#define glBlendFuncSeparate      ogl_blend_function_separate
#define glDepthMask              ogl_depth_mask
#define glDepthFunc              ogl_depth_func
#define glPolygonMode            ogl_polygon_mode
// other
#define glClearError             ogl_clear_error

#	ifndef __gl_h__
		// constants
#		define GL_NONE                           0
#		define GL_TRUE                           1
#		define GL_FALSE                          0
#		define GL_ZERO                           0
#		define GL_ONE                            1
		// operations
#		define GL_NEVER                          0x0200
#		define GL_LESS                           0x0201
#		define GL_EQUAL                          0x0202
#		define GL_LEQUAL                         0x0203
#		define GL_GREATER                        0x0204
#		define GL_NOTEQUAL                       0x0205
#		define GL_GEQUAL                         0x0206
#		define GL_ALWAYS                         0x0207
#		define GL_CLEAR                          0x1500
#		define GL_AND                            0x1501
#		define GL_AND_REVERSE                    0x1502
#		define GL_COPY                           0x1503
#		define GL_AND_INVERTED                   0x1504
#		define GL_NOOP                           0x1505
#		define GL_XOR                            0x1506
#		define GL_OR                             0x1507
#		define GL_NOR                            0x1508
#		define GL_EQUIV                          0x1509
#		define GL_INVERT                         0x150A
#		define GL_OR_REVERSE                     0x150B
#		define GL_COPY_INVERTED                  0x150C
#		define GL_OR_INVERTED                    0x150D
#		define GL_NAND                           0x150E
#		define GL_SET                            0x150F
#		define GL_LOGIC_OP_MODE                  0x0BF0
#		define GL_INDEX_LOGIC_OP                 0x0BF1
#		define GL_COLOR_LOGIC_OP                 0x0BF2
#		define GL_KEEP                           0x1E00
#		define GL_REPLACE                        0x1E01
#		define GL_INCR                           0x1E02
#		define GL_DECR                           0x1E03
		// data types
#		define GL_BOOL                           0x8B56
#		define GL_BOOL_VEC2                      0x8B57
#		define GL_BOOL_VEC3                      0x8B58
#		define GL_BOOL_VEC4                      0x8B59
#		define GL_BYTE                           0x1400
#		define GL_2_BYTES                        0x1407
#		define GL_3_BYTES                        0x1408
#		define GL_4_BYTES                        0x1409
#		define GL_UNSIGNED_BYTE                  0x1401
#		define GL_SHORT                          0x1402
#		define GL_UNSIGNED_SHORT                 0x1403
#		define GL_INT                            0x1404
#		define GL_INT_VEC2                       0x8B53
#		define GL_INT_VEC3                       0x8B54
#		define GL_INT_VEC4                       0x8B55
#		define GL_UNSIGNED_INT                   0x1405
#		define GL_UNSIGNED_INT_VEC2              0x8DC6
#		define GL_UNSIGNED_INT_VEC3              0x8DC7
#		define GL_UNSIGNED_INT_VEC4              0x8DC8
#		define GL_FLOAT                          0x1406
#		define GL_FLOAT_VEC2                     0x8B50
#		define GL_FLOAT_VEC3                     0x8B51
#		define GL_FLOAT_VEC4                     0x8B52
#		define GL_FLOAT_MAT2                     0x8B5A
#		define GL_FLOAT_MAT3                     0x8B5B
#		define GL_FLOAT_MAT4                     0x8B5C
#		define GL_DOUBLE                         0x140A
#		define GL_DOUBLE_VEC2                    0x8FFC
#		define GL_DOUBLE_VEC3                    0x8FFD
#		define GL_DOUBLE_VEC4                    0x8FFE
#		define GL_DOUBLE_MAT2                    0x8F46
#		define GL_DOUBLE_MAT3                    0x8F47
#		define GL_DOUBLE_MAT4                    0x8F48
#		define GL_DOUBLE_MAT2x3                  0x8F49
#		define GL_DOUBLE_MAT2x4                  0x8F4A
#		define GL_DOUBLE_MAT3x2                  0x8F4B
#		define GL_DOUBLE_MAT3x4                  0x8F4C
#		define GL_DOUBLE_MAT4x2                  0x8F4D
#		define GL_DOUBLE_MAT4x3                  0x8F4E
#		define GL_SAMPLER_1D                     0x8B5D
#		define GL_SAMPLER_2D                     0x8B5E
#		define GL_SAMPLER_3D                     0x8B5F
		// params
#		define GL_VIEWPORT                       0x0BA2
#		define GL_POINT_SIZE                     0x0B11
#		define GL_POINT_SIZE_RANGE               0x0B12
#		define GL_POINT_SIZE_GRANULARITY         0x0B13
#		define GL_LINE_WIDTH                     0x0B21
#		define GL_POLYGON_MODE                   0x0B40
		// modes
#		define GL_POINT                          0x1B00
#		define GL_LINE                           0x1B01
#		define GL_FILL                           0x1B02
		// faces
#		define GL_FRONT_LEFT                     0x0400
#		define GL_FRONT_RIGHT                    0x0401
#		define GL_BACK_LEFT                      0x0402
#		define GL_BACK_RIGHT                     0x0403
#		define GL_FRONT                          0x0404
#		define GL_BACK                           0x0405
#		define GL_LEFT                           0x0406
#		define GL_RIGHT                          0x0407
#		define GL_FRONT_AND_BACK                 0x0408
#		define GL_CULL_FACE                      0x0B44
#		define GL_CULL_FACE_MODE                 0x0B45
#		define GL_FRONT_FACE                     0x0B46
#		define GL_CW                             0x0900
#		define GL_CCW                            0x0901
		// blending
#		define GL_BLEND_DST_RGB                  0x80C8
#		define GL_BLEND_SRC_RGB                  0x80C9
#		define GL_BLEND_DST_ALPHA                0x80CA
#		define GL_BLEND_SRC_ALPHA                0x80CB
#		define GL_BLEND_SRC                      0x0BE1
#		define GL_BLEND                          0x0BE2
#		define GL_ONE_MUNUS_DST_ALPHA            0x0305
#		define GL_DST_COLOR                      0x0306
#		define GL_ONE_MINUS_DST_COLOR            0x0307
#		define GL_SRC_ALPHA_SATURATE             0x0308
#		define GL_CONSTANT_COLOR                 0x8001
#		define GL_ONE_MINUS_CONSTANT_COLOR       0x8002
#		define GL_CONSTANT_ALPHA                 0x8003
#		define GL_ONE_MINUS_CONSTANT_ALPHA       0x8004
#		define GL_BLEND_COLOR                    0x8005
#		define GL_FUNC_ADD                       0x8006
#		define GL_MIN                            0x8007
#		define GL_MAX                            0x8008
#		define GL_BLEND_EQUATION                 0x8009
#		define GL_BLEND_EQUATION_RGB             0x8009
#		define GL_BLEND_EQUATION_ALPHA           0x883D
#		define GL_FUNC_SUBTRACT                  0x800A
#		define GL_FUNC_REVERSE_SUBTRACT          0x800B
#		define GL_SRC_COLOR                      0x0300
#		define GL_ONE_MINUS_SRC_COLOR            0x0301
#		define GL_SRC_ALPHA                      0x0302
#		define GL_ONE_MINUS_SRC_ALPHA            0x0303
#		define GL_DST_ALPHA                      0x0304
#		define GL_ONE_MINUS_DST_ALPHA            0x0305
		// scissors
#		define GL_SCISSOR_BOX                    0x0C10
#		define GL_SCISSOR_TEST                   0x0C11
		// primitives(begin/draw mode)
#		define GL_POINTS                         0x0000
#		define GL_LINES                          0x0001
#		define GL_LINE_LOOP                      0x0002
#		define GL_LINE_STRIP                     0x0003
#		define GL_TRIANGLES                      0x0004
#		define GL_TRIANGLE_STRIP                 0x0005
#		define GL_TRIANGLE_FAN                   0x0006
#		define GL_QUADS                          0x0007
#		define GL_QUAD_STRIP                     0x0008
#		define GL_POLYGON                        0x0009
		// configs
#		define GL_DONT_CARE                      0x1100
#		define GL_FASTEST                        0x1101
#		define GL_NICEST                         0x1102
		// info
#		define GL_MAJOR_VERSION                  0x821B
#		define GL_MINOR_VERSION                  0x821C
#		define GL_VENDOR                         0x1F00
#		define GL_RENDERER                       0x1F01
#		define GL_VERSION                        0x1F02
#		define GL_EXTENSIONS                     0x1F03
		// error codes
#		define GL_NO_ERROR                       0
#		define GL_INVALID_ENUM                   0x0500
#		define GL_INVALID_VALUE                  0x0501
#		define GL_INVALID_OPERATION              0x0502
#		define GL_STACK_OVERFLOW                 0x0503
#		define GL_STACK_UNDERFLOW                0x0504
#		define GL_OUT_OF_MEMORY                  0x0505
#	endif	// __gl_h__
#	ifndef NW_GFX_VAL_H
#		define NW_GFX_VAL_H
		// bool 8 bit
#		define NW_GFX_V1BIT GL_BOOL
#		define NW_GFX_V2BIT GL_BOOL
#		define NW_GFX_V3BIT GL_BOOL
#		define NW_GFX_V4BIT GL_BOOL
#		define NW_GFX_M2BIT GL_BOOL
#		define NW_GFX_M3BIT GL_BOOL
#		define NW_GFX_M4BIT GL_BOOL
		// signed int 8 bit
#		define NW_GFX_V1S08 GL_BYTE
#		define NW_GFX_V2S08 GL_BYTE
#		define NW_GFX_V3S08 GL_BYTE
#		define NW_GFX_V4S08 GL_BYTE
#		define NW_GFX_M2S08 GL_BYTE
#		define NW_GFX_M3S08 GL_BYTE
#		define NW_GFX_M4S08 GL_BYTE
		// signed int 16 bit
#		define NW_GFX_V1S16 GL_SHORT
#		define NW_GFX_V2S16 GL_SHORT
#		define NW_GFX_V3S16 GL_SHORT
#		define NW_GFX_V4S16 GL_SHORT
#		define NW_GFX_M2S16 GL_SHORT
#		define NW_GFX_M3S16 GL_SHORT
#		define NW_GFX_M4S16 GL_SHORT
		// signed int 32 bit
#		define NW_GFX_V1S32 GL_INT
#		define NW_GFX_V2S32 GL_INT
#		define NW_GFX_V3S32 GL_INT
#		define NW_GFX_V4S32 GL_INT
#		define NW_GFX_M2S32 GL_INT
#		define NW_GFX_M3S32 GL_INT
#		define NW_GFX_M4S32 GL_INT
		// signed int 64 bit
#		define NW_GFX_V1S64 GL_INT
#		define NW_GFX_V2S64 GL_INT
#		define NW_GFX_V3S64 GL_INT
#		define NW_GFX_V4S64 GL_INT
#		define NW_GFX_M2S64 GL_INT
#		define NW_GFX_M3S64 GL_INT
#		define NW_GFX_M4S64 GL_INT
		// unsigned int 8 bit
#		define NW_GFX_V1U08 GL_UNSIGNED_BYTE
#		define NW_GFX_V2U08 GL_UNSIGNED_BYTE
#		define NW_GFX_V3U08 GL_UNSIGNED_BYTE
#		define NW_GFX_V4U08 GL_UNSIGNED_BYTE
#		define NW_GFX_M2U08 GL_UNSIGNED_BYTE
#		define NW_GFX_M3U08 GL_UNSIGNED_BYTE
#		define NW_GFX_M4U08 GL_UNSIGNED_BYTE
		// unsigned int 16 bit
#		define NW_GFX_V1U16 GL_UNSIGNED_SHORT
#		define NW_GFX_V2U16 GL_UNSIGNED_SHORT
#		define NW_GFX_V3U16 GL_UNSIGNED_SHORT
#		define NW_GFX_V4U16 GL_UNSIGNED_SHORT
#		define NW_GFX_M2U16 GL_UNSIGNED_SHORT
#		define NW_GFX_M3U16 GL_UNSIGNED_SHORT
#		define NW_GFX_M4U16 GL_UNSIGNED_SHORT
		// unsigned int 32 bit
#		define NW_GFX_V1U32 GL_UNSIGNED_INT
#		define NW_GFX_V2U32 GL_UNSIGNED_INT
#		define NW_GFX_V3U32 GL_UNSIGNED_INT
#		define NW_GFX_V4U32 GL_UNSIGNED_INT
#		define NW_GFX_M2U32 GL_UNSIGNED_INT
#		define NW_GFX_M3U32 GL_UNSIGNED_INT
#		define NW_GFX_M4U32 GL_UNSIGNED_INT
		// unsigned int 64 bit
#		define NW_GFX_V1U64 GL_UNSIGNED_INT
#		define NW_GFX_V2U64 GL_UNSIGNED_INT
#		define NW_GFX_V3U64 GL_UNSIGNED_INT
#		define NW_GFX_V4U64 GL_UNSIGNED_INT
#		define NW_GFX_M2U64 GL_UNSIGNED_INT
#		define NW_GFX_M3U64 GL_UNSIGNED_INT
#		define NW_GFX_M4U64 GL_UNSIGNED_INT
		// float 32 bit
#		define NW_GFX_V1F32 GL_FLOAT
#		define NW_GFX_V2F32 GL_FLOAT
#		define NW_GFX_V3F32 GL_FLOAT
#		define NW_GFX_V4F32 GL_FLOAT
#		define NW_GFX_M2F32 GL_FLOAT
#		define NW_GFX_M3F32 GL_FLOAT
#		define NW_GFX_M4F32 GL_FLOAT
		// float 64 bit
#		define NW_GFX_V1F64 GL_FLOAT
#		define NW_GFX_V2F64 GL_FLOAT
#		define NW_GFX_V3F64 GL_FLOAT
#		define NW_GFX_V4F64 GL_FLOAT
#		define NW_GFX_M2F64 GL_FLOAT
#		define NW_GFX_M3F64 GL_FLOAT
#		define NW_GFX_M4F64 GL_FLOAT
#	endif	// NW_GFX_VAL_H
#	ifndef NW_GFX_MACRO_H
#		define NW_GFX_MACRO_H
		// faces sides directions
#		define NW_GFX_FACE_LFT     GL_LEFT
#		define NW_GFX_FACE_RHT     GL_RIGHT
#		define NW_GFX_FACE_LFT_RHT 0x0001 // none
#		define NW_GFX_FACE_BOT     0x0003 // none
#		define NW_GFX_FACE_TOP     0x0002 // none
#		define NW_GFX_FACE_BOT_TOP 0x0004 // none
#		define NW_GFX_FACE_BCK     GL_BACK
#		define NW_GFX_FACE_FRT     GL_FRONT
#		define NW_GFX_FACE_BCK_FRT GL_FRONT_AND_BACK 
#		define NW_GFX_FACE_BCK_LFT GL_BACK_LEFT
#		define NW_GFX_FACE_BCK_RHT GL_BACK_RIGHT
#		define NW_GFX_FACE_FRT_LFT GL_FRONT_LEFT
#		define NW_GFX_FACE_FRT_RHT GL_FRONT_RIGHT
		// operators
#		define NW_GFX_LOGIC_ALWAYS  GL_ALWAYS
#		define NW_GFX_LOGIC_NEVER   GL_NEVER
#		define NW_GFX_LOGIC_GREATER GL_GREATER
#		define NW_GFX_LOGIC_LESSER  GL_LESS
#		define NW_GFX_LOGIC_EQUAL   GL_EQUAL
#		define NW_GFX_LOGIC_NEQUAL  GL_NOTEQUAL
#		define NW_GFX_LOGIC_GEQUAL  GL_GEQUAL
#		define NW_GFX_LOGIC_LEQUAL  GL_LEQUAL
#		define NW_GFX_LOGIC_AND     GL_AND
#		define NW_GFX_LOGIC_AND_REV GL_AND_REVERSE
#		define NW_GFX_LOGIC_AND_INV GL_AND_INVERTED
#		define NW_GFX_LOGIC_OR      GL_OR
#		define NW_GFX_LOGIC_OR_NOT  GL_NOR 
#		define NW_GFX_LOGIC_OR_EXC  GL_XOR
#		define NW_GFX_LOGIC_NO_OPER GL_NOOP
		// stencil testing
#		define NW_GFX_STENCIL_DECR GL_DECR
#		define NW_GFX_STENCIL_INCR GL_INCR
#		define NW_GFX_STENCIL_KEEP GL_KEEP
#		define NW_GFX_STENCIL_ZERO GL_ZERO
#		define NW_GFX_STENCIL_REPL GL_REPLACE
#		define NW_GFX_STENCIL_INVT GL_INVERT
		// color blending
#		define NW_GFX_BLEND_SRC_ALPHA           GL_SRC_ALPHA
#		define NW_GFX_BLEND_DST_ALPHA           GL_DST_ALPHA
#		define NW_GFX_BLEND_SRC_COLOR           GL_SRC_COLOR
#		define NW_GFX_BLEND_DST_COLOR           GL_DST_COLOR
#		define NW_GFX_BLEND_ONE_MINUS_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
#		define NW_GFX_BLEND_ONE_MUNUS_DST_ALPHA GL_ONE_MUNUS_DST_ALPHA 
#		define NW_GFX_BLEND_ONE_MINUS_SRC_COLOR GL_ONE_MINUS_SRC_COLOR
#		define NW_GFX_BLEND_ONE_MINUS_DST_COLOR GL_ONE_MINUS_DST_COLOR
		// face culling
#		define NW_GFX_CULL_CW  GL_CW
#		define NW_GFX_CULL_CCW GL_CCW
		// geometry filling
#		define NW_GFX_FILL_LINE   GL_LINE
#		define NW_GFX_FILL_FACE   GL_FILL
		// primitives
#		define NW_GFX_PRIM_POINTS         GL_POINTS
#		define NW_GFX_PRIM_LINES          GL_LINES
#		define NW_GFX_PRIM_LINE_LOOP      GL_LINE_LOOP
#		define NW_GFX_PRIM_LINE_STRIP     GL_LINE_STRIP
#		define NW_GFX_PRIM_TRIANGLES      GL_TRIANGLES
#		define NW_GFX_PRIM_TRIANGLE_STRIP GL_TRIANGLE_STRIP
#		define NW_GFX_PRIM_TRIANGLE_FAN   GL_TRIANGLE_FAN
		// texture wraps
#		define NW_GFX_WRAP_REPEAT  GL_REPEAT
#		define NW_GFX_WRAP_CLAMP   GL_CLAMP_TO_EDGE
#		define NW_GFX_WRAP_BORDER  GL_CLAMP_TO_BORDER
		// texture filters
#		define NW_GFX_FILTER_LINEAR  GL_LINEAR
#		define NW_GFX_FILTER_NEAREST GL_NEAREST
		// base formats
#		define NW_GFX_FORMAT_RED   GL_RED
#		define NW_GFX_FORMAT_RG	   GL_RG
#		define NW_GFX_FORMAT_RGB   GL_RGB
#		define NW_GFX_FORMAT_RGBA  GL_RGBA
#		define NW_GFX_FORMAT_DEPT  GL_DEPTH_COMPONENT
#		define NW_GFX_FORMAT_STEN  GL_STENCIL_INDEX
#		define NW_GFX_FORMAT_DPST  GL_DEPTH_STENCIL
		// pixel formats
#		define NW_GFX_FORMAT_R8_S8        GL_R8I
#		define NW_GFX_FORMAT_R8_U8        GL_R8UI
#		define NW_GFX_FORMAT_R16_S16      GL_R16I
#		define NW_GFX_FORMAT_R16_U16      GL_R16UI
#		define NW_GFX_FORMAT_R32_S32      GL_R32I
#		define NW_GFX_FORMAT_R8G8_U16     GL_RG8UI
#		define NW_GFX_FORMAT_R8G8_S16     GL_RG8I
#		define NW_GFX_FORMAT_R16G16_S32   GL_RG16I
#		define NW_GFX_FORMAT_R8G8B8_S32   GL_RGB8I
#		define NW_GFX_FORMAT_R8G8B8A8_S32 GL_RGBA8I
#		define NW_GFX_FORMAT_R32_U32      GL_R32UI
#		define NW_GFX_FORMAT_R16G16_U32   GL_RG16UI
#		define NW_GFX_FORMAT_R8G8B8_U32   GL_RGB8UI
#		define NW_GFX_FORMAT_R8G8B8A8_U32 GL_RGBA8UI
#		define NW_GFX_FORMAT_S8_S8        GL_R8I
#		define NW_GFX_FORMAT_D32_S32      GL_DEPTH_COMPONENT
#		define NW_GFX_FORMAT_D32_U32      GL_DEPTH_COMPONENT
#		define NW_GFX_FORMAT_S8_U8        GL_STENCIL_INDEX
#		define NW_GFX_FORMAT_D24S8_S32    GL_DEPTH_STENCIL
#		define NW_GFX_FORMAT_D24S8_U32    GL_DEPTH_STENCIL
#	endif // NW_GFX_MACRO_H
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
#		include "dxgi.h"
#		include "d3d11.h"
// by using D3DCompile() from <d3dcompiler.h" / d3dcompiler.lib, we introduce a dependency to a given version of d3dcompiler_XX.dll (see D3DCOMPILER_DLL_A)
// if you would like to use this DX11 sample code but remove this dependency you can:
//  1) compile once, save the compiled shader blobs into a file or source code and pass them to CreateVertexShader()/CreatePixelShader() [preferred solution]
//  2) use code to detect any version of the DLL and grab a pointer to D3DCompile from the DLL.
struct ID3D11DeviceChild;
struct IDXGISwapChain;
struct ID3D11Resource;
struct ID3D11ShaderResource;
struct ID3D11ShaderResourceView;
struct ID3D11RasterizerState;
struct ID3D11DepthStencilState;
namespace NW
{
	typedef HRESULT(NW_API_ENTRYP pfn_d3d_new_device_context)
		(_In_opt_ IDXGIAdapter*,
		D3D_DRIVER_TYPE, HMODULE, UINT,
		_In_reads_opt_(FeatureLevels) CONST D3D_FEATURE_LEVEL*,
		UINT FeatureLevels, UINT, _COM_Outptr_opt_ ID3D11Device**,
		_Out_opt_ D3D_FEATURE_LEVEL*, _COM_Outptr_opt_ ID3D11DeviceContext**);
	typedef HRESULT(NW_API_ENTRYP pfn_d3d_new_device_context_swap)
		(_In_opt_ IDXGIAdapter*,
		D3D_DRIVER_TYPE, HMODULE, UINT,
		_In_reads_opt_(FeatureLevels) CONST D3D_FEATURE_LEVEL*,
		UINT FeatureLevels, UINT, _In_opt_ CONST DXGI_SWAP_CHAIN_DESC*,
		_COM_Outptr_opt_ IDXGISwapChain**, _COM_Outptr_opt_ ID3D11Device**,
		_Out_opt_ D3D_FEATURE_LEVEL*, _COM_Outptr_opt_ ID3D11DeviceContext**);
}
namespace NW
{
	extern pfn_d3d_new_device_context gfx_new_device_context;
	extern pfn_d3d_new_device_context_swap gfx_new_device_context_swap;
}
#		define D3D11CreateDevice               gfx_new_device_context
#		define D3D11CreateDeviceAndSwapChain   gfx_new_device_context_swap
#	endif	// GAPI_D3D
#endif	// NW_GAPI
#endif	// NW_GFX_LIB_CORE_H