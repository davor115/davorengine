#include "Environment.h"
#include <SDL2/SDL.h>

Environment::Environment()
{
	deltaTime = 0.0166666667f;
	lastTime = 0;
	currentTime = 0;
}

void Environment::UpdateEnvironment()
{
	currentTime = SDL_GetTicks();
	deltaTime = (float)(currentTime - lastTime) / 1000.0f;
	lastTime = currentTime;
}

float Environment::getDeltaTime()
{
	return deltaTime;
}