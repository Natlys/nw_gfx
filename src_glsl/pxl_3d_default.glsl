#version 400 core

out vec4 pso_pxlClr;

in VS_INFO {
	vec3 vtxCrd;
	vec2 texCrd;
	vec3 nrmCrd;
} psi;

uniform vec4 unf_abdClr;
uniform sampler2D unf_texIdx;

void main()
{
	pso_pxClr = vec4(texture(unf_texIdx, psi.texCrd).rgba * unf_abdClr);
}