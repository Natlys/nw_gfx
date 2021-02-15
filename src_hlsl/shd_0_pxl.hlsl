//#shader_type pixel
// 13d:02m:2021y_7:17 - my first pixel shader in the high-level-shading-language
// output is four component color rgba
// after the function follows render target sematic
// arguments are optional
float4 main() : SV_Target
{
	return float4(0.3f, 0.4f, 1.0f, 1.0f);
}