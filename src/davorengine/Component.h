#pragma once
#ifndef _COMPONENT_
#define _COMPONENT_
#include <iostream>

class Entity;
class Core;
class Keyboard;
class Environment;
class Transform;
class Camera;
class Resources;

/**
* The Component Class.
*/
class Component
{
private:
	std::weak_ptr<Entity> entity;
	friend class Entity;
public:
	/**
	* \brief Gets the entity the component is attatched to.
	*/
	std::shared_ptr<Entity> getEntity();
	/**
	* \brief Gets the shared pointer to Core.
	*
	* It gets the current Entity and runs the getCore() function. This is because the Entity class has a weak pointer that points towards Core.
	*/
	std::shared_ptr<Core> getCore();
	/**
	* \brief Returns the shared pointer to keyboard.
	*
	* The keyboard was first initialized in Core, this function gets Core and returns the keyboard from there.
	*/
	std::shared_ptr<Keyboard> getKeyboard();
	/**
	* \brief Returns a pointer to Enviroment
	*
	* The Environment class is where deltaTime is created. The pointer to this class is first initialized in Core.
	*/
	std::shared_ptr<Environment> getEnvironment();
	/**
	* \brief Returns the transform component from the current entity.
	*/
	std::shared_ptr<Transform> getTransform();
	/**
	* \brief Start the player jump cycle
	*/
	std::shared_ptr<Camera> getCamera();
	/**
	* \brief Gets Resources from Core.
	*
	* Resources is later used to load objects. It saves them on a list so if the user decides to use an already uploaded model on an entity it
	* won't need to load it again. 
	*/
	std::shared_ptr<Resources> getResources();
	virtual void OnInit(); ///< OnInit() will run once when the component is added onto an entity.
	virtual void OnBegin();
	virtual void OnTick(); ///< OnTick() runs every frame.
	virtual void OnDisplay(); ///< OnDisplay() runs every frame.
	virtual void OnGUI(); ///< OnGUI() will run after every frame, it displays the GUI on the screen.


};


#endif // !_COMPONENT_
