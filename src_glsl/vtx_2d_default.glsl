#version 400 core

layout(location=0)in vec2 atb_vtxCrd;
layout(location=1)in vec2 atb_texCrd;

layout(std140)uniform unf_tform{mat4 unf_matModel;mat4 unf_matProj;mat4 unf_matView;};

out VS_INFO {vec4 vtxCrd;vec2 texCrd;}vso;

void main()
{
	gl_Position =
	//	unf_matProj * unf_matView *
		vec4(atb_vtxCrd.x, atb_vtxCrd.y, 0.0f, 1.0f);
	vso.vtxCrd = gl_Position;
	vso.texCrd = atb_texCrd;
}