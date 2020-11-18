#include "Scene.h"
#include "Window.h"

Scene::Scene()
{

}

Scene::~Scene()
{
	for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		delete (*it);
	}
}

void Scene::DoUpdate(double dt)
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->UpdateAllComponents(dt);
	}
}
