#ifndef NC_GFX_LIB_CORE_H
#define NC_GFX_LIB_CORE_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	if (NC_GAPI & NC_GAPI_OGL)
// --core
namespace NC
{
	// /* getters */
	typedef v1nil_t(NC_API_CALL* pfn_gfx_get_int)(GLenum info, GLint* param);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_get_intv)(GLenum info, GLint* param);
	typedef const GLubyte* (NC_API_CALL* pfn_gfx_get_str)(GLenum info);
	typedef GLenum(NC_API_CALL* pfn_gfx_get_err)(v1nil_t);
	/* //setters */
	typedef v1nil_t(NC_API_CALL* pfn_gfx_set_enabled)(GLenum mode_to_enable);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_set_disabled)(GLenum mode_to_disable);
	// /* vetters */
	typedef GLboolean(NC_API_CALL* pfn_gfx_is_enabled)(GLenum what);
	typedef GLboolean(NC_API_CALL* pfn_gfx_is_shader)(GLuint id);
	typedef GLboolean(NC_API_CALL* pfn_gfx_is_material)(GLuint id);
	/* commands */
	typedef v1nil_t(NC_API_CALL* pfn_gfx_draw_vtx)(GLenum primitive, GLint first, GLsizei count);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_draw_idx)(GLenum primitive, GLsizei count, GLenum data_type, const GLvoid* index_data);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_clear_error)(v1nil_t);
#		ifndef NC_GFX_CODES_CORE
#		define NC_GFX_CODES_CORE
	// constants
#			define GL_NONE                           0
#			define GL_TRUE                           1
#			define GL_FALSE                          0
#			define GL_ZERO                           0
#			define GL_ONE                            1
			// operations
#			define GL_NEVER                          0x0200
#			define GL_LESS                           0x0201
#			define GL_EQUAL                          0x0202
#			define GL_LEQUAL                         0x0203
#			define GL_GREATER                        0x0204
#			define GL_NOTEQUAL                       0x0205
#			define GL_GEQUAL                         0x0206
#			define GL_ALWAYS                         0x0207
#			define GL_CLEAR                          0x1500
#			define GL_AND                            0x1501
#			define GL_AND_REVERSE                    0x1502
#			define GL_COPY                           0x1503
#			define GL_AND_INVERTED                   0x1504
#			define GL_NOOP                           0x1505
#			define GL_XOR                            0x1506
#			define GL_OR                             0x1507
#			define GL_NOR                            0x1508
#			define GL_EQUIV                          0x1509
#			define GL_INVERT                         0x150A
#			define GL_OR_REVERSE                     0x150B
#			define GL_COPY_INVERTED                  0x150C
#			define GL_OR_INVERTED                    0x150D
#			define GL_NAND                           0x150E
#			define GL_SET                            0x150F
#			define GL_LOGIC_OP_MODE                  0x0BF0
#			define GL_INDEX_LOGIC_OP                 0x0BF1
#			define GL_COLOR_LOGIC_OP                 0x0BF2
#			define GL_KEEP                           0x1E00
#			define GL_REPLACE                        0x1E01
#			define GL_INCR                           0x1E02
#			define GL_DECR                           0x1E03
			// data types
#			define GL_BOOL                           0x8B56
#			define GL_BOOL_VEC2                      0x8B57
#			define GL_BOOL_VEC3                      0x8B58
#			define GL_BOOL_VEC4                      0x8B59
#			define GL_BYTE                           0x1400
#			define GL_2_BYTES                        0x1407
#			define GL_3_BYTES                        0x1408
#			define GL_4_BYTES                        0x1409
#			define GL_UNSIGNED_BYTE                  0x1401
#			define GL_SHORT                          0x1402
#			define GL_UNSIGNED_SHORT                 0x1403
#			define GL_INT                            0x1404
#			define GL_INT_VEC2                       0x8B53
#			define GL_INT_VEC3                       0x8B54
#			define GL_INT_VEC4                       0x8B55
#			define GL_UNSIGNED_INT                   0x1405
#			define GL_UNSIGNED_INT_VEC2              0x8DC6
#			define GL_UNSIGNED_INT_VEC3              0x8DC7
#			define GL_UNSIGNED_INT_VEC4              0x8DC8
#			define GL_FLOAT                          0x1406
#			define GL_FLOAT_VEC2                     0x8B50
#			define GL_FLOAT_VEC3                     0x8B51
#			define GL_FLOAT_VEC4                     0x8B52
#			define GL_FLOAT_MAT2                     0x8B5A
#			define GL_FLOAT_MAT3                     0x8B5B
#			define GL_FLOAT_MAT4                     0x8B5C
#			define GL_DOUBLE                         0x140A
#			define GL_DOUBLE_VEC2                    0x8FFC
#			define GL_DOUBLE_VEC3                    0x8FFD
#			define GL_DOUBLE_VEC4                    0x8FFE
#			define GL_DOUBLE_MAT2                    0x8F46
#			define GL_DOUBLE_MAT3                    0x8F47
#			define GL_DOUBLE_MAT4                    0x8F48
#			define GL_DOUBLE_MAT2x3                  0x8F49
#			define GL_DOUBLE_MAT2x4                  0x8F4A
#			define GL_DOUBLE_MAT3x2                  0x8F4B
#			define GL_DOUBLE_MAT3x4                  0x8F4C
#			define GL_DOUBLE_MAT4x2                  0x8F4D
#			define GL_DOUBLE_MAT4x3                  0x8F4E
#			define GL_SAMPLER_1D                     0x8B5D
#			define GL_SAMPLER_2D                     0x8B5E
#			define GL_SAMPLER_3D                     0x8B5F
			// params
#			define GL_VIEWPORT                       0x0BA2
#			define GL_POINT_SIZE                     0x0B11
#			define GL_POINT_SIZE_RANGE               0x0B12
#			define GL_POINT_SIZE_GRANULARITY         0x0B13
#			define GL_LINE_WIDTH                     0x0B21
#			define GL_POLYGON_MODE                   0x0B40
			// modes
#			define GL_POINT                          0x1B00
#			define GL_LINE                           0x1B01
#			define GL_FILL                           0x1B02
			// faces
#			define GL_FRONT_LEFT                     0x0400
#			define GL_FRONT_RIGHT                    0x0401
#			define GL_BACK_LEFT                      0x0402
#			define GL_BACK_RIGHT                     0x0403
#			define GL_FRONT                          0x0404
#			define GL_BACK                           0x0405
#			define GL_LEFT                           0x0406
#			define GL_RIGHT                          0x0407
#			define GL_FRONT_AND_BACK                 0x0408
#			define GL_CULL_FACE                      0x0B44
#			define GL_CULL_FACE_MODE                 0x0B45
#			define GL_FRONT_FACE                     0x0B46
#			define GL_CW                             0x0900
#			define GL_CCW                            0x0901
			// blending
