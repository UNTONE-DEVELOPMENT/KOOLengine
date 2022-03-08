#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "component.hpp"
#include "entity.hpp"
#include <vector>

#define MASS_DEFAULT 9.8f
#define VELOCITY_DEFAULT 0
#define METER_WINDOW_RATIO 100

class Phys {
public:
    static float Meter();
};

class Rigidbody: public Component
{
public:
    Entity* ent;
    bool Kinematic;
    float Mass;
    float Gravity;
    float Velocity;
    void Destroy();
    Rigidbody(Entity* e, bool k, float m, float g, float v);
};

class Collider: public Component
{
public:
    Entity* ent;
    void Destroy();
    bool isColliding;
    Collider(Entity* e);
};

class ColliderManager
{
public:
    static std::vector<Collider*> colliders;
};

class RigidbodyManager
{
public:
    static std::vector<Rigidbody*> bodies;
};