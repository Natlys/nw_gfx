inline const char* strScreenShaderCode =
R"(
#shader_type vertex
#version 400 core

layout(location = 0)in vec2 atb_vtxCrd;
layout(location = 1)in vec2 atb_texCrd;

out VS_OUT{
	vec2 texCrd;
}vs_out;

void main(){
	gl_Position = vec4(atb_vtxCrd.x, atb_vtxCrd.y, 0.0f, 1.0f);
	vs_out.texCrd = atb_texCrd;
}

#shader_type pixel
#version 400 core

out vec4 ps_pxClr0;

in VS_OUT{
	vec2 texCrd;
}ps_in;

uniform sampler2D unf_tex;

void main(){
	ps_pxClr0 = vec4(texture(unf_tex, ps_in.texCrd).rgba);
}

)";