#include <Windows.h>
#include "Timer.h"
#include "Scene.h"
#include "Window.h"

struct InputData
{
public:
	double verticalAxis;
	double horizontalAxis;
};

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
		//Get Input here
		mainWindow.ProcessInput();

		//Do scene update
		//mainScene.DoUpdate();

		//Draw result

	}

}