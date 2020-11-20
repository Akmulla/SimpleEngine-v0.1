#pragma once
//#include "GameObject.h"

class GameObject;

class Component
{
public:
	Component();
	void BindGameObject(GameObject& gameObject);
	virtual void UpdateComponent(float dt);
protected:
	GameObject* m_gameObject;
};