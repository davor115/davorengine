#pragma once
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "stb_vorbis.h"
#include "Component.h"

#include <AL/al.h>
#include <AL/alc.h>

#include <iostream>
#include <vector>
#include <exception>

class Audio : public Component
{
private:
	ALuint sourceId;



public:
	void OnInit();
	void OnTick();
	void LoadAudio(const std::string& fileName, std::vector<char>& buffer,
		ALenum &format, ALsizei &freq);

};

