#pragma once

#include <iostream>
#include <SDL2/SDL.h>

class Component
{
public:
    int ID;
    std::string Name;
    virtual void Activate();
    virtual void Destroy();
};