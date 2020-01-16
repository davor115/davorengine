#include <iostream>
#include <memory>
#include "davorengine/Audio.h"
#include "davorengine/Engineincludes.h"
#include "davorengine/EngineKeyboard.h"

using namespace davorengine;

struct PlayerControl : public Component
{
	bool isActive = false;
	bool pickup = false;
	int w = 640;
	int h = 480;
	std::shared_ptr<Entity> theCamera;
	std::shared_ptr<Entity> platButton;
	std::shared_ptr<Entity> theBox;

	std::shared_ptr<Material> theCameraTexture;
	std::shared_ptr<Mesh> guiMesh;
	void OnInit()
	{
		theCameraTexture = getCore()->getResources()->load<Material>("../src/Models/davormodel/pollo.png");
		guiMesh = getCore()->getResources()->load<Mesh>("../src/Models/davormodel/Davor_Bird_Sprite.obj");
	}

	void PlatForm_Button_Func()
	{
		if (theBox->getComponent<Collision>()->isColliding(platButton->getComponent<Transform>()->getPosition(), platButton->getComponent<Transform>()->getSize() + glm::vec3(-1.5f, -1.0f, -1.5f)))
		{
			//std::cout << "Colliding" << std::endl;
			if (platButton->getComponent<Transform>()->getPosition().y > 0.10f && isActive == false) // 0.2 <- Max height at start.
			{
				platButton->getComponent<Transform>()->Translate(platButton->getComponent<Transform>()->Down());
			}
			else if (platButton->getComponent<Transform>()->getPosition().y <= 0.10f)
			{
				isActive = true;
			}
		}
		else
		{
			//std::cout << "Not colliding" << std::endl;
			if (platButton->getComponent<Transform>()->getPosition().y < 0.2f && isActive == true)
			{
				platButton->getComponent<Transform>()->Translate(platButton->getComponent<Transform>()->Up() ); // * getCore()->getEnvironment()->getDeltaTime() <- not fully working.
			}
			else if (platButton->getComponent<Transform>()->getPosition().y >= 0.2f)
			{
				isActive = false;
			}
		}
	}

	void MoveBox()
	{
		float distance = glm::distance(theCamera->getComponent<Transform>()->getPosition(), theBox->getComponent<Transform>()->getPosition());
		if (distance <= 5.5f) 
		{
			if (getKeyboard()->getKeyDown(davorengine_E))
			{
				pickup = !pickup;
				std::cout << "We picked up the box" << std::endl;
			}
		}

		if (pickup)
		{
			theBox->getComponent<Transform>()->setPosition(theCamera->getComponent<Transform>()->getPosition() + glm::vec3(5.0f, 0.0f, 0.0f));
		}
		else if (!pickup && theBox->getComponent<Transform>()->getPosition().y > 0.0f)
		{
			theBox->getComponent<Transform>()->Translate(glm::vec3(0.0f, -0.05f, 0.0f));
		}


		//std::cout << "We are at a distance of: " << distance << " from the box" << std::endl;
	}

	void FakeGravity()
	{
		if (theCamera->getComponent<Transform>()->getPosition().y > 3.0f)
		{
			theCamera->getComponent<Transform>()->Translate(glm::vec3(0.0f, -0.05f, 0.0f) * getCore()->getEnvironment()->getDeltaTime() * 50.0f);
		}
		else
		{
			theCamera->getComponent<Transform>()->Translate(glm::vec3(0.0f, 0.05f, 0.0f) * getCore()->getEnvironment()->getDeltaTime() * 50.0f);
		}
	}


