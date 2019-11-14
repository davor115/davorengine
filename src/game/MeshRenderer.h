
#define WINDOW_WIDTH 640  // Change these to actual variables later...
#define WINDOW_HEIGHT 480

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <exception>
#include <davorengine/Component.h>

#include "davorengine/Entity.h"
#include "davorengine/Engineincludes.h"
#include "davorengine/Transform.h"

class MeshRenderer : public Component
{

private:
	GLuint programId;
	GLuint positionsVboId;
	GLuint colorsVboId;
	GLuint vboId;
	GLuint vaoId;
	


public:
	SDL_Window *window;
	~MeshRenderer();
	MeshRenderer();
	//void OnInit();
	void OnDisplay();

	


};