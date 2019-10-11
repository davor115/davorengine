#ifndef _DAVOR_ENGINE_
#define _DAVOR_ENGINE_
#include <iostream>
class Core
{
private:

public:
	Core()
	{
		// Constructor
		std::cout << "Core constructor called" << std::endl;
	}

	~Core()
	{
		std::cout << "Exit" << std::endl;
	}

	void Print();

};




#endif