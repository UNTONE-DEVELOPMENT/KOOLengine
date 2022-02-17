#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "engine.hpp"
#include <vector>

typedef struct
{
    Mix_Chunk* src;
    std::string name;
    int channel;
} Sound;

class SoundManager
{
public:
    static int channelSize;
    static std::vector<Sound> sources;
    static void PlayOneShot(std::string path, std::string name);
    static void PlayLooped(std::string path, std::string name);
    static void StopMix(std::string name);
};