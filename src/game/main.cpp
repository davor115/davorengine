#include <iostream>
#include <memory>
#include "davorengine/Engineincludes.h"
#include "davorengine/EngineKeyboard.h"

using namespace davorengine;

struct PlayerControl : public Component
{
	int w = 640;
	int h = 480;
	std::shared_ptr<Entity> theCamera;
	std::shared_ptr<Entity> self;
	std::shared_ptr<Entity> dummy;
	void OnTick()
	{
						
		if (getKeyboard()->getKeyUp(davorengine_UP))
		{
			//std::cout << "Up!" << std::endl;
		}
		if (getKeyboard()->getKey(davorengine_DOWN))
		{

			//	self->getComponent<Transform>()->setPosition(glm::vec3(self->getComponent<Transform>()->getPosition().x + 0.05f, self->getComponent<Transform>()->getPosition().y, self->getComponent<Transform>()->getPosition().z));	
			self->getComponent<Transform>()->Translate(glm::vec3(0.05f, 0.0f, 0.0f));
		}
		if (getKeyboard()->getKey(davorengine_UP))
		{
			//	self->getComponent<Transform>()->Translate(glm::vec3(-0.05f, 0.0f, 0.0f));
			//std::cout << "Pressed UP once" << std::endl;
			//self->getComponent<Transform>()->Translate(glm::vec3(-0.05f, 0.0f, 0.0f));
			self->getComponent<Transform>()->Translate(self->getComponent<Transform>()->Forward());
		}
		if (getKeyboard()->getKey(davorengine_LEFT))
		{
			self->getComponent<Transform>()->Translate(glm::vec3(0.0f, 0.0f, 0.05f));
		}
		if (getKeyboard()->getKey(davorengine_RIGHT))
		{
			self->getComponent<Transform>()->Translate(glm::vec3(0.0f, 0.0f, -0.05f));
			
		}
		if (getKeyboard()->getKey(davorengine_W))
		{
			theCamera->getComponent<Transform>()->Translate(glm::vec3(0.0f, 0.05f, 0.0f));
		}
		if (getKeyboard()->getKey(davorengine_S))
		{
			theCamera->getComponent<Transform>()->Translate(glm::vec3(0.0f, -0.05f, 0.0f));
		}
		if (getKeyboard()->getKey(davorengine_A))
		{
			theCamera->getComponent<Transform>()->Rotate(glm::vec3(0.0f, 0.01f, 0.0f));
		}
		if (getKeyboard()->getKey(davorengine_D))
		{
			theCamera->getComponent<Transform>()->Rotate(glm::vec3(0.0f, -0.01f, 0.0f));
		}
		if (self->getComponent<Collision>()->isColliding(dummy->getComponent<Transform>()->getPosition(), dummy->getComponent<Transform>()->getSize()))
		{
			//self->getComponent<Transform>()->setPosition(self->getComponent<Collision>()->getCollisionResponse(dummy->getComponent<Transform>()->getPosition(), dummy->getComponent<Transform>()->getSize()));
			std::cout << "We are colliding against something..." << std::endl;
		}
	}

