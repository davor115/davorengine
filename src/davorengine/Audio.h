

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
	void OnInit(); ///< Initialize OpenAL audio system
	void OnTick(); ///< Once the audio has finished playing, the component gets removed from the entity.
	void LoadAudio(const std::string& fileName); ///< Load an audio into OpenAL.
	bool getDestroy(); ///< getDestroy() is used by core to get a signal when it needs to remove the audio.
};

