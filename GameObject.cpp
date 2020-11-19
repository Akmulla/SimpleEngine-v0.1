#include "GameObject.h"
#include "Component.h"

GameObject::GameObject(Scene& scene) : scene(scene) { }

GameObject::~GameObject()
{
	for (auto it = m_components.begin(); it != m_components.end(); ++it) 
	{
		delete (*it);
	}
}

void GameObject::AddComponent(Component& component)
{
	component.BindGameObject(*this);
	m_components.push_back(&component);
}

void GameObject::UpdateAllComponents(double dt)
{
	for (auto it = m_components.begin(); it != m_components.end(); ++it)
	{
		(*it)->UpdateComponent(dt);
	}
}
