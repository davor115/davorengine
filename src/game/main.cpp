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
	gameObject->getComponent<Transform>()->setPosition(glm::vec3(0,0,-5));
	gameObject->getComponent<Transform>()->setRotation(glm::vec3(0, 45, 0));
	
	


	core->Start(); // Run updates loops, etc.

	return 0;
}
