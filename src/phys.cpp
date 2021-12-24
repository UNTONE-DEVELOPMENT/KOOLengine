#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "component.hpp"
#include "entity.hpp"
#include <vector>
#include "phys.hpp"

std::vector<Rigidbody*> RigidbodyManger::bodies;

Rigidbody::Rigidbody(Entity* e, bool k, float m, float g)
{
    ent = e;
    Kinematic = k;
    Mass = m;
    Gravity = g;
    RigidbodyManger::bodies.push_back(this);
}