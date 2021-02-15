#shader_type vertex
#version 330 core

layout(location = 0) in vec3 atb_vtxCrd;
layout(location = 1) in vec2 atb_texCrd;
layout(location = 2) in vec3 atb_normCrd;

out vec3 vs_vtxCrd;
out vec2 vs_texCrd;
out vec3 vs_normCrd;

uniform mat4 unf_m4TForm;
uniform mat4 unf_m4Proj;
uniform mat4 unf_m4View;

void main()
{
	vs_vtxCrd = vec3(unf_m4TForm * vec4(atb_vtxCrd.xyz, 1.0f));
	vs_texCrd = atb_texCrd;
	vs_normCrd = mat3(transpose(inverse(unf_m4TForm))) * atb_normCrd;

	gl_Position = unf_m4Proj * unf_m4View * vec4(vs_vtxCrd.xyz, 1.0f);
	//gl_Position = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}

#shader_type pixel
#version 330 core

#define MAX_TEXTURES 10

out vec4 ps_pxClr;

in vec3 vs_vtxCrd;
in vec2 vs_texCrd;
in vec3 vs_normCrd;

unniform vec4 unf_albedoClr;
uniform vec3 unf_ambient;
uniform vec3 unf_specular;
uniform float unf_shining;
uniform sampler2D unf_textures[MAX_TEXTURES];

struct DirectLight
{
	vec3 lClr;
	vec3 lDir;
};
struct PointLight {
	vec3 lClr;
	vec3 lCrd;

	float atn_const;
	float atn_linear;
	float atn_quad;
};
struct SpotLight {
	vec3 lClr;
	vec3 lDir;
	vec3 lCrd;

	float atn_const;
	float atn_linear;
	float atn_quad;

	float cutOff_in;
	float cutOff_out;
};
// -- Structures

// --Ligthing Calculation
float GetDiffuseF(vec3 normCrd, vec3 lDir);
float GetSpecularF(vec3 normCrd, vec3 viewDir, vec3 lDir);

vec4 GetAmbientRgba(vec3 lClr);
vec4 GetDiffuseRgba(vec3 normCrd, vec3 lDir, vec3 lClr);
vec4 GetSpecularRgba(vec3 normCrd, vec3 viewDir, vec3 lDir, vec3 lClr);

vec4 GetDirectLighting(DirectLight dtLight, vec3 normCrd, vec3 viewDir);
vec4 GetPointLighting(PointLight ptLight, vec3 normCrd, vec3 viewDir, vec3 vtxCrd);
vec4 GetSpotLighting(SpotLight stLight, vec3 normCrd, vec3 viewDir, vec3 vtxCrd);
// --Ligthing Calculation

// --Uniforms
uniform vec3 unf_viewCrd;

uniform GMaterial mtl_core_3d;

#define MAX_LIGHTS_DIRECT 10
#define MAX_LIGHTS_POINT 10
#define MAX_LIGHTS_SPOT 10

uniform DirectLight directLight[MAX_LIGHTS_DIRECT];
uniform PointLight pointLight[MAX_LIGHTS_POINT];
uniform SpotLight spotLight[MAX_LIGHTS_SPOT];
// --Uniforms

void main()
{
	vec3 viewDir = normalize(unf_viewCrd - vs_vtxCrd);
	
	vec4 lDtClr = vec4(0.0f);
	vec4 lPtClr = vec4(0.0f);
	vec4 lStClr = vec4(0.0f);
	/*
	for (int i = 0; i < MAX_LIGHTS_DIRECT; i++)
	{
		lDtClr += GetDirectLighting(directLight[i], vs_normCrd, viewDir);
	}
	for (int i = 0; i < MAX_LIGHTS_POINT; i++)
	{
		lPtClr += GetPointLighting(pointLight[i], vs_normCrd, viewDir, vs_vtxCrd);
	}
	for (int i = 0; i < MAX_LIGHTS_SPOT; i++)
	{
		lStClr += GetSpotLighting(spotLight[i], vs_normCrd, viewDir, vs_vtxCrd);
	}
	
	ps_pxClr = lDtClr + lPtClr + lStClr;
	*/
	ps_pxClr = vec4(unf_viewCrd.xyz / 100.0f, 1.0f);
}

// -- LightComponents
// The more vectors of light and normCrd are same - the more light is there
float GetDiffuseF(vec3 normCrd, vec3 lDir)
{
	return (max(dot(normCrd, normalize(-lDir)), 0.0f));
}
// The more vectors of light and reflection are same - the more light is there
float GetSpecularF(vec3 normCrd, vec3 viewDir, vec3 lDir)
{
	vec3 reflectDir = reflect(normCrd, normalize(lDir));
	return (pow(max(dot(reflectDir, viewDir), 0.0f), mtl_core_3d.shining));
}

vec4 GetAmbientRgba(vec3 lClr)
{
	vec4 resClr = vec4(0.0f);
	for (int tx = 0; tx < MAX_TEXTURES; tx++)
		resClr += (texture(mtl_core_3d.textures[tx], vs_texCrd).rgba * vec4(lClr.xyz, 1.0f));
	return resClr;
}
vec4 GetDiffuseRgba(vec3 normCrd, vec3 lDir, vec3 lClr)
{
	vec4 resClr = vec4(0.0f);
	for (int tx = 0; tx < MAX_TEXTURES; tx++)
		resClr += (texture(mtl_core_3d.textures[tx], vs_texCrd).rgba *
			GetDiffuseF(normCrd, lDir) * vec4(lClr.xyz, 1.0f));
	return resClr;
}
vec4 GetSpecularRgba(vec3 normCrd, vec3 viewDir, vec3 lDir, vec3 lClr)
{
	vec4 resClr = vec4(0.0f);
	for (int tx = 0; tx < MAX_TEXTURES; tx++)
		resClr += (texture(mtl_core_3d.textures[tx], vs_texCrd).rgba *
			GetSpecularF(normCrd, lDir, viewDir) * vec4(lClr.xyz, 1.0f));
	return resClr;
}
// -- LightComponents

// -- LightSources
vec4 GetDirectLighting(DirectLight lDt, vec3 normCrd, vec3 viewDir)
{
	vec4 ambient = GetAmbientRgba(lDt.lClr);
	vec4 diffuse = GetDiffuseRgba(normCrd, lDt.lDir, lDt.lClr);
	vec4 specular = GetSpecularRgba(normCrd, viewDir, lDt.lDir, lDt.lClr);
	
	return (ambient + diffuse + specular);
}
vec4 GetPointLighting(PointLight lPt, vec3 normCrd, vec3 viewDir, vec3 pxCrd)
{
	vec3 lfDir = normalize(lPt.lCrd - pxCrd);
	
	vec4 ambient = GetAmbientRgba(lPt.lClr);
	vec4 diffuse = GetDiffuseRgba(normCrd, lfDir, lPt.lClr);
	vec4 specular = GetSpecularRgba(normCrd, viewDir, lfDir, lPt.lClr);
	
	return (ambient + diffuse + specular);
}
vec4 GetSpotLighting(SpotLight lSt, vec3 normCrd, vec3 viewDir, vec3 pxCrd)
{
	vec3 lfDir = normalize(lSt.lCrd - pxCrd);

	vec4 ambient = GetAmbientRgba(lSt.lClr);
	vec4 diffuse = GetDiffuseRgba(normCrd, lfDir, lSt.lClr);
	vec4 specular = GetSpecularRgba(normCrd, viewDir, lfDir, lSt.lClr);

	return (ambient + diffuse + specular);
}
// -- LightSources