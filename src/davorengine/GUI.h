
#include "Component.h"
#include <glm/glm.hpp>
#include <rend/rend.h>

class Material;

class GUI : public Component
{
private:
	std::shared_ptr<rend::Mesh> mesh;
	glm::mat4 projection;
	std::shared_ptr<rend::Shader> shader; // GUI Shader, no lights, vec2, textures.
public:
	void setGUITexture(glm::vec4 position, std::shared_ptr<Material> texture);



};