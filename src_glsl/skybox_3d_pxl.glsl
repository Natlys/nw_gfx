#version 460 core
// iput;
in VS_INFO{vec3 txr_crd;}psi;
layout(location=0)uniform samplerCube txr_idx;
// oput;
layout(location=0)out vec4 pso_pxl_clr;
// functions;
void main()
{
	vec4 txr_clr = texture(txr_idx, psi.txr_crd).rgba;
	
	//if (txr_clr.r == 0.0f || txr_clr.g == 0.0f || txr_clr.b == 0.0f) { discard; }

	txr_clr = vec4(1.0f, 1.0f, 1.0f, 1.0f);

	pso_pxl_clr = txr_clr;
}