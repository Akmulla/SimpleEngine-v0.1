#pragma once
#include <Windows.h>
#include <d3d11.h>
#include <sstream>
#include <string>
#include <memory>
#include "Scene.h"
#include "Graphics.h"
#include "SupportDataStructures.h"

class Window
{
public:
	Window(HINSTANCE);
	~Window();
	void DrawContent(Scene);
	int ProcessInput(InputData&);
	static Window* GetMainWindow();
	InputData inputData;
private:
	static Window* mainWindow;
	HWND hwnd;
	std::unique_ptr<Graphics> graphics;
	
};