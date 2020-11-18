#pragma once
#include "Component.h"
#include "Window.h"

class Player : public Component
{
public:
	Player(float movement_speed);
	void UpdateComponent(double dt) override;
	float movement_speed;
};