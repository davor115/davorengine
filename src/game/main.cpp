#include <iostream>
#include <memory>
#include "davorengine/Engineincludes.h"
#include "davorengine/EngineKeyboard.h"

using namespace davorengine;

struct PlayerControl : public Component
{
	std::shared_ptr<Entity> self;
	void OnTick()
	{
		if (getKeyboard()->getKeyUp(davorengine_DOWN))
		{
			std::cout << "Up!" << std::endl;
		}
		if (getKeyboard()->getKey(davorengine_DOWN))
		{
			std::cout << "Pressed down once" << std::endl;
			self->getComponent<Transform>()->setPosition(glm::vec3(self->getComponent<Transform>()->getPosition().x, self->getComponent<Transform>()->getPosition().y, self->getComponent<Transform>()->getPosition().z + 0.05f));	
		}
		if (getKeyboard()->getKey(davorengine_UP))
		{
			self->getComponent<Transform>()->setPosition(glm::vec3(self->getComponent<Transform>()->getPosition().x, self->getComponent<Transform>()->getPosition().y, self->getComponent<Transform>()->getPosition().z - 0.05f));
		}
		if (getKeyboard()->getKey(davorengine_LEFT))
		{
			self->getComponent<Transform>()->setPosition(glm::vec3(self->getComponent<Transform>()->getPosition().x + 0.05f, self->getComponent<Transform>()->getPosition().y, self->getComponent<Transform>()->getPosition().z));
		}
		if (getKeyboard()->getKey(davorengine_RIGHT))
		{
			self->getComponent<Transform>()->setPosition(glm::vec3(self->getComponent<Transform>()->getPosition().x - 0.05f, self->getComponent<Transform>()->getPosition().y, self->getComponent<Transform>()->getPosition().z));
		}
	}
};


int main()
{

	//TODO: Why does it run so slow?
	//TODO: Note that onInit only should call once when addComponent
	std::cout << "Hello world!" << std::endl;

	std::shared_ptr<Core> core = Core::initialize();
	
	
	std::shared_ptr<Entity> MainCamera = core->addEntity();	
	std::shared_ptr<Entity> map = core->addEntity();
	std::shared_ptr<Entity> player = core->addEntity();
	player->addComponent<PlayerControl>();
	player->getComponent<PlayerControl>()->self = player;

	std::weak_ptr<Camera> cam = MainCamera->addComponent<Camera>(); // Camera
	MainCamera->getComponent<Transform>()->setPosition(glm::vec3(14, 15, 20));
	MainCamera->getComponent<Transform>()->setRotation(glm::vec3(-0.7f, 0.8f, 0.6f)); // y Left right, Z side


	std::weak_ptr<MeshRenderer> mapMeshRenderer = map->addComponent<MeshRenderer>();
	std::weak_ptr<Transform> trans = map->addComponent<Transform>();
	//std::weak_ptr<Mesh> mesh = gameObject->addComponent<Mesh>();
	map->getComponent<Transform>()->setPosition(glm::vec3(0, 0,-5));
	map->getComponent<Transform>()->setRotation(glm::vec3(0, 45, 0));
	
	std::weak_ptr<MeshRenderer> playerMeshRenderer = player->addComponent<MeshRenderer>();
	std::weak_ptr<Transform> pTransform = player->addComponent<Transform>();
	player->getComponent<Transform>()->setPosition(glm::vec3(-16.0f, 3.0f, 5.0f));
	

	// TODO: Visual Studio runs from build directory... so add "../" i.e ../src/davor....

	std::shared_ptr<Mesh> m = core->getResources()->load<Mesh>("../src/davorengine/share/rend/samples/graveyard/graveyard.obj");
	std::shared_ptr<Material> mat = core->getResources()->load<Material>("../src/davorengine/share/rend/samples/graveyard/graveyard.png");
	map->getComponent<MeshRenderer>()->setMesh(m);
	map->getComponent<MeshRenderer>()->setMaterial(mat);
																		
	std::shared_ptr<Mesh> playerMesh = core->getResources()->load<Mesh>("../src/davorengine/share/rend/samples/curuthers/curuthers.obj");
	std::shared_ptr<Material> playerMaterial = core->getResources()->load<Material>("../src/davorengine/share/rend/samples/curuthers/Whiskers_diffuse.png");

	player->getComponent<MeshRenderer>()->setMesh(playerMesh);
	player->getComponent<MeshRenderer>()->setMaterial(playerMaterial);

	
	core->Start(); // Run updates loops, etc.



/*
	while (true)
	{
		if (core->getKeyboard()->getKeyDown(davorengine_DOWN) == true)
		{
			//std::cout << "Yea it found it." << std::endl;
			player->getComponent<Transform>()->setPosition(glm::vec3(player->getComponent<Transform>()->getPosition().x + 0.05f, player->getComponent<Transform>()->getPosition().y, player->getComponent<Transform>()->getPosition().z));
		}
		if (core->getKeyboard()->getKeyDown(davorengine_UP) == true)
		{
			//std::cout << "Yea it found it." << std::endl;
			player->getComponent<Transform>()->setPosition(glm::vec3(player->getComponent<Transform>()->getPosition().x - 0.05f, player->getComponent<Transform>()->getPosition().y, player->getComponent<Transform>()->getPosition().z));
		}
		if (core->getKeyboard()->getKeyDown(davorengine_LEFT) == true)
		{
			//std::cout << "Yea it found it." << std::endl;
			player->getComponent<Transform>()->setPosition(glm::vec3(player->getComponent<Transform>()->getPosition().x, player->getComponent<Transform>()->getPosition().y, player->getComponent<Transform>()->getPosition().z + 0.05));
		}
		if (core->getKeyboard()->getKeyDown(davorengine_RIGHT) == true)
		{
			//std::cout << "Yea it found it." << std::endl;
			player->getComponent<Transform>()->setPosition(glm::vec3(player->getComponent<Transform>()->getPosition().x, player->getComponent<Transform>()->getPosition().y, player->getComponent<Transform>()->getPosition().z - 0.05f));
		}
		core->getKeyboard()->ClearKeys();
	}
*/

	return 0;
}