#			define GL_BLEND_DST_RGB                  0x80C8
#			define GL_BLEND_SRC_RGB                  0x80C9
#			define GL_BLEND_DST_ALPHA                0x80CA
#			define GL_BLEND_SRC_ALPHA                0x80CB
#			define GL_BLEND_SRC                      0x0BE1
#			define GL_BLEND                          0x0BE2
#			define GL_ONE_MUNUS_DST_ALPHA            0x0305
#			define GL_DST_COLOR                      0x0306
#			define GL_ONE_MINUS_DST_COLOR            0x0307
#			define GL_SRC_ALPHA_SATURATE             0x0308
#			define GL_CONSTANT_COLOR                 0x8001
#			define GL_ONE_MINUS_CONSTANT_COLOR       0x8002
#			define GL_CONSTANT_ALPHA                 0x8003
#			define GL_ONE_MINUS_CONSTANT_ALPHA       0x8004
#			define GL_BLEND_COLOR                    0x8005
#			define GL_FUNC_ADD                       0x8006
#			define GL_MIN                            0x8007
#			define GL_MAX                            0x8008
#			define GL_BLEND_EQUATION                 0x8009
#			define GL_BLEND_EQUATION_RGB             0x8009
#			define GL_BLEND_EQUATION_ALPHA           0x883D
#			define GL_FUNC_SUBTRACT                  0x800A
#			define GL_FUNC_REVERSE_SUBTRACT          0x800B
#			define GL_SRC_COLOR                      0x0300
#			define GL_ONE_MINUS_SRC_COLOR            0x0301
#			define GL_SRC_ALPHA                      0x0302
#			define GL_ONE_MINUS_SRC_ALPHA            0x0303
#			define GL_DST_ALPHA                      0x0304
#			define GL_ONE_MINUS_DST_ALPHA            0x0305
			// scissors
#			define GL_SCISSOR_BOX                    0x0C10
#			define GL_SCISSOR_TEST                   0x0C11
			// primitives(begin/draw mode)
#			define GL_POINTS                         0x0000
#			define GL_LINES                          0x0001
#			define GL_LINE_LOOP                      0x0002
#			define GL_LINE_STRIP                     0x0003
#			define GL_TRIANGLES                      0x0004
#			define GL_TRIANGLE_STRIP                 0x0005
#			define GL_TRIANGLE_FAN                   0x0006
#			define GL_QUADS                          0x0007
#			define GL_QUAD_STRIP                     0x0008
#			define GL_POLYGON                        0x0009
			// configs
#			define GL_DONT_CARE                      0x1100
#			define GL_FASTEST                        0x1101
#			define GL_NICEST                         0x1102
			// info
#			define GL_MAJOR_VERSION                  0x821B
#			define GL_MINOR_VERSION                  0x821C
#			define GL_VENDOR                         0x1F00
#			define GL_RENDERER                       0x1F01
#			define GL_VERSION                        0x1F02
#			define GL_EXTENSIONS                     0x1F03
			// error codes
#			define GL_NO_ERROR                       0
#			define GL_INVALID_ENUM                   0x0500
#			define GL_INVALID_VALUE                  0x0501
#			define GL_INVALID_OPERATION              0x0502
#			define GL_STACK_OVERFLOW                 0x0503
#			define GL_STACK_UNDERFLOW                0x0504
#			define GL_OUT_OF_MEMORY                  0x0505
#		endif // NC_GFX_CODES_CORE
}
// --buffer
namespace NC
{
	// // --general
	typedef v1nil_t(NC_API_CALL* pfn_gfx_buf_gen)(GLsizei count, GLuint* buf_ids);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_buf_del)(GLsizei count, const GLuint* buf_ids);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_buf_bind)(GLenum buf_type, GLuint buf_id);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_buf_bind_rang)(GLenum buf_type, GLuint bind_idx, GLuint buf_id, GLintptr offset, GLsizeiptr size);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_buf_bind_base)(GLenum buf_type, GLuint bind_idx, GLuint buf_id);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_buf_bind_vert)(GLuint bind_idx, GLuint vbuf_id, GLintptr offset, GLsizei stride);
	// /* setters */
	typedef v1nil_t(NC_API_CALL* pfn_gfx_buf_set_data)(GLenum buf_type, GLsizei data_size, const GLvoid* data_ptr, GLenum data_access_type);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_buf_set_sub_data)(GLenum buf_type, GLsizei offset_size, GLsizei data_size, const GLvoid* data_ptr);
#		ifndef NC_GFX_CODES_BUFFER
#		define NC_GFX_CODES_BUFFER_H
/////////// --general
#			define GL_BUFFER                         0x82E0
#			define GL_COPY_READ_BUFFER_BINDING       0x8F36
#			define GL_COPY_READ_BUFFER               GL_COPY_READ_BUFFER_BINDING
#			define GL_COPY_WRITE_BUFFER_BINDING      0x8F37
#			define GL_COPY_WRITE_BUFFER              GL_COPY_WRITE_BUFFER_BINDING
#			define GL_READ_ONLY                      0x88B8
#			define GL_WRITE_ONLY                     0x88B9
#			define GL_READ_WRITE                     0x88BA
#			define GL_BUFFER_ACCESS                  0x88BB
#			define GL_BUFFER_MAPPED                  0x88BC
#			define GL_STREAM_DRAW                    0x88E0
#			define GL_STREAM_READ                    0x88E1
#			define GL_STREAM_COPY                    0x88E2
#			define GL_STATIC_DRAW                    0x88E4
#			define GL_STATIC_READ                    0x88E5
#			define GL_STATIC_COPY                    0x88E6
#			define GL_DYNAMIC_DRAW                   0x88E8
#			define GL_DYNAMIC_READ                   0x88E9
#			define GL_DYNAMIC_COPY                   0x88EA
			// vertex_buffer
#			define GL_ARRAY_BUFFER                   0x8892
#			define GL_ARRAY_BUFFER_BINDING           0x8894
			// index_buffer
#			define GL_ELEMENT_ARRAY_BUFFER           0x8893
#			define GL_ELEMENT_ARRAY_BUFFER_BINDING   0x8895
			// uniform_buffer
#			define GL_UNIFORM_BUFFER                 0x8A11
#			define GL_UNIFORM_BUFFER_BINDING         0x8A28
#			define GL_UNIFORM_BUFFER_START           0x8A29
#			define GL_UNIFORM_BUFFER_SIZE            0x8A2A
#			define GL_MAX_UNIFORM_BUFFER_BINDINGS    0x8A2F
#			define GL_MAX_UNIFORM_BLOCK_SIZE         0x8A30
#			define GL_UNIFORM_BLOCK_BINDING          0x8A3F
#		endif // NC_GFX_CODES_BUFFER
}
// --layout
namespace NC
{
	// // --general
	typedef v1nil_t(NC_API_CALL* pfn_gfx_layt_gen)(GLsizei count, GLuint* vtx_arr_ids);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_layt_del)(GLsizei count, const GLuint* vtx_arr_ids);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_layt_bind)(GLuint vtx_arr_id);
	/* //setters */
	typedef v1nil_t(NC_API_CALL* pfn_gfx_layt_set_enabled)(GLuint vtx_atb_idx);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_layt_set_disabled)(GLuint vtx_atb_idx);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_layt_set_atb)(GLuint vtx_atb_idx, GLint count, GLenum data_type, GLboolean is_normalized, GLsizei stride_size, const GLvoid* offset);
