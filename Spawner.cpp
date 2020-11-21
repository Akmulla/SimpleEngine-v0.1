#include "Spawner.h"
#include "GameObject.h"

Spawner::Spawner(GameObject& game_object, float spawn_delay) : spawn_delay(spawn_delay), prefab(*(new GameObject(game_object))), time_from_last_tick(0.0f)
{ 

}

void Spawner::Spawn()
{
	GameObject* new_obj = new GameObject(prefab);
	new_obj->GetComponent<Transform>()->position = m_gameObject->GetComponent<Transform>()->position;
	m_gameObject->scene.gameObjects.push_back(new_obj);
}

void Spawner::UpdateComponent(float dt) 
{
	time_from_last_tick += dt;
	if (time_from_last_tick > spawn_delay)
	{
		time_from_last_tick = 0.0f;
		//Spawn();
	}
}
