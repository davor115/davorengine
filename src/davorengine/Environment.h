#pragma once
#ifndef _ENVIRONMENT_
#define _ENVIRONMENT_
class Environment
{
private:
	float deltaTime;


public:
	float getDeltaTime();
	void setDeltaTime(float _num);

};
#endif