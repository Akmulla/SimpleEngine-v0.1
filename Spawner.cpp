#include "Spawner.h"
#include "GameObject.h"

Spawner::Spawner(GameObject& game_object, float spawn_delay) : spawn_delay(spawn_delay), prefab(*(new GameObject(game_object))), time_from_last_tick(0.0f)
{ 

}

void Spawner::Spawn()
{
	m_gameObject->scene.gameObjects.push_back(new GameObject(prefab));
}

void Spawner::UpdateComponent(float dt) 
{

}
