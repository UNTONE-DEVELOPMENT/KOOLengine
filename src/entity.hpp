#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "component.hpp"
#include <vector>

class Entity: public Component
{
public:
    void SetPosition(int x, int y);
    void SetSize(int w, int h);
    SDL_Rect rect;
    SDL_Texture* Texture;
    void LoadTexture(std::string path);
    SDL_Texture* animation(std::vector<std::string> paths);
    void Activate();
    void Destroy();
};