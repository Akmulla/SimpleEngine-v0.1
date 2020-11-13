#include "Transform.h"

Transform::Transform() : m_position(0.0f,0.0f)
{
	//dxPosition = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
	//position = Vector2();
}

Transform::~Transform()
{

}

void Transform::Move(const Vector2& movement)
{
	m_position += movement;
}

void Transform::UpdateDxCoord()
{

}