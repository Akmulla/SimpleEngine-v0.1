#pragma once
#include <Windows.h>
#include <d3d11.h>
#include <sstream>
#include <string>
#include <memory>
#include "Scene.h"
#include "Graphics.h"

class Window
{
public:
	Window(HINSTANCE);
	~Window();
	void DrawContent(Scene);
private:
	HWND hwnd;
	std::unique_ptr<Graphics> graphics;
};