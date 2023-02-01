#version 330

in vec3 Color;

uniform vec3 SolidColor = vec3(-1,-1,-1);
uniform int ShouldInvert;

out vec4 Fragment;

void main()
{
	vec3 output = Color;
	Fragment = vec4(Color,1);
	
	if(SolidColor.r != -1.0 && SolidColor.g != -1.0 && SolidColor.b != -1.0)
		output = SolidColor;

	else if(ShouldInvert == 1){
		output = vec3(1.0f,1.0f,1,0f)-output;
	}
	Fragment= vec4(output,1);

	return;
}