#		ifndef NC_GFX_CODES_LAYOUT
#		define NC_GFX_CODES_LAYOUT
/////////// --vertex_array
#			define GL_VERTEX_ARRAY_BINDING           0x85B5
#			define GL_VERTEX_ATTRIB_BINDING          0x82D4
#			define GL_MAX_VERTEX_ATTRIB_BINDINGS     0x82DA
#			define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#			define GL_MAX_VERTEX_ATTRIBS             0x8869
#		endif
}
// --rasterizer
namespace NC
{
	/* setters */
	typedef v1nil_t(NC_API_CALL* pfn_gfx_rastr_set_cull)(GLenum mode);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_rastr_set_fill)(GLenum face, GLenum mode);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_rastr_set_viewp)(GLint crd_x, GLint crd_y, GLsizei size_x, GLsizei size_y);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_rastr_set_sciss)(GLint crd_x, GLint crd_y, GLsizei size_x, GLsizei size_y);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_rastr_set_line_width)(GLfloat size);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_rastr_set_point_size)(GLfloat size);
}
// --depth_stencil
namespace NC
{
	/* setters */
	typedef v1nil_t(NC_API_CALL* pfn_gfx_depth_set_mask)(GLboolean enable_flag);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_depth_set_func)(GLenum logic_oper);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_stenc_set_mask)(GLuint bitmask);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_stenc_set_func)(GLenum logic_oper, GLint ref_value, GLuint bitmask);
}
// --blending
namespace NC
{
	/* setters */
	typedef v1nil_t(NC_API_CALL* pfn_gfx_blend_set_equation)(GLenum blend_mode);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_blend_set_equation_separate)(GLenum blend_mode_rgb, GLenum blend_mode_alpha);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_blend_set_function)(GLenum src_factor, GLenum dest_factor);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_blend_set_function_separate)(GLenum src_factor_rgb, GLenum dest_factor_rgb, GLenum src_factor_alpha, GLenum dest_factor_alpha);
}
// --texture
namespace NC
{
	// --general
	typedef v1nil_t(NC_API_CALL* pfn_gfx_txr_new)(GLsizei count, GLuint* txr_ids);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_txr_new_mipmap)(GLenum txr_type);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_txr_del)(GLsizei count, const GLuint* txr_ids);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_txr_active)(GLenum slot);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_txr_bind)(GLenum txr_type, GLuint txr_id);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_txr_clear)(GLuint txr_id, GLint lvl, GLenum pxl_fmt, GLenum data_type, const GLvoid* params);
	/* setters */
	typedef v1nil_t(NC_API_CALL* pfn_gfx_txr_set_image_1d)(GLenum txr_type, GLint lvl, GLint int_fmt, GLsizei sz_x, GLint border, GLenum img_fmt, GLenum data_type, const GLvoid* pxl_data);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_txr_set_image_2d)(GLenum txr_type, GLint lvl, GLint int_fmt, GLsizei sz_x, GLsizei sz_y, GLint border, GLenum img_fmt, GLenum data_type, const GLvoid* pxl_data);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_txr_set_image_3d)(GLenum txr_type, GLint lvl, GLint int_fmt, GLsizei sz_x, GLsizei sz_y, GLsizei sz_z, GLint border, GLenum img_fmt, GLenum data_type, const GLvoid* pxl_data);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_txr_set_image_2d_mulsmp)(GLenum txr_type, GLsizei smp_count, GLint int_format, GLsizei sz_x, GLsizei sz_y, GLboolean fixed_smp_loc);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_txr_set_image_3d_mulsmp)(GLenum txr_type, GLsizei smp_count, GLint int_format, GLsizei sz_x, GLsizei sz_y, GLsizei sz_z, GLboolean fixed_smp_loc);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_txr_set_param_n1s)(GLenum txr_type, GLenum param_type, GLint param_val);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_txr_set_param_v1s)(GLenum txr_type, GLenum param_type, const GLint* params);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_txr_set_param_n1f)(GLenum txr_type, GLenum param_type, GLfloat param_val);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_txr_set_param_v1f)(GLenum txr_type, GLenum param_type, const GLfloat* params);
#	ifndef NC_GFX_CODES_TEXTURE
#	define NC_GFX_CODES_TEXTURE
	// --general
#	define GL_TEXTURE                        0x1702
#	define GL_TEXTURE_1D                     0x0DE0
#	define GL_PROXY_TEXTURE_1D               0x8063
#	define GL_TEXTURE_BINDING_1D             0x8068
#	define GL_TEXTURE_2D                     0x0DE1
#	define GL_TEXTURE_2D_MULTISAMPLE         0x9100
#	define GL_PROXY_TEXTURE_2D               0x8064
#	define GL_PROXY_TEXTURE_2D_MULTISAMPLE   0x9101
#	define GL_TEXTURE_BINDING_2D             0x8069
#	define GL_TEXTURE_3D                     0x806F
#	define GL_PROXY_TEXTURE_3D               0x8070
#	define GL_TEXTURE_BINDING_3D             0x806A
#	define GL_TEXTURE_2D_MULTISAMPLE_ARRAY   0x9102
#	define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#	define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#	define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#	define GL_TEXTURE_CUBE_MAP               0x8513
#	define GL_TEXTURE_BINDING_CUBE_MAP       0x8514
#	define GL_PROXY_TEXTURE_CUBE_MAP         0x851B
#	define GL_TEXTURE_CUBE_MAP_POSITIVE_X    0x8515
#	define GL_TEXTURE_CUBE_MAP_NEGATIVE_X    0x8516
#	define GL_TEXTURE_CUBE_MAP_POSITIVE_Y    0x8517
#	define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    0x8518
#	define GL_TEXTURE_CUBE_MAP_POSITIVE_Z    0x8519
#	define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    0x851A
#	define GL_TEXTURE_SAMPLES                0x9106
#	define GL_TEXTURE_1D_ARRAY               0x8C18
#	define GL_PROXY_TEXTURE_1D_ARRAY         0x8C19
#	define GL_TEXTURE_2D_ARRAY               0x8C1A
#	define GL_PROXY_TEXTURE_2D_ARRAY         0x8C1B
#	define GL_TEXTURE_BINDING_1D_ARRAY       0x8C1C
#	define GL_TEXTURE_BINDING_2D_ARRAY       0x8C1D
#	define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#	define GL_TEXTURE0                       0x84C0
#	define GL_TEXTURE1                       0x84C1
#	define GL_TEXTURE2                       0x84C2
#	define GL_TEXTURE3                       0x84C3
#	define GL_TEXTURE4                       0x84C4
#	define GL_TEXTURE5                       0x84C5
#	define GL_TEXTURE6                       0x84C6
#	define GL_TEXTURE7                       0x84C7
#	define GL_TEXTURE8                       0x84C8
#	define GL_TEXTURE9                       0x84C9
#	define GL_TEXTURE10                      0x84CA
#	define GL_TEXTURE11                      0x84CB
#	define GL_TEXTURE12                      0x84CC
#	define GL_TEXTURE13                      0x84CD
#	define GL_TEXTURE14                      0x84CE
#	define GL_TEXTURE15                      0x84CF
#	define GL_TEXTURE16                      0x84D0
#	define GL_TEXTURE17                      0x84D1
#	define GL_TEXTURE18                      0x84D2
#	define GL_TEXTURE19                      0x84D3
#	define GL_TEXTURE20                      0x84D4
#	define GL_TEXTURE21                      0x84D5
#	define GL_TEXTURE22                      0x84D6
#	define GL_TEXTURE23                      0x84D7
#	define GL_TEXTURE24                      0x84D8
#	define GL_TEXTURE25                      0x84D9
#	define GL_TEXTURE26                      0x84DA
#	define GL_TEXTURE27                      0x84DB
#	define GL_TEXTURE28                      0x84DC
#	define GL_TEXTURE29                      0x84DD
#	define GL_TEXTURE30                      0x84DE
#	define GL_TEXTURE31                      0x84DF
#	define GL_ACTIVE_TEXTURE                 0x84E0
#	define GL_MULTISAMPLE                    0x809D
	// --formats
