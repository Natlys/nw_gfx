#version 400 core

out vec4 pso_pxl_clr;

in VS_INFO{vec4 vtx_crd;vec2 txr_crd;}psi;

uniform sampler2D unf_txr_idx_0;

void main()
{
	vec4 clr_txr_0 = texture(unf_txr_idx_0, psi.txr_crd);
	
	if (clr_txr_0.r == 0) { discard; }
	else if (clr_txr_0.g == 0) { discard; }
	else if (clr_txr_0.b == 0) { discard; }
	
	pso_pxl_clr = clr_txr_0;
}