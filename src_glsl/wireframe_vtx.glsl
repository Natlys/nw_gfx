#version 460 core
// iput;
layout(location=0)in vec3 vsi_vtx_crd;
// oput;
out VS_INFO{vec4 vtx_crd}vso;
// functions;
void main()
{
	gl_Position =
		cam_proj *
		cam_view *
		obj_modl *
		vec4(vsi_vtx_crd.xyz, 1.0f);
}