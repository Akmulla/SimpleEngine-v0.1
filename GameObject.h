#pragma once
#include <DirectXMath.h>
#include "Geometry.h"

class GameObject
{
public:
	GameObject(DirectX::XMFLOAT3* dxVertices,int size);
	~GameObject();
	Vector3 position;
	//DirectX::XMFLOAT3 position;
	//DirectX::XMFLOAT3* dxVertices;
	int size;
private:
	DirectX::XMFLOAT3 dxCoord;
	DirectX::XMFLOAT3* dxVertices;
};