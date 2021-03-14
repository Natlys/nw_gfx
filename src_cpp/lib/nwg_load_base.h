#ifndef NW_LOAD_LIB_H
#define NW_LOAD_LIB_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	extern bit ogl_load_base();
}
namespace NW
{
	typedef signed char GLbyte;
	typedef char GLchar;
	typedef short GLshort;
	typedef int GLint;
	typedef int GLsizei;
	typedef unsigned char GLboolean;
	typedef unsigned char GLubyte;
	typedef unsigned short GLushort;
	typedef unsigned short GLhalf;
	typedef unsigned int GLenum;
	typedef unsigned int GLuint;
	typedef unsigned int GLbitfield;
	typedef float GLfloat;
	typedef float GLclampf;
	typedef double GLdouble;
	typedef double GLclampd;
	typedef void GLvoid;
	typedef ptrdiff_t GLintptr;
	typedef ptrdiff_t GLsizeiptr;
}
namespace NW
{
	// getters
	typedef void (APIENTRYP pfn_ogl_get_int_v)(GLenum info, GLint* param);
	typedef const GLubyte* (APIENTRYP pfn_ogl_get_string)(GLenum info);
	typedef GLenum (APIENTRYP pfn_ogl_get_error)(void);
	// predicates
	typedef GLboolean (APIENTRYP pfn_ogl_is_enabled)(GLenum what);
	// drawing
	typedef void (APIENTRYP pfn_ogl_draw_vtx)(GLenum primitive, GLint first, GLsizei count);
	typedef void (APIENTRYP pfn_ogl_draw_idx)(GLenum primitive, GLsizei count, GLenum data_type, cptr index_data);
	// configs
	typedef void (APIENTRYP pfn_ogl_viewport)(GLint crd_x, GLint crd_y, GLsizei size_x, GLsizei size_y);
	typedef void (APIENTRYP pfn_ogl_scissor)(GLint crd_x, GLint crd_y, GLsizei size_x, GLsizei size_y);
	typedef void (APIENTRYP pfn_ogl_enable)(GLenum mode_to_enable);
	typedef void (APIENTRYP pfn_ogl_disable)(GLenum mode_to_disable);
	typedef void (APIENTRYP pfn_ogl_blend_equation)(GLenum blend_mode);
	typedef void (APIENTRYP pfn_ogl_blend_equation_separate)(GLenum blend_mode_rgb, GLenum blend_mode_alpha);
	typedef void (APIENTRYP pfn_ogl_blend_function)(GLenum src_factor, GLenum dest_factor);
	typedef void (APIENTRYP pfn_ogl_blend_function_separate)(GLenum src_factor_rgb, GLenum dest_factor_rgb, GLenum src_factor_alpha, GLenum dest_factor_alpha);
	typedef void (APIENTRYP pfn_ogl_depth_mask)(GLboolean enable);
	typedef void (APIENTRYP pfn_ogl_depth_func)(GLenum operation);
	typedef void (APIENTRYP pfn_ogl_polygon_mode)(GLenum face, GLenum mode);
	// other
	typedef void (APIENTRYP pfn_ogl_clear_error)(void);
}
namespace NW
{
	// getters
	extern pfn_ogl_get_int_v ogl_get_int_v;
	extern pfn_ogl_get_string ogl_get_string;
	extern pfn_ogl_get_error ogl_get_error;
	// predicates
	extern pfn_ogl_is_enabled ogl_is_enabled;
	// drawing
	extern pfn_ogl_draw_vtx ogl_draw_vtx;
	extern pfn_ogl_draw_idx ogl_draw_idx;
	// configs
	extern pfn_ogl_viewport ogl_viewport;
	extern pfn_ogl_scissor ogl_scissor;
	extern pfn_ogl_enable ogl_enable;
	extern pfn_ogl_disable ogl_disable;
	extern pfn_ogl_blend_equation ogl_blend_equation;
	extern pfn_ogl_blend_equation_separate ogl_blend_equation_separate;
	extern pfn_ogl_blend_function ogl_blend_function;
	extern pfn_ogl_blend_function_separate ogl_blend_function_separate;
	extern pfn_ogl_depth_mask ogl_depth_mask;
	extern pfn_ogl_depth_func ogl_depth_func;
	extern pfn_ogl_polygon_mode ogl_polygon_mode;
	// other
	extern pfn_ogl_clear_error ogl_clear_error;
}
// getters
#define glGetIntegerv ogl_get_int_v
#define glGetString ogl_get_string
#define glGetError ogl_get_error
// predicates
#define glIsEnabled ogl_is_enabled
// drawing
#define glDrawArrays ogl_draw_vtx
#define glDrawElements ogl_draw_idx
// configs
#define glViewport ogl_viewport
#define glScissor ogl_scissor
#define glEnable ogl_enable
#define glDisable ogl_disable
#define glBlendEquation ogl_blend_equation
#define glBlendEquationSeparate ogl_blend_equation_separate
#define glBlendFunc ogl_blend_function
#define glBlendFuncSeparate ogl_blend_function_separate
#define glDepthMask ogl_depth_mask
#define glDepthFunc ogl_depth_func
#define glPolygonMode ogl_polygon_mode
// other
#define glClearError ogl_clear_error

