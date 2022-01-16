#include <iostream>
#include <SDL2/SDL.h>
#include "component.hpp"
#include "entity.hpp"
#include "engine.hpp"

std::vector<Entity*> EntityManager::entities;

void Entity::SetPosition(int x, int y)
{
    rect.x = x;
    rect.y = y;
}

void Entity::SetSize(int w, int h)
{
    rect.w = w;
    rect.h = h;
}   

void Entity::Destroy()
{
    EntityManager::entities.erase(std::remove(EntityManager::entities.begin(), EntityManager::entities.end(), this), EntityManager::entities.end());
    delete this;
}

void Entity::LoadTexture(std::string path)
{
    SDL_Surface* s = IMG_Load(path.c_str());
    if(s)
    {
        SDL_Texture* tex = SDL_CreateTextureFromSurface(Engine::Renderer, s);
        rect.w = s->w;
        rect.h = s->h;
        SDL_FreeSurface(s);
        Texture = tex;
    }
    else
    {
        SDL_FreeSurface(s);
        char er[1000];
        sprintf(er, "Could not load texture from %s", path.c_str());
        throw std::runtime_error(er);
    }
}

void Entity::LoadTextureArray(std::vector<std::string> paths)
{
    for(int i = 0; i < paths.size(); i++)
    {
        SDL_Surface* s = IMG_Load(paths[i].c_str());
        if(s)
        {
            SDL_Texture* tex = SDL_CreateTextureFromSurface(Engine::Renderer, s);
            SDL_Rect r = {rect.x, rect.y, s->w, s->h};
            AnimationFrames.push_back(tex);
            AnimationRects.push_back(r);
            SDL_FreeSurface(s);
        }
        else
        {
            SDL_FreeSurface(s);
            char er[1000];
            sprintf(er, "Could not load texture from %s", paths[i].c_str());
            throw std::runtime_error(er);
        }
    }
}

Entity::Entity(void)
{
    std::cout << "added entity" << std::endl;
    EntityManager::entities.push_back(this);
}