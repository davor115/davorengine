#ifndef _DAVOR_ENGINE_
#define _DAVOR_ENGINE_
#include <iostream>
#include <list>
#include <vector>

#include "Environment.h"
#include "Entity.h"
#include "Transform.h"
#include "Keyboard.h"
#include "Component.h"
#include <../src/game/TriangleRenderer.h>

class Entity;
class Environment;
class Keyboard;

class Core
{
private:
	std::weak_ptr<Core> self;
	std::shared_ptr<Environment> environment;
	//std::vector<std::shared_ptr<Entity>> entities;
	std::list<std::shared_ptr<Entity>> entities;
	std::shared_ptr<Keyboard> keyboard;
	bool running;

public:
	static std::shared_ptr<Core> initialize();
	void Start();
	void Stop();
	std::shared_ptr<Entity> addEntity();
	// I'm going to create a function that allows me to get all entities in my engine.
	std::list<std::shared_ptr<Entity>> getWorldEntities();

};




#endif