#include <Windows.h>
#include "Timer.h"
#include "Scene.h"
#include "Window.h"



LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	default:
		break;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
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

	MSG msg;

	while (true)
	{
		//Get Input here
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				return msg.wParam;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		//Do scene update

		//Draw result

	}

}