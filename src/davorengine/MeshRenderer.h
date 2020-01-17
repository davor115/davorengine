

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include "Component.h"
#include <rend/stb_image.h>
#include <string>

	/**
	* \brief MeshRenderer Display, Fragment Shader, Vertex Shader...
	*/

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
	std::shared_ptr<Material> texture;

public:
	SDL_Window *window;
	/**
	* \brief Initializes the Mesh Renderer Class
	*
	* Gets the current Context from Core, a shader is created and the vertex & fragment shader parsed into it.
	*/
	void OnInit();
	/**
	* \brief On every frame, applies the matrices onto the entities in the world.
	*/
	void OnDisplay();
	void setMesh(std::shared_ptr<Mesh> shape); ///< Sets the Mesh
	void setMaterial(std::shared_ptr<Material> material); ///< Sets the Material

};