#include <iostream>
#include <vector>
#define SDL_MAIN_HANDLED
#include <KOOLengine/engine.hpp>
#include <KOOLengine/entity.hpp>
#include <KOOLengine/phys.hpp>
#include <KOOLengine/animation.hpp>
#include <KOOLengine/scene.hpp>
#include <KOOLengine/sound.hpp>

int main(int argc, char** argv)
{
    Engine::Begin("Bounce Test", 400, 400);
    Scene bnc = {0, "bnc", [](){
        Entity ground;
        ground.LoadTexture("ground.png");
        ground.SetPosition(0, 300);
        ground.SetSize(400, 100);
        SDL_Color white = {255, 255, 255};
        Entity ball1;
        ball1.LoadTexture("ball.png");
        ball1.SetPosition(100, 100);
        ball1.SetSize(40, 40);
        Entity ball2;
        ball2.LoadTexture("ball1.png");
        ball2.SetPosition(200, 100);
        ball2.SetSize(40, 40);
        Rigidbody body1(&ball1, false, 1.0f, 1.0f, VELOCITY_DEFAULT);
        Rigidbody body2(&ball2, false, 1.0f, 1.0f, VELOCITY_DEFAULT);
        Collider col1(&ball1);
        Collider col2(&ball2);
        ball1.ID = 0;
        ball2.ID = 0;
        Collider col3(&ground);
        int index = 0;
        bool movingLeft = false;
        bool movingRight = false;
        bool jumping = false;
        while(!Engine::Done)
        {
            Engine::FillScreen(white);
            while(SDL_PollEvent(&Engine::EngineEvent))
            {
                switch(Engine::EngineEvent.type)
                {
                    case SDL_KEYDOWN:
                        switch(Engine::EngineEvent.key.keysym.sym)
                        {
                            case SDLK_SPACE:
                                jumping = true;
                                break;
                            case SDLK_d:
                                movingRight = true;
                                break;
                            case SDLK_a:
                                movingLeft = true;
                                break;
                        }
                        break;
                    case SDL_KEYUP:
                        switch(Engine::EngineEvent.key.keysym.sym)
                        {
                            case SDLK_SPACE:
                                jumping = false;
                                break;
                            case SDLK_d:
                                movingRight = false;
                                break;
                            case SDLK_a:
                                movingLeft = false;
                                break;
                        }
                        break;
                    case SDL_QUIT:
                        Engine::End(0);
                }
            }
            if(movingLeft)
            {
                ball1.rect.x-=5.0f;
            }
            else if(movingRight)
            {
                ball1.rect.x+=5.0f;
            }
            if(jumping)
            {
                body1.Kinematic = true;
                ball1.rect.y-=10.0f;
            }
            else if(!jumping)
            {
                //canJump = true;
                body1.Kinematic = false;
            }
            Engine::MainLoop();
            Engine::Tick();
        }
        Engine::End(0);
    }};
    SceneManager::AddScene(bnc);
    SceneManager::LoadScene("bnc");
    return 0;
}