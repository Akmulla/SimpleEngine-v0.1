#pragma once
#include "Component.h"
#include "Window.h"

class Player : public Component
{
public:
	void UpdateComponent(double dt) override;
};