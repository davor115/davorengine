
#define WINDOW_WIDTH 640  // Change these to actual variables later...
#define WINDOW_HEIGHT 480

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include "Component.h"
#include <rend/rend.h>


class MeshRenderer : public Component
{

private:
	GLuint programId;
	GLuint positionsVboId;
	GLuint colorsVboId;
	GLuint vboId;
	GLuint vaoId;
	std::shared_ptr<rend::Shader> shader;


public:
	SDL_Window *window;
	~MeshRenderer();
	MeshRenderer();
	//void OnInit();
	void OnDisplay();

	


};