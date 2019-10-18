#include "Environment.h"



float Environment::getDeltaTime()
{
	return Environment::deltaTime;
}

void Environment::setDeltaTime(float _num)
{
	Environment::deltaTime += _num;
}