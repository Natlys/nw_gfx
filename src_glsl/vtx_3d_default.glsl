#version 400 core

layout(location = 0) in vec3 atb_vtxCrd;
layout(location = 1) in vec2 atb_texCrd;
layout(location = 2) in vec3 atb_nrmCrd;

layout(std140)uniform unf_mat {
	mat4 unf_matProj;
	mat4 unf_matView;
};

out VS_INFO {
	vec3 vtxCrd;
	vec2 texCrd;
	vec3 nrmCrd;
} vso;

void main()
{
	gl_Position = vec4(atb_vtxCrd.x, atb_vtxCrd.y, atb_vtxCrd.z, 1.0f);
	vso.vtxCrd = atb_vtxCrd;
	vso.texCrd = atb_texCrd;
	vso.nrmCrd = atb_nrmCrd;
}