#include "Environment.h"
#include <SDL2/SDL.h>

float Environment::getDeltaTime()
{
	// Store this variable and initialize
	float lastTime = SDL_GetTicks();
	// In loop
	float time = SDL_GetTicks();
	float diff = time - lastTime;
	deltaTime = diff / 1000.0f;
	lastTime = time;
	




	return deltaTime;
}