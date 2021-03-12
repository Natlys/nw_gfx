#version 400 core

layout(location = 0) in vec3 atb_vtx_crd;

out VS_INFO{vec3 txr_crd;}vso;

layout(std140)uniform unf_transform{mat4 unf_view;mat4 unf_proj;};

void main()
{
	gl_Position =
		unf_proj *
		unf_view *
		vec4(atb_vtx_crd.x, atb_vtx_crd.y, atb_vtx_crd.z, 1.0f);

	vso.txr_crd = atb_vtx_crd;
}