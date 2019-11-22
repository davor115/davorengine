#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "Camera.h"
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
	entity->self = entity;
	entity->addComponent<Transform>(); // Because every entity should have a transform.
	return entity;
}

void Core::Start()
{
	while(true)
	{
		for (std::list<std::shared_ptr<Entity>>::iterator i = entities.begin(); i != entities.end(); i++)
		{
			std::cout << "Run number: " << *i << std::endl;
			(*i)->Update();
		}

		// TODO: include GL
		//glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
		for (std::list<std::shared_ptr<Entity>>::iterator i = entities.begin(); i != entities.end(); i++)
		{
			std::cout << "Run number: " << *i << std::endl;
			(*i)->Display();
		}
	
		// TODO: Move window to core
		//SDL_GL_SwapWindow(window);
	}
}
