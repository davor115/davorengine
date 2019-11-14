#include "Component.h"


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
	std::shared_ptr<Transform> rtn = std::make_shared<Transform>();
	return rtn;
}