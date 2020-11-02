#include <Windows.h>
#include <iostream>
#include "Timer.h"
#include "Scene.h"
#include "Window.h"
#include "SupportDataStructures.h"

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

	while (true)
	{
		double dt = timer.Mark();

		//Get Input here
		inputData.Clear();
		mainWindow.ProcessInput(inputData);
		
		//Do scene update
		mainScene.DoUpdate(dt);

		//Draw result
		mainWindow.DrawContent(mainScene);
	}
}