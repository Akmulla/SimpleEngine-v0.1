#pragma once
#include "GameObject.h"

class Component
{
public:
	Component();
	void BindGameObject(GameObject& gameObject);
private:
	GameObject* m_gameObject;
};