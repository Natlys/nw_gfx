#shader_type vertex
#version 400 core

layout(location = 0) in vec2 atb_xyCrd;
layout(location = 1) in vec2 atb_texCrd;

layout(std140) uniform unf_Matrices{
	mat4 unf_camProj;
	mat4 unf_camView;
};

out VS_OUT{
	vec2 texCrd;
}vs_out;

uniform mat4 unf_mdlTransform;

void main()
{
	gl_Position = unf_camProj * unf_camView * unf_mdlTransform *
	vec4(atb_xyCrd.xy, 0.0f, 1.0f);
	vs_out.texCrd = atb_texCrd;
}

#shader_type geometry
#version 400 core

layout(triangles)in;
layout(triangle_strip,max_vertices=4)out;

in VS_OUT{
	vec2 texCrd;
}gs_in[];

out VS_OUT{
	vec2 texCrd;
}gs_out;

void main()
{
	gl_Position = vec4(gl_in[0].gl_Position.xyzw);
	gs_out.texCrd = gs_in[0].texCrd;
	EmitVertex();
	gl_Position = vec4(gl_in[1].gl_Position.xyzw);
	gs_out.texCrd = gs_in[1].texCrd;
	EmitVertex();
	gl_Position = vec4(gl_in[2].gl_Position.xyzw);
	gs_out.texCrd = gs_in[2].texCrd;
	EmitVertex();
	gl_Position = vec4(gl_in[0].gl_Position.xyzw) + vec4(gl_in[2].gl_Position.x, 0.0f, 0.0f, 0.0f);
	gs_out.texCrd = gs_in[0].texCrd + gs_in[2].texCrd.x;
	EmitVertex();

	EndPrimitive();
}

#shader_type shader
#version 400 core

out vec4 ps_pxClr;

in VS_OUT{
	vec2 texCrd;
} ps_in;

uniform sampler2D unf_tex;

void main()
{
	ps_pxClr = vec4(texture(unf_tex, ps_in.texCrd).rgba);
}