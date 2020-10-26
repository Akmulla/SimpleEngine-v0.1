#pragma once
#include <Windows.h>
#include <d3d11.h>

class Window
{
public:
	Window(HINSTANCE hInstance);
	~Window();
private:
	HWND hwnd;
};