	void OnTick()
	{
		//std::cout << "Mouse Pos (x/y/z) " << theCamera->getComponent<Transform>()->getPosition().x << "/" << theCamera->getComponent<Transform>()->getPosition().y << "/" << theCamera->getComponent<Transform>()->getPosition().z << std::endl;
		if (getKeyboard()->getKeyUp(davorengine_UP))
		{
			//std::cout << "Up!" << std::endl;
		}
		if (getKeyboard()->getKey(davorengine_DOWN))
		{

			//self->getComponent<Transform>()->Translate(-self->getComponent<Transform>()->Forward());
			//self->getComponent<Transform>()->Translate(-self->getComponent<Transform>()->Forward());
		}
		if (getKeyboard()->getKey(davorengine_UP))
		{
			//self->getComponent<Transform>()->Translate(self->getComponent<Transform>()->Forward());
		}
		if (getKeyboard()->getKey(davorengine_LEFT))
		{
			//self->getComponent<Transform>()->Translate(self->getComponent<Transform>()->Left());
		}
		if (getKeyboard()->getKey(davorengine_RIGHT))
		{
			//self->getComponent<Transform>()->Translate(self->getComponent<Transform>()->Right());		
		}
		if (getKeyboard()->getKey(davorengine_W))
		{
			theCamera->getComponent<Transform>()->Translate(theCamera->getComponent<Camera>()->getCamDirection() * getCore()->getEnvironment()->getDeltaTime() * 2.0f);
		}
		if (getKeyboard()->getKey(davorengine_S))
		{
			theCamera->getComponent<Transform>()->Translate(-theCamera->getComponent<Camera>()->getCamDirection() * getCore()->getEnvironment()->getDeltaTime() * 2.0f);
		}
		if (getKeyboard()->getKey(davorengine_A))
		{
			theCamera->getComponent<Transform>()->Translate(-theCamera->getComponent<Camera>()->getCamRight() * getCore()->getEnvironment()->getDeltaTime() * 2.0f);
		}
		if (getKeyboard()->getKey(davorengine_D))
		{
			theCamera->getComponent<Transform>()->Translate(theCamera->getComponent<Camera>()->getCamRight() * getCore()->getEnvironment()->getDeltaTime() * 2.0f);
		}
		
		PlatForm_Button_Func(); // This function is in charge of activating the pressure plate when the player is on top.
		MoveBox(); // This function is in charge of the interaction between the player and the box.
		FakeGravity();

		

	//	theCamera->getComponent<Transform>()->setPosition(glm::vec3(self->getComponent<Transform>()->getPosition().x + 10.0f, self->getComponent<Transform>()->getPosition().y + 9.0f, self->getComponent<Transform>()->getPosition().z + 6.0f));
	}
	void OnGUI()
	{
		//getCore()->getGUI()->setMesh(guiMesh);
		getCore()->getGUI()->setGUITexture(glm::vec4(0, 0, 100, 100), theCameraTexture);
		
	}
};


