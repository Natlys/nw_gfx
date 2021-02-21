struct VS_INFO {
	float2 texCrd : vs_tex_crd;
	float3 nrmCrd : vs_nrm_crd;
	float4 vtxCrd : sv_position;
};

cbuffer cbf_transform {
	matrix cst_matModel;
	matrix cst_matView;
	matrix cst_matProj;
};
VS_INFO main(float3 atb_vtxCrd : vtx_crd, float2 atb_texCrd : tex_crd, float3 atb_nrmCrd : nrm_crd)
{
	VS_INFO vso;
	vso.texCrd = atb_texCrd;
	vso.nrmCrd = atb_nrmCrd;
	vso.vtxCrd = float4(atb_vtxCrd.x, atb_vtxCrd.y, atb_vtxCrd.z, 1.0f);
	vso.vtxCrd = mul(vso.vtxCrd, cst_matProj);
	vso.vtxCrd = mul(vso.vtxCrd, cst_matView);
	vso.vtxCrd = mul(vso.vtxCrd, cst_matModel);
	return vso;
}