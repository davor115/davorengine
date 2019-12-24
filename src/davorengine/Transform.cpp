#include "Transform.h"
#include <glm/ext.hpp>

void Transform::OnInit()
{
	scale = glm::vec3(1, 1, 1);
}

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

glm::mat4 Transform::getLocalMat()
{
	glm::mat4 mat = glm::mat4(1.0f);
	
	mat = glm::rotate(mat, rotation.x, glm::vec3(1, 0, 0));
	mat = glm::rotate(mat, rotation.y, glm::vec3(0, 1, 0));
	mat = glm::rotate(mat, rotation.z, glm::vec3(0, 0, 1));

	mat = glm::translate(mat, position);

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

glm::vec3 Transform::getPosition()
{
	return position;
}

void Transform::Translate(glm::vec3 _val)
{
	position =  position + _val;
}

glm::vec3 Transform::getRotation()
{
	return rotation;
}

glm::vec3 Transform::getSize()
{
	return scale;
}

glm::vec3 Transform::Forward()
{
	glm::vec3 rtn = rotation * glm::vec3(-0.05f, 0.0f, 0.0f); // This doesn't work.. trying to allow the user to move an object forward in local coordinates.
	return rtn;
}