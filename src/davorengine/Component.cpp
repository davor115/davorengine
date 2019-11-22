#include "Component.h"
#include "Transform.h"
#include "Entity.h"
#include "Camera.h"

std::shared_ptr<Entity> Component::getEntity()
{
	return entity.lock(); // makes the weak_ptr into a shared_ptr
}

void Component::OnInit()
{

}

void Component::OnTick()
{

}

void Component::OnBegin()
{

}

void Component::OnDisplay()
{

}

std::shared_ptr<Transform> Component::getTransform()
{
	std::shared_ptr<Transform> rtn = getEntity()->getComponent<Transform>();
	return rtn;
}

std::shared_ptr<Core> Component::getCore()
{
	std::shared_ptr<Core> rtn = getEntity()->getCore();
	return rtn;
}

std::shared_ptr<Camera> Component::getCamera()
{
	std::cout << "Getting the camera..." << std::endl;
	std::shared_ptr<Camera> rtn = entity.lock()->getComponent<Camera>();
	
	return rtn;
}