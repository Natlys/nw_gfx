#ifndef NW_GFX_DATA_H
#define NW_GFX_DATA_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#include "core/nw_core_mtx.h"
namespace NW
{
	struct NW_API vtx_v2f
	{
		v2f vtx_crd = { 0.0f, 0.0f };
	};
	struct NW_API vtx_v2fv2f
	{
		v2f vtx_crd = { 0.0f, 0.0f };
		v2f tex_crd = { 0.0f, 0.0f };
	};
	struct NW_API vtx_v2fv2fv4u08
	{
		v2f vtx_crd = { 0.0f, 0.0f };
		v2f tex_crd = { 0.0f, 0.0f };
		v4u08 vtx_clr = { 0u, 0u, 0u, 0u };
	};
	struct NW_API vtx_v3f
	{
		v3f vtx_crd = { 0.0f, 0.0f, 0.0f };
	};
	struct NW_API vtx_v3fv2f
	{
		v3f vtx_crd = { 0.0f, 0.0f, 0.0f };
		v2f txr_crd = { 0.0f, 0.0f };
	};
	struct NW_API vtx_v3fv2fv3f
	{
		v3f vtx_crd = { 0.0f, 0.0f, 0.0f };
		v2f tex_crd = { 0.0f, 0.0f };
		v3f nrm_crd = { 0.0f, 0.0f, 0.0f };
	};
}
namespace NW
{
	struct NW_API buf_m4f {
		m4f model = m4f::make_ident();
	};
	struct NW_API buf_m4fm4f {
		m4f view = m4f::make_ident();
		m4f proj = m4f::make_ident();
	};
	struct NW_API buf_m4fm4fm4f {
		m4f model = m4f::make_ident();
		m4f view = m4f::make_ident();
		m4f proj = m4f::make_ident();
	};
}
namespace NW
{
	/// templated graphics_data class
	/// description:
	/// --makes render data for primitives;
	/// interface:
	/// --add vertex data one by one;
	/// --update_idx_data for required topology;
	/// --use index and vertex data for drawing;
	template<typename vtype, typename itype = v1u>
	class NW_API t_gfx_data
	{
		using cvtype = const vtype;
		using citype = const itype;
		using vertices = darray<vtype>;
		using cvertices = const darray<vtype>;
		using indices = darray<itype>;
		using cindices = const darray<itype>;
		using prim = venum;
	public:
		t_gfx_data() :
			m_vtxs(vertices()), m_idxs(indices()), m_iter(0) { }
		// --getters
		inline cvertices& get_vtx_buf() const { return m_vtxs; }
		inline cvtype* get_vtx_data() const   { return &m_vtxs[0]; }
		inline size_tc get_vtx_count() const  { return m_vtxs.size(); }
		inline vtype get_vtx(v1u idx) const   { return m_vtxs[idx % m_vtxs.size()]; }
		inline cindices& get_idx_buf() const  { return m_idxs; }
		inline citype* get_idx_data() const   { return &m_idxs[0]; }
		inline v1u get_idx_count()	const     { return m_idxs.size(); }
		inline itype get_idx(v1u idx) const   { return m_idxs[idx % m_idxs.size()]; }
		// --setters
		void set_vtx_buf(cvertices& buffer)    { m_vtxs = buffer; }
		void add_vtx_buf(cvertices& buffer)    { for (auto& ivtx : buffer) { add_vtx(ivtx); } }
		void add_vtx(cvtype& vtx)              { m_vtxs.push_back(vtx); }
		// --core_methods
		void update_indices(prim primitive) {
			switch (primitive) {
				if (m_vtxs.size() < 1) { break; }
			case NW_PRIM_POINTS:
			case NW_PRIM_LINE_LOOP:
			case NW_PRIM_LINE_STRIP:
			case NW_PRIM_TRIANGLE_FAN: {
				while (m_iter < m_vtxs.size() - 0) {
					m_idxs.push_back(m_iter + 0);
					m_iter++;
				}
				m_iter++;
				break;
			}
			case NW_PRIM_LINES: {
				if (m_vtxs.size() < 2) { break; }
				while (m_iter < m_vtxs.size() - 1) {
					m_idxs.push_back(m_iter + 0);
					m_idxs.push_back(m_iter + 1);
					m_iter++;
				}
				m_iter++;
				break;
			}
			case NW_PRIM_TRIANGLES: {
				if (m_vtxs.size() < 3) { break; }
				v1u first = m_iter;
				while (m_iter < m_vtxs.size() - 2) {
					m_idxs.push_back(first);
					m_idxs.push_back(m_iter + 1);
					m_idxs.push_back(m_iter + 2);
					m_iter++;
				}
				m_iter++;
				break;
			}
			case NW_PRIM_TRIANGLE_STRIP: {
				if (m_vtxs.size() < 3) { break; }
				v1u first = m_iter;
				while (m_iter < m_vtxs.size() - 0) {
					m_idxs.push_back(first);
					m_idxs.push_back(m_iter + 0);
					m_iter++;
				}
				m_iter++;
				break;
			}
			default: break;
			}
		}
		void remake() {
			m_vtxs.clear();
			m_idxs.clear();
			m_iter = 0;
		}
	private:
		vertices m_vtxs;
		indices m_idxs;
		v1u m_iter;
	};
}
// vertex
namespace NW
{
	static inline const darray<vtx_v2fv2f> vtx_quad_2f2f = {
	{ { -1.0f,	-1.0f },	{ 0.00f,	0.00f } },	// lt-bt
	{ { -1.0f,	+1.0f },	{ 0.00f,	1.00f } },	// lt-tp
	{ { +1.0f,	+1.0f },	{ 1.00f,	1.00f } },	// rt-tp
	{ { +1.0f,	-1.0f },	{ 1.00f,	0.00f } },	// rt-bt
	};
	static inline const darray<vtx_v3fv2fv3f> vtx_quad_3f2f3f = {
		{ {	-0.5f,	-0.5f,	-0.0f },	{ 0.00f,	0.00f },	{ +0.0f,	+0.0f,	-1.0f } },
		{ {	-0.5f,	+0.5f,	-0.0f },	{ 0.00f,	1.00f },	{ +0.0f,	+0.0f,	-1.0f } },
		{ {	+0.5f,	+0.5f,	-0.0f },	{ 1.00f,	1.00f },	{ +0.0f,	+0.0f,	-1.0f } },
		{ {	+0.5f,	-0.5f,	-0.0f },	{ 1.00f,	0.00f },	{ +0.0f,	+0.0f,	-1.0f } },
	};
	static inline const darray<vtx_v3f> vtx_cube_3f = {
		// lt
		{ { -1.0f, -1.0f,  1.0f } },
		{ { -1.0f, -1.0f, -1.0f } },
		{ { -1.0f,  1.0f, -1.0f } },
		{ { -1.0f,  1.0f,  1.0f } },
		// rt
		{  { 1.0f, -1.0f, -1.0f } },
		{  { 1.0f, -1.0f,  1.0f } },
		{  { 1.0f,  1.0f,  1.0f } },
		{  { 1.0f,  1.0f, -1.0f } },
		// bt
		{ { -1.0f, -1.0f, -1.0f } },
		{ { -1.0f, -1.0f,  1.0f } },
		{ {  1.0f, -1.0f, -1.0f } },
		{ { -1.0f, -1.0f,  1.0f } },
		// tp
		{ { -1.0f,  1.0f, -1.0f } },
		{ {  1.0f,  1.0f, -1.0f } },
		{ {  1.0f,  1.0f,  1.0f } },
		{ { -1.0f,  1.0f,  1.0f } },
		// bk
		{ { -1.0f,  1.0f, -1.0f } },
		{ { -1.0f, -1.0f, -1.0f } },
		{ {  1.0f, -1.0f, -1.0f } },
		{ {  1.0f,  1.0f, -1.0f } },
		// ft
		{ { -1.0f, -1.0f,  1.0f } },
		{ { -1.0f,  1.0f,  1.0f } },
		{ {  1.0f,  1.0f,  1.0f } },
		{ {  1.0f, -1.0f,  1.0f } },
	};
	static inline const darray<vtx_v3fv2fv3f> vtx_cube_3f2f3f = {
		// lt
		{ { -0.5f,	-0.5f,	-0.5f },	{ 0.00f,	0.00f },	{ -1.0f,	+0.0f,	+0.0f } },
		{ { -0.5f,	-0.5f,	+0.5f },	{ 0.00f,	1.00f },	{ -1.0f,	+0.0f,	+0.0f } },
		{ { -0.5f,	+0.5f,	+0.5f },	{ 1.00f,	1.00f },	{ -1.0f,	+0.0f,	+0.0f } },
		{ { -0.5f,	+0.5f,	-0.5f },	{ 1.00f,	0.00f },	{ -1.0f,	+0.0f,	+0.0f } },
		// rt
		{ { +0.5f,	-0.5f,	-0.5f },	{ 0.00f,	0.00f },	{ +1.0f,	+0.0f,	+0.0f } },
		{ { +0.5f,	-0.5f,	+0.5f },	{ 0.00f,	1.00f },	{ +1.0f,	+0.0f,	+0.0f } },
		{ { +0.5f,	+0.5f,	+0.5f },	{ 1.00f,	1.00f },	{ +1.0f,	+0.0f,	+0.0f } },
		{ { +0.5f,	+0.5f,	-0.5f },	{ 1.00f,	0.00f },	{ +1.0f,	+0.0f,	+0.0f } },
		// bt
		{ { -0.5f,	-0.5f,	-0.5f },	{ 0.00f,	0.00f },	{ +0.0f,	-1.0f,	+0.0f } },
		{ { -0.5f,	-0.5f,	+0.5f },	{ 0.00f,	1.00f },	{ +0.0f,	-1.0f,	+0.0f } },
		{ { +0.5f,	-0.5f,	+0.5f },	{ 1.00f,	1.00f },	{ +0.0f,	-1.0f,	+0.0f } },
		{ { +0.5f,	-0.5f,	-0.5f },	{ 1.00f,	0.00f },	{ +0.0f,	-1.0f,	+0.0f } },
		// tp
		{ { -0.5f,	+0.5f,	-0.5f },	{ 0.00f,	0.00f },	{ +0.0f,	+1.0f,	+0.0f } },
		{ { -0.5f,	+0.5f,	+0.5f },	{ 0.00f,	1.00f },	{ +0.0f,	+1.0f,	+0.0f } },
		{ { +0.5f,	+0.5f,	+0.5f },	{ 1.00f,	1.00f },	{ +0.0f,	+1.0f,	+0.0f } },
		{ { +0.5f,	+0.5f,	-0.5f },	{ 1.00f,	0.00f },	{ +0.0f,	+1.0f,	+0.0f } },
		// bk
		{ { -0.5f,	-0.5f,	-0.5f },	{ 0.00f,	0.00f },	{ +0.0f,	+0.0f,	-1.0f } },
		{ { -0.5f,	+0.5f,	-0.5f },	{ 0.00f,	1.00f },	{ +0.0f,	+0.0f,	-1.0f } },
		{ { +0.5f,	+0.5f,	-0.5f },	{ 1.00f,	1.00f },	{ +0.0f,	+0.0f,	-1.0f } },
		{ { +0.5f,	-0.5f,	-0.5f },	{ 1.00f,	0.00f },	{ +0.0f,	+0.0f,	-1.0f } },
		// ft
		{ { -0.5f,	-0.5f,	+0.5f },	{ 0.00f,	0.00f },	{ +0.0f,	+0.0f,	+1.0f } },
		{ { -0.5f,	+0.5f,	+0.5f },	{ 0.00f,	1.00f },	{ +0.0f,	+0.0f,	+1.0f } },
		{ { +0.5f,	+0.5f,	+0.5f },	{ 1.00f,	1.00f },	{ +0.0f,	+0.0f,	+1.0f } },
		{ { +0.5f,	-0.5f,	+0.5f },	{ 1.00f,	0.00f },	{ +0.0f,	+0.0f,	+1.0f } },
	};
}
// index
namespace NW
{
	static inline const darray<v1u> idx_quad = {
		// lt-bt -> lt-tp -> rt-tp
		0u, 1u, 2u,
		// rt-tp -> rt-bt -> lt-bt
		2u, 3u, 0u,
	};
	static inline const darray<v1u> idx_cube = {
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
	static inline const darray<v1u08> txr_pixels = {
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
	static inline const cstr shd_default_3d_vtx = R"(
#version 460 core

layout(location = 0)in vec3 vsi_vtx_crd;
layout(location = 1)in vec2 vsi_txr_crd;
layout(location = 2)in vec3 vsi_nrm_crd;

out VS_INFO{vec4 vtx_crd;vec2 txr_crd;vec3 nrm_crd;}vso;

layout(std140)uniform cst_transform{mat4 cst_model;mat4 cst_view;mat4 cst_proj;};

void main()
{
	gl_Position =
		cst_proj *
		cst_view *
		cst_model *
		vec4(vsi_vtx_crd.xyz, 1.0f);

	vso.vtx_crd = gl_Position;
	vso.txr_crd = vsi_txr_crd;
	vso.nrm_crd.x = clamp(vsi_nrm_crd.x, 0.1f, 0.5f);
	vso.nrm_crd.y = clamp(vsi_nrm_crd.y, 0.2f, 0.5f);
	vso.nrm_crd.z = clamp(vsi_nrm_crd.z, 0.3f, 0.5f);
}
)";
	static inline const cstr shd_default_3d_pxl = R"(
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
	txr_clr = vec4(1.0f, 1.0f, 1.0f, 1.0f);

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