#	define GL_RG                             0x8227
#	define GL_RG_INTEGER                     0x8228
#	define GL_RED_INTEGER                    0x8D94
#	define GL_GREEN_INTEGER                  0x8D95
#	define GL_BLUE_INTEGER                   0x8D96
#	define GL_RGB_INTEGER                    0x8D98
#	define GL_RGBA_INTEGER                   0x8D99
#	define GL_BGR_INTEGER                    0x8D9A
#	define GL_BGRA_INTEGER                   0x8D9B
#	define GL_R8                             0x8229
#	define GL_R16                            0x822A
#	define GL_RG8                            0x822B
#	define GL_RG16                           0x822C
#	define GL_R16F                           0x822D
#	define GL_R32F                           0x822E
#	define GL_RG16F                          0x822F
#	define GL_RG32F                          0x8230
#	define GL_R8I                            0x8231
#	define GL_R8UI                           0x8232
#	define GL_R16I                           0x8233
#	define GL_R16UI                          0x8234
#	define GL_R32I                           0x8235
#	define GL_R32UI                          0x8236
#	define GL_RG8I                           0x8237
#	define GL_RG8UI                          0x8238
#	define GL_RG16I                          0x8239
#	define GL_RG16UI                         0x823A
#	define GL_RG32I                          0x823B
#	define GL_RG32UI                         0x823C
#	define GL_RGBA32UI                       0x8D70
#	define GL_RGBA16UI                       0x8D76
#	define GL_RGB16UI                        0x8D77
#	define GL_RGBA8UI                        0x8D7C
#	define GL_RGB8UI                         0x8D7D
#	define GL_RGBA32I                        0x8D82
#	define GL_RGB32I                         0x8D83
#	define GL_RGBA16I                        0x8D88
#	define GL_RGB16I                         0x8D89
#	define GL_RGBA8I                         0x8D8E
#	define GL_RGB8I                          0x8D8F
#	define GL_COLOR_INDEX                    0x1900
#	define GL_STENCIL_INDEX                  0x1901
#	define GL_DEPTH_COMPONENT                0x1902
#	define GL_RED                            0x1903
#	define GL_GREEN                          0x1904
#	define GL_BLUE                           0x1905
#	define GL_ALPHA                          0x1906
#	define GL_RGB                            0x1907
#	define GL_RGBA                           0x1908
#	define GL_BGR                            0x80E0
#	define GL_BGRA                           0x80E1
#	define GL_LUMINANCE                      0x1909
#	define GL_LUMINANCE_ALPHA                0x190A
#	define GL_COMPRESSED_RGB                 0x84ED
#	define GL_COMPRESSED_RGBA                0x84EE
#	define GL_RED_SNORM                      0x8F90
#	define GL_RG_SNORM                       0x8F91
#	define GL_RGB_SNORM                      0x8F92
#	define GL_RGBA_SNORM                     0x8F93
#	define GL_R8_SNORM                       0x8F94
#	define GL_RG8_SNORM                      0x8F95
#	define GL_RGB8_SNORM                     0x8F96
#	define GL_RGBA8_SNORM                    0x8F97
#	define GL_R16_SNORM                      0x8F98
#	define GL_RG16_SNORM                     0x8F99
#	define GL_RGB16_SNORM                    0x8F9A
#	define GL_RGBA16_SNORM                   0x8F9B
	// --internal formats
#	define GL_R3_G3_B2                       0x2A10
#	define GL_RGB4                           0x804F
#	define GL_RGB5                           0x8050
#	define GL_RGB8                           0x8051
#	define GL_RGB10                          0x8052
#	define GL_RGB12                          0x8053
#	define GL_RGB16                          0x8054
#	define GL_RGBA2                          0x8055
#	define GL_RGBA4                          0x8056
#	define GL_RGB5_A1                        0x8057
#	define GL_RGBA8                          0x8058
#	define GL_RGB10_A2                       0x8059
#	define GL_RGBA12                         0x805A
#	define GL_RGBA16                         0x805B
#	define GL_UNSIGNED_BYTE_3_3_2            0x8032
#	define GL_UNSIGNED_SHORT_4_4_4_4         0x8033
#	define GL_UNSIGNED_SHORT_5_5_5_1         0x8034
#	define GL_UNSIGNED_INT_8_8_8_8           0x8035
#	define GL_UNSIGNED_INT_10_10_10_2        0x8036
	// --filters
#	define GL_NEAREST                        0x2600
#	define GL_LINEAR                         0x2601
#	define GL_NEAREST_MIPMAP_NEAREST         0x2700
#	define GL_LINEAR_MIPMAP_NEAREST          0x2701
#	define GL_NEAREST_MIPMAP_LINEAR          0x2702
#	define GL_LINEAR_MIPMAP_LINEAR           0x2703
#	define GL_TEXTURE_MAG_FILTER             0x2800
#	define GL_TEXTURE_MIN_FILTER             0x2801
	// --wraps
#	define GL_TEXTURE_WRAP_S                 0x2802
#	define GL_TEXTURE_WRAP_T                 0x2803
#	define GL_TEXTURE_WRAP_R                 0x8072
#	define GL_CLAMP_TO_BORDER                0x812D
#	define GL_CLAMP_TO_EDGE                  0x812F
#	define GL_CLAMP                          0x2900
#	define GL_REPEAT                         0x2901
	// --cubemap
#	define GL_TEXTURE_CUBE_MAP_ARRAY_ARB     0x9009
#	define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB 0x900A
#	define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB 0x900B
#	define GL_SAMPLER_CUBE_MAP_ARRAY_ARB     0x900C
#	define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB 0x900D
#	define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900E
#	define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900F
	// --samplers
#	define GL_SAMPLER                        0x82E6
#	define GL_SAMPLER_BINDING                0x8919
#	define GL_SAMPLER_2D_MULTISAMPLE         0x9108
#	define GL_INT_SAMPLER_2D_MULTISAMPLE     0x9109
#	define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#	define GL_SAMPLER_2D_MULTISAMPLE_ARRAY   0x910B
#	define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#	define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
	// --params
#	define GL_TEXTURE_WIDTH                  0x1000
#	define GL_TEXTURE_HEIGHT                 0x1001
#	define GL_TEXTURE_DEPTH                  0x8071
#	define GL_TEXTURE_INTERNAL_FORMAT        0x1003
#	define GL_TEXTURE_BORDER_COLOR           0x1004
#	define GL_TEXTURE_BORDER                 0x1005
#	define GL_MAX_COLOR_TEXTURE_SAMPLES      0x910E
#	define GL_MAX_DEPTH_TEXTURE_SAMPLES      0x910F
#	define GL_MAX_INTEGER_SAMPLES            0x9110
#	endif // NC_GFX_CODES_TEXTURE
}
// --sampler
namespace NC
{
	// --general
	typedef v1nil_t(NC_API_CALL* pfn_gfx_smp_gen) (GLsizei count, GLuint* sampler_ids);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_smp_del) (GLsizei count, const GLuint* sampler_ids);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_smp_bind) (GLuint gfx_txrunit, GLuint sampler_id);
	/* setters */
	typedef v1nil_t(NC_API_CALL* pfn_gfx_smp_set_param_n1s) (GLuint sampler_id, GLenum param_type, GLint param_val);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_smp_set_param_v1s) (GLuint sampler_id, GLenum param_type, GLint* param_vals);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_smp_set_param_n1f) (GLuint sampler_id, GLenum param_type, GLfloat param_val);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_smp_set_param_v1f) (GLuint sampler_id, GLenum param_type, GLfloat* param_vals);
#	ifndef NC_GFX_CODES_SAMPLER
#	define NC_GFX_CODES_SAMPLER
	// --general
