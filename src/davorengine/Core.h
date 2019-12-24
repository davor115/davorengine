#include <iostream>
#include <list>
#include <vector>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <rend/rend.h>

#define WINDOW_WIDTH 640  // Change these to actual variables later...
#define WINDOW_HEIGHT 480


class Entity;
class Environment;
class Keyboard;
class Camera;
class Resources;
class Keyboard;
class Collision;
class Core
{
private:
	friend class Camera;
	friend class Collision;
	std::shared_ptr<rend::Context> context;
	std::weak_ptr<Core> self;	
	std::weak_ptr<Camera> currentCamera;
	std::shared_ptr<Resources> resources;
	std::shared_ptr<Environment> environment;
	//std::vector<std::shared_ptr<Entity>> entities;
	std::list<std::shared_ptr<Entity>> entities;
	std::shared_ptr<Keyboard> keyboard;
	bool running;

public:
	SDL_Window *window;
	static std::shared_ptr<Core> initialize();
	void Start();
	void Stop();
	std::shared_ptr<Entity> addEntity();
	std::shared_ptr<Camera> getCurrentCamera();
	std::shared_ptr<rend::Context> getContext();
	std::shared_ptr<Resources> getResources();
	std::shared_ptr<Keyboard> getKeyboard();
	~Core();
	
};