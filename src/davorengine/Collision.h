
#include "Component.h"

#include "glm/glm.hpp"
/**
* Check for collisions.
*/

class Collision : public Component
{
private:
	std::shared_ptr<Entity> self; ///< A shared pointer to point to Entity. Useful if the user wants to get the entity where this component is attatched to.
	glm::vec3 size; ///< Collider size.
	glm::vec3 position; ///< Collider's position.
	bool unmovable; ///< If an object is unmovable set to true, else set to false.


public:
	void OnTick(); ///< OnTick() runs every frame, here it runs the function that dectects collisions.
	void OnInit(); ///< OnInit() runs once, when the component is added to the entity.
	 /**
	* \brief Check if an object is colliding with another object. 
	*
	* The function takes two parameters, the other object's position and size.
	*/
	bool isColliding(glm::vec3 _position, glm::vec3 _size);
	/**
	* \brief Get the collision response from the isColliding() function.
	*
	* If a collision was detected, the movable objects get pushed back in the opposite direction of the object they collided with.
	*/
	glm::vec3 getCollisionResponse(glm::vec3 _position, glm::vec3 _size);
	/**
	* \brief Checks for collision against all the entities attatched.
	*
	* CollisionChecker() Runs through all the entities in the world with a collider attatched, and sends the position and size of them through the getCollisionResponse() function.
	*/
	void CollisionChecker(); ///< Checks for collision against all the entities attatched.

	void setSize(glm::vec3 _size); ///< Sets the size of the collider
	//void setOffset(glm::vec3 _offset);
	void setBoxColliderPosition(glm::vec3 _pos); ///< If the user doesn't want the box collider in the center of the object, add a different position.
	 /**
	* \brief This function takes a parameter to set whether the entity will be unmovable or not.
	*
	* If unmovable is set to false, the entity with keyboard input will be able to push other entities (with the boolean on false) in the incoming direction.
	* If unmovable is set to true on the entity the user collides against, it will be pushed back when colliding with another entity of unmovable set to true.
	*/
	void setUnmovable(bool _v);
};