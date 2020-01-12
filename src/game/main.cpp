#include <iostream>
#include <memory>
#include "davorengine/Engineincludes.h"
#include "davorengine/EngineKeyboard.h"

using namespace davorengine;

struct PlayerControl : public Component
{
	bool isActive = false;
	int w = 640;
	int h = 480;
	std::shared_ptr<Entity> theCamera;
	std::shared_ptr<Entity> self;
	std::shared_ptr<Entity> dummy;
	std::shared_ptr<Entity> env;
	std::shared_ptr<Entity> platButton;

	std::shared_ptr<Material> theCameraTexture;
	std::shared_ptr<Mesh> guiMesh;
	void OnInit()
	{
		theCameraTexture = getCore()->getResources()->load<Material>("../src/davorengine/share/rend/samples/davormodel/pollo.png");
		guiMesh = getCore()->getResources()->load<Mesh>("../src/davorengine/share/rend/samples/davormodel/Davor_Bird_Sprite.obj");
	}

	void OnTick()
	{
						
		if (getKeyboard()->getKeyUp(davorengine_UP))
		{
			//std::cout << "Up!" << std::endl;
		}
		if (getKeyboard()->getKey(davorengine_DOWN))
		{

			//	self->getComponent<Transform>()->setPosition(glm::vec3(self->getComponent<Transform>()->getPosition().x + 0.05f, self->getComponent<Transform>()->getPosition().y, self->getComponent<Transform>()->getPosition().z));	
			//self->getComponent<Transform>()->Translate(glm::vec3(0.05f, 0.0f, 0.0f));
			//self->getComponent<Transform>()->Translate(-self->getComponent<Transform>()->Forward() * env->getCore()->getEnvironment()->getDeltaTime());
			self->getComponent<Transform>()->Translate(-self->getComponent<Transform>()->Forward());
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
		//	self->getComponent<Transform>()->Translate(glm::vec3(0.0f, 0.0f, 0.05f));
			self->getComponent<Transform>()->Translate(self->getComponent<Transform>()->Left());
		}
		if (getKeyboard()->getKey(davorengine_RIGHT))
		{
			//self->getComponent<Transform>()->Translate(glm::vec3(0.0f, 0.0f, -0.05f));
			self->getComponent<Transform>()->Translate(self->getComponent<Transform>()->Right());
			
		}
		if (getKeyboard()->getKey(davorengine_W))
		{
			//theCamera->getComponent<Transform>()->Translate(glm::vec3(0.0f, 0.05f, 0.0f));
			theCamera->getComponent<Transform>()->Translate(self->getComponent<Transform>()->Up());
		}
		if (getKeyboard()->getKey(davorengine_S))
		{
			//theCamera->getComponent<Transform>()->Translate(glm::vec3(0.0f, -0.05f, 0.0f));
			theCamera->getComponent<Transform>()->Translate(self->getComponent<Transform>()->Down());
		}
		if (getKeyboard()->getKey(davorengine_A))
		{
			//theCamera->getComponent<Transform>()->Translate(self->getComponent<Transform>()->Left());
		//	theCamera->getComponent<Transform>()->Rotate(glm::vec3(0.0f, 0.01f, 0.0f));
			self->getComponent<Transform>()->Rotate(glm::vec3(0.0f, 0.01f, 0.0f));
		}
		if (getKeyboard()->getKey(davorengine_D))
		{
		//	theCamera->getComponent<Transform>()->Rotate(glm::vec3(0.0f, -0.01f, 0.0f));
			self->getComponent<Transform>()->Rotate(glm::vec3(0.0f, -0.01f, 0.0f));
		}
		if (self->getComponent<Collision>()->isColliding(platButton->getComponent<Transform>()->getPosition(), platButton->getComponent<Transform>()->getSize() - glm::vec3(1.5f)))
		{
			//self->getComponent<Transform>()->setPosition(self->getComponent<Collision>()->getCollisionResponse(dummy->getComponent<Transform>()->getPosition(), dummy->getComponent<Transform>()->getSize()));
			//std::cout << "We are colliding against something..." << std::endl;
			if (platButton->getComponent<Transform>()->getPosition().y > 0.6f && isActive == false)
			{
				platButton->getComponent<Transform>()->Translate(platButton->getComponent<Transform>()->Down());
			}
			
		}
		else
		{
			if (platButton->getComponent<Transform>()->getPosition().y < 1.2f && isActive == true)
			{
				platButton->getComponent<Transform>()->Translate(platButton->getComponent<Transform>()->Up());
				std::cout << "This runs?" << std::endl;
			}
			
			
		}

		theCamera->getComponent<Transform>()->setPosition(glm::vec3(self->getComponent<Transform>()->getPosition().x + 10.0f, self->getComponent<Transform>()->getPosition().y + 9.0f, self->getComponent<Transform>()->getPosition().z + 6.0f));
	

	//	std::cout << "Player Rotation (x,y,z): " << self->getComponent<Transform>()->getRotation().x << "/" << self->getComponent<Transform>()->getRotation().y << "/" << self->getComponent<Transform>()->getRotation().z << std::endl;
	//	std::cout << "Camera Rotation (x,y,z): " << theCamera->getComponent<Transform>()->getRotation().x << "/" << theCamera->getComponent<Transform>()->getRotation().y << "/" << theCamera->getComponent<Transform>()->getRotation().z << std::endl;

	}
	void OnGUI()
	{
		//getCore()->getGUI()->setMesh(guiMesh);
		getCore()->getGUI()->setGUITexture(glm::vec4(0, 0, 100, 100), theCameraTexture);
		
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
	std::shared_ptr<Entity> environment = core->addEntity();
	std::shared_ptr<Entity> platform_base = core->addEntity();
	//std::shared_ptr<Entity> box = core->addEntity();
	std::shared_ptr<Entity> platform_button = core->addEntity();
	
	// Camera:
	std::weak_ptr<Camera> cam = MainCamera->addComponent<Camera>(); // Camera
	MainCamera->getComponent<Transform>()->setPosition(glm::vec3(14, 15, 20));
	MainCamera->getComponent<Transform>()->setRotation(glm::vec3(-0.7f, 0.8f, 0.6f)); // y Left right, Z side   -> -0.7f, 0.8f, 0.6f;

	// Map:
	std::weak_ptr<MeshRenderer> mapMeshRenderer = map->addComponent<MeshRenderer>();
//	std::weak_ptr<Collision> mapCol = map->addComponent<Collision>();
	map->getComponent<Transform>()->setPosition(glm::vec3(0, 0, -5)); // 0, 0, -5
	map->getComponent<Transform>()->setRotation(glm::vec3(0, 45, 0)); // 0 , 45, 0

	// Player:
	player->addComponent<PlayerControl>();
	player->getComponent<PlayerControl>()->self = player;
	player->getComponent<PlayerControl>()->dummy = enemy;
	player->getComponent<PlayerControl>()->theCamera = MainCamera;
	player->getComponent<PlayerControl>()->env = environment;
	player->getComponent<PlayerControl>()->platButton = platform_button;
	
	std::weak_ptr<Collision> playerCollisionBox = player->addComponent<Collision>();
//	player->getComponent<Collision>()->setSize(glm::vec3(5.0f, 5.0f, 5.0f));
	std::weak_ptr<MeshRenderer> playerMeshRenderer = player->addComponent<MeshRenderer>();
	player->getComponent<Transform>()->setPosition(glm::vec3(0.0f, 3.0f, 5.0f)); // -16, 3.0f, 5.0f; actually -> 0.0f, 3.0f, 5.0f;
	player->getComponent<Transform>()->setRotation(glm::vec3(0.0f, 0.0f, 0.0f)); // y = 4.2f
	
	// Enemy:
	std::weak_ptr<Collision> enemyCol = enemy->addComponent<Collision>();
//	enemy->getComponent<Collision>()->setSize(glm::vec3(2.0f, 2.0f, 2.0f));
	std::weak_ptr<MeshRenderer> enemyMeshRenderer = enemy->addComponent<MeshRenderer>();
	enemy->getComponent<Transform>()->setPosition(glm::vec3(-4.0f, 3.0f, -2.0f)); // -4.0f, 3.0f, -2.0f;
//	enemy->getComponent<Transform>()->setRotation(glm::vec3(0.0f, -4.2f, 0.0f));
	enemy->getComponent<Transform>()->setRotation(glm::vec3(0.0f, 0.0f, 0.0f));
	
	// Platform
	std::weak_ptr<MeshRenderer> platformMeshRenderer = platform_base->addComponent<MeshRenderer>();
	platform_base->getComponent<Transform>()->setPosition(glm::vec3(3.0f, 1.0f, -2.0f));
	platform_base->getComponent<Transform>()->setScale(glm::vec3(3.0f, 3.0f, 3.0f));

	// Box
	//std::weak_ptr<MeshRenderer> boxMeshRenderer = box->addComponent<MeshRenderer>();
	//std::weak_ptr<Collision> boxCollision = box->addComponent<Collision>();
	//box->getComponent<Transform>()->setPosition(glm::vec3(2.0f, 1.0f, -6.0f));
	//box->getComponent<Transform>()->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	//box->getComponent<Transform>()->setScale(glm::vec3(3.0f, 3.0f, 3.0f));

	// Platform Button:
	std::weak_ptr<MeshRenderer> platform_buttonMeshRend = platform_button->addComponent<MeshRenderer>();
	platform_button->getComponent<Transform>()->setPosition(glm::vec3(3.0f, 1.2f, -2.0f));
	platform_button->getComponent<Transform>()->setScale(glm::vec3(3.0f, 3.0f, 3.0f));

	
	// TODO: Visual Studio runs from build directory... so add "../" i.e ../src/davor....

	std::shared_ptr<Mesh> m = core->getResources()->load<Mesh>("../src/davorengine/share/rend/samples/graveyard/graveyard.obj");
	std::shared_ptr<Material> mat = core->getResources()->load<Material>("../src/davorengine/share/rend/samples/graveyard/graveyard.png");

	map->getComponent<MeshRenderer>()->setMesh(m);
	map->getComponent<MeshRenderer>()->setMaterial(mat);
																		
	std::shared_ptr<Mesh> playerMesh = core->getResources()->load<Mesh>("../src/davorengine/share/rend/samples/curuthers/curuthers.obj");
	std::shared_ptr<Material> playerMaterial = core->getResources()->load<Material>("../src/davorengine/share/rend/samples/curuthers/Whiskers_diffuse.png");


	std::shared_ptr<Mesh> enemyMesh = core->getResources()->load<Mesh>("../src/davorengine/share/rend/samples/davormodel/Davor_Bird_Sprite.obj");
	std::shared_ptr<Material> enemyMaterial = core->getResources()->load<Material>("../src/davorengine/share/rend/samples/davormodel/pollo.png");

	std::shared_ptr<Mesh> platformMesh = core->getResources()->load<Mesh>("../src/davorengine/share/rend/samples/platform/Base.obj");
	std::shared_ptr<Material> platformMaterial = core->getResources()->load<Material>("../src/davorengine/share/rend/samples/platform/BaseTexture.jpg");

//	std::shared_ptr<Mesh> boxMesh = core->getResources()->load<Mesh>("../src/davorengine/share/rend/samples/box/box.obj");
//	std::shared_ptr<Material> boxMaterial = core->getResources()->load<Material>("../src/davorengine/share/rend/samples/box/box_diffuse_png.png");
	

	std::shared_ptr<Mesh> platform_buttonMesh = core->getResources()->load<Mesh>("../src/davorengine/share/rend/samples/platform/Base_Button.obj");
	std::shared_ptr<Material> platform_buttonMaterial = core->getResources()->load<Material>("../src/davorengine/share/rend/samples/platform/ButtonTexture.png");


	player->getComponent<MeshRenderer>()->setMesh(playerMesh);
	player->getComponent<MeshRenderer>()->setMaterial(playerMaterial);

	
	enemy->getComponent<MeshRenderer>()->setMesh(playerMesh);
	enemy->getComponent<MeshRenderer>()->setMaterial(playerMaterial);

	platform_base->getComponent<MeshRenderer>()->setMesh(platformMesh);
	platform_base->getComponent<MeshRenderer>()->setMaterial(platformMaterial);

	platform_button->getComponent<MeshRenderer>()->setMesh(platform_buttonMesh);
	platform_button->getComponent<MeshRenderer>()->setMaterial(platform_buttonMaterial);

	/*box->getComponent<MeshRenderer>()->setMesh(boxMesh);
	box->getComponent<MeshRenderer>()->setMaterial(boxMaterial);*/

	core->Start(); // Run updates loops, etc.


	return 0;
}
