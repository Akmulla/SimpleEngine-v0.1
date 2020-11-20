#pragma once
#include "Component.h"
#include "Scene.h"

class Spawner : public Component
{
public:
	float spawn_delay;
	Spawner(GameObject&, float);
	void Spawn();
	void UpdateComponent(float dt) override;
private:
	const GameObject& prefab;
	float time_from_last_tick;
};