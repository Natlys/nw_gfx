#shader_type vertex
#version 400 core

layout(location = 0) in vec3 atb_vtxCrd;

void main()
{
	gl_Position = vec4(atb_vtxCrd.xyz, 1.0f);
}

#shader_type geometry
layout(triangles) in;
layout(triangles_strip, max_vertices = 4)

void main()
{
	gl_Position = gl_in[0].gl_Position;
	EmitVertex();
	gl_Position = gl_in[1].gl_Position;
	EmitVertex();
	gl_Position = gl_in[2].gl_Position;
	EmitVertex();
	gl_Position = vec4(gl_in[2].gl_Position.x, gl_in[0].gl_Position.y, gl_in[2].gl_Position.z, gl_in[2].gl_Position.w);

	EndPrimitive();
}


#shader_type pixel
#version 400 core

out vec4 ps_pxClr;

void main()
{
	ps_pxClr = vec4(1.0f, 1.0f, 0.0f, 1.0f);
}