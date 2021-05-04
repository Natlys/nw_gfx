#version 460 core
// iput;
in VS_INFO{vec4 vtx_crd;vec2 txr_crd;vec3 nrm_crd;}psi;
layout(location=0)uniform sampler2D txr_idx;
// oput;
layout(location=0)out vec4 pso_pxl_clr_0;
// functions;
// // lighting;
vec4 get_light_direct_albedo(vec3 dir, vec4 clr) { return clr * dot(normalize(psi.nrm_crd), normalize(dir)); }
// // core;
void main()
{
	vec4 txr_clr;

	txr_clr = texture(txr_idx, psi.txr_crd).rgba;

	//if (txr_clr.r == 0.0f || txr_clr.g == 0.0f || txr_clr.b == 0.0f) { discard; }

	pso_pxl_clr_0 = vec4(1.0f, 1.0f, 1.0f, 1.0f)
		* get_light_direct_albedo(vec3(0.33f, 0.33f, 0.33f), txr_clr)
		* get_light_direct_albedo(vec3(0.66f, 0.66f, 0.66f), txr_clr)
		;
}