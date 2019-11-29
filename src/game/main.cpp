#include <iostream>
#include <memory>
#include "davorengine/Engineincludes.h"

using namespace davorengine;

int main()
{

	std::cout << "Hello world!" << std::endl;

	std::shared_ptr<Core> core = Core::initialize();
	
	
	std::shared_ptr<Entity> MainCamera = core->addEntity();	
	std::shared_ptr<Entity> gameObject = core->addEntity();

	std::weak_ptr<Camera> cam = MainCamera->addComponent<Camera>();
	std::weak_ptr<MeshRenderer> tr = gameObject->addComponent<MeshRenderer>();
	std::weak_ptr<Transform> trans = gameObject->addComponent<Transform>();
	std::weak_ptr<ShapeMesh> mesh = gameObject->addComponent<ShapeMesh>();
	gameObject->getComponent<Transform>()->setPosition(glm::vec3(0, 0,-5));
	gameObject->getComponent<Transform>()->setRotation(glm::vec3(0, 45, 0));
	
	MainCamera->getComponent<Transform>()->setPosition(glm::vec3(0, 0, 10));

	// I would like to do:
//	gameObject->getComponent<MeshRenderer>()->LoadObject("C:\\Users\\Davor Larsen\\Desktop\\Github\\davorengine\\src\\davorengine\\share\\rend\\samples\\curuthers\\curuthers.obj");
//	gameObject->getComponent<MeshRenderer>()->LoadTexture("C:\\Users\\Davor Larsen\\Desktop\\Github\\davorengine\\src\\davorengine\\share\\rend\\samples\\curuthers\\Whiskers_diffuse.png");

	

	core->Start(); // Run updates loops, etc.

	return 0;
}
