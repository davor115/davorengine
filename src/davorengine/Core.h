#include <iostream>
#include <list>
#include <vector>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <rend/rend.h>

#define WINDOW_WIDTH 1024  // Change these to actual variables later... 640, 480
#define WINDOW_HEIGHT 768


class Entity;
class Environment;
class Keyboard;
class Camera;
class Resources;
class Keyboard;
class Collision;
class GUI;
class Core
{
private:
	friend class Camera; ///< Allows the Camera class to access Core's member variables and functions.
	friend class Collision; ///< Allows the Collision class to access Core's member variables and functions.
	friend class GUI; ///< Allows the Collision class to access Core's member variables and functions.
	std::shared_ptr<GUI> Gui; ///< The GUI used in the scene.
	std::shared_ptr<rend::Context> context; ///< The context is used to create Mesh, a Texture, a Shader, etc.
	std::weak_ptr<Core> self;	///< A pointer to Core to reference itself.
	std::weak_ptr<Camera> currentCamera; ///< The current Camera in the world.
	std::list<std::shared_ptr<Collision>> collidersInWorld; ///< List of all the entities with colliders in the world.
	std::shared_ptr<Resources> resources; ///< The main Resources shared pointer.
	std::shared_ptr<Environment> environment; ///< The main Environment shared pointer.
	std::list<std::shared_ptr<Entity>> entities; ///< List of all the entities created.
	std::shared_ptr<Keyboard> keyboard; ///< The Keyboard for the user.
	bool running;

public:
	SDL_Window *window; ///< An SDL window that represents the screen, given a width and height.
	 /**
	* \brief Initializes Core, Keyboard, Resources, Environment, the SDL Window, Context and GUI.
	*/
	static std::shared_ptr<Core> initialize(); 
	void Start();
	/**
	* \brief Adds an entity.
	*
	* The function AddEntity creates a new shared pointer to Entity, saves it on the entities list, 
	* adds a transform component to it and returns it.
	*/
	std::shared_ptr<Entity> addEntity();
	/**
	* \brief Returns the current camera.
	*/
	std::shared_ptr<Camera> getCurrentCamera();
	/**
	* \brief Returns the Context
	*/
	std::shared_ptr<rend::Context> getContext();
	/**
	* \brief Returns the Resources pointer.
	*/
	std::shared_ptr<Resources> getResources();
	std::shared_ptr<Environment> getEnvironment(); ///< Returns the Environment.
	std::shared_ptr<Keyboard> getKeyboard(); ///< Returns the keyboard.
	std::list<std::shared_ptr<Collision>> getCollidersInWorld(); ///< List of all the objects with box colliders in the scene.
	std::shared_ptr<GUI> getGUI(); ///< Returns the GUI.
	
	~Core();
	
};