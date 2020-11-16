#pragma once
#include <DirectXMath.h>
#include "Geometry.h"

class Mesh
{
public:
	Mesh(DirectX::XMFLOAT3 dxVertices);
private:
	DirectX::XMFLOAT3 m_dxVertices;
};