#	define GL_SAMPLER                        0x82E6
#	define GL_SAMPLER_BINDING                0x8919
#	define GL_SAMPLER_2D_MULTISAMPLE         0x9108
#	define GL_INT_SAMPLER_2D_MULTISAMPLE     0x9109
#	define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#	define GL_SAMPLER_2D_MULTISAMPLE_ARRAY   0x910B
#	define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#	define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
	// --params
#	define GL_MAX_COLOR_TEXTURE_SAMPLES      0x910E
#	define GL_MAX_DEPTH_TEXTURE_SAMPLES      0x910F
#	define GL_MAX_INTEGER_SAMPLES            0x9110
#	endif // NC_GFX_CODES_SAMPLER
}
// --shader
namespace NC
{
	// --general
	typedef GLuint(NC_API_CALL* pfn_gfx_shd_new)         (GLenum shd_type);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_shd_del)          (GLuint shd_id);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_shd_remake)       (GLuint shd_id);
	/* getters */
	typedef v1nil_t(NC_API_CALL* pfn_gfx_shd_get_v1s)      (GLuint shd_id, GLenum param_type, GLint* param_buf);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_shd_get_info_log) (GLuint shd_id, GLsizei max_length, GLsizei* length, GLchar* info_log_buf);
	/* setters */
	typedef v1nil_t(NC_API_CALL* pfn_gfx_shd_set_source)   (GLuint shd_id, GLsizei arg_count, const GLchar* const* src_string, const GLint* src_length);
#	ifndef NC_GFX_CODES_SHADER
#	define NC_GFX_CODES_SHADER
	// general
#	define GL_SHADER                         0x82E1
#	define GL_PROGRAM                        0x82E2
#	define GL_VERTEX_SHADER                  0x8B31
#	define GL_GEOMETRY_SHADER                0x8DD9
#	define GL_COMPUTE_SHADER                 0x91B9
#	define GL_FRAGMENT_SHADER                0x8B30
#	define GL_ACTIVE_PROGRAM                 0x825
#	define GL_CURRENT_PROGRAM                0x8B8D
#	define GL_UNIFORM                        0x92E1
#	define GL_UNIFORM_BLOCK                  0x92E2
#	define GL_PROGRAM_INPUT                  0x92E3
#	define GL_PROGRAM_OUTPUT                 0x92E4
	// params
#	define GL_MAX_UNIFORM_LOCATIONS          0x826E
#	define GL_INFO_LOG_LENGTH                0x8B84
	// info
#	define GL_SHADING_LANGUAGE_VERSION       0x8B8C
#	define GL_COMPILE_STATUS                 0x8B81
#	define GL_LINK_STATUS                    0x8B82
#	endif // NC_GFX_CODES_SHADER
#	endif // NC_GFX_CODES_SHADER
}
// --material
namespace NC
{
	// --general
	typedef GLuint(NC_API_CALL* pfn_gfx_mtl_new)(GLvoid);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_del)(GLuint mtl_id);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_bind)(GLuint mtl_id);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_remake)(GLuint mtl_id);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_add_shd)(GLuint mtl_id, GLuint shd_id);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_rmv_shd)(GLuint mtl_id, GLuint shd_id);
	/* getters */
	typedef GLint(NC_API_CALL* pfn_gfx_mtl_get_loc_atb)(GLuint mtl_id, const GLchar* atb_name);
	typedef GLint(NC_API_CALL* pfn_gfx_mtl_get_loc_unf)(GLuint mtl_id, const GLchar* unf_name);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_get_iv)(GLuint shd_id, GLenum param_type, GLint* param_buf);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_get_info_log)(GLuint shd_id, GLsizei max_length, GLsizei* length, GLchar* info_log_buf);
	/* setters */
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_n1s)(GLint loc_idx, GLint val0);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_n2s)(GLint loc_idx, GLint val0, GLint val1);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_n3s)(GLint loc_idx, GLint val0, GLint val1, GLint val2);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_n4s)(GLint loc_idx, GLint val0, GLint val1, GLint val2, GLint val3);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_v1s)(GLint loc_idx, GLsizei count, const GLint* val);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_v2s)(GLint loc_idx, GLsizei count, const GLint* val);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_v3s)(GLint loc_idx, GLsizei count, const GLint* val);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_v4s)(GLint loc_idx, GLsizei count, const GLint* val);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_n1u)(GLint loc_idx, GLuint val0);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_n2u)(GLint loc_idx, GLuint val0, GLuint val1);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_n3u)(GLint loc_idx, GLuint val0, GLuint val1, GLuint val2);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_n4u)(GLint loc_idx, GLuint val0, GLuint val1, GLuint val2, GLuint val3);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_v1u)(GLint loc_idx, GLsizei count, const GLuint* val);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_v2u)(GLint loc_idx, GLsizei count, const GLuint* val);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_v3u)(GLint loc_idx, GLsizei count, const GLuint* val);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_v4u)(GLint loc_idx, GLsizei count, const GLuint* val);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_n1f)(GLint loc_idx, GLfloat val0);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_n2f)(GLint loc_idx, GLfloat val0, GLfloat val1);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_n3f)(GLint loc_idx, GLfloat val0, GLfloat val1, GLfloat val2);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_n4f)(GLint loc_idx, GLfloat val0, GLfloat val1, GLfloat val2, GLfloat val3);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_v1f)(GLint loc_idx, GLsizei count, const GLfloat* val);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_v2f)(GLint loc_idx, GLsizei count, const GLfloat* val);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_v3f)(GLint loc_idx, GLsizei count, const GLfloat* val);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_v4f)(GLint loc_idx, GLsizei count, const GLfloat* val);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_m2f)(GLint loc_idx, GLsizei coiunt, GLboolean transpose, const GLfloat* val);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_m3f)(GLint loc_idx, GLsizei count, GLboolean transpose, const GLfloat* val);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_m4f)(GLint loc_idx, GLsizei count, GLboolean transpose, const GLfloat* val);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_mtl_set_bind)(GLuint mtl_id, GLuint unf_block_idx, GLuint unf_block_binding);
#	ifndef NC_GFX_CODES_MATERIAL
#	define NC_GFX_CODES_MATERIAL
}
// --framebuffer
namespace NC
{
	// // --general
	typedef v1nil_t(NC_API_CALL* pfn_gfx_fmbuf_new)(GLsizei count, GLuint* fmbuf_ids);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_fmbuf_del)(GLsizei count, const GLuint* fmbuf_ids);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_fmbuf_bind)(GLenum fmbuf_type, GLuint fmbuf_id);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_fmbuf_bind_draw)(GLenum atch_type);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_fmbuf_bind_read)(GLenum atch_type);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_fmbuf_bind_draws)(GLsizei count, const GLuint* buf_ids);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_fmbuf_bind_reads)(GLsizei count, const GLuint* buf_ids);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_fmbuf_draw)(GLsizei size_x, GLsizei size_h, GLenum data_format, GLenum data_type, const GLvoid* pixel_buf);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_fmbuf_read)(GLint crd_x, GLint crd_y, GLsizei size_x, GLsizei size_h, GLenum data_format, GLenum data_type, GLvoid* pixel_buf);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_fmbuf_clear)(GLbitfield attachments_bitmask);
	// /* getters */
	typedef GLenum(NC_API_CALL* pfn_gfx_fmbuf_get_status)(GLenum status_type);
	// /* setters */
	typedef v1nil_t(NC_API_CALL* pfn_gfx_fmbuf_set_color)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_fmbuf_set_txr_1d)(GLenum fmbuf_type, GLenum atch_type, GLenum txr_type, GLuint txr_id, GLint level);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_fmbuf_set_txr_2d)(GLenum fmbuf_type, GLenum atch_type, GLenum txr_type, GLuint txr_id, GLint level);
	typedef v1nil_t(NC_API_CALL* pfn_gfx_fmbuf_set_txr_3d)(GLenum fmbuf_type, GLenum atch_type, GLenum txr_type, GLuint txr_id, GLint level, GLint offset_z);
