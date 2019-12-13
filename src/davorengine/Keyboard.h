
#include <SDL2/SDL.h>
#include <vector>
class Keyboard
{
private:
	std::vector<SDL_Keycode> keyCodes;
	std::vector<SDL_Keycode> pressedKeys;
	std::vector<SDL_Keycode> releasedKeys;
	


public:
	SDL_Event event;
	void onInit();
	bool getKey(int keyCode);
	bool getKeyDown(int keyCode);
	bool getKeyUp(int keyCode);
};




