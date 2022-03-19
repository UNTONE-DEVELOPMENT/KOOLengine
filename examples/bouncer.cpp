#include <iostream>
#include <vector>
#define SDL_MAIN_HANDLED
#include <KOOLengine/engine.hpp>
#include <KOOLengine/entity.hpp>
#include <KOOLengine/phys.hpp>
#include <KOOLengine/animation.hpp>
#include <KOOLengine/scene.hpp>
#include <KOOLengine/sound.hpp>
#include <SDL2/SDL_ttf.h>

float reverse_wein(float dmax)
{
    const float b = 2.89f*pow(10, -3);
    return b/dmax;
}

SDL_Texture* render_text(SDL_Renderer *renderer, const char* text, TTF_Font *font, SDL_Color color, SDL_Rect *rect) 
{
    SDL_Surface *surface;
    SDL_Texture *texture;

    surface = TTF_RenderText_Solid(font, text, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    rect->w = surface->w;
    rect->h = surface->h;

    SDL_FreeSurface(surface);

    return texture;
}

int main(int argc, char** argv)
{
    Engine::Begin("Bounce Test", 400, 400);
    TTF_Init();
    Scene bnc = {0, "bnc", [](){
        SDL_Texture* t;
        SDL_Rect tr = {10, 10, 25, 50};
        SDL_Color black = {0,0,0};
        TTF_Font* font = TTF_OpenFont("Roboto-Light.ttf", 36);
        Entity ground;
        ground.LoadTexture("ground.png");
        ground.SetPosition(0, 300);
        ground.SetSize(400, 100);
        SDL_Color white = {255, 255, 255};
        Entity ball1;
        ball1.LoadTexture("ball.png");
        ball1.SetPosition(100, 100);
        ball1.SetSize(100, 100);
        Rigidbody body1(&ball1, false, 1.0f, 1.0f, VELOCITY_DEFAULT);
        Collider col1(&ball1);
        Thermo th1(&ball1);
        th1.temp_abs = -273;
        ball1.ID = 1;
        Collider col3(&ground);
        int index = 0;
        bool movingLeft = false;
        bool movingRight = false;
        bool jumping = false;
        Entity waves;
        waves.LoadTexture("waves.png");
        waves.SetSize(370, 39);
        waves.SetPosition(400/2-370/2, 320);
        Entity tick;
        tick.LoadTexture("tick.png");
        tick.SetSize(5, 39);
        tick.SetPosition(waves.rect.x + waves.rect.w, waves.rect.y);
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
            float w = th1.wein();
            if(movingLeft)
            {
                if(tick.rect.x > waves.rect.x)
                {
                    th1.temp_abs+=1;
                    tick.rect.x-=1;
                    char tt[100];
                    sprintf(tt, "Temperatura: %dK", (int)reverse_wein(w));
                    t = render_text(Engine::Renderer, tt, font, black, &tr);
                    //ball1.rect.x-=5.0f;
                }
            }
            else if(movingRight)
            {
                if(tick.rect.x < waves.rect.x + waves.rect.w)
                {
                    th1.temp_abs-=1;
                    tick.rect.x+=1;
                    char tt[100];
                    sprintf(tt, "Temperatura: %dK", (int)th1.temp_abs);
                    t = render_text(Engine::Renderer, tt, font, black, &tr);
                    //ball1.rect.x+=5.0f;
                }
            }
            if(jumping)
            {
                //body1.Kinematic = true;
                //ball1.rect.y-=10.0f;
            }
            else if(!jumping)
            {
                //canJump = true;
                body1.Kinematic = false;
            }
            
            Engine::MainLoop();
            SDL_RenderCopy(Engine::Renderer, t, NULL, &tr);
            if(tick.rect.x >= 159 && tick.rect.x <= 160)
            {
                SDL_SetTextureColorMod(ball1.Texture, 255, 0, 0);
            }
            else if(tick.rect.x >= 158 && tick.rect.x <= 159)
            {
                SDL_SetTextureColorMod(ball1.Texture, 255, 61, 0);
            }
            else if(tick.rect.x >= 157 && tick.rect.x <= 158)
            {
                SDL_SetTextureColorMod(ball1.Texture, 255, 241, 0);
            }
            else if(tick.rect.x >= 156 && tick.rect.x <= 157)
            {
                SDL_SetTextureColorMod(ball1.Texture, 0, 255, 0);
            }
            else if(tick.rect.x >= 155 && tick.rect.x <= 156)
            {
                SDL_SetTextureColorMod(ball1.Texture, 0, 255, 211);
            }
            else if(tick.rect.x >= 154 && tick.rect.x <= 155)
            {
                SDL_SetTextureColorMod(ball1.Texture, 0, 185, 255);
            }
            else if(tick.rect.x >= 153 && tick.rect.x <= 154)
            {
                SDL_SetTextureColorMod(ball1.Texture, 0, 107, 255);
            }
            else if(tick.rect.x >= 152 && tick.rect.x <= 153)
            {
                SDL_SetTextureColorMod(ball1.Texture, 0, 0, 255);
            }
            else if(tick.rect.x >= 151 && tick.rect.x <= 152)
            {
                SDL_SetTextureColorMod(ball1.Texture, 139, 0, 211);
            }
            else if(tick.rect.x >= 150 && tick.rect.x <= 151)
            {
                SDL_SetTextureColorMod(ball1.Texture, 181, 0, 211);
            }
            else
            {
                SDL_SetTextureColorMod(ball1.Texture, 255, 255, 255);
            }
            Engine::Tick();
        }
        Engine::End(0);
    }};
    SceneManager::AddScene(bnc);
    SceneManager::LoadScene("bnc");
    return 0;
}