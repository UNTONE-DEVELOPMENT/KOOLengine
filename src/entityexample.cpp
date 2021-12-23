#include <iostream>
#include "engine.hpp"
#include "component.hpp"
#include "entity.hpp"

int main(int argc, char** argv)
{
    Engine::Begin("Example", 512, 512);
    Entity ent;
    Component *entPtr = &ent;
    ent.LoadTexture("mono.png");
    ent.SetPosition(100, 100);
    SDL_Color white = {255, 255, 255, 255};
    SDL_Color red = {255, 0, 0, 255};
    while(!Engine::Done)
    {
        while(SDL_PollEvent(&Engine::EngineEvent))
        {
            switch(Engine::EngineEvent.type)
            {
                case SDL_QUIT:
                    Engine::End(0);
            }
        }
        Engine::FillScreen(white);
        Engine::SetOverlayColor(red);
        ent.Activate();
        Engine::Tick();
    }
}