#pragma once
#include "GameObject.h"
#include <vector>

#include "SupportDataStructures.h"

class Scene
{
public:
	Scene();
	~Scene();
	void DoUpdate(double dt);
	std::vector<GameObject*> gameObjects;
};
