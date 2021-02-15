//#shader_type vertex
// 13d:02m:2021y_6:50 - my first shader in high_level_shading_language
// {return type} main({arg type} : {semantic}) : {semantic}
// SV_Position - system value position
// The bare minimum for rendering is vertex positions for rasterizing
float4 main(float2 vtxCrd : coord) : SV_Position
{
	return float4(vtxCrd.x, vtxCrd.y, 0.0f, 1.0f);
}