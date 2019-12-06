

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include "Component.h"
#include <rend/stb_image.h>



class Mesh;
class Material;

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
	std::shared_ptr<Mesh> shape;
	std::shared_ptr<rend::Texture> texture;


public:
	SDL_Window *window;
	MeshRenderer();
	//void OnInit();
	void OnDisplay();
	//void LoadObject(const char* path);
	//void LoadTexture(const char* path);

	void setMesh(std::shared_ptr<Mesh> shape);
	void setMaterial(std::shared_ptr<Material> material);

};