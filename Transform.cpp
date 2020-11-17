#include "Transform.h"

Transform::Transform() : position(0.0f,0.0f)
{
	
}

Transform::~Transform()
{

}

void Transform::Move(const Vector2& movement)
{
	position += movement;
}
