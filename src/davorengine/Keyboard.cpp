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
	for (std::vector<int>::iterator i = keys.begin(); i != keys.end(); ++i)
	{
		if(*i == keyCode)
		{
			return true;
		}
	}

	return false;
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
	}

	return false;
}

bool Keyboard::getKeyUp(int keyCode)
{
	for (std::vector<int>::iterator i = releasedKeys.begin(); i != releasedKeys.end(); ++i)
	{
		if (*i == keyCode) // If the number we pressed is on the list (we pressed it before..), the return true.
		{
			//std::cout << "Key is on the list." << std::endl;
			return true;
		}
	}

	return false;
}

void Keyboard::ClearKeys()
{
	releasedKeys.clear();
	pressedKeys.clear();
}
