#version 330 core

// Interpolated values from the vertex shaders
in vec4 emissiveColor;
in vec3 texCoord3d;

// Ouput data
out vec4 color;
uniform sampler3D VolumeTex;

void main(){

	// Output color = color specified in the vertex shader, 
	// interpolated between all 3 surrounding vertices
	//color = vec4(1,0,0,1);
	color = texture(VolumeTex, texCoord3d);  // Read 3D data texture
	//if(intensity > 1)
		//color = vec4(1,0,0,0);
	//if(intensity < 1)
		//color = vec4(0,1,0,0);
	//color =  emissiveColor * a.x;           // Multiply color by opacityvec4(1,0,0,1);

}