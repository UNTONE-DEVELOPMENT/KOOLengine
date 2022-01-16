#include <iostream>
#include <KOOLengine/engine.hpp>
#include <KOOLengine/entity.hpp>
#include <KOOLengine/phys.hpp>
#include <KOOLengine/animation.hpp>
#include <KOOLengine/scene.hpp>

int main(int argc, char** argv)
{
    Engine::Begin("Example", 512, 512);
    Scene sc1 = {0, "Hello", [](){
        std::cout << "Hello" << std::endl;
    }};
    Scene sc2 = {1, "World!", [](){
        std::cout << "World!" << std::endl;
    }};
    SceneManager::AddScene(sc1);
    SceneManager::AddScene(sc2);
    while(!Engine::Done)
    {
        Engine::FillScreen((SDL_Color){255,255,255});
        Engine::MainLoop();
        SceneManager::LoadScene("Hello");
        SceneManager::LoadScene("World!");
        Engine::Tick();
    }
}