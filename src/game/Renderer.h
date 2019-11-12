
#define WINDOW_WIDTH 640  // Change these to actual variables later...
#define WINDOW_HEIGHT 480

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <exception>
#include <davorengine/Component.h>

#include "davorengine/Entity.h"
#include "davorengine/Transform.h"

class Renderer : public Component
{

private:
	GLuint programId;
	GLuint positionsVboId;
	GLuint colorsVboId;
	GLuint vboId;
	GLuint vaoId;
	


public:
	SDL_Window *window;
	~Renderer();
	Renderer();
	//void OnInit();
	void OnDisplay();

	


};