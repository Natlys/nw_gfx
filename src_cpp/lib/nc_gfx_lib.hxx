#ifndef NC_GFX_LIBRARY_H
#define NC_GFX_LIBRARY_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "std/nc_std_lib.hxx"
#	include "nc_gfx_lib_core.hxx"
#	include "nc_gfx_lib_wapi.hxx"
namespace NC
{
	/// graphics_library_loader class
	class gfx_library_t : private library_t
	{
	public:
		gfx_library_t();
		~gfx_library_t();
		/* getters */
		inline v1u_tc get_ver_num() const { return m_ver_num; }
		inline v1u_tc get_ver_major() const { return (m_ver_num / 100); }
		inline v1u_tc get_ver_minor() const { return (m_ver_num / 10) % 10; }
		inline cstr_t get_ver_str() const { return &m_ver_str[0]; }
		inline cstr_t get_ext_str() const { return &m_ext_str[0]; }
		inline ptr_t get_proc(cstr_t name) {
			ptr_t proc = library_t::get_proc(name);
			if (proc == NC_NULL) { proc = wglGetProcAddress(name); }
			return proc;
		}
		/* setters */
		/* vetters */
		inline v1bit_t has_proc(cstr_t name) { get_proc(name) != NC_NULL; }
		inline v1bit_t has_support(v1u_t major, v1u_t minor) const { if (get_ver_major() == major) { return NC_TRUTH; } return NC_TRUTH; }
		inline v1bit_t has_support(cstr_t extension) const { return strstr(wglGetExtensionsStringEXT(), extension) != NC_NULL; }
		/* command */
	private:
		v1u_t m_ver_num;
		dstr_t m_ext_str;
		dstr_t m_ver_str;
#	if (NC_GAPI & NC_GAPI_OGL)
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
		handle_t m_libh_dxcomp;
		handle_t m_libh_dxgi;
#	endif	// GAPI_D3D
	};
}
namespace NC
{
	/// graphics_context_state_t
	/// --allows to backup the entire graphical context state and restore that;
	struct gfx_context_state_t
	{
		gfx_context_state_t();
		~gfx_context_state_t();
#   if (NC_GAPI & NC_GAPI_OGL)
		// --shaders
		GLuint material_handle;
		// --textures
		GLuint texture_handle;
		GLenum texture_slot;
		// --samplers
		GLuint sampler_handle;
		// --buffers
		GLuint buffer_vetex_handle;
		GLuint layout_hadle;
		// --modes
		// // --depth_stencil
		GLboolean is_enabled_depth;
		GLboolean is_enabled_stenc;
		// // --rasterizer
		GLint viewp_box[4];
		GLint sciss_box[4];
		GLenum fill_mode;
		GLenum fill_face;
		GLenum cull_mode;
		GLboolean is_enabled_sciss;
		GLboolean is_enabled_cull;
		// // --blending
		GLboolean is_enabled_blend;
		GLenum blend_src_rgb;
		GLenum blend_dst_rgb;
		GLenum blend_src_alpha;
		GLenum blend_dst_alpha;
		GLenum blend_eq_rgb;
		GLenum blend_eq_alpha;
#   endif   // GAPI_OGL
#   if (NC_GAPI & NC_GAPI_D3D)
		// --modes
		// // --rasterizer
		ID3D11RasterizerState* mode_rastr;
		UINT                     mode_rastr_sciss_count;
		UINT                     mode_rastr_viewp_count;
		D3D11_RECT               mode_rastr_sciss_rects[D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE];
		D3D11_VIEWPORT           mode_rastr_viewp_rects[D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE];
		D3D11_PRIMITIVE_TOPOLOGY mode_rastr_prim_type;
		// // --blending
		ID3D11BlendState* mode_blend;
		FLOAT             mode_blend_factor[4];
		UINT              mode_blend_sample_mask;
		// --depth_stencil
		ID3D11DepthStencilState* mode_depst;
		UINT                     mode_depst_stencil_ref;
		// --shaders
		// // --vertex_shader
		ID3D11VertexShader* shader_vertex;
		UINT                 shader_vertex_instances_count;
		ID3D11ClassInstance* shader_vertex_instances[256];
		ID3D11Buffer* shader_vertex_cbuffer;
		// // --pixel_shader
		ID3D11PixelShader* shader_pixel;
		UINT                      shader_pixel_instances_count;
		ID3D11ClassInstance* shader_pixel_instances[256];
		ID3D11ShaderResourceView* shader_pixel_resource;
		ID3D11SamplerState* shader_pixel_sampler;
		// // --geometry_shader
		ID3D11GeometryShader* shader_geometry_vertex_cbuffer;
		UINT                  shader_geomery_instances_count;
		ID3D11ClassInstance* shader_geometry_instances[256];
		// --buffers
		// // --vertex
		ID3D11Buffer* buffer_vertex;
		UINT          buffer_vertex_stride;
		UINT          buffer_vertex_offset;
		// // --index
		ID3D11Buffer* buffer_index;
		UINT          buffer_index_offset;
		DXGI_FORMAT   buffer_index_format;
		// // --layout
		ID3D11InputLayout* input_layout;
#   endif   // GAPI_D3D
	};
	v1nil_t gfx_clear_err();
	v1bit_t gfx_get_err_log(cstr_t loc, cstr_t fpath, v1u_tc line);
	v1bit_t gfx_check_shader(v1u_t shader_handle);
#	if (defined NC_WORK)
#		define NC_GFX_CALL(code)    \
			gfx_clear_err(); (code) \
			NC_CHECK(gfx_get_err_log(#code, __FILE__, __LINE__), "graphics error!")
#	else
#		define NC_GFX_CALL(code) ( code )
#	endif
}
#endif	// NC_GAPI
#endif	// NC_GFX_LIBRARY_H