#include "Core.h"
#include "Entity.h"

std::shared_ptr<Core> Core::initialize()
{
	// Initialize the game engine.
	std::cout << "Game engine initialized" << std::endl;
	std::shared_ptr<Core> rtn = std::make_shared<Core>();
	rtn->self = rtn;
	return rtn;
}

std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entities.push_back(entity);
	return entity;
}

void Core::Start()
{
	
	for (std::list<std::shared_ptr<Entity>>::iterator i = entities.begin(); i != entities.end(); i++)
	{
		std::cout << "Run number: " << *i << std::endl;
		(*i)->Update();
	}
	
	for (std::list<std::shared_ptr<Entity>>::iterator i = entities.begin(); i != entities.end(); i++)
	{
		std::cout << "Run number: " << *i << std::endl;
		(*i)->Display();
	}
	
}
