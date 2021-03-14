#version 460 core

layout(location=0)in vec2 atb_vtx_crd;
layout(location=1)in vec2 atb_txr_crd;

layout(std140)uniform unf_transform{mat4 unf_model;mat4 unf_view;mat4 unf_proj;};

out VS_INFO {vec4 vtx_crd;vec2 txr_crd;}vso;

void main()
{
	gl_Position =
		unf_proj *
		unf_view *
		unf_model *
		vec4(atb_vtx_crd.x, atb_vtx_crd.y, -1.0f, 1.0f);
	vso.vtx_crd = gl_Position;
	vso.txr_crd = atb_txr_crd;
}