#include <Windows.h>
#include <iostream>
#include "Timer.h"
#include "Scene.h"
#include "Window.h"
#include "SupportDataStructures.h"
#include "Mesh.h"
#include "Component.h"
#include "Transform.h"


void InitScene(Scene& scene)
{
	DirectX::XMFLOAT3* dxVertices = new DirectX::XMFLOAT3[3];
	dxVertices[0].x = 0.0f;
	dxVertices[0].y = 0.5f;
	dxVertices[1].x = 0.5f;
	dxVertices[1].y = -0.5f;
	dxVertices[2].x = -0.5f;
	dxVertices[2].y = -0.5f;

	GameObject* obj = new GameObject();
	Mesh* mesh = new Mesh(dxVertices, 3);
	Transform* transform = new Transform();
	obj->AddComponent(*mesh);
	obj->AddComponent(*transform);

	scene.gameObjects.push_back(obj);
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
		double dt = timer.Mark();

		//Get Input here
		//inputData.Clear();
		mainWindow.ProcessInput(inputData);
		
		//Do scene update
		mainScene.DoUpdate(dt);

		//Draw result
		mainWindow.DrawContent(mainScene);
	}
}

