#ifndef _DAVOR_ENGINE_
#define _DAVOR_ENGINE_
#include <iostream>
#include <vector>
#include "Environment.h"
#include "Entity.h"
#include "Keyboard.h"
#include "Component.h"
class Core
{
private:
	std::shared_ptr<Environment> environment;
	std::vector<std::shared_ptr<Entity>> entities;
	std::shared_ptr<Keyboard> keyboard;
	bool running;

public:
	std::shared_ptr<Core> initialize();
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity;
	

	void Print();

};




#endif