#ifndef NW_GFX_LIB_SAMPLER_H
#define NW_GFX_LIB_SAMPLER_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#include "nw_gfx_lib_core.h"
namespace NW
{
	extern v1bit gfx_load_smp();
}
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	// general
	typedef v1nil(NW_API_ENTRYP pfn_gfx_smp_gen) (GLsizei count, GLuint* sampler_ids);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_smp_del) (GLsizei count, const GLuint* sampler_ids);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_smp_bind) (GLuint gfx_txrunit, GLuint sampler_id);
	// params
	typedef v1nil(NW_API_ENTRYP pfn_gfx_smp_param_i) (GLuint sampler_id, GLenum param_type, GLint param_val);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_smp_param_iv) (GLuint sampler_id, GLenum param_type, GLint* param_vals);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_smp_param_f) (GLuint sampler_id, GLenum param_type, GLfloat param_val);
	typedef v1nil(NW_API_ENTRYP pfn_gfx_smp_param_fv) (GLuint sampler_id, GLenum param_type, GLfloat* param_vals);
	// params
}
namespace NW
{
	// general
	extern pfn_gfx_smp_gen ogl_smp_gen;
	extern pfn_gfx_smp_del ogl_smp_del;
	extern pfn_gfx_smp_bind ogl_smp_bind;
	// params
	extern pfn_gfx_smp_param_i ogl_smp_param_i;
	extern pfn_gfx_smp_param_iv ogl_smp_param_iv;
	extern pfn_gfx_smp_param_f ogl_smp_param_f;
	extern pfn_gfx_smp_param_fv ogl_smp_param_fv;
}
// general
#define glGenSamplers ogl_smp_gen
#define glDeleteSamplers ogl_smp_del
#define glBindSampler ogl_smp_bind
// params
#define glSamplerParameteri ogl_smp_param_i
#define glSamplerParameteriv ogl_smp_param_iv
#define glSamplerParameterf ogl_smp_param_f
#define glSamplerParameterfv ogl_smp_param_fv
#	ifndef __gl_h__
		// general
#		define GL_SAMPLER                        0x82E6
#		define GL_SAMPLER_BINDING                0x8919
#		define GL_SAMPLER_2D_MULTISAMPLE         0x9108
#		define GL_INT_SAMPLER_2D_MULTISAMPLE     0x9109
#		define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#		define GL_SAMPLER_2D_MULTISAMPLE_ARRAY   0x910B
#		define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#		define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
		// params
#		define GL_MAX_COLOR_TEXTURE_SAMPLES      0x910E
#		define GL_MAX_DEPTH_TEXTURE_SAMPLES      0x910F
#		define GL_MAX_INTEGER_SAMPLES            0x9110
#		endif	// __gl_h__
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
struct ID3D11SamplerState;
namespace NW
{
}
#	endif	// GAPI_D3D
#endif	// NW_GAPI
#endif	// NW_GFX_LIB_SMP_H