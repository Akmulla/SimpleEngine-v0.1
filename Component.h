#pragma once
//#include "GameObject.h"

class GameObject;

class Component
{
public:
	Component();
	void BindGameObject(GameObject& gameObject);
	virtual void Init();
	virtual void UpdateComponent(double dt);
private:
	GameObject* m_gameObject;
};