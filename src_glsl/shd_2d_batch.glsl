#shader_type vertex
#version 400 core

layout(location = 0) in vec2 atb_vtxCrd;
layout(location = 1) in vec4 atb_vtxClr;
layout(location = 2) in vec2 atb_texCrd;
layout(location = 3) in float atb_texSlot;
layout(location = 4) in vec3 atb_mdlCrd;
layout(location = 5) in vec3 atb_mdlRtn;
layout(location = 6) in vec3 atb_mdlScl;

out VS_OUT{
	vec4 vtxClr;
	vec2 texCrd;
	float texSlot;
} vs_out;

layout(std140) uniform unf_Matrices{
	mat4 unf_camProj;
	mat4 unf_camView;
};

void main()
{
	mat4 mdlTransform = mat4(1.0f,0.0f,0.0f,0.0f,	0.0f,1.0f,0.0f,0.0f,	0.0f,0.0f,1.0f,0.0f,	0.0f,0.0f,0.0f,1.0f);
	//mdlTransform *= mat4(
	//	1.0f,			0.0f,			0.0f,			atb_mdlCrd.x,
	//	0.0f,			1.0f,			0.0f,			atb_mdlCrd.y,
	//	0.0f,			0.0f,			1.0f,			atb_mdlCrd.z,
	//	0.0f,			0.0f,			0.0f,			1.0f
	//);
	mdlTransform *= mat4 (
		cos(atb_mdlRtn.z),	-sin(atb_mdlRtn.z),		0.0f,				0.0f,
		sin(atb_mdlRtn.z),	cos(atb_mdlRtn.z),		0.0f,				0.0f,
		0.0f,				0.0f,					1.0f,				0.0f,
		0.0f,				0.0f,					0.0f,				1.0f
	) * mat4 (
		1.0f,				0.0f,					0.0f,				0.0f,
		0.0f,				cos(atb_mdlRtn.x),		-sin(atb_mdlRtn.x),	0.0f,
		1.0f,				sin(atb_mdlRtn.x),		cos(atb_mdlRtn.x),	0.0f,
		0.0f,				0.0f,					0.0f,				1.0f
	) * mat4 (
		cos(atb_mdlRtn.y),	0.0f,					-sin(atb_mdlRtn.y),	0.0f,
		0.0f,				1.0f,					0.0f,				0.0f,
		sin(atb_mdlRtn.y),	0.0f,					cos(atb_mdlRtn.y),	0.0f,
		0.0f,				0.0f,					0.0f,				1.0f
	);
	mdlTransform *= mat4(
		atb_mdlScl.x,	0.0f,			0.0f,			0.0f,
		0.0f,			atb_mdlScl.y,	0.0f,			0.0f,
		0.0f,			0.0f,			atb_mdlScl.z,	0.0f,
		0.0f,			0.0f,			0.0f,			1.0f
	);

	gl_Position = unf_camProj * unf_camView * mdlTransform *
		vec4(atb_vtxCrd.xy, 0.0f, 1.0f);
	
	gl_Position.x += atb_mdlCrd.x;
	gl_Position.y += atb_mdlCrd.y;
	gl_Position.z += atb_mdlCrd.z;

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