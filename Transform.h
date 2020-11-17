#pragma once
#include "GameObject.h"
#include "Geometry.h"
#include "Component.h"

class Transform : public Component
{
public:
	Transform();
	~Transform();
	Vector2 position;
	void Move(const Vector2& movement);
};