#	ifndef NC_GFX_CODES_FRAMEBUFFER
#	define NC_GFX_CODES_FRAMEBUFFER
	// general
#	define GL_FRAMEBUFFER                    0x8D40
#	define GL_READ_FRAMEBUFFER               0x8CA8
#	define GL_MAX_SAMPLES                    0x8D57
#	define GL_DRAW_FRAMEBUFFER               0x8CA9
#	define GL_FRAMEBUFFER_BINDING            0x8CA6
#	define GL_DRAW_FRAMEBUFFER_BINDING       GL_FRAMEBUFFER_BINDING
#	define GL_RENDERBUFFER_BINDING           0x8CA7
#	define GL_READ_FRAMEBUFFER_BINDING       0x8CAA
#	define GL_UNSIGNED_NORMALIZED            0x8C17
#	define GL_DRAW_BUFFER                    0x0C01
#	define GL_READ_BUFFER                    0x0C02
	// pixel copy types
#	define GL_COLOR                          0x1800
#	define GL_DEPTH                          0x1801
#	define GL_STENCIL                        0x1802
	// states
#	define GL_FRAMEBUFFER_COMPLETE           0x8CD5
#	define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#	define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#	define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
	// color
#	define GL_COLOR_ATTACHMENT0              0x8CE0
#	define GL_COLOR_ATTACHMENT1              0x8CE1
#	define GL_COLOR_ATTACHMENT2              0x8CE2
#	define GL_COLOR_ATTACHMENT3              0x8CE3
#	define GL_COLOR_ATTACHMENT4              0x8CE4
#	define GL_COLOR_ATTACHMENT5              0x8CE5
#	define GL_COLOR_ATTACHMENT6              0x8CE6
#	define GL_COLOR_ATTACHMENT7              0x8CE7
#	define GL_COLOR_ATTACHMENT8              0x8CE8
#	define GL_COLOR_ATTACHMENT9              0x8CE9
#	define GL_COLOR_ATTACHMENT10             0x8CEA
#	define GL_COLOR_ATTACHMENT11             0x8CEB
#	define GL_COLOR_ATTACHMENT12             0x8CEC
#	define GL_COLOR_ATTACHMENT13             0x8CED
#	define GL_COLOR_ATTACHMENT14             0x8CEE
#	define GL_COLOR_ATTACHMENT15             0x8CEF
#	define GL_MAX_COLOR_ATTACHMENTS          0x8CDF
	// depth
#	define GL_DEPTH_RANGE                    0x0B70
#	define GL_DEPTH_TEST                     0x0B71
#	define GL_DEPTH_WRITEMASK                0x0B72
#	define GL_DEPTH_CLEAR_VALUE              0x0B73
#	define GL_DEPTH_FUNC                     0x0B74
#	define GL_ACCUM_CLEAR_VALUE              0x0B80
#	define GL_DEPTH_ATTACHMENT               0x8D00
#	define GL_DEPTH_COMPONENT16              0x81A5
#	define GL_DEPTH_COMPONENT24              0x81A6
#	define GL_DEPTH_COMPONENT32              0x81A7
	// stencil
#	define GL_STENCIL_ATTACHMENT             0x8D20
#	define GL_STENCIL_INDEX1                 0x8D46
#	define GL_STENCIL_INDEX4                 0x8D47
#	define GL_STENCIL_INDEX8                 0x8D48
#	define GL_STENCIL_INDEX16                0x8D49
#	define GL_STENCIL_TEST                   0x0B90
#	define GL_STENCIL_CLEAR_VALUE            0x0B91
#	define GL_STENCIL_FUNC                   0x0B92
#	define GL_STENCIL_VALUE_MASK             0x0B93
#	define GL_STENCIL_FAIL                   0x0B94
#	define GL_STENCIL_PASS_DEPTH_FAIL        0x0B95
#	define GL_STENCIL_PASS_DEPTH_PASS        0x0B96
#	define GL_STENCIL_REF                    0x0B97
#	define GL_STENCIL_WRITEMASK              0x0B98
	// depth and stencil
#	define GL_DEPTH_STENCIL_ATTACHMENT       0x821A
#	define GL_DEPTH_STENCIL                  0x84F9
#	define GL_DEPTH24_STENCIL8               0x88F0
#	define GL_UNSIGNED_INT_24_8              0x84FA
	// renderbuffer
#	define GL_RENDERBUFFER                   0x8D41
#	define GL_RENDERBUFFER_WIDTH             0x8D42
#	define GL_RENDERBUFFER_HEIGHT            0x8D43
#	define GL_RENDERBUFFER_INTERNAL_FORMAT   0x8D44
#	define GL_RENDERBUFFER_RED_SIZE          0x8D50
#	define GL_RENDERBUFFER_GREEN_SIZE        0x8D51
#	define GL_RENDERBUFFER_BLUE_SIZE         0x8D52
#	define GL_RENDERBUFFER_ALPHA_SIZE        0x8D53
#	define GL_RENDERBUFFER_DEPTH_SIZE        0x8D54
#	define GL_RENDERBUFFER_STENCIL_SIZE      0x8D55
#	define GL_RENDERBUFFER_SAMPLES           0x8CAB
	// bit mask
#	define GL_DEPTH_BUFFER_BIT               0x00000100
#	define GL_ACCUM_BUFFER_BIT               0x00000200
#	define GL_STENCIL_BUFFER_BIT             0x00000400
#	define GL_COLOR_BUFFER_BIT               0x00004000
	// format
#	define GL_DEPTH_COMPONENT32F             0x8CAC
#	define GL_DEPTH32F_STENCIL8              0x8CAD
#	define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
	// drawbuffers
#	define GL_MAX_DRAW_BUFFERS               0x8824
#	define GL_DRAW_BUFFER0                   0x8825
#	define GL_DRAW_BUFFER1                   0x8826
#	define GL_DRAW_BUFFER2                   0x8827
#	define GL_DRAW_BUFFER3                   0x8828
#	define GL_DRAW_BUFFER4                   0x8829
#	define GL_DRAW_BUFFER5                   0x882A
#	define GL_DRAW_BUFFER6                   0x882B
#	define GL_DRAW_BUFFER7                   0x882C
#	define GL_DRAW_BUFFER8                   0x882D
#	define GL_DRAW_BUFFER9                   0x882E
#	define GL_DRAW_BUFFER10                  0x882F
#	define GL_DRAW_BUFFER11                  0x8830
#	define GL_DRAW_BUFFER12                  0x8831
#	define GL_DRAW_BUFFER13                  0x8832
#	define GL_DRAW_BUFFER14                  0x8833
#	define GL_DRAW_BUFFER15                  0x8834
#	endif // NC_GFX_CODES_FRAMEBUFFER
}
#	ifndef NC_GFX_CODES_VALUE
#		define NC_GFX_CODES_VALUE
		// bool 8 bit
