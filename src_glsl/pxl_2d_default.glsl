#version 400 core

out vec4 pso_pxlClr;

in VS_INFO{vec4 vtxCrd;vec2 texCrd;}psi;

uniform sampler2D unf_texIdx0;

void main()
{
	vec4 clrTex0 = texture(unf_texIdx0, psi.texCrd);
	
	//if (clrTex0.r == 0) { discard; }
	//else if (clrTex0.g == 0) { discard; }
	//else if (clrTex0.b == 0) { discard; }
	
	//pso_pxlClr = clrTex0;
	pso_pxlClr = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}