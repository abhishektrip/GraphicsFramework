#include "atVolumeRenderingScene.h"
using namespace atRenderEngine;


atVolumeRenderingScene::atVolumeRenderingScene()
{
}


atVolumeRenderingScene::~atVolumeRenderingScene()
{
}

void atRenderEngine::atVolumeRenderingScene::LoadRawVolume(std::string path, unsigned int xRange, unsigned int yRange, unsigned int zRange)
{
	char* buffer;
	char* rgbaBuffer;
	mRawVolumeLoader.LoadFile(path, xRange, yRange, zRange, buffer);
	
	Utility::convertToRGBA(rgbaBuffer, buffer, xRange*yRange*zRange);

	if (rgbaBuffer != nullptr)
	{
		mVRShader.Setup(mSliceQuad, rgbaBuffer, xRange, yRange, zRange);
		mSlices = zRange;
	}

	delete[] rgbaBuffer;
	delete[] buffer;
	Setup();
}

void atVolumeRenderingScene::Setup()
{
	mProgramID = mVRShader.mProgramId;
}

void atVolumeRenderingScene::Draw(Matrix4f& viewMatrix, Matrix4f& projectionMatrix)
{
	// Enable blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Disable lighting
	glDisable(GL_LIGHTING);
	
	//Disable Depth Test
	//glDisable(GL_DEPTH_TEST);
	glDepthMask(0);
	mVRShader.Draw(mSliceQuad, mSlices, viewMatrix, projectionMatrix);

	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
	//glEnable(GL_DEPTH_TEST);
	glDepthMask(1);
}
