struct VS_INFO {
	float3 vtxClr : vs_vtx_clr;
	float4 vtxCrd : sv_position;
};

cbuffer cbf_transform {
	row_major matrix cst_matModel;
	row_major matrix cst_matView;
	row_major matrix cst_matProj;
};

VS_INFO main(float3 atb_vtxCrd : vtx_crd)
{
	VS_INFO vso;
	vso.vtxCrd = float4(atb_vtxCrd.x, atb_vtxCrd.y, atb_vtxCrd.z, 1.0f);
	vso.vtxCrd = mul(vso.vtxCrd, cst_matModel);
	vso.vtxCrd = mul(vso.vtxCrd, cst_matView);
	vso.vtxCrd = mul(vso.vtxCrd, cst_matProj);
	vso.vtxClr = float3(atb_vtxCrd.x, atb_vtxCrd.y, atb_vtxCrd.z);
	return vso;
}