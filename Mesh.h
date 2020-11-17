#pragma once
#include <DirectXMath.h>
#include "GameObject.h"
#include "Component.h"
#include "Geometry.h"

class Mesh : public Component
{
public:
	Mesh(DirectX::XMFLOAT3* dxVertices, int size);

	DirectX::XMFLOAT3* dxVertices;
	int size;
};