#		define NC_GFX_V1BIT GL_BOOL
#		define NC_GFX_V2BIT GL_BOOL
#		define NC_GFX_V3BIT GL_BOOL
#		define NC_GFX_V4BIT GL_BOOL
#		define NC_GFX_M2BIT GL_BOOL
#		define NC_GFX_M3BIT GL_BOOL
#		define NC_GFX_M4BIT GL_BOOL
		// signed int 8 bit
#		define NC_GFX_V1S08 GL_BYTE
#		define NC_GFX_V2S08 GL_BYTE
#		define NC_GFX_V3S08 GL_BYTE
#		define NC_GFX_V4S08 GL_BYTE
#		define NC_GFX_M2S08 GL_BYTE
#		define NC_GFX_M3S08 GL_BYTE
#		define NC_GFX_M4S08 GL_BYTE
		// signed int 16 bit
#		define NC_GFX_V1S16 GL_SHORT
#		define NC_GFX_V2S16 GL_SHORT
#		define NC_GFX_V3S16 GL_SHORT
#		define NC_GFX_V4S16 GL_SHORT
#		define NC_GFX_M2S16 GL_SHORT
#		define NC_GFX_M3S16 GL_SHORT
#		define NC_GFX_M4S16 GL_SHORT
		// signed int 32 bit
#		define NC_GFX_V1S32 GL_INT
#		define NC_GFX_V2S32 GL_INT
#		define NC_GFX_V3S32 GL_INT
#		define NC_GFX_V4S32 GL_INT
#		define NC_GFX_M2S32 GL_INT
#		define NC_GFX_M3S32 GL_INT
#		define NC_GFX_M4S32 GL_INT
		// signed int 64 bit
#		define NC_GFX_V1S64 GL_INT
#		define NC_GFX_V2S64 GL_INT
#		define NC_GFX_V3S64 GL_INT
#		define NC_GFX_V4S64 GL_INT
#		define NC_GFX_M2S64 GL_INT
#		define NC_GFX_M3S64 GL_INT
#		define NC_GFX_M4S64 GL_INT
		// unsigned int 8 bit
#		define NC_GFX_V1U08 GL_UNSIGNED_BYTE
#		define NC_GFX_V2U08 GL_UNSIGNED_BYTE
#		define NC_GFX_V3U08 GL_UNSIGNED_BYTE
#		define NC_GFX_V4U08 GL_UNSIGNED_BYTE
#		define NC_GFX_M2U08 GL_UNSIGNED_BYTE
#		define NC_GFX_M3U08 GL_UNSIGNED_BYTE
#		define NC_GFX_M4U08 GL_UNSIGNED_BYTE
		// unsigned int 16 bit
#		define NC_GFX_V1U16 GL_UNSIGNED_SHORT
#		define NC_GFX_V2U16 GL_UNSIGNED_SHORT
#		define NC_GFX_V3U16 GL_UNSIGNED_SHORT
#		define NC_GFX_V4U16 GL_UNSIGNED_SHORT
#		define NC_GFX_M2U16 GL_UNSIGNED_SHORT
#		define NC_GFX_M3U16 GL_UNSIGNED_SHORT
#		define NC_GFX_M4U16 GL_UNSIGNED_SHORT
		// unsigned int 32 bit
#		define NC_GFX_V1U32 GL_UNSIGNED_INT
#		define NC_GFX_V2U32 GL_UNSIGNED_INT
#		define NC_GFX_V3U32 GL_UNSIGNED_INT
#		define NC_GFX_V4U32 GL_UNSIGNED_INT
#		define NC_GFX_M2U32 GL_UNSIGNED_INT
#		define NC_GFX_M3U32 GL_UNSIGNED_INT
#		define NC_GFX_M4U32 GL_UNSIGNED_INT
		// unsigned int 64 bit
#		define NC_GFX_V1U64 GL_UNSIGNED_INT
#		define NC_GFX_V2U64 GL_UNSIGNED_INT
#		define NC_GFX_V3U64 GL_UNSIGNED_INT
#		define NC_GFX_V4U64 GL_UNSIGNED_INT
#		define NC_GFX_M2U64 GL_UNSIGNED_INT
#		define NC_GFX_M3U64 GL_UNSIGNED_INT
#		define NC_GFX_M4U64 GL_UNSIGNED_INT
		// float 32 bit
#		define NC_GFX_V1F32 GL_FLOAT
#		define NC_GFX_V2F32 GL_FLOAT
#		define NC_GFX_V3F32 GL_FLOAT
#		define NC_GFX_V4F32 GL_FLOAT
#		define NC_GFX_M2F32 GL_FLOAT
#		define NC_GFX_M3F32 GL_FLOAT
#		define NC_GFX_M4F32 GL_FLOAT
		// float 64 bit
#		define NC_GFX_V1F64 GL_FLOAT
#		define NC_GFX_V2F64 GL_FLOAT
#		define NC_GFX_V3F64 GL_FLOAT
#		define NC_GFX_V4F64 GL_FLOAT
#		define NC_GFX_M2F64 GL_FLOAT
#		define NC_GFX_M3F64 GL_FLOAT
#		define NC_GFX_M4F64 GL_FLOAT
#	endif	// NC_GFX_CODES_VALUE
#	ifndef NC_GFX_CODES
#		define NC_GFX_CODES
		// faces sides directions
#		define NC_GFX_FACE_LFT     GL_LEFT
#		define NC_GFX_FACE_RHT     GL_RIGHT
#		define NC_GFX_FACE_LFT_RHT 0x0001 // none
#		define NC_GFX_FACE_BOT     0x0003 // none
#		define NC_GFX_FACE_TOP     0x0002 // none
#		define NC_GFX_FACE_BOT_TOP 0x0004 // none
#		define NC_GFX_FACE_BCK     GL_BACK
#		define NC_GFX_FACE_FRT     GL_FRONT
#		define NC_GFX_FACE_BCK_FRT GL_FRONT_AND_BACK 
#		define NC_GFX_FACE_BCK_LFT GL_BACK_LEFT
#		define NC_GFX_FACE_BCK_RHT GL_BACK_RIGHT
#		define NC_GFX_FACE_FRT_LFT GL_FRONT_LEFT
#		define NC_GFX_FACE_FRT_RHT GL_FRONT_RIGHT
		// operators
#		define NC_GFX_LOGIC_ALWAYS  GL_ALWAYS
#		define NC_GFX_LOGIC_NEVER   GL_NEVER
#		define NC_GFX_LOGIC_GREATER GL_GREATER
#		define NC_GFX_LOGIC_LESSER  GL_LESS
#		define NC_GFX_LOGIC_EQUAL   GL_EQUAL
#		define NC_GFX_LOGIC_NEQUAL  GL_NOTEQUAL
#		define NC_GFX_LOGIC_GEQUAL  GL_GEQUAL
#		define NC_GFX_LOGIC_LEQUAL  GL_LEQUAL
#		define NC_GFX_LOGIC_AND     GL_AND
#		define NC_GFX_LOGIC_AND_REV GL_AND_REVERSE
#		define NC_GFX_LOGIC_AND_INV GL_AND_INVERTED
#		define NC_GFX_LOGIC_OR      GL_OR
#		define NC_GFX_LOGIC_OR_NOT  GL_NOR 
#		define NC_GFX_LOGIC_OR_EXC  GL_XOR
#		define NC_GFX_LOGIC_NO_OPER GL_NOOP
		// stencil testing
#		define NC_GFX_STENCIL_DECR GL_DECR
#		define NC_GFX_STENCIL_INCR GL_INCR
#		define NC_GFX_STENCIL_KEEP GL_KEEP
#		define NC_GFX_STENCIL_ZERO GL_ZERO
#		define NC_GFX_STENCIL_REPL GL_REPLACE
#		define NC_GFX_STENCIL_INVT GL_INVERT
		// color blending
