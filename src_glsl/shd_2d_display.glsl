#shader_type vertex
#version 400 core

layout(location = 0) in vec2 atb_vtxCrd;
layout(location = 1) in vec2 atb_texCrd;

out VS_OUT {
	vec2 texCrd;
} vs_out;

void main()
{
	gl_Position = vec4(atb_vtxCrd.x, atb_vtxCrd.y, 0.0f, 1.0f);
	
	vs_out.texCrd = atb_texCrd;
}

#shader_type geometry
#version 400 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

in VS_OUT {
	vec2 texCrd;
	float texSlot;
} gs_in[];

out VS_OUT {
	vec2 texCrd;
	float texSlot;
} gs_out;

void main()
{
	gl_Position = gl_in[0].gl_Position;
	gs_out.texCrd = gs_in[0].texCrd;
	gs_out.texSlot = gs_in[0].texSlot;
	EmitVertex();
	gl_Position = gl_in[1].gl_Position;
	gs_out.texCrd = gs_in[1].texCrd;
	gs_out.texSlot = gs_in[1].texSlot;
	EmitVertex();
	gl_Position = gl_in[2].gl_Position;
	gs_out.texCrd = gs_in[2].texCrd;
	gs_out.texSlot = gs_in[2].texSlot;
	EmitVertex();

	EndPrimitive();
}

#shader_type pixel
#version 400 core

out vec4 ps_pxClr;

in VS_OUT {
	vec2 texCrd;
} ps_in;

uniform sampler2D tex_img;

void main()
{
	ps_pxClr = vec4(texture(tex_img, ps_in.texCrd).rgba);
}