#include <iostream>
#include <KOOLengine/engine.hpp>
#include <KOOLengine/entity.hpp>
#include <KOOLengine/phys.hpp>
#include <KOOLengine/animation.hpp>

int main(int argc, char** argv)
{
    Engine::Begin("Example", 512, 512);
    Entity ent;
    Component *entPtr = &ent;
    ent.LoadTexture("mono.png");
    ent.SetPosition(100, 0);
    ent.SetSize(100, 100);
    ent.ID = 0;
    Rigidbody body(&ent, false, 1.0f, MASS_DEFAULT, VELOCITY_DEFAULT);
    body.Kinematic = false;
    Entity grnd;
    grnd.LoadTexture("bul.png");
    Collider col1(&ent);
    Collider col(&grnd);
    grnd.SetPosition(100, 400);
    SDL_Color white = {255, 255, 255, 255};
    SDL_Color red = {255, 0, 0, 255};
    Animation an(&ent);
    std::vector<std::string> frames;
    for(int i = 0; i < 4; i++)
    {
        frames.push_back("mono.png");
    }
    ent.LoadTextureArray(frames); 
    while(!Engine::Done)
    {
        Engine::FillScreen(white);
        Engine::SetOverlayColor(red);
        Engine::MainLoop();
        Engine::Tick();
    }
}
