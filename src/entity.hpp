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
    std::vector<SDL_Rect> AnimationRects;
    std::vector<SDL_Texture*> AnimationFrames;
    void LoadTexture(std::string path);
    void LoadTextureArray(std::vector<std::string> paths);
    void Destroy();
    Entity(void);
};

class EntityManager
{
public:
    static std::vector<Entity*> entities;
};