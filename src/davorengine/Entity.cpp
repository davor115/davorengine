#include "Entity.h"



void Entity::Update()
{
	for (std::list<std::shared_ptr<Component>>::iterator i = components.begin(); i != components.end(); i++)
	{
		(*i)->OnTick(); // Fixed: Pointer to incomplete class type is not allowed.
	}
}

void Entity::Display()
{
	std::cout << "Displaying entities" << std::endl;
	for (std::list<std::shared_ptr<Component>>::iterator i = components.begin(); i != components.end(); i++)
	{
		(*i)->OnDisplay(); 
	}
}