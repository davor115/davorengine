#include <iostream>
#include <memory>
#include "davorengine/Engineincludes.h"

using namespace davorengine;

int main()
{

	std::cout << "Hello world!" << std::endl;

	std::shared_ptr<Core> core = Core::initialize();
	
	
	std::shared_ptr<Entity> MainCamera = core->addEntity();	
	std::shared_ptr<Entity> map = core->addEntity();
	std::shared_ptr<Entity> player = core->addEntity();

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
	


	// I would like to do:
//	gameObject->getComponent<MeshRenderer>()->LoadObject("C:\\Users\\Davor Larsen\\Desktop\\Github\\davorengine\\src\\davorengine\\share\\rend\\samples\\curuthers\\curuthers.obj");
//	gameObject->getComponent<MeshRenderer>()->LoadTexture("C:\\Users\\Davor Larsen\\Desktop\\Github\\davorengine\\src\\davorengine\\share\\rend\\samples\\curuthers\\Whiskers_diffuse.png");

//	std::shared_ptr<Mesh> m = core->getResources()->load<Mesh>("D:\\Github\\davorengine\\src\\davorengine\\share\\rend\\samples\\curuthers\\curuthers.obj");
	std::shared_ptr<Mesh> m = core->getResources()->load<Mesh>("C:\\Users\\Davor Larsen\\Desktop\\Github\\davorengine\\src\\davorengine\\share\\rend\\samples\\graveyard\\graveyard.obj");
	std::shared_ptr<Material> mat = core->getResources()->load<Material>("C:\\Users\\Davor Larsen\\Desktop\\Github\\davorengine\\src\\davorengine\\share\\rend\\samples\\graveyard\\graveyard.png");
	map->getComponent<MeshRenderer>()->setMesh(m);
	map->getComponent<MeshRenderer>()->setMaterial(mat);

	std::shared_ptr<Mesh> playerMesh = core->getResources()->load<Mesh>("C:\\Users\\Davor Larsen\\Desktop\\Github\\davorengine\\src\\davorengine\\share\\rend\\samples\\curuthers\\curuthers.obj");
	std::shared_ptr<Material> playerMaterial = core->getResources()->load<Material>("C:\\Users\\Davor Larsen\\Desktop\\Github\\davorengine\\src\\davorengine\\share\\rend\\samples\\curuthers\\Whiskers_diffuse.png");

	player->getComponent<MeshRenderer>()->setMesh(playerMesh);
	player->getComponent<MeshRenderer>()->setMaterial(playerMaterial);

	core->Start(); // Run updates loops, etc.

	return 0;
}
