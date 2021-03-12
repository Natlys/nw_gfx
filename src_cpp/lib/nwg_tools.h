#ifndef NW_GFX_TOOLS_H
#define NW_GFX_TOOLS_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <lib/nwg_switch.h>
namespace NW
{
	struct NW_API gfx_context_info : public a_info
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
namespace NW
{
	struct NW_API gfx_config
	{
		gfx_primitives prim_type = GPT_DEFAULT;
		si32 swap_interval = 1u;
		v4si viewport = { 0, 0, 800, 600 };
		v4f clear_color = { 0.3f, 0.5f, 0.7f, 1.0f };
	};
}
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	extern NW_API void ogl_clear_err();
	extern NW_API bit ogl_get_err_log(cstring* info, cstring location, si32 line);
	extern NW_API bit ogl_get_err_log(shader_types shd_type, si32 shd_id);
}
	#if (defined NW_DEBUG)
			#define NW_DEBUG_CALL(code) ( ogl_clear_err(); code		\
			if (ogl_get_err_log(#code, __FILE__, __LINE__, "GL_ERROR: ") == false) { NW_BREAK(); } )
	#else
		#define NW_DEBUG_CALL(code) (code)
	#endif
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	extern NW_API void dx_clear_err();
	extern NW_API bool dx_err_log(cstring comment, cstring file, si32 line);
}
#	if (defined NW_DEBUG)
		#define NW_DEBUG_CALL(code) ( dx_clear_err(); (code) NW_ASSERT(DxErrLog(##code, __FILE__, __LINE__, "GL_ERROR: "))
#	else
		#define NW_DEBUG_CALL(code) (code)
#	endif
#endif

#endif	// NW_GAPI
#endif	// NW_GFX_TOOLS_H