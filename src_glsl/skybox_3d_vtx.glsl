#version 460 core

layout(location = 0) in vec3 atb_vtx_crd;

out VS_INFO{vec3 txr_crd;}vso;

layout(std140)uniform unf_transform{mat4 unf_model;mat4 unf_view;mat4 unf_proj;};

void main()
{
	mat4 no_move_view = mat4(mat3(unf_view));

	gl_Position =
		unf_proj *
		no_move_view *
		vec4(atb_vtx_crd.xyz, 1.0f);
	
	gl_Position = gl_Position.xyww;

	vso.txr_crd = atb_vtx_crd;
}