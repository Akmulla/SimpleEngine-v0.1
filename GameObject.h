#pragma once
#include <DirectXMath.h>
#include "Geometry.h"
#include <memory>
#include <vector>

class Component
{

};

class GameObject
{
public:
	GameObject(DirectX::XMFLOAT3* dxVertices,int size);
	~GameObject();

	DirectX::XMFLOAT3 position;
	//DirectX::XMFLOAT3* dxVertices;
	int size;

	DirectX::XMFLOAT3 dxCoord;
	DirectX::XMFLOAT3* dxVertices;
private:
	std::vector<Component*> components;
};