	void OnGUI()
	{
		
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
	std::shared_ptr<Entity> enemy = core->addEntity();
	std::shared_ptr<Entity> myGUI = core->addEntity();
	
	// Camera:
	std::weak_ptr<Camera> cam = MainCamera->addComponent<Camera>(); // Camera
	MainCamera->getComponent<Transform>()->setPosition(glm::vec3(14, 15, 20));
	MainCamera->getComponent<Transform>()->setRotation(glm::vec3(-0.7f, 0.8f, 0.6f)); // y Left right, Z side   -> -0.7f, 0.8f, 0.6f;

	// Map:
	std::weak_ptr<MeshRenderer> mapMeshRenderer = map->addComponent<MeshRenderer>();
	std::weak_ptr<Transform> trans = map->addComponent<Transform>();
//	std::weak_ptr<Collision> mapCol = map->addComponent<Collision>();
	map->getComponent<Transform>()->setPosition(glm::vec3(0, 0, -5)); // 0, 0, -5
	map->getComponent<Transform>()->setRotation(glm::vec3(0, 45, 0)); // 0 , 45, 0

	// Player:
	player->addComponent<PlayerControl>();
	player->getComponent<PlayerControl>()->self = player;
	player->getComponent<PlayerControl>()->dummy = enemy;
	player->getComponent<PlayerControl>()->theCamera = MainCamera;
	
	std::weak_ptr<Collision> playerCollisionBox = player->addComponent<Collision>();
//	player->getComponent<Collision>()->setSize(glm::vec3(5.0f, 5.0f, 5.0f));
	std::weak_ptr<MeshRenderer> playerMeshRenderer = player->addComponent<MeshRenderer>();
	std::weak_ptr<Transform> pTransform = player->addComponent<Transform>();
	player->getComponent<Transform>()->setPosition(glm::vec3(0.0f, 3.0f, 5.0f)); // -16, 3.0f, 5.0f; actually -> 0.0f, 3.0f, 5.0f;
	player->getComponent<Transform>()->setRotation(glm::vec3(0.0f, 4.2f, 0.0f));
	
	// Enemy:
	std::weak_ptr<Transform> enemyTransform = enemy->addComponent<Transform>();
	std::weak_ptr<Collision> enemyCol = enemy->addComponent<Collision>();
//	enemy->getComponent<Collision>()->setSize(glm::vec3(2.0f, 2.0f, 2.0f));
	std::weak_ptr<MeshRenderer> enemyMeshRenderer = enemy->addComponent<MeshRenderer>();
	enemy->getComponent<Transform>()->setPosition(glm::vec3(-4.0f, 3.0f, -2.0f)); // -4.0f, 3.0f, -2.0f;
//	enemy->getComponent<Transform>()->setRotation(glm::vec3(0.0f, -4.2f, 0.0f));
	enemy->getComponent<Transform>()->setRotation(glm::vec3(0.0f, 0.0f, 0.0f));
	
	
	
	// TODO: Visual Studio runs from build directory... so add "../" i.e ../src/davor....

	std::shared_ptr<Mesh> m = core->getResources()->load<Mesh>("../src/davorengine/share/rend/samples/graveyard/graveyard.obj");
	std::shared_ptr<Material> mat = core->getResources()->load<Material>("../src/davorengine/share/rend/samples/graveyard/graveyard.png");

	map->getComponent<MeshRenderer>()->setMesh(m);
	map->getComponent<MeshRenderer>()->setMaterial(mat);
																		
	std::shared_ptr<Mesh> playerMesh = core->getResources()->load<Mesh>("../src/davorengine/share/rend/samples/curuthers/curuthers.obj");
	std::shared_ptr<Material> playerMaterial = core->getResources()->load<Material>("../src/davorengine/share/rend/samples/curuthers/Whiskers_diffuse.png");


	std::shared_ptr<Mesh> enemyMesh = core->getResources()->load<Mesh>("../src/davorengine/share/rend/samples/davormodel/Davor_Bird_Sprite.obj");
	std::shared_ptr<Material> enemyMaterial = core->getResources()->load<Material>("../src/davorengine/share/rend/samples/davormodel/pollo.png");

	player->getComponent<MeshRenderer>()->setMesh(playerMesh);
	player->getComponent<MeshRenderer>()->setMaterial(playerMaterial);
//	player->getComponent<MeshRenderer>()->setObjNameRend("player"); // If the mesh renderer has a obj name it will use local coordinates. (First rotate then translate)
	
	// Later found that using the other drawing method disables collisions since it's a "fake" draw.
	
	enemy->getComponent<MeshRenderer>()->setMesh(enemyMesh);
	enemy->getComponent<MeshRenderer>()->setMaterial(enemyMaterial);
//	enemy->getComponent<MeshRenderer>()->setObjNameRend("enemy"); // If the mesh renderer has a obj name it will use local coordinates. (First rotate then translate)

	// GUI Stuff:
	
	std::weak_ptr<GUI> gui = myGUI->addComponent<GUI>();
//	std::weak_ptr<MeshRenderer> mGUI = myGUI->addComponent<MeshRenderer>();
	std::shared_ptr<Material> GUIText = core->getResources()->load<Material>("../src/davorengine/share/rend/samples/davormodel/pollo.png");
	std::shared_ptr<Mesh> guiMesh = core->getResources()->load<Mesh>("../src/davorengine/share/rend/samples/davormodel/Davor_Bird_Sprite.obj");
	myGUI->getComponent<GUI>()->setMesh(guiMesh);
	myGUI->getComponent<GUI>()->setGUITexture(glm::vec4(0, 0, 1, 1), GUIText);


	core->Start(); // Run updates loops, etc.


	return 0;
}
