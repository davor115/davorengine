#include "Transform.h"
#include <glm/ext.hpp>
glm::mat4 Transform::getMat()
{
	glm::mat4 mat = glm::mat4(1.0f);

	mat = glm::translate(mat, position);

	mat = glm::rotate(mat, rotation.x, glm::vec3(1, 0, 0));
	mat = glm::rotate(mat, rotation.y, glm::vec3(0, 1, 0));
	mat = glm::rotate(mat, rotation.z, glm::vec3(0, 0, 1));
	
	mat = glm::scale(mat, scale);

	return mat;
}

void Transform::setPosition(glm::vec3 _pos)
{
	position = _pos;
}

void Transform::setRotation(glm::vec3 _rot)
{
	rotation = _rot;
}

void Transform::setScale(glm::vec3 _s)
{
	scale = _s;
}