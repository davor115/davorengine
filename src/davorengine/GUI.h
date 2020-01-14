
#include "Component.h"
#include <glm/glm.hpp>
#include <rend/rend.h>

class Material;
class Mesh;

class GUI : public Component
{
private:
	std::shared_ptr<rend::Context> context;
	std::shared_ptr<Entity> myGUI; // Check if this is the right way of doing it..
	std::shared_ptr<Mesh> shape;
	glm::mat4 projection;
	std::shared_ptr<rend::Shader> shader; // GUI Shader, no lights, vec2, textures.
	std::shared_ptr<rend::Buffer> buffer;
	
	std::shared_ptr<Material> material;
public:
	GUI(std::shared_ptr<Core> _core);
	void setGUITexture(glm::vec4 position, std::shared_ptr<Material> texture);
	void setMesh(std::shared_ptr<Mesh> _set);
	void OnInit();

};