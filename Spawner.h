#pragma once
#include "Component.h"
#include "Scene.h"

class Spawner : public Component
{
public:
	float spawn_delay;
	Spawner(GameObject&, float);
	void Spawn();
private:
	const GameObject& prefab;
};