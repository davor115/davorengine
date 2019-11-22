

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
	std::shared_ptr<rend::Buffer> buffer;
	std::shared_ptr<rend::Mesh> shape;


public:
	SDL_Window *window;
	MeshRenderer();
	//void OnInit();
	void OnDisplay();

	


};