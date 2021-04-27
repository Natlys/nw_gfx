#version 460 core
// iput;
layout(location=0)in vec2 vti_vtx_crd;
layout(location=1)in vec2 vti_txr_crd;
// oput;
out VS_INFO{vec2 vtx_crd;vec2 txr_crd;}vso;
// functions;
void main()
{
	gl_Position = vec4(vti_vtx_crd.x, vti_vtx_crd.y, 0.0f, 1.0f);
	
	vso.vtx_crd = vec2(vti_vtx_crd.x, vti_vtx_crd.y);
	vso.txr_crd = vec2(vti_txr_crd.x, vti_txr_crd.y);
}