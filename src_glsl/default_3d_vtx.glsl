#version 460 core

layout(location=0)in vec3 vsi_vtx_crd;
layout(location=1)in vec2 vsi_txr_crd;
layout(location=2)in vec3 vsi_nrm_crd;

out VS_INFO{vec4 vtx_crd;vec2 txr_crd;vec3 nrm_crd;}vso;

layout(std140)uniform cst_transform{mat4 cst_model;mat4 cst_view;mat4 cst_proj;};

void main()
{
	gl_Position =
		cst_proj *
		cst_view *
		cst_model *
		vec4(vsi_vtx_crd.xyz, 1.0f);

	vso.vtx_crd = gl_Position;
	vso.txr_crd = vsi_txr_crd;
	vso.nrm_crd = vsi_nrm_crd;
}