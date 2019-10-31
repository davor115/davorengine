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
