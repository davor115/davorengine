#pragma once
#ifndef _COMPONENT_
#define _COMPONENT_
#include <iostream>

class Entity;
class Core;
class Keyboard;
class Environment;
class Transform;


class Component
{
private:
	std::weak_ptr<Entity> entity;

public:
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Core> getCore();
	std::shared_ptr<Keyboard> getKeyboard();
	std::shared_ptr<Environment> getEnvironment();
	std::shared_ptr<Transform> getTransform(); // empty
	virtual void OnInit();
	virtual void OnBegin();
	virtual void OnTick();
	virtual void OnDisplay();


};


#endif // !_COMPONENT_
