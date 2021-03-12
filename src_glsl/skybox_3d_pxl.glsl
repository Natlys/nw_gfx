#version 400 core

in VS_INFO{vec3 txr_crd;}psi;

out vec4 pso_pxl_clr;

uniform samplerCube unf_txr_idx_0;

void main()
{
	
	vec4 txr_clr = texture(unf_txr_idx_0, psi.txr_crd).rgba;
	
	pso_pxl_clr = txr_clr;
}