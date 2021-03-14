#version 460 core

layout(location=0)in vec3 atb_vtx_crd;
layout(location=1)in vec2 atb_txr_crd;
layout(location=2)in vec3 atb_nrm_crd;

out VS_INFO{vec4 vtx_crd;vec2 txr_crd;vec3 nrm_crd;}vso;

layout(std140)uniform unf_transform{mat4 unf_model;mat4 unf_view;mat4 unf_proj;};

void main()
{
	gl_Position =
		unf_proj *
		unf_view *
		unf_model *
		vec4(atb_vtx_crd.x, atb_vtx_crd.y, atb_vtx_crd.z, 1.0f);

	vso.vtx_crd = gl_Position;
	vso.txr_crd = atb_txr_crd;
	vso.nrm_crd = atb_nrm_crd;
}