#include "atBox.h"
using namespace atRenderEngine;


atBox::atBox()
{
	// Create a unit 3d cube
	// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
	// A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles.

	const int CUBE_FACES = 6;
	const int CUBE_TRIANGLES = CUBE_FACES * 2;
	const int VERTICES_PER_TRIANGLE = 3;
	const int UNIQUE_VERTICES_PER_CUBE = 8;

	ReadObjFile("../Common/StandardShapes/Cube.obj");
}


atBox::~atBox()
{
}
