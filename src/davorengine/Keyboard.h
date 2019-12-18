#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

class Core;

class Keyboard
{
private:
	friend class Core;

	std::vector<SDL_Keycode> keys;
	std::vector<SDL_Keycode> pressedKeys;
	std::vector<SDL_Keycode> releasedKeys;
	


public:
	SDL_Event event;
	void onInit();
	bool getKey(int keyCode);
	bool getKeyDown(int keyCode);
	bool getKeyUp(int keyCode);
	void ClearKeys();
};




