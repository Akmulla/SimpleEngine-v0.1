#include "Component.h"

Component::Component() : m_gameObject(nullptr)
{
	
}

void Component::BindGameObject(GameObject& gameObject)
{
	m_gameObject = &gameObject;
}

void Component::Init()
{

}

void Component::UpdateComponent(double dt)
{

}