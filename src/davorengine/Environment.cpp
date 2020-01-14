#include "Environment.h"
#include <SDL2/SDL.h>

Environment::Environment()
{
	deltaTime = 0.0166666667f;
	lastTime = 0;
	currentTime = 0;
}

float Environment::getDeltaTime()
{
	// Store this variable and initialize
	currentTime = SDL_GetTicks();
	deltaTime = (float)(currentTime - lastTime) / 1000.0f;
	lastTime = currentTime;

	//// In loop
	//if (environment->deltaTime < (1.0f / 60.0f))
	//{
		//SDL_Delay((unsigned int)(((1.0f / 60.0f) - environment->deltaTime)*1000.0f));
	//}



	return deltaTime;
}