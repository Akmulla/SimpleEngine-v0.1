#pragma once
#include <DirectXMath.h>
#include "GameObject.h"
#include "Component.h"
#include "Geometry.h"

class Mesh : Component
{
public:
	Mesh(DirectX::XMFLOAT3 dxVertices);
private:
	DirectX::XMFLOAT3 m_dxVertices;
};