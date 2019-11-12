
#include "Component.h"
#include <glm/glm.hpp>
class Transform : public Component
{
private:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	

public:
	glm::mat4 getMat();
	void setPosition(glm::vec3 _pos);
	void setRotation(glm::vec3 _rot);
	void setScale(glm::vec3 _s);
};
