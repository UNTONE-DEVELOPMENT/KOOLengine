#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "engine.hpp"
#include "phys.hpp"
#include <vector>
#include "scene.hpp"
#include "sound.hpp"

SDL_Renderer* Engine::Renderer;
SDL_Window* Engine::CurrentWindow;
SDL_Event Engine::EngineEvent;
bool Engine::Done;
Uint64 Engine::deltaTime;
Uint64 lastTick = 0;
Uint64 delta = 0;
Uint32 getTick = SDL_GetTicks();

int tick1 = SDL_GetTicks();
int tick2;
int fps;

void Engine::Begin(std::string programName, int WindowWidth, int WindowHeight)
{
    Done = false;
    std::cout << "Starting KOOLengine..." << std::endl;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
    IMG_Init(IMG_INIT_PNG);
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    CurrentWindow = SDL_CreateWindow(programName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowWidth, WindowHeight, 0);
    Renderer = SDL_CreateRenderer(CurrentWindow, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Engine::MainLoop()
{
    tick1 = SDL_GetTicks();
    SDL_Rect inter;
    while(SDL_PollEvent(&EngineEvent))
    {
        switch(EngineEvent.type)
        {
            case SDL_QUIT:
                Engine::End(0);
        }
    }
    for(int i = 0; i < EntityManager::entities.size(); i++)
    {
        if(EntityManager::entities[i]->Texture)
        {
            SDL_RenderCopy(Renderer, EntityManager::entities[i]->Texture, NULL, &EntityManager::entities[i]->rect);
        }
    }
    for(int i = 0; i < RigidbodyManager::bodies.size(); i++)
    {
        if(fps > 0 && RigidbodyManager::bodies[i]->Kinematic == false) {
            RigidbodyManager::bodies[i]->Velocity = RigidbodyManager::bodies[i]->Velocity + RigidbodyManager::bodies[i]->Gravity;
            RigidbodyManager::bodies[i]->ent->rect.y = RigidbodyManager::bodies[i]->ent->rect.y + RigidbodyManager::bodies[i]->Velocity;
        }
    }
    for(int i = 0; i < ColliderManager::colliders.size(); i++)
    {
        for(int j = 0; j < ColliderManager::colliders.size(); j++)
        {
            if(ColliderManager::colliders[i] != ColliderManager::colliders[j])
            {
                if(SDL_IntersectRect(&ColliderManager::colliders[i]->ent->rect, &ColliderManager::colliders[j]->ent->rect, &inter) == SDL_TRUE)
                {
                    ColliderManager::colliders[i]->isColliding = true;
                    ColliderManager::colliders[j]->isColliding = true;
                    if(ColliderManager::colliders[i]->ent->rect.y > ColliderManager::colliders[j]->ent->rect.y)
                    {
                        ColliderManager::colliders[i]->ent->rect.y-=inter.h;
                    }
                    else if(ColliderManager::colliders[i]->ent->rect.y < ColliderManager::colliders[j]->ent->rect.y)
                    {
                        ColliderManager::colliders[i]->ent->rect.y-=inter.h;
                    }
                    else if(ColliderManager::colliders[i]->ent->rect.x > ColliderManager::colliders[j]->ent->rect.x) 
                    {
                        try
                        {
                            if(RigidbodyManager::bodies[j]->Kinematic)
                            {
                                ColliderManager::colliders[i]->ent->rect.x+=inter.w;
                            }
                            else
                            {
                                ColliderManager::colliders[j]->ent->rect.x-=inter.w;
                            }
                        }
                        catch(const std::exception& e)
                        {
                            ColliderManager::colliders[i]->ent->rect.x+=inter.w;
                        }
                    }
                    else if(ColliderManager::colliders[i]->ent->rect.x < ColliderManager::colliders[j]->ent->rect.x)
                    {
                        try
                        {
                            if(RigidbodyManager::bodies[j]->Kinematic)
                            {
                                ColliderManager::colliders[i]->ent->rect.x-=inter.w;
                            }
                            else
                            {
                                ColliderManager::colliders[j]->ent->rect.x+=inter.w;
                            }
                        }
                        catch(const std::exception& e)
                        {
                            ColliderManager::colliders[i]->ent->rect.x-=inter.w;
                        }
                    }
                    try {
                        RigidbodyManager::bodies[i]->Velocity = 0;
                    } catch(std::exception& e) {
                        std::cout << "KOOLengine: tried to stop velocity, but entity didn't have a rigidbody component attached." << std::endl;
                    }
                }
                else
                {
                    ColliderManager::colliders[i]->isColliding = false;
                    ColliderManager::colliders[j]->isColliding = false;
                }
            }
        }
    }    
}

void Engine::SetOverlayColor(SDL_Color cl)
{
    SDL_SetRenderDrawColor(Renderer, cl.r, cl.g, cl.b, cl.a);
}

void Engine::DrawRect(SDL_Rect r)
{
    SDL_RenderDrawRect(Renderer, &r);
}

void Engine::FillScreen(SDL_Color cl)
{
    SDL_SetRenderDrawColor(Renderer, cl.r, cl.g, cl.b, cl.a);
    SDL_RenderClear(Renderer);
}

int Engine::End(int code)
{
    Done = true;
    for(auto& mixes : SoundManager::sources)
    {
        Mix_FreeChunk(mixes.src);
    }
    IMG_Quit();
    Mix_CloseAudio();
    SDL_Quit();
    return code;
}

void Engine::Tick()
{
    SDL_RenderPresent(Renderer);
    deltaTime = getTick - lastTick;
    lastTick = getTick;
    tick2 = SDL_GetTicks()-tick1;
    fps = (tick2 > 0) ? 1000.0f / tick2 : 0.0f;
}
