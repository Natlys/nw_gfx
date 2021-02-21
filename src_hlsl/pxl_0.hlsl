float4 main(float3 vtxClr : vs_vtx_clr) : sv_target
{
	return float4(vtxClr.x, vtxClr.y, vtxClr.z, 1.0f);
}