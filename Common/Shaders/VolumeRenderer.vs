#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 vertexUV;
layout(location = 2) in vec3 vertexNormal_modelspace;

// Output data ; will be interpolated for each fragment.
out vec4 emissiveColor;
out vec3 texCoord3d;

// Values that stay constant for the whole mesh.
uniform mat4 MVP;
uniform mat4 V;
uniform mat4 M;
uniform int sliceNumber;
uniform float totalSlices;

void main(){	

	// Output position of the vertex, in clip space : MVP * position
	//gl_Position =  MVP * vec4(vertexPosition_modelspace,1);
	gl_Position = MVP * vec4(vertexPosition_modelspace.x,vertexPosition_modelspace.y,totalSlices,1);
	texCoord3d = vec3(vertexUV.x, vertexUV.y, totalSlices);
	// The color of each vertex will be interpolated
	// to produce the color of each fragment
	emissiveColor = vec4(1,0,0,1);
}