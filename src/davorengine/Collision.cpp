#include "Collision.h"
#include "Transform.h"
#include "Core.h"
#include "Entity.h"
#include <list>
void Collision::OnInit()
{
	size = getEntity()->getComponent<Transform>()->getSize();
	offset = glm::vec3(0.0f);

	getCore()->collidersInWorld.push_back(getEntity()->getComponent<Collision>()); // Add current collider into the list of all colliders.

}

void Collision::OnTick()
{
	position = getTransform()->getPosition(); // Save the current position.
	CollisionChecker();
}

void Collision::CollisionChecker()
{
	for (std::list<std::shared_ptr<Collision>>::iterator it = getCore()->collidersInWorld.begin(); it != getCore()->collidersInWorld.end(); it++)
	{
		if (*it == getEntity()->getComponent<Collision>())
		{
			continue; // Avoid collision against itself.			
		}

		glm::vec3 moveBack = getCollisionResponse((*it)->getTransform()->getPosition(), (*it)->getTransform()->getSize());
		getEntity()->getComponent<Transform>()->setPosition(moveBack);
		

	}
}

bool Collision::isColliding(glm::vec3 _position, glm::vec3 _size)
{
	// AABB -> Top left position -> Position
	//		-> Bottom right-> Position + size.
	/*
	glm::vec3 topLeft = position;
	glm::vec3 bottomRight = position + size;
	bool itCollidesX = false;
	bool itCollidesY = false;

	if (bottomRight.x >= _position.x)
	{
		if (_position.x + _size.x >= topLeft.x)
		{
			itCollidesX = true;
		}
	}

	if (bottomRight.y >= _position.y)
	{
		if (_position.y + _size.y >= topLeft.y)
		{
			itCollidesY = true;
		}
	}
	if (itCollidesX && itCollidesY)
	{
		return true;
	}
	else
	{
		return false;
	}*/

	if (position.x > _position.x) // a right of b
	{
		if (position.x - size.x > _position.x + _size.x) // left edge of a greater than right edge of b (not colliding)
		{
			return false;
		}
	}
	else
	{
		if (_position.x - _size.x > position.x + size.x)
		{
			return false;
		}
	}

	if (position.z > _position.z) // a front of b
	{
		if (position.z - size.z > _position.z + _size.z) // back edge of a greater than front edge of b (not colliding)
		{
			return false;
		}
	}
	else
	{
		if (_position.z - _size.z > position.z + size.z)
		{
			return false;
		}
	}

	if (position.y > _position.y) // a above b
	{
		if (position.y - size.y > _position.y + _size.y) // bottom edge of a greater than top edge of b (not colliding)
		{
			return false;
		}
	}
	else
	{
		if (_position.y - _size.y > position.y + size.y)
		{
			return false;
		}
	}

	return true;
}



glm::vec3 Collision::getCollisionResponse(glm::vec3 _position, glm::vec3 _size)
{
	float amount = 0.1f;
	float step = 0.1f;
	while (true)
	{
		if (!isColliding(_position, _size)) break;
		position.x += amount;
		if (!isColliding(_position, _size)) break;
		position.x -= amount;
		position.x -= amount;
		if (!isColliding(_position, _size)) break;
		position.x += amount;
		position.z += amount;
		if (!isColliding(_position, _size)) break;
		position.z -= amount;
		position.z -= amount;
		if (!isColliding(_position, _size)) break;
		position.z += amount;
		position.y += amount;
		if (!isColliding(_position, _size)) break;
		position.y -= amount;
		position.y -= amount;
		if (!isColliding(_position, _size)) break;
		position.y += amount;
		amount += step;
	}
	return position;
}


void Collision::setOffset(glm::vec3 _offset)
{
	offset = _offset;
}

void Collision::setSize(glm::vec3 _size)
{
	size = _size;
}
