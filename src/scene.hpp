#include <iostream>
#include <functional>
#include <vector>
#include <SDL2/SDL.h>
#include "component.hpp"

typedef struct 
{
    int index;
    std::string name;
    std::function<void(void)> Body;
} Scene;

class SceneManager: public Component
{
public:
    static std::vector<Scene> loadedScenes;
    static void AddScene(Scene sc);
    static void LoadScene(std::string name);
private:
    static Scene currentScene;
};