#include "Spawner.h"
#include "GameObject.h"

Spawner::Spawner(GameObject& game_object, float spawn_delay) : spawn_delay(spawn_delay), prefab(*(new GameObject(game_object)))
{ 

}

void Spawner::Spawn()
{
	m_gameObject->scene.gameObjects.push_back(new GameObject(prefab));
}
