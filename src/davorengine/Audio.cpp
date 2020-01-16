#include "Audio.h"
#include "Core.h"
#include "Camera.h"
#include "Transform.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "stb_vorbis.h"
#include <exception>
void Audio::OnInit()
{
	onDestroy = false;
	/*
	* Initialize OpenAL audio system
	*/

  // Open up the OpenAL device
	device = alcOpenDevice(NULL);

	if (device == NULL)
	{
		throw std::exception();
	}

	// Create audio context
	context = alcCreateContext(device, NULL);

	if (context == NULL)
	{
		alcCloseDevice(device);
		throw std::exception();
	}

	// Set as current context
	if (!alcMakeContextCurrent(context))
	{
		alcDestroyContext(context);
		alcCloseDevice(device);
		throw std::exception();
	}

	// Generally not needed. Translate sources instead
	alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);

	/*
	 * Create OpenAL sound buffer
	 */
	bufferId = 0;
	alGenBuffers(1, &bufferId);


	//LoadAudio("../src/thehorn/dixie_horn.ogg"); // Change the string for a variable.


	
	
}

bool Audio::getDestroy()
{
	return onDestroy;
}
void Audio::OnTick()
{
	/*
	 * Wait for sound to finish
	 *
	 * Once the sound is finished, the component gets removed from the entity.
	 *       
	 */
	
	glm::vec3 pos = getTransform()->getPosition();
	std::shared_ptr<Camera> camera = getCore()->getCurrentCamera();
	glm::vec4 res = camera->getView() * glm::vec4(pos, 1.0f);

	alSource3f(sourceId, AL_POSITION, res.x, res.y, res.z);

		ALint state = 0;
		alGetSourcei(sourceId, AL_SOURCE_STATE, &state);

		if (state == AL_STOPPED)
		{
		//	break;
			onDestroy = true;
		}

#ifdef _WIN32
		Sleep(1000);
#else
		sleep(1);
#endif
}


void Audio::LoadAudio(const std::string& fileName)
{
	/*
	 * Create OpenAL sound source
	 */
	ALenum format = 0;
	freq = 0;
	std::vector<char> bufferData;

	int channels = 0;
	int sampleRate = 0;
	short* output = NULL;

	size_t samples = stb_vorbis_decode_filename(
		fileName.c_str(), &channels, &sampleRate, &output);

	if (samples == -1)
	{
		throw std::exception();
	}

	// Record the sample rate required by OpenAL
	freq = sampleRate;

	// Record the format required by OpenAL
	if (channels == 1)
	{
		format = AL_FORMAT_MONO16;
	}
	else
	{
		//format = AL_FORMAT_STEREO16;

		// Force format to be mono (Useful for positional audio)
		 format = AL_FORMAT_MONO16;
		 freq *= 2;
	}

	// Allocate enough space based on short (two chars) multipled by the number of
	// channels and length of clip
	bufferData.resize(sizeof(*output) * channels * samples);
	memcpy(&bufferData.at(0), output, bufferData.size());



	alBufferData(bufferId, format, &bufferData.at(0),
		static_cast<ALsizei>(bufferData.size()), freq);

	// Clean up the read data
	free(output);

	sourceId = 0;
	alGenSources(1, &sourceId);


	alSourcei(sourceId, AL_BUFFER, bufferId);
	alSourcePlay(sourceId);

}


Audio::~Audio()
{

	/*
	 * Clean up OpenAL data.
	 *
	 * Note: Do not free the buffer before the source using it has been freed.
	 *       Use a std::shared_ptr to hold onto you sound buffer class from source class.
	 *
	 * Note: Make sure current context has been set to NULL before deleting context.
	 *       Make sure context destroyed before closing device.
	 */
	alDeleteSources(1, &sourceId);
	alDeleteBuffers(1, &bufferId);
	alcMakeContextCurrent(NULL);
	alcDestroyContext(context);
	alcCloseDevice(device);
}