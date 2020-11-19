#pragma once
#include "Component.h"
#include "Scene.h"

class Spawner : public Component
{
public:
	float spawn_delay;
	Spawner(GameObject&);
	void Spawn();
private:
	GameObject* prefab;
};