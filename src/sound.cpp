#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "engine.hpp"
#include <vector>
#include "sound.hpp"

std::vector<Sound> SoundManager::sources;
int SoundManager::channelSize;

void SoundManager::PlayOneShot(std::string path, std::string name)
{
    Mix_Chunk* loaded = Mix_LoadWAV(path.c_str());
    Sound snd = {loaded, name, channelSize};
    Mix_PlayChannel(snd.channel, snd.src, 0);
    sources.push_back(snd);
}

void SoundManager::PlayLooped(std::string path, std::string name)
{
    Mix_Chunk* loaded = Mix_LoadWAV(path.c_str());
    Sound snd = {loaded, name, channelSize};
    Mix_PlayChannel(snd.channel, snd.src, 2000000000);
    sources.push_back(snd);
}

void SoundManager::StopMix(std::string name)
{
    for(auto& i : sources)
    {
        if(i.name == name)
        {
            Mix_HaltChannel(i.channel);
        }
    }
}