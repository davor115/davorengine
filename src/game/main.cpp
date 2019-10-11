#include <iostream>
#include <memory>

#include <davorengine/davorengine.h>

int main()
{

	std::cout << "Hello world!" << std::endl;
	std::shared_ptr<Core> core = std::make_shared<Core>();

	core->Print();

	return 0;
}