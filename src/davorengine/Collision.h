
#include "Component.h"

#include "glm/glm.hpp"

class Collision : public Component
{
private:
	std::shared_ptr<Entity> self;
	glm::vec3 size;
	glm::vec3 position;
	glm::vec3 offset; // If you don't want to have the box collider in the center of the object, add an offset.

public:
	void OnTick();
	void OnInit();
	bool OnCollisionEnter(std::shared_ptr<Collision> other);
	bool isColliding(glm::vec3 _position, glm::vec3 _size);
	glm::vec3 getCollisionResponse(glm::vec3 _position, glm::vec3 _size);

	void CollisionChecker();

	void setSize(glm::vec3 _size);
	void setOffset(glm::vec3 _offset);



};