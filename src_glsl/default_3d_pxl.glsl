#version 400 core

in VS_INFO{vec4 vtx_crd;vec2 txr_crd;vec3 nrm_crd;}psi;

out vec4 pso_pxl_clr;

uniform sampler2D unf_txr_idx_0;

void main()
{
	vec4 txr_clr = texture(unf_txr_idx_0, psi.txr_crd).rgba;
	
	if (txr_clr.r == 0 || txr_clr.g == 0 || txr_clr.b == 0) { discard; }
	
	pso_pxl_clr = txr_clr;
}