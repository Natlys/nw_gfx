struct VS_IN {
	float3 vtx_crd : vsi_vtx_crd;
	float2 txr_crd : vsi_txr_crd;
	float3 nrm_crd : vsi_nrm_crd;
};
struct VS_OUT {
	float2 txr_crd : vso_txr_crd;
	float3 nrm_crd : vso_nrm_crd;
	float4 vtx_crd : sv_position;
};

cbuffer cbf_transform {
	row_major matrix cst_model;
	row_major matrix cst_view;
	row_major matrix cst_proj;
};

VS_OUT main(VS_IN vsi)
{
	VS_OUT vso;
	vso.txr_crd = vsi.txr_crd;
	vso.nrm_crd = vsi.nrm_crd;
	vso.vtx_crd = float4(vsi.vtx_crd.x, vsi.vtx_crd.y, vsi.vtx_crd.z, 1.0f);
	vso.vtx_crd = mul(vso.vtx_crd, cst_model);
	vso.vtx_crd = mul(vso.vtx_crd, cst_view);
	vso.vtx_crd = mul(vso.vtx_crd, cst_proj);
	return vso;
}