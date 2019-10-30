#pragma once
#ifndef  _TRIANGLE_RENDERER_
#define  _TRIANGLE_RENDERER_

#define WINDOW_WIDTH 640  // Change these to actual variables later...
#define WINDOW_HEIGHT 480

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <exception>

class TriangleRenderer
{

private:
	GLuint programId;
	GLuint positionsVboId;
	GLuint colorsVboId;
	GLuint vboId;
	GLuint vaoId;


public:
	SDL_Window *window;
	TriangleRenderer();
	void OnInit();
	void onDisplay();

	


};

#endif // ! _TRIANGLE_RENDERER_
