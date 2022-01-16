#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "engine.hpp"
#include "component.hpp"
#include "entity.hpp"
#include "animation.hpp"

Animation::Animation(Entity* e)
{
    ent = e;
}

void Animation::Translate(int x, int y, float speed)
{
    if(ent->rect.x < x)
    {
        ent->rect.x+=speed;
    }
    if(ent->rect.y < y)
    {
        ent->rect.y+=speed;
    }
    if(ent->rect.x > x)
    {
        ent->rect.x-=speed;
    }
    if(ent->rect.y > y)
    {
        ent->rect.y-=speed;
    }
}

void Animation::Scatter(float amount, float speed)
{
    std::vector<SDL_Texture*> frames = ent->AnimationFrames;
    std::vector<SDL_Rect> rects = ent->AnimationRects;
    for(int i = 0; i < frames.size(); i++)
    {
        int position = rects[i].y + 20;
        int randoX = rand() % (rects[i].x - 20) + (rects[i].x + 20);
        int randoY = rand() % rects[i].y + rects[i].h;
        SDL_Rect newR = {randoX, randoY, rects[i].w/5, rects[i].h/5};
        int randoAngle = rand() % -180 + 180;
        SDL_RenderCopyEx(Engine::Renderer, frames[i], NULL, &newR, randoAngle, NULL, SDL_FLIP_NONE);
    }
}
