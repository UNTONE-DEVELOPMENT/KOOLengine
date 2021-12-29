#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "component.hpp"
#include "entity.hpp"
#include <vector>

#define MASS_DEFAULT 9.8f

class Rigidbody: public Component
{
public:
    Entity* ent;
    bool Kinematic;
    float Mass;
    float Gravity;
    Rigidbody(Entity* e, bool k, float m, float g);
};

class Collider: public Component
{
public:
    Entity* ent;
    Collider(Entity* e);
};

class ColliderManager
{
public:
    static std::vector<Collider*> colliders;
};

class RigidbodyManger
{
public:
    static std::vector<Rigidbody*> bodies;
};