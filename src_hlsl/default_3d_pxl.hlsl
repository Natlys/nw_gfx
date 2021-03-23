Texture2D cst_txr : register(ps, t[0]);
SamplerState cst_smp : register(ps, s[0]);

float4 main(float2 txr_crd : vso_txr_crd, float3 nrm_crd : vso_nrm_crd) : sv_target
{
	float4 clr_txr = cst_txr.Sample(cst_smp, txr_crd);

	return clr_txr;
}