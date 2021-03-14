#version 460 core

in VS_INFO{vec3 txr_crd;}psi;

out vec4 pso_pxl_clr;

layout(location=0)uniform samplerCube unf_txr_idx;

void main()
{
	vec4 txr_clr = texture(unf_txr_idx, psi.txr_crd).rgba;
	
	//if (txr_clr.r == 0.0f || txr_clr.g == 0.0f || txr_clr.b == 0.0f) { discard; }

	pso_pxl_clr = txr_clr;
}