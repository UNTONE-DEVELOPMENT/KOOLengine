#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "engine.hpp"
#include "component.hpp"
#include "entity.hpp"
#include <vector>
#include "phys.hpp"

std::vector<Rigidbody*> RigidbodyManager::bodies;
std::vector<Collider*> ColliderManager::colliders;

float Phys::Meter()
{
    int w = 0;
    int h = 0;
    SDL_GetWindowSize(Engine::CurrentWindow, &w, &h);
    return h / METER_WINDOW_RATIO;
}

Rigidbody::Rigidbody(Entity* e, bool k, float m, float g, float v)
{
    ent = e;
    Kinematic = k;
    Mass = m;
    Gravity = g;
    Velocity = v;
    RigidbodyManager::bodies.push_back(this);
}

Collider::Collider(Entity* e)
{
    ent = e;
    ColliderManager::colliders.push_back(this);
}