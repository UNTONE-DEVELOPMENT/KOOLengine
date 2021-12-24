#include <iostream>
#include "engine.hpp"
#include "component.hpp"
#include "entity.hpp"
#include "phys.hpp"

int main(int argc, char** argv)
{
    Engine::Begin("Example", 512, 512);
    Entity ent;
    Component *entPtr = &ent;
    ent.LoadTexture("mono.png");
    ent.SetPosition(100, 100);
    Rigidbody body(&ent, true, 1.0f, MASS_DEFAULT);
    SDL_Color white = {255, 255, 255, 255};
    SDL_Color red = {255, 0, 0, 255};
    while(!Engine::Done)
    {
        Engine::MainLoop();       
        Engine::FillScreen(white);
        Engine::SetOverlayColor(red);
        ent.Activate();
        Engine::Tick();
    }
}