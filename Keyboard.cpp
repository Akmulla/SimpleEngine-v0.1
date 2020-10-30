#include "Keyboard.h"

Keyboard::Keyboard()
{
	keystates.reset();
}

Keyboard::~Keyboard()
{
	
}

bool Keyboard::ReadKeyPressed(unsigned char keycode)
{
	return false;
}

void Keyboard::SetKeyPressState(unsigned char keycode)
{

}
