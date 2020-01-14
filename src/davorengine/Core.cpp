#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "Camera.h"
#include "Resources.h"
#include "Keyboard.h"
#include "Environment.h"
#include "GUI.h"
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

  rtn->resources = std::make_shared<Resources>();
  rtn->resources->core = rtn->self;
  rtn->keyboard = std::make_shared<Keyboard>(); // Set the keyboard first.
  rtn->environment = std::make_shared<Environment>();
  
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

  rtn->context = rend::Context::initialize();
  rtn->Gui = std::make_shared<GUI>(rtn);
  rtn->environment->lastTime = SDL_GetTicks();
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

std::list<std::shared_ptr<Collision>> Core::getCollidersInWorld()
{
	return collidersInWorld;
}

std::shared_ptr<Keyboard> Core::getKeyboard()
{
  return keyboard;
}

void Core::Start()
{
  bool quit = false;

  while(!quit)
  {
    SDL_Event event = {0};

    while (SDL_PollEvent(&event) != 0)
    {
      if (event.type == SDL_QUIT)
      {
        quit = true;
      }
      else if(event.type == SDL_KEYDOWN)
      {
	// TODO: also push to pressed Keys
        keyboard->keys.push_back(event.key.keysym.sym);
		keyboard->pressedKeys.push_back(event.key.keysym.sym);
      }
      else if(event.type == SDL_KEYUP)
      {
	// TODO: also push to released Keys
		keyboard->releasedKeys.push_back(event.key.keysym.sym);

        for(std::vector<int>::iterator i = keyboard->keys.begin(); i != keyboard->keys.end();)
        {
          if(*i == event.key.keysym.sym)
          {
            i = keyboard->keys.erase(i);
          }
          else
          {
            i++;
          }
        }
      }
    }
    for (std::list<std::shared_ptr<Entity>>::iterator i = entities.begin(); i != entities.end(); i++)
    {
      //std::cout << "Run number: " << *i << std::endl;
      (*i)->Update();
    }
    // TODO: Clear pressedKeys and releasedKeys
	keyboard->pressedKeys.clear();
	keyboard->releasedKeys.clear();

    // TODO: include GL
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (std::list<std::shared_ptr<Entity>>::iterator i = entities.begin(); i != entities.end(); i++)
    {
      //std::cout << "Run number: " << *i << std::endl;
      (*i)->Display();
    }
	glClear(GL_DEPTH_BUFFER_BIT);
	for (std::list<std::shared_ptr<Entity>>::iterator i = entities.begin(); i != entities.end(); i++)
	{
		//std::cout << "Run number: " << *i << std::endl;
		(*i)->Gui();
	}

    SDL_GL_SwapWindow(window);

  }
}


std::shared_ptr<rend::Context> Core::getContext()
{
  return context;
}

std::shared_ptr<Resources> Core::getResources()
{
  return resources;
}

std::shared_ptr<Environment> Core::getEnvironment()
{
	
	return environment;
}

std::shared_ptr<GUI> Core::getGUI()
{
	return Gui;
}