#ifndef __gl_h__
// constants
#define GL_NONE                           0
#define GL_TRUE                           1
#define GL_FALSE                          0
#define GL_ZERO                           0
#define GL_ONE                            1
// logic
#define GL_NEVER                          0x0200
#define GL_LESS                           0x0201
#define GL_EQUAL                          0x0202
#define GL_LEQUAL                         0x0203
#define GL_GREATER                        0x0204
#define GL_NOTEQUAL                       0x0205
#define GL_GEQUAL                         0x0206
#define GL_ALWAYS                         0x0207
#define GL_CLEAR                          0x1500
#define GL_AND                            0x1501
#define GL_AND_REVERSE                    0x1502
#define GL_COPY                           0x1503
#define GL_AND_INVERTED                   0x1504
#define GL_NOOP                           0x1505
#define GL_XOR                            0x1506
#define GL_OR                             0x1507
#define GL_NOR                            0x1508
#define GL_EQUIV                          0x1509
#define GL_INVERT                         0x150A
#define GL_OR_REVERSE                     0x150B
#define GL_COPY_INVERTED                  0x150C
#define GL_OR_INVERTED                    0x150D
#define GL_NAND                           0x150E
#define GL_SET                            0x150F
#define GL_LOGIC_OP_MODE                  0x0BF0
#define GL_INDEX_LOGIC_OP                 0x0BF1
#define GL_COLOR_LOGIC_OP                 0x0BF2
#define GL_KEEP                           0x1E00
#define GL_REPLACE                        0x1E01
#define GL_INCR                           0x1E02
#define GL_DECR                           0x1E03
// data types
#define GL_BOOL                           0x8B56
#define GL_BOOL_VEC2                      0x8B57
#define GL_BOOL_VEC3                      0x8B58
#define GL_BOOL_VEC4                      0x8B59
#define GL_BYTE                           0x1400
#define GL_2_BYTES                        0x1407
#define GL_3_BYTES                        0x1408
#define GL_4_BYTES                        0x1409
#define GL_UNSIGNED_BYTE                  0x1401
#define GL_SHORT                          0x1402
#define GL_UNSIGNED_SHORT                 0x1403
#define GL_INT                            0x1404
#define GL_INT_VEC2                       0x8B53
#define GL_INT_VEC3                       0x8B54
#define GL_INT_VEC4                       0x8B55
#define GL_UNSIGNED_INT                   0x1405
#define GL_UNSIGNED_INT_VEC2              0x8DC6
#define GL_UNSIGNED_INT_VEC3              0x8DC7
#define GL_UNSIGNED_INT_VEC4              0x8DC8
#define GL_FLOAT                          0x1406
#define GL_FLOAT_VEC2                     0x8B50
#define GL_FLOAT_VEC3                     0x8B51
#define GL_FLOAT_VEC4                     0x8B52
#define GL_FLOAT_MAT2                     0x8B5A
#define GL_FLOAT_MAT3                     0x8B5B
#define GL_FLOAT_MAT4                     0x8B5C
#define GL_DOUBLE                         0x140A
#define GL_DOUBLE_VEC2                    0x8FFC
#define GL_DOUBLE_VEC3                    0x8FFD
#define GL_DOUBLE_VEC4                    0x8FFE
#define GL_DOUBLE_MAT2                    0x8F46
#define GL_DOUBLE_MAT3                    0x8F47
#define GL_DOUBLE_MAT4                    0x8F48
#define GL_DOUBLE_MAT2x3                  0x8F49
#define GL_DOUBLE_MAT2x4                  0x8F4A
#define GL_DOUBLE_MAT3x2                  0x8F4B
#define GL_DOUBLE_MAT3x4                  0x8F4C
#define GL_DOUBLE_MAT4x2                  0x8F4D
#define GL_DOUBLE_MAT4x3                  0x8F4E
#define GL_SAMPLER_1D                     0x8B5D
#define GL_SAMPLER_2D                     0x8B5E
#define GL_SAMPLER_3D                     0x8B5F
// params
#define GL_VIEWPORT                       0x0BA2
#define GL_POINT_SIZE                     0x0B11
#define GL_LINE_WIDTH                     0x0B21
#define GL_POLYGON_MODE                   0x0B40
// modes
#define GL_POINT                          0x1B00
#define GL_LINE                           0x1B01
#define GL_FILL                           0x1B02
// faces
#define GL_FRONT_LEFT                     0x0400
#define GL_FRONT_RIGHT                    0x0401
#define GL_BACK_LEFT                      0x0402
#define GL_BACK_RIGHT                     0x0403
#define GL_FRONT                          0x0404
#define GL_BACK                           0x0405
#define GL_LEFT                           0x0406
#define GL_RIGHT                          0x0407
#define GL_FRONT_AND_BACK                 0x0408
#define GL_CULL_FACE                      0x0B44
#define GL_CULL_FACE_MODE                 0x0B45
#define GL_FRONT_FACE                     0x0B46
#define GL_CW                             0x0900
#define GL_CCW                            0x0901
// blending
#define GL_BLEND_DST_RGB                  0x80C8
#define GL_BLEND_SRC_RGB                  0x80C9
#define GL_BLEND_DST_ALPHA                0x80CA
#define GL_BLEND_SRC_ALPHA                0x80CB
#define GL_BLEND_SRC                      0x0BE1
#define GL_BLEND                          0x0BE2
#define GL_DST_COLOR                      0x0306
#define GL_ONE_MINUS_DST_COLOR            0x0307
#define GL_SRC_ALPHA_SATURATE             0x0308
#define GL_CONSTANT_COLOR                 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR       0x8002
#define GL_CONSTANT_ALPHA                 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA       0x8004
#define GL_BLEND_COLOR                    0x8005
#define GL_FUNC_ADD                       0x8006
#define GL_MIN                            0x8007
#define GL_MAX                            0x8008
#define GL_BLEND_EQUATION                 0x8009
#define GL_BLEND_EQUATION_RGB             0x8009
#define GL_BLEND_EQUATION_ALPHA           0x883D
#define GL_FUNC_SUBTRACT                  0x800A
#define GL_FUNC_REVERSE_SUBTRACT          0x800B
#define GL_SRC_COLOR                      0x0300
#define GL_ONE_MINUS_SRC_COLOR            0x0301
#define GL_SRC_ALPHA                      0x0302
#define GL_ONE_MINUS_SRC_ALPHA            0x0303
#define GL_DST_ALPHA                      0x0304
#define GL_ONE_MINUS_DST_ALPHA            0x0305
// scissors
#define GL_SCISSOR_BOX                    0x0C10
#define GL_SCISSOR_TEST                   0x0C11
// primitives(begin/draw mode)
#define GL_POINTS                         0x0000
#define GL_LINES                          0x0001
#define GL_LINE_LOOP                      0x0002
#define GL_LINE_STRIP                     0x0003
#define GL_TRIANGLES                      0x0004
#define GL_TRIANGLE_STRIP                 0x0005
#define GL_TRIANGLE_FAN                   0x0006
#define GL_QUADS                          0x0007
#define GL_QUAD_STRIP                     0x0008
#define GL_POLYGON                        0x0009
// configs
#define GL_DONT_CARE                      0x1100
#define GL_FASTEST                        0x1101
#define GL_NICEST                         0x1102
// info
#define GL_MAJOR_VERSION                  0x821B
#define GL_MINOR_VERSION                  0x821C
#define GL_VENDOR                         0x1F00
#define GL_RENDERER                       0x1F01
#define GL_VERSION                        0x1F02
#define GL_EXTENSIONS                     0x1F03
// error codes
#define GL_NO_ERROR                       0
#define GL_INVALID_ENUM                   0x0500
#define GL_INVALID_VALUE                  0x0501
#define GL_INVALID_OPERATION              0x0502
#define GL_STACK_OVERFLOW                 0x0503
#define GL_STACK_UNDERFLOW                0x0504
#define GL_OUT_OF_MEMORY                  0x0505
#endif	// __gl_h__
#endif

#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
}
#endif
#endif	// NW_GAPI
#endif	// NW_LOAD_LIB_H