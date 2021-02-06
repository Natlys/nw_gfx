#shader_type vertex
#version 400 core

layout(location = 0)in vec3 atb_vtxCrd;
layout(location = 1)in vec2 atb_texCrd;
layout(location = 2)in vec3 atb_nrmCrd;

out VS_BLOCK{
	vec3 vtxCrd;
	vec2 texCrd;
	vec3 nrmCrd;
}vs_out;

layout(std140)uniform unf_Matrices{
	mat4 unf_camProj;
	mat4 unf_camView;
	//mat4 unf_mdlTransform;
};

void main()
{
	gl_Position = unf_camProj * unf_camView *
		//unf_mdlTransform *
		vec4(atb_vtxCrd.xyz, 1.0f);

		vs_out.vtxCrd = atb_vtxCrd;
		vs_out.texCrd = atb_texCrd;
		vs_out.nrmCrd = atb_nrmCrd;
}

#shader_type pixel
#version 400 core

out vec4 ps_pxClr0;

in VS_BLOCK{
	vec3 vtxCrd;
	vec2 texCrd;
	vec3 nrmCrd;
}ps_in;

uniform vec4 unf_albedoClr;
uniform sampler2D unf_tex;

void main()
{
	ps_pxClr0 = vec4(texture(unf_tex, ps_in.texCrd).rgba *
		unf_albedoClr);
}