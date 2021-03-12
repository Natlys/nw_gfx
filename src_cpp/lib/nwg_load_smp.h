#ifndef NW_LOAD_SMP_H
#define NW_LOAD_SMP_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include "nwg_load_base.h"
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	extern bit ogl_load_smp();
}
namespace NW
{
	// general
	typedef void (APIENTRYP pfn_ogl_smp_gen) (GLsizei count, GLuint* sampler_ids);
	typedef void (APIENTRYP pfn_ogl_smp_del) (GLsizei count, const GLuint* sampler_ids);
	typedef void (APIENTRYP pfn_ogl_smp_bind) (GLuint txr_unit, GLuint sampler_id);
	// params
	typedef void (APIENTRYP pfn_ogl_smp_param_i) (GLuint sampler_id, GLenum param_type, GLint param_val);
	typedef void (APIENTRYP pfn_ogl_smp_param_iv) (GLuint sampler_id, GLenum param_type, GLint* param_vals);
	typedef void (APIENTRYP pfn_ogl_smp_param_f) (GLuint sampler_id, GLenum param_type, GLfloat param_val);
	typedef void (APIENTRYP pfn_ogl_smp_param_fv) (GLuint sampler_id, GLenum param_type, GLfloat* param_vals);
	// params
}
namespace NW
{
	// general
	extern pfn_ogl_smp_gen ogl_smp_gen;
	extern pfn_ogl_smp_del ogl_smp_del;
	extern pfn_ogl_smp_bind ogl_smp_bind;
	// params
	extern pfn_ogl_smp_param_i ogl_smp_param_i;
	extern pfn_ogl_smp_param_iv ogl_smp_param_iv;
	extern pfn_ogl_smp_param_f ogl_smp_param_f;
	extern pfn_ogl_smp_param_fv ogl_smp_param_fv;
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
#ifndef __gl_h__
// general
#define GL_SAMPLER                        0x82E6
#define GL_SAMPLER_BINDING                0x8919
#define GL_SAMPLER_2D_MULTISAMPLE         0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE     0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY   0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
// params
#define GL_MAX_COLOR_TEXTURE_SAMPLES      0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES      0x910F
#define GL_MAX_INTEGER_SAMPLES            0x9110
#endif	// __gl_h__
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
}
#endif
#endif	// NW_GAPI
#endif	// NW_LOAD_SMP_H