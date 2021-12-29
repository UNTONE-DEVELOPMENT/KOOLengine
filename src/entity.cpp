#include <iostream>
#include <SDL2/SDL.h>
#include "component.hpp"
#include "entity.hpp"
#include "engine.hpp"

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

void Entity::Activate()
{
    SDL_RenderCopy(Engine::Renderer, Texture, NULL, &rect);
}

void Entity::Destroy()
{
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

SDL_Texture* Entity::animation(std::vector<std::string> paths)
{
    throw std::runtime_error("Not implemented");
}