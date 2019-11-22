#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "Camera.h"
std::shared_ptr<Core> Core::initialize()
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}

	
	// Initialize the game engine.
	std::cout << "Game engine initialized" << std::endl;
	std::shared_ptr<Core> rtn = std::make_shared<Core>();
	rtn->self = rtn;
	rtn->window = SDL_CreateWindow("DavorEngine",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(rtn->window))
	{
		throw std::exception();
	}

	if (glewInit() != GLEW_OK)
	{
		throw std::exception();
	}


	return rtn;
}


Core::~Core()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entities.push_back(entity);
	entity->self = entity;
	entity->core = self;
	entity->addComponent<Transform>(); // Because every entity should have a transform.
	return entity;
}

std::shared_ptr<Camera> Core::getCurrentCamera()
{
	return currentCamera.lock();
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
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
		for (std::list<std::shared_ptr<Entity>>::iterator i = entities.begin(); i != entities.end(); i++)
		{
			std::cout << "Run number: " << *i << std::endl;
			(*i)->Display();
		}
	
		// TODO: Move window to core
		SDL_GL_SwapWindow(window);
	}
}
