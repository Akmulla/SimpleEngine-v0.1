#include "Window.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	Window* mainWindow = Window::GetMainWindow();
	//mainWindow->inputData.Clear();

	if (uMsg == WM_KEYDOWN)
	{
		switch (wParam)
		{
		case VK_UP:
			mainWindow->inputData.verticalAxis = 1.0;
			break;
		case VK_DOWN:
			mainWindow->inputData.verticalAxis = -1.0;
			break;
		case VK_RIGHT:
			mainWindow->inputData.horizontalAxis = 1.0;
			break;
		case VK_LEFT:
			mainWindow->inputData.horizontalAxis = -1.0;
			break;
		}
	} else
		if (uMsg == WM_KEYUP)
		{
			switch (wParam)
			{
			case VK_UP:
				mainWindow->inputData.verticalAxis = 0.0;
				break;
			case VK_DOWN:
				mainWindow->inputData.verticalAxis = -0.0;
				break;
			case VK_RIGHT:
				mainWindow->inputData.horizontalAxis = 0.0;
				break;
			case VK_LEFT:
				mainWindow->inputData.horizontalAxis = -0.0;
				break;
			}
		}
	

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

Window* Window::mainWindow;

Window::Window(HINSTANCE hInstance)
{
	Window::mainWindow = this;
	const auto winClassName = "SimpleExampleWindowClass";
	WNDCLASSEX wc = { };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = winClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);

	hwnd = CreateWindowEx(
		0,
		winClassName,
		"MyWindow",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200,
		200,
		1024,
		768,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);

	this->graphics = std::unique_ptr<Graphics>(new Graphics(hwnd));
	

	ShowWindow(hwnd, SW_SHOW);
}

Window::~Window()
{
	graphics.release();
}

void Window::DrawContent(Scene& scene)
{
	ColorRGBA c { 1,0,0,1 };
	graphics->ClearBackground(c);

	for (int i = 0; i < scene.gameObjects.size(); i++)
	{
		graphics->RenderGameObject(*(scene.gameObjects[i]));
	}

	graphics->EndFrame();
}

int Window::ProcessInput(InputData& inputData)
{
	MSG msg;

	while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
		{
			return msg.wParam;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);

		inputData = this->inputData;
	}

	return 0;
}

Window* Window::GetMainWindow()
{
	return mainWindow;
}
