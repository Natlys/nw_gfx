#version 460 core

out vec4 pso_pxl_clr;

in VS_INFO{vec4 vtx_crd;vec2 txr_crd;}psi;

uniform sampler2D unf_txr_idx_0;

void main()
{
	vec4 txr_clr = texture(unf_txr_idx_0, psi.txr_crd);
	
	if (txr_clr.r == 0.0f || txr_clr.g == 0.0f || txr_clr.b == 0.0f) { discard; }

	pso_pxl_clr = txr_clr;
}