#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "component.hpp"
#include "entity.hpp"
#include <vector>
#include "phys.hpp"

std::vector<Rigidbody*> RigidbodyManger::bodies;
std::vector<Collider*> ColliderManager::colliders;

Rigidbody::Rigidbody(Entity* e, bool k, float m, float g)
{
    ent = e;
    Kinematic = k;
    Mass = m;
    Gravity = g;
    RigidbodyManger::bodies.push_back(this);
}

Collider::Collider(Entity* e)
{
    ent = e;
    ColliderManager::colliders.push_back(this);
}