#pragma once

#include <d3d11.h>
#include <d3dcompiler.h>
#include "SupportDataStructures.h"
#include "GameObject.h"
#include <wrl.h>
#include <array>
#include "Mesh.h"
#include "Transform.h"

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib,"D3DCompiler.lib")

class Graphics
{
public:
	Graphics(HWND hwnd);
	~Graphics();
	void ClearBackground(ColorRGBA);
	void RenderGameObject(const GameObject&);
	void EndFrame();
private:
	ID3D11Device* pDevice = nullptr;
	IDXGISwapChain* pSwap = nullptr;
	ID3D11DeviceContext* pContext = nullptr;
	ID3D11RenderTargetView* pTarget = nullptr;
};