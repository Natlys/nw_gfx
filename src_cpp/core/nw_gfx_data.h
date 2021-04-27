#ifndef NW_GFX_DATA_H
#define NW_GFX_DATA_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
// vertex
namespace NW
{
	static inline v1f vtx_quad_2f[] = {
		-1.0f,	-1.0f, // lt-bt
		-1.0f,	+1.0f, // lt-tp
		+1.0f,	+1.0f, // rt-tp
		+1.0f,	-1.0f, // rt-bt
	};
	static inline v1f vtx_quad_2f2f[] = {
	-1.0f,	-1.0f,	0.00f,	0.00f,	// lt-bt
	-1.0f,	+1.0f,	0.00f,	1.00f,	// lt-tp
	+1.0f,	+1.0f,	1.00f,	1.00f,	// rt-tp
	+1.0f,	-1.0f,	1.00f,	0.00f,	// rt-bt
	};
	static inline const v1f vtx_quad_3f2f3f[] = {
		-0.5f,	-0.5f,	-0.0f,	0.00f,	0.00f,	+0.0f,	+0.0f,	-1.0f,
		-0.5f,	+0.5f,	-0.0f,	0.00f,	1.00f,	+0.0f,	+0.0f,	-1.0f,
		+0.5f,	+0.5f,	-0.0f,	1.00f,	1.00f,	+0.0f,	+0.0f,	-1.0f,
		+0.5f,	-0.5f,	-0.0f,	1.00f,	0.00f,	+0.0f,	+0.0f,	-1.0f,
	};
	static inline const v1f vtx_cube_3f[] = {
		// lt
		-1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f,  1.0f,
		// rt
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f, -1.0f,
		// bt
		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		 1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		// tp
		-1.0f,  1.0f, -1.0f,
		 1.0f,  1.0f, -1.0f,
		 1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		// bk
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f,  1.0f, -1.0f,
		// ft
		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f, -1.0f,  1.0f,
	};
	static inline const v1f vtx_cube_3f2f3f[] = {
		// lt
		-0.5f,	-0.5f,	-0.5f,	0.00f,	0.00f,	-1.0f,	+0.0f,	+0.0f,
		-0.5f,	-0.5f,	+0.5f,	0.00f,	1.00f,	-1.0f,	+0.0f,	+0.0f,
		-0.5f,	+0.5f,	+0.5f,	1.00f,	1.00f,	-1.0f,	+0.0f,	+0.0f,
		-0.5f,	+0.5f,	-0.5f,	1.00f,	0.00f,	-1.0f,	+0.0f,	+0.0f,
		// rt
		+0.5f,	-0.5f,	-0.5f,	0.00f,	0.00f,	+1.0f,	+0.0f,	+0.0f,
		+0.5f,	-0.5f,	+0.5f,	0.00f,	1.00f,	+1.0f,	+0.0f,	+0.0f,
		+0.5f,	+0.5f,	+0.5f,	1.00f,	1.00f,	+1.0f,	+0.0f,	+0.0f,
		+0.5f,	+0.5f,	-0.5f,	1.00f,	0.00f,	+1.0f,	+0.0f,	+0.0f,
		// bt
		-0.5f,	-0.5f,	-0.5f,	0.00f,	0.00f,	+0.0f,	-1.0f,	+0.0f,
		-0.5f,	-0.5f,	+0.5f,	0.00f,	1.00f,	+0.0f,	-1.0f,	+0.0f,
		+0.5f,	-0.5f,	+0.5f,	1.00f,	1.00f,	+0.0f,	-1.0f,	+0.0f,
		+0.5f,	-0.5f,	-0.5f,	1.00f,	0.00f,	+0.0f,	-1.0f,	+0.0f,
		// tp
		-0.5f,	+0.5f,	-0.5f,	0.00f,	0.00f,	+0.0f,	+1.0f,	+0.0f,
		-0.5f,	+0.5f,	+0.5f,	0.00f,	1.00f,	+0.0f,	+1.0f,	+0.0f,
		+0.5f,	+0.5f,	+0.5f,	1.00f,	1.00f,	+0.0f,	+1.0f,	+0.0f,
		+0.5f,	+0.5f,	-0.5f,	1.00f,	0.00f,	+0.0f,	+1.0f,	+0.0f,
		// bk
		-0.5f,	-0.5f,	-0.5f,	0.00f,	0.00f,	+0.0f,	+0.0f,	-1.0f,
		-0.5f,	+0.5f,	-0.5f,	0.00f,	1.00f,	+0.0f,	+0.0f,	-1.0f,
		+0.5f,	+0.5f,	-0.5f,	1.00f,	1.00f,	+0.0f,	+0.0f,	-1.0f,
		+0.5f,	-0.5f,	-0.5f,	1.00f,	0.00f,	+0.0f,	+0.0f,	-1.0f,
		// ft
		-0.5f,	-0.5f,	+0.5f,	0.00f,	0.00f,	+0.0f,	+0.0f,	+1.0f,
		-0.5f,	+0.5f,	+0.5f,	0.00f,	1.00f,	+0.0f,	+0.0f,	+1.0f,
		+0.5f,	+0.5f,	+0.5f,	1.00f,	1.00f,	+0.0f,	+0.0f,	+1.0f,
		+0.5f,	-0.5f,	+0.5f,	1.00f,	0.00f,	+0.0f,	+0.0f,	+1.0f,
	};
}
// index
namespace NW
{
	static inline const v1u idx_quad[] = {
		// lt-bt -> lt-tp -> rt-tp
		0u, 1u, 2u,
		// rt-tp -> rt-bt -> lt-bt
		2u, 3u, 0u,
	};
	static inline const v1u idx_cube[] = {
		// lt
		0u + 0u,	0u + 1u,	0u + 2u,
		0u + 2u,	0u + 3u,	0u + 0u,
		// rt
		4u + 0u,	4u + 1u,	4u + 2u,
		4u + 2u,	4u + 3u,	4u + 0u,
		// bt
		8u + 0u,	8u + 1u,	8u + 2u,
		8u + 2u,	8u + 3u,	8u + 0u,
		// tp
		12u + 0u,	12u + 1u,	12u + 2u,
		12u + 2u,	12u + 3u,	12u + 0u,
		// bk
		16u + 0u,	16u + 1u,	16u + 2u,
		16u + 2u,	16u + 3u,	16u + 0u,
		// ft
		20u + 0u,	20u + 1u,	20u + 2u,
		20u + 2u,	20u + 3u,	20u + 0u,
	};
}
namespace NW
{
	static inline const v1u08 txr_pixels[] = {
		0u,		128u,	0u,		255u,
		0u,		0u,		128u,	255u,
		0u,		0u,		128u,	255u,
		0u,		128u,	0u,		255u,
	};
}
// shader code
namespace NW
{
#if (NW_GAPI & NW_GAPI_OGL)
	static inline const cstr_t shd_src_3d_vtx = R"(
#version 460 core

layout(location = 0)in vec3 vsi_vtx_crd;
layout(location = 1)in vec2 vsi_txr_crd;
layout(location = 2)in vec3 vsi_nrm_crd;

out VS_INFO{vec4 vtx_crd;vec2 txr_crd;vec3 nrm_crd;}vso;

layout(std140)uniform cst_tform{mat4 cst_modl;mat4 cst_view;mat4 cst_proj;};

void main()
{
	gl_Position =
		cst_proj *
		cst_view *
		//cst_modl *
		vec4(vsi_vtx_crd.xyz, 1.0f);

	vso.vtx_crd = gl_Position;
	vso.txr_crd = vsi_txr_crd;
	vso.nrm_crd.x = clamp(vsi_nrm_crd.x, 0.1f, 0.5f);
	vso.nrm_crd.y = clamp(vsi_nrm_crd.y, 0.2f, 0.5f);
	vso.nrm_crd.z = clamp(vsi_nrm_crd.z, 0.3f, 0.5f);
}
)";
	static inline const cstr_t shd_src_3d_pxl = R"(
