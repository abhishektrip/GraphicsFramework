#include "atRawVolumeLoader.h"
using namespace atRenderEngine;


atRawVolumeLoader::atRawVolumeLoader()
{
}

atRenderEngine::atRawVolumeLoader::atRawVolumeLoader(string filename)
{

}


atRawVolumeLoader::~atRawVolumeLoader()
{
	if (mFileHandle.is_open())
	{
		mFileHandle.close();
	}
}

void atRenderEngine::atRawVolumeLoader::LoadFile(string filename, int height, int width, int depth, char *& buffer)
{
	if (!mFileHandle.is_open())
	{
		LoadFileInternal(filename, height*width*depth, buffer);
	}
}

void atRenderEngine::atRawVolumeLoader::LoadFile(string filename, char *& buffer)
{
	if (!mFileHandle.is_open())
	{
		LoadFileInternal(filename, FILE_SIZE_UNKNOWN, buffer);
	}
}

void atRenderEngine::atRawVolumeLoader::LoadFileInternal(string filename, const int bufferSize, char* &buffer)
{
	streampos size;
	mFileHandle.open(filename, ios::in | ios::binary | ios::ate);
	if (mFileHandle.is_open())
	{
		size = mFileHandle.tellg();
		const int bSize = (size > bufferSize && bufferSize != FILE_SIZE_UNKNOWN) ? bufferSize : size;
		buffer = new char[bSize];
		mFileHandle.seekg(0, mFileHandle.beg);
		mFileHandle.read(buffer, bSize);
		mFileHandle.close();
	}
}
