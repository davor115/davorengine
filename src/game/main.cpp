#include <iostream>
#include <memory>
#include "davorengine/Engineincludes.h"

int main()
{

	std::cout << "Hello world!" << std::endl;

	std::shared_ptr<Core> core = Core::initialize();
	
	std::shared_ptr<Entity> gameObject = core->addEntity();
	std::shared_ptr<Entity> gameObject2 = core->addEntity();

	core->Start();
	// Wrong
	//std::shared_ptr<Component> tr = gameObject->addComponent<Component>();

	
	std::weak_ptr<Renderer> tr = gameObject->addComponent<Renderer>();
	std::weak_ptr<Transform> trans = gameObject->addComponent<Transform>();
	gameObject->getComponent<Transform>()->setPosition(glm::vec3(1,1,1));
    
	// We don't need to call these two because by doing core start we are going through Init and Display of each element.
	//tr->OnInit();
	//tr->OnDisplay();

	core->Start(); // Run updates loops, etc.

	return 0;
}
