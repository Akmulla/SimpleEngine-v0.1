#pragma once
#include <Windows.h>
#include <d3d11.h>
#include "Scene.h"

class Window
{
public:
	Window(HINSTANCE hInstance);
	~Window();
	void DrawContent(Scene scene);
private:
	HWND hwnd;
};