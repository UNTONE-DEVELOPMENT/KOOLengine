#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "engine.hpp"
#include "phys.hpp"
#include <vector>

SDL_Renderer* Engine::Renderer;
SDL_Window* Engine::CurrentWindow;
SDL_Event Engine::EngineEvent;
bool Engine::Done;

void Engine::Begin(std::string programName, int WindowWidth, int WindowHeight)
{
    Done = false;
    std::cout << "Starting KOOLengine..." << std::endl;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
    IMG_Init(IMG_INIT_PNG);
    CurrentWindow = SDL_CreateWindow(programName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowWidth, WindowHeight, 0);
    Renderer = SDL_CreateRenderer(CurrentWindow, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Engine::MainLoop()
{
    while(SDL_PollEvent(&EngineEvent))
    {
        switch(EngineEvent.type)
        {
            case SDL_QUIT:
                Engine::End(0);
        }
    }
    for(int i = 0; i < RigidbodyManger::bodies.size(); i++)
    {
        RigidbodyManger::bodies[i]->ent->rect.y+=RigidbodyManger::bodies[i]->Mass*RigidbodyManger::bodies[i]->Gravity;
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
    SDL_Quit();
    IMG_Quit();
    return code;
}

void Engine::Tick()
{
    SDL_RenderPresent(Renderer);
}