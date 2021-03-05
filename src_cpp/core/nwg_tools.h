#ifndef NWG_TOOLS_H
#define NWG_TOOLS_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <core/nwg_switch.h>
namespace NWG
{
	struct NWG_API gfx_context_info : public a_info
	{
	public:
		sbyte renderer[256], version[256], vendor[256], shader_language[256];
		si32 max_vtx_attribs = 0;
		si32 max_textures = 0;
	public:
		gfx_context_info(cstring str_renderer = "default", cstring str_version = "default",
			cstring str_vendor = "default", cstring str_shader_lang = "default");
		// --operators
		virtual out_stream& operator<<(out_stream& stm) const override;
		virtual in_stream& operator>>(in_stream& stm) override;
	};
}
namespace NWG
{
	struct NWG_API gfx_config
	{
		gfx_primitives prim_type = GPT_DEFAULT;
		si32 swap_interval = 1u;
		v4si32 viewport = { 0, 0, 800, 600 };
		v4f32 clear_color = { 0.3f, 0.5f, 0.7f, 1.0f };
	};
}

#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	void ogl_clear_err();
	bool ogl_get_err_log(const char* stinfo, const char* strFile, int nLine);
	int ogl_get_err_log(shader_types ShaderType, si32 unShaderId);
}
	#if (defined NWG_DEBUG)
			#define NWG_DEBUG_CALL(code) ( ogl_clear_err(); code		\
			if (ogl_get_err_log(#code, __FILE__, __LINE__, "GL_ERROR: ") == false) { NWL_BREAK(); } )
	#else
		#define NWG_DEBUG_CALL(code) (code)
	#endif
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
	void dx_clear_err();
	bool dx_err_log(cstring comment, cstring file, si32 line);
}
#	if (defined NWG_DEBUG)
		#define NWG_DEBUG_CALL(code) ( dx_clear_err(); (code) NWL_ASSERT(DxErrLog(##code, __FILE__, __LINE__, "GL_ERROR: "))
#	else
		#define NWG_DEBUG_CALL(code) (code)
#	endif
#endif

#endif	// NWG_GAPI
#endif	// NWG_TOOLS_H