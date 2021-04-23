#ifndef NW_GFX_LIB_SHADER_H
#define NW_GFX_LIB_SHADER_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#include "nw_gfx_lib_core.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	// general
	typedef GLuint    (NW_API_ENTRYP pfn_gfx_shd_crt)          (GLenum shd_type);
	typedef v1nil     (NW_API_ENTRYP pfn_gfx_shd_del)          (GLuint shd_id);
	typedef v1nil     (NW_API_ENTRYP pfn_gfx_shd_compile)      (GLuint shd_id);
	// getters
	typedef v1nil     (NW_API_ENTRYP pfn_gfx_shd_get_iv)       (GLuint shd_id, GLenum param_type, GLint* param_buf);
	typedef v1nil     (NW_API_ENTRYP pfn_gfx_shd_get_info_log) (GLuint shd_id, GLsizei max_length, GLsizei* length, GLchar* info_log_buf);
	// setters
	typedef v1nil     (NW_API_ENTRYP pfn_gfx_shd_set_source)   (GLuint shd_id, GLsizei arg_count, const GLchar* const* src_string, const GLint* src_length);
	// predicates
	typedef GLboolean (NW_API_ENTRYP pfn_gfx_shd_is_shader)    (GLuint shd_id);
}
namespace NW
{
	// general
	extern pfn_gfx_shd_crt ogl_shd_crt;
	extern pfn_gfx_shd_del ogl_shd_del;
	extern pfn_gfx_shd_compile ogl_shd_compile;
	// getters
	extern pfn_gfx_shd_get_iv ogl_shd_get_iv;
	extern pfn_gfx_shd_get_info_log ogl_shd_get_info_log;
	// setters
	extern pfn_gfx_shd_set_source ogl_shd_set_source;
	// predicates
	extern pfn_gfx_shd_is_shader ogl_shd_is_shader;
}
// general
#	define glCreateShader     ogl_shd_crt
#	define glDeleteShader     ogl_shd_del
#	define glCompileShader    ogl_shd_compile
// getters
#	define glGetShaderiv      ogl_shd_get_iv
#	define glGetShaderInfoLog ogl_shd_get_info_log
// setters
#	define glShaderSource     ogl_shd_set_source
// predicates
#	define glIsShader         ogl_shd_is_shader
#ifndef __gl_h__
// general
#define GL_SHADER                         0x82E1
#define GL_PROGRAM                        0x82E2
#define GL_VERTEX_SHADER                  0x8B31
#define GL_GEOMETRY_SHADER                0x8DD9
#define GL_COMPUTE_SHADER                 0x91B9
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_ACTIVE_PROGRAM                 0x825
#define GL_CURRENT_PROGRAM                0x8B8D
#define GL_UNIFORM                        0x92E1
#define GL_UNIFORM_BLOCK                  0x92E2
#define GL_PROGRAM_INPUT                  0x92E3
#define GL_PROGRAM_OUTPUT                 0x92E4
// params
#define GL_MAX_UNIFORM_LOCATIONS          0x826E
#define GL_INFO_LOG_LENGTH                0x8B84
// info
#define GL_SHADING_LANGUAGE_VERSION       0x8B8C
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#endif	// __gl_h__
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
struct ID3D10Blob;
struct ID3D11Blob;
using ID3DBlob = ID3D10Blob;
struct ID3D11VertexShader;
struct ID3D11PixelShader;
struct ID3D11GeometryShader;
struct ID3D11ShaderResource;
namespace NW
{
	typedef HRESULT (NW_API_ENTRYP pfn_gfx_shd_compile)
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
namespace NW
{
	extern pfn_gfx_shd_compile gfx_shd_compile;
}
#	define D3DCompile gfx_shd_compile
#	endif	// GAPI_D3D
#endif	// NW_GAPI
#endif	// NW_GFX_LIB_SHD_H
