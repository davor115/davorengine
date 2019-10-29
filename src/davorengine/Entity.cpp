#include "Entity.h"



void Entity::Update()
{
	for (std::list<std::shared_ptr<Component>>::iterator i = components.begin(); i != components.end(); i++)
	{
		(*i)->OnTick(); // Pointer to incomplete class type is not allowed.
	}
}