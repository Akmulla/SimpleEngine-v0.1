#pragma once
#include "Component.h"

class Rotator : public Component
{
public:
	float rotation_speed;
	Rotator(float rotation_speed);
	void UpdateComponent(float dt) override;
};