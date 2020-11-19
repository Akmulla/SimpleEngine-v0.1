#pragma once

#include <vector>

#include "SupportDataStructures.h"

class GameObject;

class Scene
{
public:
	Scene();
	~Scene();
	void DoUpdate(double dt);
	std::vector<GameObject*> gameObjects;
};
