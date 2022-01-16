#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "engine.hpp"
#include "component.hpp"
#include "entity.hpp"

class Animation: public Component
{
public:
    Entity* ent;
    void Translate(int x, int y, float speed);
    void Scale(int x, int y, float speed);
    void Scatter(float amount, float speed);
    Animation(Entity* e);
};