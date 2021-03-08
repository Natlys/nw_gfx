#ifndef NWG_LOAD_SMP_H
#define NWG_LOAD_SMP_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include "nwg_load_base.h"
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	extern bit ogl_load_smp();
}
namespace NWG
{
	// general
	typedef void (APIENTRYP pfn_ogl_smp_gen) (GLsizei count, GLuint* sampler_ids);
	typedef void (APIENTRYP pfn_ogl_smp_del) (GLsizei count, const GLuint* sampler_ids);
	typedef void (APIENTRYP pfn_ogl_smp_bind) (GLuint txr_unit, GLuint sampler_id);
	// params
}
namespace NWG
{
	// general
	extern pfn_ogl_smp_gen ogl_smp_gen;
	extern pfn_ogl_smp_del ogl_smp_del;
	extern pfn_ogl_smp_bind ogl_smp_bind;
	// params
}
// general
#define glGenSamplers ogl_smp_gen
#define glDeleteSamplers ogl_smp_del
#define glBindSampler ogl_smp_bind
// params
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
#if (NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
}
#endif
#endif	// NWG_GAPI
#endif	// NWG_LOAD_SMP_H