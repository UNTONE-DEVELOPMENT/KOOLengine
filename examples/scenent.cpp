#include <iostream>
#include <KOOLengine/engine.hpp>
#include <KOOLengine/entity.hpp>
#include <KOOLengine/phys.hpp>
#include <KOOLengine/animation.hpp>
#include <KOOLengine/scene.hpp>

int main(int argc, char** argv)
{
	Engine::Begin("Scene with Entities", 900, 600);
	Scene sc1 = {0, "Scene 1", [](){
		Entity ent;
		ent.LoadTexture("mono.png");
		ent.SetPosition(450, 100);
		ent.SetSize(100, 100);
		ent.ID = 0;
		Rigidbody bd(&ent, false, 1.0f, 1.0f, VELOCITY_DEFAULT);
		Collider cl1(&ent);
		SDL_Color white = {255, 255, 255};
		while(!Engine::Done)
		{
			Engine::FillScreen(white);
			Engine::SetOverlayColor(white);
			Engine::MainLoop();
			if(ent.rect.y > 900)
			{
				SceneManager::LoadScene("Scene 2");
			}
			Engine::Tick();
		}	
	}};
	Scene sc2 = {1, "Scene 2", [](){
		SDL_Color red = {255, 0, 0};
		SDL_Color green = {0, 255, 0};
		SDL_Color blue = {0, 0, 255};
		while(!Engine::Done)
		{
			Engine::MainLoop();
			Engine::FillScreen(red);
			SDL_Delay(500);
			Engine::Tick();
			Engine::FillScreen(green);
			SDL_Delay(500);
			Engine::Tick();
			Engine::FillScreen(blue);
			SDL_Delay(500);
			Engine::Tick();			
		}
		Engine::End(0);
	}};
	SceneManager::AddScene(sc1);
	SceneManager::AddScene(sc2);
	SceneManager::LoadScene("Scene 1");
	return 0;
}
