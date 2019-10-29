#include <iostream>
#include <memory>
#include <davorengine/Core.h>

int main()
{

	std::cout << "Hello world!" << std::endl;

	std::shared_ptr<Core> core = Core::initialize();
	
	std::shared_ptr<Entity> gameObject = core->addEntity();
	std::shared_ptr<Entity> gameObject2 = core->addEntity();

	core->Start();
	//std::shared_ptr<TriangleRenderer> tr = gameObject->addComponent<TriangleRenderer>();


	return 0;
}