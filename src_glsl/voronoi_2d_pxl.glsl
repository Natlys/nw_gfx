#version 460 core
// iput;
in VS_INFO{vec2 vtx_crd;vec2 txr_crd;}psi;
// oput;
layout(location=0)out vec4 pso_pxl_clr_0;
// functions
float rand_i2o1(vec2 seed) { return (sin( dot(seed.xy, vec2(12.9898, 78.233)) * 43758.5453 ) + 1.0f) / 2.0f; }
vec2 rand_i1o2(float seed) { return vec2( rand_i2o1(vec2(seed * 2.0f)), rand_i2o1(vec2(seed / 2.0f)) ); }
void main()
{
	vec4 pxl_clr = vec4(1.0f);
	vec2 pxl_crd = psi.txr_crd.xy;

	float dist_min = 100.0f;
	float cell_min = 0.0f;
	for (float cell_idx = 0.0f; cell_idx < +1.0f; cell_idx += 0.01f) {
		vec2 cell_crd = rand_i1o2( cell_idx );
		float dist_curr = distance( pxl_crd, cell_crd );
		if (dist_curr < dist_min) { dist_min = dist_curr; cell_min = cell_idx; }
	}

	//pxl_clr = vec4( dist_min / cell_min );
	//pxl_clr = vec4( dist_min );
	pxl_clr = vec4( cell_min );
	//pxl_clr = vec4( dist_min * cell_min );

	pso_pxl_clr_0 = vec4(pxl_clr.rgb, 1.0f);
}