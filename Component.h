#pragma once
#include "GameObject.h"

class Component
{
public:
	Component();
	void BindGameObject(GameObject& gameObject);
	virtual void Init();
private:
	GameObject* m_gameObject;
};