#ifndef NWG_LOAD_TXR_H
#define NWG_LOAD_TXR_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include "nwg_load_base.h"
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	extern bit ogl_load_txr();
}
namespace NWG
{
	// general
	typedef void (APIENTRYP pfn_ogl_txr_gen)(GLsizei count, GLuint* txr_ids);
	typedef void (APIENTRYP pfn_ogl_txr_del)(GLsizei count, const GLuint* txr_ids);
	typedef void (APIENTRYP pfn_ogl_txr_bind)(GLenum txr_type, GLuint txr_id);
	typedef void (APIENTRYP pfn_ogl_txr_active)(GLenum txr_slot);
	typedef void (APIENTRYP pfn_ogl_txr_mipmap_gen)(GLenum txr_type);
	typedef void (APIENTRYP pfn_ogl_txr_img_1d)(GLenum txr_type, GLint lvl, GLint int_fmt, GLsizei sz_x, GLint border, GLenum img_fmt, GLenum data_type, const GLvoid* pxl_data);
	typedef void (APIENTRYP pfn_ogl_txr_img_2d)(GLenum txr_type, GLint lvl, GLint int_fmt, GLsizei sz_x, GLsizei sz_y, GLint border, GLenum img_fmt, GLenum data_type, const GLvoid* pxl_data);
	typedef void (APIENTRYP pfn_ogl_txr_img_3d)(GLenum txr_type, GLint lvl, GLint int_fmt, GLsizei sz_x, GLsizei sz_y, GLsizei sz_z, GLint border, GLenum img_fmt, GLenum data_type, const GLvoid* pxl_data);
	typedef void (APIENTRYP pfn_ogl_txr_img_2d_mulsmp)(GLenum txr_type, GLsizei smp_count, GLint int_format, GLsizei sz_x, GLsizei sz_y, GLboolean fixed_smp_loc);
	typedef void (APIENTRYP pfn_ogl_txr_img_3d_mulsmp)(GLenum txr_type, GLsizei smp_count, GLint int_format, GLsizei sz_x, GLsizei sz_y, GLsizei sz_z, GLboolean fixed_smp_loc);
	// params
	typedef void (APIENTRYP pfn_ogl_txr_param_i)(GLenum txr_type, GLenum param_type, GLint param_val);
	typedef void (APIENTRYP pfn_ogl_txr_param_vi)(GLenum txr_type, GLenum param_type, const GLint* params);
	typedef void (APIENTRYP pfn_ogl_txr_param_f)(GLenum txr_type, GLenum param_type, GLfloat param_val);
	typedef void (APIENTRYP pfn_ogl_txr_param_vf)(GLenum txr_type, GLenum param_type, const GLfloat* params);
	// other
	typedef void (APIENTRYP pfn_ogl_txr_img_clear)(GLuint txr_id, GLint lvl, GLenum pxl_fmt, GLenum data_type, const GLvoid* params);
}
namespace NWG
{
	// general
	extern pfn_ogl_txr_gen ogl_txr_gen;
	extern pfn_ogl_txr_del ogl_txr_del;
	extern pfn_ogl_txr_bind ogl_txr_bind;
	extern pfn_ogl_txr_active ogl_txr_active;
	extern pfn_ogl_txr_mipmap_gen ogl_txr_mipmap_gen;
	extern pfn_ogl_txr_img_1d ogl_txr_img_1d;
	extern pfn_ogl_txr_img_2d ogl_txr_img_2d;
	extern pfn_ogl_txr_img_3d ogl_txr_img_3d;
	extern pfn_ogl_txr_img_2d_mulsmp ogl_txr_img_2d_mulsmp;
	extern pfn_ogl_txr_img_3d_mulsmp ogl_txr_img_3d_mulsmp;
	// params
	extern pfn_ogl_txr_param_i ogl_txr_param_i;
	extern pfn_ogl_txr_param_vi ogl_txr_param_vi;
	extern pfn_ogl_txr_param_f ogl_txr_param_f;
	extern pfn_ogl_txr_param_vf ogl_txr_param_vf;
	// other
	extern pfn_ogl_txr_img_clear ogl_txr_img_clear;
}
// general
#define glGenTextures ogl_txr_gen
#define glDeleteTextures ogl_txr_del
#define glBindTexture ogl_txr_bind
#define glActiveTexture ogl_txr_active
#define glGenerateMipmap ogl_txr_mipmap_gen
#define glTexImage1D ogl_txr_img_1d
#define glTexImage2D ogl_txr_img_2d
#define glTexImage3D ogl_txr_img_3d
#define glTexImage2DMultisample ogl_txr_img_2d_mulsmp
#define glTexImage3DMultisample ogl_txr_img_3d_mulsmp
// params
#define glTexParameteri ogl_txr_param_i
#define glTexParameteriv ogl_txr_param_vi
#define glTexParameterf ogl_txr_param_f
#define glTexParameterfv ogl_txr_param_vf
// other
#define glClearTexImage ogl_txr_img_clear


