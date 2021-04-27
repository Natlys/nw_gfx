#version 460 core
// iput;
in VS_INFO{vec4 vtx_crd;vec2 txr_crd;vec3 nrm_crd;}psi;
layout(location=0)uniform sampler2D txr_idx;
// oput;
layout(location=0)out vec4 pso_pxl_clr_0;
// functions;
void main()
{
	vec4 txr_clr;
	
	txr_clr = texture(txr_idx, psi.txr_crd).rgba;

	//if (txr_clr.r == 0.0f || txr_clr.g == 0.0f || txr_clr.b == 0.0f) { discard; }
	//txr_clr = vec4(normalize(psi.nrm_crd), 1.0f);
	//txr_clr = vec4(1.0f, 1.0f, 1.0f, 1.0f);

	pso_pxl_clr_0 = txr_clr;
}