#		define NC_GFX_BLEND_SRC_ALPHA           GL_SRC_ALPHA
#		define NC_GFX_BLEND_DST_ALPHA           GL_DST_ALPHA
#		define NC_GFX_BLEND_SRC_COLOR           GL_SRC_COLOR
#		define NC_GFX_BLEND_DST_COLOR           GL_DST_COLOR
#		define NC_GFX_BLEND_ONE_MINUS_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
#		define NC_GFX_BLEND_ONE_MUNUS_DST_ALPHA GL_ONE_MUNUS_DST_ALPHA 
#		define NC_GFX_BLEND_ONE_MINUS_SRC_COLOR GL_ONE_MINUS_SRC_COLOR
#		define NC_GFX_BLEND_ONE_MINUS_DST_COLOR GL_ONE_MINUS_DST_COLOR
		// face culling
#		define NC_GFX_CULL_CW  GL_CW
#		define NC_GFX_CULL_CCW GL_CCW
		// geometry filling
#		define NC_GFX_FILL_LINE   GL_LINE
#		define NC_GFX_FILL_FACE   GL_FILL
		// primitives
#		define NC_GFX_PRIM_POINTS         GL_POINTS
#		define NC_GFX_PRIM_LINES          GL_LINES
#		define NC_GFX_PRIM_LINE_LOOP      GL_LINE_LOOP
#		define NC_GFX_PRIM_LINE_STRIP     GL_LINE_STRIP
#		define NC_GFX_PRIM_TRIANGLES      GL_TRIANGLES
#		define NC_GFX_PRIM_TRIANGLE_STRIP GL_TRIANGLE_STRIP
#		define NC_GFX_PRIM_TRIANGLE_FAN   GL_TRIANGLE_FAN
		// texture wraps
#		define NC_GFX_WRAP_REPEAT  GL_REPEAT
#		define NC_GFX_WRAP_CLAMP   GL_CLAMP_TO_EDGE
#		define NC_GFX_WRAP_BORDER  GL_CLAMP_TO_BORDER
		// texture filters
#		define NC_GFX_FILTER_LINEAR  GL_LINEAR
#		define NC_GFX_FILTER_NEAREST GL_NEAREST
		// base formats
#		define NC_GFX_FORMAT_RED   GL_RED
#		define NC_GFX_FORMAT_RG	   GL_RG
#		define NC_GFX_FORMAT_RGB   GL_RGB
#		define NC_GFX_FORMAT_RGBA  GL_RGBA
#		define NC_GFX_FORMAT_DEPT  GL_DEPTH_COMPONENT
#		define NC_GFX_FORMAT_STEN  GL_STENCIL_INDEX
#		define NC_GFX_FORMAT_DPST  GL_DEPTH_STENCIL
		// pixel formats
#		define NC_GFX_FORMAT_R8_S8        GL_R8I
#		define NC_GFX_FORMAT_R8_U8        GL_R8UI
#		define NC_GFX_FORMAT_R16_S16      GL_R16I
#		define NC_GFX_FORMAT_R16_U16      GL_R16UI
#		define NC_GFX_FORMAT_R32_S32      GL_R32I
#		define NC_GFX_FORMAT_R8G8_U16     GL_RG8UI
#		define NC_GFX_FORMAT_R8G8_S16     GL_RG8I
#		define NC_GFX_FORMAT_R16G16_S32   GL_RG16I
#		define NC_GFX_FORMAT_R8G8B8_S32   GL_RGB8I
#		define NC_GFX_FORMAT_R8G8B8A8_S32 GL_RGBA8I
#		define NC_GFX_FORMAT_R32_U32      GL_R32UI
#		define NC_GFX_FORMAT_R16G16_U32   GL_RG16UI
#		define NC_GFX_FORMAT_R8G8B8_U32   GL_RGB8UI
#		define NC_GFX_FORMAT_R8G8B8A8_U32 GL_RGBA8UI
#		define NC_GFX_FORMAT_S8_S8        GL_R8I
#		define NC_GFX_FORMAT_D32_S32      GL_DEPTH_COMPONENT
#		define NC_GFX_FORMAT_D32_U32      GL_DEPTH_COMPONENT
#		define NC_GFX_FORMAT_S8_U8        GL_STENCIL_INDEX
#		define NC_GFX_FORMAT_D24S8_S32    GL_DEPTH_STENCIL
#		define NC_GFX_FORMAT_D24S8_U32    GL_DEPTH_STENCIL
#	endif // NC_GFX_CODES
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
#		include "dxgi.hxx"
#		include "d3d11.hxx"
// by using D3DCompile() from <d3dcompiler.hxx" / d3dcompiler.lib, we introduce a dependency to a given version of d3dcompiler_XX.dll (see D3DCOMPILER_DLL_A)
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
namespace NC
{
	typedef HRESULT(NC_API_CALL* pfn_d3d_new_device_context)
		(_In_opt_ IDXGIAdapter*,
		D3D_DRIVER_TYPE, HMODULE, UINT,
		_In_reads_opt_(FeatureLevels) CONST D3D_FEATURE_LEVEL*,
		UINT FeatureLevels, UINT, _COM_Outptr_opt_ ID3D11Device**,
		_Out_opt_ D3D_FEATURE_LEVEL*, _COM_Outptr_opt_ ID3D11DeviceContext**);
	typedef HRESULT(NC_API_CALL* pfn_d3d_new_device_context_swapchain)
		(_In_opt_ IDXGIAdapter*,
		D3D_DRIVER_TYPE, HMODULE, UINT,
		_In_reads_opt_(FeatureLevels) CONST D3D_FEATURE_LEVEL*,
		UINT FeatureLevels, UINT, _In_opt_ CONST DXGI_SWAP_CHAIN_DESC*,
		_COM_Outptr_opt_ IDXGISwapChain**, _COM_Outptr_opt_ ID3D11Device**,
		_Out_opt_ D3D_FEATURE_LEVEL*, _COM_Outptr_opt_ ID3D11DeviceContext**);
	typedef HRESULT(NC_API_CALL* pfn_gfx_shd_remake)
		(_In_reads_bytes_(SrcDataSize) LPCVOID pSrcData,
			_In_ SIZE_T SrcDataSize,
			_In_opt_ LPCSTR pSourceName,
			_In_reads_opt_(_Inexpressible_(pDefines->Name != NULL)) CONST D3D_SHADER_MACRO* pDefines,
			_In_opt_ ID3DInclude* pInclude,
			_In_opt_ LPCSTR pEntrypoint,
			_In_ LPCSTR pTarget,
			_In_ UINT Flags1,
			_In_ UINT Flags2,
			_Out_ ID3DBlob** ppCode,
			_Always_(_Outptr_opt_result_maybenull_) ID3DBlob** ppErrorMsgs);
}
namespace NC
{
	extern pfn_d3d_new_device_context           gfx_new_device_context;
	extern pfn_d3d_new_device_context_swapchain gfx_new_device_context_swapchain;
	extern pfn_gfx_shd_remake                   gfx_shd_remake;
}
#		define D3D11CreateDevice             gfx_new_device_context
#		define D3D11CreateDeviceAndSwapChain gfx_new_device_context_swapchain
#		define D3DCompile                    gfx_shd_remake
#	endif	// GAPI_D3D
#endif	// NC_GAPI
#endif	// NC_GFX_LIB_CORE_H