#ifndef __gl_h__
// general
#define GL_TEXTURE                        0x1702
#define GL_TEXTURE_1D                     0x0DE0
#define GL_PROXY_TEXTURE_1D               0x8063
#define GL_TEXTURE_BINDING_1D             0x8068
#define GL_TEXTURE_2D                     0x0DE1
#define GL_TEXTURE_2D_MULTISAMPLE         0x9100
#define GL_PROXY_TEXTURE_2D               0x8064
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE   0x9101
#define GL_TEXTURE_BINDING_2D             0x8069
#define GL_TEXTURE_3D                     0x806F
#define GL_PROXY_TEXTURE_3D               0x8070
#define GL_TEXTURE_BINDING_3D             0x806A
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY   0x9102
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_SAMPLES                0x9106
#define GL_TEXTURE_1D_ARRAY               0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY         0x8C19
#define GL_TEXTURE_2D_ARRAY               0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY         0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY       0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY       0x8C1D
#define GL_TEXTURE0                       0x84C0
#define GL_TEXTURE1                       0x84C1
#define GL_TEXTURE2                       0x84C2
#define GL_TEXTURE3                       0x84C3
#define GL_TEXTURE4                       0x84C4
#define GL_TEXTURE5                       0x84C5
#define GL_TEXTURE6                       0x84C6
#define GL_TEXTURE7                       0x84C7
#define GL_TEXTURE8                       0x84C8
#define GL_TEXTURE9                       0x84C9
#define GL_TEXTURE10                      0x84CA
#define GL_TEXTURE11                      0x84CB
#define GL_TEXTURE12                      0x84CC
#define GL_TEXTURE13                      0x84CD
#define GL_TEXTURE14                      0x84CE
#define GL_TEXTURE15                      0x84CF
#define GL_TEXTURE16                      0x84D0
#define GL_TEXTURE17                      0x84D1
#define GL_TEXTURE18                      0x84D2
#define GL_TEXTURE19                      0x84D3
#define GL_TEXTURE20                      0x84D4
#define GL_TEXTURE21                      0x84D5
#define GL_TEXTURE22                      0x84D6
#define GL_TEXTURE23                      0x84D7
#define GL_TEXTURE24                      0x84D8
#define GL_TEXTURE25                      0x84D9
#define GL_TEXTURE26                      0x84DA
#define GL_TEXTURE27                      0x84DB
#define GL_TEXTURE28                      0x84DC
#define GL_TEXTURE29                      0x84DD
#define GL_TEXTURE30                      0x84DE
#define GL_TEXTURE31                      0x84DF
#define GL_ACTIVE_TEXTURE                 0x84E0
#define GL_MULTISAMPLE                    0x809D
// formats
#define GL_RG                             0x8227
#define GL_RG_INTEGER                     0x8228
#define GL_RED_INTEGER                    0x8D94
#define GL_GREEN_INTEGER                  0x8D95
#define GL_BLUE_INTEGER                   0x8D96
#define GL_RGB_INTEGER                    0x8D98
#define GL_RGBA_INTEGER                   0x8D99
#define GL_BGR_INTEGER                    0x8D9A
#define GL_BGRA_INTEGER                   0x8D9B
#define GL_R8                             0x8229
#define GL_R16                            0x822A
#define GL_RG8                            0x822B
#define GL_RG16                           0x822C
#define GL_R16F                           0x822D
#define GL_R32F                           0x822E
#define GL_RG16F                          0x822F
#define GL_RG32F                          0x8230
#define GL_R8I                            0x8231
#define GL_R8UI                           0x8232
#define GL_R16I                           0x8233
#define GL_R16UI                          0x8234
#define GL_R32I                           0x8235
#define GL_R32UI                          0x8236
#define GL_RG8I                           0x8237
#define GL_RG8UI                          0x8238
#define GL_RG16I                          0x8239
#define GL_RG16UI                         0x823A
#define GL_RG32I                          0x823B
#define GL_RG32UI                         0x823C
#define GL_RGBA32UI                       0x8D70
#define GL_RGBA16UI                       0x8D76
#define GL_RGB16UI                        0x8D77
#define GL_RGBA8UI                        0x8D7C
#define GL_RGB8UI                         0x8D7D
#define GL_RGBA32I                        0x8D82
#define GL_RGB32I                         0x8D83
#define GL_RGBA16I                        0x8D88
#define GL_RGB16I                         0x8D89
#define GL_RGBA8I                         0x8D8E
#define GL_RGB8I                          0x8D8F
#define GL_COLOR_INDEX                    0x1900
#define GL_STENCIL_INDEX                  0x1901
#define GL_DEPTH_COMPONENT                0x1902
#define GL_RED                            0x1903
#define GL_GREEN                          0x1904
#define GL_BLUE                           0x1905
#define GL_ALPHA                          0x1906
#define GL_RGB                            0x1907
#define GL_RGBA                           0x1908
#define GL_BGR                            0x80E0
#define GL_BGRA                           0x80E1
#define GL_LUMINANCE                      0x1909
#define GL_LUMINANCE_ALPHA                0x190A
#define GL_COMPRESSED_RGB                 0x84ED
#define GL_COMPRESSED_RGBA                0x84EE
#define GL_RED_SNORM                      0x8F90
#define GL_RG_SNORM                       0x8F91
#define GL_RGB_SNORM                      0x8F92
#define GL_RGBA_SNORM                     0x8F93
#define GL_R8_SNORM                       0x8F94
#define GL_RG8_SNORM                      0x8F95
#define GL_RGB8_SNORM                     0x8F96
#define GL_RGBA8_SNORM                    0x8F97
#define GL_R16_SNORM                      0x8F98
#define GL_RG16_SNORM                     0x8F99
#define GL_RGB16_SNORM                    0x8F9A
#define GL_RGBA16_SNORM                   0x8F9B
// internal formats
#define GL_R3_G3_B2                       0x2A10
#define GL_RGB4                           0x804F
#define GL_RGB5                           0x8050
#define GL_RGB8                           0x8051
#define GL_RGB10                          0x8052
#define GL_RGB12                          0x8053
#define GL_RGB16                          0x8054
#define GL_RGBA2                          0x8055
#define GL_RGBA4                          0x8056
#define GL_RGB5_A1                        0x8057
#define GL_RGBA8                          0x8058
#define GL_RGB10_A2                       0x8059
#define GL_RGBA12                         0x805A
#define GL_RGBA16                         0x805B
#define GL_UNSIGNED_BYTE_3_3_2            0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4         0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1         0x8034
#define GL_UNSIGNED_INT_8_8_8_8           0x8035
#define GL_UNSIGNED_INT_10_10_10_2        0x8036
// filters
#define GL_NEAREST                        0x2600
#define GL_LINEAR                         0x2601
#define GL_NEAREST_MIPMAP_NEAREST         0x2700
#define GL_LINEAR_MIPMAP_NEAREST          0x2701
#define GL_NEAREST_MIPMAP_LINEAR          0x2702
#define GL_LINEAR_MIPMAP_LINEAR           0x2703
#define GL_TEXTURE_MAG_FILTER             0x2800
#define GL_TEXTURE_MIN_FILTER             0x2801
// wraps
#define GL_TEXTURE_WRAP_S                 0x2802
#define GL_TEXTURE_WRAP_T                 0x2803
#define GL_TEXTURE_WRAP_R                 0x8072
#define GL_CLAMP_TO_BORDER                0x812D
#define GL_CLAMP                          0x2900
#define GL_REPEAT                         0x2901
// cubemap
#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB     0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB     0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900F
// samplers
#define GL_SAMPLER                        0x82E6
#define GL_SAMPLER_BINDING                0x8919
#define GL_SAMPLER_2D_MULTISAMPLE         0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE     0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY   0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
// params
#define GL_TEXTURE_WIDTH                  0x1000
#define GL_TEXTURE_HEIGHT                 0x1001
#define GL_TEXTURE_DEPTH                  0x8071
#define GL_TEXTURE_INTERNAL_FORMAT        0x1003
#define GL_TEXTURE_BORDER_COLOR           0x1004
#define GL_TEXTURE_BORDER                 0x1005
#define GL_MAX_COLOR_TEXTURE_SAMPLES      0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES      0x910F
#define GL_MAX_INTEGER_SAMPLES            0x9110
#endif	// __gl_h__
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
}
#endif
#endif	// NWG_GAPI
#endif	// NWG_LOAD_TXR_H