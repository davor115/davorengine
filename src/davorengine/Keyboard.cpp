#include "Keyboard.h"

/*
void Keyboard::runKeyboard()
{
	
			const Uint8* currentKeyCode = SDL_GetKeyboardState(NULL);
			if (currentKeyCode[SDL_SCANCODE_UP]) // 1
			{
				keyCodes.push_back(1);
			}
			if (currentKeyCode[SDL_SCANCODE_DOWN]) // 2
			{
				keyCodes.push_back(2);
			}
			if (currentKeyCode[SDL_SCANCODE_LEFT]) // 3
			{
				keyCodes.push_back(3);
			}
			if (currentKeyCode[SDL_SCANCODE_RIGHT]) // 4
			{
				keyCodes.push_back(4);
			}
			
}
*/

bool Keyboard::getKey(int keyCode)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == keyCode)
		{
			keyCodes.push_back(event.key.keysym.sym);
			return true;
		}
		return false;
		
	}
}

void Keyboard::onInit()
{

	bool quit = false;

	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_QUIT)
		{
			quit = true;
		}
	}

}