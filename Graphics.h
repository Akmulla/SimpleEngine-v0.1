#pragma once

#include <d3dcompiler.h>
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib,"D3DCompiler.lib")

class Graphics
{
public:
	Graphics(HWND hwnd);
	~Graphics();
};