#version 400 core

layout(location = 0) in vec2 atb_vtxCrd;
layout(location = 1) in vec2 atb_texCrd;

layout(std140)uniform unf_mat {
	mat4 unf_matProj;
	mat4 unf_matView;
};

out VS_INFO {
	vec2 vtxCrd;
	vec2 texCrd;
} vso;

void main()
{
	gl_Position = vec4(atb_vtxCrd.x, atb_vtxCrd.y, 0.0f, 1.0f);
	vso.vtxCrd = atb_vtxCrd;
	vso.texCrd = atb_texCrd;
}