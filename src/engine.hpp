#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "phys.hpp"
#include <vector>

class Engine
{
public:
    static SDL_Renderer* Renderer;
    static SDL_Window* CurrentWindow;
    static SDL_Event EngineEvent;
    static bool Done;
    static void FillScreen(SDL_Color cl);
    static void SetOverlayColor(SDL_Color cl);
    static void DrawRect(SDL_Rect r);
    static void Begin(std::string programName, int WindowWidth, int WindowHeight);
    static void Tick();
    static void MainLoop();
    static int End(int code);
};