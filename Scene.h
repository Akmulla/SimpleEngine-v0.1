#pragma once

#include <vector>

#include "SupportDataStructures.h"

class GameObject;

class Scene
{
public:
	Scene();
	~Scene();
	void DoUpdate(float dt);
	std::vector<GameObject*> gameObjects;
};
