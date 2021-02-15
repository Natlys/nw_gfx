#shader_type vertex
#version 400 core

layout(location = 0) in vec3 atb_vtxCrd;
layout(location = 1) in vec4 atb_vtxClr;
layout(location = 2) in vec2 atb_texCrd;
layout(location = 3) in float atb_texSlot;
layout(location = 4) in mat4 atb_mdlTransform;

out VS_OUT{
	vec4 vtxClr;
	vec2 texCrd;
	float texSlot;
}vs_out;

layout(std140) uniform unf_Matrices{
	mat4 unf_camProj;
	mat4 unf_camView;
};

void main()
{
	gl_Position = unf_camProj * unf_camView *
		atb_mdlTransform *
		vec4(atb_vtxCrd.xyz, 1.0f);

	vs_out.vtxClr = atb_vtxClr;
	vs_out.texCrd = atb_texCrd;
	vs_out.texSlot = atb_texSlot;
}

#shader_type pixel
#version 400 core

out vec4 ps_pxClr;

in VS_OUT{
	vec4 vtxClr;
	vec2 texCrd;
	float texSlot;
}vs_in;

uniform vec4 unf_albedoClr;
uniform sampler2D unf_tex[7];

void main()
{
	ps_pxClr = vec4(texture(unf_tex[int(vs_in.texSlot)], vs_in.texCrd).rgba *
		vs_in.vtxClr * unf_albedoClr);
}