#include <iostream>
#define SDL_MAIN_HANDLED
#include <KOOLengine/engine.hpp>
#include <KOOLengine/entity.hpp>
#include <KOOLengine/phys.hpp>
#include <KOOLengine/animation.hpp>
#include <KOOLengine/scene.hpp>
#include <KOOLengine/sound.hpp>

int main(int argc, char** argv)
{
    Engine::Begin("Sound Check", 400, 400);
    Scene chk = {0, "chk", [](){
        SoundManager::PlayLooped("SEQ.wav", "test_sequence");
        SDL_Color white = {255, 255, 255};
        while(!Engine::Done)
        {
            Engine::FillScreen(white);
            Engine::MainLoop();
            SDL_Delay(10000);
            SoundManager::StopMix("test_sequence");
            Engine::End(0);
            Engine::Tick();
        }
    }};
    SceneManager::AddScene(chk);
    SceneManager::LoadScene("chk");
    return 0;
}