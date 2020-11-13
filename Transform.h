#pragma once
#include "GameObject.h"
#include "Geometry.h"

class Transform : Component
{
public:
	Transform();
	~Transform();
	Vector2 m_position;
	void Move(const Vector2& movement);
private:
	DirectX::XMFLOAT3 dxPosition;
	void UpdateDxCoord();
};