#include <Windows.h>
#include <iostream>
#include "Timer.h"
#include "Scene.h"
#include "Window.h"
#include "SupportDataStructures.h"
#include "Mesh.h"
#include "Component.h"
#include "Transform.h"
#include "Player.h"
#include "Spawner.h"

GameObject* CreatePlayer(Scene& scene)
{
	DirectX::XMFLOAT3* dxVertices = new DirectX::XMFLOAT3[3];
	dxVertices[0].x = 0.0f;
	dxVertices[0].y = 0.5f;
	dxVertices[1].x = 0.5f;
	dxVertices[1].y = -0.5f;
	dxVertices[2].x = -0.5f;
	dxVertices[2].y = -0.5f;

	GameObject* obj = new GameObject(scene);
	Mesh* mesh = new Mesh(dxVertices, 3);
	Transform* transform = new Transform();
	Player* player = new Player(1.0f);

	obj->AddComponent(*mesh);
	obj->AddComponent(*transform);
	obj->AddComponent(*player);

	return obj;
}

GameObject* CreateSpawner(Scene& scene)
{
	GameObject* spawner_obj = new GameObject(scene);
	GameObject* enemy_prefab = new GameObject(scene);

	DirectX::XMFLOAT3* dxVertices = new DirectX::XMFLOAT3[6];
	dxVertices[0].x = 0.0f;
	dxVertices[0].y = 0.0f;

	dxVertices[1].x = 0.0f;
	dxVertices[1].y = 0.5f;

	dxVertices[2].x = 0.5f;
	dxVertices[2].y = 0.5f;

	dxVertices[3].x = 0.5f;
	dxVertices[3].y = 0.5f;

	dxVertices[4].x = 0.5f;
	dxVertices[4].y = 0.0f;

	dxVertices[5].x = 0.0f;
	dxVertices[5].y = 0.0f;

	

	Mesh* mesh = new Mesh(dxVertices, 6);
	Transform* transform = new Transform();

	enemy_prefab->AddComponent(*mesh);
	enemy_prefab->AddComponent(*transform);

	Spawner* spawner = new Spawner(*enemy_prefab, 2.0f);
	spawner_obj->AddComponent(*(new Transform()));
	spawner_obj->AddComponent(*spawner);


	return spawner_obj;
}


void InitScene(Scene& scene)
{
	GameObject* player = CreatePlayer(scene);
	GameObject* spawner = CreateSpawner(scene);

	scene.gameObjects.push_back(player);
	scene.gameObjects.push_back(spawner);
}



int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	Timer timer;
	Scene mainScene;
	Window mainWindow(hInstance);

	InputData inputData;
	InitScene(mainScene);

	while (true)
	{
		float dt = timer.Mark();

		//Get Input here
		//inputData.Clear();
		mainWindow.ProcessInput(inputData);
		
		//Do scene update
		mainScene.DoUpdate(dt);

		//Draw result
		mainWindow.DrawContent(mainScene);
	}
}
