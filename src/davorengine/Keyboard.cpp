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
			//std::cout << "We pressed a key" << std::endl;
			return true;
		}
		return false;
		
	}
}

bool Keyboard::getKeyDown(int keyCode)
{
	for (std::vector<int>::iterator i = pressedKeys.begin(); i != pressedKeys.end(); ++i)
	{
		if (*i == keyCode) // If the number we pressed is on the list (we pressed it before..), the return true.
		{
			//std::cout << "Key is on the list." << std::endl;
			return true;
		}
		else
		{
			return false;
		}
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
		//std::cout << "Keyboard onInit run" << std::endl;
		// User input:
		if (event.type == SDL_KEYDOWN)
		{		
			if (event.key.keysym.sym == SDLK_DOWN)
			{
				//std::cout << " Pressed KeyDown" << std::endl;
				pressedKeys.push_back(event.key.keysym.sym);
			}
			if (event.key.keysym.sym == SDLK_UP)
			{
				//std::cout << " Pressed KeyDown" << std::endl;
				pressedKeys.push_back(event.key.keysym.sym);
			}
			if (event.key.keysym.sym == SDLK_LEFT)
			{
				//std::cout << " Pressed KeyDown" << std::endl;
				pressedKeys.push_back(event.key.keysym.sym);
			}
			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				//std::cout << " Pressed KeyDown" << std::endl;
				pressedKeys.push_back(event.key.keysym.sym);
			}
		}
		else if (event.type == SDL_KEYUP)
		{
			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				// We lifted right key
				//std::cout << "Lifted right key" << std::endl;
			}
			if (event.key.keysym.sym == SDLK_DOWN)
			{
				//std::cout << "Lifted down key" << std::endl;
			}
		}

		
	}

}

void Keyboard::ClearKeys()
{
	releasedKeys.clear();
	pressedKeys.clear();
}