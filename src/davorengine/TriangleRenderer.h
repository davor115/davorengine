#pragma once
#ifndef  _TRIANGLE_RENDERER_
#define  _TRIANGLE_RENDERER_

#include <GL/glew.h>

class TriangleRenderer
{

private:
	GLuint programId;
	GLuint vboId;
	GLuint vaoId;


public:
	~TriangleRenderer();
	void OnInit();
	void onDisplay();
	


};

#endif // ! _TRIANGLE_RENDERER_