int main()
{

	//TODO: Why does it run so slow? -> I was getting the context every frame in the mesh renderer.
	//TODO: Note that onInit only should call once when addComponent
	std::cout << "Hello world!" << std::endl;

	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> MainCamera = core->addEntity();
	std::shared_ptr<Entity> player = core->addEntity();

	std::shared_ptr<Entity> platform_base = core->addEntity();
	std::shared_ptr<Entity> box = core->addEntity();
	std::shared_ptr<Entity> platform_button = core->addEntity();
	std::shared_ptr<Entity> room = core->addEntity();
	std::shared_ptr<Entity> doorR1 = core->addEntity();
	std::shared_ptr<Entity> doorR2 = core->addEntity();
	std::shared_ptr<Entity> doorL1 = core->addEntity();
	std::shared_ptr<Entity> doorL2 = core->addEntity();
	std::shared_ptr<Entity> SoundSource = core->addEntity();

	
	
	// Camera:
	std::weak_ptr<Camera> cam = MainCamera->addComponent<Camera>(); // Camera
	std::weak_ptr<Collision> camColl = MainCamera->addComponent<Collision>();
	MainCamera->getComponent<Transform>()->setPosition(glm::vec3(0.0f, 0.0f, 0.0f)); // 14, 15, 20
	MainCamera->getComponent<Transform>()->setRotation(glm::vec3(0.0f, 0.0f, 0.0f)); // y Left right, Z side   -> -0.7f, 0.8f, 0.6f;
//	MainCamera->getComponent<Collision>()->setOffset(glm::vec3(0.0f, -3.0f, 0.0f));
	//MainCamera->getComponent<Collision>()->setBoxColliderPosition(MainCamera->getComponent<Transform>()->getPosition() - glm::vec3(0.0f, 3.0f, 0.0f));
	MainCamera->getComponent<Collision>()->setSize(glm::vec3(1.0f, 3.0f, 1.0f));
	MainCamera->getComponent<Collision>()->setUnmovable(false);

	
	// Player:
	player->addComponent<PlayerControl>();
	player->getComponent<PlayerControl>()->theCamera = MainCamera;
	player->getComponent<PlayerControl>()->platButton = platform_button;
	player->getComponent<PlayerControl>()->theBox = box;
	
	// Platform
	std::weak_ptr<Collision> platformColl = platform_base->addComponent<Collision>();
	std::weak_ptr<MeshRenderer> platformMeshRenderer = platform_base->addComponent<MeshRenderer>();
	platform_base->getComponent<Transform>()->setPosition(glm::vec3(30.0f, 0.0f, -2.0f));
	platform_base->getComponent<Transform>()->setScale(glm::vec3(3.0f, 3.0f, 3.0f));
	platform_base->getComponent<Collision>()->setSize(glm::vec3(3.0f, 0.5f, 3.0f));

	// Box
	std::weak_ptr<Collision> boxCollision = box->addComponent<Collision>();
	std::weak_ptr<MeshRenderer> boxMeshRenderer = box->addComponent<MeshRenderer>();
	box->getComponent<Transform>()->setPosition(glm::vec3(25.0f, 0.0f, 10.0f));
	box->getComponent<Transform>()->setRotation(glm::vec3(0.0f, 0.0f, 0.0f));
	box->getComponent<Transform>()->setScale(glm::vec3(3.0f, 3.0f, 3.0f));
	box->getComponent<Collision>()->setSize(glm::vec3(1.0f, 0.5f, 1.0f));

	// Platform Button:
	std::weak_ptr<MeshRenderer> platform_buttonMeshRend = platform_button->addComponent<MeshRenderer>();
	std::weak_ptr<Collision> platform_buttonColl = platform_button->addComponent<Collision>();
	platform_button->getComponent<Transform>()->setPosition(glm::vec3(30.0f, 0.2f, -2.0f));
	platform_button->getComponent<Transform>()->setScale(glm::vec3(3.0f, 3.0f, 3.0f));
	platform_button->getComponent<Collision>()->setSize(glm::vec3(0.5f, 0.2f, 0.5f));

	// Room
	std::weak_ptr<MeshRenderer> roomMeshRend = room->addComponent<MeshRenderer>();
	room->getComponent<Transform>()->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	room->getComponent<Transform>()->setRotation(glm::vec3(0.0f, 0.0f, 0.0f));
	room->getComponent<Transform>()->setScale(glm::vec3(3.0f));

	// Door Right 1
	std::weak_ptr<MeshRenderer> doorRMesh = doorR1->addComponent<MeshRenderer>();
	//std::weak_ptr<Collision> doorRColl = doorR1->addComponent<Collision>();
	doorR1->getComponent<Transform>()->setPosition(glm::vec3(-23.2f, 5.0f, -2.7f));
	doorR1->getComponent<Transform>()->setRotation(glm::vec3(0.0f, 0.0f, 0.0f));
	doorR1->getComponent<Transform>()->setScale(glm::vec3(3.0f));
	//doorR1->getComponent<Collision>()->setSize(glm::vec3(3.0f));

	// Door Right 2
	std::weak_ptr<MeshRenderer> doorRMesh2 = doorR2->addComponent<MeshRenderer>();
	std::weak_ptr<Collision> doorR2Coll = doorR2->addComponent<Collision>();
	doorR2->getComponent<Transform>()->setPosition(glm::vec3(22.7f, 5.0f, -2.7f));
	doorR2->getComponent<Transform>()->setRotation(glm::vec3(0.0f, 0.0f, 0.0f));
	doorR2->getComponent<Transform>()->setScale(glm::vec3(3.0f));
	//doorR2->getComponent<Collision>()->setBoxColliderPosition(doorR2->getComponent<Transform>()->getPosition() - glm::vec3(0.0f, 3.0f, 0.0f));
	doorR2->getComponent<Collision>()->setSize(glm::vec3(3.0f));

	// Door Left 1
	std::weak_ptr<MeshRenderer> doorLMesh = doorL1->addComponent<MeshRenderer>();
	//std::weak_ptr<Collision> doorL1Coll = doorL1->addComponent<Collision>();
	doorL1->getComponent<Transform>()->setPosition(glm::vec3(22.7f, 5.0f, 2.7f));
	doorL1->getComponent<Transform>()->setRotation(glm::vec3(0.0f, 0.0f, 0.0f));
	doorL1->getComponent<Transform>()->setScale(glm::vec3(3.0f));
	//doorL1->getComponent<Collision>()->setSize(glm::vec3(3.0f));

	// Door Left 2
	std::weak_ptr<MeshRenderer> doorLMesh2 = doorL2->addComponent<MeshRenderer>();
	//std::weak_ptr<Collision> doorL2Coll = doorL2->addComponent<Collision>();
	doorL2->getComponent<Transform>()->setPosition(glm::vec3(-23.2f, 5.0f, 2.7f));
	doorL2->getComponent<Transform>()->setRotation(glm::vec3(0.0f, 0.0f, 0.0f));
	doorL2->getComponent<Transform>()->setScale(glm::vec3(3.0f));
	//doorL2->getComponent<Collision>()->setSize(glm::vec3(3.0f));
	//doorL2->getComponent<Collision>()->setBoxColliderPosition(doorL2->getComponent<Transform>()->getPosition() - glm::vec3(0.0f, 2.0f, 0.0f));

	std::shared_ptr<Audio> audioclip = box->addComponent<Audio>();
	box->getComponent<Audio>()->LoadAudio("../src/thehorn/dixie_horn.ogg");

			
	std::shared_ptr<Mesh> platformMesh = core->getResources()->load<Mesh>("../src/Models/platform/Base.obj");
	std::shared_ptr<Material> platformMaterial = core->getResources()->load<Material>("../src/Models/platform/BaseTexture.jpg");

	std::shared_ptr<Mesh> boxMesh = core->getResources()->load<Mesh>("../src/Models/box/box.obj");
	std::shared_ptr<Material> boxMaterial = core->getResources()->load<Material>("../src/Models/box/box_diffuse_png.png");
	

	std::shared_ptr<Mesh> platform_buttonMesh = core->getResources()->load<Mesh>("../src/Models/platform/Base_Button.obj");
	std::shared_ptr<Material> platform_buttonMaterial = core->getResources()->load<Material>("../src/Models/platform/ButtonTexture.png");

	std::shared_ptr<Mesh> room_Mesh = core->getResources()->load<Mesh>("../src/Models/Tom/davor_room3.obj");
	std::shared_ptr<Material> room_Mat = core->getResources()->load<Material>("../src/Models/Room/davor_room_baked.jpg");

	std::shared_ptr<Mesh> doorR_Mesh = core->getResources()->load<Mesh>("../src/Models/Tom/DoorR3.obj");
	std::shared_ptr<Mesh> doorL_Mesh = core->getResources()->load<Mesh>("../src/Models/Tom/DoorL3.obj");
	std::shared_ptr<Material> doorR1_Material = core->getResources()->load<Material>("../src/Models/Room/davor_room_baked.jpg");
	std::shared_ptr<Material> doorR2_Material = core->getResources()->load<Material>("../src/Models/Room/davor_room_baked.jpg");
	std::shared_ptr<Material> doorL1_Material = core->getResources()->load<Material>("../src/Models/Room/davor_room_baked.jpg");
	std::shared_ptr<Material> doorL2_Material = core->getResources()->load<Material>("../src/Models/Room/davor_room_baked.jpg");

	platform_base->getComponent<MeshRenderer>()->setMesh(platformMesh);
	platform_base->getComponent<MeshRenderer>()->setMaterial(platformMaterial);

	platform_button->getComponent<MeshRenderer>()->setMesh(platform_buttonMesh);
	platform_button->getComponent<MeshRenderer>()->setMaterial(platform_buttonMaterial);

	box->getComponent<MeshRenderer>()->setMesh(boxMesh);
	box->getComponent<MeshRenderer>()->setMaterial(boxMaterial);

	room->getComponent<MeshRenderer>()->setMesh(room_Mesh);
	room->getComponent<MeshRenderer>()->setMaterial(room_Mat);
	
	doorR1->getComponent<MeshRenderer>()->setMesh(doorR_Mesh);
	doorR1->getComponent<MeshRenderer>()->setMaterial(doorR1_Material);

	doorR2->getComponent<MeshRenderer>()->setMesh(doorR_Mesh);
	doorR2->getComponent<MeshRenderer>()->setMaterial(doorR2_Material);

	
	doorL1->getComponent<MeshRenderer>()->setMesh(doorL_Mesh);
	doorL1->getComponent<MeshRenderer>()->setMaterial(doorL1_Material);
	
	doorL2->getComponent<MeshRenderer>()->setMesh(doorL_Mesh);
	doorL2->getComponent<MeshRenderer>()->setMaterial(doorL2_Material);

	core->Start(); // Run updates loops, etc.


	return 0;
}
