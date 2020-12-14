#include "Rotator.h"
#include "GameObject.h"

Rotator::Rotator(float rotation_speed) : rotation_speed(rotation_speed) {}

void Rotator::UpdateComponent(float dt)
{
	m_gameObject->GetComponent<Transform>()->rotation += rotation_speed * dt;
}