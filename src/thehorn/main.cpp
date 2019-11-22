#ifdef _WIN32
  #include <windows.h>
#else
  #include <unistd.h>
#endif

#include "stb_vorbis.h"

#include <AL/al.h>
#include <AL/alc.h>

#include <iostream>
#include <vector>
#include <exception>

void load_ogg(const std::string& fileName, std::vector<char>& buffer,
  ALenum &format, ALsizei &freq);

int main()
{
  /*
   * Initialize OpenAL audio system
   */

  // Open up the OpenAL device
  ALCdevice* device = alcOpenDevice(NULL);

  if(device == NULL)
  {
    throw std::exception();
  }

  // Create audio context
  ALCcontext* context = alcCreateContext(device, NULL);

  if(context == NULL)
  {
    alcCloseDevice(device);
    throw std::exception();
  }

  // Set as current context
  if(!alcMakeContextCurrent(context))
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
  ALuint bufferId = 0;
  alGenBuffers(1, &bufferId);

  ALenum format = 0;
  ALsizei freq = 0;
  std::vector<char> bufferData;
  load_ogg("dixie_horn.ogg", bufferData, format, freq);

  alBufferData(bufferId, format, &bufferData.at(0),
    static_cast<ALsizei>(bufferData.size()), freq);

  /*
   * Create OpenAL sound source
   */
  ALuint sourceId = 0;
  alGenSources(1, &sourceId);

  alSource3f(sourceId, AL_POSITION, 0.0f, 0.0f, 0.0f);
  alSourcei(sourceId, AL_BUFFER, bufferId);
  alSourcePlay(sourceId);

  /*
   * Wait for sound to finish
   *
   * Note: You will generally want to check within your onTick functions
   *       and get the SoundSource component to remove itself when complete.
   */
  while(true)
  {
    ALint state = 0;
    alGetSourcei(sourceId, AL_SOURCE_STATE, &state);

    if(state == AL_STOPPED)
    {
      break;
    }

#ifdef _WIN32
    Sleep(1000);
#else
    sleep(1);
#endif
  }

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

  return 0;
}

void load_ogg(const std::string& fileName, std::vector<char>& buffer,
  ALenum &format, ALsizei &freq)
{
  int channels = 0;
  int sampleRate = 0;
  short* output = NULL;

  size_t samples = stb_vorbis_decode_filename(
    fileName.c_str(), &channels, &sampleRate, &output);

  if(samples == -1)
  {
    throw std::exception();
  }

  // Record the sample rate required by OpenAL
  freq = sampleRate;

  // Record the format required by OpenAL
  if(channels == 1)
  {
    format = AL_FORMAT_MONO16;
  }
  else
  {
    format = AL_FORMAT_STEREO16;

    // Force format to be mono (Useful for positional audio)
    // format = AL_FORMAT_MONO16;
    // freq *= 2;
  }

  // Allocate enough space based on short (two chars) multipled by the number of
  // channels and length of clip
  buffer.resize(sizeof(*output) * channels * samples);
  memcpy(&buffer.at(0), output, buffer.size());

  // Clean up the read data
  free(output);
}