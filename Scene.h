#pragma once
#include "GameObject.h"
#include <vector>

class Scene
{
public:
	Scene();
	~Scene();
	void DoUpdate(double dt);
	std::vector<GameObject> gameObjects;
};
