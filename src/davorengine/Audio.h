

#include "Component.h"

#include <AL/al.h>
#include <AL/alc.h>

#include <vector>

class Audio : public Component
{
private:
	ALuint sourceId;
	ALuint bufferId;
	ALsizei freq;
	ALCcontext* context;
	ALCdevice* device;
	bool onDestroy;


public:
	~Audio();
	void OnInit();
	void OnTick();
	void LoadAudio(const std::string& fileName, std::vector<char>& buffer,
		ALenum &format, ALsizei &freq);
	bool getDestroy();
};

