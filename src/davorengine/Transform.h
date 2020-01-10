
#include "Component.h"
#include <glm/glm.hpp>
class Transform : public Component
{
private:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

public:
	void OnInit();

	glm::mat4 getMat();

	void setPosition(glm::vec3 _pos);
	void setRotation(glm::vec3 _rot);
	void setScale(glm::vec3 _s);
	
	void Translate(glm::vec3 _val);
	void Rotate(glm::vec3 _rotVal);
	glm::vec3 Forward();
	glm::vec3 Left();
	glm::vec3 Right();
	glm::vec3 Up();
	glm::vec3 Down();

	glm::vec3 getPosition();
	glm::vec3 getRotation();
	glm::vec3 getSize();
};
