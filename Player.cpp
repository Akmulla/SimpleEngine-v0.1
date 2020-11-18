#include "Player.h"

Player::Player(float movement_speed) : movement_speed(movement_speed){}

void Player::UpdateComponent(double dt)
{
	InputData input = Window::GetMainWindow()->inputData;

	Vector2 movement(input.horizontalAxis, input.verticalAxis); 
	movement = movement * movement_speed * dt;
	m_gameObject->GetComponent<Transform>()->position += movement;
}