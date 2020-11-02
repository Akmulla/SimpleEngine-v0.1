#pragma once
#include <DirectXMath.h>

class GameObject
{
public:
	GameObject(DirectX::XMFLOAT3* dxVertices,int size);
	~GameObject();
	DirectX::XMFLOAT3* dxVertices;
	int size;
};