#version 460 core

in VS_INFO{vec4 vtx_crd;vec2 txr_crd;vec3 nrm_crd;}psi;

layout(location=0)out vec4 pso_pxl_clr_0;

layout(location=0)uniform sampler2D cst_txr_idx;

void main()
{
	vec4 txr_clr;
	
	txr_clr = texture(cst_txr_idx, psi.txr_crd).rgba;

	//if (txr_clr.r == 0.0f || txr_clr.g == 0.0f || txr_clr.b == 0.0f) { discard; }
	//txr_clr = vec4(normalize(psi.nrm_crd), 1.0f);
	//txr_clr = vec4(1.0f, 1.0f, 1.0f, 1.0f);

	pso_pxl_clr_0 = txr_clr;
}
)";
	static inline const cstr_t shd_src_screen_vtx = R"(
#version 460 core

layout(location = 0)in vec3 vsi_vtx_crd;

out VS_INFO{vec4 vtx_crd;}vso;

void main()
{
	gl_Position = vec4(vsi_vtx_crd.xyz, 1.0f);

	vso.vtx_crd = gl_Position;
	
}
)";
	static inline const cstr_t shd_src_screen_pxl = R"(
#version 460 core

in VS_INFO{vec4 vtx_crd;}psi;

layout(location=0)out vec4 pso_pxl_clr_0;

