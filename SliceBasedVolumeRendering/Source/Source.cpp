#include <iostream>
#include "atRenderer.h"
using namespace atRenderEngine;

int main()
{
	atRenderer renderer;
	atCamera* camera = new atCamera();
	camera->SetPerspective(Utility::ToRadians(45.0f), 300.0f / 300.0f, 0.1f, 1000.0f);
	camera->SetLookAt(Vector3f(0, 0, -4), Vector3f(0, 0, 0), Vector3f(0, 1, 0));

	renderer.AddCamera(camera);
	renderer.Setup("Marker Generation ", 1920, 1080);

	atVolumeRenderingScene* scene1 = new atVolumeRenderingScene();
	scene1->LoadRawVolume("../data/Volumes/Raw/bonsai.raw", 256, 256, 256);

	//scene1->LoadMesh("../data/EggData/BARREL.DAT", true,true);

	//atScene* scene2 = new atScene();
	//scene2->LoadMesh("../data/EggData/POINT.DAT", false , true);

	//atScene* scene3 = new atScene();
	//scene3->LoadMesh("../data/EggData/END.DAT", false, true);

	renderer.AddScene(scene1);
	renderer.Draw();
	return 1;
}