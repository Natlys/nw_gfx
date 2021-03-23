#ifndef NWG_CORE_HPP
#define NWG_CORE_HPP
// --==<configuration>==--
#define NW_BUILD_DLL
// --==</configurations>==--
#include <nwg_pch.hpp>
#if (defined NW_GAPI)
namespace NW
{
	class NW_API gfx_engine;
	class NW_API a_gfx_cmp;

	class NW_API a_gfx_ent;
	class NW_API ent_vtx;
	class NW_API ent_idx;

	class NW_API gfx_mtl;
	
	class NW_API fmbuf;
	
	class NW_API buf_vtx;
	class NW_API buf_idx;
	class NW_API buf_shd;

	class NW_API a_shd;
	class NW_API shd_vtx;
	class NW_API shd_pxl;
	class NW_API shd_gmt;

	class NW_API img_cmp;
	class NW_API img_bmp;
	class NW_API img_png;
	class NW_API image_jpg;
	class NW_API a_txr;
	class NW_API txr_1d;
	class NW_API txr_2d;
	class NW_API txr_2d_mulsmp;
	class NW_API txr_font;
	class NW_API txr_cube;
	class NW_API txr_smp;

	class NW_API a_gfx_stt;
	class NW_API stt_depth;
	class NW_API stt_stenc;
	class NW_API stt_draw;
	class NW_API stt_cull;
	class NW_API stt_blend;
	class NW_API stt_scis;
	class NW_API stt_viewp;

	struct NW_API camera;
	class NW_API camera_lad;
}
#if (NW_GAPI & NW_GAPI_OGL)
#endif
#if (NW_GAPI & NW_GAPI_DX)
struct ID3D11Blob;
struct ID3D10Blob;
struct IDXGISwapChain;
struct ID3D11RenderTarget;
struct ID3D11RenderTargetView;
struct ID3D11Resource;
struct ID3D11ShaderResource;
struct ID3D11ShaderResourceView;
struct ID3D11Buffer;
struct ID3D11InputLayout;
struct ID3D11VertexShader;
struct ID3D11PixelShader;
struct ID3D11GeometryShader;
struct ID3D11ShaderResource;
struct ID3D11SamplerState;
using ID3DBlob = ID3D10Blob;
struct ID3D11DeviceChild;
struct ID3D11Texture1D;
struct ID3D11Texture2D;
struct ID3D11Texture3D;
struct ID3D11CubeTexture;
#endif
#endif	// NW_GAPI
#endif	// NWG_CORE_HPP