#ifndef NATIVE_GRAPHICS_CORE_HPP
#define NATIVE_GRAPHICS_CORE_HPP
// --==<configuration>==--
// --==</configurations>==--
#include <nwg_pch.hpp>
namespace NW
{
	class NW_API gfx_engine;
	class NW_API gfx_camera_lad;

	class NW_API a_gfx_rsc;
	class NW_API drawable;
	class NW_API drawable_vtx;
	class NW_API drawable_idx;

	class NW_API gfx_material;
	
	class NW_API framebuf;
	
	class NW_API buf_vtx;
	class NW_API buf_idx;
	class NW_API buf_shd;

	class NW_API a_shader;
	class NW_API shader_vtx;
	class NW_API shader_pxl;
	class NW_API shader_gmt;

	class NW_API a_image;
	class NW_API image_bmp;
	class NW_API image_png;
	class NW_API image_jpg;
	class NW_API a_texture;

	struct NW_API gfx_camera;
}
#endif	// NATIVE_GRAPHICS_CORE_HPP