#version 460 core
// iput;
layout(location = 0)in vec3 vsi_vtx_crd;
layout(location = 1)in vec2 vsi_txr_crd;
layout(location = 2)in vec3 vsi_nrm_crd;
layout(std140)uniform cam_tform{mat4 cam_modl;mat4 cam_view;mat4 cam_proj;};
layout(std140)uniform obj_tform{mat4 obj_modl;};
// oput;
out VS_INFO{vec4 vtx_crd;vec2 txr_crd;vec3 nrm_crd;}vso;
// functions;
void main()
{
	gl_Position =
		cam_proj *
		cam_view *
		obj_modl *
		vec4(vsi_vtx_crd.xyz, 1.0f);

	vso.vtx_crd = gl_Position;
	vso.txr_crd = vsi_txr_crd;
	vso.nrm_crd.x = clamp(vsi_nrm_crd.x, 0.1f, 0.5f);
	vso.nrm_crd.y = clamp(vsi_nrm_crd.y, 0.2f, 0.5f);
	vso.nrm_crd.z = clamp(vsi_nrm_crd.z, 0.3f, 0.5f);
}
