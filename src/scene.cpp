#include <iostream>
#include <functional>
#include <vector>
#include <SDL2/SDL.h>
#include "component.hpp"
#include "entity.hpp"
#include "phys.hpp"
#include "scene.hpp"

std::vector<Scene> SceneManager::loadedScenes;
Scene SceneManager::currentScene;

void SceneManager::AddScene(Scene sc)
{
    bool shouldAdd = true;
    for(auto &i : loadedScenes)
    {
        if(i.name == sc.name)
        {
            shouldAdd = false;
        }
    }
    if(shouldAdd == true)
    {
        loadedScenes.push_back(sc);
    }
}

void SceneManager::LoadScene(std::string name)
{
    RigidbodyManager::bodies.clear();
    ColliderManager::colliders.clear();
    EntityManager::entities.clear();
    for(auto &i : loadedScenes)
    {
        if(i.name == name)
        {
            currentScene = i;
            i.Body();
        }
    }
}
