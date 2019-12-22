

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include "Component.h"
#include <rend/stb_image.h>
#include <string>


class Mesh;
class Material;

class MeshRenderer : public Component
{

private:
	std::string rObjectName;
	GLuint programId;
	GLuint positionsVboId;
	GLuint colorsVboId;
	GLuint vboId;
	GLuint vaoId;
	std::shared_ptr<rend::Shader> shader;
	std::shared_ptr<rend::Buffer> buffer;
	std::shared_ptr<Mesh> shape;
	std::shared_ptr<Material> texture;


public:
	SDL_Window *window;
	MeshRenderer();
	//void OnInit();
	void OnDisplay();
	//void LoadObject(const char* path);
	//void LoadTexture(const char* path);
	void setObjNameRend(std::string _s);
	void setMesh(std::shared_ptr<Mesh> shape);
	void setMaterial(std::shared_ptr<Material> material);

};