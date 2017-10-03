#pragma once
#include "atShader.h"
#include "atBox.h"
#include "atQuad.h"

namespace atRenderEngine
{
	namespace Utility
	{
		class atVolumeRenderingShader :
			public atShader
		{
		public:
			atVolumeRenderingShader();
			~atVolumeRenderingShader();
			GLuint VolumeTexture() { return mVolumeTexture; }
			void Setup(atQuad& quad, const char* volume, unsigned int xRange, unsigned int yRange, unsigned int zRange);
			void Draw(std::vector<Vector3f>& vertexArray, std::vector<Vector3f>& colorArray, Matrix4f& MVPMatrix);
			void Draw(atQuad& quad, int numberOfSlices, Matrix4f& viewMatrix, Matrix4f& projectionMatrix);
		private:
			void Setup3DTexture(const char* volume, unsigned int xRange, unsigned int yRange, unsigned int zRange);
			void SetupQuadRendering(atQuad& quad);

			//member variables
			GLuint mVolumeTexture;
			GLuint mVolumeTextureId;
			GLuint mElementbuffer;
			GLuint mVertexArrayID;
			GLuint mVertexBuffer;
			GLuint mUVVertexBuffer;
			GLuint mNormalBuffer;
			GLuint mMatrixID;
			GLuint mViewMatrixID;
			GLuint mModelMatrixID;

			std::vector<unsigned int> indices;
			std::vector<GLfloat> mVertexBufferData;
			atBox mBox;
		};
	}
}