layout(location=0)uniform sampler2D cst_txr_idx;

void main()
{
	vec4 txr_clr;
	
	txr_clr = texture(cst_txr_idx, psi.vtx_crd.xy).rgba;

	pso_pxl_clr_0 = txr_clr;
}
)";
#endif
#if (NW_GAPI & NW_GAPI_D3D)
	static inline const cstr shd_default_3d_vtx = R"(
struct VS_IN {
	float3 vtx_crd : vsi_vtx_crd;
	float2 txr_crd : vsi_txr_crd;
	float3 nrm_crd : vsi_nrm_crd;
};
struct VS_OUT {
	float4 vtx_crd : sv_position;
	float2 txr_crd : vso_txr_crd;
	float3 nrm_crd : vso_nrm_crd;
};

cbuffer cbf_transform {
	row_major matrix cst_model;
	row_major matrix cst_view;
	row_major matrix cst_proj;
};

VS_OUT main(VS_IN vsi)
{
	VS_OUT vso;
	vso.vtx_crd = float4(vsi.vtx_crd.x, vsi.vtx_crd.y, vsi.vtx_crd.z, 1.0f);
	vso.vtx_crd = mul(vso.vtx_crd, cst_model);
	vso.vtx_crd = mul(vso.vtx_crd, cst_view);
	vso.vtx_crd = mul(vso.vtx_crd, cst_proj);
	vso.txr_crd = vsi.txr_crd;
	vso.nrm_crd = vsi.nrm_crd;
	return vso;
}
)";
	static inline const cstr shd_default_3d_pxl = R"(
Texture2D cst_txr : register(t0);
SamplerState cst_smp : register(s0);

float4 main(float4 vtx_crd : sv_position, float2 txr_crd : vso_txr_crd, float3 nrm_crd : vso_nrm_crd) : sv_target
{
	float4 pxl_clr = cst_txr.Sample(cst_smp, txr_crd);
	//float4 pxl_clr = float4(txr_crd.x, txr_crd.y, txr_crd.x, 1.0f);
	//float4 pxl_clr = float4(vtx_crd.x, vtx_crd.y, vtx_crd.z, 1.0f);
	
	return pxl_clr;
}
)";
#endif
}

#endif	// NW_GFX_GAPI
#endif	// NW_GFX_DATA_H