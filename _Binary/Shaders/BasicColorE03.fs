#version 330

in vec3 Color;

uniform vec3 SolidColor = vec3(-1,-1,-1);
//uniform bool ShouldInvert = false;

out vec4 Fragment;

void main()
{
	vec3 output = Color;
	
	
	if(SolidColor.r != -1.0 && SolidColor.g != -1.0 && SolidColor.b != -1.0){
		output = SolidColor;}
	
	// if(ShouldInvert)
	// {
	// 	output = vec3(1,1,1) - output;
	// }

	Fragment = vec4(output,1);
	return;
}