#include "Scene.h"
#include "Window.h"

Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::DoUpdate(double dt)
{
	Window* mainWindow = Window::GetMainWindow();
	InputData inputData = mainWindow->inputData;

	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i].UpdateAllComponents(dt);
		/*using namespace DirectX;
		XMFLOAT3 movement{ (float)(inputData.horizontalAxis * dt * 5),(float)( inputData.verticalAxis * dt * 5), 0.0f };
		XMVECTOR v1 = DirectX::XMLoadFloat3(&gameObjects[i].position);
		XMVECTOR v2 = DirectX::XMLoadFloat3(&movement);
		XMStoreFloat3(&gameObjects[i].position, DirectX::XMVectorAdd(v1, v2));*/
	}
}
