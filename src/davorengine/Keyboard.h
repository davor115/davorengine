#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

class Core;

	/**
	* \brief Detect Keyboard Input
	*/

class Keyboard
{
private:
	friend class Core; ///< Allows the Core class to access all the member variables and functions from the Keyboard class.

	std::vector<SDL_Keycode> keys; ///< List of all the pressed keys
	std::vector<SDL_Keycode> pressedKeys; ///< List of all the keys pressed down in a frame
	std::vector<SDL_Keycode> releasedKeys; ///< List of all the released keys in a frame
	


public:
	SDL_Event event;

	/**
	* \brief Returns true if a specific key has been pressed, else return false.
	*/
	bool getKey(int keyCode);
	/**
	* \brief Returns true if a specific key has been pressed, else return false.
	*/
	bool getKeyDown(int keyCode);
	/**
	* \brief Returns true if a specific key has been released, else return false.
	*/
	bool getKeyUp(int keyCode);
};




