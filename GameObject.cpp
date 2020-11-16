#include "GameObject.h"
#include "Component.h"

GameObject::GameObject(DirectX::XMFLOAT3* vertices, int size)
{
	this->dxVertices = vertices;
	this->size = size;
}

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