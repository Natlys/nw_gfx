#version 460 core
// iput;
layout(location = 0) in vec3 vsi_vtx_crd;
layout(std140)uniform cst_transform{mat4 cam_modl;mat4 cam_view;mat4 cam_proj;};
// oput;
out VS_INFO{vec3 txr_crd;}vso;
// functions;
void main()
{
	mat4 cam_no_move_view = mat4(mat3(cam_view));

	gl_Position =
		cam_proj *
		cam_no_move_view *
		vec4(vsi_vtx_crd.xyz, 1.0f);
	
	gl_Position = gl_Position.xyww;

	vso.txr_crd = vsi_vtx_crd;
}