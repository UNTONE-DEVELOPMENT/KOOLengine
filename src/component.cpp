#include <iostream>
#include <SDL2/SDL.h>
#include "component.hpp"

void Component::Activate()
{
    std::cout << "Activated component of name: " << Name << std::endl;
}

void Component::Destroy()
{
    std::cout << "Destroying component of name: " << Name << std::endl;
}